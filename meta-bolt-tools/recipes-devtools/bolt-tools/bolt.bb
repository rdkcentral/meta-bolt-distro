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
SRCREV = "6270d2338f97e6475ecfaecccb1c64e6dddd190e"

S = "${WORKDIR}/git/bolt"

do_install() {
  install -d ${D}${datadir}/bolt
  cp -r ${S}/bin ${D}${datadir}/bolt
  cp -r ${S}/src ${D}${datadir}/bolt
  install -d ${D}${bindir}
  ln -rs ${D}${datadir}/bolt/bin/bolt ${D}${bindir}/bolt
}

BBCLASSEXTEND = "native nativesdk"
