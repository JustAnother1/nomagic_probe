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

#include "target.h"

bool target_is_SWDv2(void)
{
    return false;
}

uint32_t target_get_SWD_core_id(uint32_t core_num)
{
    return 23 + core_num;
}

uint32_t target_get_SWD_APSel(uint32_t core_num)
{
    return 5 + core_num;
}

void target_send_file(char* filename, uint32_t offset, uint32_t len)
{
    (void) filename;
    (void) offset;
    (void) len;
}

bool target_command_halt_cpu(void)
{
    return true;
}

void target_re_init(void)
{

}
