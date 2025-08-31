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

#include "cfg/serial_cfg.h"
#include "hal/hw/UART1.h"
#include "hal/target_uart.h"
#include "probe_api/debug_log.h"
#include "target/target_uart_handler.h"

static uint32_t from_pc;
static uint32_t to_pc;
static uint32_t baudrate;

void target_uart_handler_init(void)
{
    baudrate = serial_cfg_get_target_UART_baudrate();
    // limit the baudrate to the possible values. ( all values are in bit/s )
    if(120 > baudrate)
    {
        baudrate = 120;
    }
    if(7812500 < baudrate)
    {
        baudrate = 7812500;
    }
    target_uart_init(baudrate);
    from_pc = 0;
    to_pc = 0;
}

void target_uart_handler_tick(void)
{
    if(0 < target_uart_get_num_received_bytes())
    {
        // received something from target
        // -> forward to PC
        to_pc++;
        uint8_t data = target_uart_get_next_received_byte();
        target_uart_pc_send_bytes(&data, 1);
    }
    if(0 < target_uart_pc_get_num_received_bytes())
    {
        // received something from PC
        // -> forward to target
        from_pc++;
        uint8_t data = target_uart_pc_get_next_received_byte();
        target_uart_send_bytes(&data, 1);
    }
}

#ifdef FEAT_CLI
bool target_handler_cmd_info(const uint32_t loop)
{
    switch(loop)
    {
        case 0: cli_line("Target UART status:"); break;
        case 1: cli_line("received %ld Bytes from target", to_pc); break;
        case 2: cli_line("send %ld Bytes to the target", from_pc); break;
        case 3: cli_line("baudrate: %ld bit/s", baudrate); break;
        case 4: cli_line("baudrate register : %ld ", UART1->UARTIBRD); break;
        case 5: cli_line("fraction register : %ld ", UART1->UARTFBRD); break;
        default:
            return true;  // we are done
    }
    return false; // not yet done
}
#endif
