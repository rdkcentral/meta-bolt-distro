SUMMARY = "C++ Firebolt: Transport layer"
DESCRIPTION = "Recipe for building Transport layer for C++ Firebolt Clients"

LICENSE = "Apache-2.0"

inherit cmake

FIREBOLT_TRANSPORT_VERSION = "1.0.0-next.21"

SRC_URI = "https://github.com/rdkcentral/firebolt-native-transport/releases/download/v${FIREBOLT_TRANSPORT_VERSION}/firebolt-native-transport-${FIREBOLT_TRANSPORT_VERSION}.tar.gz"
SRC_URI[sha256sum] = "fff284166ed2d1331e67417ff949093b7e21c4e47c786fec3373f0dc5023ed71"

S = "${WORKDIR}/firebolt-native-transport-${FIREBOLT_TRANSPORT_VERSION}"

LICENSE_LOCATION = "${S}/LICENSE"
LIC_FILES_CHKSUM = "file://${LICENSE_LOCATION};md5=b1e01b26bacfc2232046c90a330332b3"

DEPENDS = "nlohmann-json websocketpp boost"
RDEPENDS:${PN} = "websocketpp boost-system"

PACKAGES = "${PN} ${PN}-dbg"

FILES:${PN} += "${libdir} ${includedir}/firebolt"
FILES:${PN}-dbg += "${libdir}/.debug"

INSANE_SKIP:${PN} = "dev-so"
