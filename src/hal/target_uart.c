/*
  automatically created hal/target_uart.c
*/

#include <hal/hw/IO_BANK0.h>
#include <hal/hw/PSM.h>
#include <hal/hw/RESETS.h>
#include <hal/hw/UART1.h>
#include <hal/irq.h>
#include <hal/target_uart.h>
#include <stdbool.h>

static uint8_t UART1_recv_buf[100];
static uint8_t UART1_send_buf[500];
static volatile bool UART1_is_sending;
static volatile uint32_t UART1_recv_read_pos;
static volatile uint32_t UART1_recv_write_pos;
static volatile uint32_t UART1_send_read_pos;
static volatile uint32_t UART1_send_write_pos;



void UART1_IRQ(void)
{
    uint32_t irq = UART1->UARTMIS;
    if (0 != (irq & (1 << UART1_UARTRIS_OERIS_OFFSET))) // Overrun error
    {
        UART1->UARTICR = (1 << UART1_UARTRIS_OERIS_OFFSET); // clear Interrupt
    }
    if (0 != (irq & (1 << UART1_UARTRIS_BERIS_OFFSET))) // Break error
    {
        UART1->UARTICR = (1 << UART1_UARTRIS_BERIS_OFFSET); // clear Interrupt
    }
    if (0 != (irq & (1 << UART1_UARTRIS_PERIS_OFFSET))) // Parity error
    {
        UART1->UARTICR = (1 << UART1_UARTRIS_PERIS_OFFSET); // clear Interrupt
    }
    if (0 != (irq & (1 << UART1_UARTRIS_FERIS_OFFSET))) // Framing error
    {
        UART1->UARTICR = (1 << UART1_UARTRIS_FERIS_OFFSET); // clear Interrupt
    }
    if (0 != (irq & (1 << UART1_UARTRIS_RTRIS_OFFSET))) // Receive timeout
    {
        UART1->UARTICR = (1 << UART1_UARTRIS_RTRIS_OFFSET); // clear Interrupt
    }
    if (0 != (irq & (1 << UART1_UARTRIS_TXRIS_OFFSET))) {  // Transmit
        // we can send a byte
        UART1_is_sending = false;
        UART1->UARTICR = (1 << UART1_UARTRIS_TXRIS_OFFSET); // clear Interrupt
    }
    if (0 != (irq & (1 << UART1_UARTRIS_RXRIS_OFFSET))) // Receive
    {
        // we received a byte
        uint32_t data = UART1->UARTDR;
        if (0 != (data & 0xf00))
        {
            // error
        }
        else
        {
            uint32_t nextWrite;
            UART1_recv_buf[UART1_recv_write_pos] = (uint8_t)(data & 0xff);
            nextWrite = UART1_recv_write_pos + 1;
            if (100 == nextWrite)
            {
                nextWrite = 0;
            }
            if (nextWrite == UART1_recv_read_pos)
            {
                // buffer full -> lost Byte
            }
            else
            {
                UART1_recv_write_pos = nextWrite;
            }
        }
        UART1->UARTICR = (1 << UART1_UARTRIS_RXRIS_OFFSET); // clear Interrupt
    }
    if (0 != (irq & (1 << UART1_UARTRIS_DSRRMIS_OFFSET))) // DSR
    {
        UART1->UARTICR = (1 << UART1_UARTRIS_DSRRMIS_OFFSET); // clear Interrupt
    }
    if (0 != (irq & (1 << UART1_UARTRIS_DCDRMIS_OFFSET))) // DCD
    {
        UART1->UARTICR = (1 << UART1_UARTRIS_DCDRMIS_OFFSET); // clear Interrupt
    }
    if (0 != (irq & (1 << UART1_UARTRIS_CTSRMIS_OFFSET))) // CTS
    {
        UART1->UARTICR = (1 << UART1_UARTRIS_CTSRMIS_OFFSET); // clear Interrupt
    }
    if (0 != (irq & (1 << UART1_UARTRIS_RIRMIS_OFFSET))) // RI
    {
        UART1->UARTICR = (1 << UART1_UARTRIS_RIRMIS_OFFSET); // clear Interrupt
    }
}

            
void target_uart_init(uint32_t baud_rate)
{
    uint32_t reg_baud = 0;
    uint32_t reg_fract = 0;
    UART1_recv_read_pos = 0;
    UART1_recv_write_pos = 0;
    UART1_send_read_pos = 0;
    UART1_send_write_pos = 0;
    UART1_is_sending = false;

    RESETS->RESET = RESETS->RESET & ~((uint32_t)(1<< RESETS_RESET_IO_BANK0_OFFSET)); // take IO_BANK0 out of Reset
    PSM->FRCE_ON = PSM->FRCE_ON | (1<<PSM_FRCE_ON_SIO_OFFSET); // make sure that SIO is powered on
    // take UART1 out of Reset
    RESETS->RESET = RESETS->RESET & ~(1ul << RESETS_RESET_SYSCFG_OFFSET);
    while (0 == ((1 << RESETS_RESET_SYSCFG_OFFSET) & RESETS->RESET_DONE))
    {
        ;
    }

    RESETS->RESET = RESETS->RESET & ~(1ul << RESETS_RESET_UART1_OFFSET);

    // while waiting for the end of Reset calculate the baud rate settings
    // The baud rate divisor is = Peripheral Clock/(16*baud rate)
    // the fraction of that value multiplied by 64 is the value for the fraction register
    // example:
    // peripheral Clock = 125 MHz = 125000000
    // baud rate = 115200 bit/s
    // -> 125000000/(16* 115200) = 67,8168402777 -> baud rate register = 67
    // 0,8168402777 * 64 = 52,2777777 -> fraction register = 52
    reg_baud = (200000000u * 4) / baud_rate;
    reg_fract = reg_baud % 64;
    reg_baud = reg_baud/ 64;

    // wait for UART1 to come out of Reset
    while (0 == ((1 << RESETS_RESET_UART1_OFFSET) & RESETS->RESET_DONE))
    {
         ;
    }
    // configure GPIO Pins
    IO_BANK0->GPIO4_CTRL = IO_BANK0_GPIO4_CTRL_FUNCSEL_UART1_TX; // TX
    IO_BANK0->GPIO5_CTRL = IO_BANK0_GPIO5_CTRL_FUNCSEL_UART1_RX; // RX

    // UART1 configuration
    // baud rate:
    UART1->UARTIBRD = reg_baud; // integer
    UART1->UARTFBRD = reg_fract; // fraction// FIFO disabled + 8,n,1
    UART1->UARTLCR_H = (3 << UART1_UARTLCR_H_WLEN_OFFSET);  // Word length = 8 bit// FIFO Level trigger IRQ
    UART1->UARTIFLS = (0 << UART1_UARTIFLS_RXIFLSEL_OFFSET)  // trigger when RX FIFO is 1/8 full
                    | (4 << UART1_UARTIFLS_TXIFLSEL_OFFSET); // trigger when TX FIFO is 7/8 full
    UART1->UARTIMSC = 0x7fe; // enable all IRQs (but not Ring Indication)
    UART1->UARTLCR_H = (3 << UART1_UARTLCR_H_WLEN_OFFSET);  // Word length = 8 bit TODO
    // UART mode + RX+TX enabled
    UART1->UARTCR = (1 << UART1_UARTCR_RXE_OFFSET)
            | (1 << UART1_UARTCR_TXE_OFFSET)
            | (1 << UART1_UARTCR_UARTEN_OFFSET);

    NVIC_EnableIRQ(21, 3);
}

void target_uart_tick(void)
{
    if(UART1_send_read_pos != UART1_send_write_pos)
    {
        // we want to send something
        if(false == UART1_is_sending)
        {
            // peripheral is idle (we are not sending)
            if(UART1_send_read_pos != UART1_send_write_pos)
            {
                // send a byte
                UART1_is_sending = true;
                UART1->UARTDR = UART1_send_buf[UART1_send_read_pos];
                UART1_send_read_pos++;
                if(500 == UART1_send_read_pos)
                {
                    UART1_send_read_pos = 0;
                }
            }
            else
            {
                // nothing to send anymore -> disable TX
            }
        }
        // else we are already sending something
    }
    // else we do not want to send anything
}

void target_uart_flush(void)
{
    while(UART1_send_read_pos != UART1_send_write_pos)
    {
        UART1_IRQ(); // we might be in an interrupt that blocks the UART interrupt
        target_uart_tick();
    }
}

void target_uart_send_bytes(const uint8_t *data, const uint32_t length)
{
    uint32_t i;
    for(i = 0; i < length; i++)
    {
        uint32_t next_write = UART1_send_write_pos;
        next_write++;
        if(500 <= next_write)
        {
            next_write = 0;
        }
        while(next_write == UART1_send_read_pos)
        {
            // buffer is full
            // -> wait for space to become available
            UART1_IRQ();// we might be in an interrupt that blocks the UART interrupt
            target_uart_tick();
        }
        UART1_send_buf[UART1_send_write_pos] = data[i];
        UART1_send_write_pos = next_write;
    }
}

void target_uart_send_string(char* str)
{
    while(*str != 0)
    {
        uint32_t next_write = UART1_send_write_pos;
        next_write++;
        if(500 <= next_write)
        {
            next_write = 0;
        }
        while(next_write == UART1_send_read_pos)
        {
            // buffer is full
            // -> wait for space to become available
            UART1_IRQ();// we might be in an interrupt that blocks the UART interrupt
            target_uart_tick();
        }
        UART1_send_buf[UART1_send_write_pos] = *str;
        str++;
        UART1_send_write_pos = next_write;
    }
}

void target_uart_putc(void* p, char c)
{
    (void) p; // not used
    target_uart_send_bytes((uint8_t *)&c, 1);
}

uint32_t target_uart_get_num_received_bytes(void)
{
    if(UART1_recv_read_pos == UART1_recv_write_pos)
    {
        // buffer empty
        return 0;
    }
    if(UART1_recv_read_pos < UART1_recv_write_pos)
    {
        return UART1_recv_write_pos - UART1_recv_read_pos;
    }
    else
    {
        // wrap around
        return (100 - UART1_recv_read_pos) + UART1_recv_write_pos;
    }
}

uint8_t target_uart_get_next_received_byte(void)
{
    uint8_t res;
    if(UART1_recv_read_pos == UART1_recv_write_pos)
    {
        // buffer empty
        return 0;
    }
    res = UART1_recv_buf[UART1_recv_read_pos];
    UART1_recv_read_pos++;
    if(100 == UART1_recv_read_pos)
    {
        UART1_recv_read_pos = 0;
    }
    return res;
}

bool target_uart_get_received_bytes(uint8_t *buf, const uint32_t length)
{
    uint32_t i;
    if (length < target_uart_get_num_received_bytes())
    {
        return false;
    }
    for (i = 0; i < length; i++)
    {
        buf[i] = target_uart_get_next_received_byte();
    }
    return true;
}

