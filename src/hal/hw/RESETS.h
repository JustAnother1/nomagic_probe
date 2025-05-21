/*
  automatically created from data available on https://chipselect.org/
*/
#ifndef HW_RESETS_H
#define HW_RESETS_H
/** Memory Block starting at 0x4000C000 + 0x0 is 0x1000 bytes in size. It is used for registers. Protection: n */

#include <stdint.h>


#define RESETS_RESET_USBCTRL_OFFSET                        24u
#define RESETS_RESET_USBCTRL_MASK                          0x1000000u

#define RESETS_RESET_UART1_OFFSET                          23u
#define RESETS_RESET_UART1_MASK                            0x800000u

#define RESETS_RESET_UART0_OFFSET                          22u
#define RESETS_RESET_UART0_MASK                            0x400000u

#define RESETS_RESET_TIMER_OFFSET                          21u
#define RESETS_RESET_TIMER_MASK                            0x200000u

#define RESETS_RESET_TBMAN_OFFSET                          20u
#define RESETS_RESET_TBMAN_MASK                            0x100000u

#define RESETS_RESET_SYSINFO_OFFSET                        19u
#define RESETS_RESET_SYSINFO_MASK                          0x80000u

#define RESETS_RESET_SYSCFG_OFFSET                         18u
#define RESETS_RESET_SYSCFG_MASK                           0x40000u

#define RESETS_RESET_SPI1_OFFSET                           17u
#define RESETS_RESET_SPI1_MASK                             0x20000u

#define RESETS_RESET_SPI0_OFFSET                           16u
#define RESETS_RESET_SPI0_MASK                             0x10000u

#define RESETS_RESET_RTC_OFFSET                            15u
#define RESETS_RESET_RTC_MASK                              0x8000u

#define RESETS_RESET_PWM_OFFSET                            14u
#define RESETS_RESET_PWM_MASK                              0x4000u

#define RESETS_RESET_PLL_USB_OFFSET                        13u
#define RESETS_RESET_PLL_USB_MASK                          0x2000u

#define RESETS_RESET_PLL_SYS_OFFSET                        12u
#define RESETS_RESET_PLL_SYS_MASK                          0x1000u

#define RESETS_RESET_PIO1_OFFSET                           11u
#define RESETS_RESET_PIO1_MASK                             0x800u

#define RESETS_RESET_PIO0_OFFSET                           10u
#define RESETS_RESET_PIO0_MASK                             0x400u

#define RESETS_RESET_PADS_QSPI_OFFSET                      9u
#define RESETS_RESET_PADS_QSPI_MASK                        0x200u

#define RESETS_RESET_PADS_BANK0_OFFSET                     8u
#define RESETS_RESET_PADS_BANK0_MASK                       0x100u

#define RESETS_RESET_JTAG_OFFSET                           7u
#define RESETS_RESET_JTAG_MASK                             0x80u

#define RESETS_RESET_IO_QSPI_OFFSET                        6u
#define RESETS_RESET_IO_QSPI_MASK                          0x40u

#define RESETS_RESET_IO_BANK0_OFFSET                       5u
#define RESETS_RESET_IO_BANK0_MASK                         0x20u

#define RESETS_RESET_I2C1_OFFSET                           4u
#define RESETS_RESET_I2C1_MASK                             0x10u

#define RESETS_RESET_I2C0_OFFSET                           3u
#define RESETS_RESET_I2C0_MASK                             8u

#define RESETS_RESET_DMA_OFFSET                            2u
#define RESETS_RESET_DMA_MASK                              4u

#define RESETS_RESET_BUSCTRL_OFFSET                        1u
#define RESETS_RESET_BUSCTRL_MASK                          2u

#define RESETS_RESET_ADC_OFFSET                            0u
#define RESETS_RESET_ADC_MASK                              1u

#define RESETS_WDSEL_USBCTRL_OFFSET                        24u
#define RESETS_WDSEL_USBCTRL_MASK                          0x1000000u

#define RESETS_WDSEL_UART1_OFFSET                          23u
#define RESETS_WDSEL_UART1_MASK                            0x800000u

#define RESETS_WDSEL_UART0_OFFSET                          22u
#define RESETS_WDSEL_UART0_MASK                            0x400000u

#define RESETS_WDSEL_TIMER_OFFSET                          21u
#define RESETS_WDSEL_TIMER_MASK                            0x200000u

#define RESETS_WDSEL_TBMAN_OFFSET                          20u
#define RESETS_WDSEL_TBMAN_MASK                            0x100000u

#define RESETS_WDSEL_SYSINFO_OFFSET                        19u
#define RESETS_WDSEL_SYSINFO_MASK                          0x80000u

#define RESETS_WDSEL_SYSCFG_OFFSET                         18u
#define RESETS_WDSEL_SYSCFG_MASK                           0x40000u

#define RESETS_WDSEL_SPI1_OFFSET                           17u
#define RESETS_WDSEL_SPI1_MASK                             0x20000u

#define RESETS_WDSEL_SPI0_OFFSET                           16u
#define RESETS_WDSEL_SPI0_MASK                             0x10000u

#define RESETS_WDSEL_RTC_OFFSET                            15u
#define RESETS_WDSEL_RTC_MASK                              0x8000u

#define RESETS_WDSEL_PWM_OFFSET                            14u
#define RESETS_WDSEL_PWM_MASK                              0x4000u

#define RESETS_WDSEL_PLL_USB_OFFSET                        13u
#define RESETS_WDSEL_PLL_USB_MASK                          0x2000u

#define RESETS_WDSEL_PLL_SYS_OFFSET                        12u
#define RESETS_WDSEL_PLL_SYS_MASK                          0x1000u

#define RESETS_WDSEL_PIO1_OFFSET                           11u
#define RESETS_WDSEL_PIO1_MASK                             0x800u

#define RESETS_WDSEL_PIO0_OFFSET                           10u
#define RESETS_WDSEL_PIO0_MASK                             0x400u

#define RESETS_WDSEL_PADS_QSPI_OFFSET                      9u
#define RESETS_WDSEL_PADS_QSPI_MASK                        0x200u

#define RESETS_WDSEL_PADS_BANK0_OFFSET                     8u
#define RESETS_WDSEL_PADS_BANK0_MASK                       0x100u

#define RESETS_WDSEL_JTAG_OFFSET                           7u
#define RESETS_WDSEL_JTAG_MASK                             0x80u

#define RESETS_WDSEL_IO_QSPI_OFFSET                        6u
#define RESETS_WDSEL_IO_QSPI_MASK                          0x40u

#define RESETS_WDSEL_IO_BANK0_OFFSET                       5u
#define RESETS_WDSEL_IO_BANK0_MASK                         0x20u

#define RESETS_WDSEL_I2C1_OFFSET                           4u
#define RESETS_WDSEL_I2C1_MASK                             0x10u

#define RESETS_WDSEL_I2C0_OFFSET                           3u
#define RESETS_WDSEL_I2C0_MASK                             8u

#define RESETS_WDSEL_DMA_OFFSET                            2u
#define RESETS_WDSEL_DMA_MASK                              4u

#define RESETS_WDSEL_BUSCTRL_OFFSET                        1u
#define RESETS_WDSEL_BUSCTRL_MASK                          2u

#define RESETS_WDSEL_ADC_OFFSET                            0u
#define RESETS_WDSEL_ADC_MASK                              1u

#define RESETS_RESET_DONE_USBCTRL_OFFSET                   24u
#define RESETS_RESET_DONE_USBCTRL_MASK                     0x1000000u

#define RESETS_RESET_DONE_UART1_OFFSET                     23u
#define RESETS_RESET_DONE_UART1_MASK                       0x800000u

#define RESETS_RESET_DONE_UART0_OFFSET                     22u
#define RESETS_RESET_DONE_UART0_MASK                       0x400000u

#define RESETS_RESET_DONE_TIMER_OFFSET                     21u
#define RESETS_RESET_DONE_TIMER_MASK                       0x200000u

#define RESETS_RESET_DONE_TBMAN_OFFSET                     20u
#define RESETS_RESET_DONE_TBMAN_MASK                       0x100000u

#define RESETS_RESET_DONE_SYSINFO_OFFSET                   19u
#define RESETS_RESET_DONE_SYSINFO_MASK                     0x80000u

#define RESETS_RESET_DONE_SYSCFG_OFFSET                    18u
#define RESETS_RESET_DONE_SYSCFG_MASK                      0x40000u

#define RESETS_RESET_DONE_SPI1_OFFSET                      17u
#define RESETS_RESET_DONE_SPI1_MASK                        0x20000u

#define RESETS_RESET_DONE_SPI0_OFFSET                      16u
#define RESETS_RESET_DONE_SPI0_MASK                        0x10000u

#define RESETS_RESET_DONE_RTC_OFFSET                       15u
#define RESETS_RESET_DONE_RTC_MASK                         0x8000u

#define RESETS_RESET_DONE_PWM_OFFSET                       14u
#define RESETS_RESET_DONE_PWM_MASK                         0x4000u

#define RESETS_RESET_DONE_PLL_USB_OFFSET                   13u
#define RESETS_RESET_DONE_PLL_USB_MASK                     0x2000u

#define RESETS_RESET_DONE_PLL_SYS_OFFSET                   12u
#define RESETS_RESET_DONE_PLL_SYS_MASK                     0x1000u

#define RESETS_RESET_DONE_PIO1_OFFSET                      11u
#define RESETS_RESET_DONE_PIO1_MASK                        0x800u

#define RESETS_RESET_DONE_PIO0_OFFSET                      10u
#define RESETS_RESET_DONE_PIO0_MASK                        0x400u

#define RESETS_RESET_DONE_PADS_QSPI_OFFSET                 9u
#define RESETS_RESET_DONE_PADS_QSPI_MASK                   0x200u

#define RESETS_RESET_DONE_PADS_BANK0_OFFSET                8u
#define RESETS_RESET_DONE_PADS_BANK0_MASK                  0x100u

#define RESETS_RESET_DONE_JTAG_OFFSET                      7u
#define RESETS_RESET_DONE_JTAG_MASK                        0x80u

#define RESETS_RESET_DONE_IO_QSPI_OFFSET                   6u
#define RESETS_RESET_DONE_IO_QSPI_MASK                     0x40u

#define RESETS_RESET_DONE_IO_BANK0_OFFSET                  5u
#define RESETS_RESET_DONE_IO_BANK0_MASK                    0x20u

#define RESETS_RESET_DONE_I2C1_OFFSET                      4u
#define RESETS_RESET_DONE_I2C1_MASK                        0x10u

#define RESETS_RESET_DONE_I2C0_OFFSET                      3u
#define RESETS_RESET_DONE_I2C0_MASK                        8u

#define RESETS_RESET_DONE_DMA_OFFSET                       2u
#define RESETS_RESET_DONE_DMA_MASK                         4u

#define RESETS_RESET_DONE_BUSCTRL_OFFSET                   1u
#define RESETS_RESET_DONE_BUSCTRL_MASK                     2u

#define RESETS_RESET_DONE_ADC_OFFSET                       0u
#define RESETS_RESET_DONE_ADC_MASK                         1u


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
