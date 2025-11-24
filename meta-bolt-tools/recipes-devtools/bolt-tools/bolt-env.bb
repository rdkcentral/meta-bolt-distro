SUMMARY = "Environment for the bolt tool"
LICENSE = "Apache-2.0"
LIC_FILES_CHKSUM = "file://${COMMON_LICENSE_DIR}/Apache-2.0;md5=89aea4e17d99a7cacdbeed46a0096b10"

inherit native

DEPENDS += "bolt-native"
DEPENDS += "cryptsetup-native"
DEPENDS += "erofs-utils-native"
DEPENDS += "nodejs-native"
DEPENDS += "rsync-native"
DEPENDS += "umoci-native"
DEPENDS += "zip-native"

PACKAGE_ARCH = "bolt"

do_compile[nostamp] = "1"
