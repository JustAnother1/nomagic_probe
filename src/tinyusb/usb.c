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
 * Copyright (c) 2019 Ha Thach (tinyusb.org)
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
#include "usb.h"
#include "hal/hw/CLOCKS.h"
#include "hal/hw/IO_BANK0.h"
#include "hal/hw/PLL_USB.h"
#include "hal/hw/RESETS.h"
#include "hal/hw/USBCTRL_REGS.h"
#include "hal/hw/USBCTRL_DPRAM.h"
#include "hal/startup.h"
#include "time_base.h"

#include "usb_cdc.h"

// tinyusb:
#include "tusb.h"
#include "common/tusb_types.h"
#include "device/dcd.h"
#include "device/usbd.h"


#define FORCE_VBUS_DETECT             1
// 0-15
#define USB_NUM_ENDPOINTS             16
// 1-15
#define USB_HOST_INTERRUPT_ENDPOINTS  (USB_NUM_ENDPOINTS - 1)

#define USB_DPRAM_SIZE                4096u

// Define maximum packet sizes
#define USB_MAX_ISO_PACKET_SIZE       1023
#define USB_MAX_PACKET_SIZE           64

#define usb_dpram ((usb_device_dpram_t *)USBCTRL_DPRAM)

#define EP_CTRL_ENABLE_BITS                        (1u << 31u)
#define EP_CTRL_DOUBLE_BUFFERED_BITS               (1u << 30)
#define EP_CTRL_INTERRUPT_PER_BUFFER               (1u << 29)
#define EP_CTRL_INTERRUPT_PER_DOUBLE_BUFFER        (1u << 28)
#define EP_CTRL_INTERRUPT_ON_NAK                   (1u << 16)
#define EP_CTRL_INTERRUPT_ON_STALL                 (1u << 17)
#define EP_CTRL_BUFFER_TYPE_LSB                    26u
#define EP_CTRL_HOST_INTERRUPT_INTERVAL_LSB        16u

#define USB_BUF_CTRL_FULL                          0x00008000u
#define USB_BUF_CTRL_LAST                          0x00004000u
#define USB_BUF_CTRL_DATA0_PID                     0x00000000u
#define USB_BUF_CTRL_DATA1_PID                     0x00002000u
#define USB_BUF_CTRL_SEL                           0x00001000u
#define USB_BUF_CTRL_STALL                         0x00000800u
#define USB_BUF_CTRL_AVAIL                         0x00000400u
#define USB_BUF_CTRL_LEN_MASK                      0x000003FFu
#define USB_MAIN_CTRL_HOST_NDEVICE_BITS            0x00000002u
#define USB_MAIN_CTRL_CONTROLLER_EN_BITS           0x00000001u
#define USB_EP_STALL_ARM_EP0_OUT_BITS              0x00000002u
#define USB_EP_STALL_ARM_EP0_IN_BITS               0x00000001u
#define USB_INTS_DEV_SOF_BITS                      0x00020000u
#define USB_INTS_BUFF_STATUS_BITS                  0x00000010u
#define USB_INTS_SETUP_REQ_BITS                    0x00010000u
#define USB_INTS_DEV_CONN_DIS_BITS                 0x00002000u
#define USB_INTS_BUS_RESET_BITS                    0x00001000u
#define USB_INTS_DEV_SUSPEND_BITS                  0x00004000u
#define USB_INTS_DEV_RESUME_FROM_HOST_BITS         0x00008000u
#define USB_INTF_DEV_SOF_BITS                      0x00020000u
#define USB_USB_PWR_VBUS_DETECT_BITS               0x00000004u
#define USB_USB_PWR_VBUS_DETECT_OVERRIDE_EN_BITS   0x00000008u
#define USB_SOF_RD_BITS                            0x000007ffu
#define USB_SIE_CTRL_EP0_INT_1BUF_BITS             0x20000000u
#define USB_SIE_CTRL_RESUME_BITS                   0x00001000u
#define USB_SIE_CTRL_PULLUP_EN_BITS                0x00010000u
#define USB_SIE_STATUS_SETUP_REC_BITS              0x00020000u
#define USB_SIE_STATUS_CONNECTED_BITS              0x00010000u
#define USB_SIE_STATUS_SUSPENDED_BITS              0x00000010u
#define USB_SIE_STATUS_BUS_RESET_BITS              0x00080000u
#define USB_SIE_STATUS_RESUME_BITS                 0x00000800u

#define REG_ALIAS_RW_BITS  (0x0u << 12u)
#define REG_ALIAS_XOR_BITS (0x1u << 12u)
#define REG_ALIAS_SET_BITS (0x2u << 12u)
#define REG_ALIAS_CLR_BITS (0x3u << 12u)

#define USBCTRL_REGS_SET ((USBCTRL_REGS_type *) (0x50110000 | REG_ALIAS_SET_BITS))
#define USBCTRL_REGS_CLR ((USBCTRL_REGS_type *) (0x50110000 | REG_ALIAS_CLR_BITS))


typedef struct {
    // 4K of DPSRAM at beginning. Note this supports 8, 16, and 32 bit accesses
    volatile uint8_t setup_packet[8]; //! First 8 bytes are always for setup packets

    //! Starts at ep1
    struct usb_device_dpram_ep_ctrl {
        volatile uint32_t in;
        volatile uint32_t out;
    } ep_ctrl[USB_NUM_ENDPOINTS - 1];

    //! Starts at ep0
    struct usb_device_dpram_ep_buf_ctrl {
        volatile uint32_t in;
        volatile uint32_t out;
    } ep_buf_ctrl[USB_NUM_ENDPOINTS];

    //! EP0 buffers are fixed. Assumes single buffered mode for EP0
    uint8_t ep0_buf_a[0x40];
    uint8_t ep0_buf_b[0x40];

    //! Rest of DPRAM can be carved up as needed
    uint8_t epx_data[USB_DPRAM_SIZE - 0x180];
} usb_device_dpram_t;

typedef struct {
    // 4K of DPSRAM at beginning. Note this supports 8, 16, and 32 bit accesses
    volatile uint8_t setup_packet[8]; //! First 8 bytes are always for setup packets

    //! Interrupt endpoint control 1 -> 15
    struct usb_host_dpram_ep_ctrl {
        volatile uint32_t ctrl;
        volatile uint32_t spare;
    } int_ep_ctrl[USB_HOST_INTERRUPT_ENDPOINTS];

    volatile uint32_t epx_buf_ctrl;
    volatile uint32_t _spare0;

    //! Interrupt endpoint buffer control
    struct usb_host_dpram_ep_buf_ctrl {
        volatile uint32_t ctrl;
        volatile uint32_t spare;
    } int_ep_buffer_ctrl[USB_HOST_INTERRUPT_ENDPOINTS];

    volatile uint32_t epx_ctrl;

    uint8_t _spare1[124];

    //! Should start at 0x180
    uint8_t epx_data[USB_DPRAM_SIZE - 0x180];
} usb_host_dpram_t;

//! Hardware information per endpoint
typedef struct
{
    //! Is this a valid struct
    bool configured;

    //! Transfer direction (i.e. IN is rx for host but tx for device)
    //! allows us to common up transfer functions
    bool rx;

    uint8_t ep_addr;
    uint8_t next_pid;

    //! Endpoint control register
    volatile uint32_t *endpoint_control;

    //! Buffer control register
    volatile uint32_t *buffer_control;

    //! Buffer pointer in usb dpram
    uint8_t *hw_data_buf;

    //! User buffer in main memory
    uint8_t *user_buf;

    //! Current transfer information
    uint16_t remaining_len;
    uint16_t xferred_len;

    //! Data needed from EP descriptor
    uint16_t wMaxPacketSize;

    //! Endpoint is in use
    bool active;

    //! Interrupt, bulk, etc
    uint8_t transfer_type;

    //! Transfer scheduled but not active
    uint8_t pending;

#if CFG_TUH_ENABLED
    //! Only needed for host
    uint8_t dev_addr;

    //! If interrupt endpoint
    uint8_t interrupt_num;
#endif

} hw_endpoint_t;


//! SOF may be used by remote wakeup as RESUME, this indicate whether SOF is actually used by usbd
static bool _sof_enable = false;
//! Direction strings for debug
const char *ep_dir_string[] = {
        "out",
        "in",
};

//! USB_NUM_ENDPOINTS Endpoints, direction TUSB_DIR_OUT for out and TUSB_DIR_IN for in.
static hw_endpoint_t hw_endpoints[USB_NUM_ENDPOINTS][2];

//! Init these in dcd_init
static uint8_t *next_buffer_ptr;


#if TUD_OPT_RP2040_USB_DEVICE_UFRAME_FIX
  static bool e15_is_bulkin_ep(hw_endpoint_t *ep);
  static bool e15_is_critical_frame_period(hw_endpoint_t *ep);
#else
  #define e15_is_bulkin_ep(x)             (false)
  #define e15_is_critical_frame_period(x) (false)
#endif
static void hw_endpoint_xfer(uint8_t ep_addr, uint8_t* buffer, uint16_t total_bytes);
static void hw_endpoint_xfer_start(hw_endpoint_t* ep, uint8_t* buffer, uint16_t total_len);
static void hw_endpoint_start_next_buffer(hw_endpoint_t* ep);
static hw_endpoint_t* hw_endpoint_get_by_addr(uint8_t ep_addr);
TU_ATTR_ALWAYS_INLINE static inline hw_endpoint_t* hw_endpoint_get_by_num(uint8_t num, tusb_dir_t dir);
TU_ATTR_ALWAYS_INLINE static inline void _hw_endpoint_buffer_control_set_value32 (hw_endpoint_t* ep, uint32_t value);
static void _hw_endpoint_buffer_control_update32(hw_endpoint_t* ep, uint32_t and_mask, uint32_t or_mask);
static void reset_non_control_endpoints(void);
static void hw_endpoint_init(uint8_t ep_addr, uint16_t wMaxPacketSize, uint8_t transfer_type);
static void _hw_endpoint_alloc(hw_endpoint_t* ep, uint8_t transfer_type);
static void dcd_rp2040_irq(void);
static void hw_endpoint_reset_transfer(hw_endpoint_t* ep);
static uint32_t prepare_ep_buffer(hw_endpoint_t* ep, uint8_t buf_id);
TU_ATTR_ALWAYS_INLINE static inline void _hw_endpoint_buffer_control_clear_mask32 (hw_endpoint_t* ep, uint32_t value);
static void usb_init(void);

//! initialize the USB peripheral
static void usb_init(void)
{
    RESETS->RESET = RESETS->RESET & ~0x1002000ul; // take USB_CTRL, PLL_USB out of Reset
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
    CLOCKS->CLK_USB_CTRL = 0x800;
    CLOCKS->CLK_USB_DIV = 0x100; // divisor = 1

    while (0 == ((1 << 24) & RESETS->RESET_DONE)) {
        ;
    }

    memset(USBCTRL_REGS, 0, sizeof(USBCTRL_REGS_type));
    memset(usb_dpram, 0, sizeof(*usb_dpram));
    USBCTRL_REGS->USBPHY_TRIM = 0x1F1F;  // restore default
    // Mux the controller to the onboard usb phy
    USBCTRL_REGS->USB_MUXING = 0x9;
    // Tell device that it is already plugged into the host (as we do not have VBus detection)
    // USBCTRL_REGS->USB_PWR = 0xc; - also done in dcd_init
    // enable USB device mode
    USBCTRL_REGS->MAIN_CTRL = 1;
    // enable Interrupt for EP0
    USBCTRL_REGS->SIE_CTRL = 0x20000000;
    // enable interrupts on buffer done(4), bus reset(12), setup paket received(16)
    USBCTRL_REGS->INTE = 0x11010;
    // activate full speed device mode
    USBCTRL_REGS->SIE_CTRL = 0x20010000;

    NVIC_EnableIRQ(USBCTRL_IRQ_NUMBER, USBCTRL_IRQ_PRIORITY);
}

//! USB "Task"
void usb_tick(void)
{
    tud_task(); // device task
}

//! USB interrupt
void USBCTRL_IRQ(void)
{
    tud_int_handler(0);
}

//! interrupt handler
void dcd_int_handler(uint8_t rhport)
{
    (void) rhport;
    dcd_rp2040_irq();
}

//! enable interrupt
void dcd_int_enable(uint8_t rhport)
{
    (void) rhport;
    // NVIC_EnableIRQ(USBCTRL_IRQ_NUMBER, USBCTRL_IRQ_PRIORITY);   TODO
}

//! disable interrupt
void dcd_int_disable(uint8_t rhport)
{
    (void) rhport;
    // NVIC_DisableIRQ(USBCTRL_IRQ_NUMBER);   TODO
}

//! Stall endpoint, any queuing transfer should be removed from endpoint
void dcd_edpt_stall(uint8_t rhport, uint8_t ep_addr)
{
    (void) rhport;
    if ( tu_edpt_number(ep_addr) == 0 )
    {
        // A stall on EP0 has to be armed so it can be cleared on the next setup packet
        USBCTRL_REGS_SET->EP_STALL_ARM = (tu_edpt_dir(ep_addr) == TUSB_DIR_IN) ? USB_EP_STALL_ARM_EP0_IN_BITS : USB_EP_STALL_ARM_EP0_OUT_BITS;
    }

    hw_endpoint_t* ep = hw_endpoint_get_by_addr(ep_addr);

    // stall and clear current pending buffer
    // may need to use EP_ABORT
    _hw_endpoint_buffer_control_set_value32(ep, USB_BUF_CTRL_STALL);
}

//! Receive Set Address request, mcu port must also include status IN response
void dcd_set_address(uint8_t rhport, uint8_t dev_addr)
{
    (void) rhport;
    (void) dev_addr;
    // Can't set device address in hardware until status xfer has complete
    // Send 0len complete response on EP0 IN
    hw_endpoint_xfer(0x80, NULL, 0);
}

//! clear stall, data toggle is also reset to DATA0
//! This API never calls with control endpoints, since it is auto cleared when receiving setup packet
void dcd_edpt_clear_stall(uint8_t rhport, uint8_t ep_addr)
{
    (void) rhport;
    if (tu_edpt_number(ep_addr))
    {
        hw_endpoint_t* ep = hw_endpoint_get_by_addr(ep_addr);

        // clear stall also reset toggle to DATA0, ready for next transfer
        ep->next_pid = 0;
        _hw_endpoint_buffer_control_clear_mask32(ep, USB_BUF_CTRL_STALL);
    }
}

//! Close all non-control endpoints, cancel all pending transfers if any.
//! Invoked when switching from a non-zero Configuration by SET_CONFIGURE therefore
//! required for multiple configuration support.
void dcd_edpt_close_all(uint8_t rhport)
{
    (void) rhport;
    // may need to use EP Abort
    reset_non_control_endpoints();
}

//! Configure endpoint's registers according to descriptor
bool dcd_edpt_open(uint8_t rhport, tusb_desc_endpoint_t const* desc_edpt)
{
    (void) rhport;
    hw_endpoint_init(desc_edpt->bEndpointAddress, tu_edpt_packet_size(desc_edpt), desc_edpt->bmAttributes.xfer);
    return true;
}

//! Submit a transfer, When complete dcd_event_xfer_complete() is invoked to notify the stack
bool dcd_edpt_xfer(uint8_t rhport, uint8_t ep_addr, uint8_t* buffer, uint16_t total_bytes)
{
    (void) rhport;
    hw_endpoint_xfer(ep_addr, buffer, total_bytes);
    return true;
}

static void hw_endpoint_xfer(uint8_t ep_addr, uint8_t* buffer, uint16_t total_bytes)
{
    hw_endpoint_t* ep = hw_endpoint_get_by_addr(ep_addr);
    hw_endpoint_xfer_start(ep, buffer, total_bytes);
}

static void hw_endpoint_xfer_start(hw_endpoint_t* ep, uint8_t* buffer, uint16_t total_len)
{
    if ( ep->active )
    {
        // TODO: Is this acceptable for interrupt packets?
        TU_LOG(1, "WARN: starting new transfer on already active ep %d %s\r\n", tu_edpt_number(ep->ep_addr),
                   ep_dir_string[tu_edpt_dir(ep->ep_addr)]);

        hw_endpoint_reset_transfer(ep);
    }

    // Fill in info now that we're kicking off the hw
    ep->remaining_len = total_len;
    ep->xferred_len   = 0;
    ep->active        = true;
    ep->user_buf      = buffer;

    if ( e15_is_bulkin_ep(ep) )
    {
        USBCTRL_REGS_SET->INTE = USB_INTS_DEV_SOF_BITS;
    }

    if ( e15_is_critical_frame_period(ep) )
    {
        ep->pending = 1;
    }
    else
    {
        hw_endpoint_start_next_buffer(ep);
    }
}

//! if usb hardware is in host mode
TU_ATTR_ALWAYS_INLINE static inline bool is_host_mode(void)
{
    return (USBCTRL_REGS->MAIN_CTRL & USB_MAIN_CTRL_HOST_NDEVICE_BITS) ? true : false;
}


//! Prepare buffer control register value
static void hw_endpoint_start_next_buffer(hw_endpoint_t* ep)
{
    uint32_t ep_ctrl = *ep->endpoint_control;

    // always compute and start with buffer 0
    uint32_t buf_ctrl = prepare_ep_buffer(ep, 0) | USB_BUF_CTRL_SEL;

    // For now: skip double buffered for OUT endpoint in Device mode, since
    // host could send < 64 bytes and cause short packet on buffer0
    // NOTE: this could happen to Host mode IN endpoint
    // Also, Host mode "interrupt" endpoint hardware is only single buffered,
    // NOTE2: Currently Host bulk is implemented using "interrupt" endpoint
    bool const is_host = is_host_mode();
    bool const force_single = (!is_host && !tu_edpt_dir(ep->ep_addr)) ||
                        (is_host && tu_edpt_number(ep->ep_addr) != 0);

    if(ep->remaining_len && !force_single)
    {
        // Use buffer 1 (double buffered) if there is still data
        // TODO: Isochronous for buffer1 bit-field is different than CBI (control bulk, interrupt)

        buf_ctrl |= prepare_ep_buffer(ep, 1);

        // Set endpoint control double buffered bit if needed
        ep_ctrl &= ~EP_CTRL_INTERRUPT_PER_BUFFER;
        ep_ctrl |= EP_CTRL_DOUBLE_BUFFERED_BITS | EP_CTRL_INTERRUPT_PER_DOUBLE_BUFFER;
    }
    else
    {
        // Single buffered since 1 is enough
        ep_ctrl &= ~(EP_CTRL_DOUBLE_BUFFERED_BITS | EP_CTRL_INTERRUPT_PER_DOUBLE_BUFFER);
        ep_ctrl |= EP_CTRL_INTERRUPT_PER_BUFFER;
    }

    *ep->endpoint_control = ep_ctrl;

    TU_LOG(3, "  Prepare BufCtrl: [0] = 0x%04x  [1] = 0x%04x\r\n", tu_u32_low16(buf_ctrl), tu_u32_high16(buf_ctrl));

    // Finally, write to buffer_control which will trigger the transfer
    // the next time the controller polls this dpram address
    _hw_endpoint_buffer_control_set_value32(ep, buf_ctrl);
}

static hw_endpoint_t* hw_endpoint_get_by_addr(uint8_t ep_addr)
{
    uint8_t num = tu_edpt_number(ep_addr);
    tusb_dir_t dir = tu_edpt_dir(ep_addr);
    return hw_endpoint_get_by_num(num, dir);
}

TU_ATTR_ALWAYS_INLINE static inline hw_endpoint_t* hw_endpoint_get_by_num(uint8_t num, tusb_dir_t dir)
{
    return &hw_endpoints[num][dir];
}

TU_ATTR_ALWAYS_INLINE static inline void _hw_endpoint_buffer_control_set_value32 (hw_endpoint_t* ep, uint32_t value)
{
    _hw_endpoint_buffer_control_update32(ep, 0, value);
}

static void _hw_endpoint_buffer_control_update32(hw_endpoint_t* ep, uint32_t and_mask, uint32_t or_mask)
{
    uint32_t value = 0;

    if(0 !=  and_mask )
    {
        value = *ep->buffer_control & and_mask;
    }

    if(0 != or_mask )
    {
        value |= or_mask;
        if( or_mask & USB_BUF_CTRL_AVAIL )
        {
            if( *ep->buffer_control & USB_BUF_CTRL_AVAIL )
            {
                TU_LOG(1, "ep %d %s was already available\r\n", tu_edpt_number(ep->ep_addr), ep_dir_string[tu_edpt_dir(ep->ep_addr)]);
            }
            *ep->buffer_control = value & ~USB_BUF_CTRL_AVAIL;
            // 12 cycle delay.. (should be good for 48*12Mhz = 576Mhz)
            // Don't need delay in host mode as host is in charge
            #if !CFG_TUH_ENABLED
                __asm__ __volatile__ (
                        "b 1f\n"
                        "1: b 1f\n"
                        "1: b 1f\n"
                        "1: b 1f\n"
                        "1: b 1f\n"
                        "1: b 1f\n"
                        "1:\n"
                        : : : "memory");
            #endif
        }
    }

    *ep->buffer_control = value;
}

static void reset_non_control_endpoints(void)
{
    // Disable all non-control
    for(uint8_t i = 0; i < USB_NUM_ENDPOINTS-1; i++ )
    {
        usb_dpram->ep_ctrl[i].in = 0;
        usb_dpram->ep_ctrl[i].out = 0;
    }

    // clear non-control hw endpoints
    tu_memclr(hw_endpoints[1], sizeof(hw_endpoints) - 2*sizeof(hw_endpoint_t));

    // reclaim buffer space
    next_buffer_ptr = &usb_dpram->epx_data[0];
}

static void hw_endpoint_init(uint8_t ep_addr, uint16_t wMaxPacketSize, uint8_t transfer_type)
{
    hw_endpoint_t* ep = hw_endpoint_get_by_addr(ep_addr);

    const uint8_t num = tu_edpt_number(ep_addr);
    const tusb_dir_t dir = tu_edpt_dir(ep_addr);

    ep->ep_addr = ep_addr;

    // For device, IN is a tx transfer and OUT is an rx transfer
    ep->rx = (dir == TUSB_DIR_OUT);

    ep->next_pid = 0u;
    ep->wMaxPacketSize = wMaxPacketSize;
    ep->transfer_type = transfer_type;

    // Every endpoint has a buffer control register in dpram
    if ( dir == TUSB_DIR_IN )
    {
        ep->buffer_control = &usb_dpram->ep_buf_ctrl[num].in;
    }
    else
    {
        ep->buffer_control = &usb_dpram->ep_buf_ctrl[num].out;
    }

    // Clear existing buffer control state
    *ep->buffer_control = 0;

    if ( num == 0 )
    {
        // EP0 has no endpoint control register because the buffer offsets are fixed
        ep->endpoint_control = NULL;

        // Buffer offset is fixed (also double buffered)
        ep->hw_data_buf = (uint8_t*) &usb_dpram->ep0_buf_a[0];
    }
    else
    {
        // Set the endpoint control register (starts at EP1, hence num-1)
        if ( dir == TUSB_DIR_IN )
        {
            ep->endpoint_control = &usb_dpram->ep_ctrl[num - 1].in;
        }
        else
        {
            ep->endpoint_control = &usb_dpram->ep_ctrl[num - 1].out;
        }

        // alloc a buffer and fill in endpoint control register
        _hw_endpoint_alloc(ep, transfer_type);
    }
}

static inline uintptr_t hw_data_offset (uint8_t *buf)
{
    // Remove usb base from buffer pointer
    return (uintptr_t) buf ^ (uintptr_t) usb_dpram;
}

static void _hw_endpoint_alloc(hw_endpoint_t* ep, uint8_t transfer_type)
{
    // size must be multiple of 64
    uint32_t size = tu_div_ceil(ep->wMaxPacketSize, 64) * 64u;

    // double buffered Bulk endpoint
    if( transfer_type == TUSB_XFER_BULK )
    {
        size *= 2u;
    }

    ep->hw_data_buf = next_buffer_ptr;
    next_buffer_ptr += size;

    // assert(((uintptr_t )next_buffer_ptr & 0b111111u) == 0);
    uint32_t dpram_offset = hw_data_offset(ep->hw_data_buf);
    // hard_assert(hw_data_offset(next_buffer_ptr) <= USB_DPRAM_SIZE);

    TU_LOG(2, "  Allocated %ld bytes at offset 0x%lx (0x%p)\r\n", size, dpram_offset, ep->hw_data_buf);

    // Fill in endpoint control register with buffer offset
    uint32_t const reg = EP_CTRL_ENABLE_BITS | ((uint32_t)transfer_type << EP_CTRL_BUFFER_TYPE_LSB) | dpram_offset;

    *ep->endpoint_control = reg;
}

TU_ATTR_ALWAYS_INLINE static inline void reset_ep0_pid(void)
{
    // If we have finished this transfer on EP0 set pid back to 1 for next
    // setup transfer. Also clear a stall in case
    uint8_t addrs[] = {0x0, 0x80};
    for (uint32_t i = 0 ; i < TU_ARRAY_SIZE(addrs); i++)
    {
        hw_endpoint_t *ep = hw_endpoint_get_by_addr(addrs[i]);
        ep->next_pid = 1u;
    }
}

TU_ATTR_ALWAYS_INLINE static inline uint32_t _hw_endpoint_buffer_control_get_value32(hw_endpoint_t *ep)
{
    return *ep->buffer_control;
}

//! sync endpoint buffer and return transferred bytes
static uint16_t sync_ep_buffer(hw_endpoint_t* ep, uint8_t buf_id)
{
    uint32_t buf_ctrl = _hw_endpoint_buffer_control_get_value32(ep);
    if(buf_id)
    {
        buf_ctrl = buf_ctrl >> 16;
    }

    uint16_t xferred_bytes = buf_ctrl & USB_BUF_CTRL_LEN_MASK;

    if( !ep->rx )
    {
        // We are continuing a transfer here. If we are TX, we have successfully
        // sent some data can increase the length we have sent
        // assert(!(buf_ctrl & USB_BUF_CTRL_FULL));

        ep->xferred_len = (uint16_t)(ep->xferred_len + xferred_bytes);
    }
    else
    {
        // If we have received some data, so can increase the length
        // we have received AFTER we have copied it to the user buffer at the appropriate offset
        // assert(buf_ctrl & USB_BUF_CTRL_FULL);

        memcpy(ep->user_buf, ep->hw_data_buf + buf_id*64, xferred_bytes);
        ep->xferred_len = (uint16_t)(ep->xferred_len + xferred_bytes);
        ep->user_buf += xferred_bytes;
    }

    // Short packet
    if (xferred_bytes < ep->wMaxPacketSize)
    {
        TU_LOG(3, "  Short packet on buffer %d with %u bytes\r\n", buf_id, xferred_bytes);
        // Reduce total length as this is last packet
        ep->remaining_len = 0;
    }

    return xferred_bytes;
}

static void _hw_endpoint_xfer_sync(hw_endpoint_t *ep)
{
    // Update hw endpoint struct with info from hardware
    // after a buff status interrupt

    uint32_t __unused buf_ctrl = _hw_endpoint_buffer_control_get_value32(ep);
    TU_LOG(3, "  Sync BufCtrl: [0] = 0x%04x  [1] = 0x%04x\r\n", tu_u32_low16(buf_ctrl), tu_u32_high16(buf_ctrl));

    // always sync buffer 0
    uint16_t buf0_bytes = sync_ep_buffer(ep, 0);

    // sync buffer 1 if double buffered
    if ( (*ep->endpoint_control) & EP_CTRL_DOUBLE_BUFFERED_BITS )
    {
        if (buf0_bytes == ep->wMaxPacketSize)
        {
            // sync buffer 1 if not short packet
            sync_ep_buffer(ep, 1);
        }
        else
        {
            // short packet on buffer 0
            // TODO couldn't figure out how to handle this case which happen with net_lwip_webserver example
            // At this time (currently trigger per 2 buffer), the buffer1 is probably filled with data from
            // the next transfer (not current one). For now we disable double buffered for device OUT
            // NOTE this could happen to Host IN
            #if 0
                uint8_t const ep_num = tu_edpt_number(ep->ep_addr);
                uint8_t const dir =  (uint8_t) tu_edpt_dir(ep->ep_addr);
                uint8_t const ep_id = 2*ep_num + (dir ? 0 : 1);

                // abort queued transfer on buffer 1
                USBCTRL_REGS->abort |= TU_BIT(ep_id);

                while ( !(USBCTRL_REGS->abort_done & TU_BIT(ep_id)) ) {}

                uint32_t ep_ctrl = *ep->endpoint_control;
                ep_ctrl &= ~(EP_CTRL_DOUBLE_BUFFERED_BITS | EP_CTRL_INTERRUPT_PER_DOUBLE_BUFFER);
                ep_ctrl |= EP_CTRL_INTERRUPT_PER_BUFFER;

                _hw_endpoint_buffer_control_set_value32(ep, 0);

                USBCTRL_REGS->abort &= ~TU_BIT(ep_id);

                TU_LOG(3, "----SHORT PACKET buffer0 on EP %02X:\r\n", ep->ep_addr);
                TU_LOG(3, "  BufCtrl: [0] = 0x%04x  [1] = 0x%04x\r\n", tu_u32_low16(buf_ctrl), tu_u32_high16(buf_ctrl));
            #endif
        }
    }
}

//! Returns true if transfer is complete
bool hw_endpoint_xfer_continue(hw_endpoint_t *ep)
{
    // Part way through a transfer
    if (!ep->active)
    {
        TU_LOG(1, "Can't continue xfer on inactive ep %d %s\r\n", tu_edpt_number(ep->ep_addr), ep_dir_string[tu_edpt_dir(ep->ep_addr)]);
    }

    // Update EP struct from hardware state
    _hw_endpoint_xfer_sync(ep);

    // Now we have synced our state with the hardware. Is there more data to transfer?
    // If we are done then notify tinyusb
    if (ep->remaining_len == 0)
    {
        TU_LOG(3, "Completed transfer of %d bytes on ep %d %s\r\n",
        ep->xferred_len, tu_edpt_number(ep->ep_addr), ep_dir_string[tu_edpt_dir(ep->ep_addr)]);
        // Notify caller we are done so it can notify the tinyusb stack
        return true;
    }
    else
    {
        if ( e15_is_critical_frame_period(ep) )
        {
            ep->pending = 1;
        }
        else
        {
            hw_endpoint_start_next_buffer(ep);
        }
    }

    // More work to do
    return false;
}

static void hw_handle_buff_status(void)
{
    uint32_t bit = 1u;
    uint32_t remaining_buffers = USBCTRL_REGS->BUFF_STATUS;

    TU_LOG(3, "buf_status = 0x%08lx\r\n", remaining_buffers);

    for(uint8_t i = 0; remaining_buffers && i < USB_NUM_ENDPOINTS * 2; i++)
    {
        if(remaining_buffers & bit)
        {
            // clear this in advance
            USBCTRL_REGS_CLR->BUFF_STATUS = bit;

            // IN transfer for even i, OUT transfer for odd i
            hw_endpoint_t *ep = hw_endpoint_get_by_num(i >> 1u, !(i & 1u));

            // Continue xfer
            bool done = hw_endpoint_xfer_continue(ep);
            if(done)
            {
                // Notify
                dcd_event_xfer_complete(0, ep->ep_addr, ep->xferred_len, XFER_RESULT_SUCCESS, true);
                hw_endpoint_reset_transfer(ep);
            }
            remaining_buffers &= ~bit;
        }
        bit <<= 1u;
    }
}

//--------------------------------------------------------------------+
// Errata 15
//--------------------------------------------------------------------+

#if TUD_OPT_RP2040_USB_DEVICE_UFRAME_FIX

/* Don't mark IN buffers as available during the last 200us of a full-speed
   frame. This avoids a situation seen with the USB2.0 hub on a Raspberry
   Pi 4 where a late IN token before the next full-speed SOF can cause port
   babble and a corrupt ACK packet. The nature of the data corruption has a
   chance to cause device lockup.

   Use the next SOF to mark delayed buffers as available. This reduces
   available Bulk IN bandwidth by approximately 20%, and requires that the
   SOF interrupt is enabled while these transfers are ongoing.

   Inherit the top-level enable from the corresponding Pico-SDK flag.
   Applications that will not use the device in a situation where it could
   be plugged into a Pi 4 or Pi 400 (for example, when directly connected
   to a commodity hub or other host) can turn off the flag in the SDK.
*/

volatile uint32_t e15_last_sof = 0;

//! check if Errata 15 is needed for this endpoint i.e device bulk-in
static bool e15_is_bulkin_ep (hw_endpoint_t *ep)
{
    return (!is_host_mode() && tu_edpt_dir(ep->ep_addr) == TUSB_DIR_IN &&
            ep->transfer_type == TUSB_XFER_BULK);
}

//! check if we need to apply Errata 15 workaround : i.e
//! Endpoint is BULK IN and is currently in critical frame period i.e 20% of last usb frame
static bool e15_is_critical_frame_period (hw_endpoint_t *ep)
{
    TU_VERIFY(e15_is_bulkin_ep(ep));

    /* Avoid the last 200us (uframe 6.5-7) of a frame, up to the EOF2 point.
    * The device state machine cannot recover from receiving an incorrect PID
    * when it is expecting an ACK.
    */ /*
    uint32_t delta = time_us_32() - e15_last_sof;
    if (delta < 800 || delta > 998)
    {
        return false;
    }*/
    TU_LOG(3, "Avoiding sof %lu now %lu last %lu\r\n", (USBCTRL_REGS->SOF_RD + 1) & USB_SOF_RD_BITS, time_us_32(), e15_last_sof);
    return true;
}

#endif

static void dcd_rp2040_irq(void)
{
    uint32_t const status = USBCTRL_REGS->INTS;
    uint32_t handled = 0;

    if( status & USB_INTF_DEV_SOF_BITS )
    {
        bool keep_sof_alive = false;

        handled |= USB_INTF_DEV_SOF_BITS;

        #if TUD_OPT_RP2040_USB_DEVICE_UFRAME_FIX
        // Errata 15 workaround for Device Bulk-In endpoint
        e15_last_sof = time_us_32();

        for( uint8_t i = 0; i < USB_NUM_ENDPOINTS; i++ )
        {
            hw_endpoint_t * ep = hw_endpoint_get_by_num(i, TUSB_DIR_IN);

            // Active Bulk IN endpoint requires SOF
            if( (ep->transfer_type == TUSB_XFER_BULK) && ep->active )
            {
                keep_sof_alive = true;

                // Deferred enable?
                if( ep->pending )
                {
                    ep->pending = 0;
                    hw_endpoint_start_next_buffer(ep);
                }
            }
        }
        #endif

        // disable SOF interrupt if it is used for RESUME in remote wakeup
        if( !keep_sof_alive && !_sof_enable )
        {
            USBCTRL_REGS_CLR->INTE = USB_INTS_DEV_SOF_BITS;
        }
        dcd_event_sof(0, USBCTRL_REGS->SOF_RD & USB_SOF_RD_BITS, true);
    }

    // xfer events are handled before setup req. So if a transfer completes immediately
    // before closing the EP, the events will be delivered in same order.
    if( status & USB_INTS_BUFF_STATUS_BITS )
    {
        handled |= USB_INTS_BUFF_STATUS_BITS;
        hw_handle_buff_status();
    }

    if( status & USB_INTS_SETUP_REQ_BITS )
    {
        handled |= USB_INTS_SETUP_REQ_BITS;
        uint8_t const * setup = (uint8_t const*) &usb_dpram->setup_packet;

        // reset pid to both 1 (data and ack)
        reset_ep0_pid();

        // Pass setup packet to tiny usb
        dcd_event_setup_received(0, setup, true);
        USBCTRL_REGS_CLR->SIE_STATUS = USB_SIE_STATUS_SETUP_REC_BITS;
    }

    #if FORCE_VBUS_DETECT == 0
    // Since we force VBUS detect On, device will always think it is connected and
    // couldn't distinguish between disconnect and suspend
    if (status & USB_INTS_DEV_CONN_DIS_BITS)
    {
        handled |= USB_INTS_DEV_CONN_DIS_BITS;

        if ( USBCTRL_REGS->SIE_STATUS & USB_SIE_STATUS_CONNECTED_BITS )
        {
            // Connected: nothing to do
        }
        else
        {
            // Disconnected
            dcd_event_bus_signal(0, DCD_EVENT_UNPLUGGED, true);
        }

        USBCTRL_REGS_CLR->SIE_STATUS = USB_SIE_STATUS_CONNECTED_BITS;
    }
    #endif

    // SE0 for 2.5 us or more (will last at least 10ms)
    if( status & USB_INTS_BUS_RESET_BITS )
    {
        TU_LOG(3, "BUS RESET\r\n");

        handled |= USB_INTS_BUS_RESET_BITS;

        USBCTRL_REGS->ADDR_ENDP = 0;
        reset_non_control_endpoints();
        dcd_event_bus_reset(0, TUSB_SPEED_FULL, true);
        USBCTRL_REGS_CLR->SIE_STATUS = USB_SIE_STATUS_BUS_RESET_BITS;

        #if TUD_OPT_RP2040_USB_DEVICE_ENUMERATION_FIX
        // Only run enumeration workaround if pull up is enabled
        if ( USBCTRL_REGS->sie_ctrl & USB_SIE_CTRL_PULLUP_EN_BITS ) rp2040_usb_device_enumeration_fix();
        #endif
    }

    /* Note from pico datasheet 4.1.2.6.4 (v1.2)
    * If you enable the suspend interrupt, it is likely you will see a suspend interrupt when
    * the device is first connected but the bus is idle. The bus can be idle for a few ms before
    * the host begins sending start of frame packets. You will also see a suspend interrupt
    * when the device is disconnected if you do not have a VBUS detect circuit connected. This is
    * because without VBUS detection, it is impossible to tell the difference between
    * being disconnected and suspended.
    */
    if( status & USB_INTS_DEV_SUSPEND_BITS )
    {
        handled |= USB_INTS_DEV_SUSPEND_BITS;
        dcd_event_bus_signal(0, DCD_EVENT_SUSPEND, true);
        USBCTRL_REGS_CLR->SIE_STATUS = USB_SIE_STATUS_SUSPENDED_BITS;
    }

    if( status & USB_INTS_DEV_RESUME_FROM_HOST_BITS )
    {
        handled |= USB_INTS_DEV_RESUME_FROM_HOST_BITS;
        dcd_event_bus_signal(0, DCD_EVENT_RESUME, true);
        USBCTRL_REGS_CLR->SIE_STATUS = USB_SIE_STATUS_RESUME_BITS;
    }

    if( status ^ handled )
    {
        // panic("Unhandled IRQ 0x%x\n", (uint32_t) (status ^ handled));
    }
}

static void hw_endpoint_reset_transfer(hw_endpoint_t* ep)
{
    ep->active = false;
    ep->remaining_len = 0;
    ep->xferred_len = 0;
    ep->user_buf = 0;
}

//! prepare buffer, return buffer control
static uint32_t prepare_ep_buffer(hw_endpoint_t* ep, uint8_t buf_id)
{
    uint16_t const buflen = tu_min16(ep->remaining_len, ep->wMaxPacketSize);
    ep->remaining_len = (uint16_t)(ep->remaining_len - buflen);

    uint32_t buf_ctrl = buflen | USB_BUF_CTRL_AVAIL;

    // PID
    buf_ctrl |= ep->next_pid ? USB_BUF_CTRL_DATA1_PID : USB_BUF_CTRL_DATA0_PID;
    ep->next_pid ^= 1u;

    if( !ep->rx )
    {
        // Copy data from user buffer to hw buffer
        memcpy(ep->hw_data_buf + buf_id*64, ep->user_buf, buflen);
        ep->user_buf += buflen;

        // Mark as full
        buf_ctrl |= USB_BUF_CTRL_FULL;
    }

    // Is this the last buffer? Only really matters for host mode. Will trigger
    // the trans complete irq but also stop it polling. We only really care about
    // trans complete for setup packets being sent
    if(ep->remaining_len == 0)
    {
        buf_ctrl |= USB_BUF_CTRL_LAST;
    }

    if(buf_id)
    {
        buf_ctrl = buf_ctrl << 16;
    }

    return buf_ctrl;
}

TU_ATTR_ALWAYS_INLINE static inline void _hw_endpoint_buffer_control_clear_mask32 (hw_endpoint_t* ep, uint32_t value)
{
    _hw_endpoint_buffer_control_update32(ep, ~value, 0);
}

void dcd_init(uint8_t rhport)
{
    (void) rhport;

    // Reset hardware to default state
    usb_init();

    #if FORCE_VBUS_DETECT
    // Force VBUS detect so the device thinks it is plugged into a host
    USBCTRL_REGS->USB_PWR = USB_USB_PWR_VBUS_DETECT_BITS | USB_USB_PWR_VBUS_DETECT_OVERRIDE_EN_BITS;
    #endif

    // Init control endpoints
    tu_memclr(hw_endpoints[0], 2*sizeof(hw_endpoint_t));
    hw_endpoint_init(0x0, 64, TUSB_XFER_CONTROL);
    hw_endpoint_init(0x80, 64, TUSB_XFER_CONTROL);

    // Init non-control endpoints
    reset_non_control_endpoints();

    // Initializes the USB peripheral for device mode and enables it.
    // Don't need to enable the pull up here. Force VBUS
    USBCTRL_REGS->MAIN_CTRL = USB_MAIN_CTRL_CONTROLLER_EN_BITS;

    // Enable individual controller IRQS here. Processor interrupt enable will be used
    // for the global interrupt enable...
    // Note: Force VBUS detect cause disconnection not detectable
    USBCTRL_REGS->SIE_CTRL = USB_SIE_CTRL_EP0_INT_1BUF_BITS;
    USBCTRL_REGS->INTE     = USB_INTS_BUFF_STATUS_BITS | USB_INTS_BUS_RESET_BITS | USB_INTS_SETUP_REQ_BITS |
                     USB_INTS_DEV_SUSPEND_BITS | USB_INTS_DEV_RESUME_FROM_HOST_BITS |
                     (FORCE_VBUS_DETECT ? 0 : USB_INTS_DEV_CONN_DIS_BITS);

    dcd_connect(rhport);
}

void dcd_sof_enable(uint8_t rhport, bool en)
{
    (void) rhport;

    _sof_enable = en;

    if(en)
    {
        USBCTRL_REGS->INTE = USB_INTS_DEV_SOF_BITS;
    }
    else
    {
        // Don't clear immediately if the SOF workaround is in use.
        // The SOF handler will conditionally disable the interrupt.
        #if !TUD_OPT_RP2040_USB_DEVICE_UFRAME_FIX
        USBCTRL_REGS_CLR->INTE = USB_INTS_DEV_SOF_BITS;
        #endif
    }
}

void dcd_remote_wakeup(__unused uint8_t rhport)
{
    TU_LOG(2, "dcd_remote_wakeup %d\r\n", rhport);

    // since RESUME interrupt is not triggered if we are the one initiate
    // briefly enable SOF to notify usbd when bus is ready
    USBCTRL_REGS_SET->INTE = USB_INTS_DEV_SOF_BITS;
    USBCTRL_REGS_SET->SIE_CTRL = USB_SIE_CTRL_RESUME_BITS;
}

//! connect by enabling internal pull-up resistor on D+/D-
void dcd_connect(__unused uint8_t rhport)
{
  (void) rhport;
  USBCTRL_REGS_SET->SIE_CTRL = USB_SIE_CTRL_PULLUP_EN_BITS;
}

//! disconnect by disabling internal pull-up resistor on D+/D-
void dcd_disconnect(__unused uint8_t rhport)
{
    (void) rhport;
    USBCTRL_REGS_CLR->SIE_CTRL = USB_SIE_CTRL_PULLUP_EN_BITS;
}

void dcd_edpt0_status_complete(uint8_t rhport, tusb_control_request_t const * request)
{
    (void) rhport;

    if( request->bmRequestType_bit.recipient == TUSB_REQ_RCPT_DEVICE &&
        request->bmRequestType_bit.type == TUSB_REQ_TYPE_STANDARD &&
        request->bRequest == TUSB_REQ_SET_ADDRESS )
    {
        USBCTRL_REGS->ADDR_ENDP = (uint8_t) request->wValue;
    }
}
