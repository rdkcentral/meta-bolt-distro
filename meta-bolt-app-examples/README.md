# meta-bolt-app-examples

Bitbake meta layer extending the **bolt** distro with recipes allowing to build OCI image of app examples.

# Setup and building

See [Setup and building](https://github.com/rdkcentral/meta-bolt-distro/blob/develop/README.md#setup-and-building)
section in the [meta-bolt-distro](https://github.com/rdkcentral/meta-bolt-distro) documentation.

## wayland egl OCI image building instructions

* Download this repository and enter its root directory.
```
git clone https://github.com/rdkcentral/meta-bolt-distro.git
cd meta-bolt-distro
```

* Setup the build environment.
```
source meta-bolt-app-examples/setup-environment
```

* Start building the wayland egl OCI image.
```

bitbake wayland-egl-test-bolt-image \
        wayland-egl-test-epoxy-bolt-image  # no multi config

bitbake mc:arm:wayland-egl-test-bolt-image \
        mc:arm64:wayland-egl-test-bolt-image \
        mc:amd64:wayland-egl-test-bolt-image  \
        mc:arm:wayland-egl-test-epoxy-bolt-image \
        mc:arm64:wayland-egl-test-epoxy-bolt-image \
        mc:amd64:wayland-egl-test-epoxy-bolt-image   # requires multi config

```
