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
#ifndef SRC_SWD_SWD_PROTOCOL_H_
#define SRC_SWD_SWD_PROTOCOL_H_

#include <stdint.h>
#include <stdbool.h>

#define RES_OK  0

void swd_init(void);
void swd_tick(void);
bool swd_is_connected(void);
bool swd_info(uint32_t which);
int32_t swd_connect(bool multi, uint32_t target);
void swd_disconnect(void);
int32_t swd_get_Memory_APsel(void);
int32_t read_ap(int32_t ap_sel, uint32_t addr, uint32_t* data);

#endif /* SRC_SWD_SWD_PROTOCOL_H_ */
