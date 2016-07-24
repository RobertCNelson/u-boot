/*
 *  (C) Copyright 2010-2012
 *  NVIDIA Corporation <www.nvidia.com>
 *
 * SPDX-License-Identifier:	GPL-2.0+
 */

#ifndef __CONFIG_H
#define __CONFIG_H

#include <linux/sizes.h>
#include "tegra20-common.h"

/* High-level configuration options */
#define CONFIG_TEGRA_BOARD_STRING	"Compulab Trimslice"

/* default trimslice settings (different than tegra20-common.h) */
#define CONFIG_SYS_LOAD_ADDR   0x00A00800
#define CONFIG_SYS_TEXT_BASE   0x0010E000

#define CONFIG_LOADADDR        0x00408000
#define MEM_LAYOUT_ENV_SETTINGS \
	"scriptaddr=0x10000000\0" \
	"pxefile_addr_r=0x10100000\0" \
	"kernel_addr_r=0x01000000\0" \
	"fdt_addr_r=0x02000000\0" \
	"ramdisk_addr_r=0x02100000\0"

#define CONFIG_SYS_USB_EHCI_MAX_ROOT_PORTS 2

/* Board-specific serial config */
#define CONFIG_TEGRA_ENABLE_UARTA
#define CONFIG_TEGRA_UARTA_GPU
#define CONFIG_SYS_NS16550_COM1		NV_PA_APB_UARTA_BASE

#define CONFIG_MACH_TYPE		MACH_TYPE_TRIMSLICE

/* SPI */
#define CONFIG_SF_DEFAULT_MODE		SPI_MODE_0

/* I2C */
#define CONFIG_SYS_I2C_TEGRA

/* SD/MMC */
#define CONFIG_MMC
#define CONFIG_GENERIC_MMC
#define CONFIG_TEGRA_MMC

/* Environment in SPI */
#define CONFIG_ENV_IS_IN_SPI_FLASH
#define CONFIG_ENV_SPI_MAX_HZ		48000000
#define CONFIG_ENV_SPI_MODE		SPI_MODE_0
#define CONFIG_ENV_SECT_SIZE		CONFIG_ENV_SIZE
#define CONFIG_ENV_OFFSET		(512 * 1024)

/* USB Host support */
#define CONFIG_USB_EHCI
#define CONFIG_USB_EHCI_TEGRA
#define CONFIG_USB_STORAGE

/* USB networking support */
#define CONFIG_USB_HOST_ETHER
#define CONFIG_USB_ETHER_ASIX

/* PCI host support */
#define CONFIG_PCI
#define CONFIG_PCI_PNP
#define CONFIG_CMD_PCI

/* General networking support */

#include "tegra-common-post.h"

#endif /* __CONFIG_H */
