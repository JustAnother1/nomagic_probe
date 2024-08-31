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

#include <string.h>
#include "swd_cfg.h"
#include "read_ini.h"

swd_cfg_typ swd_cfg;

void swd_cfg_reset_to_default(void)
{
	swd_cfg.break_on_hard_fault = true;
}

void swd_cfg_set(char * setting, char * value)
{
    // debug_line("swd cfg: %s = %s !", setting, value);

    if(0 == strncmp(setting, BREAK_ON_HARD_FAULT_SETTING, sizeof(BREAK_ON_HARD_FAULT_SETTING)))
    {
    	swd_cfg.break_on_hard_fault = read_ini_bool(value);
    }

}

void swd_cfg_apply(void)
{

}
