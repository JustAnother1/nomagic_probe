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

#include <stdint.h>
#include <stdbool.h>
#include "probe_api/common.h"
#include "probe_api/debug_log.h"
#include "probe_api/gdb_packets.h"
#include "probe_api/result.h"
#include "probe_api/util.h"
#include "target.h"


bool cmd_target_info(uint32_t loop)
{
    if(0 == loop)
    {
        debug_line("Target Status");
        debug_line("=============");
        debug_line("target: no");
    }
    else
    {
        return common_cmd_target_info(loop -1);
    }
    return false; // true == Done; false = call me again
}

void target_send_file(char* filename, uint32_t offset, uint32_t len)
{
    (void)filename;
    (void)offset;
    (void)len;
}

bool target_is_SWDv2(void)
{
    return false;
}

uint32_t target_get_SWD_core_id(uint32_t core_num)
{
    (void) core_num;
    return 0;
}

uint32_t target_get_SWD_APSel(uint32_t core_num)
{
    (void) core_num;
    return 0;
}

Result handle_target_reply_vFlashDone(action_data_typ* const action, bool first_call)
{
    (void) action;
    (void) first_call;
    return RESULT_OK;
}

Result handle_target_reply_vFlashErase(action_data_typ* const action, bool first_call)
{
    (void) action;
    (void) first_call;
    return RESULT_OK;
}

Result handle_target_reply_vFlashWrite(action_data_typ* const action, bool first_call)
{
    (void) action;
    (void) first_call;
    return RESULT_OK;
}

void target_monitor_command(uint32_t which, char* command)
{
    char buf[100];
    (void)command;
    (void)which;
    reply_packet_prepare();
    reply_packet_add("O"); // packet is $ big oh, hex string# checksum
    encode_text_to_hex_string("ERROR: invalid command !\r\n", sizeof(buf), buf);
    reply_packet_add(buf);
    reply_packet_send();
    gdb_is_not_busy_anymore();
}

