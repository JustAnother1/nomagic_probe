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

#include "cli_usb.h"
#include "hal/debug_uart.h"
#include "tinyusb/src/device/usbd.h"

static void print_bool(bool val)
{
    if(true == val)
    {
        debug_line("true");
    }
    else
    {
        debug_line("false");
    }
}

bool cmd_usb_info(void)
{
    debug_line("\r\nUSB Status:");
    debug_msg("connected : ");
    print_bool(tud_connected());
    debug_msg("mounted   : ");
    print_bool(tud_mounted());
    debug_msg("suspended : ");
    print_bool(tud_suspended());

    return true; // true == Done; false = call me again
}
