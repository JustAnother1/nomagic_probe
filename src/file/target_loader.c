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

}

void target_tick(void)
{

}

void target_reply_g(void)
{

}

void target_reply_questionmark(void)
{

}

void target_reply_write_g(char* received, uint32_t length)
{
    (void) received; // TODO
    (void) length; // TODO
}

void target_reply_continue(char* received, uint32_t length)
{
    (void) received; // TODO
    (void) length; // TODO
}

void target_reply_read_memory(char* received, uint32_t length)
{
    (void) received; // TODO
    (void) length; // TODO
}

void target_reply_write_memory(char* received, uint32_t length)
{
    (void) received; // TODO
    (void) length; // TODO
}

void target_reply_step(char* received, uint32_t length)
{
    (void) received; // TODO
    (void) length; // TODO
}

Result target_request_read(uint32_t address)
{
    (void) address;
    debug_line("loader: not available!");
    return ERR_WRONG_STATE;
}

Result target_read_result(Result transaction, uint32_t* data)
{
    (void)transaction;
    (void)data;
    debug_line("loader: not available!");
    return ERR_WRONG_STATE;
}

Result target_connect(bool first_call)
{
    (void) first_call;
    debug_line("loader: not available!");
    return ERR_WRONG_STATE;
}

void target_send_file(char* filename, uint32_t offset, uint32_t len)
{
    (void) filename;
    (void) offset;
    (void) len;
}
