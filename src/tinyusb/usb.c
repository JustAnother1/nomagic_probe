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
#include "usb.h"
#include "hal/hw/RESETS.h"
#include <hal/hw/IO_BANK0.h>
#include "hal/hw/PLL_USB.h"
#include "hal/hw/CLOCKS.h"
#include "hal/startup.h"
// tinyusb:
#include "tusb.h"
#include "device/usbd.h"


void usb_init(void)
{
    RESETS->RESET = RESETS->RESET & ~0x1001000ul; // take USB_CTRL, PLL_USB out of Reset
    while (0 == ((1 << 24) & RESETS->RESET_DONE)) {
        ;
    }
    // configure GPIO Pins
    IO_BANK0->GPIO24_CTRL = 0; // VBUS Detect is not on that pin as a function :-(

    // USB Clock
    // configure USB PLL
    // program the clk_ref divider ( 1)
    PLL_USB->CS = 0x1;
    // program feedback divider ( 48)
    PLL_USB->FBDIV_INT = 0x30;
    // turn on main power and VCO
    PLL_USB->PWR = 0x0;
    // wait for VCO clock to lock
    while (0 == (0x80000000 & PLL_USB->CS)) {
        ;
    }
    // set up post dividers and turn them on (6, 2)
    PLL_USB->PRIM = 0x62000;
    // switch sys aux to PLL
    CLOCKS->CLK_USB_CTRL = 0;



    NVIC_EnableIRQ(USBCTRL_IRQ_NUMBER, USBCTRL_IRQ_PRIORITY);
    tusb_init(); // initialize tinyusb stack
}

// USB "Task"
void usb_tick(void)
{
    tud_task(); // device task
}

// USB interrupt
void USBCTRL_IRQ(void)
{
    tud_int_handler(0);
}

void dcd_int_handler(uint8_t rhport)
{
    // TODO
}

// Stall endpoint, any queuing transfer should be removed from endpoint
void dcd_edpt_stall(uint8_t rhport, uint8_t ep_addr)
{
    // TODO
}

// Receive Set Address request, mcu port must also include status IN response
void dcd_set_address(uint8_t rhport, uint8_t dev_addr)
{
    // TODO
}

// Invoked when received GET STRING DESCRIPTOR request
// Application return pointer to descriptor, whose contents must exist long enough for transfer to complete
uint16_t const* tud_descriptor_string_cb(uint8_t index, uint16_t langid)
{
    // TODO
    return 0;
}

// clear stall, data toggle is also reset to DATA0
// This API never calls with control endpoints, since it is auto cleared when receiving setup packet
void dcd_edpt_clear_stall     (uint8_t rhport, uint8_t ep_addr)
{
    // TODO
}

// Invoked when received GET CONFIGURATION DESCRIPTOR request
// Application return pointer to descriptor, whose contents must exist long enough for transfer to complete
uint8_t const * tud_descriptor_configuration_cb(uint8_t index)
{
    // TODO
    return NULL;
}

// Close all non-control endpoints, cancel all pending transfers if any.
// Invoked when switching from a non-zero Configuration by SET_CONFIGURE therefore
// required for multiple configuration support.
void dcd_edpt_close_all(uint8_t rhport)
{
    // TODO
}

// Configure endpoint's registers according to descriptor
bool dcd_edpt_open(uint8_t rhport, tusb_desc_endpoint_t const * desc_ep)
{
    // TODO
    return true;
}

// Submit a transfer, When complete dcd_event_xfer_complete() is invoked to notify the stack
bool dcd_edpt_xfer            (uint8_t rhport, uint8_t ep_addr, uint8_t * buffer, uint16_t total_bytes)
{
    // TODO
    return true;
}

// Invoked when received GET DEVICE DESCRIPTOR request
// Application return pointer to descriptor
uint8_t const * tud_descriptor_device_cb(void)
{
    // TODO
    return NULL;
}

