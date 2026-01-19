SUMMARY = "Rialto-ocdm"
LICENSE  = "Apache-2.0"
LIC_FILES_CHKSUM = "file://LICENSE;md5=1fa88b316b1ce25ab7d95ae4d854ec8f"

SRC_URI = "git://github.com/rdkcentral/rialto-ocdm;protocol=https;branch=master"

# SRCREV for v0.9.3
SRCREV = "4f8e4556754cde3498d960d47fd0827f997ea43b"

DEPENDS = "rialto-client gstreamer1.0 gstreamer1.0-plugins-base ocdm-headers"

S = "${WORKDIR}/git"

inherit pkgconfig cmake


