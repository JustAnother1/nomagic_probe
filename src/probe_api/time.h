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
#ifndef PROBE_API_TIME_H_
#define PROBE_API_TIME_H_

#include <stdint.h>
#include<stdbool.h>

typedef struct{
    uint32_t timeout_time;
    bool wait_for_wrap_around;
} timeout_typ;

uint32_t time_get_ms(void);

void start_timeout(timeout_typ* to, const uint32_t time_ms);
bool timeout_expired(timeout_typ* to);


#endif /* PROBE_API_TIME_H_ */
