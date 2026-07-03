SUMMARY = "Stub library for Vulkan ICD loader (libvulkan)"
DESCRIPTION = "Provides a stub libvulkan.so built from the official Khronos \
Vulkan headers. Does nothing at runtime; allows bolt app recipes to link \
against Vulkan at build time. Removed from the base layer OCI rootfs before \
packaging (see stub_gpu_libraries in base-bolt-image.bbclass) and replaced \
at runtime by the real vendor ICD loader from the GPU layer. \
Follows the same pattern as khronos-stubs for EGL and OpenGL ES. \
"

HOMEPAGE             = "https://github.com/KhronosGroup/Vulkan-Headers"

REQUIRED_DISTRO_FEATURES = "vulkan"

S = "${WORKDIR}"
SRC_URI = " \
           file://vulkan-stub.c \
           file://vulkan.pc \
           file://LICENSE.md \
"

# License taken from Vulkan-Headers
LICENSE          = "Apache-2.0 & MIT"
LIC_FILES_CHKSUM = "file://LICENSE.md;md5=1bc355d8c4196f774c8b87ed1a8dd625"

DEPENDS              = "vulkan-headers"

PROVIDES             = "virtual/vulkan-loader"
RPROVIDES:${PN}      = "libvulkan libvulkan1"

BBCLASSEXTEND        = "native"

inherit cmake pkgconfig features_check

CFLAGS:append = "${@bb.utils.contains('DISTRO_FEATURES', 'wayland', ' -DVK_USE_PLATFORM_WAYLAND_KHR', '', d)}"
CFLAGS:append = "${@bb.utils.contains('DISTRO_FEATURES', 'x11', ' -DVK_USE_PLATFORM_XCB_KHR', '', d)}"

do_configure[noexec] = "1"
do_patch[noexec]     = "1"

do_compile() {
    ${CC} ${CFLAGS} ${LDFLAGS} -fPIC -shared \
        -Wl,-soname,libvulkan.so.1 \
        -I${STAGING_INCDIR} \
        -o ${S}/libvulkan.so.1 \
        ${WORKDIR}/vulkan-stub.c
}

do_install() {
    install -d ${D}${libdir}
    install -d ${D}${libdir}/pkgconfig
    install -m 0755 ${S}/libvulkan.so.1 ${D}${libdir}/
    ln -sf libvulkan.so.1  ${D}${libdir}/libvulkan.so
    install -m 0644 ${WORKDIR}/vulkan.pc ${D}${libdir}/pkgconfig/vulkan.pc
}


# skip dev-so in order for the unversioned so file to be packaged as well
FILES:${PN}       += "${libdir}/libvulkan.so* ${libdir}/pkgconfig/vulkan.pc"
FILES:${PN}       += "${libdir}/*.so*"
FILES_SOLIBSDEV    = ""
INSANE_SKIP:${PN} += "dev-so"
INSANE_SKIP:${PN} += "installed-vs-shipped"
