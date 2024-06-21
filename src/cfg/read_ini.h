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

#ifndef NOMAGIC_PROBE_SRC_CFG_READ_INI_H_
#define NOMAGIC_PROBE_SRC_CFG_READ_INI_H_

#include <stdbool.h>
#include <stdint.h>

#define MAX_SETTING_LENGTH   30
#define MAX_VALUE_LENGTH     30

// call back functions
typedef void (* configuration_setter)(char * setting, char * value);
typedef configuration_setter (* get_section_setter)(char * section);
typedef char * (* get_next_char)(void);

void read_ini_read(get_next_char stream, get_section_setter section_cb);
bool read_ini_bool(char * value);
uint32_t read_int_address(char * val);
uint32_t read_ipv4_address(char * val);

#endif /* NOMAGIC_PROBE_SRC_CFG_READ_INI_H_ */
