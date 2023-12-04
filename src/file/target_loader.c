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


#include <stdbool.h>
#include <stdint.h>
#include <stddef.h>

#include "target_api/target_actions.h"

#include "swd/swd_protocol.h"

// TODO load from configuration
int32_t target_connect(void)
{
    return swd_connect(false, 0);
}

