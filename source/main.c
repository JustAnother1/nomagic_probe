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
#include <hal/debug_uart.h>
#include <hal/hw/IO_BANK0.h>
#include <hal/hw/PADS_BANK0.h>
#include <hal/hw/PSM.h>
#include <hal/hw/RESETS.h>
#include <hal/hw/SIO.h>
#include <hal/hw/XOSC.h>
#include "hal/watchdog.h"
#include "hal/boot_rom.h"
#include "hal/flash.h"
#include "cli/cli.h"
#include "time_base.h"
#include <stdint.h>
#include "tinyusb/usb.h"
#include "tinyusb/src/tusb.h"
#include "led.h"
#include "gdbserver/gdbserver.h"

static void init_0(void);
static void init_1(void);
static void loop_0(void);
static void loop_1(void);


static void init_0(void)
{
    boot_rom_check_if_valid();
    watchdog_enable();
    init_time();
    flash_init();
    debug_uart_initialize();
    cli_init();
    tusb_init(); // initialize tinyusb stack
    gdbserver_init();
}

static void init_1(void)
{
    led_init();
}

static void loop_0(void)
{
    watchdog_enter_section(SECTION_WATCHDOG);
    watchdog_feed();
    watchdog_leave_section(SECTION_WATCHDOG);

    watchdog_enter_section(SECTION_CLI);
    cli_tick();
    watchdog_leave_section(SECTION_CLI);

    watchdog_enter_section(SECTION_USB);
    usb_tick();
    watchdog_leave_section(SECTION_USB);

    watchdog_enter_section(SECTION_GDBSERVER);
    gdbserver_tick();
    watchdog_leave_section(SECTION_GDBSERVER);
}

static void loop_1(void)
{
    watchdog_enter_section(SECTION_LED);
    led_tick();
    watchdog_leave_section(SECTION_LED);
}

#ifdef ENABLE_CORE_1
void main1(void)
{
    watchdog_enter_section(SECTION_INIT);
    init_1();
    watchdog_leave_section(SECTION_INIT);
    for(;;)
    {
        loop_1();
    }
}

#endif

void main(void)
{
    watchdog_enter_section(SECTION_INIT);
#ifdef ENABLE_CORE_1
    init_0();
#else
    init_0();
    init_1();
#endif
    watchdog_leave_section(SECTION_INIT);
    for(;;)
    {
#ifdef ENABLE_CORE_1
        loop_0();
#else
        loop_0();
        loop_1();
#endif
    }
}

