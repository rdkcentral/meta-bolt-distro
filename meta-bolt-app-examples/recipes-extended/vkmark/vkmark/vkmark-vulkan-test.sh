#!/bin/sh
set -e

#May need it while bolt run --direct
WAYLAND_DISPLAY="${WAYLAND_DISPLAY:-wayland-0}"
XDG_RUNTIME_DIR="${XDG_RUNTIME_DIR:-/run/user/0}"
WAYLAND_SOCKET_PATH="${XDG_RUNTIME_DIR}/${WAYLAND_DISPLAY}"

#Uncomment to enable wayland logs
#WAYLAND_DEBUG=1

export VK_LOADER_DEBUG="${VK_LOADER_DEBUG:-all}"

VKMARK_WINSYS_DIR="/usr/lib/vkmark"
VKMARK_SEQ_1="-b :duration=20.0 -b vertex:interleave=true:duration=20.0 -b vertex:interleave=false:duration=10.0 -b cube -b clear:color=1.0,0.5,0"
run_result=0
ran_any=0

VKMARK_SIZE="${VKMARK_SIZE:-1920x1080}"

run_vkmark() {
    backend=$1
    shift
    time vkmark --winsys "$backend" --winsys-dir="${VKMARK_WINSYS_DIR}" --size "${VKMARK_SIZE}" "$@"
}

run_all_tests() {
    run_vkmark $1 $VKMARK_SEQ_1
    return $?
}

if [ -f "$VKMARK_WINSYS_DIR/wayland.so" ]; then
    if [ -S "$WAYLAND_SOCKET_PATH" ]; then
        echo "=== vkmark: wayland start ==="

        run_all_tests wayland
        run_result=$((run_result + $?))
        echo "=== vkmark: wayland end ==="
        ran_any=1
    else
        echo "vkmark-run: wayland plugin present but WAYLAND_DISPLAY not set, skipping"
    fi
fi

if [ -f "$VKMARK_WINSYS_DIR/xcb.so" ]; then
    if [ -n "$DISPLAY" ]; then
        echo "=== vkmark: xcb start ==="
        run_all_tests xcb
        run_result=$((run_result + $?))
        echo "=== vkmark: xcb end ==="
        ran_any=1
    else
        echo "vkmark-run: xcb plugin present but DISPLAY not set, skipping"
    fi
fi

if [ "$ran_any" -eq 0 ]; then
    echo "vkmark-run: no usable window system found, exiting"
    exit 1
fi

exit $run_result
