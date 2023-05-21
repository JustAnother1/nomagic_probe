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
#include <hal/debug_uart.h>
#include "hal/hw/RESETS.h"
#include <hal/hw/IO_BANK0.h>
#include <hal/hw/PADS_BANK0.h>
#include "hal/hw/UART0.h"
#include "hal/hw/SYSCFG.h"
#include <hal/hw/PSM.h>
#include "startup.h"

#define RECEIVE_BUFFER_SIZE      100
#define SEND_BUFFER_SIZE         500

uint8_t recv_buf[RECEIVE_BUFFER_SIZE];
uint8_t send_buf[SEND_BUFFER_SIZE];
volatile uint32_t recv_read_pos;
volatile uint32_t recv_write_pos;
volatile uint32_t send_read_pos;
volatile uint32_t send_write_pos;
volatile bool is_sending;

static void send_a_byte(void);
static void receive_a_byte(void);
static void debug_putc(void* p, char c);

void debug_uart_initialize(void) {
    recv_read_pos = 0;
    recv_write_pos = 0;
    send_read_pos = 0;
    send_write_pos = 0;

    RESETS->RESET = RESETS->RESET & ~0x00000020lu; // take IO_BANK0 out of Reset
    PSM->FRCE_ON = PSM->FRCE_ON | 0x00000400; // make sure that SIO is powered on
    // take UART0 out of Reset
    RESETS->RESET = RESETS->RESET & ~(1ul << 18);  // sysCFG
    while (0 == ((1 << 18) & RESETS->RESET_DONE)) {
        ;
    }

    RESETS->RESET = RESETS->RESET & ~(1ul << 22);
    // wait for UART0 to come out of Reset
    while (0 == ((1 << 22) & RESETS->RESET_DONE)) {
         ;
    }
    // configure GPIO Pins
    // IO_BANK0->GPIO0_CTRL = 0x2;  TX
    // IO_BANK0->GPIO1_CTRL = 0x2; RX
    IO_BANK0->GPIO16_CTRL = 0x2; // TX
    IO_BANK0->GPIO17_CTRL = 0x2; // RX

    // UART0 configuration
    // baud rate:
    UART0->UARTIBRD = 67;
    UART0->UARTFBRD = 52;
    // FIFO enabled + 8,n,1
    UART0->UARTLCR_H = 0x60;
    UART0->UARTIFLS = 4;  // FIFO Level trigger IRQ
    UART0->UARTIMSC = 0x7fe; // enable all IRQs (but nor Ring Indication)
    UART0->UARTLCR_H = 0x60;
    UART0->UARTCR = 0x201; // UART mode + RX enabled

    is_sending = false;
    NVIC_EnableIRQ(UART0_IRQ_NUMBER, UART0_IRQ_PRIORITY);
    init_printf(NULL, debug_putc);
}

void debug_uart_tick(void)
{
    if(send_read_pos != send_write_pos)
    {
        is_sending = true;
        UART0->UARTCR = 0x301; // UART mode + RX+TX enabled
    }
}

// send data:
uint32_t debug_uart_send_bytes(uint8_t* data, uint32_t length) {
    uint32_t i;
    for (i = 0; i < length; i++) {
        uint32_t next_write = send_write_pos;
        next_write++;
        if (SEND_BUFFER_SIZE <= next_write) {
            next_write = 0;
        }
        if (next_write != send_read_pos) {
            send_buf[send_write_pos] = data[i];
            send_write_pos = next_write;
        } else {
            // buffer is full
            break;
        }
    }
    if(false == is_sending)
    {
    	send_a_byte();
    	is_sending = true;
    	UART0->UARTCR = 0x301; // UART mode + RX+TX enabled
    }
    return i;
}

void debug_uart_send_String(char* str)
{
    while(*str != 0) {
        uint32_t next_write = send_write_pos;
        next_write++;
        if (SEND_BUFFER_SIZE <= next_write) {
            next_write = 0;
        }
        if (next_write != send_read_pos) {
            send_buf[send_write_pos] = *str;
            str++;
            send_write_pos = next_write;
        } else {
            // buffer is full
            break;
        }
    }
    if(false == is_sending)
    {
    	send_a_byte();
    	is_sending = true;
    	UART0->UARTCR = 0x301; // UART mode + RX+TX enabled
    }
}

// get received data:
uint32_t debug_uart_get_num_received_bytes(void) {
    if (recv_read_pos == recv_write_pos) {
        // buffer empty
        return 0;
    }
    if (recv_read_pos < recv_write_pos) {
        return recv_write_pos - recv_read_pos;
    } else {
        // wrap around
        return (RECEIVE_BUFFER_SIZE - recv_read_pos) + recv_write_pos;
    }
}

uint8_t debug_uart_get_next_received_byte(void) {
    uint8_t res;
    if (recv_read_pos == recv_write_pos) {
        // buffer empty
        return 0;
    }
    res = recv_buf[recv_read_pos];
    recv_read_pos++;
    if (RECEIVE_BUFFER_SIZE == recv_read_pos) {
        recv_read_pos = 0;
    }
    return res;
}

bool debug_uart_get_received_bytes(uint8_t *buf, uint32_t length) {
    uint32_t i;
    if (length < debug_uart_get_num_received_bytes()) {
        return false;
    }
    for (i = 0; i < length; i++) {
        buf[i] = debug_uart_get_next_received_byte();
    }
    return true;
}

static void debug_putc(void* p, char c)
{
    (void) p; // not used
    debug_uart_send_bytes((uint8_t *)&c, 1);
}

static void send_a_byte(void)
{
    if (send_read_pos != send_write_pos) {
        UART0->UARTDR = send_buf[send_read_pos];
        send_read_pos++;
        if (SEND_BUFFER_SIZE == send_read_pos) {
            send_read_pos = 0;
        }
        if (send_read_pos == send_write_pos) {
        	if(0 == (UART0->UARTFR & 0x4)) {  // not busy
        		// nothing to send anymore -> disable TX
        		UART0->UARTCR = 0x201; // UART mode + RX enabled
        	}
        }
    } else {
        // nothing to send anymore -> disable TX
        UART0->UARTCR = 0x201; // UART mode + RX enabled
        is_sending = false;
    }
}

static void receive_a_byte(void)
{
    uint32_t data = UART0->UARTDR;
    if (0 != (data & 0xf00)) {
        // error
        // TODO report
    } else {
        uint32_t nextWrite;
        recv_buf[recv_write_pos] = (uint8_t)(data & 0xff);
        nextWrite = recv_write_pos + 1;
        if (RECEIVE_BUFFER_SIZE == nextWrite) {
            nextWrite = 0;
        }
        if (nextWrite == recv_read_pos) {
            // buffer full -> lost Byte
            // TODO report
        } else {
            recv_write_pos = nextWrite;
        }
    }
}

void UART0_IRQ(void) {
    uint32_t irq = UART0->UARTMIS;
    if (0 != (irq & 0x400)) {  // Overrun error
        UART0->UARTICR = 0x400; // clear Interrupt
    }
    if (0 != (irq & 0x200)) {  // Break error
        UART0->UARTICR = 0x200; // clear Interrupt
    }
    if (0 != (irq & 0x100)) {  // Parity error
        UART0->UARTICR = 0x100; // clear Interrupt
    }
    if (0 != (irq & 0x80)) {  // Framing error
        UART0->UARTICR = 0x80; // clear Interrupt
    }
    if (0 != (irq & 0x40)) {  // Receive timeout
        UART0->UARTICR = 0x40; // clear Interrupt
    }
    if (0 != (irq & 0x20)) {  // Transmit
        // we can send a byte
    	send_a_byte();
    	UART0->UARTICR = 0x20; // clear Interrupt
    }
    if (0 != (irq & 0x10)) {  // Receive
        // we received a byte
    	receive_a_byte();
    	UART0->UARTICR = 0x10; // clear Interrupt
    }
    if (0 != (irq & 0x8)) {  // DSR
        UART0->UARTICR = 0x8; // clear Interrupt
    }
    if (0 != (irq & 0x4)) {  // DCD
        UART0->UARTICR = 0x4; // clear Interrupt
    }
    if (0 != (irq & 0x2)) {  // CTS
        UART0->UARTICR = 0x2; // clear Interrupt
    }
    if (0 != (irq & 0x1)) {  // RI
        UART0->UARTICR = 0x1; // clear Interrupt
    }
}

