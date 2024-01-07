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
#ifndef SRC_CFG_TUSB_CONFIG_H_
#define SRC_CFG_TUSB_CONFIG_H_

#define CFG_TUSB_MCU              OPT_MCU_RP2040
#define CFG_TUSB_OS               OPT_OS_NONE

/* USB DMA on some MCUs can only access a specific SRAM region with restriction on alignment.
 * TinyUSB use following macros to declare transferring memory so that they can be put
 * into those specific section.
 * e.g
 * - CFG_TUSB_MEM SECTION : __attribute__ (( section(".usb_ram") ))
 * - CFG_TUSB_MEM_ALIGN   : __attribute__ ((aligned(4)))
 */

#ifndef CFG_TUSB_MEM_SECTION
#define CFG_TUSB_MEM_SECTION
#endif

#ifndef CFG_TUSB_MEM_ALIGN
#define CFG_TUSB_MEM_ALIGN    __attribute__ ((aligned(4)))
#endif

// Enable Device stack
#define CFG_TUD_ENABLED           1
#define CFG_TUSB_RHPORT0_MODE     OPT_MODE_DEVICE
#define CFG_TUD_CDC               1
#ifdef FEAT_USB_MSC
#define CFG_TUD_MSC               1
#endif

#define CFG_TUD_CDC_RX_BUFSIZE    64
#define CFG_TUD_CDC_TX_BUFSIZE    64
// CDC Endpoint transfer buffer size, more is faster
#define CFG_TUD_CDC_EP_BUFSIZE   (TUD_OPT_HIGH_SPEED ? 512 : 64)

// MSC Buffer size of Device Mass storage
#define CFG_TUD_MSC_EP_BUFSIZE   512

#ifndef TUD_OPT_RP2040_USB_DEVICE_UFRAME_FIX
#define TUD_OPT_RP2040_USB_DEVICE_UFRAME_FIX       1
#endif

#define CFG_TUD_TASK_QUEUE_SZ   32

#endif /* SRC_CFG_TUSB_CONFIG_H_ */
