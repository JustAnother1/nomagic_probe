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
#include "commands.h"
#include <stdint.h>
#include <stdbool.h>
#include "util.h"
#include "cfg/gdbserver_cfg.h"
#include "target_api/target_actions.h"
#include "probe_api/gdb_packets.h"
// commands:
#include "cmd_qsupported.h"
#include "cmd_qxfer.h"

typedef struct {
    bool extended_mode;
    bool noAckMode;
} config_typ;


static config_typ cfg;

static bool checksumOK(char* received, uint32_t length, char* checksum);
static uint32_t cmd_length(char* received, uint32_t length);
static void handle_general_query(char* received, uint32_t length);
static void handle_general_set(char* received, uint32_t length);
static void handle_vee(char* received, uint32_t length);
static void handle_tee(char* received, uint32_t length);

void commands_init(void)
{
    cfg.extended_mode = false;
    cfg.noAckMode = false;
}


// split received packet into command + parameters
// split by ',', ';' and ':'
// The binary data representation uses 7d (ASCII ‘}’) as an escape character.
// Any escaped byte is transmitted as the escape character followed by the original character XORed with 0x20.
// For example, the byte 0x7d would be transmitted as the two bytes 0x7d 0x5d.
// The bytes 0x23 (ASCII ‘#’), 0x24 (ASCII ‘$’), and 0x7d (ASCII ‘}’) must always be escaped.
// Responses sent by the stub must also escape 0x2a (ASCII ‘*’),
// so that it is not interpreted as the start of a run-length encoded sequence (described next).
// Response data can be run-length encoded to save space.
// Run-length encoding replaces runs of identical characters with one instance of the repeated character,
// followed by a ‘*’ and a repeat count. The repeat count is itself sent encoded,
// to avoid binary characters in data: a value of n is sent as n+29. For a repeat count greater or equal to 3,
// this produces a printable ASCII character, e.g. a space (ASCII code 32) for a repeat count of 3.
// (This is because run-length encoding starts to win for counts 3 or more.)
// Thus, for example, ‘0* ’ is a run-length encoding of “0000”: the space character after ‘*’ means repeat the leading 0 32 - 29 = 3 more times.
// The printable characters ‘#’ and ‘$’ or with a numeric value greater than 126 must not be used.
// Runs of six repeats (‘#’) or seven repeats (‘$’) can be expanded using a repeat count of only five (‘"’). For example, ‘00000000’ can be encoded as ‘0*"00’.

void commands_execute(char* received, uint32_t length, char* checksum)
{
    debug_line("gdbs received: %s", received);
    if(false == checksumOK(received, length, checksum))
    {
        debug_line("checksum is wrong($%s#%s)!", received, checksum);
        send_error_packet();
        return;
    }
    // else OK
    if(false == cfg.noAckMode)
    {
        send_ack_packet();  // ack the received packet
    }

    switch(*received)
    {
        case '!': // enable extended mode
            if(1 == length)
            {
                cfg.extended_mode = true;
                reply_packet_prepare();
                reply_packet_add("OK");
                reply_packet_send();
            }
            else
            {
                send_unknown_command_reply();
            }
            break;

        case '?':  // Report why the target halted
            // TODO report correct reason
            reply_packet_prepare();
            reply_packet_add("S05");
            reply_packet_send();
            break;

        case 'g':  // read  or write general Registers
            reply_packet_prepare();
            target_reply_g();
            reply_packet_send();
            break;

        case 'c':  // continue
        case 'C':  // continue
        case 'D':  // Detach from client
        case 'G':  // read  or write general Registers
        case 'H':  // report the current tread
            // Hc ?
        case 'k':  // kill the target
        case 'M':  // read  or write main memory
        case 'm':  // read  or write main memory
        case 'P':  // read  or write specific Register
        case 'p':  // read  or write specific Register
            // TODO
            send_unknown_command_reply();
            break;

        case 'q': // general query
            if(1 < length)
            {
                handle_general_query(received, length);
            }
            else
            {
                send_unknown_command_reply();
            }
            break;

        case 'Q': // general set
            if(1 < length)
            {
                handle_general_set(received, length);
            }
            else
            {
                send_unknown_command_reply();
            }
            break;

        case 'R':  // Restart the program being run
        case 's':  // step
        case 'S':  // step
            // TODO
            send_unknown_command_reply();
            break;

        case 'T':  // report if a particular Thread is alive
            // TODO
            send_unknown_command_reply();
            break;

        case 't':
            handle_tee(received, length);
            break;

        case 'v':
            handle_vee(received, length);
            break;

        case 'X':  // load binary data
        case 'Z':  // clear or set breakpoints or watchpoints
            // TODO
            send_unknown_command_reply();
            break;

        default : // unknown or unsupported command
            send_unknown_command_reply();
            break;
    }
}

static bool checksumOK(char* received, uint32_t length, char* checksum)
{
    uint32_t calculated_sum = 0;
    uint32_t recieved_sum;

    calculated_sum = calculateChecksum(received, length);
    recieved_sum = hex_to_int(checksum, 2);

    if(calculated_sum == recieved_sum)
    {
        return true;
    }
    else
    {
        debug_line("gdbs: CRC expected: 0x%02lx received : 0x%02lx", calculated_sum, recieved_sum);
        return false;
    }
}

static uint32_t cmd_length(char* received, uint32_t length)
{
    uint32_t i;
    for(i = 0; i < length; i++)
    {
        if(0 == *received)
        {
            // should not happen;
            return i;
        }
        if(':' == *received)
        {
            // end of command
            return i;
        }
        if('#' == *received)
        {
            // end of command
            return i;
        }
        received++;
    }
    return length;
}

static void handle_vee(char* received, uint32_t length)
{
    uint32_t cmd_len = cmd_length(received, length);
    bool found_cmd = false;
    if(1 == cmd_len)
    {
        if('v' == *received)
        {
            found_cmd = true;
            // Report the features supported by the server.
            // TODO parse parameters
            reply_packet_prepare();
            // TODO add supported features
            reply_packet_add("hwbreak+");
            reply_packet_send();
        }
    }
    else if(4 == cmd_len)
    {
        if(0 == strncmp(received, "vRun", 4))
        {
            found_cmd = true;
            // run program
            // TODO
            send_unknown_command_reply();
        }
    }
    else if(5 == cmd_len)
    {
        if(0 == strncmp(received, "vCont", 5))
        {
            found_cmd = true;
            // specify step or continue actions specific to one or more threads
            // TODO
            send_unknown_command_reply();
        }
    }
    else if(6 == cmd_len)
    {
        if(0 == strncmp(received, "vCont?", 6))
        {
            // report the supported vCont actions
            // TODO
            send_unknown_command_reply();
        }
    }
    else if(7 == cmd_len)
    {
        if(0 == strncmp(received, "vAttach", 7))
        {
            found_cmd = true;
            // Attach to (new) process
            // TODO
            send_unknown_command_reply();
        }
    }

    if(false == found_cmd)
    {
        send_unknown_command_reply();
    }
}

static void handle_tee(char* received, uint32_t length)
{
    uint32_t cmd_len = cmd_length(received, length);
    bool found_cmd = false;

    if(12 == cmd_len)
    {
        if(0 == strncmp(received, "target async", 12))
        {
            found_cmd = true;
            // debug with other core running
            // TODO
            send_unknown_command_reply();
        }
    }
    else if(21 == cmd_len)
    {
        if(0 == strncmp(received, "target extended-async", 21))
        {
            found_cmd = true;
            // debug with other core running
            // TODO
            send_unknown_command_reply();
        }
    }

    if(false == found_cmd)
    {
        send_unknown_command_reply();
    }
}

static void handle_general_query(char* received, uint32_t length)
{
    uint32_t cmd_len = cmd_length(received, length);
    bool found_cmd = false;

    if(2 == cmd_len)
    {
        if(0 == strncmp(received, "qC", 2))
        {
            found_cmd = true;
            // report the current tread
            reply_packet_prepare();
            reply_packet_add("0");
            reply_packet_send();
        }
        else if(0 == strncmp(received, "qL", 2))
        {
            found_cmd = true;
            // report the current tread
            reply_packet_prepare();
            reply_packet_add("qM001");
            reply_packet_send();
        }
    }
    else if(5 == cmd_len)
    {
        if(0 == strncmp(received, "qXfer", 5))
        {
            found_cmd = true;
            // qXfer:features:read:target.xml:0,3fb
            handle_cmd_qXfer(received +5, length - 5);
        }
    }
    else if(7 == cmd_len)
    {
        if(0 == strncmp(received, "qSymbol", 7))
        {
            found_cmd = true;
            // request any symbol data
            // TODO
            send_unknown_command_reply();
        }
    }
    else if(8 == cmd_len)
    {
        if(0 == strncmp(received, "qOffsets", 8))
        {
            found_cmd = true;
            // report the offsets to use when relocating downloaded code
            reply_packet_prepare();
            reply_packet_add("Text=000;Data=000"); // Bss value will be ignored and Data value will be used
            // warning: Target reported unsupported offsets: Text=0;Data=0;Bss=0;
            reply_packet_send();
        }
    }
    else if(9 == cmd_len)
    {
        if(0 == strncmp(received, "qAttached", 9))
        {
            found_cmd = true;
            reply_packet_prepare();
            reply_packet_add("1"); // 1 = attached to an existing process, 0 = created a new process, E = error
            reply_packet_send();
        }
    }
    else if(10 == cmd_len)
    {
        if(0 == strncmp(received, "qSupported", 10))
        {
            found_cmd = true;
            commands_init(); // might be a new connection -> reset everything to default
            // report the supported features of the probe.
            handle_cmd_qSupported(received +10, length - 10);
        }
    }
    else if(11 == cmd_len)
    {
        if(0 == strncmp(received, "qGetTLSAddr", 11))
        {
            found_cmd = true;
            // report the current tread
            // TODO
            send_unknown_command_reply();
        }
    }
    else if(12 == cmd_len)
    {
        if(0 == strncmp(received, "qfThreadInfo", 12))
        {
            found_cmd = true;
            // report the current tread
            reply_packet_prepare();
            reply_packet_add("l"); // l = end of list
            reply_packet_send();
        }
        else if(0 == strncmp(received, "qsThreadInfo", 12))
        {
            found_cmd = true;
            // report the current tread
            reply_packet_prepare();
            reply_packet_add("l"); // l = end of list
            reply_packet_send();
        }
    }
    else if(16 == cmd_len)
    {
        if(0 == strncmp(received, "qThreadExtraInfo", 16))
        {
            found_cmd = true;
            // report the current tread
            // TODO
            send_unknown_command_reply();
        }
    }

    if(false == found_cmd)
    {
        send_unknown_command_reply();
    }
}

static void handle_general_set(char* received, uint32_t length)
{
    uint32_t cmd_len = cmd_length(received, length);
    bool found_cmd = false;

    if(15 == cmd_len)
    {
        if(0 == strncmp(received, "QStartNoAckMode", 15))
        {
            found_cmd = true;
            // QStartNoAckMode
            cfg.noAckMode = true;
            reply_packet_prepare();
            reply_packet_add("OK");
            reply_packet_send();
        }
    }

    if(false == found_cmd)
    {
        send_unknown_command_reply();
    }
}

