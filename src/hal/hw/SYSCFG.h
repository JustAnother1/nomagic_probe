/*
  automatically created from data available on https://chipselect.org/
*/
#ifndef HW_SYSCFG_H
#define HW_SYSCFG_H
/** Register block for various chip control signals */
/** Memory Block starting at 0x40004000 + 0x0 is 0x1000 bytes in size. It is used for registers. Protection: n */

#include <stdint.h>


#define SYSCFG_PROC_CONFIG_PROC1_DAP_INSTID_OFFSET         28u
#define SYSCFG_PROC_CONFIG_PROC1_DAP_INSTID_MASK           0xf0000000u

#define SYSCFG_PROC_CONFIG_PROC0_DAP_INSTID_OFFSET         24u
#define SYSCFG_PROC_CONFIG_PROC0_DAP_INSTID_MASK           0xf000000u

#define SYSCFG_PROC_CONFIG_PROC1_HALTED_OFFSET             1u
#define SYSCFG_PROC_CONFIG_PROC1_HALTED_MASK               2u

#define SYSCFG_PROC_CONFIG_PROC0_HALTED_OFFSET             0u
#define SYSCFG_PROC_CONFIG_PROC0_HALTED_MASK               1u

#define SYSCFG_PROC_IN_SYNC_BYPASS_PROC_IN_SYNC_BYPASS_OFFSET   0u
#define SYSCFG_PROC_IN_SYNC_BYPASS_PROC_IN_SYNC_BYPASS_MASK   0x3fffffffu

#define SYSCFG_PROC_IN_SYNC_BYPASS_HI_PROC_IN_SYNC_BYPASS_HI_OFFSET   0u
#define SYSCFG_PROC_IN_SYNC_BYPASS_HI_PROC_IN_SYNC_BYPASS_HI_MASK   0x3fu

#define SYSCFG_DBGFORCE_PROC1_ATTACH_OFFSET                7u
#define SYSCFG_DBGFORCE_PROC1_ATTACH_MASK                  0x80u

#define SYSCFG_DBGFORCE_PROC1_SWCLK_OFFSET                 6u
#define SYSCFG_DBGFORCE_PROC1_SWCLK_MASK                   0x40u

#define SYSCFG_DBGFORCE_PROC1_SWDI_OFFSET                  5u
#define SYSCFG_DBGFORCE_PROC1_SWDI_MASK                    0x20u

#define SYSCFG_DBGFORCE_PROC1_SWDO_OFFSET                  4u
#define SYSCFG_DBGFORCE_PROC1_SWDO_MASK                    0x10u

#define SYSCFG_DBGFORCE_PROC0_ATTACH_OFFSET                3u
#define SYSCFG_DBGFORCE_PROC0_ATTACH_MASK                  8u

#define SYSCFG_DBGFORCE_PROC0_SWCLK_OFFSET                 2u
#define SYSCFG_DBGFORCE_PROC0_SWCLK_MASK                   4u

#define SYSCFG_DBGFORCE_PROC0_SWDI_OFFSET                  1u
#define SYSCFG_DBGFORCE_PROC0_SWDI_MASK                    2u

#define SYSCFG_DBGFORCE_PROC0_SWDO_OFFSET                  0u
#define SYSCFG_DBGFORCE_PROC0_SWDO_MASK                    1u

#define SYSCFG_MEMPOWERDOWN_ROM_OFFSET                     7u
#define SYSCFG_MEMPOWERDOWN_ROM_MASK                       0x80u

#define SYSCFG_MEMPOWERDOWN_USB_OFFSET                     6u
#define SYSCFG_MEMPOWERDOWN_USB_MASK                       0x40u

#define SYSCFG_MEMPOWERDOWN_SRAM5_OFFSET                   5u
#define SYSCFG_MEMPOWERDOWN_SRAM5_MASK                     0x20u

#define SYSCFG_MEMPOWERDOWN_SRAM4_OFFSET                   4u
#define SYSCFG_MEMPOWERDOWN_SRAM4_MASK                     0x10u

#define SYSCFG_MEMPOWERDOWN_SRAM3_OFFSET                   3u
#define SYSCFG_MEMPOWERDOWN_SRAM3_MASK                     8u

#define SYSCFG_MEMPOWERDOWN_SRAM2_OFFSET                   2u
#define SYSCFG_MEMPOWERDOWN_SRAM2_MASK                     4u

#define SYSCFG_MEMPOWERDOWN_SRAM1_OFFSET                   1u
#define SYSCFG_MEMPOWERDOWN_SRAM1_MASK                     2u

#define SYSCFG_MEMPOWERDOWN_SRAM0_OFFSET                   0u
#define SYSCFG_MEMPOWERDOWN_SRAM0_MASK                     1u


typedef struct
{

/** PROC0_NMI_MASK (offset: 0x0)
  Processor core 0 NMI source mask

 Set a bit high to enable NMI from that IRQ
  access : read-write
  reset value : 0x0
  reset mask : 0x0
*/
volatile uint32_t PROC0_NMI_MASK;

/** PROC1_NMI_MASK (offset: 0x4)
  Processor core 1 NMI source mask

 Set a bit high to enable NMI from that IRQ
  access : read-write
  reset value : 0x0
  reset mask : 0x0
*/
volatile uint32_t PROC1_NMI_MASK;

/** PROC_CONFIG (offset: 0x8)
  Configuration for processors
  access : read-write
  reset value : 0x10000000
  reset mask : 0x0
  Field: PROC1_DAP_INSTID
  offset: 28, size: 4, access: read-write
  Configure proc1 DAP instance ID.

 Recommend that this is NOT changed until you require debug access in multi-chip environment

 WARNING: do not set to 15 as this is reserved for RescueDP
  Field: PROC0_DAP_INSTID
  offset: 24, size: 4, access: read-write
  Configure proc0 DAP instance ID.

 Recommend that this is NOT changed until you require debug access in multi-chip environment

 WARNING: do not set to 15 as this is reserved for RescueDP
  Field: PROC1_HALTED
  offset: 1, size: 1, access: read-only
  Indication that proc1 has halted
  Field: PROC0_HALTED
  offset: 0, size: 1, access: read-only
  Indication that proc0 has halted
*/
volatile uint32_t PROC_CONFIG;

/** PROC_IN_SYNC_BYPASS (offset: 0xc)
  For each bit, if 1, bypass the input synchronizer between that GPIO

 and the GPIO input register in the SIO. The input synchronizers should

 generally be unbypassed, to avoid injecting metastabilities into processors.

 If you&apos;re feeling brave, you can bypass to save two cycles of input

 latency. This register applies to GPIO 0...29.
  access : read-write
  reset value : 0x0
  reset mask : 0x0
  Field: PROC_IN_SYNC_BYPASS
  offset: 0, size: 30, access: read-write
*/
volatile uint32_t PROC_IN_SYNC_BYPASS;

/** PROC_IN_SYNC_BYPASS_HI (offset: 0x10)
  For each bit, if 1, bypass the input synchronizer between that GPIO

 and the GPIO input register in the SIO. The input synchronizers should

 generally be unbypassed, to avoid injecting metastabilities into processors.

 If you&apos;re feeling brave, you can bypass to save two cycles of input

 latency. This register applies to GPIO 30...35 (the QSPI IOs).
  access : read-write
  reset value : 0x0
  reset mask : 0x0
  Field: PROC_IN_SYNC_BYPASS_HI
  offset: 0, size: 6, access: read-write
*/
volatile uint32_t PROC_IN_SYNC_BYPASS_HI;

/** DBGFORCE (offset: 0x14)
  Directly control the SWD debug port of either processor
  access : read-write
  reset value : 0x66
  reset mask : 0x0
  Field: PROC1_ATTACH
  offset: 7, size: 1, access: read-write
  Attach processor 1 debug port to syscfg controls, and disconnect it from external SWD pads.
  Field: PROC1_SWCLK
  offset: 6, size: 1, access: read-write
  Directly drive processor 1 SWCLK, if PROC1_ATTACH is set
  Field: PROC1_SWDI
  offset: 5, size: 1, access: read-write
  Directly drive processor 1 SWDIO input, if PROC1_ATTACH is set
  Field: PROC1_SWDO
  offset: 4, size: 1, access: read-only
  Observe the value of processor 1 SWDIO output.
  Field: PROC0_ATTACH
  offset: 3, size: 1, access: read-write
  Attach processor 0 debug port to syscfg controls, and disconnect it from external SWD pads.
  Field: PROC0_SWCLK
  offset: 2, size: 1, access: read-write
  Directly drive processor 0 SWCLK, if PROC0_ATTACH is set
  Field: PROC0_SWDI
  offset: 1, size: 1, access: read-write
  Directly drive processor 0 SWDIO input, if PROC0_ATTACH is set
  Field: PROC0_SWDO
  offset: 0, size: 1, access: read-only
  Observe the value of processor 0 SWDIO output.
*/
volatile uint32_t DBGFORCE;

/** MEMPOWERDOWN (offset: 0x18)
  Control power downs to memories. Set high to power down memories.

 Use with extreme caution
  access : read-write
  reset value : 0x0
  reset mask : 0x0
  Field: ROM
  offset: 7, size: 1, access: read-write
  Field: USB
  offset: 6, size: 1, access: read-write
  Field: SRAM5
  offset: 5, size: 1, access: read-write
  Field: SRAM4
  offset: 4, size: 1, access: read-write
  Field: SRAM3
  offset: 3, size: 1, access: read-write
  Field: SRAM2
  offset: 2, size: 1, access: read-write
  Field: SRAM1
  offset: 1, size: 1, access: read-write
  Field: SRAM0
  offset: 0, size: 1, access: read-write
*/
volatile uint32_t MEMPOWERDOWN;
} SYSCFG_type;

#define SYSCFG ((SYSCFG_type *) 0x40004000)

#endif // HW_SYSCFG_H
