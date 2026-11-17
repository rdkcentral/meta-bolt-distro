include westeros.inc

SUMMARY = "Essos is a library making it simple to create applications that run either as native EGL or Wayland clients."
LICENSE = "Apache-2.0"
LIC_FILES_CHKSUM = "file://${LICENSE_LOCATION};md5=7df5a8706277b586ca000838046993d1"

SRC_URI:append = " file://001-enable-building-wayland-code-without-xkb.patch \
                 "

SRC_URI = "${ESSOS_URI}"

SRCREV_FORMAT = "essos"

S = "${WORKDIR}/git"

DEPENDS = "wayland virtual/egl westeros-simpleshell"

inherit autotools pkgconfig

EXTRA_OECONF:append = " --enable-essoswesterosfree "
EXTRA_OECONF:append = " --enable-essosresmgrfree "

PACKAGES =+ "${PN}-examples"
FILES:${PN}-examples += "${bindir}/*"

