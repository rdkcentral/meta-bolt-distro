SUMMARY = "Rialto-gstreamer"
LICENSE = "LGPLv2.1"
LIC_FILES_CHKSUM = "file://COPYING.LGPL;md5=23c2a5e0106b99d75238986559bb5fc6"

SRC_URI = "git://github.com/rdkcentral/rialto-gstreamer;protocol=https;branch=master"

+# SRCREV for v0.15.1
+SRCREV = "eb227caee2521f14d81cbf9fa0f199be1cadb97c"

DEPENDS = "rialto-client rialto-ocdm gstreamer1.0 gstreamer1.0-plugins-base"

S = "${WORKDIR}/git"
inherit pkgconfig cmake

FILES:${PN} = "${libdir}/gstreamer-1.0/libgstrialtosinks.so"

