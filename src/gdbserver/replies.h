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

#define MAX_MEMORY_POSITIONS   20

typedef struct {
    uint32_t value;
    bool has_value;
    uint8_t padding[3];
} mem_val_typ;

typedef struct {
    uint32_t address;
    uint32_t length;
    uint32_t num_memory_locations;
    mem_val_typ memory[MAX_MEMORY_POSITIONS];
    bool has_address;
    uint8_t padding[3];
} parameter_typ;


void target_reply_g(void);
void target_reply_questionmark(void);
void target_reply_write_g(parameter_typ* parsed_parameter);
void target_reply_continue(parameter_typ* parsed_parameter);
void target_reply_read_memory(parameter_typ* parsed_parameter);
void target_reply_write_memory(parameter_typ* parsed_parameter);
void target_reply_step(parameter_typ* parsed_parameter);



#endif /* GDBSERVER_REPLIES_H_ */
