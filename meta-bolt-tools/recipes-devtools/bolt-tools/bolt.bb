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

SRC_URI = "git://github.com/rdkcentral/bolt-tools.git;branch=main;protocol=https"
SRCREV = "ab6f1c456f814157d087f6cb82080f3931d0e4e2"

S = "${WORKDIR}/git/bolt"

do_install() {
  install -d ${D}${datadir}/bolt
  cp -r ${S}/bin ${D}${datadir}/bolt
  cp -r ${S}/src ${D}${datadir}/bolt
  install -d ${D}${bindir}
  ln -rs ${D}${datadir}/bolt/bin/bolt ${D}${bindir}/bolt
}

BBCLASSEXTEND = "native nativesdk"
