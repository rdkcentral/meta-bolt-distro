SUMMARY = "Wayland egl bolt image"

inherit base-bolt-image

IMAGE_INSTALL += "wayland-egl-test"
IMAGE_INSTALL += "wayland-egl-test-epoxy"
IMAGE_INSTALL += "wayland-egl-test-input"
IMAGE_INSTALL += "wayland-egl-test-input-epoxy"
IMAGE_INSTALL += "xkeyboard-config"
