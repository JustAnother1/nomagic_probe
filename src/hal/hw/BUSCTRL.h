#ifndef HW_BUSCTRL_H
#define HW_BUSCTRL_H
/** Register block for busfabric control signals and performance counters */
/** Memory Block starting at 0x40030000 + 0x0 is 0x1000 bytes in size. It is used for registers. Protection: n */

#include <stdint.h>


#define BUSCTRL_BUS_PRIORITY_DMA_W_OFFSET                  12u
#define BUSCTRL_BUS_PRIORITY_DMA_W_MASK                    0x1000u

#define BUSCTRL_BUS_PRIORITY_DMA_R_OFFSET                  8u
#define BUSCTRL_BUS_PRIORITY_DMA_R_MASK                    0x100u

#define BUSCTRL_BUS_PRIORITY_PROC1_OFFSET                  4u
#define BUSCTRL_BUS_PRIORITY_PROC1_MASK                    0x10u

#define BUSCTRL_BUS_PRIORITY_PROC0_OFFSET                  0u
#define BUSCTRL_BUS_PRIORITY_PROC0_MASK                    1u

#define BUSCTRL_BUS_PRIORITY_ACK_BUS_PRIORITY_ACK_OFFSET   0u
#define BUSCTRL_BUS_PRIORITY_ACK_BUS_PRIORITY_ACK_MASK     1u

#define BUSCTRL_PERFCTR0_PERFCTR0_OFFSET                   0u
#define BUSCTRL_PERFCTR0_PERFCTR0_MASK                     0xffffffu

#define BUSCTRL_PERFSEL0_PERFSEL0_OFFSET                   0u
#define BUSCTRL_PERFSEL0_PERFSEL0_MASK                     0x1fu
#define BUSCTRL_PERFSEL0_PERFSEL0_apb_contested            0u
#define BUSCTRL_PERFSEL0_PERFSEL0_apb                      1u
#define BUSCTRL_PERFSEL0_PERFSEL0_fastperi_contested       2u
#define BUSCTRL_PERFSEL0_PERFSEL0_fastperi                 3u
#define BUSCTRL_PERFSEL0_PERFSEL0_sram5_contested          4u
#define BUSCTRL_PERFSEL0_PERFSEL0_sram5                    5u
#define BUSCTRL_PERFSEL0_PERFSEL0_sram4_contested          6u
#define BUSCTRL_PERFSEL0_PERFSEL0_sram4                    7u
#define BUSCTRL_PERFSEL0_PERFSEL0_sram3_contested          8u
#define BUSCTRL_PERFSEL0_PERFSEL0_sram3                    9u
#define BUSCTRL_PERFSEL0_PERFSEL0_sram2_contested          0xau
#define BUSCTRL_PERFSEL0_PERFSEL0_sram2                    0xbu
#define BUSCTRL_PERFSEL0_PERFSEL0_sram1_contested          0xcu
#define BUSCTRL_PERFSEL0_PERFSEL0_sram1                    0xdu
#define BUSCTRL_PERFSEL0_PERFSEL0_sram0_contested          0xeu
#define BUSCTRL_PERFSEL0_PERFSEL0_sram0                    0xfu
#define BUSCTRL_PERFSEL0_PERFSEL0_xip_main_contested       0x10u
#define BUSCTRL_PERFSEL0_PERFSEL0_xip_main                 0x11u
#define BUSCTRL_PERFSEL0_PERFSEL0_rom_contested            0x12u
#define BUSCTRL_PERFSEL0_PERFSEL0_rom                      0x13u

#define BUSCTRL_PERFCTR1_PERFCTR1_OFFSET                   0u
#define BUSCTRL_PERFCTR1_PERFCTR1_MASK                     0xffffffu

#define BUSCTRL_PERFSEL1_PERFSEL1_OFFSET                   0u
#define BUSCTRL_PERFSEL1_PERFSEL1_MASK                     0x1fu
#define BUSCTRL_PERFSEL1_PERFSEL1_apb_contested            0u
#define BUSCTRL_PERFSEL1_PERFSEL1_apb                      1u
#define BUSCTRL_PERFSEL1_PERFSEL1_fastperi_contested       2u
#define BUSCTRL_PERFSEL1_PERFSEL1_fastperi                 3u
#define BUSCTRL_PERFSEL1_PERFSEL1_sram5_contested          4u
#define BUSCTRL_PERFSEL1_PERFSEL1_sram5                    5u
#define BUSCTRL_PERFSEL1_PERFSEL1_sram4_contested          6u
#define BUSCTRL_PERFSEL1_PERFSEL1_sram4                    7u
#define BUSCTRL_PERFSEL1_PERFSEL1_sram3_contested          8u
#define BUSCTRL_PERFSEL1_PERFSEL1_sram3                    9u
#define BUSCTRL_PERFSEL1_PERFSEL1_sram2_contested          0xau
#define BUSCTRL_PERFSEL1_PERFSEL1_sram2                    0xbu
#define BUSCTRL_PERFSEL1_PERFSEL1_sram1_contested          0xcu
#define BUSCTRL_PERFSEL1_PERFSEL1_sram1                    0xdu
#define BUSCTRL_PERFSEL1_PERFSEL1_sram0_contested          0xeu
#define BUSCTRL_PERFSEL1_PERFSEL1_sram0                    0xfu
#define BUSCTRL_PERFSEL1_PERFSEL1_xip_main_contested       0x10u
#define BUSCTRL_PERFSEL1_PERFSEL1_xip_main                 0x11u
#define BUSCTRL_PERFSEL1_PERFSEL1_rom_contested            0x12u
#define BUSCTRL_PERFSEL1_PERFSEL1_rom                      0x13u

#define BUSCTRL_PERFCTR2_PERFCTR2_OFFSET                   0u
#define BUSCTRL_PERFCTR2_PERFCTR2_MASK                     0xffffffu

#define BUSCTRL_PERFSEL2_PERFSEL2_OFFSET                   0u
#define BUSCTRL_PERFSEL2_PERFSEL2_MASK                     0x1fu
#define BUSCTRL_PERFSEL2_PERFSEL2_apb_contested            0u
#define BUSCTRL_PERFSEL2_PERFSEL2_apb                      1u
#define BUSCTRL_PERFSEL2_PERFSEL2_fastperi_contested       2u
#define BUSCTRL_PERFSEL2_PERFSEL2_fastperi                 3u
#define BUSCTRL_PERFSEL2_PERFSEL2_sram5_contested          4u
#define BUSCTRL_PERFSEL2_PERFSEL2_sram5                    5u
#define BUSCTRL_PERFSEL2_PERFSEL2_sram4_contested          6u
#define BUSCTRL_PERFSEL2_PERFSEL2_sram4                    7u
#define BUSCTRL_PERFSEL2_PERFSEL2_sram3_contested          8u
#define BUSCTRL_PERFSEL2_PERFSEL2_sram3                    9u
#define BUSCTRL_PERFSEL2_PERFSEL2_sram2_contested          0xau
#define BUSCTRL_PERFSEL2_PERFSEL2_sram2                    0xbu
#define BUSCTRL_PERFSEL2_PERFSEL2_sram1_contested          0xcu
#define BUSCTRL_PERFSEL2_PERFSEL2_sram1                    0xdu
#define BUSCTRL_PERFSEL2_PERFSEL2_sram0_contested          0xeu
#define BUSCTRL_PERFSEL2_PERFSEL2_sram0                    0xfu
#define BUSCTRL_PERFSEL2_PERFSEL2_xip_main_contested       0x10u
#define BUSCTRL_PERFSEL2_PERFSEL2_xip_main                 0x11u
#define BUSCTRL_PERFSEL2_PERFSEL2_rom_contested            0x12u
#define BUSCTRL_PERFSEL2_PERFSEL2_rom                      0x13u

#define BUSCTRL_PERFCTR3_PERFCTR3_OFFSET                   0u
#define BUSCTRL_PERFCTR3_PERFCTR3_MASK                     0xffffffu

#define BUSCTRL_PERFSEL3_PERFSEL3_OFFSET                   0u
#define BUSCTRL_PERFSEL3_PERFSEL3_MASK                     0x1fu
#define BUSCTRL_PERFSEL3_PERFSEL3_apb_contested            0u
#define BUSCTRL_PERFSEL3_PERFSEL3_apb                      1u
#define BUSCTRL_PERFSEL3_PERFSEL3_fastperi_contested       2u
#define BUSCTRL_PERFSEL3_PERFSEL3_fastperi                 3u
#define BUSCTRL_PERFSEL3_PERFSEL3_sram5_contested          4u
#define BUSCTRL_PERFSEL3_PERFSEL3_sram5                    5u
#define BUSCTRL_PERFSEL3_PERFSEL3_sram4_contested          6u
#define BUSCTRL_PERFSEL3_PERFSEL3_sram4                    7u
#define BUSCTRL_PERFSEL3_PERFSEL3_sram3_contested          8u
#define BUSCTRL_PERFSEL3_PERFSEL3_sram3                    9u
#define BUSCTRL_PERFSEL3_PERFSEL3_sram2_contested          0xau
#define BUSCTRL_PERFSEL3_PERFSEL3_sram2                    0xbu
#define BUSCTRL_PERFSEL3_PERFSEL3_sram1_contested          0xcu
#define BUSCTRL_PERFSEL3_PERFSEL3_sram1                    0xdu
#define BUSCTRL_PERFSEL3_PERFSEL3_sram0_contested          0xeu
#define BUSCTRL_PERFSEL3_PERFSEL3_sram0                    0xfu
#define BUSCTRL_PERFSEL3_PERFSEL3_xip_main_contested       0x10u
#define BUSCTRL_PERFSEL3_PERFSEL3_xip_main                 0x11u
#define BUSCTRL_PERFSEL3_PERFSEL3_rom_contested            0x12u
#define BUSCTRL_PERFSEL3_PERFSEL3_rom                      0x13u


typedef struct
{

/** BUS_PRIORITY (offset: 0x0)
  Set the priority of each master for bus arbitration.
  access : read-write
  reset value : 0x0
  reset mask : 0x0
  Field: DMA_W
  offset: 12, size: 1, access: read-write
  0 - low priority, 1 - high priority
  Field: DMA_R
  offset: 8, size: 1, access: read-write
  0 - low priority, 1 - high priority
  Field: PROC1
  offset: 4, size: 1, access: read-write
  0 - low priority, 1 - high priority
  Field: PROC0
  offset: 0, size: 1, access: read-write
  0 - low priority, 1 - high priority
*/
volatile uint32_t BUS_PRIORITY;

/** BUS_PRIORITY_ACK (offset: 0x4)
  Bus priority acknowledge
  access : read-write
  reset value : 0x0
  reset mask : 0x0
  Field: BUS_PRIORITY_ACK
  offset: 0, size: 1, access: read-only
  Goes to 1 once all arbiters have registered the new global priority levels.

 Arbiters update their local priority when servicing a new nonsequential access.

 In normal circumstances this will happen almost immediately.
*/
volatile uint32_t BUS_PRIORITY_ACK;

/** PERFCTR0 (offset: 0x8)
  Bus fabric performance counter 0
  access : read-write
  reset value : 0x0
  reset mask : 0x0
  Field: PERFCTR0
  offset: 0, size: 24, access: read-write
  Busfabric saturating performance counter 0

 Count some event signal from the busfabric arbiters.

 Write any value to clear. Select an event to count using PERFSEL0
*/
volatile uint32_t PERFCTR0;

/** PERFSEL0 (offset: 0xc)
  Bus fabric performance event select for PERFCTR0
  access : read-write
  reset value : 0x1F
  reset mask : 0x0
  Field: PERFSEL0
  offset: 0, size: 5, access: read-write
  Select an event for PERFCTR0. Count either contested accesses, or all accesses, on a downstream port of the main crossbar.
  Enum:
  Value: 0 - apb_contested
  Value: 1 - apb
  Value: 2 - fastperi_contested
  Value: 3 - fastperi
  Value: 4 - sram5_contested
  Value: 5 - sram5
  Value: 6 - sram4_contested
  Value: 7 - sram4
  Value: 8 - sram3_contested
  Value: 9 - sram3
  Value: 0xa - sram2_contested
  Value: 0xb - sram2
  Value: 0xc - sram1_contested
  Value: 0xd - sram1
  Value: 0xe - sram0_contested
  Value: 0xf - sram0
  Value: 0x10 - xip_main_contested
  Value: 0x11 - xip_main
  Value: 0x12 - rom_contested
  Value: 0x13 - rom
*/
volatile uint32_t PERFSEL0;

/** PERFCTR1 (offset: 0x10)
  Bus fabric performance counter 1
  access : read-write
  reset value : 0x0
  reset mask : 0x0
  Field: PERFCTR1
  offset: 0, size: 24, access: read-write
  Busfabric saturating performance counter 1

 Count some event signal from the busfabric arbiters.

 Write any value to clear. Select an event to count using PERFSEL1
*/
volatile uint32_t PERFCTR1;

/** PERFSEL1 (offset: 0x14)
  Bus fabric performance event select for PERFCTR1
  access : read-write
  reset value : 0x1F
  reset mask : 0x0
  Field: PERFSEL1
  offset: 0, size: 5, access: read-write
  Select an event for PERFCTR1. Count either contested accesses, or all accesses, on a downstream port of the main crossbar.
  Enum:
  Value: 0 - apb_contested
  Value: 1 - apb
  Value: 2 - fastperi_contested
  Value: 3 - fastperi
  Value: 4 - sram5_contested
  Value: 5 - sram5
  Value: 6 - sram4_contested
  Value: 7 - sram4
  Value: 8 - sram3_contested
  Value: 9 - sram3
  Value: 0xa - sram2_contested
  Value: 0xb - sram2
  Value: 0xc - sram1_contested
  Value: 0xd - sram1
  Value: 0xe - sram0_contested
  Value: 0xf - sram0
  Value: 0x10 - xip_main_contested
  Value: 0x11 - xip_main
  Value: 0x12 - rom_contested
  Value: 0x13 - rom
*/
volatile uint32_t PERFSEL1;

/** PERFCTR2 (offset: 0x18)
  Bus fabric performance counter 2
  access : read-write
  reset value : 0x0
  reset mask : 0x0
  Field: PERFCTR2
  offset: 0, size: 24, access: read-write
  Busfabric saturating performance counter 2

 Count some event signal from the busfabric arbiters.

 Write any value to clear. Select an event to count using PERFSEL2
*/
volatile uint32_t PERFCTR2;

/** PERFSEL2 (offset: 0x1c)
  Bus fabric performance event select for PERFCTR2
  access : read-write
  reset value : 0x1F
  reset mask : 0x0
  Field: PERFSEL2
  offset: 0, size: 5, access: read-write
  Select an event for PERFCTR2. Count either contested accesses, or all accesses, on a downstream port of the main crossbar.
  Enum:
  Value: 0 - apb_contested
  Value: 1 - apb
  Value: 2 - fastperi_contested
  Value: 3 - fastperi
  Value: 4 - sram5_contested
  Value: 5 - sram5
  Value: 6 - sram4_contested
  Value: 7 - sram4
  Value: 8 - sram3_contested
  Value: 9 - sram3
  Value: 0xa - sram2_contested
  Value: 0xb - sram2
  Value: 0xc - sram1_contested
  Value: 0xd - sram1
  Value: 0xe - sram0_contested
  Value: 0xf - sram0
  Value: 0x10 - xip_main_contested
  Value: 0x11 - xip_main
  Value: 0x12 - rom_contested
  Value: 0x13 - rom
*/
volatile uint32_t PERFSEL2;

/** PERFCTR3 (offset: 0x20)
  Bus fabric performance counter 3
  access : read-write
  reset value : 0x0
  reset mask : 0x0
  Field: PERFCTR3
  offset: 0, size: 24, access: read-write
  Busfabric saturating performance counter 3

 Count some event signal from the busfabric arbiters.

 Write any value to clear. Select an event to count using PERFSEL3
*/
volatile uint32_t PERFCTR3;

/** PERFSEL3 (offset: 0x24)
  Bus fabric performance event select for PERFCTR3
  access : read-write
  reset value : 0x1F
  reset mask : 0x0
  Field: PERFSEL3
  offset: 0, size: 5, access: read-write
  Select an event for PERFCTR3. Count either contested accesses, or all accesses, on a downstream port of the main crossbar.
  Enum:
  Value: 0 - apb_contested
  Value: 1 - apb
  Value: 2 - fastperi_contested
  Value: 3 - fastperi
  Value: 4 - sram5_contested
  Value: 5 - sram5
  Value: 6 - sram4_contested
  Value: 7 - sram4
  Value: 8 - sram3_contested
  Value: 9 - sram3
  Value: 0xa - sram2_contested
  Value: 0xb - sram2
  Value: 0xc - sram1_contested
  Value: 0xd - sram1
  Value: 0xe - sram0_contested
  Value: 0xf - sram0
  Value: 0x10 - xip_main_contested
  Value: 0x11 - xip_main
  Value: 0x12 - rom_contested
  Value: 0x13 - rom
*/
volatile uint32_t PERFSEL3;
} BUSCTRL_type;

#define BUSCTRL ((BUSCTRL_type *) 0x40030000)

#endif // HW_BUSCTRL_H
