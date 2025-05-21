/*
  automatically created from data available on https://chipselect.org/
*/
#ifndef HW_VREG_AND_CHIP_RESET_H
#define HW_VREG_AND_CHIP_RESET_H
/** control and status for on-chip voltage regulator and chip level reset subsystem */
/** Memory Block starting at 0x40064000 + 0x0 is 0x1000 bytes in size. It is used for registers. Protection: n */

#include <stdint.h>


#define VREG_AND_CHIP_RESET_VREG_ROK_OFFSET                12u
#define VREG_AND_CHIP_RESET_VREG_ROK_MASK                  0x1000u

#define VREG_AND_CHIP_RESET_VREG_VSEL_OFFSET               4u
#define VREG_AND_CHIP_RESET_VREG_VSEL_MASK                 0xf0u

#define VREG_AND_CHIP_RESET_VREG_HIZ_OFFSET                1u
#define VREG_AND_CHIP_RESET_VREG_HIZ_MASK                  2u

#define VREG_AND_CHIP_RESET_VREG_EN_OFFSET                 0u
#define VREG_AND_CHIP_RESET_VREG_EN_MASK                   1u

#define VREG_AND_CHIP_RESET_BOD_VSEL_OFFSET                4u
#define VREG_AND_CHIP_RESET_BOD_VSEL_MASK                  0xf0u

#define VREG_AND_CHIP_RESET_BOD_EN_OFFSET                  0u
#define VREG_AND_CHIP_RESET_BOD_EN_MASK                    1u

#define VREG_AND_CHIP_RESET_CHIP_RESET_PSM_RESTART_FLAG_OFFSET   24u
#define VREG_AND_CHIP_RESET_CHIP_RESET_PSM_RESTART_FLAG_MASK   0x1000000u

#define VREG_AND_CHIP_RESET_CHIP_RESET_HAD_PSM_RESTART_OFFSET   20u
#define VREG_AND_CHIP_RESET_CHIP_RESET_HAD_PSM_RESTART_MASK   0x100000u

#define VREG_AND_CHIP_RESET_CHIP_RESET_HAD_RUN_OFFSET      16u
#define VREG_AND_CHIP_RESET_CHIP_RESET_HAD_RUN_MASK        0x10000u

#define VREG_AND_CHIP_RESET_CHIP_RESET_HAD_POR_OFFSET      8u
#define VREG_AND_CHIP_RESET_CHIP_RESET_HAD_POR_MASK        0x100u


typedef struct
{

/** VREG (offset: 0x0)
  Voltage regulator control and status
  access : read-write
  reset value : 0xB1
  reset mask : 0x0
  Field: ROK
  offset: 12, size: 1, access: read-only
  regulation status

 0=not in regulation, 1=in regulation
  Field: VSEL
  offset: 4, size: 4, access: read-write
  output voltage select

 0000 to 0101 - 0.80V

 0110 - 0.85V

 0111 - 0.90V

 1000 - 0.95V

 1001 - 1.00V

 1010 - 1.05V

 1011 - 1.10V (default)

 1100 - 1.15V

 1101 - 1.20V

 1110 - 1.25V

 1111 - 1.30V
  Field: HIZ
  offset: 1, size: 1, access: read-write
  high impedance mode select

 0=not in high impedance mode, 1=in high impedance mode
  Field: EN
  offset: 0, size: 1, access: read-write
  enable

 0=not enabled, 1=enabled
*/
volatile uint32_t VREG;

/** BOD (offset: 0x4)
  brown-out detection control
  access : read-write
  reset value : 0x91
  reset mask : 0x0
  Field: VSEL
  offset: 4, size: 4, access: read-write
  threshold select

 0000 - 0.473V

 0001 - 0.516V

 0010 - 0.559V

 0011 - 0.602V

 0100 - 0.645V

 0101 - 0.688V

 0110 - 0.731V

 0111 - 0.774V

 1000 - 0.817V

 1001 - 0.860V (default)

 1010 - 0.903V

 1011 - 0.946V

 1100 - 0.989V

 1101 - 1.032V

 1110 - 1.075V

 1111 - 1.118V
  Field: EN
  offset: 0, size: 1, access: read-write
  enable

 0=not enabled, 1=enabled
*/
volatile uint32_t BOD;

/** CHIP_RESET (offset: 0x8)
  Chip reset control and status
  access : read-write
  reset value : 0x0
  reset mask : 0x0
  Field: PSM_RESTART_FLAG
  offset: 24, size: 1, access: read-write
  This is set by psm_restart from the debugger.

 Its purpose is to branch bootcode to a safe mode when the debugger has issued a psm_restart in order to recover from a boot lock-up.

 In the safe mode the debugger can repair the boot code, clear this flag then reboot the processor.
  Field: HAD_PSM_RESTART
  offset: 20, size: 1, access: read-only
  Last reset was from the debug port
  Field: HAD_RUN
  offset: 16, size: 1, access: read-only
  Last reset was from the RUN pin
  Field: HAD_POR
  offset: 8, size: 1, access: read-only
  Last reset was from the power-on reset or brown-out detection blocks
*/
volatile uint32_t CHIP_RESET;
} VREG_AND_CHIP_RESET_type;

#define VREG_AND_CHIP_RESET ((VREG_AND_CHIP_RESET_type *) 0x40064000)

#endif // HW_VREG_AND_CHIP_RESET_H
