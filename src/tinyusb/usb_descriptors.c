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
#ifdef FEAT_USB_NCM
#include "cfg/network_cfg.h"
#endif
#include "cfg/serial_cfg.h"

// TinyUSB:
#include "tinyusb/src/tusb.h"
#include "tinyusb/src/device/usbd.h"
#include "tinyusb/src/common/tusb_types.h"
#include "tinyusb/src/class/net/net_device.h"

#ifdef FEAT_USB_NCM
static char hex(uint32_t value);
#endif

#define DESC_STR_MAX       20
#define USBD_MAX_POWER_MA  250
#define USBD_DESC_LEN      (TUD_CONFIG_DESC_LEN + TUD_CDC_DESC_LEN * CFG_TUD_CDC + TUD_MSC_DESC_LEN * CFG_TUD_MSC)
#define USBD_DESC_MAX_LEN  (TUD_CONFIG_DESC_LEN + TUD_CDC_DESC_LEN * CFG_TUD_CDC + TUD_MSC_DESC_LEN * CFG_TUD_MSC + TUD_CDC_NCM_DESC_LEN * CFG_TUD_NCM)

#define USBD_VID           0x2E8A // Raspberry Pi
#define USB_BCD            0x0200 // supported USB Version in BCD : 0x0200 = USB 2.00

/* A combination of interfaces must have a unique product id, since PC will save device driver after the first plug.
 * Same VID/PID with different interface e.g MSC (first), then CDC (later) will possibly cause system error on PC.
 *
 * Auto ProductID layout's Bitmap:
 *   [MSB]       NET | VENDOR | MIDI | HID | MSC | CDC          [LSB]
 */
#define _PID_MAP(itf, n)  ( (CFG_TUD_##itf) << (n) )
#define USB_PID           (0x4000 | _PID_MAP(CDC, 0) | _PID_MAP(MSC, 1) | _PID_MAP(HID, 2) | \
                           _PID_MAP(MIDI, 3) | _PID_MAP(VENDOR, 4) | _PID_MAP(ECM_RNDIS, 5) | _PID_MAP(NCM, 5) )


// Interface numbers:
#define USBD_ITF_MSC       0
#define USBD_ITF_CDC_0     1
#define USBD_ITF_NCM       3
#define USBD_ITF_MAX       3

// End Points
// OUT:
#define EPNUM_CDC_OUT         0x02
#define EPNUM_MSC_OUT         0x03
#define EPNUM_NCM_OUT         0x04
// IN
#define EPNUM_CDC_CMD         0x81
#define EPNUM_CDC_IN          0x82
#define EPNUM_MSC_IN          0x83
#define EPNUM_NCM_NOTIFY      0x84
#define EPNUM_NCM_IN          0x85

// CDC:
#define USBD_CDC_CMD_MAX_SIZE     8
#define USBD_CDC_IN_OUT_MAX_SIZE  64

enum
{
    USBD_STR_0 = 0,
    USBD_STR_MANUF,
    USBD_STR_PRODUCT,
    USBD_STR_SERIAL,
#ifdef FEAT_USB_MSC
    USBD_STR_MSC,       // MSC
#endif
    USBD_STR_CDC,       // CDC
    USBD_STR_NCM_INTERFACE, // NCM
    USBD_STR_NCM_MAC,       // NCM
};


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
    .idProduct          = USB_PID,
    .bcdDevice          = 0x0100, // TODO = 0x0101, ???
    .iManufacturer      = USBD_STR_MANUF,
    .iProduct           = USBD_STR_PRODUCT,
    .iSerialNumber      = USBD_STR_SERIAL,
    .bNumConfigurations = 1,
};

//! configuration descriptor
static uint8_t usbd_desc_cfg[USBD_DESC_MAX_LEN] = {

    TUD_CONFIG_DESCRIPTOR(1,                                  // configuration number
                          USBD_ITF_MAX,                       // interface count
                          USBD_STR_0,                         // string index
                          USBD_DESC_LEN,                      // total length
                          TUSB_DESC_CONFIG_ATT_REMOTE_WAKEUP, // attribute
                          USBD_MAX_POWER_MA),                 // max power in mA

#ifdef FEAT_USB_MSC
    TUD_MSC_DESCRIPTOR(USBD_ITF_MSC,  // interface number
                       USBD_STR_MSC,  // string index
                       EPNUM_MSC_OUT, // bulk end point out number
                       EPNUM_MSC_IN,  // bulk end point in number
                       64),           // end point size (bytes)
#endif

    TUD_CDC_DESCRIPTOR(USBD_ITF_CDC_0,            // interface number
                       USBD_STR_CDC,              // string index
                       EPNUM_CDC_CMD,             // interrupt notification end point
                       USBD_CDC_CMD_MAX_SIZE,     // notification end point size
                       EPNUM_CDC_OUT,             // bulk end point out number
                       EPNUM_CDC_IN,              // bulk end point in number
                       USBD_CDC_IN_OUT_MAX_SIZE), // bulk end point size

#ifdef FEAT_USB_NCM
    TUD_CDC_NCM_DESCRIPTOR(USBD_ITF_NCM,              // Interface number
                           USBD_STR_NCM_INTERFACE,    // description string index
                           USBD_STR_NCM_MAC,          // MAC address string index
                           EPNUM_NCM_NOTIFY,          // EP notification address (in)
                           64,                        // EP notification size (bytes)
                           EPNUM_NCM_OUT,             // EP data address (out)
                           EPNUM_NCM_IN,              // EP data address (in)
                           CFG_TUD_NET_ENDPOINT_SIZE, // EP data size (bytes)
                           CFG_TUD_NET_MTU),          // max segment size (bytes)
#endif
};

static const char *const usbd_desc_str[] = {
        // index 0 is not used
    [USBD_STR_MANUF]     = "Raspberry Pi",
    [USBD_STR_PRODUCT]   = "nomagic probe",
    [USBD_STR_SERIAL]    = "000000000001",
    [USBD_STR_CDC]       = "nomagic cdc",
#ifdef FEAT_USB_MSC
    [USBD_STR_MSC]       = "nomagic msc",
#endif
#ifdef FEAT_USB_NCM
    [USBD_STR_NCM_INTERFACE] = "nomagic NCM Network interface",
    [USBD_STR_NCM_MAC]       = NULL,
#endif
};

//! Invoked when received GET STRING DESCRIPTOR request
//! Application return pointer to descriptor, whose contents must exist long enough for transfer to complete
uint16_t const* tud_descriptor_string_cb(uint8_t index, uint16_t langid)
{
    (void)langid;
    static uint16_t desc_str[DESC_STR_MAX];
    uint8_t len;

    if(index == 0)
    {
        desc_str[1] = 0x0409;
        len = 1;
    }
#ifdef FEAT_USB_NCM
    else if(USBD_STR_NCM_MAC == index)
    {
        for(uint32_t i = 0; i < sizeof(tud_network_mac_address); i++)
        {
            desc_str[2*i + 1] = hex(tud_network_mac_address[i] >> 4);
            desc_str[(2*i) + 2] = hex(tud_network_mac_address[i]);
        }
        len = 2 * sizeof(tud_network_mac_address);
    }
#endif
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

    // first byte is length (including header), second byte is string type
    desc_str[0] = (uint16_t)(0xffff & ((TUSB_DESC_STRING << 8) | (2 * len + 2)));
    return desc_str;
}

//! Invoked when received GET CONFIGURATION DESCRIPTOR request
//! Application return pointer to descriptor, whose contents must exist long enough for transfer to complete
uint8_t const * tud_descriptor_configuration_cb(uint8_t index)
{
    (void) index;
    return usbd_desc_cfg;
}

//! Invoked when received GET DEVICE DESCRIPTOR request
//! Application return pointer to descriptor
uint8_t const * tud_descriptor_device_cb(void)
{
    return (const uint8_t *) &usbd_desc_device;
}

void update_descriptors(void)
{
    // default: includes CDC does not include NCM
    uint32_t descriptor_length = USBD_DESC_LEN;
    uint8_t interface_count = USBD_ITF_MAX;
    bool has_cdc = true;
    uint8_t interface_number_ncm = USBD_ITF_NCM;

    if(true == serial_cfg_is_USB_CDC_enabled())
    {
        // no change
    }
    else
    {
        interface_count = interface_count -2;
        interface_number_ncm -= 2;
        descriptor_length -= TUD_CDC_DESC_LEN;
        has_cdc = false;
    }

#ifdef FEAT_USB_NCM
    if(true == network_cfg_is_network_enabled())
    {
        interface_count += 2;
        descriptor_length += TUD_CDC_NCM_DESC_LEN;
    }
    else
    {
        // no change
    }
#endif

    // apply changes:
    // ==============

    // TUD_CONFIG_DESCRIPTOR = 9 bytes (TUD_CONFIG_DESC_LEN)
    // adjust size + remove end points of Network
    // interface count = idx 4
    usbd_desc_cfg[4] = interface_count;
    // total length =  idx 2(low)+3(high)
    usbd_desc_cfg[2] = (descriptor_length & 0xff);
    usbd_desc_cfg[3]= ((descriptor_length>>8) & 0xff);
    // TUD_MSC_DESCRIPTOR = 23 bytes (TUD_MSC_DESC_LEN)
    // TUD_CDC_DESCRIPTOR = 66 bytes (TUD_CDC_DESC_LEN)

#ifdef FEAT_USB_NCM
    // TUD_CDC_NCM_DESCRIPTOR = 85 bytes (TUD_CDC_NCM_DESC_LEN)
    usbd_desc_cfg[98 + 2]  = interface_number_ncm;
    usbd_desc_cfg[98 + 10] = interface_number_ncm;
    usbd_desc_cfg[98 + 25] = interface_number_ncm;
    usbd_desc_cfg[98 + 26] = interface_number_ncm + 1;
    usbd_desc_cfg[98 + 55] = interface_number_ncm + 1;
    usbd_desc_cfg[98 + 64] = interface_number_ncm + 1;
#endif

    // remove unused descriptors
    if(false == has_cdc)
    {
#ifdef FEAT_USB_MSC
        // overwrite CDC descriptor with the following descriptors
        memcpy(&(usbd_desc_cfg[32]), // to the start of the CDC descriptor copy
               &(usbd_desc_cfg[32 + TUD_CDC_DESC_LEN]), // whatever comes after it
               descriptor_length -32); // and as many bytes come after the CDC
               //(length of CDC is already subtracted from descriptor_length)
#else
        // overwrite CDC descriptor with the following descriptors
        memcpy(&(usbd_desc_cfg[9]), // to the start of the CDC descriptor copy
               &(usbd_desc_cfg[9 + TUD_CDC_DESC_LEN]), // whatever comes after it
               descriptor_length -9); // and as many bytes come after the CDC
               //(length of CDC is already subtracted from descriptor_length)
#endif
    }
}

#ifdef FEAT_USB_NCM
static char hex(uint32_t value)
{
    switch(value&0xf)
    {
    case  0: return '0';
    case  1: return '1';
    case  2: return '2';
    case  3: return '3';
    case  4: return '4';
    case  5: return '5';
    case  6: return '6';
    case  7: return '7';
    case  8: return '8';
    case  9: return '9';
    case 10: return 'a';
    case 11: return 'b';
    case 12: return 'c';
    case 13: return 'd';
    case 14: return 'e';
    case 15: return 'f';
    }
    return 'U';  // impossible if math works out.
}
#endif

// cheat sheet for descriptor offset numbers:
// // Interface number, description string index, MAC address string index, EP notification address and size, EP data address (out, in), and size, max segment size.
// #define TUD_CDC_NCM_DESCRIPTOR(_itfnum, _desc_stridx, _mac_stridx, _ep_notif, _ep_notif_size, _epout, _epin, _epsize, _maxsegmentsize)
//   /* Interface Association (8)*/
//   8[0], TUSB_DESC_INTERFACE_ASSOCIATION[1], _itfnum[2], 2[3], TUSB_CLASS_CDC[4], CDC_COMM_SUBCLASS_NETWORK_CONTROL_MODEL[5], 0[6], 0[7],
//   /* CDC Control Interface (9)*/
//   9[8], TUSB_DESC_INTERFACE[9], _itfnum[10], 0[11], 1[12], TUSB_CLASS_CDC[13], CDC_COMM_SUBCLASS_NETWORK_CONTROL_MODEL[14], 0[15], _desc_stridx[16],
//   /* CDC-NCM Header (5)*/
//   5[17], TUSB_DESC_CS_INTERFACE[18], CDC_FUNC_DESC_HEADER[19], U16_TO_U8S_LE(0x0110)[20+21],
//   /* CDC-NCM Union (5)*/
//   5[22], TUSB_DESC_CS_INTERFACE[23], CDC_FUNC_DESC_UNION[24], _itfnum[25], (uint8_t)((_itfnum) + 1)[26],
//   /* CDC-NCM Functional Descriptor (13)*/
//   13[27], TUSB_DESC_CS_INTERFACE[28], CDC_FUNC_DESC_ETHERNET_NETWORKING[29], _mac_stridx[30], 0[31], 0[32], 0[33], 0[34], U16_TO_U8S_LE(_maxsegmentsize)[35 + 36], U16_TO_U8S_LE(0)[37 + 38], 0[39],
//   /* CDC-NCM Functional Descriptor (6)*/
//   6[40], TUSB_DESC_CS_INTERFACE[41], CDC_FUNC_DESC_NCM[42], U16_TO_U8S_LE(0x0100)[43 + 44], 0[45],
//   /* Endpoint Notification (7)*/
//   7[46], TUSB_DESC_ENDPOINT[47], _ep_notif[48], TUSB_XFER_INTERRUPT[49], U16_TO_U8S_LE(_ep_notif_size)[50 + 51], 50[52],
//   /* CDC Data Interface (default inactive) (9)*/
//   9[53], TUSB_DESC_INTERFACE[54], (uint8_t)((_itfnum)+1)[55], 0[56], 0[57], TUSB_CLASS_CDC_DATA[58], 0[59], NCM_DATA_PROTOCOL_NETWORK_TRANSFER_BLOCK[60], 0[61],
//   /* CDC Data Interface (alternative active) (9)*/
//   9[62], TUSB_DESC_INTERFACE[63], (uint8_t)((_itfnum)+1)[64], 1[65], 2[66], TUSB_CLASS_CDC_DATA[67], 0[68], NCM_DATA_PROTOCOL_NETWORK_TRANSFER_BLOCK[69], 0[70],
//   /* Endpoint In (7)*/
//   7[71], TUSB_DESC_ENDPOINT[72], _epin[73], TUSB_XFER_BULK[74], U16_TO_U8S_LE(_epsize)[75 + 76], 0[77],
//   /* Endpoint Out (7)*/
//   7[78], TUSB_DESC_ENDPOINT[79], _epout[80], TUSB_XFER_BULK[81], U16_TO_U8S_LE(_epsize)[82 + 83], 0[84]

