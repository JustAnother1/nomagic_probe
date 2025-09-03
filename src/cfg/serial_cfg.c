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

#include <stddef.h>
#include <string.h>
#include "serial_cfg.h"
#include "tinyusb/usb_cdc.h"
#include "tinyusb/usb_descriptors.h"
#include "hal/debug_uart.h"
#include "lwip/lwip.h"
#include "cfg/network_cfg.h"
#include "read_ini.h"
#include "probe_api/debug_log.h"

enum interface{
    CDC,
    ETHERNET,
    NONE,
};

// CLI
#ifdef FEAT_CLI
#ifdef FEAT_DEBUG_CDC
static uint8_t debug_cdc_itf = 0;
#endif
#endif
// GDB
static enum interface itf_gdb = 0;
static uint8_t gdb_cdc_itf = 0;
// target uart
#ifdef FEAT_TARGET_UART
static enum interface itf_target_uart = 0;
static uint8_t target_uart_cdc_itf = 0;
#endif

static bool is_USB_CDC_enabled;
static bool is_target_UART_enabled;
static uint32_t target_uart_baudrate;

#ifdef FEAT_CLI
#ifdef FEAT_DEBUG_CDC
    static uint8_t debug_cdc_itf;
#endif
#endif


void serial_cfg_reset_to_default(void)
{
    is_USB_CDC_enabled = true;
    is_target_UART_enabled = false;
    target_uart_baudrate = 115200; // default value
}

void serial_cfg_set(char * setting, char * value)
{
    if(0 == strncmp(setting, CDC_ENABLED_SETTING, sizeof(CDC_ENABLED_SETTING)))
    {
        is_USB_CDC_enabled = read_ini_bool(value);
    }

    if(0 == strncmp(setting, TARGET_UART_ENABLED_SETTING, sizeof(TARGET_UART_ENABLED_SETTING)))
    {
        is_target_UART_enabled = read_ini_bool(value);
    }

    if(0 == strncmp(setting, TARGET_UART_BAUDRATE_SETTING, sizeof(TARGET_UART_BAUDRATE_SETTING)))
    {
        target_uart_baudrate = read_int_address(value);
        if(0 == target_uart_baudrate)
        {
            target_uart_baudrate = 115200; // default value
        }
    }

}


void serial_cfg_apply(void)
{
#ifdef FEAT_GDB_SERVER
    // GDB Server interface
    if(true == is_USB_CDC_enabled)
    {
        debug_line("GDB on CDC !");
        itf_gdb =  CDC;
        gdb_cdc_itf = usb_descriptor_get_cdc_itf(GDB);
    }
#ifdef FEAT_USB_NCM
    else if((true == network_cfg_is_network_enabled()) && (0 != net_cfg.gdb_port))
    {
        debug_line("GDB on Ethernet !");
        itf_gdb = ETHERNET;
    }
#endif
    else
    {
        debug_line("GDB not available !");
        // avoid null pointers in function pointers
        itf_gdb = NONE;
    }
#endif

    // Debug interface is handled by compiler switches -> ifdef
#ifdef FEAT_CLI
#ifdef FEAT_DEBUG_CDC
    debug_cdc_itf = usb_descriptor_get_cdc_itf(DEBUG);
#endif
#endif

#ifdef FEAT_TARGET_UART
    if(true == is_target_UART_enabled)
    {
#ifdef FEAT_USB_NCM
        if((true == network_cfg_is_network_enabled()) && (0 != net_cfg.target_uart_port))
        {
            debug_line("target UART on Ethernet !");
            itf_target_uart = ETHERNET;
        }
        else
#endif
        {
            debug_line("target UART on USB CDC !");
            target_uart_cdc_itf = usb_descriptor_get_cdc_itf(TARGET_UART);
            itf_target_uart = CDC;
        }
    }
#endif
}

bool serial_cfg_is_USB_CDC_enabled(void)
{
    return is_USB_CDC_enabled;
}

bool serial_cfg_is_target_UART_enabled(void)
{
    return is_target_UART_enabled;
}

uint32_t serial_cfg_get_target_UART_baudrate(void)
{
    return target_uart_baudrate;
}


#ifdef FEAT_CLI
// DEBUG CLI interface
// ===================
void serial_debug_send_string(char * str)
{
#ifdef FEAT_DEBUG_UART
        debug_uart_send_string(str);
#elif FEAT_DEBUG_CDC
        usb_cdc_send_string(str, debug_cdc_itf);
#elif FEAT_DEBUG_TCP_IP
        network_cli_send_string(str);
#endif
}
void serial_debug_send_bytes(const uint8_t * data, const uint32_t length)
{
#ifdef FEAT_DEBUG_UART
    debug_uart_send_bytes(data, length);
#elif FEAT_DEBUG_CDC
    usb_cdc_send_bytes(data, length, debug_cdc_itf);
#elif FEAT_DEBUG_TCP_IP
    network_cli_send_bytes(data, length);
#endif
}

uint32_t serial_debug_get_num_received_bytes(void)
{
#if defined(FEAT_DEBUG_UART)
    return debug_uart_get_num_received_bytes();
#elif defined(FEAT_DEBUG_CDC)
    return usb_cdc_get_num_received_bytes(debug_cdc_itf);
#elif FEAT_DEBUG_TCP_IP
    return network_cli_get_num_received_bytes();
#else
    return 0;
#endif

}

uint8_t serial_debug_get_next_received_byte(void)
{
#if defined(FEAT_DEBUG_UART)
    return debug_uart_get_next_received_byte();
#elif defined(FEAT_DEBUG_CDC)
    return usb_cdc_get_next_received_byte(debug_cdc_itf);
#elif FEAT_DEBUG_TCP_IP
    return network_cli_get_next_received_byte();
#else
    return 0;
#endif
}

void serial_debug_putc(void* p, char c)
{
#ifdef FEAT_DEBUG_UART
    debug_uart_putc(p, c);
#elif FEAT_DEBUG_CDC
    usb_cdc_putc(p, c, debug_cdc_itf);
#elif FEAT_DEBUG_TCP_IP
    network_cli_putc(p, c);
#endif
}
#endif // FEAT_CLI

#ifdef FEAT_GDB_SERVER
// GDB Interface
// =============
void serial_gdb_send_string(char * str)
{
    switch(itf_gdb)
    {
    case CDC: usb_cdc_send_string(str, gdb_cdc_itf);return;
    case ETHERNET:
#ifdef FEAT_USB_NCM
        network_gdb_send_string(str); return;
#endif
    case NONE:
    default:
        // nothing to do
        break;
    }
}

void serial_gdb_send_bytes(const uint8_t * data, const uint32_t length)
{
    switch(itf_gdb)
    {
    case CDC: usb_cdc_send_bytes(data, length, gdb_cdc_itf);return;
    case ETHERNET:
#ifdef FEAT_USB_NCM
        network_gdb_send_bytes(data, length); return;
#endif
    case NONE:
    default:
        // nothing to do
        break;
    }
}

uint32_t serial_gdb_get_num_received_bytes(void)
{
    switch(itf_gdb)
    {
    case CDC: return usb_cdc_get_num_received_bytes(gdb_cdc_itf);
    case ETHERNET:
#ifdef FEAT_USB_NCM
        return network_gdb_get_num_received_bytes();
#endif
    case NONE:
    default:
        // nothing to do
        break;
    }
    return 0;
}

uint8_t serial_gdb_get_next_received_byte(void)
{
    switch(itf_gdb)
    {
    case CDC: return usb_cdc_get_next_received_byte(gdb_cdc_itf);
    case ETHERNET:
#ifdef FEAT_USB_NCM
        return network_gdb_get_next_received_byte();
#endif
    case NONE:
    default:
        // nothing to do
        break;
    }
    return 0;
}

void serial_gdb_putc(void* p, char c)
{
    switch(itf_gdb)
    {
    case CDC: usb_cdc_putc(p, c, gdb_cdc_itf);return;
    case ETHERNET:
#ifdef FEAT_USB_NCM
        network_gdb_putc(p, c); return;
#endif
    case NONE:
    default:
        // nothing to do
        break;
    }
}

bool serial_gdb_is_connected(void)
{
    switch(itf_gdb)
    {
    case CDC: return tud_cdc_n_connected(gdb_cdc_itf);
    case ETHERNET:
#ifdef FEAT_USB_NCM
        return network_gdb_is_connected();
#endif
    case NONE:
    default:
        // nothing to do
        break;
    }
    return false;
}

void serial_gdb_flush(void)
{
    switch(itf_gdb)
    {
    case CDC: usb_cdc_flush(gdb_cdc_itf);return;
    case ETHERNET:
#ifdef FEAT_USB_NCM
        network_gdb_flush(); return;
#endif
    case NONE:
    default:
        // nothing to do
        break;
    }
}

bool serial_gdb_is_buffer_full(void)
{
    switch(itf_gdb)
    {
    case ETHERNET:
#ifdef FEAT_USB_NCM
        return network_gdb_is_buffer_full();
#endif
    case CDC:
    case NONE:
    default:
        // nothing to do
        break;
    }
    return false;
}
#endif

#ifdef FEAT_TARGET_UART
// Target UART
// ===========
uint32_t target_uart_pc_get_num_received_bytes(void)
{
    switch(itf_target_uart)
    {
    case CDC: return usb_cdc_get_num_received_bytes(target_uart_cdc_itf);
    case ETHERNET:
#ifdef FEAT_USB_NCM
        return network_target_uart_get_num_received_bytes();
#endif
    case NONE:
    default:
        // nothing to do
        break;
    }
    return 0;
}

uint8_t target_uart_pc_get_next_received_byte(void)
{
    switch(itf_target_uart)
    {
    case CDC: return usb_cdc_get_next_received_byte(target_uart_cdc_itf);
    case ETHERNET:
#ifdef FEAT_USB_NCM
        return network_target_uart_get_next_received_byte();
#endif
    case NONE:
    default:
        // nothing to do
        break;
    }
    return 0;
}

void target_uart_pc_send_bytes(const uint8_t * data, const uint32_t length)
{
    switch(itf_target_uart)
    {
    case CDC: usb_cdc_send_bytes(data, length, target_uart_cdc_itf);return;
    case ETHERNET:
#ifdef FEAT_USB_NCM
        network_target_uart_send_bytes(data, length); return;
#endif
    case NONE:
    default:
        // nothing to do
        break;
    }
}
#endif
