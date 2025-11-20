# meta-bolt-app-examples

Bitbake meta layer extending the **bolt** distro with recipes allowing to build Cobalt OCI image.

# Setup and building

See [Setup and building](https://github.com/rdkcentral/meta-bolt-distro/blob/develop/README.md#setup-and-building)
section in the [meta-bolt-distro](https://github.com/rdkcentral/meta-bolt-distro) documentation.

## wayland egl OCI image building instructions

* Download this repository and enter its root directory.
```
git clone https://github.com/rdkcentral/meta-bolt-distro.git
cd meta-bolt-distro/meta-bolt-app-examples
```

* Setup the build environment.
```
source setup-environment
```

* Start building the wayland egl OCI image.
```
bitbake wayland-egl-bolt-image                # no multi config

bitbake mc:arm:wayland-egl-bolt-image \
        mc:arm64:wayland-egl-bolt-image \
        mc:amd64:wayland-egl-bolt-image       # requires multi config
```
