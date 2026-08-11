# Adapt upstream recipe to kirkstone
SRC_URI = "git://github.com/KhronosGroup/Vulkan-Loader.git;branch=main;protocol=https"
S = "${WORKDIR}/git"

# Packages do not need to include a GPU driver
RRECOMMENDS:${PN}:remove = "virtual-vulkan-icd"
