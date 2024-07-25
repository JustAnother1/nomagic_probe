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
#include "cfg/serial_cfg.h"
#include "probe_api/gdb_monitor_defs.h"
#include "probe_api/gdb_packets.h"
#include "probe_api/hex.h"
#include "probe_api/debug_log.h"
#include "probe_api/util.h"
#include "target.h"
// commands:
#include "cmd_qsupported.h"
#include "cmd_qxfer.h"
// replies:
#include "replies.h"
#include "threads.h"


#define NUM_MON_COMMANDS  (sizeof(mon_commands)/sizeof(mon_cmd_typ))

typedef struct {
    bool extended_mode;
    bool noAckMode;
} config_typ;

typedef enum parameter_pattern {
    PARAM_XX,
    PARAM_ADDR_XX,
    PARAM_ADDR_LENGTH_XX,
    PARAM_ADDR_LENGTH,
    PARAM_OPT_ADDR,
    PARAM_ADDR_BINARY,
} param_pattern_typ;



static config_typ cfg;
static parameter_typ parsed_parameter;

static bool checksumOK(char* received, uint32_t length, char* checksum);
static uint32_t cmd_length(char* received, uint32_t length);
static void handle_general_query(char* received, uint32_t length);
static void handle_general_set(char* received, uint32_t length);
static void handle_vee(char* received, uint32_t length);
static void handle_tee(char* received, uint32_t length);
static bool parse_parameter(param_pattern_typ pattern, char* parameter);
static bool parse_memory(char* parameter);
static bool parse_binary(char* parameter);

void commands_init(void)
{
    cfg.extended_mode = false;
    cfg.noAckMode = false;
    threads_init();
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

// received is guaranteed to end with zeros
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

    switch(*received)  // this only looks at the first character of the received string
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
            gdb_is_now_busy();
            if(false == target_reply_questionmark())
            {
                // failed to add command
                send_unknown_command_reply();
            }
            // else OK. Reply packet ends busy state.
            break;

        case 'c':  // continue
        case 'C':  // continue
            gdb_is_now_busy();
            // TODO continue at address ? if(true == parse_parameter(PARAM_XX, received))
            if(false == target_reply_continue())
            {
                // failed to add command
                send_unknown_command_reply();
            }
            // else OK. Reply packet ends busy state.
            break;

        case 'D':  // Detach from client
            commands_init(); // end of the connection -> reset everything to default
            reply_packet_prepare();
            reply_packet_add("OK");
            reply_packet_send();
            break;

        case 'g':  // read general Registers
            gdb_is_now_busy();
            if(false == target_reply_g())
            {
                // failed to add command
                send_unknown_command_reply();
            }
            // else OK. Reply packet ends busy state.
            break;

        case 'G':  // write general Registers
            received++;
            if(true == parse_parameter(PARAM_XX, received))
            {
                gdb_is_now_busy();
                if(false == target_reply_write_g(&parsed_parameter))
                {
                    // failed to add command
                    send_unknown_command_reply();
                }
                // else OK. Reply packet ends busy state.
            }
            break;

        case 'H':  // report the current tread
            handle_H_command(received);
            break;

        case 'k':  // kill the target
            // TODO
            send_unknown_command_reply();
            break;

        case 'M':  // write main memory : M addr,length:XX...
            received++;
            if(true == parse_parameter(PARAM_ADDR_LENGTH_XX, received))
            {
                gdb_is_now_busy();
                if(false == target_reply_write_memory(&parsed_parameter))
                {
                    // failed to add command
                    send_unknown_command_reply();
                }
                // else OK. Reply packet ends busy state.
            }
            break;

        case 'm':  // read main memory : m addr,length
            received++;
            if(true == parse_parameter(PARAM_ADDR_LENGTH, received))
            {
                gdb_is_now_busy();
                if(false == target_reply_read_memory(&parsed_parameter))
                {
                    // failed to add command
                    send_unknown_command_reply();
                }
                // else OK. Reply packet ends busy state.
            }
            break;

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
            received++;
            if(true == parse_parameter(PARAM_OPT_ADDR, received))
            {
                gdb_is_now_busy();
                if(false == target_reply_step(&parsed_parameter))
                {
                    // failed to add command
                    send_unknown_command_reply();
                }
                // else OK. Reply packet ends busy state.
            }
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
        case 'Z':  // clear or set breakpoints or watch points
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
        if(';' == *received)
        {
            // end of command
            return i;
        }
        if('#' == *received)
        {
            // end of command
            return i;
        }
        if(',' == *received)  // used in qRcmd
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
    else
    {
        if(0 == strncmp(received, "vCont", 5))
        {
            // command start with "vCont"
            if('?' == received[5])
            {
                // "vCont?"
                // report the supported vCont actions
                found_cmd = true;
                reply_packet_prepare();
                reply_packet_add("vCont;c;C;s;S");
                reply_packet_send();
                found_cmd = true;
            }
            else if(';' == received[5])
            {
                // specify step or continue actions specific to one or more threads
                if(('c' == received[6]) || ('C' == received[6]))
                {
                    // vCont;c  -> continue
                    found_cmd = true;
                    if(true == target_reply_continue())
                    {
                        found_cmd = true;
                    }
                }
                else if(('s' == received[6]) || ('S' == received[6]))
                {
                    // vCont;s -> single step
                    found_cmd = true;
                    if(true == parse_parameter(PARAM_OPT_ADDR, &(received[7])))
                    {
                        gdb_is_now_busy();
                        if(false == target_reply_step(&parsed_parameter))
                        {
                            // failed to add command
                            send_unknown_command_reply();
                        }
                        // else OK. Reply packet ends busy state.
                    }
                }
            }
        }
        else if(0 == strncmp(received, "vRun", 4))
        {
            // command start with "vRun"
            found_cmd = true;
            // run program
            // TODO
            send_unknown_command_reply();
        }
        else if(0 == strncmp(received, "vAttach", 7))
        {
            // command start with "vAttach"
            found_cmd = true;
            // Attach to (new) process
            // TODO
            send_unknown_command_reply();
        }
        else if(0 == strncmp(received, "vFlashDone", 10))
        {
            // command start with "vFlashDone"
            found_cmd = true;
            gdb_is_now_busy();
            if(false == target_reply_flash_done())
            {
                // failed to add command
                send_unknown_command_reply();
            }
            // else OK. target reply packet ends busy state.
        }
        else if(0 == strncmp(received, "vFlashErase", 11))
        {
            // command start with "vFlashErase"
            found_cmd = true;
            if(true == parse_parameter(PARAM_ADDR_LENGTH, &(received[12])))
            {
                gdb_is_now_busy();
                if(false == target_reply_flash_erase(&parsed_parameter))
                {
                    // failed to add command
                    send_unknown_command_reply();
                }
                // else OK. Reply packet ends busy state.
            }
        }
        else if(0 == strncmp(received, "vFlashWrite", 11))
        {
            // command start with "vFlashWrite"
            found_cmd = true;
            if(true == parse_parameter(PARAM_ADDR_BINARY, &(received[12])))
            {
                gdb_is_now_busy();
                if(false == target_reply_flash_write(&parsed_parameter))
                {
                    // failed to add command
                    send_unknown_command_reply();
                }
                // else OK. Reply packet ends busy state.
            }
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
            handle_qC_command(received);
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
        else if(0 == strncmp(received, "qRcmd", 5))
        {
            found_cmd = true;
            char buf[100];
            size_t len;
            uint32_t i;
            bool found;
            // command is encoded in hex
            decode_hex_string_to_text(&(received[6]), sizeof(buf), buf);
            // execute command in buf
            debug_line("received command: %s!", buf);
            // Target implements monitor commands (reset init, halt,...)
            len = strlen(buf);
            found = false;
            for(i = 0; i < NUM_MON_COMMANDS; i++)
            {
                if(len >= strlen(mon_commands[i].name))
                {
                    if(0 == strncmp(mon_commands[i].name, buf, len))
                    {
                        found = true;
                        break;
                    }
                    // else continue searching
                }
                // else input to short to be this command
            }
            if((false == found) || (i >= NUM_MON_COMMANDS))
            {
                char err_buf[100];
                // invalid command
                reply_packet_prepare();
                reply_packet_add("O"); // packet is $ big oh, hex string# checksum
                encode_text_to_hex_string("ERROR: invalid command (", sizeof(err_buf), err_buf);
                reply_packet_add(err_buf);
                encode_text_to_hex_string(buf, sizeof(err_buf), err_buf);
                reply_packet_add(err_buf);
                encode_text_to_hex_string(") !\r\n", sizeof(err_buf), err_buf);
                reply_packet_add(err_buf);
                reply_packet_send();

                // end of output
                reply_packet_prepare();
                reply_packet_add("OK");
                reply_packet_send();
            }
            else
            {
                // found the command
                gdb_is_now_busy();
                target_monitor_command(i, buf);
            }
        }
    }
    else if(7 == cmd_len)
    {
        if(0 == strncmp(received, "qSymbol", 7))
        {
            found_cmd = true;
            // request any symbol data
            // TODO
            reply_packet_prepare();
            reply_packet_add("OK"); // we do not need to resolve any more Symbols
            reply_packet_send();
        }
    }
    else if(8 == cmd_len)
    {
        if(0 == strncmp(received, "qOffsets", 8))
        {
            found_cmd = true;
            // report the offsets to use when relocating downloaded code
            reply_packet_prepare();
            // reply_packet_add("Text=0;Data=0;"); // Bss value will be ignored and Data value will be used
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
            handle_qfThreadInfo_command(received);
        }
        else if(0 == strncmp(received, "qsThreadInfo", 12))
        {
            found_cmd = true;
            // report the current tread
            handle_qsThreadInfo_command(received);
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

static bool parse_parameter(param_pattern_typ pattern, char* parameter)
{
    // reset values
    parsed_parameter.has_address = false;
    parsed_parameter.num_memory_locations = 0;
    switch(pattern)
    {
    case PARAM_XX: // XX
        return parse_memory(parameter);

    case PARAM_ADDR_XX: // addr:XX
    {
        char* mem_start;
        mem_start = strchr(parameter, ':');
        if(NULL == mem_start)
        {
            // pattern needs to have a ":"
            reply_packet_prepare();
            reply_packet_add("E 04");
            reply_packet_send();
            return false;
        }
        *mem_start = '\0';
        mem_start++;
        parsed_parameter.address = hex_to_int(parameter, 0);
        parsed_parameter.has_address = true;
        // XX is now in mem_start
        return parse_memory(mem_start);
    }


    case PARAM_ADDR_LENGTH_XX: // addr,length:XX
    {
        char* mem_start;
        char* split_pos = strchr(parameter, ',');
        if(NULL == split_pos)
        {
            // pattern needs to have a ","
            reply_packet_prepare();
            reply_packet_add("E 03");
            reply_packet_send();
            return false;
        }
        *split_pos = '\0';
        split_pos++;
        mem_start = strchr(parameter, ':');
        if(NULL == mem_start)
        {
            // pattern needs to have a ":"
            reply_packet_prepare();
            reply_packet_add("E 04");
            reply_packet_send();
            return false;
        }
        *mem_start = '\0';
        mem_start++;
        parsed_parameter.address = hex_to_int(parameter, 0);
        parsed_parameter.has_address = true;
        parsed_parameter.length = hex_to_int(split_pos, 0);
        // XX is now in mem_start
        return parse_memory(mem_start);
    }

    case PARAM_ADDR_LENGTH: // addr,length
    {
        char* split_pos = strchr(parameter, ',');
        if(NULL == split_pos)
        {
            // pattern needs to have a ","
            reply_packet_prepare();
            reply_packet_add("E 03");
            reply_packet_send();
            return false;
        }
        *split_pos = '\0';
        split_pos++;
        parsed_parameter.address = hex_to_int(parameter, 0);
        parsed_parameter.has_address = true;
        parsed_parameter.length = hex_to_int(split_pos, 0);
        break;
    }

    case PARAM_OPT_ADDR: // optionaly addr
        if('\0' != *parameter)
        {
            parsed_parameter.address = hex_to_int(parameter, 0);
            parsed_parameter.has_address = true;
        }
        else
        {
            parsed_parameter.has_address = false;
        }
        break;

    case PARAM_ADDR_BINARY:  // address followed by binary data
    {
        char* mem_start;
        mem_start = strchr(parameter, ':');
        if(NULL == mem_start)
        {
            // pattern needs to have a ":"
            reply_packet_prepare();
            reply_packet_add("E 04");
            reply_packet_send();
            return false;
        }
        *mem_start = '\0';
        mem_start++;
        parsed_parameter.address = hex_to_int(parameter, 0);
        parsed_parameter.has_address = true;
        // XX is now in mem_start
        return parse_binary(mem_start);
    }

    default:
        // invalid pattern
        reply_packet_prepare();
        reply_packet_add("E 02");
        reply_packet_send();
        return false;
    }
    return true;
}

static bool parse_binary(char* parameter)
{
    if(NULL == parameter)
    {
        return false;
    }
    if(0 == *parameter)
    {
        return false;
    }
    // TODO
    return true;
}

static bool parse_memory(char* parameter)
{
    // string is something like this:  xxxxxxxx00000000xxxxxxxx00000000
    uint32_t i;
    uint32_t len = strlen(parameter);
    if(len < 8)
    {
        // we need at least one 32bit value
        reply_packet_prepare();
        reply_packet_add("E 05");
        reply_packet_send();
        return false;
    }
    if(0 != len%8)
    {
        // we are doing 32bit values only
        reply_packet_prepare();
        reply_packet_add("E 06");
        reply_packet_send();
        return false;
    }
    parsed_parameter.num_memory_locations = len/8;
    for(i = 0; i < len/8; i++)
    {
        if(('x' == parameter[i*8]) || ('X' == parameter[i*8]))
        {
            // this value is skipped
            parsed_parameter.memory[i].has_value = false;
        }
        else
        {
            parsed_parameter.memory[i].has_value = true;
            parsed_parameter.memory[i].value = hex_to_int(&(parameter[i*8]), 8);
        }
    }
    return true;
}
