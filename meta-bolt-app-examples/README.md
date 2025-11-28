# meta-bolt-app-examples

Bitbake meta layer extending the **bolt** distro with recipes allowing to build OCI image of app examples.

# Setup and building

See [Setup and building](https://github.com/rdkcentral/meta-bolt-distro/blob/develop/README.md#setup-and-building)
section in the [meta-bolt-distro](https://github.com/rdkcentral/meta-bolt-distro) documentation.

## OCI image building instructions for examples

* Download this repository and enter its root directory.
```
git clone https://github.com/rdkcentral/meta-bolt-distro.git
cd meta-bolt-distro/meta-bolt-app-examples
```

* Setup the build environment.
```
source setup-environment
```

* Start building the OCI images for examples.
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
## Building the example applications as bolt package

To create the bolt packages for the examples, follow the same steps as described in the
[OCI image building instructions for examples](#OCI-image-building-instructions-for-examples) chapter, but instead calling `bitbake <target>`,
use the [bolt tool](https://github.com/rdkcentral/bolt-tools/tree/main/bolt) as follows:
```
bolt make wayland-egl-test
bolt make wayland-egl-test-input
bolt make wayland-egl-epoxy
bolt make wayland-egl-test-input-epoxy
```

To resolve the dependencies defined in package config, the dependent package must be available in the local store. Follow the details in [dependency handling](https://github.com/astolcenburg/bolt-tools/blob/main/bolt/docs/make.md#dependency-handling) for setting up local store.


Use `--install` option in the `bolt make` command to store the output packages in local store

```
bolt make wayland-egl-test --install
bolt make wayland-egl-test-input --install
bolt make wayland-egl-test-epoxy --install
bolt make wayland-egl-test-input-epoxy --install
```
