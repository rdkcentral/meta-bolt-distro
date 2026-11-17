# EyilClient and protocol libraries for Bolt applications

Copyright 2026 RDK Management. SPDX-License-Identifier: Apache-2.0.

`eyil-client.bb` builds the application-side Eyil C client and the shared C++
RPC/Crypto Protobuf bindings. It requires ZeroMQ, Protobuf and host `protoc`,
without Thunder, entservices-apis, ICrypto or the Gateway transport patch.

## Runtime and SDK ownership

Both base-layer profiles install `eyil-client`. Its dependencies provide the
protocol and transport libraries. The application therefore uses libraries from
its Bolt base layer rather than copying host middleware libraries or bundling
another copy into each application. Applications must use a compatible base
layer release and SDK.

The profile SDK exports `eyil-client-dev`, including the client and generated
protocol headers, linker symlinks, CMake packages, pkg-config metadata and proto
sources. Protobuf development files are pulled in as a dependency.

| Recipe package | Contents |
| --- | --- |
| `eyil-client` | `libeyilclient.so.*` |
| `eyil-client-protocol` | `libeyilprotocol.so.*` |
| `eyil-client-dev` | Public headers, link-time files, CMake/pkg-config metadata and `.proto` files |
| `eyil-client-tools` | Optional `CryptoTestClient` built for the Bolt ABI |

Yocto may rename shared-library runtime packages according to their SONAME.
Recipe dependencies and SDK selection use the recipe package names above.
There is no Gateway plugin, configuration, startup service or CryptoTestBackend
in these packages.

Middleware independently builds its Gateway and host protocol from
`meta-rdk-video/recipes-extended/eyil-secure-gateway/eyil-secure-gateway.bb`.
The host and container communicate using the RPC wire protocol; they do not
share C++ objects or need identical Protobuf runtime binaries. Within either
process, use bindings and Protobuf from that process's SDK and load only one
implementation of the generated Eyil descriptors.

Keep the source revision and wire definitions aligned with the selected Gateway
release. When updating the revision, verify the Protobuf/runtime compatibility
and schema handling on both sides. Do not mix the host and Bolt packages in one
rootfs. Gateway's patched ZeroMQ remains a host dependency; the application
client uses the standard DEALER and monitor APIs.

## Build and consume

```sh
bitbake eyil-client
bitbake base-bolt-image
bitbake base-bolt-image -c populate_sdk
```

For the slim profile, build `rdke-app-baselayer-p2` and its `populate_sdk` task
instead. The distro includes a package-scoped license exception for the
ZeroMQ 4.3.4 dependency; it does not relax the general incompatible-license
policy.

An application recipe declares build dependencies, without adding Gateway:

```bitbake
inherit cmake
DEPENDS += "eyil-client protobuf"
```

```cmake
find_package(EyilClient CONFIG REQUIRED)
find_package(EyilProtocol CONFIG REQUIRED)
target_link_libraries(my_app PRIVATE
    EyilClient::EyilClient
    EyilProtocol::EyilProtocol
)
```

```cpp
#include <eyilclient/EyilClient.h>
#include <eyilprotocol/rpc.pb.h>
#include <eyilprotocol/crypto.pb.h>
```

Link the SDK protocol library instead of compiling another copy of its
generated `.pb.cc` files. C-only EyilClient consumers need only the C header;
service-specific serialization is handled by their chosen service layer.

## Optional container diagnostic client

For a development image, enable the tools and explicitly select their package:

```bitbake
PACKAGECONFIG:append:pn-eyil-client = " dev-tools"
IMAGE_INSTALL:append = " eyil-client-tools"
```

These settings belong in the development image configuration. Tools are not
enabled or installed by default and are not pulled in by `eyil-client-dev`.
CryptoTestBackend remains a separate host middleware development plugin.
Do not substitute the host-built CryptoTestClient for the Bolt-built executable
without validating its entire runtime ABI and dependencies.

The platform must expose the Gateway socket to the application container at
`/tmp/app-eyil-gateway.ipc`; the base layer does not create or mount that socket.
