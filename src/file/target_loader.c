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
#include <stdint.h>
#include <stddef.h>

#include "target_api/target_actions.h"
#include "probe_api/result.h"
#include "probe_api/swd.h"
#include "probe_api/debug_log.h"

// TODO load from configuration

void target_init(void)
{
    debug_line("loader: not available!");
}

void target_tick(void)
{
    // no debug printout as this gets called all the time
}

void target_reply_g(void)
{
    debug_line("loader: not available!");
}

void target_reply_questionmark(void)
{
    debug_line("loader: not available!");
}

void target_reply_write_g(parameter_typ* parsed_parameter)
{
    (void) parsed_parameter; // TODO
    debug_line("loader: not available!");
}

void target_reply_continue(parameter_typ* parsed_parameter)
{
    (void) parsed_parameter; // TODO
    debug_line("loader: not available!");
}

void target_reply_read_memory(parameter_typ* parsed_parameter)
{
    (void) parsed_parameter; // TODO
    debug_line("loader: not available!");
}

void target_reply_write_memory(parameter_typ* parsed_parameter)
{
    (void) parsed_parameter; // TODO
    debug_line("loader: not available!");
}

void target_reply_step(parameter_typ* parsed_parameter)
{
    (void) parsed_parameter; // TODO
    debug_line("loader: not available!");
}

void target_connect(void)
{
    debug_line("loader: not available!");
}

void target_close_connection(void)
{
    debug_line("loader: not available!");
}

void target_send_file(char* filename, uint32_t offset, uint32_t len)
{
    (void) filename;
    (void) offset;
    (void) len;
    debug_line("loader: not available!");
}

bool cmd_target_info(uint32_t loop)
{
    (void)loop;
    debug_line("Target Status");
    debug_line("=============");
    debug_line(" target: not configured !");
    return true; // true == Done; false = call me again
}
