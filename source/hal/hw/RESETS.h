#ifndef HW_RESETS_H
#define HW_RESETS_H
/** Memory Block starting at 0x4000C000 + 0x0 is 0x1000 bytes in size. It is used for registers. Protection: n */

#include <stdint.h>

typedef struct
{

/** RESET (offset: 0x0)
  Reset control. If a bit is set it means the peripheral is in reset. 0 means the peripheral&apos;s reset is deasserted.
  access : read-write
  reset value : 0x1FFFFFF
  reset mask : 0x0
  Field: usbctrl
  offset: 24, size: 1, access: read-write
  Field: uart1
  offset: 23, size: 1, access: read-write
  Field: uart0
  offset: 22, size: 1, access: read-write
  Field: timer
  offset: 21, size: 1, access: read-write
  Field: tbman
  offset: 20, size: 1, access: read-write
  Field: sysinfo
  offset: 19, size: 1, access: read-write
  Field: syscfg
  offset: 18, size: 1, access: read-write
  Field: spi1
  offset: 17, size: 1, access: read-write
  Field: spi0
  offset: 16, size: 1, access: read-write
  Field: rtc
  offset: 15, size: 1, access: read-write
  Field: pwm
  offset: 14, size: 1, access: read-write
  Field: pll_usb
  offset: 13, size: 1, access: read-write
  Field: pll_sys
  offset: 12, size: 1, access: read-write
  Field: pio1
  offset: 11, size: 1, access: read-write
  Field: pio0
  offset: 10, size: 1, access: read-write
  Field: pads_qspi
  offset: 9, size: 1, access: read-write
  Field: pads_bank0
  offset: 8, size: 1, access: read-write
  Field: jtag
  offset: 7, size: 1, access: read-write
  Field: io_qspi
  offset: 6, size: 1, access: read-write
  Field: io_bank0
  offset: 5, size: 1, access: read-write
  Field: i2c1
  offset: 4, size: 1, access: read-write
  Field: i2c0
  offset: 3, size: 1, access: read-write
  Field: dma
  offset: 2, size: 1, access: read-write
  Field: busctrl
  offset: 1, size: 1, access: read-write
  Field: adc
  offset: 0, size: 1, access: read-write
*/
volatile uint32_t RESET;

/** WDSEL (offset: 0x4)
  Watchdog select. If a bit is set then the watchdog will reset this peripheral when the watchdog fires.
  access : read-write
  reset value : 0x0
  reset mask : 0x0
  Field: usbctrl
  offset: 24, size: 1, access: read-write
  Field: uart1
  offset: 23, size: 1, access: read-write
  Field: uart0
  offset: 22, size: 1, access: read-write
  Field: timer
  offset: 21, size: 1, access: read-write
  Field: tbman
  offset: 20, size: 1, access: read-write
  Field: sysinfo
  offset: 19, size: 1, access: read-write
  Field: syscfg
  offset: 18, size: 1, access: read-write
  Field: spi1
  offset: 17, size: 1, access: read-write
  Field: spi0
  offset: 16, size: 1, access: read-write
  Field: rtc
  offset: 15, size: 1, access: read-write
  Field: pwm
  offset: 14, size: 1, access: read-write
  Field: pll_usb
  offset: 13, size: 1, access: read-write
  Field: pll_sys
  offset: 12, size: 1, access: read-write
  Field: pio1
  offset: 11, size: 1, access: read-write
  Field: pio0
  offset: 10, size: 1, access: read-write
  Field: pads_qspi
  offset: 9, size: 1, access: read-write
  Field: pads_bank0
  offset: 8, size: 1, access: read-write
  Field: jtag
  offset: 7, size: 1, access: read-write
  Field: io_qspi
  offset: 6, size: 1, access: read-write
  Field: io_bank0
  offset: 5, size: 1, access: read-write
  Field: i2c1
  offset: 4, size: 1, access: read-write
  Field: i2c0
  offset: 3, size: 1, access: read-write
  Field: dma
  offset: 2, size: 1, access: read-write
  Field: busctrl
  offset: 1, size: 1, access: read-write
  Field: adc
  offset: 0, size: 1, access: read-write
*/
volatile uint32_t WDSEL;

/** RESET_DONE (offset: 0x8)
  Reset done. If a bit is set then a reset done signal has been returned by the peripheral. This indicates that the peripheral&apos;s registers are ready to be accessed.
  access : read-write
  reset value : 0x0
  reset mask : 0x0
  Field: usbctrl
  offset: 24, size: 1, access: read-only
  Field: uart1
  offset: 23, size: 1, access: read-only
  Field: uart0
  offset: 22, size: 1, access: read-only
  Field: timer
  offset: 21, size: 1, access: read-only
  Field: tbman
  offset: 20, size: 1, access: read-only
  Field: sysinfo
  offset: 19, size: 1, access: read-only
  Field: syscfg
  offset: 18, size: 1, access: read-only
  Field: spi1
  offset: 17, size: 1, access: read-only
  Field: spi0
  offset: 16, size: 1, access: read-only
  Field: rtc
  offset: 15, size: 1, access: read-only
  Field: pwm
  offset: 14, size: 1, access: read-only
  Field: pll_usb
  offset: 13, size: 1, access: read-only
  Field: pll_sys
  offset: 12, size: 1, access: read-only
  Field: pio1
  offset: 11, size: 1, access: read-only
  Field: pio0
  offset: 10, size: 1, access: read-only
  Field: pads_qspi
  offset: 9, size: 1, access: read-only
  Field: pads_bank0
  offset: 8, size: 1, access: read-only
  Field: jtag
  offset: 7, size: 1, access: read-only
  Field: io_qspi
  offset: 6, size: 1, access: read-only
  Field: io_bank0
  offset: 5, size: 1, access: read-only
  Field: i2c1
  offset: 4, size: 1, access: read-only
  Field: i2c0
  offset: 3, size: 1, access: read-only
  Field: dma
  offset: 2, size: 1, access: read-only
  Field: busctrl
  offset: 1, size: 1, access: read-only
  Field: adc
  offset: 0, size: 1, access: read-only
*/
volatile uint32_t RESET_DONE;
} RESETS_type;

#define RESETS ((RESETS_type *) 0x4000C000)

#endif // HW_RESETS_H
