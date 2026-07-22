SUMMARY = "Rialto-gstreamer"
LICENSE = "LGPLv2.1"
LIC_FILES_CHKSUM = "file://COPYING.LGPL;md5=23c2a5e0106b99d75238986559bb5fc6"

SRC_URI = "git://github.com/rdkcentral/rialto-gstreamer;protocol=https;branch=master"

# SRCREV for v0.20.1
SRCREV = "459651b3d33b40f4f6161a9789786d653cd762f5"

DEPENDS = "rialto-client rialto-ocdm gstreamer1.0 gstreamer1.0-plugins-base"

S = "${WORKDIR}/git"
inherit pkgconfig cmake

FILES:${PN} = "${libdir}/gstreamer-1.0/libgstrialtosinks.so"

