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
#include "swd_packets.h"
#include "swd_gpio.h"

// ARM document defines this!
static bool sticky_overrun = false;

static uint32_t send_packet_request(uint32_t APnotDP, uint32_t read_not_write, uint32_t address);
static uint32_t  read_ACK(void);
static void write_bit(uint32_t data);
static uint32_t  read_bit(void);
static void turn_to_output(void);
static void jtag_to_swd_sequence(void);
/* not used
static void jtag_to_dormant_state_sequence(void);
static void leave_dormant_state_to_swd_sequence(void);
static void swd_to_dormant_state_sequence(void);
*/

/*
Write to Target: (SWDIO must be valid before rising edge)
SWCLK:
High          /------\
             /       |\
LOW : ------/        | \---
        |   |        |     |
        1   2        3     4

1: set SWDIO - High for 1, low for 0 bit.
after 1/4 clock cycle
2:set SWCLK High
after 2/4 clock cycle
3 set SWCLK Low
after 1/4 clock cycle
bit is done
*/

/*
Read from Target: (SWDIO is valid at falling edge)
SWCLK:
High          /------\
             /       |\
LOW : ------/        | \---
        |   |        |     |
        1   2        3     4

1: SWDIO is switched to input
after 1/4 clock cycle
2:set SWCLK High
after 2/4 clock cycle
3 read SWDIO and set SWCLK Low
after 1/4 clock cycle
bit is done
*/

void swd_packets_init(void)
{
    sticky_overrun = false;
    swd_gpio_init();
}

void swd_packet_set_sticky_overrun(bool value)
{
    sticky_overrun = value;
}

void swd_packet_line_reset(void)
{
    uint32_t i;
    // at least 50 bits 1
    switch_SWDIO_to_Output();
    for(i = 0; i < 64; i++)
    {
        write_bit(1);
    }
    // the first one might not have worked if the device is talked to another debugger before we came along.
    // if this is a JTAG + SWD interface then we switch to SWD using this 16 bit sequence
    jtag_to_swd_sequence();

    // and another at least 50 bits 1
    for(i = 0; i < 64; i++)
    {
        write_bit(1);
    }
    // at least 2 idle cycles
    for(i = 0; i < 4; i++)
    {
        write_bit(0);
    }
}

void swd_packet_disconnect(void)
{
    // at least 8 Idle cycles
    uint32_t i;
    set_SWDIO_Low();
    switch_SWDIO_to_Output();
    for(i = 0; i < 16; i++)
    {
        write_bit(0);
    }
}

uint32_t swd_packet_write(uint32_t APnotDP, uint32_t address, uint32_t data)
{
    uint32_t i;
    uint32_t num_ones = 0;
    uint32_t ack;

    ack = send_packet_request(APnotDP, 0, address);

    // handle ACK
    if(ACK_OK != ack)
    {
        if((0 == APnotDP) && (ADDR_TARGETSEL == address))
        {
            // this is a TARGETSEL access and the device is not active.
            // -> line is not driven -> ignore ACK -> OK
            ack = ACK_OK;
        }
        else
        {
            // handle "Sticky overrun"
            if(false == sticky_overrun)
            {
                return ack;
            }
            // else we need the data phase
        }
    }

    turn_to_output();

    // Data
    for(i = 0; i < 32; i++)
    {
        // send 32 bits of data start with least significant bit first
        // get the bit
        if(0 == ((1<<i) & data))
        {
            write_bit(0);
        }
        else
        {
            write_bit(1);
            num_ones++;
        }
    }

    // Parity
    if(0 == num_ones%2)
    {
        write_bit(0);
    }
    else
    {
        write_bit(1);
    }
    return ack;
}

uint32_t swd_packet_read(uint32_t APnotDP, uint32_t address, uint32_t* data)
{
    uint32_t i;
    uint32_t num_ones = 0;
    uint32_t ack;
    uint32_t parity;
    uint32_t read_data = 0;

    ack = send_packet_request(APnotDP, 1, address);

    // handle ACK
    if(ACK_OK != ack)
    {
        // handle "Sticky overrun"
        if(true == sticky_overrun)
        {
            // we need to not drive the line for 33 clocks (32 data + parity)
            for(i = 0; i < 33; i++)
            {
                read_bit();
            }
        }
        return ack;
    }

    // Data
    for(i = 0; i < 32; i++)
    {
        // read 32 bits of data start with least significant bit first
        uint32_t bit = read_bit();
        if(1 == bit)
        {
            read_data = read_data | (1<<i);
            num_ones++;
        }
        // else 0 is already in read_data ;-)
    }

    *data = read_data;

    parity = read_bit();

    turn_to_output();

    if(ACK_OK == ack)
    {
        // Parity
        if((num_ones%2) != parity)
        {
            // parity error !
            ack = ERROR_PARITY;
        }
    }
    return ack;
}

void swd_packet_set_swdio_idle(void)
{
    set_SWDIO_High();
}

// static functions

static void write_bit(uint32_t data)
{
    if(0 == data)
    {
        set_SWDIO_Low();
    }
    else
    {
        set_SWDIO_High();
    }
    quarter_clock_delay();
    set_SWCLK_High();
    quarter_clock_delay();
    quarter_clock_delay();
    set_SWCLK_Low();
    quarter_clock_delay();
}

// returns 0 or 1 depending on SWDIO bit level on falling edge
static uint32_t read_bit(void)
{
    uint32_t res = 0;
    quarter_clock_delay();
    res = read_SWDIO();
    set_SWCLK_High();
    quarter_clock_delay();
    quarter_clock_delay();
    set_SWCLK_Low();
    quarter_clock_delay();
    return res;
}

static void turn_to_output(void)
{
    quarter_clock_delay();
    set_SWCLK_High();
    quarter_clock_delay();
    quarter_clock_delay();
    set_SWCLK_Low();
    quarter_clock_delay();
    switch_SWDIO_to_Output();
}

static uint32_t send_packet_request(uint32_t APnotDP, uint32_t read_not_write, uint32_t address)
{
    uint32_t parity = 0;

    switch_SWDIO_to_Output();

    // start Bit
    write_bit(1);

    // AP or DP
    if(0 == APnotDP)
    {
        // -> DP = 0
        write_bit(0);
    }
    else
    {
        // -> AP = 1
        write_bit(1);
        parity++;
    }

    // Read not Write
    if(0 == read_not_write)
    {
        // 0 -> write
        write_bit(0);
    }
    else
    {
        // 1 -> read
        write_bit(1);
        parity++;
    }

    // A2
    if(0 == (0x4 & address))
    {
        // -> 0
        write_bit(0);
    }
    else
    {
        // -> 1
        write_bit(1);
        parity++;
    }

    // A3
    if(0 == (0x8 & address))
    {
        // -> 0
        write_bit(0);
    }
    else
    {
        // -> 1
        write_bit(1);
        parity++;
    }

    // Parity ( over "AP or DP",  "Read not Write", A2 and A3
    write_bit(parity%2);

    // Stop
    write_bit(0);

    // Park
    set_SWDIO_High();
    quarter_clock_delay();
    set_SWCLK_High();
    quarter_clock_delay();
    switch_SWDIO_to_Input();
    quarter_clock_delay();
    set_SWCLK_Low();
    quarter_clock_delay();

    // Trn - turn around (turn to input - so that target can send)
    quarter_clock_delay();
    set_SWCLK_High();
    quarter_clock_delay();
    quarter_clock_delay();
    set_SWCLK_Low();
    quarter_clock_delay();

    return read_ACK();
}

static uint32_t read_ACK(void)
{
    uint32_t ack = 0;
    // ACK 0
    ack = read_bit();
    // ACK 1
    ack += (read_bit()<<1);
    // ACK 2
    ack += (read_bit()<<2);
    return ack;
}

static void jtag_to_swd_sequence(void)
{
    // if this is a JTAG + SWD interface then we switch to SWD using this 16 bit sequence
    write_bit(0);
    write_bit(1);
    write_bit(1);
    write_bit(1);

    write_bit(1);
    write_bit(0);
    write_bit(0);
    write_bit(1);

    write_bit(1);
    write_bit(1);
    write_bit(1);
    write_bit(0);

    write_bit(0);
    write_bit(1);
    write_bit(1);
    write_bit(1);
}
/* not used
static void swd_to_dormant_state_sequence(void)
{
    uint32_t i;
    // at least 50 bits 1
    switch_SWDIO_to_Output();
    for(i = 0; i < 64; i++)
    {
        write_bit(1);
    }

    // 16 bit sequence
    write_bit(0);
    write_bit(0);
    write_bit(1);
    write_bit(1);

    write_bit(1);
    write_bit(1);
    write_bit(0);
    write_bit(1);

    write_bit(1);
    write_bit(1);
    write_bit(0);
    write_bit(0);

    write_bit(0);
    write_bit(1);
    write_bit(1);
    write_bit(1);
}

static void leave_dormant_state_to_swd_sequence(void)
{
    uint32_t i;
    // at least 8x1
    for(i = 0; i < 9; i++)
    {
        write_bit(1);
    }

    // 128 bit selection alert
    // 1
    write_bit(0);
    write_bit(1);
    write_bit(0);
    write_bit(0);
    //2
    write_bit(1);
    write_bit(0);
    write_bit(0);
    write_bit(1);
    // 3
    write_bit(1);
    write_bit(1);
    write_bit(0);
    write_bit(0);
    // 4
    write_bit(1);
    write_bit(1);
    write_bit(1);
    write_bit(1);
    // 5
    write_bit(1);
    write_bit(0);
    write_bit(0);
    write_bit(1);
    // 6
    write_bit(0);
    write_bit(0);
    write_bit(0);
    write_bit(0);
    // 7
    write_bit(0);
    write_bit(1);
    write_bit(0);
    write_bit(0);
    // 8
    write_bit(0);
    write_bit(1);
    write_bit(1);
    write_bit(0);
    // 9
    write_bit(1);
    write_bit(0);
    write_bit(1);
    write_bit(0);
    // 10
    write_bit(1);
    write_bit(0);
    write_bit(0);
    write_bit(1);
    // 11
    write_bit(1);
    write_bit(0);
    write_bit(1);
    write_bit(1);
    // 12
    write_bit(0);
    write_bit(1);
    write_bit(0);
    write_bit(0);
    // 13
    write_bit(1);
    write_bit(0);
    write_bit(1);
    write_bit(0);
    // 14
    write_bit(0);
    write_bit(0);
    write_bit(0);
    write_bit(1);
    // 15
    write_bit(0);
    write_bit(1);
    write_bit(1);
    write_bit(0);
    // 16
    write_bit(0);
    write_bit(0);
    write_bit(0);
    write_bit(1);
    // 17
    write_bit(1);
    write_bit(0);
    write_bit(0);
    write_bit(1);
    // 18
    write_bit(0);
    write_bit(1);
    write_bit(1);
    write_bit(1);
    // 19
    write_bit(1);
    write_bit(1);
    write_bit(1);
    write_bit(1);
    // 20
    write_bit(0);
    write_bit(1);
    write_bit(0);
    write_bit(1);
    // 21
    write_bit(1);
    write_bit(0);
    write_bit(1);
    write_bit(1);
    // 22
    write_bit(1);
    write_bit(0);
    write_bit(1);
    write_bit(1);
    // 23
    write_bit(1);
    write_bit(1);
    write_bit(0);
    write_bit(0);
    // 24
    write_bit(0);
    write_bit(1);
    write_bit(1);
    write_bit(1);
    // 25
    write_bit(0);
    write_bit(1);
    write_bit(0);
    write_bit(0);
    // 26
    write_bit(0);
    write_bit(1);
    write_bit(0);
    write_bit(1);
    // 27
    write_bit(0);
    write_bit(1);
    write_bit(1);
    write_bit(1);
    // 28
    write_bit(0);
    write_bit(0);
    write_bit(0);
    write_bit(0);
    // 29
    write_bit(0);
    write_bit(0);
    write_bit(1);
    write_bit(1);
    // 30
    write_bit(1);
    write_bit(1);
    write_bit(0);
    write_bit(1);
    // 31
    write_bit(1);
    write_bit(0);
    write_bit(0);
    write_bit(1);
    // 32
    write_bit(1);
    write_bit(0);
    write_bit(0);
    write_bit(0);


    // 4x0
    write_bit(0);
    write_bit(0);
    write_bit(0);
    write_bit(0);

    // activation code (MSB first 0b0101 1000)
    write_bit(0);
    write_bit(0);
    write_bit(0);
    write_bit(1);

    write_bit(1);
    write_bit(0);
    write_bit(1);
    write_bit(0);

    // place target in known state
    // at least 50 bits 1
    switch_SWDIO_to_Output();
    for(i = 0; i < 64; i++)
    {
        write_bit(1);
    }
    // TODO target select might be needed now
}

static void jtag_to_dormant_state_sequence(void)
{
    // at least 5x1
    write_bit(1);
    write_bit(1);
    write_bit(1);
    write_bit(1);
    write_bit(1);
    write_bit(1);

    // 31 bit code
    write_bit(0);
    write_bit(1);
    write_bit(0);

    write_bit(1);
    write_bit(1);
    write_bit(1);
    write_bit(0);

    write_bit(1);
    write_bit(1);
    write_bit(1);
    write_bit(0);

    write_bit(1);
    write_bit(1);
    write_bit(1);
    write_bit(0);

    write_bit(1);
    write_bit(1);
    write_bit(1);
    write_bit(0);

    write_bit(1);
    write_bit(1);
    write_bit(1);
    write_bit(0);

    write_bit(1);
    write_bit(1);
    write_bit(1);
    write_bit(0);

    write_bit(0);
    write_bit(1);
    write_bit(1);
    write_bit(0);
}
*/
