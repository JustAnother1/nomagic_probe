/*
  automatically created from data available on https://chipselect.org/
*/
#ifndef HW_XOSC_H
#define HW_XOSC_H
/** Controls the crystal oscillator */
/** Memory Block starting at 0x40024000 + 0x0 is 0x1000 bytes in size. It is used for registers. Protection: n */

#include <stdint.h>


#define XOSC_CTRL_ENABLE_OFFSET                            12u
#define XOSC_CTRL_ENABLE_MASK                              0xfff000u
#define XOSC_CTRL_ENABLE_DISABLE                           0xd1eu
#define XOSC_CTRL_ENABLE_ENABLE                            0xfabu

#define XOSC_CTRL_FREQ_RANGE_OFFSET                        0u
#define XOSC_CTRL_FREQ_RANGE_MASK                          0xfffu
#define XOSC_CTRL_FREQ_RANGE_1_15MHZ                       0xaa0u
#define XOSC_CTRL_FREQ_RANGE_RESERVED_1                    0xaa1u
#define XOSC_CTRL_FREQ_RANGE_RESERVED_2                    0xaa2u
#define XOSC_CTRL_FREQ_RANGE_RESERVED_3                    0xaa3u

#define XOSC_STATUS_STABLE_OFFSET                          31u
#define XOSC_STATUS_STABLE_MASK                            0x80000000u

#define XOSC_STATUS_BADWRITE_OFFSET                        24u
#define XOSC_STATUS_BADWRITE_MASK                          0x1000000u

#define XOSC_STATUS_ENABLED_OFFSET                         12u
#define XOSC_STATUS_ENABLED_MASK                           0x1000u

#define XOSC_STATUS_FREQ_RANGE_OFFSET                      0u
#define XOSC_STATUS_FREQ_RANGE_MASK                        3u
#define XOSC_STATUS_FREQ_RANGE_1_15MHZ                     0u
#define XOSC_STATUS_FREQ_RANGE_RESERVED_1                  1u
#define XOSC_STATUS_FREQ_RANGE_RESERVED_2                  2u
#define XOSC_STATUS_FREQ_RANGE_RESERVED_3                  3u

#define XOSC_STARTUP_X4_OFFSET                             20u
#define XOSC_STARTUP_X4_MASK                               0x100000u

#define XOSC_STARTUP_DELAY_OFFSET                          0u
#define XOSC_STARTUP_DELAY_MASK                            0x3fffu

#define XOSC_COUNT_COUNT_OFFSET                            0u
#define XOSC_COUNT_COUNT_MASK                              0xffu


typedef struct
{

/** CTRL (offset: 0x0)
  Crystal Oscillator Control
  access : read-write
  reset value : 0x0
  reset mask : 0x0
  Field: ENABLE
  offset: 12, size: 12, access: read-write
  On power-up this field is initialised to DISABLE and the chip runs from the ROSC.

 If the chip has subsequently been programmed to run from the XOSC then setting this field to DISABLE may lock-up the chip. If this is a concern then run the clk_ref from the ROSC and enable the clk_sys RESUS feature.

 The 12-bit code is intended to give some protection against accidental writes. An invalid setting will enable the oscillator.
  Enum:
  Value: 0xd1e - DISABLE
  Value: 0xfab - ENABLE
  Field: FREQ_RANGE
  offset: 0, size: 12, access: read-write
  Frequency range. This resets to 0xAA0 and cannot be changed.
  Enum:
  Value: 0xaa0 - 1_15MHZ
  Value: 0xaa1 - RESERVED_1
  Value: 0xaa2 - RESERVED_2
  Value: 0xaa3 - RESERVED_3
*/
volatile uint32_t CTRL;

/** STATUS (offset: 0x4)
  Crystal Oscillator Status
  access : read-write
  reset value : 0x0
  reset mask : 0x0
  Field: STABLE
  offset: 31, size: 1, access: read-only
  Oscillator is running and stable
  Field: BADWRITE
  offset: 24, size: 1, access: read-write
  An invalid value has been written to CTRL_ENABLE or CTRL_FREQ_RANGE or DORMANT
  Field: ENABLED
  offset: 12, size: 1, access: read-only
  Oscillator is enabled but not necessarily running and stable, resets to 0
  Field: FREQ_RANGE
  offset: 0, size: 2, access: read-only
  The current frequency range setting, always reads 0
  Enum:
  Value: 0 - 1_15MHZ
  Value: 1 - RESERVED_1
  Value: 2 - RESERVED_2
  Value: 3 - RESERVED_3
*/
volatile uint32_t STATUS;

/** DORMANT (offset: 0x8)
  Crystal Oscillator pause control

 This is used to save power by pausing the XOSC

 On power-up this field is initialised to WAKE

 An invalid write will also select WAKE

 WARNING: stop the PLLs before selecting dormant mode

 WARNING: setup the irq before selecting dormant mode
  access : read-write
  reset value : 0x0
  reset mask : 0x0
*/
volatile uint32_t DORMANT;

/** STARTUP (offset: 0xc)
  Controls the startup delay
  access : read-write
  reset value : 0xC4
  reset mask : 0x0
  Field: X4
  offset: 20, size: 1, access: read-write
  Multiplies the startup_delay by 4. This is of little value to the user given that the delay can be programmed directly.
  Field: DELAY
  offset: 0, size: 14, access: read-write
  in multiples of 256*xtal_period. The reset value of 0xc4 corresponds to approx 50 000 cycles.
*/
volatile uint32_t STARTUP;
volatile uint32_t reserved0[3];

/** COUNT (offset: 0x1c)
  A down counter running at the xosc frequency which counts to zero and stops.

 To start the counter write a non-zero value.

 Can be used for short software pauses when setting up time sensitive hardware.
  access : read-write
  reset value : 0x0
  reset mask : 0x0
  Field: COUNT
  offset: 0, size: 8, access: read-write
*/
volatile uint32_t COUNT;
} XOSC_type;

#define XOSC ((XOSC_type *) 0x40024000)

#endif // HW_XOSC_H
