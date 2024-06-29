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

#include "cli_usb.h"
#include "cfg/cli_cfg.h"
#include "tinyusb/src/device/usbd.h"
#include "tinyusb/src/class/cdc/cdc_device.h"
#include "probe_api/debug_log.h"
#ifdef FEAT_USB_NCM
#include "cfg/network_cfg.h"
#endif

static void print_bool(const bool val);

static void print_bool(const bool val)
{
    if(true == val)
    {
        debug_line("true");
    }
    else
    {
        debug_line("false");
    }
}

bool cmd_usb_info(const uint32_t loop)
{
    if(0 == loop)
    {
        debug_line("USB Status");
        debug_line("==========");
        debug_msg("connected       : ");
        print_bool(tud_connected());
        debug_msg("mounted         : ");
        print_bool(tud_mounted());
        debug_msg("suspended       : ");
        print_bool(tud_suspended());
        debug_msg("CDC connected   : ");
        print_bool(tud_cdc_connected());
        return false; // true == Done; false = call me again
    }
    else
    {
#ifdef FEAT_USB_NCM
        if(true == network_cfg_is_network_enabled())
        {
            debug_line("NCM (network)   : active");
            debug_msg("probe IP        : ");
            network_cfg_debug_print_ip_address(net_cfg.probe_ip.addr);
            debug_line(" ");
            debug_msg("probe net mask  : ");
            network_cfg_debug_print_ip_address(net_cfg.netmask.addr);
            debug_line(" ");
            debug_msg("DHCP IP         : ");
            network_cfg_debug_print_ip_address(net_cfg.host_pc_ip.addr);
            debug_line(" ");
            debug_msg("gateway IP      : ");
            network_cfg_debug_print_ip_address(net_cfg.gateway.addr);
            debug_line(" ");
            debug_line("gdb-server port : TCP:%d", net_cfg.gdb_port);
        }
        else
        {
            debug_line("NCM (network)   : not active");
        }
#endif
        return true; // true == Done; false = call me again
    }
}
