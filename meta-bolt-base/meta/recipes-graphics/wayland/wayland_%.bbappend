
do_install:append() {
    # removes wayland.xml core protocol description
    rm -rf ${D}${datadir}/wayland
}

