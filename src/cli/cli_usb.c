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
        cli_line("true");
    }
    else
    {
        cli_line("false");
    }
}

bool cmd_usb_info(const uint32_t loop)
{
    if(0 == loop)
    {
        cli_line("USB Status");
        cli_line("==========");
        cli_msg("connected       : ");
        print_bool(tud_connected());
        cli_msg("mounted         : ");
        print_bool(tud_mounted());
        cli_msg("suspended       : ");
        print_bool(tud_suspended());
        cli_msg("CDC connected   : ");
        print_bool(tud_cdc_connected());
        return false; // true == Done; false = call me again
    }
    else
    {
#ifdef FEAT_USB_NCM
        if(true == network_cfg_is_network_enabled())
        {
            cli_line("NCM (network)   : active");
            cli_msg("probe IP        : ");
            network_cfg_debug_print_ip_address(net_cfg.probe_ip.addr);
            cli_line(" ");
            cli_msg("probe net mask  : ");
            network_cfg_debug_print_ip_address(net_cfg.netmask.addr);
            cli_line(" ");
            cli_msg("DHCP IP         : ");
            network_cfg_debug_print_ip_address(net_cfg.host_pc_ip.addr);
            cli_line(" ");
            cli_msg("gateway IP      : ");
            network_cfg_debug_print_ip_address(net_cfg.gateway.addr);
            cli_line(" ");
            cli_line("gdb-server port : TCP:%d", net_cfg.gdb_port);
        }
        else
        {
            cli_line("NCM (network)   : not active");
        }
#endif
        return true; // true == Done; false = call me again
    }
}
