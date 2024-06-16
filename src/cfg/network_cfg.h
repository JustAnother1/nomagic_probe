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

#ifndef NOMAGIC_PROBE_SRC_CFG_NETWORK_CFG_H_
#define NOMAGIC_PROBE_SRC_CFG_NETWORK_CFG_H_

#include <stdbool.h>
#include "lwip/src/include/lwip/ip4_addr.h"

typedef struct {
    ip4_addr_t probe_ip;
    ip4_addr_t host_pc_ip;
    ip4_addr_t netmask;
    ip4_addr_t gateway;
    uint16_t   gdb_port;
} network_cfg_typ;

extern network_cfg_typ net_cfg;

extern uint8_t tud_network_mac_address[6];


void network_cfg_load(void);
bool network_cfg_is_network_enabled(void);

#endif /* NOMAGIC_PROBE_SRC_CFG_NETWORK_CFG_H_ */
