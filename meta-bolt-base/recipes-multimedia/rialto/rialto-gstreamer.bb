SUMMARY = "Rialto-gstreamer"
LICENSE = "LGPLv2.1"
LIC_FILES_CHKSUM = "file://COPYING.LGPL;md5=23c2a5e0106b99d75238986559bb5fc6"

SRC_URI = "git://github.com/rdkcentral/rialto-gstreamer;protocol=https;branch=master"

# SRCREV for v0.22.1
SRCREV = "7d81332599b04c9111d824666e8c916470b14092"

DEPENDS = "rialto-client rialto-ocdm gstreamer1.0 gstreamer1.0-plugins-base"

S = "${WORKDIR}/git"
inherit pkgconfig cmake

FILES:${PN} = "${libdir}/gstreamer-1.0/libgstrialtosinks.so"

