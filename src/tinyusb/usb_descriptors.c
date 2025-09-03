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
#include "tinyusb/src/class/msc/msc.h"
#include "tinyusb/src/class/net/net_device.h"

#if (defined FEAT_USB_MSC) | (defined FEAT_USB_NCM) | (defined FEAT_DEBUG_CDC) | (defined FEAT_GDB_SERVER) | (defined FEAT_TARGET_UART)
    // OK
#else
    #error "At least one USB interface needs to be enabled !"
#endif


// A combination of interfaces must have a unique product id, since PC will save device driver after the first plug.
// Same VID/PID with different interface e.g MSC (first), then CDC (later) will possibly cause system error on PC.
//
// Auto ProductID layout's Bitmap:
//   [MSB]       NET | VENDOR | MIDI | HID | MSC | CDC          [LSB]
//
// #define _PID_MAP(itf, n)  ( (CFG_TUD_##itf) << (n) )
// #define USB_PID           (0x4000 | _PID_MAP(CDC, 0) | _PID_MAP(MSC, 1) | _PID_MAP(HID, 2) | _PID_MAP(MIDI, 3) | _PID_MAP(VENDOR, 4) | _PID_MAP(ECM_RNDIS, 5) | _PID_MAP(NCM, 5) )
// -> dynamic_product_id
static uint16_t dynamic_product_id;
uint32_t num_cdc = 0;

/*******************************************************************************
 *        S T R I N G   D E S C R I P T O R
 ***************************************************************************** */

#define DESC_STR_MAX       20

enum
{
    USBD_STR_0 = 0,
    USBD_STR_MANUF,
    USBD_STR_PRODUCT,
    USBD_STR_SERIAL,
#ifdef FEAT_USB_MSC
    USBD_STR_MSC,           // MSC
#endif
#ifdef FEAT_USB_NCM
    USBD_STR_NCM_INTERFACE, // NCM
    USBD_STR_NCM_MAC,       // NCM
#endif
#ifdef FEAT_DEBUG_CDC
    USBD_STR_CDC_CLI,       // CDC
#endif
#ifdef FEAT_GDB_SERVER
    USBD_STR_CDC_GDB,       // CDC
#endif
#ifdef FEAT_TARGET_UART
    USBD_STR_CDC_TARGET,    // CDC
#endif
};

static const char *const usbd_desc_str[] = {
        // index 0 is not used
    [USBD_STR_MANUF]         = "Raspberry Pi",
    [USBD_STR_PRODUCT]       = "nomagic probe",
    [USBD_STR_SERIAL]        = "000000000001",
#ifdef FEAT_USB_MSC
    [USBD_STR_MSC]           = "nomagic msc",
#endif
#ifdef FEAT_USB_NCM
    [USBD_STR_NCM_INTERFACE] = "nomagic NCM Network interface",
#endif
#ifdef FEAT_DEBUG_CDC
    [USBD_STR_CDC_CLI]       = "nomagic cli",
#endif
#ifdef FEAT_GDB_SERVER
    [USBD_STR_CDC_GDB]       = "nomagic gdb",
#endif
#ifdef FEAT_TARGET_UART
    [USBD_STR_CDC_TARGET]    = "nomagic target",
#endif
};

#ifdef FEAT_USB_NCM
static char hex(uint32_t value);
#endif

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


/*******************************************************************************
 *        D E V I C E   D E S C R I P T O R
 ***************************************************************************** */


#define USBD_VID           0x2E8A // Raspberry Pi
#define USB_BCD            0x0200 // supported USB Version in BCD : 0x0200 = USB 2.00

//! device descriptor
static tusb_desc_device_t usbd_desc_device = {
    .bLength            = sizeof(tusb_desc_device_t),
    .bDescriptorType    = TUSB_DESC_DEVICE,
    .bcdUSB             = USB_BCD,  // supported USB Version in BCD : 0x0200 = USB 2.00
    .bDeviceClass       = TUSB_CLASS_MISC,
    .bDeviceSubClass    = MISC_SUBCLASS_COMMON,
    .bDeviceProtocol    = MISC_PROTOCOL_IAD,
    .bMaxPacketSize0    = CFG_TUD_ENDPOINT0_SIZE,
    .idVendor           = USBD_VID,
    // .idProduct          = 0,
    .bcdDevice          = 0x0100, // TODO = 0x0101, ???
    .iManufacturer      = USBD_STR_MANUF,
    .iProduct           = USBD_STR_PRODUCT,
    .iSerialNumber      = USBD_STR_SERIAL,
    .bNumConfigurations = 1,
};

//! Invoked when received GET DEVICE DESCRIPTOR request
//! Application return pointer to descriptor
uint8_t const * tud_descriptor_device_cb(void)
{
    usbd_desc_device.idProduct = dynamic_product_id;
    return (const uint8_t *) &usbd_desc_device;
}


/*******************************************************************************
 *        C O N F I G U R A T I O N   D E S C R I P T O R
 ***************************************************************************** */


#define USBD_MAX_POWER_MA  250

/*

 Configuration   | CDC | MSC | NCM | #define
 ----------------+-----+-----+-----+------------------
 HAS_MSC         |     |  +1 |     | FEAT_USB_MSC
 HAS_NCM         |     |     | +1  | FEAT_USB_NCM
 HAS_DEBUG_CDC   |  +1 |     |     | FEAT_DEBUG_CDC
 HAS_TARGET_UART | (+1)|     |     | FEAT_TARGET_UART
 HAS_GDB_SERVER  | (+1)|     |     | FEAT_GDB_SERVER
 descriptor-size |  66 |  23 |  85 |

configuration descriptor size = 9

 max = 9 + 3*66 + 23 + 85 = 315

*/

//! configuration descriptor
static uint8_t usbd_desc_cfg[315] = {0};

static void write_config_desc(uint8_t * descr_buffer, uint32_t descriptor_length, uint8_t interface_count);
#ifdef FEAT_USB_MSC
static void write_msc_desc(uint8_t * descr_buffer, uint8_t if_num, uint8_t ep_out, uint8_t ep_in);
#endif
#ifdef FEAT_USB_NCM
static void write_ncm_desc(uint8_t * descr_buffer, uint8_t if_num,  uint8_t ep_ctrl, uint8_t ep_out, uint8_t ep_in);
#endif
#if (defined FEAT_DEBUG_CDC) | (defined FEAT_GDB_SERVER) | (defined FEAT_TARGET_UART)
static void write_cdc_desc(uint8_t * descr_buffer, uint8_t if_num,  uint8_t ep_ctrl, uint8_t ep_out, uint8_t ep_in, uint8_t string_idx);
#endif


//! Invoked when received GET CONFIGURATION DESCRIPTOR request
//! Application return pointer to descriptor, whose contents must exist long enough for transfer to complete
uint8_t const * tud_descriptor_configuration_cb(uint8_t index)
{
    (void) index;
    return usbd_desc_cfg;
}


void update_descriptors(void)
{
    uint32_t descriptor_length = TUD_CONFIG_DESC_LEN;
    uint8_t interface_count = 0;
    uint32_t buf_offset = 0;
    uint8_t int_cnt = 0;
    uint8_t ep_out_cnt = 1;
    uint8_t ep_in_cnt = 0x81;
#ifdef FEAT_USB_MSC
    uint8_t interf_num_MSC;
    uint8_t ep_in_msc;
    uint8_t ep_out_msc;
#endif
#ifdef FEAT_USB_NCM
    uint8_t interf_num_NCM;
    uint8_t ep_ctrl_ncm;
    uint8_t ep_in_ncm;
    uint8_t ep_out_ncm;
#endif
#ifdef FEAT_DEBUG_CDC
    uint8_t interf_num_cli_CDC;
    uint8_t ep_ctrl_cli_CDC;
    uint8_t ep_in_cli_CDC;
    uint8_t ep_out_cli_CDC;
#endif
#ifdef FEAT_GDB_SERVER
    bool has_gdb_cdc = false;
    uint8_t interf_num_gdb_CDC;
    uint8_t ep_ctrl_gdb_CDC;
    uint8_t ep_in_gdb_CDC;
    uint8_t ep_out_gdb_CDC;
#endif
#ifdef FEAT_TARGET_UART
    bool has_target_cdc = false;
    uint8_t interf_num_target_CDC;
    uint8_t ep_ctrl_target_CDC;
    uint8_t ep_in_target_CDC;
    uint8_t ep_out_target_CDC;
#endif


    // configuration descriptor
    // 1.) collect data
#ifdef FEAT_USB_MSC
    interface_count++;
    descriptor_length += TUD_MSC_DESC_LEN;
    interf_num_MSC = int_cnt;
    int_cnt++;
    ep_in_msc = ep_in_cnt;
    ep_in_cnt++;
    ep_out_msc = ep_out_cnt;
    ep_out_cnt++;
#endif
#ifdef FEAT_USB_NCM
    interface_count++;
    descriptor_length += TUD_CDC_NCM_DESC_LEN;
    interf_num_NCM = int_cnt;
    int_cnt++;
    // NCM uses 2 interfaces.
    int_cnt++;
    ep_ctrl_ncm = ep_in_cnt;
    ep_in_cnt++;
    ep_in_ncm = ep_in_cnt;
    ep_in_cnt++;
    ep_out_ncm = ep_out_cnt;
    ep_out_cnt++;
#endif
#ifdef FEAT_DEBUG_CDC
    num_cdc++;
    interface_count++;
    descriptor_length += TUD_CDC_DESC_LEN;
    interf_num_cli_CDC = int_cnt;
    int_cnt++;
    // CDC uses 2 interfaces.
    int_cnt++;
    ep_ctrl_cli_CDC = ep_in_cnt;
    ep_in_cnt++;
    ep_in_cli_CDC = ep_in_cnt;
    ep_in_cnt++;
    ep_out_cli_CDC = ep_out_cnt;
    ep_out_cnt++;
#endif


#ifdef FEAT_GDB_SERVER
    // GDB Server interface
    if(true == serial_cfg_is_USB_CDC_enabled())
    {
        // GDB on CDC !
        num_cdc++;
        interface_count++;
        descriptor_length += TUD_CDC_DESC_LEN;
        interf_num_gdb_CDC = int_cnt;
        int_cnt++;
        // CDC uses 2 interfaces.
        int_cnt++;
        ep_ctrl_gdb_CDC = ep_in_cnt;
        ep_in_cnt++;
        ep_in_gdb_CDC = ep_in_cnt;
        ep_in_cnt++;
        ep_out_gdb_CDC = ep_out_cnt;
        ep_out_cnt++;
        has_gdb_cdc = true;
    }
#ifdef FEAT_USB_NCM
    else if((true == network_cfg_is_network_enabled()) && (0 != net_cfg.gdb_port))
    {
        // GDB on Ethernet !
    }
#endif
    else
    {
        // GDB not available !
    }
#endif

#ifdef FEAT_TARGET_UART
    if(true == serial_cfg_is_target_UART_enabled())
    {
#ifdef FEAT_USB_NCM
        if((true == network_cfg_is_network_enabled()) && (0 != net_cfg.target_uart_port))
        {
            // target UART on Ethernet !
        }
        else
#endif
        {
            // target UART on USB CDC !
            num_cdc++;
            interface_count++;
            descriptor_length += TUD_CDC_DESC_LEN;
            interf_num_target_CDC = int_cnt;
            int_cnt++;
            // CDC uses 2 interfaces.
            int_cnt++;
            ep_ctrl_target_CDC = ep_in_cnt;
            ep_in_cnt++;
            ep_in_target_CDC = ep_in_cnt;
            ep_in_cnt++;
            ep_out_target_CDC = ep_out_cnt;
            ep_out_cnt++;
            has_target_cdc = true;
        }
    }
#endif

    // 2.)write descriptor
    write_config_desc(usbd_desc_cfg, descriptor_length, interface_count);
    buf_offset = 9;
#ifdef FEAT_USB_MSC
    write_msc_desc(&(usbd_desc_cfg[buf_offset]), interf_num_MSC, ep_out_msc, ep_in_msc);
    buf_offset += TUD_MSC_DESC_LEN;
#endif
#ifdef FEAT_USB_NCM
    write_ncm_desc(&(usbd_desc_cfg[buf_offset]), interf_num_NCM, ep_ctrl_ncm, ep_out_ncm, ep_in_ncm);
    buf_offset += TUD_CDC_NCM_DESC_LEN;
#endif
#ifdef FEAT_DEBUG_CDC
    write_cdc_desc(&(usbd_desc_cfg[buf_offset]), interf_num_cli_CDC,  ep_ctrl_cli_CDC, ep_out_cli_CDC, ep_in_cli_CDC, USBD_STR_CDC_CLI);
    buf_offset += TUD_CDC_DESC_LEN;
#endif
#ifdef FEAT_GDB_SERVER
    if(true == has_gdb_cdc)
    {
        write_cdc_desc(&(usbd_desc_cfg[buf_offset]), interf_num_gdb_CDC,  ep_ctrl_gdb_CDC, ep_out_gdb_CDC, ep_in_gdb_CDC, USBD_STR_CDC_GDB);
        buf_offset += TUD_CDC_DESC_LEN;
    }
#endif
#ifdef FEAT_TARGET_UART
    if(true == has_target_cdc)
    {
        write_cdc_desc(&(usbd_desc_cfg[buf_offset]), interf_num_target_CDC,  ep_ctrl_target_CDC, ep_out_target_CDC, ep_in_target_CDC, USBD_STR_CDC_TARGET);
        buf_offset += TUD_CDC_DESC_LEN;
    }
#endif

// USB Product ID/ USB_PID/ idProduct for device descriptor
    dynamic_product_id = 0x4000
#ifdef FEAT_USB_MSC
            + 2
#endif
#ifdef FEAT_USB_NCM
            + 0x20
#endif
            ;
    if(0 < num_cdc)
    {
        dynamic_product_id += 1;
    }
}

static void write_config_desc(uint8_t * descr_buffer, uint32_t descriptor_length, uint8_t interface_count)
{
    descr_buffer[0] = 9;
    descr_buffer[1] = TUSB_DESC_CONFIGURATION;
    descr_buffer[2] = ( descriptor_length      & 0xff); // total length (low)
    descr_buffer[3] = ((descriptor_length >>8) & 0xff); // total length (High)
    descr_buffer[4] = interface_count; // interface count
    descr_buffer[5] = 1; // configuration number
    descr_buffer[6] = USBD_STR_0; // string index
    descr_buffer[7] = (1 << 7) | TUSB_DESC_CONFIG_ATT_REMOTE_WAKEUP;// attribute
    descr_buffer[8] = USBD_MAX_POWER_MA/2; // max power in 2mA
}

#ifdef FEAT_USB_MSC
static void write_msc_desc(uint8_t * descr_buffer, uint8_t if_num, uint8_t ep_out, uint8_t ep_in)
{
    // Interface
    descr_buffer[ 0] = 9;
    descr_buffer[ 1] = TUSB_DESC_INTERFACE;
    descr_buffer[ 2] = if_num; // interface number
    descr_buffer[ 3] = 0;
    descr_buffer[ 4] = 2;
    descr_buffer[ 5] = TUSB_CLASS_MSC;
    descr_buffer[ 6] = MSC_SUBCLASS_SCSI;
    descr_buffer[ 7] = MSC_PROTOCOL_BOT;
    descr_buffer[ 8] = USBD_STR_MSC;  // string index
    // Endpoint Out
    descr_buffer[ 9] = 7;
    descr_buffer[10] = TUSB_DESC_ENDPOINT;
    descr_buffer[11] = ep_out;
    descr_buffer[12] = TUSB_XFER_BULK;
    descr_buffer[13] = 64; // EP size low
    descr_buffer[14] = 0; // EP size high
    descr_buffer[15] = 0;
    // Endpoint In
    descr_buffer[16] = 7;
    descr_buffer[17] = TUSB_DESC_ENDPOINT;
    descr_buffer[18] = ep_in;
    descr_buffer[19] = TUSB_XFER_BULK;
    descr_buffer[20] = 64; // EP size low
    descr_buffer[21] = 0; // EP size high
    descr_buffer[22] = 0;
}
#endif

#ifdef FEAT_USB_NCM
static void write_ncm_desc(uint8_t * descr_buffer, uint8_t if_num,  uint8_t ep_ctrl, uint8_t ep_out, uint8_t ep_in)
{
    // Interface Association
    descr_buffer[ 0] = 8;
    descr_buffer[ 1] = TUSB_DESC_INTERFACE_ASSOCIATION;
    descr_buffer[ 2] = if_num; // interface number
    descr_buffer[ 3] = 2;
    descr_buffer[ 4] = TUSB_CLASS_CDC;
    descr_buffer[ 5] = CDC_COMM_SUBCLASS_NETWORK_CONTROL_MODEL;
    descr_buffer[ 6] = 0;
    descr_buffer[ 7] = 0;
    // Interface
    descr_buffer[ 8] = 9;
    descr_buffer[ 9] = TUSB_DESC_INTERFACE;
    descr_buffer[10] = if_num; // interface number
    descr_buffer[11] = 0;
    descr_buffer[12] = 1;
    descr_buffer[13] = TUSB_CLASS_CDC;
    descr_buffer[14] = CDC_COMM_SUBCLASS_NETWORK_CONTROL_MODEL;
    descr_buffer[15] = 0;
    descr_buffer[16] = USBD_STR_NCM_INTERFACE;  // string index
    // CDC-NCM Header
    descr_buffer[17] = 5;
    descr_buffer[18] = TUSB_DESC_CS_INTERFACE;
    descr_buffer[19] = CDC_FUNC_DESC_HEADER;
    descr_buffer[20] = 0x10;
    descr_buffer[21] = 0x01;
    // CDC-NCM Union
    descr_buffer[22] = 5;
    descr_buffer[23] = TUSB_DESC_CS_INTERFACE;
    descr_buffer[24] = CDC_FUNC_DESC_UNION;
    descr_buffer[25] = if_num;
    descr_buffer[26] = if_num + 1;
    // CDC-NCM Functional Descriptor
    descr_buffer[27] = 13;
    descr_buffer[28] = TUSB_DESC_CS_INTERFACE;
    descr_buffer[29] = CDC_FUNC_DESC_ETHERNET_NETWORKING;
    descr_buffer[30] = USBD_STR_NCM_MAC;
    descr_buffer[31] = 0;
    descr_buffer[32] = 0;
    descr_buffer[33] = 0;
    descr_buffer[34] = 0;
    descr_buffer[35] = ( CFG_TUD_NET_MTU     & 0xff);
    descr_buffer[36] = ((CFG_TUD_NET_MTU>>8) & 0xff);
    descr_buffer[37] = 0;
    descr_buffer[38] = 0;
    descr_buffer[39] = 0;
    // CDC-NCM Functional Descriptor
    descr_buffer[40] = 6;
    descr_buffer[41] = TUSB_DESC_CS_INTERFACE;
    descr_buffer[42] = CDC_FUNC_DESC_NCM;
    descr_buffer[43] = 0x00;
    descr_buffer[44] = 0x01;
    descr_buffer[45] = 0;
    // Endpoint Notification
    descr_buffer[46] = 7;
    descr_buffer[47] = TUSB_DESC_ENDPOINT;
    descr_buffer[48] = ep_ctrl;
    descr_buffer[49] = TUSB_XFER_INTERRUPT;
    descr_buffer[50] = 64; // EP size low
    descr_buffer[51] = 0; // EP size high
    descr_buffer[52] = 50;
    // CDC Data Interface (default inactive)
    descr_buffer[53] = 9;
    descr_buffer[54] = TUSB_DESC_INTERFACE;
    descr_buffer[55] = if_num + 1;
    descr_buffer[56] = 0;
    descr_buffer[57] = 0;
    descr_buffer[58] = TUSB_CLASS_CDC_DATA;
    descr_buffer[59] = 0;
    descr_buffer[60] = NCM_DATA_PROTOCOL_NETWORK_TRANSFER_BLOCK;
    descr_buffer[61] = 0;
    // CDC Data Interface (alternative active)
    descr_buffer[62] = 9;
    descr_buffer[63] = TUSB_DESC_INTERFACE;
    descr_buffer[64] = if_num + 1;
    descr_buffer[65] = 1;
    descr_buffer[66] = 2;
    descr_buffer[67] = TUSB_CLASS_CDC_DATA;
    descr_buffer[68] = 0;
    descr_buffer[69] = NCM_DATA_PROTOCOL_NETWORK_TRANSFER_BLOCK;
    descr_buffer[70] = 0;
    // Endpoint In
    descr_buffer[71] = 7;
    descr_buffer[72] = TUSB_DESC_ENDPOINT;
    descr_buffer[73] = ep_in;
    descr_buffer[74] = TUSB_XFER_BULK;
    descr_buffer[75] = 64; // EP size low
    descr_buffer[76] = 0; // EP size high
    descr_buffer[77] = 0;
    // Endpoint Out
    descr_buffer[78] = 7;
    descr_buffer[79] = TUSB_DESC_ENDPOINT;
    descr_buffer[80] = ep_out;
    descr_buffer[81] = TUSB_XFER_BULK;
    descr_buffer[82] = 64; // EP size low
    descr_buffer[83] = 0; // EP size high
    descr_buffer[84] = 0;
}
#endif

#if (defined FEAT_DEBUG_CDC) | (defined FEAT_GDB_SERVER) | (defined FEAT_TARGET_UART)
static void write_cdc_desc(uint8_t * descr_buffer, uint8_t if_num,  uint8_t ep_ctrl, uint8_t ep_out, uint8_t ep_in, uint8_t string_idx)
{
    // Interface Association
    descr_buffer[ 0] = 8;
    descr_buffer[ 1] = TUSB_DESC_INTERFACE_ASSOCIATION;
    descr_buffer[ 2] = if_num; // interface number
    descr_buffer[ 3] = 2;
    descr_buffer[ 4] = TUSB_CLASS_CDC;
    descr_buffer[ 5] = CDC_COMM_SUBCLASS_ABSTRACT_CONTROL_MODEL;
    descr_buffer[ 6] = CDC_COMM_PROTOCOL_NONE;
    descr_buffer[ 7] = 0;
    // CDC Control Interface
    descr_buffer[ 8] = 9;
    descr_buffer[ 9] = TUSB_DESC_INTERFACE;
    descr_buffer[10] = if_num; // interface number
    descr_buffer[11] = 0;
    descr_buffer[12] = 1;
    descr_buffer[13] = TUSB_CLASS_CDC;
    descr_buffer[14] = CDC_COMM_SUBCLASS_ABSTRACT_CONTROL_MODEL;
    descr_buffer[15] = CDC_COMM_PROTOCOL_NONE;
    descr_buffer[16] = string_idx;  // string index
    // CDC Header
    descr_buffer[17] = 5;
    descr_buffer[18] = TUSB_DESC_CS_INTERFACE;
    descr_buffer[19] = CDC_FUNC_DESC_HEADER;
    descr_buffer[20] = 0x20;
    descr_buffer[21] = 0x01;
    // CDC Call
    descr_buffer[22] = 5;
    descr_buffer[23] = TUSB_DESC_CS_INTERFACE;
    descr_buffer[24] = CDC_FUNC_DESC_CALL_MANAGEMENT;
    descr_buffer[25] = 0;
    descr_buffer[26] = if_num + 1;
    // CDC ACM: support line request + send break
    descr_buffer[27] = 4;
    descr_buffer[28] = TUSB_DESC_CS_INTERFACE;
    descr_buffer[29] = CDC_FUNC_DESC_ABSTRACT_CONTROL_MANAGEMENT;
    descr_buffer[30] = 6;
    // CDC Union
    descr_buffer[31] = 5;
    descr_buffer[32] = TUSB_DESC_CS_INTERFACE;
    descr_buffer[33] = CDC_FUNC_DESC_UNION;
    descr_buffer[34] = if_num;
    descr_buffer[35] = if_num + 1;
    // Endpoint Notification
    descr_buffer[36] = 7;
    descr_buffer[37] = TUSB_DESC_ENDPOINT;
    descr_buffer[38] = ep_ctrl;
    descr_buffer[39] = TUSB_XFER_INTERRUPT;
    descr_buffer[40] = 8; // EP size low
    descr_buffer[41] = 0; // EP size high
    descr_buffer[42] = 16;
    // CDC Data Interface
    descr_buffer[43] = 9;
    descr_buffer[44] = TUSB_DESC_INTERFACE;
    descr_buffer[45] = if_num + 1;
    descr_buffer[46] = 0;
    descr_buffer[47] = 2;
    descr_buffer[48] = TUSB_CLASS_CDC_DATA;
    descr_buffer[49] = 0;
    descr_buffer[50] = 0;
    descr_buffer[51] = 0;
    // Endpoint Out
    descr_buffer[52] = 7;
    descr_buffer[53] = TUSB_DESC_ENDPOINT;
    descr_buffer[54] = ep_out;
    descr_buffer[55] = TUSB_XFER_BULK;
    descr_buffer[56] = 64; // EP size low
    descr_buffer[57] = 0; // EP size high
    descr_buffer[58] = 0;
    // Endpoint In
    descr_buffer[59] = 7;
    descr_buffer[60] = TUSB_DESC_ENDPOINT;
    descr_buffer[61] = ep_in;
    descr_buffer[62] = TUSB_XFER_BULK;
    descr_buffer[63] = 64; // EP size low
    descr_buffer[64] = 0; // EP size high
    descr_buffer[65] = 0;
}
#endif
