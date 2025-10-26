/*
  automatically created from data available on https://chipselect.org/
*/
#ifndef HW_WATCHDOG_H
#define HW_WATCHDOG_H
/** Memory Block starting at 0x40058000 + 0x0 is 0x1000 bytes in size. It is used for registers. Protection: n */

#include <stdint.h>


#define WATCHDOG_CTRL_TRIGGER_OFFSET                       31u
#define WATCHDOG_CTRL_TRIGGER_MASK                         0x80000000u

#define WATCHDOG_CTRL_ENABLE_OFFSET                        30u
#define WATCHDOG_CTRL_ENABLE_MASK                          0x40000000u

#define WATCHDOG_CTRL_PAUSE_DBG1_OFFSET                    26u
#define WATCHDOG_CTRL_PAUSE_DBG1_MASK                      0x4000000u

#define WATCHDOG_CTRL_PAUSE_DBG0_OFFSET                    25u
#define WATCHDOG_CTRL_PAUSE_DBG0_MASK                      0x2000000u

#define WATCHDOG_CTRL_PAUSE_JTAG_OFFSET                    24u
#define WATCHDOG_CTRL_PAUSE_JTAG_MASK                      0x1000000u

#define WATCHDOG_CTRL_TIME_OFFSET                          0u
#define WATCHDOG_CTRL_TIME_MASK                            0xffffffu

#define WATCHDOG_LOAD_LOAD_OFFSET                          0u
#define WATCHDOG_LOAD_LOAD_MASK                            0xffffffu

#define WATCHDOG_REASON_FORCE_OFFSET                       1u
#define WATCHDOG_REASON_FORCE_MASK                         2u

#define WATCHDOG_REASON_TIMER_OFFSET                       0u
#define WATCHDOG_REASON_TIMER_MASK                         1u

#define WATCHDOG_TICK_COUNT_OFFSET                         11u
#define WATCHDOG_TICK_COUNT_MASK                           0xff800u

#define WATCHDOG_TICK_RUNNING_OFFSET                       10u
#define WATCHDOG_TICK_RUNNING_MASK                         0x400u

#define WATCHDOG_TICK_ENABLE_OFFSET                        9u
#define WATCHDOG_TICK_ENABLE_MASK                          0x200u

#define WATCHDOG_TICK_CYCLES_OFFSET                        0u
#define WATCHDOG_TICK_CYCLES_MASK                          0x1ffu


typedef struct
{

/** CTRL (offset: 0x0)
  Watchdog control

 The rst_wdsel register determines which subsystems are reset when the watchdog is triggered.

 The watchdog can be triggered in software.
  access : read-write
  reset value : 0x7000000
  reset mask : 0x0
  Field: TRIGGER
  offset: 31, size: 1, access: read-write
  Trigger a watchdog reset
  Field: ENABLE
  offset: 30, size: 1, access: read-write
  When not enabled the watchdog timer is paused
  Field: PAUSE_DBG1
  offset: 26, size: 1, access: read-write
  Pause the watchdog timer when processor 1 is in debug mode
  Field: PAUSE_DBG0
  offset: 25, size: 1, access: read-write
  Pause the watchdog timer when processor 0 is in debug mode
  Field: PAUSE_JTAG
  offset: 24, size: 1, access: read-write
  Pause the watchdog timer when JTAG is accessing the bus fabric
  Field: TIME
  offset: 0, size: 24, access: read-only
  Indicates the number of ticks / 2 (see errata RP2040-E1) before a watchdog reset will be triggered
*/
volatile uint32_t CTRL;

/** LOAD (offset: 0x4)
  Load the watchdog timer. The maximum setting is 0xffffff which corresponds to 0xffffff / 2 ticks before triggering a watchdog reset (see errata RP2040-E1).
  access : read-write
  reset value : 0x0
  reset mask : 0x0
  Field: LOAD
  offset: 0, size: 24, access: write-only
*/
volatile uint32_t LOAD;

/** REASON (offset: 0x8)
  Logs the reason for the last reset. Both bits are zero for the case of a hardware reset.
  access : read-write
  reset value : 0x0
  reset mask : 0x0
  Field: FORCE
  offset: 1, size: 1, access: read-only
  Field: TIMER
  offset: 0, size: 1, access: read-only
*/
volatile uint32_t REASON;

/** SCRATCH
SCRATCH[0] (offset: 0xc)
  Scratch register. Information persists through soft reset of the chip.
  access : read-write
  reset value : 0x0
  reset mask : 0x0

SCRATCH[1] (offset: 0x10)
  Scratch register. Information persists through soft reset of the chip.
  access : read-write
  reset value : 0x0
  reset mask : 0x0

SCRATCH[2] (offset: 0x14)
  Scratch register. Information persists through soft reset of the chip.
  access : read-write
  reset value : 0x0
  reset mask : 0x0

SCRATCH[3] (offset: 0x18)
  Scratch register. Information persists through soft reset of the chip.
  access : read-write
  reset value : 0x0
  reset mask : 0x0

SCRATCH[4] (offset: 0x1c)
  Scratch register. Information persists through soft reset of the chip.
  access : read-write
  reset value : 0x0
  reset mask : 0x0

SCRATCH[5] (offset: 0x20)
  Scratch register. Information persists through soft reset of the chip.
  access : read-write
  reset value : 0x0
  reset mask : 0x0

SCRATCH[6] (offset: 0x24)
  Scratch register. Information persists through soft reset of the chip.
  access : read-write
  reset value : 0x0
  reset mask : 0x0

SCRATCH[7] (offset: 0x28)
  Scratch register. Information persists through soft reset of the chip.
  access : read-write
  reset value : 0x0
  reset mask : 0x0

*/
volatile uint32_t SCRATCH[8];

/** TICK (offset: 0x2c)
  Controls the tick generator
  access : read-write
  reset value : 0x200
  reset mask : 0x0
  Field: COUNT
  offset: 11, size: 9, access: read-only
  Count down timer: the remaining number clk_tick cycles before the next tick is generated.
  Field: RUNNING
  offset: 10, size: 1, access: read-only
  Is the tick generator running?
  Field: ENABLE
  offset: 9, size: 1, access: read-write
  start / stop tick generation
  Field: CYCLES
  offset: 0, size: 9, access: read-write
  Total number of clk_tick cycles before the next tick.
*/
volatile uint32_t TICK;
} WATCHDOG_type;

#define WATCHDOG ((WATCHDOG_type *) 0x40058000)

#endif // HW_WATCHDOG_H
