SUMMARY = "C++ Firebolt Client"
DESCRIPTION = "Recipe for building C++ Firebolt Client"

LICENSE = "Apache-2.0"

inherit cmake

FIREBOLT_CORE_VERSION = "1.8.0-next.30"

SRC_URI = "https://github.com/rdkcentral/firebolt-apis/releases/download/v${FIREBOLT_CORE_VERSION}/firebolt-apis--native-core-${FIREBOLT_CORE_VERSION}.tar.gz"
SRC_URI[sha256sum] = "9782fdc428e343ab1cd5cf43042257dc34ffe13edffd14c513c1370d9d2b53e7"

S = "${WORKDIR}/firebolt-apis--native-core-${FIREBOLT_CORE_VERSION}"

LICENSE_LOCATION = "${S}/LICENSE"
LIC_FILES_CHKSUM = "file://${LICENSE_LOCATION};md5=b1e01b26bacfc2232046c90a330332b3"

DEPENDS = "firebolt-cpp-transport nlohmann-json"
RDEPENDS:${PN} = "firebolt-cpp-transport"

PACKAGES = "${PN} ${PN}-dbg"

FILES:${PN} += "${libdir} ${includedir}/firebolt"
FILES:${PN}-dbg += "${libdir}/.debug"

INSANE_SKIP:${PN} = "dev-so"
