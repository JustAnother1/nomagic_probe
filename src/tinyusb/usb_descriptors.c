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

#include "usb_descriptors.h"
// tinyusb:
#include "tinyusb/src/tusb.h"
#include "tinyusb/src/device/usbd.h"
#include "tinyusb/src/common/tusb_types.h"

#define DESC_STR_MAX       20
#define USBD_MAX_POWER_MA  250
#define USBD_DESC_LEN      (TUD_CONFIG_DESC_LEN + TUD_CDC_DESC_LEN * CFG_TUD_CDC + TUD_MSC_DESC_LEN * CFG_TUD_MSC)

#define USBD_VID           0x2E8A /* Raspberry Pi */
#define USB_BCD            0x0200
/* A combination of interfaces must have a unique product id, since PC will save device driver after the first plug.
 * Same VID/PID with different interface e.g MSC (first), then CDC (later) will possibly cause system error on PC.
 *
 * Auto ProductID layout's Bitmap:
 *   [MSB]         HID | MSC | CDC          [LSB]
 */
#define _PID_MAP(itf, n)  ( (CFG_TUD_##itf) << (n) )
#define USBD_PID           (0x4000 | _PID_MAP(CDC, 0) | _PID_MAP(MSC, 1) | _PID_MAP(HID, 2) | \
                           _PID_MAP(MIDI, 3) | _PID_MAP(VENDOR, 4) )

#define USBD_ITF_CDC_0     0
#define ITF_NUM_MSC        2
#define USBD_ITF_MAX       3

#define USBD_CDC_0_EP_CMD         0x81
#define USBD_CDC_0_EP_OUT         0x02
#define USBD_CDC_0_EP_IN          0x82
#define USBD_CDC_CMD_MAX_SIZE     8
#define USBD_CDC_IN_OUT_MAX_SIZE  64

#define EPNUM_MSC_OUT     0x03
#define EPNUM_MSC_IN      0x83


#define USBD_STR_0        0x00
#define USBD_STR_MANUF    0x01
#define USBD_STR_PRODUCT  0x02
#define USBD_STR_SERIAL   0x03
#define USBD_STR_CDC      0x04
#define USBD_STR_MSC      0x05


//! device descriptor
static const tusb_desc_device_t usbd_desc_device = {
    .bLength            = sizeof(tusb_desc_device_t),
    .bDescriptorType    = TUSB_DESC_DEVICE,
    .bcdUSB             = USB_BCD,  // supported USB Version in BCD : 0x0200 = USB 2.00
    .bDeviceClass       = TUSB_CLASS_MISC,
    .bDeviceSubClass    = MISC_SUBCLASS_COMMON,
    .bDeviceProtocol    = MISC_PROTOCOL_IAD,
    .bMaxPacketSize0    = CFG_TUD_ENDPOINT0_SIZE,
    .idVendor           = USBD_VID,
    .idProduct          = USBD_PID,
    .bcdDevice          = 0x0100,
    .iManufacturer      = USBD_STR_MANUF,
    .iProduct           = USBD_STR_PRODUCT,
    .iSerialNumber      = USBD_STR_SERIAL,
    .bNumConfigurations = 1,
};

//! configuration descriptor
static const uint8_t usbd_desc_cfg[USBD_DESC_LEN] = {

    TUD_CONFIG_DESCRIPTOR(1,                                  // configuration number
                          USBD_ITF_MAX,                       // interface count
                          USBD_STR_0,                         // string index
                          USBD_DESC_LEN,                      // total length
                          TUSB_DESC_CONFIG_ATT_REMOTE_WAKEUP, // attribute
                          USBD_MAX_POWER_MA),                 // max power in mA

    TUD_CDC_DESCRIPTOR(USBD_ITF_CDC_0,            // interface number
                       USBD_STR_CDC,              // string index
                       USBD_CDC_0_EP_CMD,         // interrupt notification end point
                       USBD_CDC_CMD_MAX_SIZE,     // notification end point size
                       USBD_CDC_0_EP_OUT,         // bulk end point out number
                       USBD_CDC_0_EP_IN,          // bulk end point in number
                       USBD_CDC_IN_OUT_MAX_SIZE), // bulk end point size

    TUD_MSC_DESCRIPTOR(ITF_NUM_MSC,   // interface number
                       USBD_STR_MSC,  // string index
                       EPNUM_MSC_OUT, // bulk end point out number
                       EPNUM_MSC_IN,  // bulk end point in number
                       64),           // end point size (bytes)
};

static const char *const usbd_desc_str[] = {
        // index 0 is not used
    [USBD_STR_MANUF]   = "Raspberry Pi",
    [USBD_STR_PRODUCT] = "nomagic probe",
    [USBD_STR_SERIAL]  = "000000000001",
    [USBD_STR_CDC]     = "nomagic cdc",
    [USBD_STR_MSC]     = "nomagic msc",
};

//! Invoked when received GET STRING DESCRIPTOR request
//! Application return pointer to descriptor, whose contents must exist long enough for transfer to complete
uint16_t const* tud_descriptor_string_cb(uint8_t index, uint16_t langid)
{
    (void)langid;
    static uint16_t desc_str[DESC_STR_MAX];
    uint8_t len;

    if (index == 0)
    {
        desc_str[1] = 0x0409;
        len = 1;
    }
    else
    {
        const char *str;

        if (index >= sizeof(usbd_desc_str) / sizeof(usbd_desc_str[0]))
        {
            return NULL;
        }

        str = usbd_desc_str[index];
        for (len = 0; len < DESC_STR_MAX - 1 && str[len]; ++len)
        {
            desc_str[1 + len] = str[len];
        }
    }

    desc_str[0] = (uint16_t)(0xffff & ((TUSB_DESC_STRING << 8) | (2 * len + 2)));

    return desc_str;
}

//! Invoked when received GET CONFIGURATION DESCRIPTOR request
//! Application return pointer to descriptor, whose contents must exist long enough for transfer to complete
uint8_t const * tud_descriptor_configuration_cb(uint8_t index)
{
    (void) index; // TODO multiple configurations ?
    return usbd_desc_cfg;
}

//! Invoked when received GET DEVICE DESCRIPTOR request
//! Application return pointer to descriptor
uint8_t const * tud_descriptor_device_cb(void)
{
    return (const uint8_t *) &usbd_desc_device;
}

