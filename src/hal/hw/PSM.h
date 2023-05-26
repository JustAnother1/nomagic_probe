#ifndef HW_PSM_H
#define HW_PSM_H
/** Memory Block starting at 0x40010000 + 0x0 is 0x1000 bytes in size. It is used for registers. Protection: n */

#include <stdint.h>

typedef struct
{

/** FRCE_ON (offset: 0x0)
  Force block out of reset (i.e. power it on)
  access : read-write
  reset value : 0x0
  reset mask : 0x0
  Field: proc1
  offset: 16, size: 1, access: read-write
  Field: proc0
  offset: 15, size: 1, access: read-write
  Field: sio
  offset: 14, size: 1, access: read-write
  Field: vreg_and_chip_reset
  offset: 13, size: 1, access: read-write
  Field: xip
  offset: 12, size: 1, access: read-write
  Field: sram5
  offset: 11, size: 1, access: read-write
  Field: sram4
  offset: 10, size: 1, access: read-write
  Field: sram3
  offset: 9, size: 1, access: read-write
  Field: sram2
  offset: 8, size: 1, access: read-write
  Field: sram1
  offset: 7, size: 1, access: read-write
  Field: sram0
  offset: 6, size: 1, access: read-write
  Field: rom
  offset: 5, size: 1, access: read-write
  Field: busfabric
  offset: 4, size: 1, access: read-write
  Field: resets
  offset: 3, size: 1, access: read-write
  Field: clocks
  offset: 2, size: 1, access: read-write
  Field: xosc
  offset: 1, size: 1, access: read-write
  Field: rosc
  offset: 0, size: 1, access: read-write
*/
volatile uint32_t FRCE_ON;

/** FRCE_OFF (offset: 0x4)
  Force into reset (i.e. power it off)
  access : read-write
  reset value : 0x0
  reset mask : 0x0
  Field: proc1
  offset: 16, size: 1, access: read-write
  Field: proc0
  offset: 15, size: 1, access: read-write
  Field: sio
  offset: 14, size: 1, access: read-write
  Field: vreg_and_chip_reset
  offset: 13, size: 1, access: read-write
  Field: xip
  offset: 12, size: 1, access: read-write
  Field: sram5
  offset: 11, size: 1, access: read-write
  Field: sram4
  offset: 10, size: 1, access: read-write
  Field: sram3
  offset: 9, size: 1, access: read-write
  Field: sram2
  offset: 8, size: 1, access: read-write
  Field: sram1
  offset: 7, size: 1, access: read-write
  Field: sram0
  offset: 6, size: 1, access: read-write
  Field: rom
  offset: 5, size: 1, access: read-write
  Field: busfabric
  offset: 4, size: 1, access: read-write
  Field: resets
  offset: 3, size: 1, access: read-write
  Field: clocks
  offset: 2, size: 1, access: read-write
  Field: xosc
  offset: 1, size: 1, access: read-write
  Field: rosc
  offset: 0, size: 1, access: read-write
*/
volatile uint32_t FRCE_OFF;

/** WDSEL (offset: 0x8)
  Set to 1 if this peripheral should be reset when the watchdog fires.
  access : read-write
  reset value : 0x0
  reset mask : 0x0
  Field: proc1
  offset: 16, size: 1, access: read-write
  Field: proc0
  offset: 15, size: 1, access: read-write
  Field: sio
  offset: 14, size: 1, access: read-write
  Field: vreg_and_chip_reset
  offset: 13, size: 1, access: read-write
  Field: xip
  offset: 12, size: 1, access: read-write
  Field: sram5
  offset: 11, size: 1, access: read-write
  Field: sram4
  offset: 10, size: 1, access: read-write
  Field: sram3
  offset: 9, size: 1, access: read-write
  Field: sram2
  offset: 8, size: 1, access: read-write
  Field: sram1
  offset: 7, size: 1, access: read-write
  Field: sram0
  offset: 6, size: 1, access: read-write
  Field: rom
  offset: 5, size: 1, access: read-write
  Field: busfabric
  offset: 4, size: 1, access: read-write
  Field: resets
  offset: 3, size: 1, access: read-write
  Field: clocks
  offset: 2, size: 1, access: read-write
  Field: xosc
  offset: 1, size: 1, access: read-write
  Field: rosc
  offset: 0, size: 1, access: read-write
*/
volatile uint32_t WDSEL;

/** DONE (offset: 0xc)
  Indicates the peripheral&apos;s registers are ready to access.
  access : read-write
  reset value : 0x0
  reset mask : 0x0
  Field: proc1
  offset: 16, size: 1, access: read-only
  Field: proc0
  offset: 15, size: 1, access: read-only
  Field: sio
  offset: 14, size: 1, access: read-only
  Field: vreg_and_chip_reset
  offset: 13, size: 1, access: read-only
  Field: xip
  offset: 12, size: 1, access: read-only
  Field: sram5
  offset: 11, size: 1, access: read-only
  Field: sram4
  offset: 10, size: 1, access: read-only
  Field: sram3
  offset: 9, size: 1, access: read-only
  Field: sram2
  offset: 8, size: 1, access: read-only
  Field: sram1
  offset: 7, size: 1, access: read-only
  Field: sram0
  offset: 6, size: 1, access: read-only
  Field: rom
  offset: 5, size: 1, access: read-only
  Field: busfabric
  offset: 4, size: 1, access: read-only
  Field: resets
  offset: 3, size: 1, access: read-only
  Field: clocks
  offset: 2, size: 1, access: read-only
  Field: xosc
  offset: 1, size: 1, access: read-only
  Field: rosc
  offset: 0, size: 1, access: read-only
*/
volatile uint32_t DONE;
} PSM_type;

#define PSM ((PSM_type *) 0x40010000)

#endif // HW_PSM_H
