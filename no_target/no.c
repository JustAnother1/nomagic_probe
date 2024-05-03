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
#include "result.h"
#include "debug_log.h"
#include "device_specific.h"
#include "common.h"


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

Result handle_target_close_connection(action_data_typ* action, bool first_call)
{
    (void)action;
    (void)first_call;
    return RESULT_OK;
}

Result handle_target_connect(action_data_typ* action, bool first_call)
{
    (void)action;
    (void)first_call;
    return RESULT_OK;
}

Result handle_target_reply_g(action_data_typ* action, bool first_call)
{
    (void)action;
    (void)first_call;
    return RESULT_OK;
}

Result handle_target_reply_write_g(action_data_typ* action, bool first_call)
{
    (void)action;
    (void)first_call;
    return RESULT_OK;
}

void target_send_file(char* filename, uint32_t offset, uint32_t len)
{
    (void)filename;
    (void)offset;
    (void)len;
}
