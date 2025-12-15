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
SRCREV = "6ee7f29b0b4fa1dada086a67d447ff1f9e964cab"

S = "${WORKDIR}/git/bolt"

do_install() {
  install -d ${D}${datadir}/bolt
  cp -r ${S}/bin ${D}${datadir}/bolt
  cp -r ${S}/src ${D}${datadir}/bolt
  install -d ${D}${bindir}
  ln -rs ${D}${datadir}/bolt/bin/bolt ${D}${bindir}/bolt
}

BBCLASSEXTEND = "native nativesdk"
