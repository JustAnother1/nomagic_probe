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

#include <stdint.h>
#include "cfg/config_file_reader.h"
#include "cfg/serial_cfg.h"
#include "cli/cli_priv.h"
#include "file/file_system.h"
#include "gdbserver/gdbserver.h"
#include "hal/debug_uart.h"
#include "hal/time_base.h"
#include "hal/hw/IO_BANK0.h"
#include "hal/hw/PADS_BANK0.h"
#include "hal/hw/PSM.h"
#include "hal/hw/RESETS.h"
#include "hal/hw/SIO.h"
#include "hal/hw/XOSC.h"
#include "hal/target_uart.h"
#include "hal/watchdog.h"
#include "led.h"
#include "lib/printf.h"
#include "swd/swd_engine.h"
#include "target.h"
#include "target/target_uart_handler.h"
#include "tinyusb/usb.h"
#include "tinyusb/src/tusb.h"

#ifdef BOOT_ROM_ENABLED
#include "hal/boot_rom.h"
#endif

#ifdef FEAT_DEBUG_CDC
#include "tinyusb/usb_cdc.h"
#endif

#ifdef FEAT_USB_NCM
#include "cfg/network_cfg.h"
#include "lwip.h"
#endif


#define TASK_LOOP_0           0x1ul
#define TASK_LOOP_1           0x2ul
#define ALL_SUPERVISED_TASKS  (TASK_LOOP_0 | TASK_LOOP_1)


static void init_0(void);
static void init_1(void);
static void loop_0(void);
static void loop_1(void);

static uint32_t task_list = 0;

static void init_0(void)
{
#ifdef BOOT_ROM_ENABLED
    boot_rom_check_if_valid();
#endif

    task_list = ALL_SUPERVISED_TASKS;
    watchdog_enable();

init_printf(NULL, serial_debug_putc);

#ifdef FEAT_USB_MSC
    file_system_init();
#endif

    read_config_file();

    usb_init();

#ifdef FEAT_USB_NCM
    network_stack_init();
#endif

    target_init();

#ifdef FEAT_GDB_SERVER
    gdbserver_init();
#endif

    if(true == serial_cfg_is_target_UART_enabled())
    {
        target_uart_handler_init();
    }

#if (defined FEAT_DEBUG_UART) || (defined FEAT_DEBUG_CDC)
    cli_init(); // should be last to signal that initialization is complete.
#endif
}

static void init_1(void)
{
    led_init();
}

static void loop_0(void)
{
    // software watch dog
    watchdog_enter_section(SECTION_WATCHDOG);
    task_list = task_list &~TASK_LOOP_0;
    if(0 == task_list)
    {
        watchdog_feed();
        task_list = ALL_SUPERVISED_TASKS;
    }
    watchdog_leave_section(SECTION_WATCHDOG);

    // command line interface to debug this firmware(not the target)
#if (defined FEAT_DEBUG_UART) || (defined FEAT_DEBUG_CDC)
    watchdog_enter_section(SECTION_CLI);
#if (defined FEAT_DEBUG_UART)
    debug_uart_tick();
#endif
    cli_tick();
    watchdog_leave_section(SECTION_CLI);
#endif

    // keep the USB interface alive (tinyUSB)
    watchdog_enter_section(SECTION_USB);
    usb_tick();
    watchdog_leave_section(SECTION_USB);

    // handle the gdb-server protocol
#ifdef FEAT_GDB_SERVER
    watchdog_enter_section(SECTION_GDBSERVER);
    gdbserver_tick();
    watchdog_leave_section(SECTION_GDBSERVER);
#endif

    // keep USB networking alive
#ifdef FEAT_USB_NCM
    if(true == network_cfg_is_network_enabled())
    {
        watchdog_enter_section(SECTION_LWIP);
        network_stack_tick();
        watchdog_leave_section(SECTION_LWIP);
    }
    // else no network
#endif
}

static void loop_1(void)
{
    // flag for watch dog that function has been called again
    task_list = task_list &~TASK_LOOP_1;

    // blink the LED to let the user know everything is fine
    watchdog_enter_section(SECTION_LED);
    led_tick();
    watchdog_leave_section(SECTION_LED);

    // debug protocol state machine (above SWD but below gdb-server)
    watchdog_enter_section(SECTION_TARGET);
    target_tick();
    watchdog_leave_section(SECTION_TARGET);

    // move bytes from the UART that is connected to the debugged chip to the PC
    watchdog_enter_section(SECTION_TARGET_UART);
    if(true == serial_cfg_is_target_UART_enabled())
    {
        target_uart_handler_tick();
        target_uart_tick();
    }
    watchdog_leave_section(SECTION_TARGET_UART);
}

#ifdef ENABLE_CORE_1
int main1(void)
{
    watchdog_enter_section(SECTION_INIT);
    init_1();
    watchdog_leave_section(SECTION_INIT);
    for(;;)
    {
        loop_1();
    }
}

static void wake_up_core1(void)
{
    // if you are using the SDK then you can simply use the multicore_launch_core1 function to launch code on processor core 1.

    // values to be sent in order over the FIFO from core 0 to core 1
    //
    // vector_table is value for VTOR register
    // sp is initial stack pointer (SP)
    // entry is the initial program counter (PC) (don't forget to set the thumb bit!)
    const uint32_t cmd_sequence[6] = {0, 0, 1, (uintptr_t) &__VECTOR_TABLE, (uintptr_t) 0x20040fff, (uintptr_t) ((uint32_t)(&main1) | 1)};
    uint32_t seq = 0;
    uint32_t response = 0;
    uint32_t tries = 0;
    do {
        uint32_t cmd = cmd_sequence[seq];
        // always drain the READ FIFO (from core 1) before sending a 0
        if (!cmd)
        {
            // discard data from read FIFO until empty
            while (0 != (SIO->FIFO_ST & 1))
            {
                response = SIO->FIFO_RD;
            }
            // execute a SEV as core 1 may be waiting for FIFO space
            __asm volatile ("sev");
        }
        // write 32 bit value to write FIFO
        // We wait for the fifo to have some space
        while (0 == (SIO->FIFO_ST & 2))
            ;

        SIO->FIFO_WR = cmd;

        // Fire off an event to the other core
        __asm volatile ("sev");

        // read 32 bit value from read FIFO once available
        // If nothing there yet, we wait for an event first,
        // to try and avoid too much busy waiting
        while (1 == (SIO->FIFO_ST & 1))
        {
            response = SIO->FIFO_RD;
        }

        response = SIO->FIFO_RD;

        // move to next state on correct response (echo-d value) otherwise start over
        if(cmd == response)
        {
            seq = seq +1;
        }
        else
        {
            seq = 0;
            tries++;
        }
    } while ((seq < 6) && (tries < 6));
}
#endif

int main(void)
{
    watchdog_enter_section(SECTION_INIT);
#ifdef ENABLE_CORE_1
    if(0 != SIO->CPUID)
    {
        // soft reset with core1 active ?
        main1();
    }
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

