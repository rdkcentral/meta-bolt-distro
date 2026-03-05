
do_install:append() {

    # don't remove libwayland-cursor 
    # toyota flutter-auto embedder needs libwayland-cursor https://github.com/toyota-connected/ivi-homescreen/tree/v2.0
    # rm -rf ${D}${libdir}/libwayland-cursor.so*
    # removes wayland.xml core protocol description
    rm -rf ${D}${datadir}/wayland
}

