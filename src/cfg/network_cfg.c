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
#include "network_cfg.h"

static bool network_enabled;
network_cfg_typ net_cfg;

void network_cfg_load(void)
{
    // TODO read this from a configuration file stored in the flash
    network_enabled = true;
    // 192 = 0xC0
    // 168 = 0xA8
    // 66 = 0x42
    net_cfg.ip.addr =      0xC0A84201; // 192.168.66.1
    net_cfg.netmask.addr = 0xffffff00; // 255.255.255.0
    net_cfg.gateway.addr = 0xC0A84201; // 192.168.66.1
}

bool network_cfg_is_network_enabled(void)
{
    return network_enabled;
}
