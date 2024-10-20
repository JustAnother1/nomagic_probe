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
#include "hal/debug_uart.h"
#ifdef FEAT_USB_NCM
#include "lwip/lwip.h"
#include "cfg/network_cfg.h"
#endif
#include "read_ini.h"
#include "probe_api/debug_log.h"

static bool is_USB_CDC_enabled;
static bool is_target_UART_enabled;

typedef void (* send_string_function)(char * str);
typedef void (* send_bytes_function)(const uint8_t * data, const uint32_t length);
typedef uint32_t (* get_num_received_bytes_function)(void);
typedef uint8_t (* get_next_received_byte_function)(void);
typedef void (* putc_function)(void* p, char c);
typedef bool (* is_connected_function)(void);
typedef void (* flush_function)(void);
typedef bool (* is_buffer_full_function)(void);

static void null_send_string_function(char * str);
static void null_send_bytes_function(const uint8_t * data, const uint32_t length);
static uint32_t null_get_num_received_bytes_function(void);
static uint8_t null_get_next_received_byte_function(void);
static void null_putc_function(void* p, char c);
static bool null_is_connected_function(void);
static void null_flush_function(void);
static bool null_is_buffer_full_function(void);

// GDB
static send_string_function send_string_fct;
static send_bytes_function send_bytes_fct;
static get_num_received_bytes_function get_num_received_bytes_fct;
static get_next_received_byte_function get_next_received_byte_fct;
static putc_function putc_fct;
static is_connected_function is_connected_fct;
static flush_function flush_fct;
static is_buffer_full_function is_buffer_full_fct;

// target UART
static send_string_function target_uart_send_string_fct;
static send_bytes_function target_uart_send_bytes_fct;
static get_num_received_bytes_function target_uart_get_num_received_bytes_fct;
static get_next_received_byte_function target_uart_get_next_received_byte_fct;
static putc_function target_uart_putc_fct;
static is_connected_function target_uart_is_connected_fct;
static flush_function target_uart_flush_fct;
static is_buffer_full_function target_uart_is_buffer_full_fct;

void serial_cfg_reset_to_default(void)
{
    is_USB_CDC_enabled = true;
    is_target_UART_enabled = false;
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

}


void serial_cfg_apply(void)
{
    // GDB Server interface
    if(true == is_USB_CDC_enabled)
    {
        debug_line("GDB on CDC !");
        send_string_fct            = usb_cdc_send_string;
        send_bytes_fct             = usb_cdc_send_bytes;
        get_num_received_bytes_fct = usb_cdc_get_num_received_bytes;
        get_next_received_byte_fct = usb_cdc_get_next_received_byte;
        putc_fct                   = usb_cdc_putc;
        is_connected_fct           = tud_cdc_connected;
        flush_fct                  = usb_cdc_flush;
        is_buffer_full_fct         = null_is_buffer_full_function;
    }
#ifdef FEAT_USB_NCM
    else if((true == network_cfg_is_network_enabled()) && (0 != net_cfg.gdb_port))
    {
        debug_line("GDB on Ethernet !");
        send_string_fct            = network_gdb_send_string;
        send_bytes_fct             = network_gdb_send_bytes;
        get_num_received_bytes_fct = network_gdb_get_num_received_bytes;
        get_next_received_byte_fct = network_gdb_get_next_received_byte;
        putc_fct                   = network_gdb_putc;
        is_connected_fct           = network_gdb_is_connected;
        flush_fct                  = network_gdb_flush;
        is_buffer_full_fct         = network_gdb_is_buffer_full;
    }
#endif
    else
    {
        debug_line("GDB not available !");
        // avoid null pointers in function pointers
        send_string_fct            = null_send_string_function;
        send_bytes_fct             = null_send_bytes_function;
        get_num_received_bytes_fct = null_get_num_received_bytes_function;
        get_next_received_byte_fct = null_get_next_received_byte_function;
        putc_fct                   = null_putc_function;
        is_connected_fct           = null_is_connected_function;
        flush_fct                  = null_flush_function;
        is_buffer_full_fct         = null_is_buffer_full_function;
    }

    // Debug interface is handled by compiler switches (ifdef)

    if(true == is_target_UART_enabled)
    {
#ifdef FEAT_USB_NCM
        if((true == network_cfg_is_network_enabled()) && (0 != net_cfg.target_uart_port))
        {
            debug_line("target UART on Ethernet !");
            // TODO
            target_uart_get_num_received_bytes_fct = network_target_uart_get_num_received_bytes;
            target_uart_get_next_received_byte_fct = network_target_uart_get_next_received_byte;
            target_uart_send_bytes_fct             = network_target_uart_send_bytes;
        }
        else
#endif
        {
            debug_line("target UART on USB CDC !");
            // TODO
            target_uart_send_string_fct            = null_send_string_function;
            target_uart_send_bytes_fct             = null_send_bytes_function;
            target_uart_get_num_received_bytes_fct = null_get_num_received_bytes_function;
            target_uart_get_next_received_byte_fct = null_get_next_received_byte_function;
            target_uart_putc_fct                   = null_putc_function;
            target_uart_is_connected_fct           = null_is_connected_function;
            target_uart_flush_fct                  = null_flush_function;
            target_uart_is_buffer_full_fct         = null_is_buffer_full_function;
        }
    }
}

bool serial_cfg_is_USB_CDC_enabled(void)
{
    return is_USB_CDC_enabled;
}

bool serial_cfg_is_target_UART_enabled(void)
{
    return is_target_UART_enabled;
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

static bool null_is_buffer_full_function(void)
{
    // buffer is never full
    return false;
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
#if defined(FEAT_DEBUG_UART)
    return debug_uart_get_num_received_bytes();
#elif defined(FEAT_DEBUG_CDC)
    return usb_cdc_get_num_received_bytes();
#else
    return 0;
#endif

}

uint8_t serial_debug_get_next_received_byte(void)
{
#if defined(FEAT_DEBUG_UART)
    return debug_uart_get_next_received_byte();
#elif defined(FEAT_DEBUG_CDC)
    return usb_cdc_get_next_received_byte();
#else
    return 0;
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

bool serial_gdb_is_buffer_full(void)
{
    return (* is_buffer_full_fct)();
}

// Target UART
// ===========
uint32_t target_uart_pc_get_num_received_bytes(void)
{
    return (* target_uart_get_num_received_bytes_fct)();
}

uint8_t target_uart_pc_get_next_received_byte(void)
{
    return (* target_uart_get_next_received_byte_fct)();
}

void target_uart_pc_send_bytes(const uint8_t * data, const uint32_t length)
{
    (* target_uart_send_bytes_fct)(data, length);
}


// new interfaces:
// void send_string_function(char * str);
// uint32_t send_bytes_function(const uint8_t * data, const uint32_t length);
// uint32_t get_num_received_bytes_function(void);
// uint8_t get_next_received_byte_function(void);
// void  putc_function(void* p, char c);
