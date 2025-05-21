/*
  automatically created from data available on https://chipselect.org/
*/
#ifndef HW_RTC_H
#define HW_RTC_H
/** Register block to control RTC */
/** Interrupt : RTC_IRQ (Vector: 25)  */
/** Memory Block starting at 0x4005C000 + 0x0 is 0x1000 bytes in size. It is used for registers. Protection: n */

#include <stdint.h>


#define RTC_CLKDIV_M1_CLKDIV_M1_OFFSET                     0u
#define RTC_CLKDIV_M1_CLKDIV_M1_MASK                       0xffffu

#define RTC_SETUP_0_YEAR_OFFSET                            12u
#define RTC_SETUP_0_YEAR_MASK                              0xfff000u

#define RTC_SETUP_0_MONTH_OFFSET                           8u
#define RTC_SETUP_0_MONTH_MASK                             0xf00u

#define RTC_SETUP_0_DAY_OFFSET                             0u
#define RTC_SETUP_0_DAY_MASK                               0x1fu

#define RTC_SETUP_1_DOTW_OFFSET                            24u
#define RTC_SETUP_1_DOTW_MASK                              0x7000000u

#define RTC_SETUP_1_HOUR_OFFSET                            16u
#define RTC_SETUP_1_HOUR_MASK                              0x1f0000u

#define RTC_SETUP_1_MIN_OFFSET                             8u
#define RTC_SETUP_1_MIN_MASK                               0x3f00u

#define RTC_SETUP_1_SEC_OFFSET                             0u
#define RTC_SETUP_1_SEC_MASK                               0x3fu

#define RTC_CTRL_FORCE_NOTLEAPYEAR_OFFSET                  8u
#define RTC_CTRL_FORCE_NOTLEAPYEAR_MASK                    0x100u

#define RTC_CTRL_LOAD_OFFSET                               4u
#define RTC_CTRL_LOAD_MASK                                 0x10u

#define RTC_CTRL_RTC_ACTIVE_OFFSET                         1u
#define RTC_CTRL_RTC_ACTIVE_MASK                           2u

#define RTC_CTRL_RTC_ENABLE_OFFSET                         0u
#define RTC_CTRL_RTC_ENABLE_MASK                           1u

#define RTC_IRQ_SETUP_0_MATCH_ACTIVE_OFFSET                29u
#define RTC_IRQ_SETUP_0_MATCH_ACTIVE_MASK                  0x20000000u

#define RTC_IRQ_SETUP_0_MATCH_ENA_OFFSET                   28u
#define RTC_IRQ_SETUP_0_MATCH_ENA_MASK                     0x10000000u

#define RTC_IRQ_SETUP_0_YEAR_ENA_OFFSET                    26u
#define RTC_IRQ_SETUP_0_YEAR_ENA_MASK                      0x4000000u

#define RTC_IRQ_SETUP_0_MONTH_ENA_OFFSET                   25u
#define RTC_IRQ_SETUP_0_MONTH_ENA_MASK                     0x2000000u

#define RTC_IRQ_SETUP_0_DAY_ENA_OFFSET                     24u
#define RTC_IRQ_SETUP_0_DAY_ENA_MASK                       0x1000000u

#define RTC_IRQ_SETUP_0_YEAR_OFFSET                        12u
#define RTC_IRQ_SETUP_0_YEAR_MASK                          0xfff000u

#define RTC_IRQ_SETUP_0_MONTH_OFFSET                       8u
#define RTC_IRQ_SETUP_0_MONTH_MASK                         0xf00u

#define RTC_IRQ_SETUP_0_DAY_OFFSET                         0u
#define RTC_IRQ_SETUP_0_DAY_MASK                           0x1fu

#define RTC_IRQ_SETUP_1_DOTW_ENA_OFFSET                    31u
#define RTC_IRQ_SETUP_1_DOTW_ENA_MASK                      0x80000000u

#define RTC_IRQ_SETUP_1_HOUR_ENA_OFFSET                    30u
#define RTC_IRQ_SETUP_1_HOUR_ENA_MASK                      0x40000000u

#define RTC_IRQ_SETUP_1_MIN_ENA_OFFSET                     29u
#define RTC_IRQ_SETUP_1_MIN_ENA_MASK                       0x20000000u

#define RTC_IRQ_SETUP_1_SEC_ENA_OFFSET                     28u
#define RTC_IRQ_SETUP_1_SEC_ENA_MASK                       0x10000000u

#define RTC_IRQ_SETUP_1_DOTW_OFFSET                        24u
#define RTC_IRQ_SETUP_1_DOTW_MASK                          0x7000000u

#define RTC_IRQ_SETUP_1_HOUR_OFFSET                        16u
#define RTC_IRQ_SETUP_1_HOUR_MASK                          0x1f0000u

#define RTC_IRQ_SETUP_1_MIN_OFFSET                         8u
#define RTC_IRQ_SETUP_1_MIN_MASK                           0x3f00u

#define RTC_IRQ_SETUP_1_SEC_OFFSET                         0u
#define RTC_IRQ_SETUP_1_SEC_MASK                           0x3fu

#define RTC_RTC_1_YEAR_OFFSET                              12u
#define RTC_RTC_1_YEAR_MASK                                0xfff000u

#define RTC_RTC_1_MONTH_OFFSET                             8u
#define RTC_RTC_1_MONTH_MASK                               0xf00u

#define RTC_RTC_1_DAY_OFFSET                               0u
#define RTC_RTC_1_DAY_MASK                                 0x1fu

#define RTC_RTC_0_DOTW_OFFSET                              24u
#define RTC_RTC_0_DOTW_MASK                                0x7000000u

#define RTC_RTC_0_HOUR_OFFSET                              16u
#define RTC_RTC_0_HOUR_MASK                                0x1f0000u

#define RTC_RTC_0_MIN_OFFSET                               8u
#define RTC_RTC_0_MIN_MASK                                 0x3f00u

#define RTC_RTC_0_SEC_OFFSET                               0u
#define RTC_RTC_0_SEC_MASK                                 0x3fu

#define RTC_INTR_RTC_OFFSET                                0u
#define RTC_INTR_RTC_MASK                                  1u

#define RTC_INTE_RTC_OFFSET                                0u
#define RTC_INTE_RTC_MASK                                  1u

#define RTC_INTF_RTC_OFFSET                                0u
#define RTC_INTF_RTC_MASK                                  1u

#define RTC_INTS_RTC_OFFSET                                0u
#define RTC_INTS_RTC_MASK                                  1u


typedef struct
{

/** CLKDIV_M1 (offset: 0x0)
  Divider minus 1 for the 1 second counter. Safe to change the value when RTC is not enabled.
  access : read-write
  reset value : 0x0
  reset mask : 0x0
  Field: CLKDIV_M1
  offset: 0, size: 16, access: read-write
*/
volatile uint32_t CLKDIV_M1;

/** SETUP_0 (offset: 0x4)
  RTC setup register 0
  access : read-write
  reset value : 0x0
  reset mask : 0x0
  Field: YEAR
  offset: 12, size: 12, access: read-write
  Year
  Field: MONTH
  offset: 8, size: 4, access: read-write
  Month (1..12)
  Field: DAY
  offset: 0, size: 5, access: read-write
  Day of the month (1..31)
*/
volatile uint32_t SETUP_0;

/** SETUP_1 (offset: 0x8)
  RTC setup register 1
  access : read-write
  reset value : 0x0
  reset mask : 0x0
  Field: DOTW
  offset: 24, size: 3, access: read-write
  Day of the week: 1-Monday...0-Sunday ISO 8601 mod 7
  Field: HOUR
  offset: 16, size: 5, access: read-write
  Hours
  Field: MIN
  offset: 8, size: 6, access: read-write
  Minutes
  Field: SEC
  offset: 0, size: 6, access: read-write
  Seconds
*/
volatile uint32_t SETUP_1;

/** CTRL (offset: 0xc)
  RTC Control and status
  access : read-write
  reset value : 0x0
  reset mask : 0x0
  Field: FORCE_NOTLEAPYEAR
  offset: 8, size: 1, access: read-write
  If set, leapyear is forced off.

 Useful for years divisible by 100 but not by 400
  Field: LOAD
  offset: 4, size: 1, access: read-write
  Load RTC
  Field: RTC_ACTIVE
  offset: 1, size: 1, access: read-only
  RTC enabled (running)
  Field: RTC_ENABLE
  offset: 0, size: 1, access: read-write
  Enable RTC
*/
volatile uint32_t CTRL;

/** IRQ_SETUP_0 (offset: 0x10)
  Interrupt setup register 0
  access : read-write
  reset value : 0x0
  reset mask : 0x0
  Field: MATCH_ACTIVE
  offset: 29, size: 1, access: read-only
  Field: MATCH_ENA
  offset: 28, size: 1, access: read-write
  Global match enable. Don&apos;t change any other value while this one is enabled
  Field: YEAR_ENA
  offset: 26, size: 1, access: read-write
  Enable year matching
  Field: MONTH_ENA
  offset: 25, size: 1, access: read-write
  Enable month matching
  Field: DAY_ENA
  offset: 24, size: 1, access: read-write
  Enable day matching
  Field: YEAR
  offset: 12, size: 12, access: read-write
  Year
  Field: MONTH
  offset: 8, size: 4, access: read-write
  Month (1..12)
  Field: DAY
  offset: 0, size: 5, access: read-write
  Day of the month (1..31)
*/
volatile uint32_t IRQ_SETUP_0;

/** IRQ_SETUP_1 (offset: 0x14)
  Interrupt setup register 1
  access : read-write
  reset value : 0x0
  reset mask : 0x0
  Field: DOTW_ENA
  offset: 31, size: 1, access: read-write
  Enable day of the week matching
  Field: HOUR_ENA
  offset: 30, size: 1, access: read-write
  Enable hour matching
  Field: MIN_ENA
  offset: 29, size: 1, access: read-write
  Enable minute matching
  Field: SEC_ENA
  offset: 28, size: 1, access: read-write
  Enable second matching
  Field: DOTW
  offset: 24, size: 3, access: read-write
  Day of the week
  Field: HOUR
  offset: 16, size: 5, access: read-write
  Hours
  Field: MIN
  offset: 8, size: 6, access: read-write
  Minutes
  Field: SEC
  offset: 0, size: 6, access: read-write
  Seconds
*/
volatile uint32_t IRQ_SETUP_1;

/** RTC_1 (offset: 0x18)
  RTC register 1.
  reset value : 0x0
  reset mask : 0x0
  Field: YEAR
  offset: 12, size: 12, access: read-only
  Year
  Field: MONTH
  offset: 8, size: 4, access: read-only
  Month (1..12)
  Field: DAY
  offset: 0, size: 5, access: read-only
  Day of the month (1..31)
*/
volatile uint32_t RTC_1;

/** RTC_0 (offset: 0x1c)
  RTC register 0

 Read this before RTC 1!
  reset value : 0x0
  reset mask : 0x0
  Field: DOTW
  offset: 24, size: 3, access: read-only
  Day of the week
  Field: HOUR
  offset: 16, size: 5, access: read-only
  Hours
  Field: MIN
  offset: 8, size: 6, access: read-only
  Minutes
  Field: SEC
  offset: 0, size: 6, access: read-only
  Seconds
*/
volatile uint32_t RTC_0;

/** INTR (offset: 0x20)
  Raw Interrupts
  access : read-write
  reset value : 0x0
  reset mask : 0x0
  Field: RTC
  offset: 0, size: 1, access: read-only
*/
volatile uint32_t INTR;

/** INTE (offset: 0x24)
  Interrupt Enable
  access : read-write
  reset value : 0x0
  reset mask : 0x0
  Field: RTC
  offset: 0, size: 1, access: read-write
*/
volatile uint32_t INTE;

/** INTF (offset: 0x28)
  Interrupt Force
  access : read-write
  reset value : 0x0
  reset mask : 0x0
  Field: RTC
  offset: 0, size: 1, access: read-write
*/
volatile uint32_t INTF;

/** INTS (offset: 0x2c)
  Interrupt status after masking &amp; forcing
  access : read-write
  reset value : 0x0
  reset mask : 0x0
  Field: RTC
  offset: 0, size: 1, access: read-only
*/
volatile uint32_t INTS;
} RTC_type;

#define RTC ((RTC_type *) 0x4005C000)

#endif // HW_RTC_H
