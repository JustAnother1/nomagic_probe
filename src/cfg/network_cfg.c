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
#include "lwip/src/include/lwip/ip_addr.h"

network_cfg_typ net_cfg;

// this is used by the code in tinyusb/src/class/net/net_driver.c, and tinyusb/usb_descriptors.c
// ideally speaking, this should be generated from the hardware's unique ID (if available) (RP2040 does not have a unique id)
// the first byte is 0x02 to indicate a link-local address
// tinyUSB suggested the name.
// this is the MAC address that the host pc uses.
// The code in lwip/lwip.c creates the probes MAC address by inverting the lowest bit in the last byte.
uint8_t tud_network_mac_address[6] = {0x02, 0x12, 0x34, 0x56, 0x78, 0x90};

static bool network_enabled;


void network_cfg_load(void)
{
    // TODO read this from a configuration file stored in the flash
    network_enabled = true;
    // 192 = 0xC0
    // 168 = 0xA8
    //  66 = 0x42

    net_cfg.probe_ip.addr =   0x0142A8C0; // 192.168.66.1
    net_cfg.host_pc_ip.addr = 0x0242A8C0; // 192.168.66.2
    net_cfg.netmask.addr =    0x00ffffff; // 255.255.255.0
    net_cfg.gateway.addr =    0x0142a8c0; // 192.168.66.1

    // net_cfg.ip.addr =      IPADDR4_INIT_BYTES(192, 168, 66,  1);
    // net_cfg.netmask.addr = IPADDR4_INIT_BYTES(255, 255, 255, 0);
    // net_cfg.gateway.addr = IPADDR4_INIT_BYTES(192, 168, 66,  1);
    net_cfg.gdb_port = 3333;
}

bool network_cfg_is_network_enabled(void)
{
    return network_enabled;
}
