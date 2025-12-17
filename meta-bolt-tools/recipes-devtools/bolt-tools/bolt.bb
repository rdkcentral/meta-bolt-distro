SUMMARY = "Tool for making and running bolt packages"
LICENSE = "Apache-2.0"
LIC_FILES_CHKSUM = "file://${S}/../LICENSE;md5=b1e01b26bacfc2232046c90a330332b3"

RDEPENDS:${PN} += "cryptsetup"
RDEPENDS:${PN} += "erofs-utils"
RDEPENDS:${PN} += "nodejs"
RDEPENDS:${PN} += "rsync"
RDEPENDS:${PN} += "umoci"
RDEPENDS:${PN} += "zip"
RDEPENDS:${PN} += "tar"

SRC_URI = "git://github.com/rdkcentral/bolt-tools;branch=main;protocol=https"
SRCREV = "96c3d7ee94c8bffdad583b901c49d6bee2124f9e"

S = "${WORKDIR}/git/bolt"

do_install() {
  install -d ${D}${datadir}/bolt
  cp -r ${S}/bin ${D}${datadir}/bolt
  cp -r ${S}/src ${D}${datadir}/bolt
  install -d ${D}${bindir}
  ln -rs ${D}${datadir}/bolt/bin/bolt ${D}${bindir}/bolt
}

BBCLASSEXTEND = "native nativesdk"
