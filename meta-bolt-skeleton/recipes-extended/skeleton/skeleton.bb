SUMMARY = "Application skeleton"

LICENSE = "Apache-2.0"
LIC_FILES_CHKSUM = "file://${COMMON_LICENSE_DIR}/Apache-2.0;md5=89aea4e17d99a7cacdbeed46a0096b10"

S = "${WORKDIR}"

SRC_URI = "file://${BPN}.cpp"

do_compile () {
  ${CXX} ${CXXFLAGS} ${LDFLAGS} ${BPN}.cpp -o ${BPN}
}

do_install() {
  install -p -m 0755 -D ${BPN} ${D}${bindir}/${BPN}
}

FILES:${PN} = "${bindir}/${BPN}"
