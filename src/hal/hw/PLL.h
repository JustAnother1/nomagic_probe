/*
  automatically created from data available on https://chipselect.org/
*/
#ifndef HW_PLL_H
#define HW_PLL_H
/** Memory Block starting at 0x40028000 + 0x0 is 0x1000 bytes in size. It is used for registers. Protection: n */
/** Memory Block starting at 0x4002C000 + 0x0 is 0x1000 bytes in size. It is used for registers. Protection: n */

#include <stdint.h>


#define PLL_CS_LOCK_OFFSET                                 31u
#define PLL_CS_LOCK_MASK                                   0x80000000u

#define PLL_CS_BYPASS_OFFSET                               8u
#define PLL_CS_BYPASS_MASK                                 0x100u

#define PLL_CS_REFDIV_OFFSET                               0u
#define PLL_CS_REFDIV_MASK                                 0x3fu

#define PLL_PWR_VCOPD_OFFSET                               5u
#define PLL_PWR_VCOPD_MASK                                 0x20u

#define PLL_PWR_POSTDIVPD_OFFSET                           3u
#define PLL_PWR_POSTDIVPD_MASK                             8u

#define PLL_PWR_DSMPD_OFFSET                               2u
#define PLL_PWR_DSMPD_MASK                                 4u

#define PLL_PWR_PD_OFFSET                                  0u
#define PLL_PWR_PD_MASK                                    1u

#define PLL_FBDIV_INT_FBDIV_INT_OFFSET                     0u
#define PLL_FBDIV_INT_FBDIV_INT_MASK                       0xfffu

#define PLL_PRIM_POSTDIV1_OFFSET                           16u
#define PLL_PRIM_POSTDIV1_MASK                             0x70000u

#define PLL_PRIM_POSTDIV2_OFFSET                           12u
#define PLL_PRIM_POSTDIV2_MASK                             0x7000u


typedef struct
{

/** CS (offset: 0x0)
  Control and Status

 GENERAL CONSTRAINTS:

 Reference clock frequency min=5MHz, max=800MHz

 Feedback divider min=16, max=320

 VCO frequency min=750MHz, max=1600MHz
  access : read-write
  reset value : 0x1
  reset mask : 0x0
  Field: LOCK
  offset: 31, size: 1, access: read-only
  PLL is locked
  Field: BYPASS
  offset: 8, size: 1, access: read-write
  Passes the reference clock to the output instead of the divided VCO. The VCO continues to run so the user can switch between the reference clock and the divided VCO but the output will glitch when doing so.
  Field: REFDIV
  offset: 0, size: 6, access: read-write
  Divides the PLL input reference clock.

 Behaviour is undefined for div=0.

 PLL output will be unpredictable during refdiv changes, wait for lock=1 before using it.
*/
volatile uint32_t CS;

/** PWR (offset: 0x4)
  Controls the PLL power modes.
  access : read-write
  reset value : 0x2D
  reset mask : 0x0
  Field: VCOPD
  offset: 5, size: 1, access: read-write
  PLL VCO powerdown

 To save power set high when PLL output not required or bypass=1.
  Field: POSTDIVPD
  offset: 3, size: 1, access: read-write
  PLL post divider powerdown

 To save power set high when PLL output not required or bypass=1.
  Field: DSMPD
  offset: 2, size: 1, access: read-write
  PLL DSM powerdown

 Nothing is achieved by setting this low.
  Field: PD
  offset: 0, size: 1, access: read-write
  PLL powerdown

 To save power set high when PLL output not required.
*/
volatile uint32_t PWR;

/** FBDIV_INT (offset: 0x8)
  Feedback divisor

 (note: this PLL does not support fractional division)
  access : read-write
  reset value : 0x0
  reset mask : 0x0
  Field: FBDIV_INT
  offset: 0, size: 12, access: read-write
  see ctrl reg description for constraints
*/
volatile uint32_t FBDIV_INT;

/** PRIM (offset: 0xc)
  Controls the PLL post dividers for the primary output

 (note: this PLL does not have a secondary output)

 the primary output is driven from VCO divided by postdiv1*postdiv2
  access : read-write
  reset value : 0x77000
  reset mask : 0x0
  Field: POSTDIV1
  offset: 16, size: 3, access: read-write
  divide by 1-7
  Field: POSTDIV2
  offset: 12, size: 3, access: read-write
  divide by 1-7
*/
volatile uint32_t PRIM;
} PLL_type;

#define PLL_SYS ((PLL_type *) 0x40028000)
#define PLL_USB ((PLL_type *) 0x4002C000)

#endif // HW_PLL_H
