KBUILD_DEFCONFIG:olinuxino-a20-emmc = "sunxi_defconfig"

FILESEXTRAPATHS:prepend := "${THISDIR}/files:"

SRC_URI:append = " file://unit.cfg"
