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
#include "../probe_api/result.h"

#define MAX_MEMORY_POSITIONS   20

typedef struct {
    uint32_t value;
    bool has_value;
    uint8_t padding[3];
} mem_val_typ;

typedef struct {
    uint32_t address;
    uint32_t length;
    uint32_t num_memeory_locations;
    mem_val_typ memory[MAX_MEMORY_POSITIONS];
} parameter_typ;

void target_init(void);
void target_tick(void);
bool cmd_target_info(uint32_t loop);

void target_close_connection(void);
void target_connect(void);
void target_reply_g(void);
void target_reply_questionmark(void);
void target_reply_write_g(parameter_typ* parsed_parameter);
void target_reply_continue(parameter_typ* parsed_parameter);
void target_reply_read_memory(parameter_typ* parsed_parameter);
void target_reply_write_memory(parameter_typ* parsed_parameter);
void target_reply_step(parameter_typ* parsed_parameter);

#endif /* TARGET_TARGET_ACTIONS_H_ */
