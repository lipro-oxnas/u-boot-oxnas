/*
 * OXE800 and OXE810: DDR SDRAM control (DDRCTRL)
 *
 * (C) Copyright 2005
 * Oxford Semiconductor Ltd
 *
 * (C) Copyright 2013
 * Stephan Linz <linz@li-pro.net>
 *
 * See file CREDITS for list of people who contributed to this
 * project.
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation; either version 2 of
 * the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.	 See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston,
 * MA 02111-1307 USA
 */

#ifndef __ASM_ARCH_OXNAS_DDRCTRL_H
#define __ASM_ARCH_OXNAS_DDRCTRL_H

#include <asm/arch/bitfield.h>

/* Bits in DDR_CTRL_CFG */
#define DDR_CTRL_CFG_SDR		_BV(16)
#define DDR_CTRL_CFG_SIZE_BIT		17
#define DDR_CTRL_CFG_SIZE_MASK		_BM(4, DDR_CTRL_CFG_SIZE_BIT)
#define DDR_CTRL_CFG_SIZE_MBPO2(PO2)	_BSV(PO2, DDR_CTRL_CFG_SIZE_BIT, \
						DDR_CTRL_CFG_SIZE_MASK)
#define DDR_CTRL_CFG_BANKS_BIT		23
#define DDR_CTRL_CFG_BANKS		_BV(DDR_CTRL_CFG_BANKS_BIT)

#define PO2_1MB				0
#define PO2_2MB				1
#define PO2_4MB				2
#define PO2_8MB				3
#define PO2_16MB			4
#define PO2_32MB			5
#define PO2_64MB			6
#define PO2_128MB			7
#define PO2_256MB			8
#define PO2_512MB			9
#define PO2_1GB				10
#define PO2_2GB				11
#define PO2_4GB				12
#define PO2_8GB				13
#define PO2_16GB			14
#define PO2_32GB			15

/* Bits in DDR_CTRL_BLKEN */
#define DDR_CTRL_BLKEN_CLIENTS_MASK	_BM(16, 0)
#define DDR_CTRL_BLKEN_CLIENTS(VAL)	_BSV(VAL, 0, \
						DDR_CTRL_BLKEN_CLIENTS_MASK)
#define DDR_CTRL_BLKEN_CORE		_BV(31)

/* Bits in DDR_CTRL_AHB */
#define DDR_CTRL_AHB_FLUSH_RCACHE_MASK	_BM(16,	0)
#define DDR_CTRL_AHB_FLUSH_RCACHE(VAL)	_BSV(VAL, 0, \
						DDR_CTRL_AHB_FLUSH_RCACHE_MASK)

#define DDR_CTRL_AHB_FLUSH_RCACHE_ARMD	_BV(0)
#define DDR_CTRL_AHB_FLUSH_RCACHE_ARMI	_BV(1)
#define DDR_CTRL_AHB_FLUSH_RCACHE_COPRO	_BV(2)
#define DDR_CTRL_AHB_FLUSH_RCACHE_DMAA	_BV(3)
#define DDR_CTRL_AHB_FLUSH_RCACHE_DMAB	_BV(4)
#define DDR_CTRL_AHB_FLUSH_RCACHE_PCI	_BV(5)
#define DDR_CTRL_AHB_FLUSH_RCACHE_GMAC	_BV(6)
#define DDR_CTRL_AHB_FLUSH_RCACHE_USB	_BV(7)

#define DDR_CTRL_AHB_NO_RCACHE_MASK	_BM(16,	16)
#define DDR_CTRL_AHB_NO_RCACHE(VAL)	_BSV(VAL, 16, \
						DDR_CTRL_AHB_NO_RCACHE_MASK)

#define DDR_CTRL_AHB_NO_RCACHE_ARMD	_BV(16)
#define DDR_CTRL_AHB_NO_RCACHE_ARMI	_BV(17)
#define DDR_CTRL_AHB_NO_RCACHE_COPRO	_BV(18)
#define DDR_CTRL_AHB_NO_RCACHE_DMAA	_BV(19)
#define DDR_CTRL_AHB_NO_RCACHE_DMAB	_BV(20)
#define DDR_CTRL_AHB_NO_RCACHE_PCI	_BV(21)
#define DDR_CTRL_AHB_NO_RCACHE_GMAC	_BV(22)
#define DDR_CTRL_AHB_NO_RCACHE_USB	_BV(23)

/* Bits in DDR_CTRL_DLL */
#define DDR_CTRL_DLL_OFFSET_MASK	_BM(16,	0)
#define DDR_CTRL_DLL_OFFSET(VAL)	_BSV(VAL, 0, \
						DDR_CTRL_DLL_OFFSET_MASK)
#define DDR_CTRL_DLL_AUTO		_BV(29)
#define DDR_CTRL_DLL_NOOFFS		_BV(30)
#define DDR_CTRL_DLL_ENABLE		_BV(31)

/* Bits in DDR_CTRL_MON */
#define DDR_CTRL_MON_CLIENT		_BV(0)
#define DDR_CTRL_MON_ALL		_BV(4)

/* Bits in DDR_CTRL_DIAG */
#define DDR_CTRL_DIAG_READS_MASK	_BM(10,	0)
#define DDR_CTRL_DIAG_READS(VAL)	_BSV(VAL, 0, \
						DDR_CTRL_DIAG_READS_MASK)
#define DDR_CTRL_DIAG_WRITES_MASK	_BM(10,	10)
#define DDR_CTRL_DIAG_WRITES(VAL)	_BSV(VAL, 10, \
						DDR_CTRL_DIAG_WRITES_MASK)
#define DDR_CTRL_DIAG_HOLDOFFS_MASK	_BM(12,	20)
#define DDR_CTRL_DIAG_HOLDOFFS(VAL)	_BSV(VAL, 20, \
						DDR_CTRL_DIAG_HOLDOFFS_MASK)

/* Bits in DDR_CTRL_DIAG2 */
#define DDR_CTRL_DIAG2_DIRCHANGES_MASK	_BM(10,	0)
#define DDR_CTRL_DIAG2_DIRCHANGES(VAL)	_BSV(VAL, 0, \
						DDR_CTRL_DIAG2_DIRCHANGES_MASK)

/* Bits in DDR_CTRL_ARB */
#define DDR_CTRL_ARB_DATDIR_NCH		_BV(0)
#define DDR_CTRL_ARB_DATDIR_EN		_BV(1)
#define DDR_CTRL_ARB_REQAGE_EN		_BV(2)
#define DDR_CTRL_ARB_LRUBANK_EN		_BV(3)
#define DDR_CTRL_ARB_MIDBUF		_BV(4)

/* Bits in DDR_CTRL_AHB2 */
#define DDR_CTRL_AHB2_IGNORE_HPROT_MASK	_BM(16,	0)
#define DDR_CTRL_AHB2_IGNORE_HPROT(VAL)	_BSV(VAL, 0, \
						DDR_CTRL_AHB2_IGNORE_HPROT_MASK)

#define DDR_CTRL_AHB2_IGNORE_HPROT_ARMD	_BV(0)
#define DDR_CTRL_AHB2_IGNORE_HPROT_ARMI	_BV(1)
#define DDR_CTRL_AHB2_IGNORE_HPROT_COPRO _BV(2)
#define DDR_CTRL_AHB2_IGNORE_HPROT_DMAA	_BV(3)
#define DDR_CTRL_AHB2_IGNORE_HPROT_DMAB	_BV(4)
#define DDR_CTRL_AHB2_IGNORE_HPROT_PCI	_BV(5)
#define DDR_CTRL_AHB2_IGNORE_HPROT_GMAC	_BV(6)
#define DDR_CTRL_AHB2_IGNORE_HPROT_USB	_BV(7)

#define DDR_CTRL_AHB2_IGNORE_WRAP_MASK	_BM(16,	16)
#define DDR_CTRL_AHB2_IGNORE_WRAP(VAL)	_BSV(VAL, 16, \
						DDR_CTRL_AHB2_IGNORE_WRAP_MASK)

#define DDR_CTRL_AHB2_IGNORE_WRAP_ARMD	_BV(16)
#define DDR_CTRL_AHB2_IGNORE_WRAP_ARMI	_BV(17)
#define DDR_CTRL_AHB2_IGNORE_WRAP_COPRO	_BV(18)
#define DDR_CTRL_AHB2_IGNORE_WRAP_DMAA	_BV(19)
#define DDR_CTRL_AHB2_IGNORE_WRAP_DMAB	_BV(20)
#define DDR_CTRL_AHB2_IGNORE_WRAP_PCI	_BV(21)
#define DDR_CTRL_AHB2_IGNORE_WRAP_GMAC	_BV(22)
#define DDR_CTRL_AHB2_IGNORE_WRAP_USB	_BV(23)

/* Bits in DDR_CTRL_AHB3 */
#define DDR_CTRL_AHB3_DIS_BURST_MASK	_BM(16,	0)
#define DDR_CTRL_AHB3_DIS_BURST(VAL)	_BSV(VAL, 0, \
						DDR_CTRL_AHB3_DIS_BURST_MASK)

#define DDR_CTRL_AHB3_DIS_BURST_ARMD	_BV(0)
#define DDR_CTRL_AHB3_DIS_BURST_ARMI	_BV(1)
#define DDR_CTRL_AHB3_DIS_BURST_COPRO	_BV(2)
#define DDR_CTRL_AHB3_DIS_BURST_DMAA	_BV(3)
#define DDR_CTRL_AHB3_DIS_BURST_DMAB	_BV(4)
#define DDR_CTRL_AHB3_DIS_BURST_PCI	_BV(5)
#define DDR_CTRL_AHB3_DIS_BURST_GMAC	_BV(6)
#define DDR_CTRL_AHB3_DIS_BURST_USB	_BV(7)

#define DDR_CTRL_AHB3_DIS_NONCACHE_MASK	_BM(16,	16)
#define DDR_CTRL_AHB3_DIS_NONCACHE(VAL)	_BSV(VAL, 16, \
						DDR_CTRL_AHB3_DIS_NONCACHE_MASK)

#define DDR_CTRL_AHB3_DIS_NONCACHE_ARMD	_BV(16)
#define DDR_CTRL_AHB3_DIS_NONCACHE_ARMI	_BV(17)
#define DDR_CTRL_AHB3_DIS_NONCACHE_COPRO _BV(18)
#define DDR_CTRL_AHB3_DIS_NONCACHE_DMAA	_BV(19)
#define DDR_CTRL_AHB3_DIS_NONCACHE_DMAB	_BV(20)
#define DDR_CTRL_AHB3_DIS_NONCACHE_PCI	_BV(21)
#define DDR_CTRL_AHB3_DIS_NONCACHE_GMAC	_BV(22)
#define DDR_CTRL_AHB3_DIS_NONCACHE_USB	_BV(23)

/* Bits in DDR_CTRL_AHB4 */
#define DDR_CTRL_AHB4_EN_TIMEOUT_MASK	_BM(16,	0)
#define DDR_CTRL_AHB4_EN_TIMEOUT(VAL)	_BSV(VAL, 0, \
						DDR_CTRL_AHB4_EN_TIMEOUT_MASK)

#define DDR_CTRL_AHB4_EN_TIMEOUT_ARMD	_BV(0)
#define DDR_CTRL_AHB4_EN_TIMEOUT_ARMI	_BV(1)
#define DDR_CTRL_AHB4_EN_TIMEOUT_COPRO	_BV(2)
#define DDR_CTRL_AHB4_EN_TIMEOUT_DMAA	_BV(3)
#define DDR_CTRL_AHB4_EN_TIMEOUT_DMAB	_BV(4)
#define DDR_CTRL_AHB4_EN_TIMEOUT_PCI	_BV(5)
#define DDR_CTRL_AHB4_EN_TIMEOUT_GMAC	_BV(6)
#define DDR_CTRL_AHB4_EN_TIMEOUT_USB	_BV(7)

#define DDR_CTRL_AHB4_EN_WRBEHIND_MASK	_BM(16,	16)
#define DDR_CTRL_AHB4_EN_WRBEHIND(VAL)	_BSV(VAL, 16, \
						DDR_CTRL_AHB4_EN_WRBEHIND_MASK)

#define DDR_CTRL_AHB4_EN_WRBEHIND_ARMD	_BV(16)
#define DDR_CTRL_AHB4_EN_WRBEHIND_ARMI	_BV(17)
#define DDR_CTRL_AHB4_EN_WRBEHIND_COPRO	_BV(18)
#define DDR_CTRL_AHB4_EN_WRBEHIND_DMAA	_BV(19)
#define DDR_CTRL_AHB4_EN_WRBEHIND_DMAB	_BV(20)
#define DDR_CTRL_AHB4_EN_WRBEHIND_PCI	_BV(21)
#define DDR_CTRL_AHB4_EN_WRBEHIND_GMAC	_BV(22)
#define DDR_CTRL_AHB4_EN_WRBEHIND_USB	_BV(23)

#endif /* __ASM_ARCH_OXNAS_DDRCTRL_H */