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
 * The MIT License (MIT)
 *
 * Copyright (c) 2020 Peter Lawrence
 *
 * influenced by lrndis https://github.com/fetisov/lrndis
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 *
 */

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include "usb_ncm.h"
#include "tusb.h"
#include "cfg/network_cfg.h"

// shared between tud_network_recv_cb() and service_traffic()
// static struct pbuf *received_frame;



static void service_traffic(void);

/* this is used by this code, ./class/net/net_driver.c, and usb_descriptors.c */
/* ideally speaking, this should be generated from the hardware's unique ID (if available) */
/* it is suggested that the first byte is 0x02 to indicate a link-local address */
uint8_t tud_network_mac_address[6] = {0x02, 0x02, 0x84, 0x6A, 0x96, 0x00};

void usb_ncm_init(void)
{
    if(true == network_cfg_is_network_enabled())
    {
        // TODO
    }
}

void usb_ncm_tick(void)
{
    if(true == network_cfg_is_network_enabled())
    {
        service_traffic();
    }
}

void tud_network_init_cb(void)
{
    /*
  // if the network is re-initializing and we have a leftover packet, we must do a cleanup
  if (received_frame)
  {
    pbuf_free(received_frame);
    received_frame = NULL;
  }
  */
}

uint16_t tud_network_xmit_cb(uint8_t *dst, void *ref, uint16_t arg)
{
    (void) dst;
    (void) ref;
    (void) arg;
    /*
  struct pbuf *p = (struct pbuf *) ref;

  (void) arg; // unused for this example

  return pbuf_copy_partial(p, dst, p->tot_len, 0);
  */
    return 0;
}

bool tud_network_recv_cb(const uint8_t *src, uint16_t size)
{
    (void)src;
    (void)size;
    /*
      // this shouldn't happen, but if we get another packet before
      // parsing the previous, we must signal our inability to accept it
      if (received_frame) return false;

      if (size) {
        struct pbuf *p = pbuf_alloc(PBUF_RAW, size, PBUF_POOL);

        if (p) {
          // pbuf_alloc() has already initialized struct; all we need to do is copy the data
          memcpy(p->payload, src, size);

          // store away the pointer for service_traffic() to later handle
          received_frame = p;
        }
      }
    */
    return true;
}

static void service_traffic(void)
{
    /*
    // handle any packet received by tud_network_recv_cb()
  if (received_frame) {
    ethernet_input(received_frame, &netif_data);
    pbuf_free(received_frame);
    received_frame = NULL;
    tud_network_recv_renew();
  }

  sys_check_timeouts();
  */
}
