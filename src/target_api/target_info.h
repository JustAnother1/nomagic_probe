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
#ifndef TARGET_TARGET_INFO_H_
#define TARGET_TARGET_INFO_H_

#include <stdint.h>

void target_info_init(void);
void target_send_file(char* filename, uint32_t offset, uint32_t len);


#endif /* TARGET_TARGET_INFO_H_ */
