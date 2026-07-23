DESCRIPTION = "Recipe to include the latest OCDM header files"
LICENSE = "Apache-2.0"
LIC_FILES_CHKSUM = "file://LICENSE;md5=7a65e8e9836ac44d082594220a9a3883"

SRC_URI = "git://github.com/rdkcentral/entservices-opencdmi.git;protocol=https;branch=main"

# Release version - 2.0.2
SRCREV = "96df114e4b6006ef384697bca56104e52e228648"

S = "${WORKDIR}/git"

do_compile[noexec] = "1"
do_configure[noexec] = "1"

do_install() {
    install -d ${D}${includedir}/opencdm
    install -m 0644 ${S}/client/open_cdm.h ${D}${includedir}/opencdm/
    install -m 0644 ${S}/client/open_cdm_ext.h ${D}${includedir}/opencdm/
    install -m 0644 ${S}/client/adapter/open_cdm_adapter.h ${D}${includedir}/opencdm/
}

