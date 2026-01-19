######################################################################
# RIALTO
######################################################################
#
# Rialto provides a solution to implement the AV (audio and video) pipelines of containerised native applications
# and browsers without exposing hardware-specific handles and critical system resources inside the application containers

SUMMARY = "Rialto Client Library"
LICENSE  = "Apache-2.0"
LIC_FILES_CHKSUM = "file://LICENSE;md5=327e572d11c37963726ba0b02d30cf2c"

SRC_URI = "git://github.com/rdkcentral/rialto;protocol=https;branch=master"

# SRCREV for v0.15.1
SRCREV = "61f6aa83b2dd5abe40dae6a1b64d6c153f2a0eaa"

SRC_URI:append = " file://0001-disable-wrappers-for-client-build.patch \
                 "

DEPENDS = "protobuf protobuf-native"

S = "${WORKDIR}/git"
inherit pkgconfig cmake

EXTRA_OECMAKE:append = " -DRIALTO_BUILD_TYPE=Release "
EXTRA_OECMAKE:append = " -DENABLE_SERVER_MANAGER=OFF "
EXTRA_OECMAKE:append = " -DENABLE_SERVER=OFF "

