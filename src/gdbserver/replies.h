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

#ifndef GDBSERVER_REPLIES_H_
#define GDBSERVER_REPLIES_H_

#include <stdint.h>
#include <stdbool.h>
#include "probe_api/common.h"

bool target_reply_g(void);
bool target_reply_questionmark(void);
bool target_reply_write_g(parameter_typ* parsed_parameter);
bool target_reply_continue(void);
bool target_reply_read_memory(parameter_typ* parsed_parameter);
bool target_reply_write_memory(parameter_typ* parsed_parameter);
bool target_reply_step(parameter_typ* parsed_parameter);
bool target_reply_flash_done(void);
bool target_reply_flash_erase(parameter_typ* parsed_parameter);
bool target_reply_flash_write(parameter_typ* parsed_parameter);


#endif /* GDBSERVER_REPLIES_H_ */
