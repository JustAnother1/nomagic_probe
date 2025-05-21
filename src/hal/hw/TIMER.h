/*
  automatically created from data available on https://chipselect.org/
*/
#ifndef HW_TIMER_H
#define HW_TIMER_H
/** Controls time and alarms

 time is a 64 bit value indicating the time in usec since power-on

 timeh is the top 32 bits of time &amp; timel is the bottom 32 bits

 to change time write to timelw before timehw

 to read time read from timelr before timehr

 An alarm is set by setting alarm_enable and writing to the corresponding alarm register

 When an alarm is pending, the corresponding alarm_running signal will be high

 An alarm can be cancelled before it has finished by clearing the alarm_enable

 When an alarm fires, the corresponding alarm_irq is set and alarm_running is cleared

 To clear the interrupt write a 1 to the corresponding alarm_irq */
/** Interrupt : TIMER_IRQ_0 (Vector: 0)  */
/** Interrupt : TIMER_IRQ_1 (Vector: 1)  */
/** Interrupt : TIMER_IRQ_2 (Vector: 2)  */
/** Interrupt : TIMER_IRQ_3 (Vector: 3)  */
/** Memory Block starting at 0x40054000 + 0x0 is 0x1000 bytes in size. It is used for registers. Protection: n */

#include <stdint.h>


#define TIMER_ARMED_ARMED_OFFSET                           0u
#define TIMER_ARMED_ARMED_MASK                             0xfu

#define TIMER_DBGPAUSE_DBG1_OFFSET                         2u
#define TIMER_DBGPAUSE_DBG1_MASK                           4u

#define TIMER_DBGPAUSE_DBG0_OFFSET                         1u
#define TIMER_DBGPAUSE_DBG0_MASK                           2u

#define TIMER_PAUSE_PAUSE_OFFSET                           0u
#define TIMER_PAUSE_PAUSE_MASK                             1u

#define TIMER_INTR_ALARM_3_OFFSET                          3u
#define TIMER_INTR_ALARM_3_MASK                            8u

#define TIMER_INTR_ALARM_2_OFFSET                          2u
#define TIMER_INTR_ALARM_2_MASK                            4u

#define TIMER_INTR_ALARM_1_OFFSET                          1u
#define TIMER_INTR_ALARM_1_MASK                            2u

#define TIMER_INTR_ALARM_0_OFFSET                          0u
#define TIMER_INTR_ALARM_0_MASK                            1u

#define TIMER_INTE_ALARM_3_OFFSET                          3u
#define TIMER_INTE_ALARM_3_MASK                            8u

#define TIMER_INTE_ALARM_2_OFFSET                          2u
#define TIMER_INTE_ALARM_2_MASK                            4u

#define TIMER_INTE_ALARM_1_OFFSET                          1u
#define TIMER_INTE_ALARM_1_MASK                            2u

#define TIMER_INTE_ALARM_0_OFFSET                          0u
#define TIMER_INTE_ALARM_0_MASK                            1u

#define TIMER_INTF_ALARM_3_OFFSET                          3u
#define TIMER_INTF_ALARM_3_MASK                            8u

#define TIMER_INTF_ALARM_2_OFFSET                          2u
#define TIMER_INTF_ALARM_2_MASK                            4u

#define TIMER_INTF_ALARM_1_OFFSET                          1u
#define TIMER_INTF_ALARM_1_MASK                            2u

#define TIMER_INTF_ALARM_0_OFFSET                          0u
#define TIMER_INTF_ALARM_0_MASK                            1u

#define TIMER_INTS_ALARM_3_OFFSET                          3u
#define TIMER_INTS_ALARM_3_MASK                            8u

#define TIMER_INTS_ALARM_2_OFFSET                          2u
#define TIMER_INTS_ALARM_2_MASK                            4u

#define TIMER_INTS_ALARM_1_OFFSET                          1u
#define TIMER_INTS_ALARM_1_MASK                            2u

#define TIMER_INTS_ALARM_0_OFFSET                          0u
#define TIMER_INTS_ALARM_0_MASK                            1u


typedef struct
{

/** TIMEHW (offset: 0x0)
  Write to bits 63:32 of time

 always write timelw before timehw
  access : write-only
  reset value : 0x0
  reset mask : 0x0
*/
volatile uint32_t TIMEHW;

/** TIMELW (offset: 0x4)
  Write to bits 31:0 of time

 writes do not get copied to time until timehw is written
  access : write-only
  reset value : 0x0
  reset mask : 0x0
*/
volatile uint32_t TIMELW;

/** TIMEHR (offset: 0x8)
  Read from bits 63:32 of time

 always read timelr before timehr
  access : read-only
  reset value : 0x0
  reset mask : 0x0
*/
volatile uint32_t TIMEHR;

/** TIMELR (offset: 0xc)
  Read from bits 31:0 of time
  access : read-only
  reset value : 0x0
  reset mask : 0x0
*/
volatile uint32_t TIMELR;

/** ALARM0 (offset: 0x10)
  Arm alarm 0, and configure the time it will fire.

 Once armed, the alarm fires when TIMER_ALARM0 == TIMELR.

 The alarm will disarm itself once it fires, and can

 be disarmed early using the ARMED status register.
  access : read-write
  reset value : 0x0
  reset mask : 0x0
*/
volatile uint32_t ALARM0;

/** ALARM1 (offset: 0x14)
  Arm alarm 1, and configure the time it will fire.

 Once armed, the alarm fires when TIMER_ALARM1 == TIMELR.

 The alarm will disarm itself once it fires, and can

 be disarmed early using the ARMED status register.
  access : read-write
  reset value : 0x0
  reset mask : 0x0
*/
volatile uint32_t ALARM1;

/** ALARM2 (offset: 0x18)
  Arm alarm 2, and configure the time it will fire.

 Once armed, the alarm fires when TIMER_ALARM2 == TIMELR.

 The alarm will disarm itself once it fires, and can

 be disarmed early using the ARMED status register.
  access : read-write
  reset value : 0x0
  reset mask : 0x0
*/
volatile uint32_t ALARM2;

/** ALARM3 (offset: 0x1c)
  Arm alarm 3, and configure the time it will fire.

 Once armed, the alarm fires when TIMER_ALARM3 == TIMELR.

 The alarm will disarm itself once it fires, and can

 be disarmed early using the ARMED status register.
  access : read-write
  reset value : 0x0
  reset mask : 0x0
*/
volatile uint32_t ALARM3;

/** ARMED (offset: 0x20)
  Indicates the armed/disarmed status of each alarm.

 A write to the corresponding ALARMx register arms the alarm.

 Alarms automatically disarm upon firing, but writing ones here

 will disarm immediately without waiting to fire.
  access : read-write
  reset value : 0x0
  reset mask : 0x0
  Field: ARMED
  offset: 0, size: 4, access: read-write
*/
volatile uint32_t ARMED;

/** TIMERAWH (offset: 0x24)
  Raw read from bits 63:32 of time (no side effects)
  access : read-only
  reset value : 0x0
  reset mask : 0x0
*/
volatile uint32_t TIMERAWH;

/** TIMERAWL (offset: 0x28)
  Raw read from bits 31:0 of time (no side effects)
  access : read-only
  reset value : 0x0
  reset mask : 0x0
*/
volatile uint32_t TIMERAWL;

/** DBGPAUSE (offset: 0x2c)
  Set bits high to enable pause when the corresponding debug ports are active
  access : read-write
  reset value : 0x7
  reset mask : 0x0
  Field: DBG1
  offset: 2, size: 1, access: read-write
  Pause when processor 1 is in debug mode
  Field: DBG0
  offset: 1, size: 1, access: read-write
  Pause when processor 0 is in debug mode
*/
volatile uint32_t DBGPAUSE;

/** PAUSE (offset: 0x30)
  Set high to pause the timer
  access : read-write
  reset value : 0x0
  reset mask : 0x0
  Field: PAUSE
  offset: 0, size: 1, access: read-write
*/
volatile uint32_t PAUSE;

/** INTR (offset: 0x34)
  Raw Interrupts
  access : read-write
  reset value : 0x0
  reset mask : 0x0
  Field: ALARM_3
  offset: 3, size: 1, access: read-write
  Field: ALARM_2
  offset: 2, size: 1, access: read-write
  Field: ALARM_1
  offset: 1, size: 1, access: read-write
  Field: ALARM_0
  offset: 0, size: 1, access: read-write
*/
volatile uint32_t INTR;

/** INTE (offset: 0x38)
  Interrupt Enable
  access : read-write
  reset value : 0x0
  reset mask : 0x0
  Field: ALARM_3
  offset: 3, size: 1, access: read-write
  Field: ALARM_2
  offset: 2, size: 1, access: read-write
  Field: ALARM_1
  offset: 1, size: 1, access: read-write
  Field: ALARM_0
  offset: 0, size: 1, access: read-write
*/
volatile uint32_t INTE;

/** INTF (offset: 0x3c)
  Interrupt Force
  access : read-write
  reset value : 0x0
  reset mask : 0x0
  Field: ALARM_3
  offset: 3, size: 1, access: read-write
  Field: ALARM_2
  offset: 2, size: 1, access: read-write
  Field: ALARM_1
  offset: 1, size: 1, access: read-write
  Field: ALARM_0
  offset: 0, size: 1, access: read-write
*/
volatile uint32_t INTF;

/** INTS (offset: 0x40)
  Interrupt status after masking &amp; forcing
  access : read-write
  reset value : 0x0
  reset mask : 0x0
  Field: ALARM_3
  offset: 3, size: 1, access: read-only
  Field: ALARM_2
  offset: 2, size: 1, access: read-only
  Field: ALARM_1
  offset: 1, size: 1, access: read-only
  Field: ALARM_0
  offset: 0, size: 1, access: read-only
*/
volatile uint32_t INTS;
} TIMER_type;

#define TIMER ((TIMER_type *) 0x40054000)

#endif // HW_TIMER_H
