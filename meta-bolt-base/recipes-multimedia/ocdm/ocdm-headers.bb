DESCRIPTION = "Recipe to include the latest OCDM header files"
LICENSE = "Apache-2.0"
LIC_FILES_CHKSUM = "file://${COMMON_LICENSE_DIR}/Apache-2.0;md5=89aea4e17d99a7cacdbeed46a0096b10"

SRC_URI = "git://github.com/rdkcentral/ThunderClientLibraries.git;protocol=https;branch=R4_4;name=wpeframework-clientlibraries"

#Tag R4.4.2
SRCREV = "09a75a85e1263e0520f182dea6dc19c673e070a1"

S = "${WORKDIR}/git"

do_compile[noexec] = "1"
do_configure[noexec] = "1"
do_patch[noexec] = "1"

do_install() {
    install -d ${D}${includedir}/opencdm
    install -m 0644 ${S}/Source/ocdm/open_cdm.h ${D}${includedir}/opencdm/
    install -m 0644 ${S}/Source/ocdm/open_cdm_ext.h ${D}${includedir}/opencdm/
    install -m 0644 ${S}/Source/ocdm/adapter/open_cdm_adapter.h ${D}${includedir}/opencdm/
}

