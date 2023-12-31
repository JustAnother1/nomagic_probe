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
#include "cli_sys.h"
#include "cfg/cli_cfg.h"
#include "hal/startup.h"
#include "hal/hw_divider.h"
#include <hal/hw/TIMER.h>
#include <hal/time_base.h>
#include "cli.h"
#include "hal/watchdog.h"
#include "hal/boot_rom.h"
#include "hal/flash.h"
#include "file/file_system.h"

bool cmd_time(uint32_t loop)
{
    (void)loop;
    uint32_t now = time_get_ms();

    uint32_t micro_now = TIMER->TIMERAWL;
    debug_line("micro seconds: %lu µs", micro_now);

    debug_msg("time since boot up : ");
    if(now < 1000)
    {
        debug_line("%ld ms", now);
    }
    else
    {
        uint32_t millis;
        uint32_t seconds;
        div_and_mod(now, 1000, &seconds, &millis);
        // millis = now % 1000;
        // debug_line(STR("millis : %u"), millis);
        // seconds = now / 1000;
        // debug_line(STR("seconds : %lu"), seconds);
        if(seconds < 60)
        {
            debug_line("%lu.%03lu s", seconds, millis);
        }
        else
        {
            uint32_t minutes;
            div_and_mod(seconds, 60, &minutes, &seconds);
            // now = seconds;
            // seconds = seconds % 60;
            // debug_line(STR("seconds : %lu"), seconds);
            // minutes = now / 60;
            // debug_line(STR("minutes : %lu"), minutes);
            if(minutes < 60)
            {
                debug_line("%lu:%02lu.%03lu mm:ss",minutes, seconds, millis);
            }
            else
            {
                uint32_t hours;
                div_and_mod(minutes, 60, &hours, &minutes);
                // now = minutes;
                // minutes = minutes % 60;
                // debug_line(STR("minutes : %u"), minutes);
                // hours = now / 60;
                debug_line("%lu:%02lu:%02lu.%03lu hh:mm:ss", hours, minutes, seconds, millis);
            }
        }
    }
    return true;  // we are done
}

bool cmd_parameter_raw(uint32_t loop)
{
    (void)loop;
    uint32_t i = 0;
    uint8_t* c = cli_get_parameter(i);
    while(c != NULL)
    {
        debug_msg("Parameter %ld :", i);
        while(*c != 0)
        {
            debug_msg(" %02x", *c);
            c++;
        }
        debug_msg("\r\n");
        i++;
        c = cli_get_parameter(i);
    }
    debug_line("\r\nDone!");
    return true;  // we are done
}

bool cmd_die(uint32_t loop)
{
    (void)loop;
    for(;;)
    {
        ;
    }
    return false;  // will never happen
}

bool cmd_hil_test(uint32_t loop)
{
    (void)loop;
    uint32_t a;
    uint32_t b;
    uint32_t c;

    // MOD
    a = 40;
    b = 5;
    c = a%b;
    debug_line("40 mod 5 = %ld", c);
    a = 0;
    b = 512;
    c = a%b;
    debug_line("0 mod 512 = %ld", c);
    a = 512;
    b = 512;
    c = a%b;
    debug_line("512 mod 512 = %ld", c);
    a = 1024;
    b = 512;
    c = a%b;
    debug_line("%ld mod %ld = %ld", a, b, c);
    a = 0;
    b = 1;
    c = a%b;
    debug_line("%ld mod %ld = %ld", a, b, c);
    a = 0;
    b = 2;
    c = a%b;
    debug_line("%ld mod %ld = %ld", a, b, c);
    a = 2;
    b = 4;
    c = a%b;
    debug_line("%ld mod %ld = %ld", a, b, c);

    // logic
    a = 0x44;
    b = 0xf;
    c = a&b;
    debug_line("0x44 & 0xf  = %ld (0x4)", c);

    debug_line("\r\nDone!");
    return true;  // we are done
}

bool cmd_info(uint32_t loop)
{
    switch(loop)
    {
        case 0: debug_line("Startup:"); break;
        case 1: startup_report(); break;
        case 2: debug_line("Watchdog:"); break;
        case 3: watchdog_report(); break;
        case 4: debug_line("boot ROM:"); break;
#ifdef BOOT_ROM_ENABLED
        case 5: boot_rom_report(); break;
#else
        case 5: debug_line(" not used"); break;
#endif
        case 6: debug_line("QSPI:"); break;
        case 7: flash_report(); break;
        case 8: debug_line("file system:"); break;
#ifdef FEAT_USB_MSC
        case 9: file_system_report(); break;
#else
        case 9: debug_line("target = fixed single"); break;
#endif
        case 10: debug_line("Done"); break;
        case 11: return true;  // we are done
    }
    return false;
}

