#!/usr/bin/env python3
"""
gen_vulkan_stub_all.py — Generate a complete vulkan_stub.c from vk.xml,
covering ALL unique Vulkan commands (standard Vulkan, VulkanSC, disabled,
platform-specific and aliased commands).

Unlike gen_vulkan_stub.py (which covers ~696 commands), this script includes:
  • Every standard Vulkan command (features + extensions)
  • VulkanSC-only commands  (wrapped in #ifdef VKSC_VERSION_1_0)
  • Disabled extension commands (e.g. VK_ANDROID_native_buffer)
    (wrapped in #ifdef VK_ANDROID_NATIVE_BUFFER_SPEC_VERSION)
  • All platform-specific commands  (wrapped in their #ifdef VK_USE_PLATFORM_*)
  • All aliased KHR/EXT/KHR → core aliases

The version is detected automatically from the vk.xml registry file.

USAGE
-----
  # Generate the complete stub C source:
  python3 gen_vulkan_stub_all.py  /path/to/vk.xml  > vulkan_stub.c

  # Redirect to a file:
  python3 gen_vulkan_stub_all.py  \\
      <sysroot>/usr/share/vulkan/registry/vk.xml > vulkan_stub.c

  # Print analysis only (no C output):
  python3 gen_vulkan_stub_all.py  /path/to/vk.xml  --analyse

RETURN-VALUE POLICY (same as gen_vulkan_stub.py)
-------------------------------------------------
  VK_SUCCESS             — queries, enumerations, waits, resets, cache/debug
  VK_NOT_READY           — GetFenceStatus, GetQueryPoolResults
  VK_EVENT_RESET         — GetEventStatus
  VK_ERROR_INITIALIZATION_FAILED
                         — everything else (Create/Allocate/Bind/Submit/…)
"""

import sys
import re
import argparse


# ── Version detection ─────────────────────────────────────────────────────────

def parse_vulkan_version(xml):
    """Extract the Vulkan version string (e.g. '1.3.296') from vk.xml.

    Uses VK_HEADER_VERSION for the patch level and the highest
    VK_VERSION_<major>_<minor> feature number for major.minor.
    Falls back to 'unknown' if parsing fails.
    """
    # VK_HEADER_VERSION lives inside a <type category="define"> block:
    #   #define <name>VK_HEADER_VERSION</name> 341</type>
    # The number appears *after* </name> and *before* </type>.
    patch_m = re.search(r'<name>VK_HEADER_VERSION</name>\s*(\d+)', xml)
    if not patch_m:
        # Fallback: plain #define outside XML tags (e.g. standalone header)
        patch_m = re.search(r'#define\s+VK_HEADER_VERSION\s+(\d+)', xml)
    patch = patch_m.group(1) if patch_m else None

    # Find the highest Vulkan (not VulkanSC-only) feature version.
    # Attribute order in <feature> is not guaranteed, so parse attrs separately.
    best = (1, 0)
    for m in re.finditer(r'<feature\b([^>]*)>', xml):
        attrs = m.group(1)
        api_m = re.search(r'\bapi="([^"]+)"', attrs)
        num_m = re.search(r'\bnumber="(\d+)\.(\d+)"', attrs)
        if api_m and num_m and 'vulkan' in api_m.group(1):
            maj, mino = int(num_m.group(1)), int(num_m.group(2))
            if (maj, mino) > best:
                best = (maj, mino)
    major_minor = f'{best[0]}.{best[1]}'

    return f'{major_minor}.{patch}' if patch else major_minor


# ── VkResult return-value policy ──────────────────────────────────────────────

_SUCCESS_PREFIXES = (
    'vkEnumerate',
    'vkGetPhysicalDevice',
    'vkGetDeviceGroup',
    'vkGetSwapchainImages',
    'vkGetVideoSessionMemoryRequirements',
    'vkGetMemoryFdProperties',
    'vkGetSemaphoreCounterValue',
    'vkGetPipelineCacheData',
    'vkDeviceWaitIdle',
    'vkQueueWaitIdle',
    'vkWaitForFences',
    'vkWaitSemaphores',
    'vkReset',
    'vkFlushMapped',
    'vkInvalidateMapped',
    'vkMergePipelineCaches',
    'vkSetDebugUtils',
    'vkSetPrivateData',
)

_SPECIAL_RETURNS = {
    'vkGetFenceStatus':      'VK_NOT_READY',
    'vkGetEventStatus':      'VK_EVENT_RESET',
    'vkGetQueryPoolResults': 'VK_NOT_READY',
}


def _vkresult_return(name):
    if name in _SPECIAL_RETURNS:
        return _SPECIAL_RETURNS[name]
    if any(name.startswith(p) for p in _SUCCESS_PREFIXES):
        return 'VK_SUCCESS'
    return 'VK_ERROR_INITIALIZATION_FAILED'


# ── XML helpers ───────────────────────────────────────────────────────────────

def cmds_in_block(block):
    return set(re.findall(r'<command[^>]*name="(vk[A-Za-z0-9]+)"', block))


def parse_params(body):
    """Return [(c_decl, param_name), …] for every <param> in a command body."""
    result = []
    for pm in re.finditer(r'<param([^>]*)>(.*?)</param>', body, re.DOTALL):
        attrs, raw = pm.group(1), pm.group(2)
        api_m = re.search(r'\bapi="([^"]+)"', attrs)
        if api_m:
            tokens = {t.strip() for t in api_m.group(1).split(',')}
            # Skip params that are exclusive to VulkanSC (api="vulkansc" only).
            # Some commands (e.g. vkCreateSwapchainKHR) carry both an
            # api="vulkan" and an api="vulkansc" variant for the same parameter;
            # including both would produce duplicate parameter names that the
            # C compiler rejects.  No VulkanSC-only command has a param
            # restricted to api="vulkansc", so this filter is safe for all
            # command categories.
            if not (tokens & {'vulkan', 'vulkanbase'}):
                continue
        nm = re.search(r'<name>([^<]+)</name>', raw)
        if not nm:
            continue
        pname = nm.group(1).strip()
        decl  = ' '.join(re.sub(r'<[^>]+>', '', raw).split())
        result.append((decl, pname))
    return result


# ── Parsing ───────────────────────────────────────────────────────────────────

def build_command_maps(xml):
    """Parse vk.xml → (ret_map, param_map, alias_map).

    Unlike gen_vulkan_stub.py this does NOT skip VulkanSC export definitions
    so that VulkanSC-exclusive commands still have param/return-type info.
    """
    ret_map, param_map = {}, {}
    for blk in re.finditer(r'<command([^>]*)(?<!/)>(.*?)</command>', xml, re.DOTALL):
        attrs, body = blk.group(1), blk.group(2)
        nm = re.search(
            r'<proto>\s*(?:<type>([^<]*)</type>[^<]*)?<name>(vk[A-Za-z0-9]+)</name>',
            body, re.DOTALL)
        if nm:
            name            = nm.group(2)
            ret_map[name]   = (nm.group(1) or 'void').strip()
            param_map[name] = parse_params(body)

    alias_map = {}
    for m in re.finditer(
            r'<command\s+name="(vk[A-Za-z0-9]+)"\s+alias="(vk[A-Za-z0-9]+)"', xml):
        alias_map[m.group(1)] = m.group(2)

    return ret_map, param_map, alias_map


def resolve(name, alias_map, ret_map):
    seen = set()
    while name in alias_map and name not in ret_map:
        if name in seen:
            break
        seen.add(name)
        name = alias_map[name]
    return name


# ── Category collection ───────────────────────────────────────────────────────

def collect_all_commands(xml):
    """Return a dict: cmd_name -> category string.

    Categories (mutually exclusive, priority order):
      'disabled'   — commands in supported="disabled" extensions
      'vulkansc'   — commands only in VulkanSC features/extensions
      'vulkan'     — standard Vulkan commands (features or vulkan extensions)
    """
    category = {}   # name -> set of api tokens seen

    def _update(cmds, tokens):
        for c in cmds:
            category.setdefault(c, set()).update(tokens)

    # Features
    for m in re.finditer(r'<feature([^>]*)>(.*?)</feature>', xml, re.DOTALL):
        api_m = re.search(r'\bapi="([^"]+)"', m.group(1))
        tokens = {t.strip() for t in api_m.group(1).split(',')} if api_m else {'vulkan'}
        _update(cmds_in_block(m.group(2)), tokens)

    # Extensions
    for m in re.finditer(r'<extension([^>]*)>(.*?)</extension>', xml, re.DOTALL):
        sup_m = re.search(r'\bsupported="([^"]+)"', m.group(1))
        tokens = {t.strip() for t in sup_m.group(1).split(',')} if sup_m else {'vulkan'}
        _update(cmds_in_block(m.group(2)), tokens)

    # Build final category labels
    result = {}
    for name, tokens in category.items():
        if tokens == {'disabled'}:
            result[name] = 'disabled'
        elif tokens & {'vulkan', 'vulkanbase'}:
            result[name] = 'vulkan'          # also covers both vulkan+sc
        else:
            result[name] = 'vulkansc'
    return result


def build_platform_guard_map(xml):
    """Return cmd_name -> C guard macro for platform-specific commands."""
    platform_protect = {}
    for m in re.finditer(r'<platform\s+name="([^"]+)"\s+protect="([^"]+)"', xml):
        platform_protect[m.group(1)] = m.group(2)

    cmd_protect = {}
    for ext_m in re.finditer(r'<extension([^>]*)>(.*?)</extension>', xml, re.DOTALL):
        plat_m = re.search(r'\bplatform="([^"]+)"', ext_m.group(1))
        if not plat_m:
            continue
        protect = platform_protect.get(plat_m.group(1))
        if not protect:
            continue
        for cmd_m in re.finditer(r'<command[^>]*name="(vk[A-Za-z0-9]+)"', ext_m.group(2)):
            cmd_protect[cmd_m.group(1)] = protect
    return cmd_protect


def build_disabled_guard_map(xml):
    """Return cmd_name -> C guard macro for commands in disabled extensions."""
    cmd_guard = {}
    for ext_m in re.finditer(r'<extension([^>]*)>(.*?)</extension>', xml, re.DOTALL):
        attrs = ext_m.group(1)
        sup_m = re.search(r'\bsupported="([^"]+)"', attrs)
        if not sup_m or sup_m.group(1) != 'disabled':
            continue
        ext_name = re.search(r'\bname="([^"]+)"', attrs)
        guard = (ext_name.group(1).upper() + '_SPEC_VERSION') if ext_name else None
        if not guard:
            continue
        for cmd_m in re.finditer(r'<command[^>]*name="(vk[A-Za-z0-9]+)"', ext_m.group(2)):
            cmd_guard[cmd_m.group(1)] = guard
    return cmd_guard


# ── Emission ──────────────────────────────────────────────────────────────────

def emit_stub(name, ret, params):
    param_str = ', '.join(decl for decl, _ in params)
    casts     = ' '.join('(void){};'.format(pn) for _, pn in params)
    prefix    = casts + ' ' if casts else ''

    if ret == 'void':
        body = '{ ' + casts + ' }'
    elif ret == 'VkResult':
        body = '{ ' + prefix + 'return ' + _vkresult_return(name) + '; }'
    elif ret == 'PFN_vkVoidFunction':
        body = '{ ' + prefix + 'return NULL; }'
    else:
        body = '{ ' + prefix + 'return (' + ret + ')0; }'

    return '{} {}({}) {}'.format(ret, name, param_str, body)


# ── Analysis ──────────────────────────────────────────────────────────────────

def print_analysis(xml, category_map, ret_map, alias_map, cmd_protect):
    version = parse_vulkan_version(xml)

    canonical_cmds = set(ret_map.keys())
    all_cmds = set(category_map.keys())

    vulkan_cmds   = {n for n, c in category_map.items() if c == 'vulkan'}
    vulkansc_cmds = {n for n, c in category_map.items() if c == 'vulkansc'}
    disabled_cmds = {n for n, c in category_map.items() if c == 'disabled'}
    alias_cmds    = set(alias_map.keys())

    gen_all_approx = vulkan_cmds  # what gen_vulkan_stub.py --all covers

    # Pre-compute platform groups (needed in both header and detail sections)
    platform_groups = {}   # guard -> [name, ...]
    no_platform = []
    for name in sorted(vulkan_cmds):
        guard = cmd_protect.get(name)
        if guard:
            platform_groups.setdefault(guard, []).append(name)
        else:
            no_platform.append(name)

    print("=" * 60)
    print(f"  vk.xml API ANALYSIS  (Vulkan {version})")
    print("=" * 60)
    print(f"  Total unique commands in vk.xml     : {len(all_cmds)}")
    print(f"    Canonical definitions              : {len(canonical_cmds)}")
    print(f"    Alias definitions                  : {len(alias_cmds)}")
    print(f"")
    print(f"  By category:")
    print(f"    Standard Vulkan commands           : {len(vulkan_cmds)}")
    print(f"      No platform guard                : {len(no_platform)}")
    for guard in sorted(platform_groups):
        count = len(platform_groups[guard])
        print(f"      {guard:<36}: {count}")
    print(f"    VulkanSC-only commands             : {len(vulkansc_cmds)}")
    print(f"    Disabled extension commands        : {len(disabled_cmds)}")
    print(f"")
    print(f"  gen_vulkan_stub.py --all stubs       : {len(gen_all_approx)}")
    print(f"    (misses VulkanSC-only + disabled)")
    print(f"  gen_vulkan_stub_all.py stubs         : {len(all_cmds)}")
    print(f"    Additional commands covered        : {len(all_cmds) - len(gen_all_approx)}")
    print("=" * 60)

    # ── Per-platform detail ───────────────────────────────────────────────────
    print()
    print("Platform-specific commands (Standard Vulkan):")
    print("-" * 60)

    for guard in sorted(platform_groups):
        cmds = platform_groups[guard]
        print(f"\n  [{guard}]  ({len(cmds)} commands)")
        for n in cmds:
            alias_note = f"  → alias of {alias_map[n]}" if n in alias_map else ""
            print(f"    {n}{alias_note}")

    print(f"\n  [No platform guard]  ({len(no_platform)} commands)")
    for n in no_platform:
        alias_note = f"  → alias of {alias_map[n]}" if n in alias_map else ""
        print(f"    {n}{alias_note}")

    print()
    if vulkansc_cmds:
        print("VulkanSC-only commands:")
        for n in sorted(vulkansc_cmds):
            print(f"  {n}")
        print()
    if disabled_cmds:
        print("Disabled extension commands:")
        for n in sorted(disabled_cmds):
            print(f"  {n}")


# ── Main ──────────────────────────────────────────────────────────────────────

def main():
    ap = argparse.ArgumentParser(
        description='Generate a COMPLETE Vulkan stub C source from vk.xml '
                    '(all commands including VulkanSC and disabled).',
        formatter_class=argparse.RawDescriptionHelpFormatter,
        epilog=__doc__)
    ap.add_argument('vk_xml', metavar='vk.xml',
                    help='Path to the Khronos vk.xml registry file.')
    ap.add_argument('--analyse', action='store_true',
                    help='Print API count analysis to stdout and exit '
                         '(no C code generated).')
    args = ap.parse_args()

    with open(args.vk_xml) as fh:
        xml = fh.read()

    ret_map, param_map, alias_map = build_command_maps(xml)
    category_map  = collect_all_commands(xml)
    cmd_protect   = build_platform_guard_map(xml)
    disabled_guard = build_disabled_guard_map(xml)

    if args.analyse:
        print_analysis(xml, category_map, ret_map, alias_map, cmd_protect)
        return

    version   = parse_vulkan_version(xml)
    all_names = sorted(category_map.keys())

    # C file header
    total = len(all_names)
    print(f'''\
/* Platform headers are included conditionally — define VK_USE_PLATFORM_*
 * via compiler flags (e.g. -DVK_USE_PLATFORM_WAYLAND_KHR) to enable the
 * corresponding platform stubs.  The recipe (vulkan-stub.bb) does this
 * automatically from DISTRO_FEATURES.
 *
 * Used at build time; replaced at runtime by the vendor libvulkan.so.
 */
#include <vulkan/vulkan.h>
#ifdef VK_USE_PLATFORM_WAYLAND_KHR
#include <vulkan/vulkan_wayland.h>
#endif
#ifdef VK_USE_PLATFORM_XCB_KHR
#include <vulkan/vulkan_xcb.h>
#endif
#ifdef VK_USE_PLATFORM_XLIB_KHR
#include <vulkan/vulkan_xlib.h>
#endif
#ifdef VK_USE_PLATFORM_XLIB_XRANDR_EXT
#include <vulkan/vulkan_xlib_xrandr.h>
#endif
#ifdef VK_USE_PLATFORM_WIN32_KHR
#include <vulkan/vulkan_win32.h>
#endif
#ifdef VK_USE_PLATFORM_ANDROID_KHR
#include <vulkan/vulkan_android.h>
#endif
#ifdef VK_USE_PLATFORM_METAL_EXT
#include <vulkan/vulkan_metal.h>
#endif
#include <vulkan/vulkan_beta.h>
#pragma GCC diagnostic ignored "-Wunused-parameter"
''')

    active_guard = None

    def _set_guard(new_guard):
        nonlocal active_guard
        if new_guard != active_guard:
            if active_guard is not None:
                print('#endif /* {} */\n'.format(active_guard))
            if new_guard is not None:
                print('#ifdef {}'.format(new_guard))
            active_guard = new_guard

    # Group: disabled extension commands
    print('/* ── Disabled-extension commands ─────────────────────────────────── */')
    disabled_names = sorted(n for n in all_names if category_map[n] == 'disabled')
    for name in disabled_names:
        guard = disabled_guard.get(name, 'VK_DISABLED_EXTENSION')
        _set_guard(guard)
        canon  = resolve(name, alias_map, ret_map)
        ret    = ret_map.get(canon, 'void')
        params = param_map.get(canon, [])
        print(emit_stub(name, ret, params))
    _set_guard(None)

    # Group: VulkanSC-only commands
    print('\n/* ── VulkanSC-only commands ───────────────────────────────────────── */')
    _set_guard('VKSC_VERSION_1_0')
    vksc_names = sorted(n for n in all_names if category_map[n] == 'vulkansc')
    for name in vksc_names:
        canon  = resolve(name, alias_map, ret_map)
        ret    = ret_map.get(canon, 'void')
        params = param_map.get(canon, [])
        print(emit_stub(name, ret, params))
    _set_guard(None)

    # Group: standard Vulkan commands (with platform guards as needed)
    print('\n/* ── Standard Vulkan commands ─────────────────────────────────────── */')
    vulkan_names = sorted(n for n in all_names if category_map[n] == 'vulkan')
    for name in vulkan_names:
        guard = cmd_protect.get(name)
        _set_guard(guard)
        canon  = resolve(name, alias_map, ret_map)
        ret    = ret_map.get(canon, 'void')
        params = param_map.get(canon, [])
        print(emit_stub(name, ret, params))
    _set_guard(None)


if __name__ == '__main__':
    main()
