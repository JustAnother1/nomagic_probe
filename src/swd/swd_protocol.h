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
#ifndef SRC_SWD_SWD_PROTOCOL_H_
#define SRC_SWD_SWD_PROTOCOL_H_

#include <stdint.h>
#include <stdbool.h>
#include "swd_engine.h"
#include "probe_api/result.h"

void swd_protocol_init(void);
void swd_protocol_tick(void);
Result connect_handler(int32_t phase, command_typ* cmd);
Result scan_handler(int32_t phase, command_typ* cmd);
Result read_handler(int32_t phase, command_typ* cmd);
void swd_disconnect(void);

#endif /* SRC_SWD_SWD_PROTOCOL_H_ */
