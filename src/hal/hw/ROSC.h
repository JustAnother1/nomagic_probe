/*
  automatically created from data available on https://chipselect.org/
*/
#ifndef HW_ROSC_H
#define HW_ROSC_H
/** Memory Block starting at 0x40060000 + 0x0 is 0x1000 bytes in size. It is used for registers. Protection: n */

#include <stdint.h>


#define ROSC_CTRL_ENABLE_OFFSET                            12u
#define ROSC_CTRL_ENABLE_MASK                              0xfff000u
#define ROSC_CTRL_ENABLE_DISABLE                           0xd1eu
#define ROSC_CTRL_ENABLE_ENABLE                            0xfabu

#define ROSC_CTRL_FREQ_RANGE_OFFSET                        0u
#define ROSC_CTRL_FREQ_RANGE_MASK                          0xfffu
#define ROSC_CTRL_FREQ_RANGE_LOW                           0xfa4u
#define ROSC_CTRL_FREQ_RANGE_MEDIUM                        0xfa5u
#define ROSC_CTRL_FREQ_RANGE_HIGH                          0xfa7u
#define ROSC_CTRL_FREQ_RANGE_TOOHIGH                       0xfa6u

#define ROSC_FREQA_PASSWD_OFFSET                           16u
#define ROSC_FREQA_PASSWD_MASK                             0xffff0000u
#define ROSC_FREQA_PASSWD_PASS                             0x9696u

#define ROSC_FREQA_DS3_OFFSET                              12u
#define ROSC_FREQA_DS3_MASK                                0x7000u

#define ROSC_FREQA_DS2_OFFSET                              8u
#define ROSC_FREQA_DS2_MASK                                0x700u

#define ROSC_FREQA_DS1_OFFSET                              4u
#define ROSC_FREQA_DS1_MASK                                0x70u

#define ROSC_FREQA_DS0_OFFSET                              0u
#define ROSC_FREQA_DS0_MASK                                7u

#define ROSC_FREQB_PASSWD_OFFSET                           16u
#define ROSC_FREQB_PASSWD_MASK                             0xffff0000u
#define ROSC_FREQB_PASSWD_PASS                             0x9696u

#define ROSC_FREQB_DS7_OFFSET                              12u
#define ROSC_FREQB_DS7_MASK                                0x7000u

#define ROSC_FREQB_DS6_OFFSET                              8u
#define ROSC_FREQB_DS6_MASK                                0x700u

#define ROSC_FREQB_DS5_OFFSET                              4u
#define ROSC_FREQB_DS5_MASK                                0x70u

#define ROSC_FREQB_DS4_OFFSET                              0u
#define ROSC_FREQB_DS4_MASK                                7u

#define ROSC_DIV_DIV_OFFSET                                0u
#define ROSC_DIV_DIV_MASK                                  0xfffu
#define ROSC_DIV_DIV_PASS                                  0xaa0u

#define ROSC_PHASE_PASSWD_OFFSET                           4u
#define ROSC_PHASE_PASSWD_MASK                             0xff0u

#define ROSC_PHASE_ENABLE_OFFSET                           3u
#define ROSC_PHASE_ENABLE_MASK                             8u

#define ROSC_PHASE_FLIP_OFFSET                             2u
#define ROSC_PHASE_FLIP_MASK                               4u

#define ROSC_PHASE_SHIFT_OFFSET                            0u
#define ROSC_PHASE_SHIFT_MASK                              3u

#define ROSC_STATUS_STABLE_OFFSET                          31u
#define ROSC_STATUS_STABLE_MASK                            0x80000000u

#define ROSC_STATUS_BADWRITE_OFFSET                        24u
#define ROSC_STATUS_BADWRITE_MASK                          0x1000000u

#define ROSC_STATUS_DIV_RUNNING_OFFSET                     16u
#define ROSC_STATUS_DIV_RUNNING_MASK                       0x10000u

#define ROSC_STATUS_ENABLED_OFFSET                         12u
#define ROSC_STATUS_ENABLED_MASK                           0x1000u

#define ROSC_RANDOMBIT_RANDOMBIT_OFFSET                    0u
#define ROSC_RANDOMBIT_RANDOMBIT_MASK                      1u

#define ROSC_COUNT_COUNT_OFFSET                            0u
#define ROSC_COUNT_COUNT_MASK                              0xffu


typedef struct
{

/** CTRL (offset: 0x0)
  Ring Oscillator control
  access : read-write
  reset value : 0xAA0
  reset mask : 0x0
  Field: ENABLE
  offset: 12, size: 12, access: read-write
  On power-up this field is initialised to ENABLE

 The system clock must be switched to another source before setting this field to DISABLE otherwise the chip will lock up

 The 12-bit code is intended to give some protection against accidental writes. An invalid setting will enable the oscillator.
  Enum:
  Value: 0xd1e - DISABLE
  Value: 0xfab - ENABLE
  Field: FREQ_RANGE
  offset: 0, size: 12, access: read-write
  Controls the number of delay stages in the ROSC ring

 LOW uses stages 0 to 7

 MEDIUM uses stages 0 to 5

 HIGH uses stages 0 to 3

 TOOHIGH uses stages 0 to 1 and should not be used because its frequency exceeds design specifications

 The clock output will not glitch when changing the range up one step at a time

 The clock output will glitch when changing the range down

 Note: the values here are gray coded which is why HIGH comes before TOOHIGH
  Enum:
  Value: 0xfa4 - LOW
  Value: 0xfa5 - MEDIUM
  Value: 0xfa7 - HIGH
  Value: 0xfa6 - TOOHIGH
*/
volatile uint32_t CTRL;

/** FREQA (offset: 0x4)
  The FREQA &amp; FREQB registers control the frequency by controlling the drive strength of each stage

 The drive strength has 4 levels determined by the number of bits set

 Increasing the number of bits set increases the drive strength and increases the oscillation frequency

 0 bits set is the default drive strength

 1 bit set doubles the drive strength

 2 bits set triples drive strength

 3 bits set quadruples drive strength
  access : read-write
  reset value : 0x0
  reset mask : 0x0
  Field: PASSWD
  offset: 16, size: 16, access: read-write
  Set to 0x9696 to apply the settings

 Any other value in this field will set all drive strengths to 0
  Enum:
  Value: 0x9696 - PASS
  Field: DS3
  offset: 12, size: 3, access: read-write
  Stage 3 drive strength
  Field: DS2
  offset: 8, size: 3, access: read-write
  Stage 2 drive strength
  Field: DS1
  offset: 4, size: 3, access: read-write
  Stage 1 drive strength
  Field: DS0
  offset: 0, size: 3, access: read-write
  Stage 0 drive strength
*/
volatile uint32_t FREQA;

/** FREQB (offset: 0x8)
  For a detailed description see freqa register
  access : read-write
  reset value : 0x0
  reset mask : 0x0
  Field: PASSWD
  offset: 16, size: 16, access: read-write
  Set to 0x9696 to apply the settings

 Any other value in this field will set all drive strengths to 0
  Enum:
  Value: 0x9696 - PASS
  Field: DS7
  offset: 12, size: 3, access: read-write
  Stage 7 drive strength
  Field: DS6
  offset: 8, size: 3, access: read-write
  Stage 6 drive strength
  Field: DS5
  offset: 4, size: 3, access: read-write
  Stage 5 drive strength
  Field: DS4
  offset: 0, size: 3, access: read-write
  Stage 4 drive strength
*/
volatile uint32_t FREQB;

/** DORMANT (offset: 0xc)
  Ring Oscillator pause control

 This is used to save power by pausing the ROSC

 On power-up this field is initialised to WAKE

 An invalid write will also select WAKE

 Warning: setup the irq before selecting dormant mode
  access : read-write
  reset value : 0x0
  reset mask : 0x0
*/
volatile uint32_t DORMANT;

/** DIV (offset: 0x10)
  Controls the output divider
  access : read-write
  reset value : 0x0
  reset mask : 0x0
  Field: DIV
  offset: 0, size: 12, access: read-write
  set to 0xaa0 + div where

 div = 0 divides by 32

 div = 1-31 divides by div

 any other value sets div=31

 this register resets to div=16
  Enum:
  Value: 0xaa0 - PASS
*/
volatile uint32_t DIV;

/** PHASE (offset: 0x14)
  Controls the phase shifted output
  access : read-write
  reset value : 0x8
  reset mask : 0x0
  Field: PASSWD
  offset: 4, size: 8, access: read-write
  set to 0xaa

 any other value enables the output with shift=0
  Field: ENABLE
  offset: 3, size: 1, access: read-write
  enable the phase-shifted output

 this can be changed on-the-fly
  Field: FLIP
  offset: 2, size: 1, access: read-write
  invert the phase-shifted output

 this is ignored when div=1
  Field: SHIFT
  offset: 0, size: 2, access: read-write
  phase shift the phase-shifted output by SHIFT input clocks

 this can be changed on-the-fly

 must be set to 0 before setting div=1
*/
volatile uint32_t PHASE;

/** STATUS (offset: 0x18)
  Ring Oscillator Status
  access : read-write
  reset value : 0x0
  reset mask : 0x0
  Field: STABLE
  offset: 31, size: 1, access: read-only
  Oscillator is running and stable
  Field: BADWRITE
  offset: 24, size: 1, access: read-write
  An invalid value has been written to CTRL_ENABLE or CTRL_FREQ_RANGE or FREQA or FREQB or DIV or PHASE or DORMANT
  Field: DIV_RUNNING
  offset: 16, size: 1, access: read-only
  post-divider is running

 this resets to 0 but transitions to 1 during chip startup
  Field: ENABLED
  offset: 12, size: 1, access: read-only
  Oscillator is enabled but not necessarily running and stable

 this resets to 0 but transitions to 1 during chip startup
*/
volatile uint32_t STATUS;

/** RANDOMBIT (offset: 0x1c)
  This just reads the state of the oscillator output so randomness is compromised if the ring oscillator is stopped or run at a harmonic of the bus frequency
  access : read-write
  reset value : 0x1
  reset mask : 0x0
  Field: RANDOMBIT
  offset: 0, size: 1, access: read-only
*/
volatile uint32_t RANDOMBIT;

/** COUNT (offset: 0x20)
  A down counter running at the ROSC frequency which counts to zero and stops.

 To start the counter write a non-zero value.

 Can be used for short software pauses when setting up time sensitive hardware.
  access : read-write
  reset value : 0x0
  reset mask : 0x0
  Field: COUNT
  offset: 0, size: 8, access: read-write
*/
volatile uint32_t COUNT;
} ROSC_type;

#define ROSC ((ROSC_type *) 0x40060000)

#endif // HW_ROSC_H
