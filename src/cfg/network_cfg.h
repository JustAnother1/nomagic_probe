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

#define NCM_ENABLED_SETTING           "ncm"
#define PROBE_IP_SETTING              "probe_ip"
#define HOST_IP_SETTING               "host_ip"
#define NETMASK_SETTING               "net_mask"
#define GATEWAY_IP_SETTING            "gateway_ip"
#define GDB_TCP_PORT_SETTING          "gdb_tcp_port"
#define TARGET_UART_TCP_PORT_SETTING  "target_uart_port"

typedef struct {
    ip4_addr_t probe_ip;
    ip4_addr_t host_pc_ip;
    ip4_addr_t netmask;
    ip4_addr_t gateway;
    uint16_t   gdb_port;
    uint16_t   target_uart_port;
} network_cfg_typ;

extern network_cfg_typ net_cfg;

extern uint8_t tud_network_mac_address[6];


// load configuration
void network_cfg_reset_to_default(void);
void network_cfg_set(char * setting, char * value);
void network_cfg_apply(void);
bool network_cfg_is_network_enabled(void);
#ifdef FEAT_CLI
void network_cfg_debug_print_ip_address(uint32_t addr);
#endif

#endif /* NOMAGIC_PROBE_SRC_CFG_NETWORK_CFG_H_ */
