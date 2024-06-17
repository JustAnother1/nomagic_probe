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
/*
 * The MIT License (MIT)
 *
 * Copyright (c) 2019 Ha Thach (tinyusb.org)
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 *
 */
#include "usb_cdc.h"
#include <stdint.h>
#include "tinyusb/src/class/cdc/cdc_device.h"
#include "hal/debug_uart.h"
#include "tinyusb/usb.h"

static uint8_t nextChar = 0;

void usb_cdc_putc(void* p, char c)
{
    uint32_t res;
    (void) p; // not used
    if(true == tud_cdc_n_connected(INTERFACE))
    {
        for(;;)
        {
            res = tud_cdc_n_write_char(INTERFACE, c);
            if(1 == res)
            {
                tud_cdc_n_write_flush(INTERFACE);
                return;
            }
            else
            {
                usb_tick();  // let the USB stack work
            }
        }
    }
    // else ignore this character - nobody is listening anyway,..
}

void usb_cdc_send_string(char* str)
{
    // tud_cdc_n_write_str(INTERFACE, str);
    uint32_t res = 0;
    while(0 != *str)
    {
        res = tud_cdc_n_write_char(INTERFACE, *str);
        if(0 == res)
        {
            usb_tick();  // let the USB stack work
        }
        else
        {
            str++;
        }
    }
    tud_cdc_n_write_flush(INTERFACE);
}

void usb_cdc_send_bytes(const uint8_t *data, const uint32_t length)
{
    // the buffer is 64 bytes long, so most of the time a single call will be enough, therefore we have this first case separate and not part of the loop.
    uint32_t bytesSend = tud_cdc_n_write(INTERFACE, data, length);
    while(length > bytesSend)
    {
        tud_cdc_n_write_flush(INTERFACE);
        usb_tick();  // let the USB stack work
        bytesSend = bytesSend + tud_cdc_n_write(INTERFACE, &data[bytesSend], length - bytesSend);
    }
    // we have to flush every time, otherwise especially short replies get stuck in the queue for far too long.
    tud_cdc_n_write_flush(INTERFACE); // TODO remove?
}

void usb_cdc_flush(void)
{
    tud_cdc_n_write_flush(INTERFACE);
}

uint32_t usb_cdc_get_num_received_bytes(void)
{
    return tud_cdc_n_available(INTERFACE);
}

uint8_t  usb_cdc_get_next_received_byte(void)
{
    nextChar = 0;
    tud_cdc_n_read(INTERFACE, &nextChar, 1);
    return nextChar;
}

