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

typedef enum {
    CONNECT = 0,
    SCAN,
    READ,
    // new orders go here
    NUM_ORDERS,  // <- do not use other than array size !
}order_typ;

typedef struct{
    order_typ order;
    bool flag;
    uint32_t i_val;
    uint32_t transaction_id;
} command_typ;

void swd_init(void);
void swd_tick(void);

#endif /* SWD_SWD_ENGINE_H_ */
