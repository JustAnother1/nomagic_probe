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

#include <stdio.h>
#include <string.h>

#include "probe_api/debug_log.h"
#include "probe_api/gdb_monitor_commands.h"
#include "probe_api/gdb_monitor_defs.h"
#include "probe_api/gdb_packets.h"
#include "probe_api/util.h"
#include "target.h"
#include "version.h"

// monitor commands inspired by / copied from :
// https://openocd.org/doc/html/General-Commands.html

void target_monitor_command(uint32_t which, char* command)
{
    switch(which)
    {
    case MON_CMD_IDX_HELP:
        mon_cmd_help(command);
        break;

    case MON_CMD_IDX_VERSION:
        mon_cmd_version();
        break;

    case MON_CMD_IDX_RESET:
        mon_cmd_reset(command);
        break;

    case MON_CMD_IDX_HALT:
        mon_cmd_halt();
        break;

    case MON_CMD_IDX_REG:
        mon_cmd_reg(command);
        break;

    // new monitor commands go here

    default:
    {
        char buf[100];
        reply_packet_prepare();
        reply_packet_add("O"); // packet is $ big oh, hex string# checksum
        encode_text_to_hex_string("ERROR: invalid command !\r\n", sizeof(buf), buf);
        reply_packet_add(buf);
        reply_packet_send();

        reply_packet_prepare();
        reply_packet_add("E00");
        reply_packet_send();

        gdb_is_not_busy_anymore();
    }
        break;
    }
}

void mon_cmd_help(char* command)
{
    // help command
    char buf[100];
    char hex_buf[200];
    uint32_t loop;
    char* parameter = NULL;

    // test if we go a parameter
    loop = 0;
    while(0 != command[loop])
    {
        if(' ' == command[loop])
        {
            parameter = command + loop + 1;
            break;
        }
        loop ++;
    }
    // no parameter print everything, with command as parameter only print
    // help for that command.
    if(NULL == parameter)
    {
        // help for all commands
        for(loop = 0; loop < NUM_MON_COMMANDS; loop++)
        {
            reply_packet_prepare();
            reply_packet_add("O"); // packet is $ big oh, hex string# checksum
            snprintf(buf, 100, "%25s : %s\r\n", mon_commands[loop].name, mon_commands[loop].help);
            encode_text_to_hex_string(buf, sizeof(hex_buf), hex_buf);
            reply_packet_add(hex_buf);
            reply_packet_send();
        }
    }
    else
    {
        debug_line("command has parameter : %s !", parameter);
        // help for that command
        for(loop = 0; loop < NUM_MON_COMMANDS; loop++)
        {
            if(0 == strncmp(mon_commands[loop].name, parameter, sizeof(mon_commands[loop].name)))
            {
                reply_packet_prepare();
                reply_packet_add("O"); // packet is $ big oh, hex string# checksum
                snprintf(buf, 100, "%25s : %s\r\n", mon_commands[loop].name, mon_commands[loop].help);
                encode_text_to_hex_string(buf, sizeof(hex_buf), hex_buf);
                reply_packet_add(hex_buf);
                reply_packet_send();
                break;
            }
        }
    }

    // end of output
    reply_packet_prepare();
    reply_packet_add("OK");
    reply_packet_send();

    gdb_is_not_busy_anymore();
}

void mon_cmd_version(void)
{
    char hex_buf[200];

    reply_packet_prepare();
    reply_packet_add("O"); // packet is $ big oh, hex string# checksum
    encode_text_to_hex_string(VERSION, sizeof(hex_buf), hex_buf);
    reply_packet_add(hex_buf);
    encode_text_to_hex_string("\r\n", sizeof(hex_buf), hex_buf);
    reply_packet_add(hex_buf);
    reply_packet_send();

    // end of output
    reply_packet_prepare();
    reply_packet_add("OK");
    reply_packet_send();

    gdb_is_not_busy_anymore();
}

void mon_cmd_halt(void)
{
    // Command: halt [ms]
    // Command: wait_halt [ms]
    // The halt command first sends a halt request to the target, which wait_halt
    // doesn’t. Otherwise these behave the same: wait up to ms milliseconds, or
    // 5 seconds if there is no parameter, for the target to halt (and enter
    // debug mode). Using 0 as the ms parameter prevents OpenOCD from waiting.

    add_action(GDB_CMD_MON_HALT);
}

void mon_cmd_reset(char* command)
{
    // Perform as hard a reset as possible, using SRST if possible. All defined
    // targets will be reset, and target events will fire during the reset sequence.
    if(0 == strncmp("reset init", command, sizeof("reset init")))
    {
        // Immediately halt the target, and execute the reset-init script
        add_action(GDB_CMD_MON_RESET_INIT);
    }
    else if(0 == strncmp("reset halt", command, sizeof("reset halt")))
    {
        // Immediately halt the target
    }
    else
    {
        // reset or reset run
        // Let the target run
    }
}

/*

(gdb) monitor reg
===== arm v7m registers
(0) r0 (/32): 0x00000080
(1) r1 (/32): 0x2002f91c (dirty)
(2) r2 (/32): 0x00000000 (dirty)
(3) r3 (/32): 0x00000000 (dirty)
(4) r4 (/32): 0x2002386c
(5) r5 (/32): 0x00000002
(6) r6 (/32): 0x00000001
(7) r7 (/32): 0x000195d4 (dirty)
(8) r8 (/32): 0x20021274
(9) r9 (/32): 0x000069ae
(10) r10 (/32): 0x100005c0
(11) r11 (/32): 0x200343c0
(12) r12 (/32): 0x00002ee0
(13) sp (/32): 0x20041f64 (dirty)
(14) lr (/32): 0x20006fab (dirty)
(15) pc (/32): 0x2000a87c (dirty)
(16) xPSR (/32): 0x61000000 (dirty)
(17) msp (/32): 0x20041f64 (dirty)
(18) psp (/32): 0xfffffffc
(20) primask (/1): 0x00 (dirty)
(21) basepri (/8): 0x00
(22) faultmask (/1): 0x00
(23) control (/3): 0x00
===== Cortex-M DWT registers
(gdb)

(gdb) monitor reg r0
r0 (/32): 0x00000080
(gdb)

(gdb) monitor reg r1
r1 (/32): 0x2002f91c
(gdb)


 */

void mon_cmd_reg(char* command)
{
	parameter_typ parsed_parameter;
    // command can be "reg" or reg + register name like this "reg r0"
    bool valid_register = true;
    if(3 == strlen(command))
    {
        // command is "reg"
        char buf[100];
        parsed_parameter.has_index = false;

        reply_packet_prepare();
        reply_packet_add("O"); // packet is $ big oh, hex string# checksum
        encode_text_to_hex_string("===== arm v7m registers\r\n", sizeof(buf), buf);
        reply_packet_add(buf);
        reply_packet_send();
    }
    else
    {
        // command is "reg" + register name
        char* register_name = command + 4;
        parsed_parameter.has_index = true;
        if('r' == *register_name)
        {
            switch(register_name[1])
            {
            case '0': parsed_parameter.index = 0; break;
            case '1': switch(register_name[2])
                      {
                      case 0 :  parsed_parameter.index = 1; break;
                      case '0': parsed_parameter.index = 10; break;
                      case '1': parsed_parameter.index = 11; break;
                      case '2': parsed_parameter.index = 12; break;
                      default: valid_register = false; break;
                      }
                      break;
            case '2': parsed_parameter.index = 2; break;
            case '3': parsed_parameter.index = 3; break;
            case '4': parsed_parameter.index = 4; break;
            case '5': parsed_parameter.index = 5; break;
            case '6': parsed_parameter.index = 6; break;
            case '7': parsed_parameter.index = 7; break;
            case '8': parsed_parameter.index = 8; break;
            case '9': parsed_parameter.index = 9; break;

            default: valid_register = false; break;
            }
        }
        else
        {
            if(0 == strncmp("sp", command, sizeof("sp")))
            {
                parsed_parameter.index = 13;
            }
            else if(0 == strncmp("lr", command, sizeof("lr")))
            {
                parsed_parameter.index = 14;
            }
            else if(0 == strncmp("pc", command, sizeof("pc")))
            {
                parsed_parameter.index = 15;
            }
            else if(0 == strncmp("xPSR", command, sizeof("xPSR")))
            {
                parsed_parameter.index = 16;
            }
            else if(0 == strncmp("msp", command, sizeof("msp")))
            {
                parsed_parameter.index = 17;
            }
            else if(0 == strncmp("psp", command, sizeof("psp")))
            {
                parsed_parameter.index = 18;
            }
            else if(0 == strncmp("primask", command, sizeof("primask")))
            {
                parsed_parameter.index = 20;
            }
            else if(0 == strncmp("basepri", command, sizeof("basepri")))
            {
                parsed_parameter.index = 20;
            }
            else if(0 == strncmp("faultmask", command, sizeof("faultmask")))
            {
                parsed_parameter.index = 20;
            }
            else if(0 == strncmp("control", command, sizeof("control")))
            {
                parsed_parameter.index = 20;
            }
            else
            {
                valid_register = false;
            }
        }
    }

    if(false == valid_register)
    {
        char buf[100];
        reply_packet_prepare();
        reply_packet_add("O"); // packet is $ big oh, hex string# checksum
        encode_text_to_hex_string("ERROR: invalid register name given !\r\n", sizeof(buf), buf);
        reply_packet_add(buf);
        reply_packet_send();

        reply_packet_prepare();
        reply_packet_add(command);
        reply_packet_send();

        reply_packet_prepare();
        reply_packet_add("E01");
        reply_packet_send();

        gdb_is_not_busy_anymore();
    }
    else
    {
        add_action_with_parameter(GDB_MONITOR_REG, &parsed_parameter);
    }
}

