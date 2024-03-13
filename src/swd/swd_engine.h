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

#ifndef SWD_SWD_ENGINE_H_
#define SWD_SWD_ENGINE_H_

#include <stdbool.h>
#include <stdint.h>
#include "probe_api/result.h"

typedef enum {
    CMD_CONNECT = 0,
    CMD_READ,
    CMD_WRITE,
    CMD_READ_REG,
    CMD_WRITE_REG,
    // new orders go here
    NUM_ORDERS,  // <- do not use other than array size !
}order_typ;

typedef struct{
    order_typ order;
    bool flag;
    uint32_t address;
    uint32_t i_val;
    uint32_t i_val_1;
    uint32_t i_val_2;
    Result transaction_id;
} command_typ;

// parameter phase value is:
// 0 == calling for the first time
// negative value (-1, -2,..    = currently not used
// positive value (1, 2, 3,...) = returned value of last call
// return value is:
// 0                            = OK      -> order was executed successfully
// negative value (-1, -2,..    = ERROR   -> something went wrong, order failed
// positive value (1, 2, 3,...) = WORKING -> more steps necessary, call order_handler again
typedef Result (*order_handler)(command_typ* cmd, bool first_call);

void swd_eingine_add_cmd_result(Result idx, uint32_t data);

#endif /* SWD_SWD_ENGINE_H_ */
