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

#include "usb_cdc.h"
#include <stdint.h>
#include "tinyusb/src/class/cdc/cdc_device.h"

static void echo_serial_port(uint8_t buf[], uint32_t count);

void cdc_task(void)
{
    if(tud_cdc_n_available(0))
    {
        uint8_t buf[64];
        uint32_t count = tud_cdc_n_read(0, buf, sizeof(buf));
        // echo back to serial port
        echo_serial_port(buf, count);
    }
}

static void echo_serial_port(uint8_t buf[], uint32_t count)
{
    for(uint32_t i = 0; i < count; i++)
    {
        tud_cdc_n_write_char(0, buf[i]);
    }
    tud_cdc_n_write_flush(0);
}

