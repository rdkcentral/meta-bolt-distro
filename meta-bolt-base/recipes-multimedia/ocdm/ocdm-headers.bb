DESCRIPTION = "Recipe to include the latest OCDM header files"
LICENSE = "Apache-2.0"
LIC_FILES_CHKSUM = "file://LICENSE;md5=847677038847363222ffb66cfa6406c2"

SRC_URI = "git://github.com/rdkcentral/ThunderClientLibraries.git;protocol=https;branch=R4_4"
SRC_URI += "file://0001-RDK-OCDM-adapter.patch"
SRC_URI += "file://0003_MediaType_name_changed.patch"

# Oct 17, 2023
SRCREV = "09a75a85e1263e0520f182dea6dc19c673e070a1"

S = "${WORKDIR}/git"

do_compile[noexec] = "1"
do_configure[noexec] = "1"

do_install() {
    install -d ${D}${includedir}/opencdm
    install -m 0644 ${S}/Source/ocdm/open_cdm.h ${D}${includedir}/opencdm/
    install -m 0644 ${S}/Source/ocdm/open_cdm_ext.h ${D}${includedir}/opencdm/
    install -m 0644 ${S}/Source/ocdm/adapter/open_cdm_adapter.h ${D}${includedir}/opencdm/
}

