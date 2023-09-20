#ifndef HW_PSM_H
#define HW_PSM_H
/** Memory Block starting at 0x40010000 + 0x0 is 0x1000 bytes in size. It is used for registers. Protection: n */

#include <stdint.h>


#define PSM_FRCE_ON_PROC1_OFFSET                           16
#define PSM_FRCE_ON_PROC1_MASK                             0x10000

#define PSM_FRCE_ON_PROC0_OFFSET                           15
#define PSM_FRCE_ON_PROC0_MASK                             0x8000

#define PSM_FRCE_ON_SIO_OFFSET                             14
#define PSM_FRCE_ON_SIO_MASK                               0x4000

#define PSM_FRCE_ON_VREG_AND_CHIP_RESET_OFFSET             13
#define PSM_FRCE_ON_VREG_AND_CHIP_RESET_MASK               0x2000

#define PSM_FRCE_ON_XIP_OFFSET                             12
#define PSM_FRCE_ON_XIP_MASK                               0x1000

#define PSM_FRCE_ON_SRAM5_OFFSET                           11
#define PSM_FRCE_ON_SRAM5_MASK                             0x800

#define PSM_FRCE_ON_SRAM4_OFFSET                           10
#define PSM_FRCE_ON_SRAM4_MASK                             0x400

#define PSM_FRCE_ON_SRAM3_OFFSET                           9
#define PSM_FRCE_ON_SRAM3_MASK                             0x200

#define PSM_FRCE_ON_SRAM2_OFFSET                           8
#define PSM_FRCE_ON_SRAM2_MASK                             0x100

#define PSM_FRCE_ON_SRAM1_OFFSET                           7
#define PSM_FRCE_ON_SRAM1_MASK                             0x80

#define PSM_FRCE_ON_SRAM0_OFFSET                           6
#define PSM_FRCE_ON_SRAM0_MASK                             0x40

#define PSM_FRCE_ON_ROM_OFFSET                             5
#define PSM_FRCE_ON_ROM_MASK                               0x20

#define PSM_FRCE_ON_BUSFABRIC_OFFSET                       4
#define PSM_FRCE_ON_BUSFABRIC_MASK                         0x10

#define PSM_FRCE_ON_RESETS_OFFSET                          3
#define PSM_FRCE_ON_RESETS_MASK                            8

#define PSM_FRCE_ON_CLOCKS_OFFSET                          2
#define PSM_FRCE_ON_CLOCKS_MASK                            4

#define PSM_FRCE_ON_XOSC_OFFSET                            1
#define PSM_FRCE_ON_XOSC_MASK                              2

#define PSM_FRCE_ON_ROSC_OFFSET                            0
#define PSM_FRCE_ON_ROSC_MASK                              1

#define PSM_FRCE_OFF_PROC1_OFFSET                          16
#define PSM_FRCE_OFF_PROC1_MASK                            0x10000

#define PSM_FRCE_OFF_PROC0_OFFSET                          15
#define PSM_FRCE_OFF_PROC0_MASK                            0x8000

#define PSM_FRCE_OFF_SIO_OFFSET                            14
#define PSM_FRCE_OFF_SIO_MASK                              0x4000

#define PSM_FRCE_OFF_VREG_AND_CHIP_RESET_OFFSET            13
#define PSM_FRCE_OFF_VREG_AND_CHIP_RESET_MASK              0x2000

#define PSM_FRCE_OFF_XIP_OFFSET                            12
#define PSM_FRCE_OFF_XIP_MASK                              0x1000

#define PSM_FRCE_OFF_SRAM5_OFFSET                          11
#define PSM_FRCE_OFF_SRAM5_MASK                            0x800

#define PSM_FRCE_OFF_SRAM4_OFFSET                          10
#define PSM_FRCE_OFF_SRAM4_MASK                            0x400

#define PSM_FRCE_OFF_SRAM3_OFFSET                          9
#define PSM_FRCE_OFF_SRAM3_MASK                            0x200

#define PSM_FRCE_OFF_SRAM2_OFFSET                          8
#define PSM_FRCE_OFF_SRAM2_MASK                            0x100

#define PSM_FRCE_OFF_SRAM1_OFFSET                          7
#define PSM_FRCE_OFF_SRAM1_MASK                            0x80

#define PSM_FRCE_OFF_SRAM0_OFFSET                          6
#define PSM_FRCE_OFF_SRAM0_MASK                            0x40

#define PSM_FRCE_OFF_ROM_OFFSET                            5
#define PSM_FRCE_OFF_ROM_MASK                              0x20

#define PSM_FRCE_OFF_BUSFABRIC_OFFSET                      4
#define PSM_FRCE_OFF_BUSFABRIC_MASK                        0x10

#define PSM_FRCE_OFF_RESETS_OFFSET                         3
#define PSM_FRCE_OFF_RESETS_MASK                           8

#define PSM_FRCE_OFF_CLOCKS_OFFSET                         2
#define PSM_FRCE_OFF_CLOCKS_MASK                           4

#define PSM_FRCE_OFF_XOSC_OFFSET                           1
#define PSM_FRCE_OFF_XOSC_MASK                             2

#define PSM_FRCE_OFF_ROSC_OFFSET                           0
#define PSM_FRCE_OFF_ROSC_MASK                             1

#define PSM_WDSEL_PROC1_OFFSET                             16
#define PSM_WDSEL_PROC1_MASK                               0x10000

#define PSM_WDSEL_PROC0_OFFSET                             15
#define PSM_WDSEL_PROC0_MASK                               0x8000

#define PSM_WDSEL_SIO_OFFSET                               14
#define PSM_WDSEL_SIO_MASK                                 0x4000

#define PSM_WDSEL_VREG_AND_CHIP_RESET_OFFSET               13
#define PSM_WDSEL_VREG_AND_CHIP_RESET_MASK                 0x2000

#define PSM_WDSEL_XIP_OFFSET                               12
#define PSM_WDSEL_XIP_MASK                                 0x1000

#define PSM_WDSEL_SRAM5_OFFSET                             11
#define PSM_WDSEL_SRAM5_MASK                               0x800

#define PSM_WDSEL_SRAM4_OFFSET                             10
#define PSM_WDSEL_SRAM4_MASK                               0x400

#define PSM_WDSEL_SRAM3_OFFSET                             9
#define PSM_WDSEL_SRAM3_MASK                               0x200

#define PSM_WDSEL_SRAM2_OFFSET                             8
#define PSM_WDSEL_SRAM2_MASK                               0x100

#define PSM_WDSEL_SRAM1_OFFSET                             7
#define PSM_WDSEL_SRAM1_MASK                               0x80

#define PSM_WDSEL_SRAM0_OFFSET                             6
#define PSM_WDSEL_SRAM0_MASK                               0x40

#define PSM_WDSEL_ROM_OFFSET                               5
#define PSM_WDSEL_ROM_MASK                                 0x20

#define PSM_WDSEL_BUSFABRIC_OFFSET                         4
#define PSM_WDSEL_BUSFABRIC_MASK                           0x10

#define PSM_WDSEL_RESETS_OFFSET                            3
#define PSM_WDSEL_RESETS_MASK                              8

#define PSM_WDSEL_CLOCKS_OFFSET                            2
#define PSM_WDSEL_CLOCKS_MASK                              4

#define PSM_WDSEL_XOSC_OFFSET                              1
#define PSM_WDSEL_XOSC_MASK                                2

#define PSM_WDSEL_ROSC_OFFSET                              0
#define PSM_WDSEL_ROSC_MASK                                1

#define PSM_DONE_PROC1_OFFSET                              16
#define PSM_DONE_PROC1_MASK                                0x10000

#define PSM_DONE_PROC0_OFFSET                              15
#define PSM_DONE_PROC0_MASK                                0x8000

#define PSM_DONE_SIO_OFFSET                                14
#define PSM_DONE_SIO_MASK                                  0x4000

#define PSM_DONE_VREG_AND_CHIP_RESET_OFFSET                13
#define PSM_DONE_VREG_AND_CHIP_RESET_MASK                  0x2000

#define PSM_DONE_XIP_OFFSET                                12
#define PSM_DONE_XIP_MASK                                  0x1000

#define PSM_DONE_SRAM5_OFFSET                              11
#define PSM_DONE_SRAM5_MASK                                0x800

#define PSM_DONE_SRAM4_OFFSET                              10
#define PSM_DONE_SRAM4_MASK                                0x400

#define PSM_DONE_SRAM3_OFFSET                              9
#define PSM_DONE_SRAM3_MASK                                0x200

#define PSM_DONE_SRAM2_OFFSET                              8
#define PSM_DONE_SRAM2_MASK                                0x100

#define PSM_DONE_SRAM1_OFFSET                              7
#define PSM_DONE_SRAM1_MASK                                0x80

#define PSM_DONE_SRAM0_OFFSET                              6
#define PSM_DONE_SRAM0_MASK                                0x40

#define PSM_DONE_ROM_OFFSET                                5
#define PSM_DONE_ROM_MASK                                  0x20

#define PSM_DONE_BUSFABRIC_OFFSET                          4
#define PSM_DONE_BUSFABRIC_MASK                            0x10

#define PSM_DONE_RESETS_OFFSET                             3
#define PSM_DONE_RESETS_MASK                               8

#define PSM_DONE_CLOCKS_OFFSET                             2
#define PSM_DONE_CLOCKS_MASK                               4

#define PSM_DONE_XOSC_OFFSET                               1
#define PSM_DONE_XOSC_MASK                                 2

#define PSM_DONE_ROSC_OFFSET                               0
#define PSM_DONE_ROSC_MASK                                 1


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
