/*
 * Common board functions for OXNAS based boards.
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
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston,
 * MA 02111-1307 USA
 */

#include <common.h>

#include <asm/arch/hardware.h>
#include <asm/arch/io.h>
#include <asm/arch/sys_proto.h>

int dram_init(void)
{
	DECLARE_GLOBAL_DATA_PTR;

	gd->bd->bi_dram[0].start = PHYS_SDRAM_1_PA;
	gd->bd->bi_dram[0].size = probe_sdr_size();

#if defined(CONFIG_SYS_SRAM_BASE) && defined(CONFIG_SYS_SRAM_SIZE)
	gd->bd->bi_sramstart = CONFIG_SYS_SRAM_BASE;
	gd->bd->bi_sramsize = CONFIG_SYS_SRAM_SIZE;
#endif

	return 0;
}