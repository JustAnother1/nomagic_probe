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

#ifndef NOMAGIC_WALK_H_
#define NOMAGIC_WALK_H_

#include <stdbool.h>
#include <stdint.h>
#include "result.h"

typedef enum {
    WALK_CONNECT = 0,
    WALK_SCAN,
    // new walks go here
    NUM_WALKS_DEFINED,  // <- do not use other than array size !
}walk_typ;

typedef struct{
    uint32_t phase;     //
    uint32_t sub_phase; //
    uint32_t par_i_0;   // targetId     |
    uint32_t par_i_1;   // APSel        |
    Result result;      // RESULT_OK    | RESULT_OK
    uint32_t intern_0;  //              | APnum
    uint32_t intern_1;  //              | AP class
    uint32_t read_0;    //              | value read from AP
    walk_typ type;      // WALK_CONNECT | WALK_SCAN
    bool par_b_0;       // isSWDv2?     |
    bool is_done;
    uint8_t padding;
} walk_data_typ;

void walk_init(void);
void walk_execute(walk_data_typ* data);

#endif /* NOMAGIC_WALK_H_ */
