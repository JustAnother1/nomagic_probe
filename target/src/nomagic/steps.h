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

#ifndef NOMAGIC_STEPS_H_
#define NOMAGIC_STEPS_H_

#include <stdbool.h>
#include <stdint.h>
#include "result.h"

typedef enum {
    STEP_CONNECT = 0,
    STEP_AP_READ,
    STEP_AP_WRITE,
    STEP_AP_REG_READ,
    STEP_AP_REG_WRITE,
    STEP_DISCONNECT,
    // new steps go here
    NUM_STEPS_DEFINED,  // <- do not use other than array size !
}step_typ;

typedef struct{       //
    uint32_t phase;   //
    uint32_t par_i_0; //     targetId    | address            | address         | bank                  | bank              |
    uint32_t par_i_1; //     APSel       |                    | value           | register              | register          |
    uint32_t par_i_2; //                 |                    |                 |                       | value             |
    Result result;    //     RESULT_OK   | RESULT_OK          | RESULT_OK       | RESULT_OK             | RESULT_OK         | RESULT_OK
    int32_t intern_0; //                 | transfer id        |                 |                       |                   |
    uint32_t read_0;  //                 | value read from AP |                 | value read from APreg |                   |
    step_typ type;    //    STEP_CONNECT | STEP_AP_READ       | STEP_AP_WRITE   | STEP_AP_REG_READ      | STEP_AP_REG_WRITE | STEP_DISCONNECT
    bool par_b_0;     //       isSWDv2?  |                    |                 |                       |                   |
    bool is_done;
    uint8_t padding;
} step_data_typ;

void steps_execute(step_data_typ* cur_step);

#endif /* NOMAGIC_STEPS_H_ */
