# meta-bolt-app-examples

Bitbake meta layer extending the **bolt** distro with recipes allowing to build wayland egl test OCI image.

# Setup and building

See [Setup and building](https://github.com/rdkcentral/meta-bolt-distro/blob/develop/README.md#setup-and-building)
section in the [meta-bolt-distro](https://github.com/rdkcentral/meta-bolt-distro) documentation.

## wayland egl test OCI image building instructions

* Download this repository and enter its root directory.
```
git clone https://github.com/rdkcentral/meta-bolt-distro.git
cd meta-bolt-distro
```

* Setup the build environment.
```
source setup-environment
```

* Start building the wayland egl test OCI image.
```
bitbake wayland-egl-bolt-image
```
