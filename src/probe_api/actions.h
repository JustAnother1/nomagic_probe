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

#ifndef PROBE_API_ACTIONS_H_
#define PROBE_API_ACTIONS_H_

#include "common.h"
#include "target/common_actions.h"
#include "cfg/target_specific_actions.h"


const action_handler action_look_up[NUM_ACTIONS] = {
        handle_target_connect,
        handle_target_close_connection,
        handle_target_reply_g,
        handle_target_reply_questionmark,
        handle_target_reply_write_g,
        handle_target_reply_continue,
        handle_target_reply_read_memory,
        handle_target_reply_write_memory,
        handle_target_reply_step,
        TARGET_SPECIFIC_ACTION_HANDLERS
};


#endif /* PROBE_API_ACTIONS_H_ */
