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
#ifndef TARGET_TARGET_ACTIONS_H_
#define TARGET_TARGET_ACTIONS_H_

#include <stdbool.h>
#include <stdint.h>
#include "../probe_api/result.h"

void target_init(void);
void target_tick(void);
bool cmd_target_info(uint32_t loop);
bool target_is_connected(void);
Result target_close_connection(bool first_call);
Result target_connect(bool first_call);
Result target_request_read(uint32_t address);
Result target_read_result(Result transaction, uint32_t* data);

void target_reply_g(void);
void target_reply_questionmark(void);
void target_reply_write_g(char* received, uint32_t length);
void target_reply_continue(char* received, uint32_t length);
void target_reply_read_memory(char* received, uint32_t length);
void target_reply_write_memory(char* received, uint32_t length);
void target_reply_step(char* received, uint32_t length);

#endif /* TARGET_TARGET_ACTIONS_H_ */
