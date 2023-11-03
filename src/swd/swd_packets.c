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

static int send_packet_request(int APnotDP, int read_not_write, int address);
static int  read_ACK(void);
static void write_bit(int data);
static int  read_bit(void);
static void turn_to_output(void);

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

void set_sticky_overrun(bool value)
{
    sticky_overrun = value;
}

void packet_line_reset(void)
{
    int i;
    // at least 50 bits 1
    switch_SWDIO_to_Output();
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

void packet_disconnect(void)
{
    // at least 8 Idle cycles
    int i;
    set_SWDIO_Low();
    switch_SWDIO_to_Output();
    for(i = 0; i < 16; i++)
    {
        write_bit(0);
    }
}

int packet_write(int APnotDP, int address, uint32_t data)
{
    int i;
    int num_ones = 0;
    int ack;

    ack = send_packet_request(APnotDP, 0, address);

    // handle ACK
    if(ACK_OK != ack)
    {
        if((0 == APnotDP) && (0xc == address))
        {
            // this is a TARGETSEL access and the device is not active.
            // -> line is not driven -> ignore ACK -> OK
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
    // delay_us(100); // TODO debug only

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

    // delay_us(100); // TODO debug only
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

int packet_read(int APnotDP, int address, uint32_t* data)
{
    int i;
    int num_ones = 0;
    int ack;
    int parity;
    uint32_t read_data = 0;

    ack = send_packet_request(APnotDP, 1, address);

    // handle ACK
    /* ignore ACK for now
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
    */

    // delay_us(100); // TODO debug only

    // Data
    for(i = 0; i < 32; i++)
    {
        // read 32 bits of data start with least significant bit first
        int bit = read_bit();
        if(1 == bit)
        {
            read_data = read_data | (1<<i);
            num_ones++;
        }
        // else 0 is already in read_data ;-)
    }

    *data = read_data;


    // delay_us(100); // TODO debug only

    // parity = read_bit();
    quarter_clock_delay();
    parity = read_SWDIO();
    set_SWCLK_High();
    switch_SWDIO_to_Output();
    quarter_clock_delay();
    // quarter_clock_delay();
    // set_SWCLK_Low();
    // quarter_clock_delay();

    // delay_us(100); // TODO debug only

    if(ACK_OK == ack)
    {
        // Parity
        if((num_ones%2) != parity)
        {
            // parity error !
            ack = ERROR_PARITY;
        }
    }
    // switch_SWDIO_to_Output();
    return ack;
}

// static functions

static void write_bit(int data)
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
static int read_bit(void)
{
    int res = 0;
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

static int send_packet_request(int APnotDP, int read_not_write, int address)
{
    int parity = 0;

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
    //write_bit(1);

    set_SWDIO_High();
    quarter_clock_delay();
    set_SWCLK_High();
    quarter_clock_delay();
    switch_SWDIO_to_Input();
    quarter_clock_delay();
    set_SWCLK_Low();
    quarter_clock_delay();

    // Trn - turnaround (turn to input - so that target can send)

    // switch_SWDIO_to_Input();
    quarter_clock_delay();
    set_SWCLK_High();
    quarter_clock_delay();
    // switch_SWDIO_to_Input();
    quarter_clock_delay();
    set_SWCLK_Low();
    // switch_SWDIO_to_Input();
    quarter_clock_delay();

    return read_ACK();
}

static int read_ACK(void)
{
    int ack = 0;
    // ACK 0
    ack = read_bit();
    // ACK 1
    ack += (read_bit()<<1);
    // ACK 2
    ack += (read_bit()<<2);
    return ack;
}
