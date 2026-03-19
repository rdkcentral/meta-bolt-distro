SUMMARY = "Provides essential root filesystem directories for container runtime"
LICENSE = "Apache-2.0"
LIC_FILES_CHKSUM = "file://${COMMON_LICENSE_DIR}/Apache-2.0;md5=89aea4e17d99a7cacdbeed46a0096b10"

do_install() {
  install -d ${D}/data
  install -d ${D}/dev
  install -d ${D}/proc
  install -d ${D}/rootdir
  install -d ${D}/sys
  install -d ${D}/tmp
}

FILES:${PN} = "/"
