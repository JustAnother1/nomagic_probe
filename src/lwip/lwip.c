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

/*
From lwip documentation: (https://www.nongnu.org/lwip/2_1_x/pitfalls.html)

Multiple Execution Contexts in lwIP code

The most common source of lwIP problems is to have multiple execution contexts inside the lwIP code.

lwIP can be used in two basic modes: Mainloop mode ("NO_SYS") (no OS/RTOS running on target system) or OS mode (TCPIP thread) (there is an OS running on the target system).

See also: Multithreading (especially the part about LWIP_ASSERT_CORE_LOCKED()!)
Mainloop Mode

In mainloop mode, only "raw" APIs can be used. The user has two possibilities to ensure there is only one exection context at a time in lwIP:

1) Deliver RX ethernet packets directly in interrupt context to lwIP by calling netif->input directly in interrupt. This implies all lwIP callback functions are called in IRQ context, which may cause further problems in application code: IRQ is blocked for a long time, multiple execution contexts in application code etc. When the application wants to call lwIP, it only needs to disable interrupts during the call. If timers are involved, even more locking code is needed to lock out timer IRQ and ethernet IRQ from each other, assuming these may be nested.

2) Run lwIP in a mainloop. There is example code here: Mainloop mode ("NO_SYS"). lwIP is ONLY called from mainloop callstacks here. The ethernet IRQ has to put received telegrams into a queue which is polled in the mainloop. Ensure lwIP is NEVER called from an interrupt, e.g. some SPI IRQ wants to forward data to udp_send() or tcp_write()!

 */

#include <stddef.h>
#include "lwip.h"
#include "cfg/network_cfg.h"
#include "hal/time_base.h"
#include "lwip/src/include/lwip/init.h"
#include "lwip/src/include/lwip/netif.h"
#include "lwip/src/include/lwip/timeouts.h"
#include "lwip/src/include/lwip/dhcp.h"
#include "lwip/src/include/lwip/err.h"

static struct netif ncm_netif;
static err_t netif_init_function(struct netif *netif);
static err_t netif_input_function(struct pbuf *p, struct netif *inp);


void network_stack_init(void)
{
    if(true == network_cfg_is_network_enabled())
    {
        lwip_init();

        netif_add(&ncm_netif, // struct netif *netif
                  &net_cfg.ip,
                  &net_cfg.netmask,
                  &net_cfg.gateway,
                  NULL, // void *state
                  netif_init_function, // netif_init_fn init
                  netif_input_function // netif_input_fn input
                  );
        ncm_netif.name[0] = 'e';
        ncm_netif.name[1] = '0';
        netif_set_default(&ncm_netif);
        netif_set_up(&ncm_netif);
        // TODO
    }
    // else no network
}

void network_stack_tick(void)
{
    // Cyclic lwIP timers check
    sys_check_timeouts();
    // TODO
}

u32_t sys_now(void)
{
    return time_get_ms();
}

/** Function prototype for netif init functions. Set up flags and output/linkoutput
 * callback functions in this function.
 *
 * @param netif The netif to initialize
 */
static err_t netif_init_function(struct netif *netif)
{
    // TODO
    return ERR_OK;
}

/** Function prototype for netif->input functions. This function is saved as 'input'
 * callback function in the netif struct. Call it when a packet has been received.
 *
 * @param p The received packet, copied into a pbuf
 * @param inp The netif which received the packet
 * @return ERR_OK if the packet was handled
 *         != ERR_OK is the packet was NOT handled, in this case, the caller has
 *                   to free the pbuf
 */
static err_t netif_input_function(struct pbuf *p, struct netif *inp)
{
    // TODO
    return ERR_OK;
}


