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
#include "serial_cfg.h"
#include "tinyusb/usb_cdc.h"
#include "hal/debug_uart.h"
#include "lwip/lwip.h"
#include "cfg/network_cfg.h"

static bool is_USB_CDC_enabled;

typedef void (* send_string_function)(char * str);
typedef void (* send_bytes_function)(const uint8_t * data, const uint32_t length);
typedef uint32_t (* get_num_received_bytes_function)(void);
typedef uint8_t (* get_next_received_byte_function)(void);
typedef void (* putc_function)(void* p, char c);
typedef bool (* is_connected_function)(void);
typedef void (* flush_function)(void);

static void null_send_string_function(char * str);
static void null_send_bytes_function(const uint8_t * data, const uint32_t length);
static uint32_t null_get_num_received_bytes_function(void);
static uint8_t null_get_next_received_byte_function(void);
static void null_putc_function(void* p, char c);
static bool null_is_connected_function(void);
static void null_flush_function(void);


static send_string_function send_string_fct;
static send_bytes_function send_bytes_fct;
static get_num_received_bytes_function get_num_received_bytes_fct;
static get_next_received_byte_function get_next_received_byte_fct;
static putc_function putc_fct;
static is_connected_function is_connected_fct;
static flush_function flush_fct;

void serial_cfg_load(void)
{
    // TODO read from configuration file
    is_USB_CDC_enabled = false;

    // GDB Server interface
    if(true == is_USB_CDC_enabled)
    {
        send_string_fct = usb_cdc_send_string;
        send_bytes_fct = usb_cdc_send_bytes;
        get_num_received_bytes_fct = usb_cdc_get_num_received_bytes;
        get_next_received_byte_fct = usb_cdc_get_next_received_byte;
        putc_fct = usb_cdc_putc;
        is_connected_fct = tud_cdc_connected;
        flush_fct = usb_cdc_flush;
    }
    else if(0 != net_cfg.gdb_port)
    {
        send_string_fct = network_gdb_send_string;
        send_bytes_fct = network_gdb_send_bytes;
        get_num_received_bytes_fct = network_gdb_get_num_received_bytes;
        get_next_received_byte_fct =network_gdb_get_next_received_byte;
        putc_fct = network_gdb_putc;
        is_connected_fct = network_gdb_is_connected;
        flush_fct = network_gdb_flush;
    }
    else
    {
        // avoid null pointers in function pointers
        send_string_fct = null_send_string_function;
        send_bytes_fct = null_send_bytes_function;
        get_num_received_bytes_fct = null_get_num_received_bytes_function;
        get_next_received_byte_fct = null_get_next_received_byte_function;
        putc_fct = null_putc_function;
        is_connected_fct = null_is_connected_function;
        flush_fct = null_flush_function;
    }

    // Debug interface is handled by compiler switches (ifdef)
}

bool serial_cfg_is_USB_CDC_enabled(void)
{
    return is_USB_CDC_enabled;
}

// NULL interface
// ==============
static void null_send_string_function(char * str)
{
    (void) str;
    // Done !
}

static void null_send_bytes_function(const uint8_t * data, const uint32_t length)
{
    (void) data;
    (void) length;
}

static uint32_t null_get_num_received_bytes_function(void)
{
    return 0;
}

static uint8_t null_get_next_received_byte_function(void)
{
    return 0;
}

static void null_putc_function(void* p, char c)
{
    (void) p;
    (void) c;
    // Done !
}

static bool null_is_connected_function(void)
{
    return false;
}

static void null_flush_function(void)
{
    // Done !
}

// DEBUG CLI interface
// ===================
void serial_debug_send_string(char * str)
{
#ifdef FEAT_DEBUG_UART
        debug_uart_send_String(str);
#endif
#ifdef FEAT_DEBUG_CDC
        usb_cdc_send_string(str);
#endif
}
void serial_debug_send_bytes(const uint8_t * data, const uint32_t length)
{
#ifdef FEAT_DEBUG_UART
    debug_uart_send_bytes(data, length);
#endif
#ifdef FEAT_DEBUG_CDC
    usb_cdc_send_bytes(data, length);
#endif
}

uint32_t serial_debug_get_num_received_bytes(void)
{
#ifdef FEAT_DEBUG_UART
    return debug_uart_get_num_received_bytes();
#endif
#ifdef FEAT_DEBUG_CDC
    return usb_cdc_get_num_received_bytes();
#endif
}

uint8_t serial_debug_get_next_received_byte(void)
{
#ifdef FEAT_DEBUG_UART
    return debug_uart_get_next_received_byte();
#endif
#ifdef FEAT_DEBUG_CDC
    return usb_cdc_get_next_received_byte();
#endif
}

void serial_debug_putc(void* p, char c)
{
#ifdef FEAT_DEBUG_UART
    debug_putc(p, c);
#endif
#ifdef FEAT_DEBUG_CDC
    usb_cdc_putc(p, c);
#endif
}

// GDB Interface
// =============
void serial_gdb_send_string(char * str)
{
    (* send_string_fct)(str);
}

void serial_gdb_send_bytes(const uint8_t * data, const uint32_t length)
{
    (* send_bytes_fct)(data, length);
}

uint32_t serial_gdb_get_num_received_bytes(void)
{
    return (* get_num_received_bytes_fct)();
}

uint8_t serial_gdb_get_next_received_byte(void)
{
    return (* get_next_received_byte_fct)();
}

void serial_gdb_putc(void* p, char c)
{
    (* putc_fct)(p, c);
}

bool serial_gdb_is_connected(void)
{
    return (* is_connected_fct)();
}

void serial_gdb_flush(void)
{
    (* flush_fct)();
}

// new interfaces:
// void send_string_function(char * str);
// uint32_t send_bytes_function(const uint8_t * data, const uint32_t length);
// uint32_t get_num_received_bytes_function(void);
// uint8_t get_next_received_byte_function(void);
// void  putc_function(void* p, char c);
