# Copyright 2026 RDK Management
# SPDX-License-Identifier: Apache-2.0

SUMMARY = "Eyil C client and shared Crypto/RPC protocol bindings for Bolt applications"
LICENSE = "Apache-2.0"
LIC_FILES_CHKSUM = "file://LICENSE;md5=3b83ef96387f14655fc854ddc3c6bd57"

PV = "1.0.0"
PR = "r0"
# Keep the wire definitions aligned with the Gateway release used by middleware.
# Build the libraries against Bolt's own toolchain and Protobuf runtime.
SRCREV = "180b6ca638967c1138c39ae0ae151700465ca936"
SRC_URI = "git://github.com/rdkcentral/eyil-secure-gateway;protocol=https;branch=topic/RDKEMW-27976"

S = "${WORKDIR}/git"

inherit cmake pkgconfig

DEPENDS = "protobuf protobuf-native zeromq"

# Optional diagnostics are built for the container ABI, without CryptoTestBackend.
PACKAGECONFIG ??= ""
PACKAGECONFIG[dev-tools] = "-DBUILD_EYIL_DEV_TOOLS=ON,-DBUILD_EYIL_DEV_TOOLS=OFF"

EXTRA_OECMAKE += " \
    -DPLUGIN_EYILGATEWAY=OFF \
    -DBUILD_EYILCLIENT=ON \
    -DBUILD_TESTING=OFF \
    -DENABLE_COVERAGE=OFF \
    -DProtobuf_PROTOC_EXECUTABLE=${STAGING_BINDIR_NATIVE}/protoc \
"

PACKAGE_BEFORE_PN += "${PN}-protocol ${PN}-tools"
FILES:${PN} = "${libdir}/libeyilclient.so.*"
FILES:${PN}-protocol = "${libdir}/libeyilprotocol.so.*"
FILES:${PN}-tools = "${bindir}/CryptoTestClient"
FILES:${PN}-dev += " \
    ${includedir}/eyilclient \
    ${includedir}/eyilprotocol \
    ${datadir}/eyil/proto \
    ${libdir}/cmake/EyilClient \
    ${libdir}/cmake/EyilProtocol \
    ${libdir}/pkgconfig/eyilclient.pc \
"

RDEPENDS:${PN} += "${PN}-protocol (= ${EXTENDPKGV})"
RDEPENDS:${PN}-dev += "${PN}-protocol (= ${EXTENDPKGV}) protobuf-dev"
RDEPENDS:${PN}-tools += "${PN} (= ${EXTENDPKGV})"
