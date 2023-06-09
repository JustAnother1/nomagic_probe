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

#define CFG_TUSB_MCU   OPT_MCU_RP2040

#define CFG_TUSB_OS    OPT_OS_NONE

// Enable Device stack
#define CFG_TUD_ENABLED       1

#define CFG_TUSB_RHPORT0_MODE     OPT_MODE_DEVICE

#define CFG_TUD_CDC    1
// #define CFG_TUD_MSC    1

#define CFG_TUD_CDC_RX_BUFSIZE   64
#define CFG_TUD_CDC_TX_BUFSIZE   64

#ifndef TUD_OPT_RP2040_USB_DEVICE_UFRAME_FIX
#define TUD_OPT_RP2040_USB_DEVICE_UFRAME_FIX 1
#endif

#endif /* SRC_CFG_TUSB_CONFIG_H_ */
