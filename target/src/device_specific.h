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

#ifndef DEVICE_SPECIFIC_H_
#define DEVICE_SPECIFIC_H_

#include <stdbool.h>
#include <stdint.h>
#include "result.h"

typedef enum {
    GDB_CMD_G = 0,
    // new actions go here
    NUM_ACTIONS,  // <- do not use other than array size !
}action_typ;

typedef struct{
    action_typ action;
} action_data_typ;

Result handle_target_reply_g(action_data_typ* action, bool first_call);


#endif /* DEVICE_SPECIFIC_H_ */
