/*
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License version 2
 * as published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program; if not, see <http://www.gnu.org/licenses/>
 *
 */

#include "watchdog.h"
#include <hal/hw/VREG_AND_CHIP_RESET.h>
#include <hal/hw/WATCHDOG.h>
#include <hal/hw/PSM.h>
#include <hal/hw/RESETS.h>
#include <hal/hw/TIMER.h>
#include <hal/hw/SIO.h>
#include "cfg/cli_cfg.h"


static uint32_t reaload_value = 10000000; // 100ms = 100000 * 2 = 200000;
// counter counts down 2 times see RP2040-E1
// maximum is 0xff ff ff (16777215µs/2 = 16777.215ms/2 = 16.777215s/2)!

void watchdog_disable(void)
{
    WATCHDOG->CTRL = 0;
}

void watchdog_enable(void)
{
    RESETS->RESET &= ~0x200000ul;  // enable TIMER
    TIMER->DBGPAUSE = 0;
    WATCHDOG->CTRL = 0; // reaload_value| 0x6000000; // disable + stop when debugging
    WATCHDOG->TICK = 12 + 0x200;  // 12 MHz -> 12 ticks per µs, 0x200 = Enable
    watchdog_feed();
    PSM->WDSEL = 0x1ffff; // reset everything
#ifdef DISABLE_WATCHDOG_FOR_DEBUG
    WATCHDOG->CTRL = reaload_value | 0x46000000; // enable + stop when debugging
#else
    WATCHDOG->CTRL = reaload_value | 0x40000000; // enable
#endif
}

void watchdog_feed(void)
{
    WATCHDOG->LOAD = reaload_value;
}

void watchdog_report(void)
{
    uint32_t i = WATCHDOG->REASON;
    switch(i)
    {
        case 0:  debug_line("watch dog : normal reset"); break;
        case 1:  debug_line("watch dog : timer reset"); break;
        case 2:  debug_line("watch dog : forced reset"); break;
        case 3:  debug_line("watch dog : timer + forced reset"); break;
        default: debug_line("watch dog : undocumented reset (%ld)", i); break;
    }
    i = WATCHDOG->SCRATCH0;
    if(0 != i)
    {
        debug_line("data in scratch0 : 0x%08lx", i);
    }
    i = WATCHDOG->SCRATCH1;
    if(0 != i)
    {
        debug_line("data in scratch1 : 0x%08lx", i);
    }
    i = WATCHDOG->SCRATCH2;
    if(0 != i)
    {
        debug_line("data in scratch2 : 0x%08lx", i);
    }
    i = WATCHDOG->SCRATCH3;
    if(0 != i)
    {
        debug_line("data in scratch3 : 0x%08lx", i);
    }
    i = WATCHDOG->SCRATCH4;
    if(0 != i)
    {
        debug_line("data in scratch4 : 0x%08lx", i);
    }
    i = WATCHDOG->SCRATCH5;
    if(0 != i)
    {
        // debug_line("data in scratch5 : 0x%08lx", i);
        debug_line("Core 1 was in section : 0x%08lx", i);
        WATCHDOG->SCRATCH5 = 0;
    }
    i = WATCHDOG->SCRATCH6;
    if(0 != i)
    {
        // debug_line("data in scratch6 : 0x%08lx", i);
        debug_line("Core 0 was in section : 0x%08lx", i);
        WATCHDOG->SCRATCH6 = 0;
    }
    i = WATCHDOG->SCRATCH7;
    if(0 != i)
    {
        // debug_line("data in scratch7 : 0x%08lx", i);
        debug_line("reported reset reason : 0x%08lx", i);
        WATCHDOG->SCRATCH7 = 0;
    }
    i = VREG_AND_CHIP_RESET->CHIP_RESET;
    if(0 != (i & 0x100000))
    {
        debug_line("chip reset: debugger reset");
    }
    if(0 != (i & 0x1000))
    {
        debug_line("chip reset: RUN pin reset");
    }
    if(0 != (i & 0x100))
    {
        debug_line("chip reset: power on or brown out reset");
    }
}

void watchdog_report_issue(uint32_t issue)
{
    WATCHDOG->SCRATCH7 = WATCHDOG->SCRATCH7 | issue;
}

void watchdog_enter_section(uint32_t section)
{
    if(0 == SIO->CPUID)
    {
        WATCHDOG->SCRATCH6 = WATCHDOG->SCRATCH6 | section;
    }
    else
    {
        WATCHDOG->SCRATCH5 = WATCHDOG->SCRATCH5 | section;
    }
}
void watchdog_leave_section(uint32_t section)
{
    if(0 == SIO->CPUID)
    {
        WATCHDOG->SCRATCH6 = WATCHDOG->SCRATCH6 & ~section;
    }
    else
    {
        WATCHDOG->SCRATCH5 = WATCHDOG->SCRATCH5 & ~section;
    }
}
