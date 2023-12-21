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

void target_init(void);
int32_t target_connect(void);
bool target_is_connected(void);
int32_t target_request_read(uint32_t address);
int32_t target_read_result(uint32_t transaction, uint32_t* data);

void target_reply_g(void);

#endif /* TARGET_TARGET_ACTIONS_H_ */
