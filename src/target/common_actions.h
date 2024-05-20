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
#ifndef TARGET_COMMON_ACTIONS_H_
#define TARGET_COMMON_ACTIONS_H_

#include "probe_api/common.h"

Result handle_target_connect(action_data_typ* const action, bool first_call);
Result handle_target_close_connection(action_data_typ* const action, bool first_call);
#ifdef FEAT_GDB_SERVER
Result handle_target_reply_g(action_data_typ* const action, bool first_call);
Result handle_target_reply_write_g(action_data_typ* const action, bool first_call);
Result handle_target_reply_questionmark(action_data_typ* const action, bool first_call);
Result handle_target_reply_continue(action_data_typ* const action, bool first_call);
Result handle_target_reply_read_memory(action_data_typ* const action, bool first_call);
Result handle_target_reply_write_memory(action_data_typ* const action, bool first_call);
Result handle_target_reply_step(action_data_typ* const action, bool first_call);
#endif

#endif /* TARGET_COMMON_ACTIONS_H_ */
