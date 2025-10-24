# firebolt meta-bolt-distro
This repository defines and provides the **RDK Firebolt Yocto distribution**, derived from Yocto **Poky** and tailored to build hardware-agnostic **Firebolt Native Applications** and **runtimes**.

A Firebolt Native Application is referred to as a **"bolt" app** or simply a **"bolt"**. Each bolt represents an application or runtime layer (in a defined OCI artifact format) that, together with the Firebolt mandatory **common base layer**, forms a second-generation Downloadable Application Container (**DAC2**) within RDK. The base layer is defined in this distribution (see **meta-bolt-base**).

To support bolt application development in other build and development environments than Yocto, each release of this distribution also has an associated Yocto SDK export, available on the firebolt-sdk repository. The **SDK** release then includes the **cross-compilation toolchain** defined by this distribution (supporting arm, arm64, and amd64 targets), along with **binary releases of the base layer**, header files, and other tools required to build bolt applications.

A **release version** of this distribution, together with its associated base-layer version, provides **support for one or more specific major RDK OS versions** (e.g., **RDK-8**).  
Bolt applications intended to run across devices within a particular major RDK OS version must be built using the corresponding **compatible release** of this distribution and its base layer.

Each release version of this distribution is derived from a specific release version the Yocto Poky reference distribution.

**This repository includes**:

- bitbake config files defining the "bolt" distro
- meta-bolt-base - meta-layer with recipes providing configuration for packages used by the base layer
- meta-bolt-app-examples - meta-layer with recipes required for building sample applications. This layer is not enabled by default; to use it, it must be added to the bblayers.conf file
- meta-bolt-tools - meta-layer with recipes for tools related to creation of OCI artifacts from build artifacts and interaction with STB
- manifests - repo tool manifest files defining all meta-layer repositories and versions required for specific version of this distribution and to build specific version of base layer or example application layer oci artifacts using this distribution.

The following target machines are supported:
- arm   - arm 32bit mode, SDK is only for compiling Apps in userland, kernel can be running 32bit or 64bit mixed mode
- arm64 - arm 64bit mode, requires 64bit kernel, RDK middleware is not fully supporting 64bit mode yet
- amd64 - x86 64bit mode, for running of x86 PC/virtual device

# how to setup and build base-layer

Before using this instruction the build machine must be prepared to meet requirements of the Yocto Project described in the
[Required Packages for the Build Host](https://docs.yoctoproject.org/ref-manual/system-requirements.html#required-packages-for-the-build-host) section
of the Yocto Project documentation and include the [repo tool](https://android.googlesource.com/tools/repo). The recommended Linux distribution for build machines is Ubuntu 20.04.

Setup the **bolt** build environment by executing:
```
source setup-environment
```

If necessary, adjust the configuration based on the displayed instructions:
```
### Welcome to bolt distro ###

Available machines: arm (default), arm64 and amd64

To select a different machine:
  echo 'MACHINE = "arm64"' >> conf/local.conf

To enable multi config:
  echo 'BBMULTICONFIG = "arm arm64 amd64"' >> conf/local.conf

Example targets:
  bitbake rdke-app-baselayer-p1            # no multi config

  bitbake mc:arm:rdke-app-baselayer-p1   \
          mc:arm64:rdke-app-baselayer-p1 \
          mc:amd64:rdke-app-baselayer-p1   # requires multi config
```

To start the base-layer build for the ARM architecture execute:
```
bitbake rdke-app-baselayer-p1
```

## .env

The `.env` file located in the directory from which the `setup-environment` script is sourced can be used to provide
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
