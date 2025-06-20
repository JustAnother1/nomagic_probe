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
#ifndef COMMANDS_H_
#define COMMANDS_H_

#include <stdint.h>
#include <stdbool.h>

typedef struct {
    bool extended_mode;
    bool noAckMode;
} config_typ;

extern config_typ gdb_cfg;

void commands_init(void);
void commands_execute(char* received, uint32_t length);

#endif /* COMMANDS_H_ */
