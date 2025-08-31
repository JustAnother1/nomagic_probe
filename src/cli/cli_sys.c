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
#include <stdlib.h>
#include <string.h>
#include "cfg/cli_cfg.h"
#include "cli_sys.h"
#include "cli_usb.h"
#include "file/file_system.h"
#ifdef FEAT_GDB_SERVER
#include "gdbserver/gdbserver.h"
#endif
#include "hal/boot_rom.h"
#include "hal/flash.h"
#include "hal/hw_divider.h"
#include "hal/hw/TIMER.h"
#include "hal/irq.h"
#include "hal/time_base.h"
#include "hal/watchdog.h"
#include "probe_api/cli.h"
#include "probe_api/debug_log.h"
#include "probe_api/swd.h"
#include "target/target_uart_handler.h"

extern uint32_t __bss_start;
extern uint32_t __bss_end;

extern uint32_t __data_start;
extern uint32_t __data_end;
extern uint32_t __data_in_flash;

extern uint32_t __code_start;
extern uint32_t __code_end;
extern uint32_t __code_in_flash;

extern uint32_t __ro_data_start;
extern uint32_t __ro_data_end;
extern uint32_t __ro_data_in_flash;

extern uint32_t file_system_start;

uint32_t log_state = 0;

static bool startup_report(const uint32_t loop);

bool cmd_time(const uint32_t loop)
{
    (void)loop;
    uint32_t now = time_get_ms();

    uint32_t micro_now = TIMER->TIMERAWL;
    cli_line("micro seconds: %lu µs", micro_now);
    // as you can see above the micro second time will always be a bit "later"
    // then the time in milliseconds, just because it is read after the
    // millisecond time is read.
    cli_msg("time since boot up : ");
    if(now < 1000)
    {
        cli_line("%ld ms", now);
    }
    else
    {
        uint32_t millis;
        uint32_t seconds;
        div_and_mod(now, 1000, &seconds, &millis);
        if(seconds < 60)
        {
            cli_line("%lu.%03lu s", seconds, millis);
        }
        else
        {
            uint32_t minutes;
            div_and_mod(seconds, 60, &minutes, &seconds);
            if(minutes < 60)
            {
                cli_line("%lu:%02lu.%03lu mm:ss",minutes, seconds, millis);
            }
            else
            {
                uint32_t hours;
                div_and_mod(minutes, 60, &hours, &minutes);
                cli_line("%lu:%02lu:%02lu.%03lu hh:mm:ss", hours, minutes, seconds, millis);
            }
        }
    }
    return true;  // we are done
}

bool cmd_parameter_raw(const uint32_t loop)
{
    (void)loop;
    uint32_t i = 0;
    uint8_t* c = cli_get_parameter(i);
    while(c != NULL)
    {
        cli_msg("Parameter %ld :", i);
        while(*c != 0)
        {
            cli_msg(" %02x", *c);
            c++;
        }
        cli_msg("\r\n");
        i++;
        c = cli_get_parameter(i);
    }
    cli_line("\r\nDone!");
    return true;  // we are done
}

bool cmd_die(const uint32_t loop)
{
    (void)loop;
    for(;;)
    {
        ;
    }
    return false;  // will never happen
}

bool cmd_hil_test(const uint32_t loop)
{
    (void)loop;
    uint32_t a;
    uint32_t b;
    uint32_t c;

    // MOD
    a = 40;
    b = 5;
    c = a%b;
    cli_line("40 mod 5 = %ld", c);
    a = 0;
    b = 512;
    c = a%b;
    cli_line("0 mod 512 = %ld", c);
    a = 512;
    b = 512;
    c = a%b;
    cli_line("512 mod 512 = %ld", c);
    a = 1024;
    b = 512;
    c = a%b;
    cli_line("%ld mod %ld = %ld", a, b, c);
    a = 0;
    b = 1;
    c = a%b;
    cli_line("%ld mod %ld = %ld", a, b, c);
    a = 0;
    b = 2;
    c = a%b;
    cli_line("%ld mod %ld = %ld", a, b, c);
    a = 2;
    b = 4;
    c = a%b;
    cli_line("%ld mod %ld = %ld", a, b, c);

    // logic
    a = 0x44;
    b = 0xf;
    c = a&b;
    cli_line("0x44 & 0xf  = %ld (0x4)", c);

    cli_line("\r\nDone!");
    return true;  // we are done
}

static bool startup_report(const uint32_t loop)
{
    switch(loop)
    {
    case 0:  cli_line(".code start:            0x%08lx", (uint32_t)&__code_start); break;
    case 1:  cli_line(".code end:              0x%08lx", (uint32_t)&__code_end); break;
    case 2:  cli_line(".code start in flash:   0x%08lx", (uint32_t)&__code_in_flash); break;
    case 3:  cli_line(".code end in flash:     0x%08lx", (uint32_t)(&__code_in_flash + (&__code_end - &__code_start))); break;

    case 4:  cli_line(".bss start:             0x%08lx", (uint32_t)&__bss_start); break;
    case 5:  cli_line(".bss end:               0x%08lx", (uint32_t)&__bss_end); break;

    case 6:  cli_line(".data start:            0x%08lx", (uint32_t)&__data_start); break;
    case 7:  cli_line(".data end:              0x%08lx", (uint32_t)&__data_end); break;
    case 8:  cli_line(".data start in flash:   0x%08lx", (uint32_t)&__data_in_flash); break;
    case 9:  cli_line(".data end in flash:     0x%08lx", (uint32_t)(&__data_in_flash + (&__data_end - &__data_start))); break;

    case 10: cli_line(".rodata start:          0x%08lx", (uint32_t)&__ro_data_start); break;
    case 11: cli_line(".rodata end:            0x%08lx", (uint32_t)&__ro_data_end); break;
    case 12: cli_line(".rodata start in flash: 0x%08lx", (uint32_t)&__ro_data_in_flash); break;
    case 13: cli_line(".rodata end in flash:   0x%08lx", (uint32_t)(&__ro_data_in_flash + (&__ro_data_end - &__ro_data_start))); break;

    case 14: cli_line("file system start:      0x%08lx", file_system_start); break;
    default: return true;
    }
    return false;
}

bool cmd_info_overview(const uint32_t loop)
{
    switch(loop)
    {
        case 0: cli_line("choose the information to show:"); break;
        case 1: cli_line("1: Startup"); break;
        case 2: cli_line("2: Watchdog"); break;
#ifdef BOOT_ROM_ENABLED
        case 3: cli_line("3: boot ROM"); break;
#else
        case 3: break;
#endif
        case 4: cli_line("4: QSPI"); break;
#ifdef FEAT_USB_MSC
        case 5: cli_line("5: file system"); break;
#else
        case 5: break;
#endif
        case 6: cli_line("6: SWD"); break;
        case 7: cli_line("7: USB"); break;
#ifdef FEAT_GDB_SERVER
        case 8: cli_line("8: gdb-server"); break;
#else
        case 8: break;
#endif
#ifdef FEAT_TARGET_UART
        case 9: cli_line("9: target UART"); break;
#else
        case 9: break;
#endif
        default: cli_line("Done"); return true;  // we are done
    }
    return false;
}

bool cmd_info(const uint32_t loop)
{
    static uint32_t which_info;
    if(0 == loop)
    {
        // first call
        uint8_t* type_str = cli_get_parameter(0);
        which_info = (uint32_t)atoi((const char*)type_str);
    }

    switch(which_info)
    {
        case 0: return cmd_info_overview(loop);
        case 1: return startup_report(loop);
        case 2: return watchdog_report(loop);
#ifdef BOOT_ROM_ENABLED
        case 3: return boot_rom_report(loop);
#else
        case 3: cli_line("Boot ROM not used !"); return true;
#endif
        case 4: return flash_report(loop);
#ifdef FEAT_USB_MSC
        case 5: return file_system_report(loop);
#else
        case 5: cli_line("no file system! target = fixed single"); return true;
#endif
        case 6: return swd_info(loop);
        case 7: return cmd_usb_info(loop);
#ifdef FEAT_GDB_SERVER
        case 8: return gdbs_info(loop);
#else
        case 8: cli_line("gdb server not active !"); return true;
#endif
#ifdef FEAT_TARGET_UART
        case 9: return target_handler_cmd_info(loop);
#else
        case 9: cli_line("target UART not enabled !"); return true;
#endif

        default:
            cli_line("ERROR: invalid information selector(%ld) !", which_info);
            return true;
    }
    return false;
}

bool cmd_log(const uint32_t loop)
{
    (void) loop;
    char* type_str = (char*)cli_get_parameter(0);
    if(0 == strncmp("off", type_str, 3))
    {
        // turn logging off
        log_state = 0;
        cli_line("Logging is now disabled!");
    }
    else if(0 == strncmp("on", type_str, 2))
    {
        // turn logging on
        log_state = 1;
        cli_line("Logging is now enabled!");
    }
    else
    {
        if(0 < strlen(type_str))
        {
            cli_line("ERROR: invalid switch %s ! (use : 'on' or 'off')", type_str);
        }
        if(0 == log_state)
        {
            cli_line("Logging is disabled!");
        }
        else if(1 == log_state)
        {
            cli_line("Logging is enabled!");
        }
        else
        {
            cli_line("Logging was confused! -> now disabled!");
            log_state = 0;
        }
    }
    return true;
}
