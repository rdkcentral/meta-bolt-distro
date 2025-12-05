SUMMARY = "Sample Firebolt Application"
DESCRIPTION = "Recipe for building Sample Firebolt Application"

LICENSE = "Apache-2.0"

inherit cmake

SRC_URI = "file://firebolt-app.tgz"
S = "${WORKDIR}/firebolt-app"

LICENSE_LOCATION = "${S}/LICENSE"
LIC_FILES_CHKSUM = "file://${LICENSE_LOCATION};md5=b1e01b26bacfc2232046c90a330332b3"

DEPENDS = "firebolt-cpp-client firebolt-cpp-transport"
RDEPENDS:${PN} = "firebolt-cpp-client firebolt-cpp-transport"

PACKAGES = "${PN} ${PN}-dbg"

FILES:${PN} += "${bindir}"
FILES:${PN}-dbg += "${bindir}/.debug"
