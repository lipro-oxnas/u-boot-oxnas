/*
 * (C) Copyright 2003
 * Texas Instruments <www.ti.com>
 *
 * (C) Copyright 2002
 * Sysgo Real-Time Solutions, GmbH <www.elinos.com>
 * Marius Groeger <mgroeger@sysgo.de>
 *
 * (C) Copyright 2002
 * Sysgo Real-Time Solutions, GmbH <www.elinos.com>
 * Alex Zuepke <azu@sysgo.de>
 *
 * (C) Copyright 2002-2004
 * Gary Jennejohn, DENX Software Engineering, <gj@denx.de>
 *
 * (C) Copyright 2004
 * Philippe Robin, ARM Ltd. <philippe.robin@arm.com>
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

#include <common.h>

#include <asm/arch/hardware.h>
#include <asm/arch/io.h>

static ulong timestamp;
static ulong lastdec;

/* nothing really to do with interrupts, just starts up a counter. */
int timer_init (void)
{
	/* Load 16 bit timer with initial value */
	writew(TIMER_VALUE_MASK, RPS_TIMER_1_LOAD);
	writew(TIMER_VALUE_MASK, RPS_TIMER_1_VALUE);

	/* Set timer to be enabled, periodic run, no interrupts, 256 divider */
	writel(TIMER_CTRL_ENABLE | TIMER_CTRL_MODE_PERIODIC |
			TIMER_CTRL_PRESCALE(TPS_256), RPS_TIMER_1_CONTROL);

	/* init the timestamp and lastdec value */
	reset_timer_masked();

	return 0;
}

/*
 * timer without interrupts
 */

void reset_timer (void)
{
	reset_timer_masked ();
}

ulong get_timer (ulong base)
{
	return get_timer_masked () - base;
}

void set_timer (ulong t)
{
	timestamp = t;
}

/* delay x useconds AND perserve advance timstamp value */
void udelay (unsigned long usec)
{
	ulong tmo, tmp;

	/* if "big" number, spread normalization to seconds */
	if(usec >= 1000){
		tmo = usec / 1000;	/* start to normalize for */
					/* usec to ticks per sec  */
		tmo *= CONFIG_SYS_HZ;	/* find number of "ticks" */
					/* to wait to achieve target */
		tmo /= 1000;		/* finish normalize. */

	/* else small number, don't kill it prior to HZ multiply */
	}else{
		tmo = usec * CONFIG_SYS_HZ;
		tmo /= (1000*1000);
	}

	tmp = get_timer (0);		/* get current timestamp */

	/* if setting this fordward will roll time stamp */
	if( (tmo + tmp + 1) < tmp )
		reset_timer_masked ();	/* reset "advancing" timestamp */
					/* to 0, set lastdec value */

	/* else, set advancing stamp wake up time */
	else
		tmo += tmp;

	while (get_timer_masked () < tmo)/* loop till event */
		/*NOP*/;
}

/* reset timer */
void reset_timer_masked (void)
{
	/* capure current decrementer value time */
	lastdec = readw(RPS_TIMER_1_VALUE) & TIMER_VALUE_MASK;

	/* start "advancing" time stamp from 0 */
	timestamp = 0;
}

ulong get_timer_masked (void)
{
	/* current tick value */
	ulong now = readw(RPS_TIMER_1_VALUE) & TIMER_VALUE_MASK;

	if (lastdec >= now) {
		/* normal mode (non roll) */
		timestamp += lastdec - now;	/* move stamp fordward with */
						/* absoulte diff ticks */

	} else {
		/*
		 * we have overflow of the count down timer
		 * 
		 * nts = ts + ld + (TLV - now)
		 * ts=old stamp, ld=time that passed before passing through -1
		 * (TLV-now) amount of time after passing though -1
		 * nts = new "advancing time stamp"...it could also roll and
		 * cause problems.
		 */
		timestamp += lastdec + TIMER_VALUE_MASK - now;
	}
	lastdec = now;

	return timestamp;
}

/* waits specified delay value and resets timestamp */
void udelay_masked (unsigned long usec)
{
	ulong tmo;
	ulong endtime;
	signed long diff;

	/* if "big" number, spread normalization to seconds */
	if (usec >= 1000) {
		tmo = usec / 1000;	/* start to normalize for */
					/* usec to ticks per sec  */
		tmo *= CONFIG_SYS_HZ;	/* find number of "ticks" */
					/* to wait to achieve target */
		tmo /= 1000;		/* finish normalize. */

	/* else small number, don't kill it prior to HZ multiply */
	} else {
		tmo = usec * CONFIG_SYS_HZ;
		tmo /= (1000*1000);
	}

	endtime = get_timer_masked () + tmo;

	do {
		ulong now = get_timer_masked ();
		diff = endtime - now;
	} while (diff >= 0);
}

/*
 * This function is derived from PowerPC code (read timebase as long long).
 * On ARM it just returns the timer value.
 */
unsigned long long get_ticks(void)
{
	return get_timer(0);
}

/*
 * This function is derived from PowerPC code (timebase clock frequency).
 * On ARM it returns the number of timer ticks per second.
 */
ulong get_tbclk (void)
{
	ulong tbclk;

	tbclk = CONFIG_SYS_HZ;
	return tbclk;
}