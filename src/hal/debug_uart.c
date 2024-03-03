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
#include "hal/debug_uart.h"
#include "hal/hw/RESETS.h"
#include "hal/hw/IO_BANK0.h"
#include "hal/hw/PADS_BANK0.h"
#include "hal/hw/UART0.h"
#include "hal/hw/SYSCFG.h"
#include "hal/hw/PSM.h"
#include "startup.h"

uint8_t recv_buf[RECEIVE_BUFFER_SIZE];
uint8_t send_buf[SEND_BUFFER_SIZE];
volatile uint32_t recv_read_pos;
volatile uint32_t recv_write_pos;
volatile uint32_t send_read_pos;
volatile uint32_t send_write_pos;
volatile bool is_sending;

static void send_a_byte(void);
static void receive_a_byte(void);

void debug_uart_initialize(void)
{
    recv_read_pos = 0;
    recv_write_pos = 0;
    send_read_pos = 0;
    send_write_pos = 0;

    RESETS->RESET = RESETS->RESET & ~((uint32_t)(1<< RESETS_RESET_IO_BANK0_OFFSET)); // take IO_BANK0 out of Reset
    PSM->FRCE_ON = PSM->FRCE_ON | (1<<PSM_FRCE_ON_SIO_OFFSET); // make sure that SIO is powered on
    // take UART0 out of Reset
    RESETS->RESET = RESETS->RESET & ~(1ul << RESETS_RESET_SYSCFG_OFFSET);
    while (0 == ((1 << RESETS_RESET_SYSCFG_OFFSET) & RESETS->RESET_DONE))
    {
        ;
    }

    RESETS->RESET = RESETS->RESET & ~(1ul << RESETS_RESET_UART0_OFFSET);
    // wait for UART0 to come out of Reset
    while (0 == ((1 << RESETS_RESET_UART0_OFFSET) & RESETS->RESET_DONE))
    {
         ;
    }
    // configure GPIO Pins
    IO_BANK0->GPIO16_CTRL = IO_BANK0_GPIO16_CTRL_FUNCSEL_uart0_tx; // TX
    IO_BANK0->GPIO17_CTRL = IO_BANK0_GPIO17_CTRL_FUNCSEL_uart0_rx; // RX

    // UART0 configuration
    // baud rate:
    UART0->UARTIBRD = 67; // integer
    UART0->UARTFBRD = 52; // fraction
    // FIFO enabled + 8,n,1
    UART0->UARTLCR_H = (1 << UART0_UARTLCR_H_FEN_OFFSET) // FIFO enabled
                     | (3 << UART0_UARTLCR_H_WLEN_OFFSET);  // Word length = 8 bit
    // FIFO Level trigger IRQ
    UART0->UARTIFLS = (0 << UART0_UARTIFLS_RXIFLSEL_OFFSET)  // trigger when RX FIFO is 1/8 full
                    | (4 << UART0_UARTIFLS_TXIFLSEL_OFFSET); // trigger when TX FIFO is 7/8 full
    UART0->UARTIMSC = 0x7fe; // enable all IRQs (but not Ring Indication)
    UART0->UARTLCR_H = (3 << UART0_UARTLCR_H_WLEN_OFFSET);  // Word length = 8 bit
    // UART mode + RX+TX enabled
    UART0->UARTCR = (1 << UART0_UARTCR_RXE_OFFSET)
            | (1 << UART0_UARTCR_TXE_OFFSET)
            | (1 << UART0_UARTCR_UARTEN_OFFSET);

    is_sending = false;
    NVIC_EnableIRQ(UART0_IRQ_NUMBER, UART0_IRQ_PRIORITY);
}

void debug_uart_tick(void)
{
    if(send_read_pos != send_write_pos)
    {
        if(false == is_sending)
        {
            is_sending = true;
            send_a_byte();
        }
    }
}

// send data:
uint32_t debug_uart_send_bytes(uint8_t* data, uint32_t length)
{
    uint32_t i;
    for (i = 0; i < length; i++)
    {
        uint32_t next_write = send_write_pos;
        next_write++;
        if (SEND_BUFFER_SIZE <= next_write)
        {
            next_write = 0;
        }
        while(next_write == send_read_pos)
        {
            // buffer is full
            // -> wait for space to become available
            debug_uart_tick();
        }
        send_buf[send_write_pos] = data[i];
        send_write_pos = next_write;
    }
    return i;
}

void debug_uart_send_String(char* str)
{
    while(*str != 0)
    {
        uint32_t next_write = send_write_pos;
        next_write++;
        if (SEND_BUFFER_SIZE <= next_write)
        {
            next_write = 0;
        }
        while(next_write == send_read_pos)
        {
            // buffer is full
            // -> wait for space to become available
            debug_uart_tick();
        }
        send_buf[send_write_pos] = *str;
        str++;
        send_write_pos = next_write;
    }
}

// get received data:
uint32_t debug_uart_get_num_received_bytes(void)
{
    if (recv_read_pos == recv_write_pos)
    {
        // buffer empty
        return 0;
    }
    if (recv_read_pos < recv_write_pos)
    {
        return recv_write_pos - recv_read_pos;
    }
    else
    {
        // wrap around
        return (RECEIVE_BUFFER_SIZE - recv_read_pos) + recv_write_pos;
    }
}

uint8_t debug_uart_get_next_received_byte(void)
{
    uint8_t res;
    if (recv_read_pos == recv_write_pos)
    {
        // buffer empty
        return 0;
    }
    res = recv_buf[recv_read_pos];
    recv_read_pos++;
    if (RECEIVE_BUFFER_SIZE == recv_read_pos)
    {
        recv_read_pos = 0;
    }
    return res;
}

bool debug_uart_get_received_bytes(uint8_t *buf, uint32_t length)
{
    uint32_t i;
    if (length < debug_uart_get_num_received_bytes())
    {
        return false;
    }
    for (i = 0; i < length; i++)
    {
        buf[i] = debug_uart_get_next_received_byte();
    }
    return true;
}

void debug_putc(void* p, char c)
{
    (void) p; // not used
    debug_uart_send_bytes((uint8_t *)&c, 1);
}

static void send_a_byte(void)
{
    if (send_read_pos != send_write_pos)
    {
        UART0->UARTDR = send_buf[send_read_pos];
        send_read_pos++;
        if (SEND_BUFFER_SIZE == send_read_pos)
        {
            send_read_pos = 0;
        }
    }
    else
    {
        // nothing to send anymore -> disable TX
        is_sending = false;
    }
}

static void receive_a_byte(void)
{
    uint32_t data = UART0->UARTDR;
    if (0 != (data & 0xf00))
    {
        // error
        // TODO report
    }
    else
    {
        uint32_t nextWrite;
        recv_buf[recv_write_pos] = (uint8_t)(data & 0xff);
        nextWrite = recv_write_pos + 1;
        if (RECEIVE_BUFFER_SIZE == nextWrite)
        {
            nextWrite = 0;
        }
        if (nextWrite == recv_read_pos)
        {
            // buffer full -> lost Byte
            // TODO report
        }
        else
        {
            recv_write_pos = nextWrite;
        }
    }
}

void UART0_IRQ(void)
{
    uint32_t irq = UART0->UARTMIS;
    if (0 != (irq & (1 << UART0_UARTRIS_OERIS_OFFSET))) // Overrun error
    {
        UART0->UARTICR = (1 << UART0_UARTRIS_OERIS_OFFSET); // clear Interrupt
    }
    if (0 != (irq & (1 << UART0_UARTRIS_BERIS_OFFSET))) // Break error
    {
        UART0->UARTICR = (1 << UART0_UARTRIS_BERIS_OFFSET); // clear Interrupt
    }
    if (0 != (irq & (1 << UART0_UARTRIS_PERIS_OFFSET))) // Parity error
    {
        UART0->UARTICR = (1 << UART0_UARTRIS_PERIS_OFFSET); // clear Interrupt
    }
    if (0 != (irq & (1 << UART0_UARTRIS_FERIS_OFFSET))) // Framing error
    {
        UART0->UARTICR = (1 << UART0_UARTRIS_FERIS_OFFSET); // clear Interrupt
    }
    if (0 != (irq & (1 << UART0_UARTRIS_RTRIS_OFFSET))) // Receive timeout
    {
        UART0->UARTICR = (1 << UART0_UARTRIS_RTRIS_OFFSET); // clear Interrupt
    }
    if (0 != (irq & (1 << UART0_UARTRIS_TXRIS_OFFSET))) {  // Transmit
        // we can send a byte
        is_sending = false;
    	UART0->UARTICR = (1 << UART0_UARTRIS_TXRIS_OFFSET); // clear Interrupt
    }
    if (0 != (irq & (1 << UART0_UARTRIS_RXRIS_OFFSET))) // Receive
    {
        // we received a byte
        receive_a_byte();
        UART0->UARTICR = (1 << UART0_UARTRIS_RXRIS_OFFSET); // clear Interrupt
    }
    if (0 != (irq & (1 << UART0_UARTRIS_DSRRMIS_OFFSET))) // DSR
    {
        UART0->UARTICR = (1 << UART0_UARTRIS_DSRRMIS_OFFSET); // clear Interrupt
    }
    if (0 != (irq & (1 << UART0_UARTRIS_DCDRMIS_OFFSET))) // DCD
    {
        UART0->UARTICR = (1 << UART0_UARTRIS_DCDRMIS_OFFSET); // clear Interrupt
    }
    if (0 != (irq & (1 << UART0_UARTRIS_CTSRMIS_OFFSET))) // CTS
    {
        UART0->UARTICR = (1 << UART0_UARTRIS_CTSRMIS_OFFSET); // clear Interrupt
    }
    if (0 != (irq & (1 << UART0_UARTRIS_RIRMIS_OFFSET))) // RI
    {
        UART0->UARTICR = (1 << UART0_UARTRIS_RIRMIS_OFFSET); // clear Interrupt
    }
}

