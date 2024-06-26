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

#include "random.h"
#include "hw/ROSC.h"


uint32_t rosc_rand(void)
{
    uint32_t random = 0;
    for(int i = 0; i < 32; i++)
    {
        uint32_t random_bit = 0x1 & ROSC->RANDOMBIT;
        random = random << 1 | random_bit;
    }
    return random;
}
