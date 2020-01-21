#!/usr/bin/env bash
###change firmware ap6212
echo "\033[36m Show files in /lib/firmware/ap6212\033[0m"
cd /lib/firmware/ap6212
ls
echo "\033[36m Deleting files.\033[0m"
sudo rm /lib/firmware/brcm/brcmfmac43430-sdio.bin
sudo rm /lib/firmware/brcm/bcm43438-sdio.hcd
echo "\033[36m Copying files.\033[0m"
sudo cp fw_bcm43438a1.bin /lib/firmware/brcm/brcmfmac43430-sdio.bin
sudo cp bcm43438a1.hcd /lib/firmware/brcm/bcm43438-sdio.hcd
sudo cp nvram.txt /lib/firmware/brcm/brcmfmac43430-sdio.sinovoip,bpi-m2-ultra.txt
sudo cp nvram.txt /lib/firmware/brcm/brcmfmac43430-sdio.txt
