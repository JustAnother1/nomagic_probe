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

void target_monitor_command(uint32_t which, char* command)
{
    (void) which;
    (void) command;
}

void mon_cmd_help(char* command)
{
    (void) command;
}

void mon_cmd_version(void)
{

}

void mon_cmd_halt(char* command)
{
    (void) command;
}

void mon_cmd_reset(char* command)
{
    (void) command;
}

void mon_cmd_reg(char* command)
{
    (void) command;
}
