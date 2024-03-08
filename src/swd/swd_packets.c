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
#include "probe_api/debug_log.h"
#include "swd_packet_bits.h"

static uint32_t get_next_write_idx(void);


/*
static const char* packet_type_names[NUM_PAKETS] = {
      // 12345678901234567890
        "line reset",
        "disconnect",
        "write",
        "read",
        "jtag to dormant",
        "dormant to swd",
        "swd to dormant",
};
*/


void swd_packets_init(void)
{
    swd_packet_bits_init();
}

Result swd_packet_line_reset(void)
{
    if(true == swd_packet_bits_is_operational())
    {
        return ERR_WRONG_STATE;
    }
    // else:
    uint32_t next_write_idx = get_next_write_idx();
    if(read_idx != next_write_idx)
    {
        packet_queue[write_idx].type = LINE_RESET;
        write_idx = next_write_idx;
        return RESULT_OK;
    }
    else
    {
        return ERR_QUEUE_FULL_TRY_AGAIN;
    }
}

Result swd_packet_disconnect(void)
{
    if(true == swd_packet_bits_is_operational())
    {
        return ERR_WRONG_STATE;
    }
    // else:
    uint32_t next_write_idx = get_next_write_idx();
    if(read_idx != next_write_idx)
    {
        packet_queue[write_idx].type = DISCONNECT;
        write_idx = next_write_idx;
        return RESULT_OK;
    }
    else
    {
        return ERR_QUEUE_FULL_TRY_AGAIN;
    }

}

Result swd_packet_get_result(Result transaction, uint32_t* data)
{
    return swd_packet_bits_get_data_value((uint32_t) transaction, data);
}

Result swd_packet_write(uint32_t APnotDP, uint32_t address, uint32_t data)
{
    if(true == swd_packet_bits_is_operational())
    {
        return ERR_WRONG_STATE;
    }
    // else:
    uint32_t next_write_idx = get_next_write_idx();
    if(read_idx != next_write_idx)
    {
        packet_queue[write_idx].type = WRITE;
        packet_queue[write_idx].APnotDP = APnotDP;
        packet_queue[write_idx].address = address;
        packet_queue[write_idx].data = data;
        write_idx = next_write_idx;
        return RESULT_OK;
    }
    else
    {
        return ERR_QUEUE_FULL_TRY_AGAIN;
    }
}

Result swd_packet_read(uint32_t APnotDP, uint32_t address)
{
    if(true == swd_packet_bits_is_operational())
    {
        return ERR_WRONG_STATE;
    }
    // else:
    uint32_t next_write_idx = get_next_write_idx();
    if(read_idx != next_write_idx)
    {
        Result res;
        packet_queue[write_idx].type = READ;
        packet_queue[write_idx].APnotDP = APnotDP;
        packet_queue[write_idx].address = address;
        packet_queue[write_idx].result_idx = swd_packet_bits_get_next_data_slot();
        res = (Result)packet_queue[write_idx].result_idx;
        write_idx = next_write_idx;
        return res;
    }
    else
    {
        return ERR_QUEUE_FULL_TRY_AGAIN;
    }
}

Result jtag_to_dormant_state_sequence(void)
{
    if(true == swd_packet_bits_is_operational())
    {
        return ERR_WRONG_STATE;
    }
    // else:
    uint32_t next_write_idx = get_next_write_idx();
    if(read_idx != next_write_idx)
    {
        packet_queue[write_idx].type = JTAG_TO_DORMANT;
        write_idx = next_write_idx;
        return RESULT_OK;
    }
    else
    {
        return ERR_QUEUE_FULL_TRY_AGAIN;
    }
}

Result leave_dormant_state_to_swd_sequence(void)
{
    if(true == swd_packet_bits_is_operational())
    {
        return ERR_WRONG_STATE;
    }
    // else:
    uint32_t next_write_idx = get_next_write_idx();
    if(read_idx != next_write_idx)
    {
        packet_queue[write_idx].type = DORMANT_TO_SWD;
        write_idx = next_write_idx;
        return RESULT_OK;
    }
    else
    {
        return ERR_QUEUE_FULL_TRY_AGAIN;
    }
}

Result swd_to_dormant_state_sequence(void)
{
    if(true == swd_packet_bits_is_operational())
    {
        return ERR_WRONG_STATE;
    }
    // else:
    uint32_t next_write_idx = get_next_write_idx();
    if(read_idx != next_write_idx)
    {
        packet_queue[write_idx].type = SWD_TO_DORMANT;
        write_idx = next_write_idx;
        return RESULT_OK;
    }
    else
    {
        return ERR_QUEUE_FULL_TRY_AGAIN;
    }
}


// static functions

static uint32_t get_next_write_idx(void)
{
    uint32_t next_idx = write_idx + 1;
    if(PACKET_QUEUE_SIZE == next_idx)
    {
        next_idx = 0;
    }
    return next_idx;
}
