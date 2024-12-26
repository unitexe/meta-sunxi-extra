KBUILD_DEFCONFIG:olinuxino-a20-emmc = "sunxi_defconfig"

FILESEXTRAPATHS:prepend := "${THISDIR}/files:"

SRC_URI:append = " file://unit.cfg"

# Pull in the devicetree files into the rootfs
RDEPENDS_${KERNEL_PACKAGE_NAME}-base += "kernel-devicetree"

KERNEL_EXTRA_ARGS += "LOADADDR=${UBOOT_ENTRYPOINT}"
