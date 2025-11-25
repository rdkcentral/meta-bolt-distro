# firebolt meta-bolt-distro
This repository defines and provides the **RDK Firebolt Yocto distribution**, derived from Yocto **Poky** and tailored to build hardware-agnostic **Firebolt Native Applications** and **runtimes**.

A Firebolt Native Application is referred to as a **"bolt" app** or simply a **"bolt"**. Each bolt represents an application or runtime layer (in a defined OCI artifact format) that, together with the Firebolt mandatory **common base layer**, forms a second-generation Downloadable Application Container (**DAC2**) within RDK. The base layer is defined in this distribution (see **meta-bolt-base**).

To support bolt application development in other build and development environments than Yocto, each release of this distribution also has an associated Yocto SDK export, available on the firebolt-sdk repository. The **SDK** release then includes the **cross-compilation toolchain** defined by this distribution (supporting arm, arm64, and amd64 targets), along with **binary releases of the base layer**, header files, and other tools required to build bolt applications.

A **release version** of this distribution, together with its associated base-layer version, provides **support for one or more specific major RDK OS versions** (e.g., **RDK-8**).  
Bolt applications intended to run across devices within a particular major RDK OS version must be built using the corresponding **compatible release** of this distribution and its base layer.

Each release version of this distribution is derived from a specific release version the Yocto Poky reference distribution.

**This repository includes**:

- meta-bolt - bitbake config files defining the **bolt** distro
- meta-bolt-base - meta-layer with recipes providing configuration for packages used by the base layer
- meta-bolt-app-examples - meta-layer with recipes required for building sample applications. This layer is not enabled by default; to use it, it must be added to the bblayers.conf file
- meta-bolt-tools - meta-layer with recipes for tools related to creation of OCI artifacts from build artifacts and interaction with STB
- manifests - repo tool manifest files defining all meta-layer repositories and versions required for specific version of this distribution and to build specific version of base layer or example application layer oci artifacts using this distribution.

The following target machines are supported:
- arm   - arm 32bit mode, SDK is only for compiling Apps in userland, kernel can be running 32bit or 64bit mixed mode
- arm64 - arm 64bit mode, requires 64bit kernel, RDK middleware is not fully supporting 64bit mode yet
- amd64 - x86 64bit mode, for running of x86 PC/virtual device

# Setup and building

## Setup of the build host

Before building the base layer, the build host must be prepared as described in the
[Required Packages for the Build Host](https://docs.yoctoproject.org/ref-manual/system-requirements.html#required-packages-for-the-build-host)
section of the Yocto Project documentation and have the [repo tool](https://android.googlesource.com/tools/repo) installed.

In addition to the packages listed in the Yocto Project documentation, it's also worth installing packages that provide functionality for
compiling 32-bit code on 64-bit operating systems, as this functionality is essential for many application build systems. While this may
vary depending on the Linux distribution, installing the `g++-multilib` package is usually sufficient to achieve this.

The recommended Linux distribution for the build host is Ubuntu 20.04.

## Building the base layer OCI image

The base layer can be built by following the steps described below.

* Download this repository and enter its root directory.
```
git clone https://github.com/rdkcentral/meta-bolt-distro.git
cd meta-bolt-distro
```

* Optionally, prepare the [.env](#env) file using your favorite text editor.
```
vi .env
```

* Setup the build environment.
```
source setup-environment
```

* Optionally, adjust the configuration based on the displayed instructions.
```
### Welcome to bolt distro ###

Available machines: arm (default), arm64 and amd64

To select a different machine:
  echo 'MACHINE = "arm64"' >> conf/local.conf

To enable multi config:
  echo 'BBMULTICONFIG = "arm arm64 amd64"' >> conf/local.conf

Example targets:
  bitbake base-bolt-image            # no multi config

  bitbake mc:arm:base-bolt-image   \
          mc:arm64:base-bolt-image \
          mc:amd64:base-bolt-image   # requires multi config
```

* Start building the base layer. If you haven't changed your configuration, the command below will create the base layer for the ARM architecture.
```
bitbake base-bolt-image
```

## Building the base bolt package

To create the base bolt package, follow the same steps as described in the
[Building the base layer OCI image](#building-the-base-layer-oci-image) chapter, but instead calling `bitbake base-bolt-image`,
use the [bolt tool](https://github.com/rdkcentral/bolt-tools/tree/main/bolt) as follows:
```
bolt make base
```

The base bolt package provides the foundation for other bolt packages and is often essential for their creation. A common way to deliver
the base bolt package to other build systems is to use a local package store. The local package store is a directory called `bolts` located in
the parent directory of all build systems' build directories. In most cases, using a `bolts` directory created in your home directory
will be a good idea:
```
mkdir ${HOME}/bolts
```

Once the package store is available, the base bolt package may be copied there manually, or it may be done automatically during the build
process by specifying the `--install` option in the `bolt make` command:
```
bolt make base --install
```

## .env

The `.env` file, located in the directory from which the `setup-environment` script is sourced, can be used to provide
additional environment variables to optimize the build process. Currently, the following variables are supported:
- `BOLT_REPO_INIT_PARAMS` - additional parameters provided to the repo init command
- `BOLT_REPO_SYNC_PARAMS` - additional parameters provided to the repo sync command
- `BOLT_DL_DIR` - specifies value for the [DL_DIR](https://docs.yoctoproject.org/ref-manual/variables.html#term-DL_DIR) variable
- `BOLT_SSTATE_DIR` - specifies value for the [SSTATE_DIR](https://docs.yoctoproject.org/ref-manual/variables.html#term-SSTATE_DIR) variable

An example `.env` file might look like this:
```
BOLT_REPO_SYNC_PARAMS="--no-clone-bundle -v -j$(getconf _NPROCESSORS_ONLN)"
BOLT_DL_DIR=${HOME}/downloads
BOLT_SSTATE_DIR=${HOME}/sstate-cache
```
