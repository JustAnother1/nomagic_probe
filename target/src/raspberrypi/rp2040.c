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
#include <string.h>
#include "target_info.h"
#include "arm/cortex-m.h"
#include "target_actions.h"
#include "target_info.h"
#include "result.h"
#include "debug_log.h"
#include "swd.h"
#include "gdb_packets.h"
#include "common.h"
#include "device_specific.h"
#include "arm/cortex-m.h"
#include "hex.h"

// RP2040:
// Core 0: 0x01002927
// Core 1: 0x11002927
// Rescue DP: 0xf1002927
// Core0 and Core1 instance IDs can be changed
// so to be sure check also these end points:
// 0x21002927, 0x31002927, 0x41002927, 0x51002927, 0x61002927, 0x71002927
// 0x81002927, 0x91002927, 0xa1002927, 0xb1002927, 0xc1002927, 0xd1002927,
// 0xe1002927

// decoded:
// IDCODE:
// bit 0     = 1;
// bit 1-11  = Designer (JEP106)
// bit 27-12 = PartNo
// bit 28-31 = Version (implementation defined)

// Part Number : 0x1002
// Designer = Raspberry Pi Trading Ltd.
// JEP 106 = 9x 0x7f then 0x13


#define SWD_ID_CORE_0    0x01002927
#define SWD_ID_CORE_1    0x11002927
#define SWD_ID_RESCUE_DP 0xf1002927

#define SWD_AP_SEL       0

#define MEMORY_MAP_CONTENT  \
"<memory-map>\r\n" \
    "<memory type=\"rom\" start=\"0x00000000\" length=\"0x00004000\"/>\r\n" \
    "<memory type=\"flash\" start=\"0x10000000\" length=\"0x4000000\">\r\n" \
        "<property name=\"blocksize\">0x1000</property>\r\n" \
    "</memory>\r\n" \
    "<memory type=\"ram\" start=\"0x20000000\" length=\"0x20042000\"/>\r\n" \
"</memory-map>\r\n"


Result handle_target_close_connection(action_data_typ* action, bool first_call)
{
    if(true == first_call)
    {
        debug_line("closing SWD connection !");
        action->walk->type = WALK_DISCONNECT;
        action->walk->phase = 0;
        action->walk->result = RESULT_OK;
        action->walk->is_done = false;
        action->phase = 1;
        return ERR_NOT_COMPLETED;
    }
    else // if(1 == step)
    {
        if(RESULT_OK == action->walk->result)
        {
            debug_line("Disconnected!");
        }
        else
        {
            debug_line("ERROR: failed to disconnect(%ld)!", action->walk->result);
        }
    }
    return action->walk->result;
}

Result handle_target_connect(action_data_typ* action, bool first_call)
{
    if(true == first_call)
    {
        debug_line("connecting SWDv2 (0x%08x)", SWD_ID_CORE_0);
        action->walk->type = WALK_CONNECT;
        action->walk->par_b_0 = true; // multi = SWDv2 -> true
        action->walk->par_i_0 = SWD_ID_CORE_0;  // TODO multi core
        action->walk->par_i_1 = SWD_AP_SEL;
        action->walk->phase = 0;
        action->walk->result = RESULT_OK;
        action->walk->is_done = false;
        action->phase = 1;
        return ERR_NOT_COMPLETED;
    }
    if(1 == action->phase)
    {
        if(RESULT_OK == action->walk->result)
        {
            debug_line("connected!");
        }
        else
        {
            debug_line("ERROR: failed to connect!");
        }
    }
    return action->walk->result;
}

Result handle_target_reply_g(action_data_typ* action, bool first_call)
{
    // ‘g’
    //    Read general registers.
    //    Reply:
    //    ‘XX…’
    //        Each byte of register data is described by two hex digits.
    // The bytes with the register are transmitted in target byte order.
    // The size of each register and their position within the ‘g’ packet
    // are determined by the target description (see Target Descriptions);
    // in the absence of a target description, this is done using code
    // internal to GDB; typically this is some customary register layout
    // for the architecture in question.
    //        When reading registers, the stub may also return a string of
    // literal ‘x’’s in place of the register data digits, to indicate that
    // the corresponding register’s value is unavailable. For example, when
    // reading registers from a trace frame (see Using the Collected Data),
    // this means that the register has not been collected in the trace frame.
    // When reading registers from a live program, this indicates that the stub
    // has no means to access the register contents, even though the
    // corresponding register is known to exist. Note that if a register truly
    // does not exist on the target, then it is better to not include it in the
    // target description in the first place.
    //        For example, for an architecture with 4 registers of 4 bytes each,
    // the following reply indicates to GDB that registers 0 and 2 are
    // unavailable, while registers 1 and 3 are available, and both have zero
    // value:
    //        -> g
    //        <- xxxxxxxx00000000xxxxxxxx00000000
    //    ‘E NN’
    //        for an error.

    if(true == first_call)
    {
        reply_packet_prepare();
        action->phase = 1;
        action->intern_0 = 0;
        return ERR_NOT_COMPLETED;
    }
    // else ...
    if(1 == action->phase)
    {
        action->walk->type = WALK_READ_SPECIAL_REGISTER;
        action->walk->par_i_0 = action->intern_0;  // select the register to read
        action->walk->phase = 0;
        action->walk->result = RESULT_OK;
        action->walk->is_done = false;
        action->phase = 2;
        return ERR_NOT_COMPLETED;
    }
    else //if(2 == action->phase)
    {
        if(RESULT_OK == action->walk->result)
        {
            char buf[9];
            buf[8] = 0;
            int_to_hex(buf, action->walk->read_0, 8);
            reply_packet_add(buf);
            debug_line("read 0x%08lx", action->walk->read_0);
            action->intern_0++;
            action->phase = 1;
            if(17 == action->intern_0)
            {
                // finished
                reply_packet_send();
                return RESULT_OK;
            }
            else
            {
                // continue with next register
                return ERR_NOT_COMPLETED;
            }
        }
        else
        {
            debug_line("ERROR: failed to read special register (%ld)!", action->walk->result);
            return action->walk->result;
        }
    }
}

Result handle_target_reply_write_g(action_data_typ* action, bool first_call)
{
    // ‘G XX…’
    //     Write general registers. See read registers packet, for a description
    // of the XX… data.
    //     Reply:
    //     ‘OK’
    //         for success
    //     ‘E NN’
    //         for an error

    (void) action; // TODO
    (void) first_call; // TODO
    // TODO
    reply_packet_prepare();
    reply_packet_add("OK");
    reply_packet_send();
    return RESULT_OK;
}

void target_send_file(char* filename, uint32_t offset, uint32_t len)
{
    if(0 == strncmp(filename, "target.xml", 10))
    {
        send_part(TARGET_XML_CONTENT, sizeof(TARGET_XML_CONTENT), offset, len);
        return;
    }
    else if(0 == strncmp(filename, "threads", 7))
    {
        send_part(THREADS_CONTENT, sizeof(THREADS_CONTENT), offset, len);
        return;
    }
    else if(0 == strncmp(filename, "memory-map", 10))
    {
        send_part(MEMORY_MAP_CONTENT, sizeof(MEMORY_MAP_CONTENT), offset, len);
        return;
    }

    debug_line("xfer:file invalid");
    // if we reach this, then the request was invalid
    reply_packet_prepare();
    reply_packet_add("E00");
    reply_packet_send();
}
