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
#ifndef PROBE_API_SWD_H_
#define PROBE_API_SWD_H_

#include <stdint.h>
#include <stdbool.h>
#include "result.h"

bool swd_info(uint32_t which);
void swd_protocol_set_AP_sel(uint32_t val);
// SWD actions:
Result swd_connect(bool multi, uint32_t target);
bool swd_is_connected(void);
Result swd_scan(void);
Result swd_read_ap(uint32_t addr);
Result swd_get_result(uint32_t transaction, uint32_t* data);

#endif /* PROBE_API_SWD_H_ */
