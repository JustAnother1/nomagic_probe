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

#include <stdbool.h>
#include "swd_packet_bits.h"
#include "probe_api/debug_log.h"
#include "probe_api/result.h"
#include "swd_gpio.h"

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


// ACK
#define ACK_PROTOCOL_ERROR_0   0 // on wire: line not driven -> read as low
#define ACK_OK                 1 // on wire: 1 0 0
#define ACK_WAIT               2 // on wire: 0 1 0
#define ACK_FAULT              4 // on wire: 0 0 1
#define ACK_PROTOCOL_ERROR_1   7 // on wire: line not driven -> read as high
#define ERROR_PARITY           8
// If the  ACK_PROTOCOL_ERROR_0 or ACK_PROTOCOL_ERROR_1 occur twice then a line reset  + read IDCODE is needed.


typedef Result (*packet_handler)(packet_definition_typ* pkg);

static uint32_t send_packet_request(uint32_t APnotDP, uint32_t read_not_write, uint32_t address);
static uint32_t  read_ACK(void);
static void write_bit(uint32_t data);
static uint32_t  read_bit(void);
static void turn_to_output(void);
static void jtag_to_swd_sequence(void);
static Result line_reset_handler(packet_definition_typ* pkg);
static Result disconnect_handler(packet_definition_typ* pkg);
static Result write_package_handler(packet_definition_typ* pkg);
static Result read_package_handler(packet_definition_typ* pkg);
static Result jtag_to_dormant_handler(packet_definition_typ* pkg);
static Result dormant_to_swd_handler(packet_definition_typ* pkg);
static Result swd_to_dormant_handler(packet_definition_typ* pkg);


static const packet_handler packet_handler_look_up[NUM_PAKETS] = {
        line_reset_handler,
        disconnect_handler,
        write_package_handler,
        read_package_handler,
        jtag_to_dormant_handler,
        dormant_to_swd_handler,
        swd_to_dormant_handler
};
volatile bool operational;
volatile uint32_t read_idx;
volatile uint32_t write_idx;
volatile uint32_t data_write_idx;
packet_definition_typ packet_queue[PACKET_QUEUE_SIZE];
uint32_t packet_result_data[PACKET_QUEUE_SIZE];
bool result_data_available[PACKET_QUEUE_SIZE];
bool result_data_error[PACKET_QUEUE_SIZE];


// ARM document defines this!
static bool sticky_overrun = false;


void swd_packet_bits_init(void)
{
    swd_packet_bits_reset_error_condition();
    swd_gpio_init();
}

void swd_packet_bits_reset_error_condition(void)
{
    operational = true;
    read_idx = 0;
    write_idx = 0;
    data_write_idx = 0;
    sticky_overrun = false;
}

bool swd_packet_bits_is_operational(void)
{
    return operational;
}

uint32_t swd_packet_bits_get_next_data_slot(void)
{
    uint32_t res = data_write_idx;
    result_data_available[res] = false;
    result_data_error[res] = false;
    data_write_idx++;
    return res;
}

Result swd_packet_bits_get_data_value(uint32_t idx, uint32_t* data)
{
    if(false == operational)
    {
        debug_line("swd_packet_bits_get_data_value(): not operational !");
        return ERR_WRONG_STATE;
    }
    if(idx < PACKET_QUEUE_SIZE)
    {
        if(false == result_data_error[idx])
        {
            if(true == result_data_available[idx])
            {
                *data = packet_result_data[idx];
                return RESULT_OK;
            }
            else
            {
                // data not yet available
                return ERR_NOT_COMPLETED;
            }
        }
        else
        {
            // operation failed - data lost
            return ERR_TARGET_ERROR;
        }
    }
    else
    {
        // invalid idx (out of bounds)
        return ERR_INVALID_TRANSACTION_ID;
    }
}

void swd_packet_bits_set_sticky_overrun(bool value)
{
    sticky_overrun = value;
}

void swd_packet_bits_set_swdio_idle(void)
{
    set_SWDIO_High();
}

void swd_packet_bits_tick(void)
{
    if(read_idx == write_idx)
    {
        // buffer is empty
    }
    else
    {
        if(true == operational)
        {
            // debug_line("swd: sending packet %s", packet_type_names[packet_queue[read_idx].type]);
            // send a packet from buffer
            Result res = (packet_handler_look_up[packet_queue[read_idx].type])(&(packet_queue[read_idx]));
            if(RESULT_OK == res)
            {
                // success ! packet will be send!
                read_idx++;
                if(PACKET_QUEUE_SIZE == read_idx)
                {
                    read_idx = 0;
                }
            }
            else if(ERR_QUEUE_FULL_TRY_AGAIN == res)
            {
                // try again next tick
            }
            else
            {
                // report this error !
                operational = false;
                // something went wrong!
                debug_line("ERROR: Failed to send packet! Result: %ld", res);
            }
        }
        // else not operational ! -> wait for ack to error
    }
}


static Result line_reset_handler(packet_definition_typ* pkg)
{
    (void)pkg;
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
    return RESULT_OK;
}

static Result disconnect_handler(packet_definition_typ* pkg)
{
    (void)pkg;
    // at least 8 Idle cycles
    uint32_t i;
    set_SWDIO_Low();
    switch_SWDIO_to_Output();
    for(i = 0; i < 16; i++)
    {
        write_bit(0);
    }
    return RESULT_OK;
}

static Result write_package_handler(packet_definition_typ* pkg)
{
    uint32_t i;
    uint32_t num_ones = 0;
    uint32_t ack;
    uint32_t APnotDP = pkg->APnotDP;
    uint32_t address = pkg->address;
    uint32_t data = pkg->data;

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
            operational = false;
            debug_line("ERROR: write ap/dp: %ld, addr: %ld, data: 0x%lx, ack: %ld", APnotDP, address, data, ack);
            // handle "Sticky overrun"
            if(false == sticky_overrun)
            {
                // TODO if this fails there is nothing I could do, also this should not fail ever, right?
                debug_line("ERROR: SWD ACK was %ld !", ack);
                return ERR_TARGET_ERROR;
            }
            else
            {
                // else we need the data phase
                // TODO Handle WAIT and Failure ACK
                debug_line("ERROR: SWD(SO) ACK was %ld !", ack);
                return ERR_TARGET_ERROR;
            }
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
    return RESULT_OK;
}

static Result read_package_handler(packet_definition_typ* pkg)
{
    uint32_t i;
    uint32_t num_ones = 0;
    uint32_t ack;
    uint32_t parity;
    uint32_t read_data = 0;
    uint32_t APnotDP = pkg->APnotDP;
    uint32_t address = pkg->address;

    ack = send_packet_request(APnotDP, 1, address);

    // handle ACK
    if(ACK_OK != ack)
    {
        operational = false;
        debug_line("ERROR: read ap/dp: %ld, addr: %ld, ack: %ld", APnotDP, address, ack);
        // handle "Sticky overrun"
        if(true == sticky_overrun)
        {
            // we need to not drive the line for 33 clocks (32 data + parity)
            for(i = 0; i < 33; i++)
            {
                read_bit();
            }
        }
        // TODO Handle WAIT and Failure ACK
        debug_line("ERROR: SWD ACK was %ld !", ack);
        result_data_error[pkg->result_idx] = true;
        // return RESULT_OK;
        return ERR_TARGET_ERROR;
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

    parity = read_bit();

    turn_to_output();

    if(ACK_OK == ack)
    {
        // Parity
        if((num_ones%2) != parity)
        {
            // parity error !
            ack = ERROR_PARITY;
            debug_line("SWD: parity error !");
            return ERR_TARGET_ERROR;
        }
    }

    packet_result_data[pkg->result_idx] = read_data;
    result_data_available[pkg->result_idx] = true;

    return RESULT_OK;
}

static Result jtag_to_dormant_handler(packet_definition_typ* pkg)
{
    (void)pkg;
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
    return RESULT_OK;
}

static Result dormant_to_swd_handler(packet_definition_typ* pkg)
{
    (void)pkg;
    uint32_t i;
    switch_SWDIO_to_Output();
    // at least 8x1
    for(i = 0; i < 9; i++)
    {
        write_bit(1);
    }

    // 128 bit selection alert
    // 1      4
    write_bit(0);
    write_bit(1);
    write_bit(0);
    write_bit(0);
    // 2      9
    write_bit(1);
    write_bit(0);
    write_bit(0);
    write_bit(1);
    // 3      c
    write_bit(1);
    write_bit(1);
    write_bit(0);
    write_bit(0);
    // 4      f
    write_bit(1);
    write_bit(1);
    write_bit(1);
    write_bit(1);
    // 5      9
    write_bit(1);
    write_bit(0);
    write_bit(0);
    write_bit(1);
    // 6      0
    write_bit(0);
    write_bit(0);
    write_bit(0);
    write_bit(0);
    // 7      4
    write_bit(0);
    write_bit(1);
    write_bit(0);
    write_bit(0);
    // 8      6
    write_bit(0);
    write_bit(1);
    write_bit(1);
    write_bit(0);
    // 9      a
    write_bit(1);
    write_bit(0);
    write_bit(1);
    write_bit(0);
    // 10     9
    write_bit(1);
    write_bit(0);
    write_bit(0);
    write_bit(1);
    // 11     b
    write_bit(1);
    write_bit(0);
    write_bit(1);
    write_bit(1);
    // 12     4
    write_bit(0);
    write_bit(1);
    write_bit(0);
    write_bit(0);
    // 13     a
    write_bit(1);
    write_bit(0);
    write_bit(1);
    write_bit(0);
    // 14     1
    write_bit(0);
    write_bit(0);
    write_bit(0);
    write_bit(1);
    // 15     6
    write_bit(0);
    write_bit(1);
    write_bit(1);
    write_bit(0);
    // 16     1
    write_bit(0);
    write_bit(0);
    write_bit(0);
    write_bit(1);
    // 17     9
    write_bit(1);
    write_bit(0);
    write_bit(0);
    write_bit(1);
    // 18     7
    write_bit(0);
    write_bit(1);
    write_bit(1);
    write_bit(1);
    // 19     f
    write_bit(1);
    write_bit(1);
    write_bit(1);
    write_bit(1);
    // 20     5
    write_bit(0);
    write_bit(1);
    write_bit(0);
    write_bit(1);
    // 21     b
    write_bit(1);
    write_bit(0);
    write_bit(1);
    write_bit(1);
    // 22     b
    write_bit(1);
    write_bit(0);
    write_bit(1);
    write_bit(1);
    // 23     c
    write_bit(1);
    write_bit(1);
    write_bit(0);
    write_bit(0);
    // 24     7
    write_bit(0);
    write_bit(1);
    write_bit(1);
    write_bit(1);
    // 25     4
    write_bit(0);
    write_bit(1);
    write_bit(0);
    write_bit(0);
    // 26     5
    write_bit(0);
    write_bit(1);
    write_bit(0);
    write_bit(1);
    // 27     7
    write_bit(0);
    write_bit(1);
    write_bit(1);
    write_bit(1);
    // 28     0
    write_bit(0);
    write_bit(0);
    write_bit(0);
    write_bit(0);
    // 29     3
    write_bit(0);
    write_bit(0);
    write_bit(1);
    write_bit(1);
    // 30     D
    write_bit(1);
    write_bit(1);
    write_bit(0);
    write_bit(1);
    // 31     9
    write_bit(1);
    write_bit(0);
    write_bit(0);
    write_bit(1);
    // 32     8
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
    write_bit(1);
    write_bit(0);
    write_bit(1);

    write_bit(1);
    write_bit(0);
    write_bit(0);
    write_bit(0);

    // place target in known state
    // at least 50 bits 1
    for(i = 0; i < 64; i++)
    {
        write_bit(1);
    }
    return RESULT_OK;
}

static Result swd_to_dormant_handler(packet_definition_typ* pkg)
{
    (void)pkg;
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
    return RESULT_OK;
}

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
    switch_SWDIO_to_Output();
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
