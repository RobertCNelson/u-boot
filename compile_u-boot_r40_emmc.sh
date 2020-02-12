#!/usr/bin/env bash
###compile uboot m2u
echo "\033[36m Compile U-boot emmc for M2U(R40).\033[0m"
echo "\033[36m Installing dependencies.\033[0m"
sudo apt update && sudo apt install -y swig python-dev python3-dev git
echo "\033[36m changing folder.\033[0m"
cd /tmp
echo "\033[36m cloning u-boot.\033[0m"
git clone https://github.com/juanesf/u-boot.git && cd u-boot && make Bananapi_M2_Ultra_defconfig && make
echo "\033[36m make boot.scr.\033[0m"
mkimage -C none -A arm -T script -d /tmp/u-boot/r40_boot.cmd boot.scr
echo "\033[36m copying binary u-boot emmc.\033[0m"
sudo dd if=/tmp/u-boot/u-boot-sunxi-with-spl.bin of=/dev/mmcblk0p0 bs=1024 seek=8
echo "\033[36m removing dtb.\033[0m"
sudo rm /boot/dtb/sun8i-r40-bananapi-m2-ultra.dtb
echo "\033[36m copying new dtb emmc.\033[0m"
sudo cp /tmp/u-boot/arch/arm/dts/sun8i-r40-bananapi-m2-ultra.dtb /boot/dtb
echo "\033[36m Please reboot Now.\033[0m"
