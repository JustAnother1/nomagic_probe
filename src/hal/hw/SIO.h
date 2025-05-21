/*
  automatically created from data available on https://chipselect.org/
*/
#ifndef HW_SIO_H
#define HW_SIO_H
/** Single-cycle IO block

 Provides core-local and inter-core hardware for the two processors, with single-cycle access. */
/** Interrupt : SIO_IRQ_PROC1 (Vector: 16)  */
/** Interrupt : SIO_IRQ_PROC0 (Vector: 15)  */
/** Memory Block starting at 0xD0000000 + 0x0 is 0x200 bytes in size. It is used for registers. Protection: n */

#include <stdint.h>


#define SIO_GPIO_IN_GPIO_IN_OFFSET                         0u
#define SIO_GPIO_IN_GPIO_IN_MASK                           0x3fffffffu

#define SIO_GPIO_HI_IN_GPIO_HI_IN_OFFSET                   0u
#define SIO_GPIO_HI_IN_GPIO_HI_IN_MASK                     0x3fu

#define SIO_GPIO_OUT_GPIO_OUT_OFFSET                       0u
#define SIO_GPIO_OUT_GPIO_OUT_MASK                         0x3fffffffu

#define SIO_GPIO_OUT_SET_GPIO_OUT_SET_OFFSET               0u
#define SIO_GPIO_OUT_SET_GPIO_OUT_SET_MASK                 0x3fffffffu

#define SIO_GPIO_OUT_CLR_GPIO_OUT_CLR_OFFSET               0u
#define SIO_GPIO_OUT_CLR_GPIO_OUT_CLR_MASK                 0x3fffffffu

#define SIO_GPIO_OUT_XOR_GPIO_OUT_XOR_OFFSET               0u
#define SIO_GPIO_OUT_XOR_GPIO_OUT_XOR_MASK                 0x3fffffffu

#define SIO_GPIO_OE_GPIO_OE_OFFSET                         0u
#define SIO_GPIO_OE_GPIO_OE_MASK                           0x3fffffffu

#define SIO_GPIO_OE_SET_GPIO_OE_SET_OFFSET                 0u
#define SIO_GPIO_OE_SET_GPIO_OE_SET_MASK                   0x3fffffffu

#define SIO_GPIO_OE_CLR_GPIO_OE_CLR_OFFSET                 0u
#define SIO_GPIO_OE_CLR_GPIO_OE_CLR_MASK                   0x3fffffffu

#define SIO_GPIO_OE_XOR_GPIO_OE_XOR_OFFSET                 0u
#define SIO_GPIO_OE_XOR_GPIO_OE_XOR_MASK                   0x3fffffffu

#define SIO_GPIO_HI_OUT_GPIO_HI_OUT_OFFSET                 0u
#define SIO_GPIO_HI_OUT_GPIO_HI_OUT_MASK                   0x3fu

#define SIO_GPIO_HI_OUT_SET_GPIO_HI_OUT_SET_OFFSET         0u
#define SIO_GPIO_HI_OUT_SET_GPIO_HI_OUT_SET_MASK           0x3fu

#define SIO_GPIO_HI_OUT_CLR_GPIO_HI_OUT_CLR_OFFSET         0u
#define SIO_GPIO_HI_OUT_CLR_GPIO_HI_OUT_CLR_MASK           0x3fu

#define SIO_GPIO_HI_OUT_XOR_GPIO_HI_OUT_XOR_OFFSET         0u
#define SIO_GPIO_HI_OUT_XOR_GPIO_HI_OUT_XOR_MASK           0x3fu

#define SIO_GPIO_HI_OE_GPIO_HI_OE_OFFSET                   0u
#define SIO_GPIO_HI_OE_GPIO_HI_OE_MASK                     0x3fu

#define SIO_GPIO_HI_OE_SET_GPIO_HI_OE_SET_OFFSET           0u
#define SIO_GPIO_HI_OE_SET_GPIO_HI_OE_SET_MASK             0x3fu

#define SIO_GPIO_HI_OE_CLR_GPIO_HI_OE_CLR_OFFSET           0u
#define SIO_GPIO_HI_OE_CLR_GPIO_HI_OE_CLR_MASK             0x3fu

#define SIO_GPIO_HI_OE_XOR_GPIO_HI_OE_XOR_OFFSET           0u
#define SIO_GPIO_HI_OE_XOR_GPIO_HI_OE_XOR_MASK             0x3fu

#define SIO_FIFO_ST_ROE_OFFSET                             3u
#define SIO_FIFO_ST_ROE_MASK                               8u

#define SIO_FIFO_ST_WOF_OFFSET                             2u
#define SIO_FIFO_ST_WOF_MASK                               4u

#define SIO_FIFO_ST_RDY_OFFSET                             1u
#define SIO_FIFO_ST_RDY_MASK                               2u

#define SIO_FIFO_ST_VLD_OFFSET                             0u
#define SIO_FIFO_ST_VLD_MASK                               1u

#define SIO_DIV_CSR_DIRTY_OFFSET                           1u
#define SIO_DIV_CSR_DIRTY_MASK                             2u

#define SIO_DIV_CSR_READY_OFFSET                           0u
#define SIO_DIV_CSR_READY_MASK                             1u

#define SIO_INTERP0_CTRL_LANE0_OVERF_OFFSET                25u
#define SIO_INTERP0_CTRL_LANE0_OVERF_MASK                  0x2000000u

#define SIO_INTERP0_CTRL_LANE0_OVERF1_OFFSET               24u
#define SIO_INTERP0_CTRL_LANE0_OVERF1_MASK                 0x1000000u

#define SIO_INTERP0_CTRL_LANE0_OVERF0_OFFSET               23u
#define SIO_INTERP0_CTRL_LANE0_OVERF0_MASK                 0x800000u

#define SIO_INTERP0_CTRL_LANE0_BLEND_OFFSET                21u
#define SIO_INTERP0_CTRL_LANE0_BLEND_MASK                  0x200000u

#define SIO_INTERP0_CTRL_LANE0_FORCE_MSB_OFFSET            19u
#define SIO_INTERP0_CTRL_LANE0_FORCE_MSB_MASK              0x180000u

#define SIO_INTERP0_CTRL_LANE0_ADD_RAW_OFFSET              18u
#define SIO_INTERP0_CTRL_LANE0_ADD_RAW_MASK                0x40000u

#define SIO_INTERP0_CTRL_LANE0_CROSS_RESULT_OFFSET         17u
#define SIO_INTERP0_CTRL_LANE0_CROSS_RESULT_MASK           0x20000u

#define SIO_INTERP0_CTRL_LANE0_CROSS_INPUT_OFFSET          16u
#define SIO_INTERP0_CTRL_LANE0_CROSS_INPUT_MASK            0x10000u

#define SIO_INTERP0_CTRL_LANE0_SIGNED_OFFSET               15u
#define SIO_INTERP0_CTRL_LANE0_SIGNED_MASK                 0x8000u

#define SIO_INTERP0_CTRL_LANE0_MASK_MSB_OFFSET             10u
#define SIO_INTERP0_CTRL_LANE0_MASK_MSB_MASK               0x7c00u

#define SIO_INTERP0_CTRL_LANE0_MASK_LSB_OFFSET             5u
#define SIO_INTERP0_CTRL_LANE0_MASK_LSB_MASK               0x3e0u

#define SIO_INTERP0_CTRL_LANE0_SHIFT_OFFSET                0u
#define SIO_INTERP0_CTRL_LANE0_SHIFT_MASK                  0x1fu

#define SIO_INTERP0_CTRL_LANE1_FORCE_MSB_OFFSET            19u
#define SIO_INTERP0_CTRL_LANE1_FORCE_MSB_MASK              0x180000u

#define SIO_INTERP0_CTRL_LANE1_ADD_RAW_OFFSET              18u
#define SIO_INTERP0_CTRL_LANE1_ADD_RAW_MASK                0x40000u

#define SIO_INTERP0_CTRL_LANE1_CROSS_RESULT_OFFSET         17u
#define SIO_INTERP0_CTRL_LANE1_CROSS_RESULT_MASK           0x20000u

#define SIO_INTERP0_CTRL_LANE1_CROSS_INPUT_OFFSET          16u
#define SIO_INTERP0_CTRL_LANE1_CROSS_INPUT_MASK            0x10000u

#define SIO_INTERP0_CTRL_LANE1_SIGNED_OFFSET               15u
#define SIO_INTERP0_CTRL_LANE1_SIGNED_MASK                 0x8000u

#define SIO_INTERP0_CTRL_LANE1_MASK_MSB_OFFSET             10u
#define SIO_INTERP0_CTRL_LANE1_MASK_MSB_MASK               0x7c00u

#define SIO_INTERP0_CTRL_LANE1_MASK_LSB_OFFSET             5u
#define SIO_INTERP0_CTRL_LANE1_MASK_LSB_MASK               0x3e0u

#define SIO_INTERP0_CTRL_LANE1_SHIFT_OFFSET                0u
#define SIO_INTERP0_CTRL_LANE1_SHIFT_MASK                  0x1fu

#define SIO_INTERP0_ACCUM0_ADD_INTERP0_ACCUM0_ADD_OFFSET   0u
#define SIO_INTERP0_ACCUM0_ADD_INTERP0_ACCUM0_ADD_MASK     0xffffffu

#define SIO_INTERP0_ACCUM1_ADD_INTERP0_ACCUM1_ADD_OFFSET   0u
#define SIO_INTERP0_ACCUM1_ADD_INTERP0_ACCUM1_ADD_MASK     0xffffffu

#define SIO_INTERP1_CTRL_LANE0_OVERF_OFFSET                25u
#define SIO_INTERP1_CTRL_LANE0_OVERF_MASK                  0x2000000u

#define SIO_INTERP1_CTRL_LANE0_OVERF1_OFFSET               24u
#define SIO_INTERP1_CTRL_LANE0_OVERF1_MASK                 0x1000000u

#define SIO_INTERP1_CTRL_LANE0_OVERF0_OFFSET               23u
#define SIO_INTERP1_CTRL_LANE0_OVERF0_MASK                 0x800000u

#define SIO_INTERP1_CTRL_LANE0_CLAMP_OFFSET                22u
#define SIO_INTERP1_CTRL_LANE0_CLAMP_MASK                  0x400000u

#define SIO_INTERP1_CTRL_LANE0_FORCE_MSB_OFFSET            19u
#define SIO_INTERP1_CTRL_LANE0_FORCE_MSB_MASK              0x180000u

#define SIO_INTERP1_CTRL_LANE0_ADD_RAW_OFFSET              18u
#define SIO_INTERP1_CTRL_LANE0_ADD_RAW_MASK                0x40000u

#define SIO_INTERP1_CTRL_LANE0_CROSS_RESULT_OFFSET         17u
#define SIO_INTERP1_CTRL_LANE0_CROSS_RESULT_MASK           0x20000u

#define SIO_INTERP1_CTRL_LANE0_CROSS_INPUT_OFFSET          16u
#define SIO_INTERP1_CTRL_LANE0_CROSS_INPUT_MASK            0x10000u

#define SIO_INTERP1_CTRL_LANE0_SIGNED_OFFSET               15u
#define SIO_INTERP1_CTRL_LANE0_SIGNED_MASK                 0x8000u

#define SIO_INTERP1_CTRL_LANE0_MASK_MSB_OFFSET             10u
#define SIO_INTERP1_CTRL_LANE0_MASK_MSB_MASK               0x7c00u

#define SIO_INTERP1_CTRL_LANE0_MASK_LSB_OFFSET             5u
#define SIO_INTERP1_CTRL_LANE0_MASK_LSB_MASK               0x3e0u

#define SIO_INTERP1_CTRL_LANE0_SHIFT_OFFSET                0u
#define SIO_INTERP1_CTRL_LANE0_SHIFT_MASK                  0x1fu

#define SIO_INTERP1_CTRL_LANE1_FORCE_MSB_OFFSET            19u
#define SIO_INTERP1_CTRL_LANE1_FORCE_MSB_MASK              0x180000u

#define SIO_INTERP1_CTRL_LANE1_ADD_RAW_OFFSET              18u
#define SIO_INTERP1_CTRL_LANE1_ADD_RAW_MASK                0x40000u

#define SIO_INTERP1_CTRL_LANE1_CROSS_RESULT_OFFSET         17u
#define SIO_INTERP1_CTRL_LANE1_CROSS_RESULT_MASK           0x20000u

#define SIO_INTERP1_CTRL_LANE1_CROSS_INPUT_OFFSET          16u
#define SIO_INTERP1_CTRL_LANE1_CROSS_INPUT_MASK            0x10000u

#define SIO_INTERP1_CTRL_LANE1_SIGNED_OFFSET               15u
#define SIO_INTERP1_CTRL_LANE1_SIGNED_MASK                 0x8000u

#define SIO_INTERP1_CTRL_LANE1_MASK_MSB_OFFSET             10u
#define SIO_INTERP1_CTRL_LANE1_MASK_MSB_MASK               0x7c00u

#define SIO_INTERP1_CTRL_LANE1_MASK_LSB_OFFSET             5u
#define SIO_INTERP1_CTRL_LANE1_MASK_LSB_MASK               0x3e0u

#define SIO_INTERP1_CTRL_LANE1_SHIFT_OFFSET                0u
#define SIO_INTERP1_CTRL_LANE1_SHIFT_MASK                  0x1fu

#define SIO_INTERP1_ACCUM0_ADD_INTERP1_ACCUM0_ADD_OFFSET   0u
#define SIO_INTERP1_ACCUM0_ADD_INTERP1_ACCUM0_ADD_MASK     0xffffffu

#define SIO_INTERP1_ACCUM1_ADD_INTERP1_ACCUM1_ADD_OFFSET   0u
#define SIO_INTERP1_ACCUM1_ADD_INTERP1_ACCUM1_ADD_MASK     0xffffffu


typedef struct
{

/** CPUID (offset: 0x0)
  Processor core identifier

 Value is 0 when read from processor core 0, and 1 when read from processor core 1.
  access : read-only
  reset value : 0x0
  reset mask : 0x0
*/
volatile uint32_t CPUID;

/** GPIO_IN (offset: 0x4)
  Input value for GPIO pins
  access : read-write
  reset value : 0x0
  reset mask : 0x0
  Field: GPIO_IN
  offset: 0, size: 30, access: read-only
  Input value for GPIO0...29
*/
volatile uint32_t GPIO_IN;

/** GPIO_HI_IN (offset: 0x8)
  Input value for QSPI pins
  access : read-write
  reset value : 0x0
  reset mask : 0x0
  Field: GPIO_HI_IN
  offset: 0, size: 6, access: read-only
  Input value on QSPI IO in order 0..5: SCLK, SSn, SD0, SD1, SD2, SD3
*/
volatile uint32_t GPIO_HI_IN;
volatile uint32_t reserved0;

/** GPIO_OUT (offset: 0x10)
  GPIO output value
  access : read-write
  reset value : 0x0
  reset mask : 0x0
  Field: GPIO_OUT
  offset: 0, size: 30, access: read-write
  Set output level (1/0 -&gt; high/low) for GPIO0...29.

 Reading back gives the last value written, NOT the input value from the pins.

 If core 0 and core 1 both write to GPIO_OUT simultaneously (or to a SET/CLR/XOR alias),

 the result is as though the write from core 0 took place first,

 and the write from core 1 was then applied to that intermediate result.
*/
volatile uint32_t GPIO_OUT;

/** GPIO_OUT_SET (offset: 0x14)
  GPIO output value set
  access : read-write
  reset value : 0x0
  reset mask : 0x0
  Field: GPIO_OUT_SET
  offset: 0, size: 30, access: write-only
  Perform an atomic bit-set on GPIO_OUT, i.e. `GPIO_OUT |= wdata`
*/
volatile uint32_t GPIO_OUT_SET;

/** GPIO_OUT_CLR (offset: 0x18)
  GPIO output value clear
  access : read-write
  reset value : 0x0
  reset mask : 0x0
  Field: GPIO_OUT_CLR
  offset: 0, size: 30, access: write-only
  Perform an atomic bit-clear on GPIO_OUT, i.e. `GPIO_OUT &amp;= ~wdata`
*/
volatile uint32_t GPIO_OUT_CLR;

/** GPIO_OUT_XOR (offset: 0x1c)
  GPIO output value XOR
  access : read-write
  reset value : 0x0
  reset mask : 0x0
  Field: GPIO_OUT_XOR
  offset: 0, size: 30, access: write-only
  Perform an atomic bitwise XOR on GPIO_OUT, i.e. `GPIO_OUT ^= wdata`
*/
volatile uint32_t GPIO_OUT_XOR;

/** GPIO_OE (offset: 0x20)
  GPIO output enable
  access : read-write
  reset value : 0x0
  reset mask : 0x0
  Field: GPIO_OE
  offset: 0, size: 30, access: read-write
  Set output enable (1/0 -&gt; output/input) for GPIO0...29.

 Reading back gives the last value written.

 If core 0 and core 1 both write to GPIO_OE simultaneously (or to a SET/CLR/XOR alias),

 the result is as though the write from core 0 took place first,

 and the write from core 1 was then applied to that intermediate result.
*/
volatile uint32_t GPIO_OE;

/** GPIO_OE_SET (offset: 0x24)
  GPIO output enable set
  access : read-write
  reset value : 0x0
  reset mask : 0x0
  Field: GPIO_OE_SET
  offset: 0, size: 30, access: write-only
  Perform an atomic bit-set on GPIO_OE, i.e. `GPIO_OE |= wdata`
*/
volatile uint32_t GPIO_OE_SET;

/** GPIO_OE_CLR (offset: 0x28)
  GPIO output enable clear
  access : read-write
  reset value : 0x0
  reset mask : 0x0
  Field: GPIO_OE_CLR
  offset: 0, size: 30, access: write-only
  Perform an atomic bit-clear on GPIO_OE, i.e. `GPIO_OE &amp;= ~wdata`
*/
volatile uint32_t GPIO_OE_CLR;

/** GPIO_OE_XOR (offset: 0x2c)
  GPIO output enable XOR
  access : read-write
  reset value : 0x0
  reset mask : 0x0
  Field: GPIO_OE_XOR
  offset: 0, size: 30, access: write-only
  Perform an atomic bitwise XOR on GPIO_OE, i.e. `GPIO_OE ^= wdata`
*/
volatile uint32_t GPIO_OE_XOR;

/** GPIO_HI_OUT (offset: 0x30)
  QSPI output value
  access : read-write
  reset value : 0x0
  reset mask : 0x0
  Field: GPIO_HI_OUT
  offset: 0, size: 6, access: read-write
  Set output level (1/0 -&gt; high/low) for QSPI IO0...5.

 Reading back gives the last value written, NOT the input value from the pins.

 If core 0 and core 1 both write to GPIO_HI_OUT simultaneously (or to a SET/CLR/XOR alias),

 the result is as though the write from core 0 took place first,

 and the write from core 1 was then applied to that intermediate result.
*/
volatile uint32_t GPIO_HI_OUT;

/** GPIO_HI_OUT_SET (offset: 0x34)
  QSPI output value set
  access : read-write
  reset value : 0x0
  reset mask : 0x0
  Field: GPIO_HI_OUT_SET
  offset: 0, size: 6, access: write-only
  Perform an atomic bit-set on GPIO_HI_OUT, i.e. `GPIO_HI_OUT |= wdata`
*/
volatile uint32_t GPIO_HI_OUT_SET;

/** GPIO_HI_OUT_CLR (offset: 0x38)
  QSPI output value clear
  access : read-write
  reset value : 0x0
  reset mask : 0x0
  Field: GPIO_HI_OUT_CLR
  offset: 0, size: 6, access: write-only
  Perform an atomic bit-clear on GPIO_HI_OUT, i.e. `GPIO_HI_OUT &amp;= ~wdata`
*/
volatile uint32_t GPIO_HI_OUT_CLR;

/** GPIO_HI_OUT_XOR (offset: 0x3c)
  QSPI output value XOR
  access : read-write
  reset value : 0x0
  reset mask : 0x0
  Field: GPIO_HI_OUT_XOR
  offset: 0, size: 6, access: write-only
  Perform an atomic bitwise XOR on GPIO_HI_OUT, i.e. `GPIO_HI_OUT ^= wdata`
*/
volatile uint32_t GPIO_HI_OUT_XOR;

/** GPIO_HI_OE (offset: 0x40)
  QSPI output enable
  access : read-write
  reset value : 0x0
  reset mask : 0x0
  Field: GPIO_HI_OE
  offset: 0, size: 6, access: read-write
  Set output enable (1/0 -&gt; output/input) for QSPI IO0...5.

 Reading back gives the last value written.

 If core 0 and core 1 both write to GPIO_HI_OE simultaneously (or to a SET/CLR/XOR alias),

 the result is as though the write from core 0 took place first,

 and the write from core 1 was then applied to that intermediate result.
*/
volatile uint32_t GPIO_HI_OE;

/** GPIO_HI_OE_SET (offset: 0x44)
  QSPI output enable set
  access : read-write
  reset value : 0x0
  reset mask : 0x0
  Field: GPIO_HI_OE_SET
  offset: 0, size: 6, access: write-only
  Perform an atomic bit-set on GPIO_HI_OE, i.e. `GPIO_HI_OE |= wdata`
*/
volatile uint32_t GPIO_HI_OE_SET;

/** GPIO_HI_OE_CLR (offset: 0x48)
  QSPI output enable clear
  access : read-write
  reset value : 0x0
  reset mask : 0x0
  Field: GPIO_HI_OE_CLR
  offset: 0, size: 6, access: write-only
  Perform an atomic bit-clear on GPIO_HI_OE, i.e. `GPIO_HI_OE &amp;= ~wdata`
*/
volatile uint32_t GPIO_HI_OE_CLR;

/** GPIO_HI_OE_XOR (offset: 0x4c)
  QSPI output enable XOR
  access : read-write
  reset value : 0x0
  reset mask : 0x0
  Field: GPIO_HI_OE_XOR
  offset: 0, size: 6, access: write-only
  Perform an atomic bitwise XOR on GPIO_HI_OE, i.e. `GPIO_HI_OE ^= wdata`
*/
volatile uint32_t GPIO_HI_OE_XOR;

/** FIFO_ST (offset: 0x50)
  Status register for inter-core FIFOs (mailboxes).

 There is one FIFO in the core 0 -&gt; core 1 direction, and one core 1 -&gt; core 0. Both are 32 bits wide and 8 words deep.

 Core 0 can see the read side of the 1-&gt;0 FIFO (RX), and the write side of 0-&gt;1 FIFO (TX).

 Core 1 can see the read side of the 0-&gt;1 FIFO (RX), and the write side of 1-&gt;0 FIFO (TX).

 The SIO IRQ for each core is the logical OR of the VLD, WOF and ROE fields of its FIFO_ST register.
  access : read-write
  reset value : 0x2
  reset mask : 0x0
  Field: ROE
  offset: 3, size: 1, access: read-write
  Sticky flag indicating the RX FIFO was read when empty. This read was ignored by the FIFO.
  Field: WOF
  offset: 2, size: 1, access: read-write
  Sticky flag indicating the TX FIFO was written when full. This write was ignored by the FIFO.
  Field: RDY
  offset: 1, size: 1, access: read-only
  Value is 1 if this core&apos;s TX FIFO is not full (i.e. if FIFO_WR is ready for more data)
  Field: VLD
  offset: 0, size: 1, access: read-only
  Value is 1 if this core&apos;s RX FIFO is not empty (i.e. if FIFO_RD is valid)
*/
volatile uint32_t FIFO_ST;

/** FIFO_WR (offset: 0x54)
  Write access to this core&apos;s TX FIFO
  access : write-only
  reset value : 0x0
  reset mask : 0x0
*/
volatile uint32_t FIFO_WR;

/** FIFO_RD (offset: 0x58)
  Read access to this core&apos;s RX FIFO
  access : read-only
  reset value : 0x0
  reset mask : 0x0
*/
volatile uint32_t FIFO_RD;

/** SPINLOCK_ST (offset: 0x5c)
  Spinlock state

 A bitmap containing the state of all 32 spinlocks (1=locked).

 Mainly intended for debugging.
  access : read-only
  reset value : 0x0
  reset mask : 0x0
*/
volatile uint32_t SPINLOCK_ST;

/** DIV_UDIVIDEND (offset: 0x60)
  Divider unsigned dividend

 Write to the DIVIDEND operand of the divider, i.e. the p in `p / q`.

 Any operand write starts a new calculation. The results appear in QUOTIENT, REMAINDER.

 UDIVIDEND/SDIVIDEND are aliases of the same internal register. The U alias starts an

 unsigned calculation, and the S alias starts a signed calculation.
  access : read-write
  reset value : 0x0
  reset mask : 0x0
*/
volatile uint32_t DIV_UDIVIDEND;

/** DIV_UDIVISOR (offset: 0x64)
  Divider unsigned divisor

 Write to the DIVISOR operand of the divider, i.e. the q in `p / q`.

 Any operand write starts a new calculation. The results appear in QUOTIENT, REMAINDER.

 UDIVISOR/SDIVISOR are aliases of the same internal register. The U alias starts an

 unsigned calculation, and the S alias starts a signed calculation.
  access : read-write
  reset value : 0x0
  reset mask : 0x0
*/
volatile uint32_t DIV_UDIVISOR;

/** DIV_SDIVIDEND (offset: 0x68)
  Divider signed dividend

 The same as UDIVIDEND, but starts a signed calculation, rather than unsigned.
  access : read-write
  reset value : 0x0
  reset mask : 0x0
*/
volatile uint32_t DIV_SDIVIDEND;

/** DIV_SDIVISOR (offset: 0x6c)
  Divider signed divisor

 The same as UDIVISOR, but starts a signed calculation, rather than unsigned.
  access : read-write
  reset value : 0x0
  reset mask : 0x0
*/
volatile uint32_t DIV_SDIVISOR;

/** DIV_QUOTIENT (offset: 0x70)
  Divider result quotient

 The result of `DIVIDEND / DIVISOR` (division). Contents undefined while CSR_READY is low.

 For signed calculations, QUOTIENT is negative when the signs of DIVIDEND and DIVISOR differ.

 This register can be written to directly, for context save/restore purposes. This halts any

 in-progress calculation and sets the CSR_READY and CSR_DIRTY flags.

 Reading from QUOTIENT clears the CSR_DIRTY flag, so should read results in the order

 REMAINDER, QUOTIENT if CSR_DIRTY is used.
  access : read-write
  reset value : 0x0
  reset mask : 0x0
*/
volatile uint32_t DIV_QUOTIENT;

/** DIV_REMAINDER (offset: 0x74)
  Divider result remainder

 The result of `DIVIDEND % DIVISOR` (modulo). Contents undefined while CSR_READY is low.

 For signed calculations, REMAINDER is negative only when DIVIDEND is negative.

 This register can be written to directly, for context save/restore purposes. This halts any

 in-progress calculation and sets the CSR_READY and CSR_DIRTY flags.
  access : read-write
  reset value : 0x0
  reset mask : 0x0
*/
volatile uint32_t DIV_REMAINDER;

/** DIV_CSR (offset: 0x78)
  Control and status register for divider.
  access : read-write
  reset value : 0x1
  reset mask : 0x0
  Field: DIRTY
  offset: 1, size: 1, access: read-only
  Changes to 1 when any register is written, and back to 0 when QUOTIENT is read.

 Software can use this flag to make save/restore more efficient (skip if not DIRTY).

 If the flag is used in this way, it&apos;s recommended to either read QUOTIENT only,

 or REMAINDER and then QUOTIENT, to prevent data loss on context switch.
  Field: READY
  offset: 0, size: 1, access: read-only
  Reads as 0 when a calculation is in progress, 1 otherwise.

 Writing an operand (xDIVIDEND, xDIVISOR) will immediately start a new calculation, no

 matter if one is already in progress.

 Writing to a result register will immediately terminate any in-progress calculation

 and set the READY and DIRTY flags.
*/
volatile uint32_t DIV_CSR;
volatile uint32_t reserved1;

/** INTERP0_ACCUM0 (offset: 0x80)
  Read/write access to accumulator 0
  access : read-write
  reset value : 0x0
  reset mask : 0x0
*/
volatile uint32_t INTERP0_ACCUM0;

/** INTERP0_ACCUM1 (offset: 0x84)
  Read/write access to accumulator 1
  access : read-write
  reset value : 0x0
  reset mask : 0x0
*/
volatile uint32_t INTERP0_ACCUM1;

/** INTERP0_BASE0 (offset: 0x88)
  Read/write access to BASE0 register.
  access : read-write
  reset value : 0x0
  reset mask : 0x0
*/
volatile uint32_t INTERP0_BASE0;

/** INTERP0_BASE1 (offset: 0x8c)
  Read/write access to BASE1 register.
  access : read-write
  reset value : 0x0
  reset mask : 0x0
*/
volatile uint32_t INTERP0_BASE1;

/** INTERP0_BASE2 (offset: 0x90)
  Read/write access to BASE2 register.
  access : read-write
  reset value : 0x0
  reset mask : 0x0
*/
volatile uint32_t INTERP0_BASE2;

/** INTERP0_POP_LANE0 (offset: 0x94)
  Read LANE0 result, and simultaneously write lane results to both accumulators (POP).
  access : read-only
  reset value : 0x0
  reset mask : 0x0
*/
volatile uint32_t INTERP0_POP_LANE0;

/** INTERP0_POP_LANE1 (offset: 0x98)
  Read LANE1 result, and simultaneously write lane results to both accumulators (POP).
  access : read-only
  reset value : 0x0
  reset mask : 0x0
*/
volatile uint32_t INTERP0_POP_LANE1;

/** INTERP0_POP_FULL (offset: 0x9c)
  Read FULL result, and simultaneously write lane results to both accumulators (POP).
  access : read-only
  reset value : 0x0
  reset mask : 0x0
*/
volatile uint32_t INTERP0_POP_FULL;

/** INTERP0_PEEK_LANE0 (offset: 0xa0)
  Read LANE0 result, without altering any internal state (PEEK).
  access : read-only
  reset value : 0x0
  reset mask : 0x0
*/
volatile uint32_t INTERP0_PEEK_LANE0;

/** INTERP0_PEEK_LANE1 (offset: 0xa4)
  Read LANE1 result, without altering any internal state (PEEK).
  access : read-only
  reset value : 0x0
  reset mask : 0x0
*/
volatile uint32_t INTERP0_PEEK_LANE1;

/** INTERP0_PEEK_FULL (offset: 0xa8)
  Read FULL result, without altering any internal state (PEEK).
  access : read-only
  reset value : 0x0
  reset mask : 0x0
*/
volatile uint32_t INTERP0_PEEK_FULL;

/** INTERP0_CTRL_LANE0 (offset: 0xac)
  Control register for lane 0
  access : read-write
  reset value : 0x0
  reset mask : 0x0
  Field: OVERF
  offset: 25, size: 1, access: read-only
  Set if either OVERF0 or OVERF1 is set.
  Field: OVERF1
  offset: 24, size: 1, access: read-only
  Indicates if any masked-off MSBs in ACCUM1 are set.
  Field: OVERF0
  offset: 23, size: 1, access: read-only
  Indicates if any masked-off MSBs in ACCUM0 are set.
  Field: BLEND
  offset: 21, size: 1, access: read-write
  Only present on INTERP0 on each core. If BLEND mode is enabled:

 - LANE1 result is a linear interpolation between BASE0 and BASE1, controlled

 by the 8 LSBs of lane 1 shift and mask value (a fractional number between

 0 and 255/256ths)

 - LANE0 result does not have BASE0 added (yields only the 8 LSBs of lane 1 shift+mask value)

 - FULL result does not have lane 1 shift+mask value added (BASE2 + lane 0 shift+mask)

 LANE1 SIGNED flag controls whether the interpolation is signed or unsigned.
  Field: FORCE_MSB
  offset: 19, size: 2, access: read-write
  ORed into bits 29:28 of the lane result presented to the processor on the bus.

 No effect on the internal 32-bit datapath. Handy for using a lane to generate sequence

 of pointers into flash or SRAM.
  Field: ADD_RAW
  offset: 18, size: 1, access: read-write
  If 1, mask + shift is bypassed for LANE0 result. This does not affect FULL result.
  Field: CROSS_RESULT
  offset: 17, size: 1, access: read-write
  If 1, feed the opposite lane&apos;s result into this lane&apos;s accumulator on POP.
  Field: CROSS_INPUT
  offset: 16, size: 1, access: read-write
  If 1, feed the opposite lane&apos;s accumulator into this lane&apos;s shift + mask hardware.

 Takes effect even if ADD_RAW is set (the CROSS_INPUT mux is before the shift+mask bypass)
  Field: SIGNED
  offset: 15, size: 1, access: read-write
  If SIGNED is set, the shifted and masked accumulator value is sign-extended to 32 bits

 before adding to BASE0, and LANE0 PEEK/POP appear extended to 32 bits when read by processor.
  Field: MASK_MSB
  offset: 10, size: 5, access: read-write
  The most-significant bit allowed to pass by the mask (inclusive)

 Setting MSB &lt; LSB may cause chip to turn inside-out
  Field: MASK_LSB
  offset: 5, size: 5, access: read-write
  The least-significant bit allowed to pass by the mask (inclusive)
  Field: SHIFT
  offset: 0, size: 5, access: read-write
  Logical right-shift applied to accumulator before masking
*/
volatile uint32_t INTERP0_CTRL_LANE0;

/** INTERP0_CTRL_LANE1 (offset: 0xb0)
  Control register for lane 1
  access : read-write
  reset value : 0x0
  reset mask : 0x0
  Field: FORCE_MSB
  offset: 19, size: 2, access: read-write
  ORed into bits 29:28 of the lane result presented to the processor on the bus.

 No effect on the internal 32-bit datapath. Handy for using a lane to generate sequence

 of pointers into flash or SRAM.
  Field: ADD_RAW
  offset: 18, size: 1, access: read-write
  If 1, mask + shift is bypassed for LANE1 result. This does not affect FULL result.
  Field: CROSS_RESULT
  offset: 17, size: 1, access: read-write
  If 1, feed the opposite lane&apos;s result into this lane&apos;s accumulator on POP.
  Field: CROSS_INPUT
  offset: 16, size: 1, access: read-write
  If 1, feed the opposite lane&apos;s accumulator into this lane&apos;s shift + mask hardware.

 Takes effect even if ADD_RAW is set (the CROSS_INPUT mux is before the shift+mask bypass)
  Field: SIGNED
  offset: 15, size: 1, access: read-write
  If SIGNED is set, the shifted and masked accumulator value is sign-extended to 32 bits

 before adding to BASE1, and LANE1 PEEK/POP appear extended to 32 bits when read by processor.
  Field: MASK_MSB
  offset: 10, size: 5, access: read-write
  The most-significant bit allowed to pass by the mask (inclusive)

 Setting MSB &lt; LSB may cause chip to turn inside-out
  Field: MASK_LSB
  offset: 5, size: 5, access: read-write
  The least-significant bit allowed to pass by the mask (inclusive)
  Field: SHIFT
  offset: 0, size: 5, access: read-write
  Logical right-shift applied to accumulator before masking
*/
volatile uint32_t INTERP0_CTRL_LANE1;

/** INTERP0_ACCUM0_ADD (offset: 0xb4)
  Values written here are atomically added to ACCUM0

 Reading yields lane 0&apos;s raw shift and mask value (BASE0 not added).
  access : read-write
  reset value : 0x0
  reset mask : 0x0
  Field: INTERP0_ACCUM0_ADD
  offset: 0, size: 24, access: read-write
*/
volatile uint32_t INTERP0_ACCUM0_ADD;

/** INTERP0_ACCUM1_ADD (offset: 0xb8)
  Values written here are atomically added to ACCUM1

 Reading yields lane 1&apos;s raw shift and mask value (BASE1 not added).
  access : read-write
  reset value : 0x0
  reset mask : 0x0
  Field: INTERP0_ACCUM1_ADD
  offset: 0, size: 24, access: read-write
*/
volatile uint32_t INTERP0_ACCUM1_ADD;

/** INTERP0_BASE_1AND0 (offset: 0xbc)
  On write, the lower 16 bits go to BASE0, upper bits to BASE1 simultaneously.

 Each half is sign-extended to 32 bits if that lane&apos;s SIGNED flag is set.
  access : write-only
  reset value : 0x0
  reset mask : 0x0
*/
volatile uint32_t INTERP0_BASE_1AND0;

/** INTERP1_ACCUM0 (offset: 0xc0)
  Read/write access to accumulator 0
  access : read-write
  reset value : 0x0
  reset mask : 0x0
*/
volatile uint32_t INTERP1_ACCUM0;

/** INTERP1_ACCUM1 (offset: 0xc4)
  Read/write access to accumulator 1
  access : read-write
  reset value : 0x0
  reset mask : 0x0
*/
volatile uint32_t INTERP1_ACCUM1;

/** INTERP1_BASE0 (offset: 0xc8)
  Read/write access to BASE0 register.
  access : read-write
  reset value : 0x0
  reset mask : 0x0
*/
volatile uint32_t INTERP1_BASE0;

/** INTERP1_BASE1 (offset: 0xcc)
  Read/write access to BASE1 register.
  access : read-write
  reset value : 0x0
  reset mask : 0x0
*/
volatile uint32_t INTERP1_BASE1;

/** INTERP1_BASE2 (offset: 0xd0)
  Read/write access to BASE2 register.
  access : read-write
  reset value : 0x0
  reset mask : 0x0
*/
volatile uint32_t INTERP1_BASE2;

/** INTERP1_POP_LANE0 (offset: 0xd4)
  Read LANE0 result, and simultaneously write lane results to both accumulators (POP).
  access : read-only
  reset value : 0x0
  reset mask : 0x0
*/
volatile uint32_t INTERP1_POP_LANE0;

/** INTERP1_POP_LANE1 (offset: 0xd8)
  Read LANE1 result, and simultaneously write lane results to both accumulators (POP).
  access : read-only
  reset value : 0x0
  reset mask : 0x0
*/
volatile uint32_t INTERP1_POP_LANE1;

/** INTERP1_POP_FULL (offset: 0xdc)
  Read FULL result, and simultaneously write lane results to both accumulators (POP).
  access : read-only
  reset value : 0x0
  reset mask : 0x0
*/
volatile uint32_t INTERP1_POP_FULL;

/** INTERP1_PEEK_LANE0 (offset: 0xe0)
  Read LANE0 result, without altering any internal state (PEEK).
  access : read-only
  reset value : 0x0
  reset mask : 0x0
*/
volatile uint32_t INTERP1_PEEK_LANE0;

/** INTERP1_PEEK_LANE1 (offset: 0xe4)
  Read LANE1 result, without altering any internal state (PEEK).
  access : read-only
  reset value : 0x0
  reset mask : 0x0
*/
volatile uint32_t INTERP1_PEEK_LANE1;

/** INTERP1_PEEK_FULL (offset: 0xe8)
  Read FULL result, without altering any internal state (PEEK).
  access : read-only
  reset value : 0x0
  reset mask : 0x0
*/
volatile uint32_t INTERP1_PEEK_FULL;

/** INTERP1_CTRL_LANE0 (offset: 0xec)
  Control register for lane 0
  access : read-write
  reset value : 0x0
  reset mask : 0x0
  Field: OVERF
  offset: 25, size: 1, access: read-only
  Set if either OVERF0 or OVERF1 is set.
  Field: OVERF1
  offset: 24, size: 1, access: read-only
  Indicates if any masked-off MSBs in ACCUM1 are set.
  Field: OVERF0
  offset: 23, size: 1, access: read-only
  Indicates if any masked-off MSBs in ACCUM0 are set.
  Field: CLAMP
  offset: 22, size: 1, access: read-write
  Only present on INTERP1 on each core. If CLAMP mode is enabled:

 - LANE0 result is shifted and masked ACCUM0, clamped by a lower bound of

 BASE0 and an upper bound of BASE1.

 - Signedness of these comparisons is determined by LANE0_CTRL_SIGNED
  Field: FORCE_MSB
  offset: 19, size: 2, access: read-write
  ORed into bits 29:28 of the lane result presented to the processor on the bus.

 No effect on the internal 32-bit datapath. Handy for using a lane to generate sequence

 of pointers into flash or SRAM.
  Field: ADD_RAW
  offset: 18, size: 1, access: read-write
  If 1, mask + shift is bypassed for LANE0 result. This does not affect FULL result.
  Field: CROSS_RESULT
  offset: 17, size: 1, access: read-write
  If 1, feed the opposite lane&apos;s result into this lane&apos;s accumulator on POP.
  Field: CROSS_INPUT
  offset: 16, size: 1, access: read-write
  If 1, feed the opposite lane&apos;s accumulator into this lane&apos;s shift + mask hardware.

 Takes effect even if ADD_RAW is set (the CROSS_INPUT mux is before the shift+mask bypass)
  Field: SIGNED
  offset: 15, size: 1, access: read-write
  If SIGNED is set, the shifted and masked accumulator value is sign-extended to 32 bits

 before adding to BASE0, and LANE0 PEEK/POP appear extended to 32 bits when read by processor.
  Field: MASK_MSB
  offset: 10, size: 5, access: read-write
  The most-significant bit allowed to pass by the mask (inclusive)

 Setting MSB &lt; LSB may cause chip to turn inside-out
  Field: MASK_LSB
  offset: 5, size: 5, access: read-write
  The least-significant bit allowed to pass by the mask (inclusive)
  Field: SHIFT
  offset: 0, size: 5, access: read-write
  Logical right-shift applied to accumulator before masking
*/
volatile uint32_t INTERP1_CTRL_LANE0;

/** INTERP1_CTRL_LANE1 (offset: 0xf0)
  Control register for lane 1
  access : read-write
  reset value : 0x0
  reset mask : 0x0
  Field: FORCE_MSB
  offset: 19, size: 2, access: read-write
  ORed into bits 29:28 of the lane result presented to the processor on the bus.

 No effect on the internal 32-bit datapath. Handy for using a lane to generate sequence

 of pointers into flash or SRAM.
  Field: ADD_RAW
  offset: 18, size: 1, access: read-write
  If 1, mask + shift is bypassed for LANE1 result. This does not affect FULL result.
  Field: CROSS_RESULT
  offset: 17, size: 1, access: read-write
  If 1, feed the opposite lane&apos;s result into this lane&apos;s accumulator on POP.
  Field: CROSS_INPUT
  offset: 16, size: 1, access: read-write
  If 1, feed the opposite lane&apos;s accumulator into this lane&apos;s shift + mask hardware.

 Takes effect even if ADD_RAW is set (the CROSS_INPUT mux is before the shift+mask bypass)
  Field: SIGNED
  offset: 15, size: 1, access: read-write
  If SIGNED is set, the shifted and masked accumulator value is sign-extended to 32 bits

 before adding to BASE1, and LANE1 PEEK/POP appear extended to 32 bits when read by processor.
  Field: MASK_MSB
  offset: 10, size: 5, access: read-write
  The most-significant bit allowed to pass by the mask (inclusive)

 Setting MSB &lt; LSB may cause chip to turn inside-out
  Field: MASK_LSB
  offset: 5, size: 5, access: read-write
  The least-significant bit allowed to pass by the mask (inclusive)
  Field: SHIFT
  offset: 0, size: 5, access: read-write
  Logical right-shift applied to accumulator before masking
*/
volatile uint32_t INTERP1_CTRL_LANE1;

/** INTERP1_ACCUM0_ADD (offset: 0xf4)
  Values written here are atomically added to ACCUM0

 Reading yields lane 0&apos;s raw shift and mask value (BASE0 not added).
  access : read-write
  reset value : 0x0
  reset mask : 0x0
  Field: INTERP1_ACCUM0_ADD
  offset: 0, size: 24, access: read-write
*/
volatile uint32_t INTERP1_ACCUM0_ADD;

/** INTERP1_ACCUM1_ADD (offset: 0xf8)
  Values written here are atomically added to ACCUM1

 Reading yields lane 1&apos;s raw shift and mask value (BASE1 not added).
  access : read-write
  reset value : 0x0
  reset mask : 0x0
  Field: INTERP1_ACCUM1_ADD
  offset: 0, size: 24, access: read-write
*/
volatile uint32_t INTERP1_ACCUM1_ADD;

/** INTERP1_BASE_1AND0 (offset: 0xfc)
  On write, the lower 16 bits go to BASE0, upper bits to BASE1 simultaneously.

 Each half is sign-extended to 32 bits if that lane&apos;s SIGNED flag is set.
  access : write-only
  reset value : 0x0
  reset mask : 0x0
*/
volatile uint32_t INTERP1_BASE_1AND0;

/** SPINLOCK0 (offset: 0x100)
  Reading from a spinlock address will:

 - Return 0 if lock is already locked

 - Otherwise return nonzero, and simultaneously claim the lock


 Writing (any value) releases the lock.

 If core 0 and core 1 attempt to claim the same lock simultaneously, core 0 wins.

 The value returned on success is 0x1 &lt;&lt; lock number.
  access : read-write
  reset value : 0x0
  reset mask : 0x0
*/
volatile uint32_t SPINLOCK0;

/** SPINLOCK1 (offset: 0x104)
  Reading from a spinlock address will:

 - Return 0 if lock is already locked

 - Otherwise return nonzero, and simultaneously claim the lock


 Writing (any value) releases the lock.

 If core 0 and core 1 attempt to claim the same lock simultaneously, core 0 wins.

 The value returned on success is 0x1 &lt;&lt; lock number.
  access : read-write
  reset value : 0x0
  reset mask : 0x0
*/
volatile uint32_t SPINLOCK1;

/** SPINLOCK2 (offset: 0x108)
  Reading from a spinlock address will:

 - Return 0 if lock is already locked

 - Otherwise return nonzero, and simultaneously claim the lock


 Writing (any value) releases the lock.

 If core 0 and core 1 attempt to claim the same lock simultaneously, core 0 wins.

 The value returned on success is 0x1 &lt;&lt; lock number.
  access : read-write
  reset value : 0x0
  reset mask : 0x0
*/
volatile uint32_t SPINLOCK2;

/** SPINLOCK3 (offset: 0x10c)
  Reading from a spinlock address will:

 - Return 0 if lock is already locked

 - Otherwise return nonzero, and simultaneously claim the lock


 Writing (any value) releases the lock.

 If core 0 and core 1 attempt to claim the same lock simultaneously, core 0 wins.

 The value returned on success is 0x1 &lt;&lt; lock number.
  access : read-write
  reset value : 0x0
  reset mask : 0x0
*/
volatile uint32_t SPINLOCK3;

/** SPINLOCK4 (offset: 0x110)
  Reading from a spinlock address will:

 - Return 0 if lock is already locked

 - Otherwise return nonzero, and simultaneously claim the lock


 Writing (any value) releases the lock.

 If core 0 and core 1 attempt to claim the same lock simultaneously, core 0 wins.

 The value returned on success is 0x1 &lt;&lt; lock number.
  access : read-write
  reset value : 0x0
  reset mask : 0x0
*/
volatile uint32_t SPINLOCK4;

/** SPINLOCK5 (offset: 0x114)
  Reading from a spinlock address will:

 - Return 0 if lock is already locked

 - Otherwise return nonzero, and simultaneously claim the lock


 Writing (any value) releases the lock.

 If core 0 and core 1 attempt to claim the same lock simultaneously, core 0 wins.

 The value returned on success is 0x1 &lt;&lt; lock number.
  access : read-write
  reset value : 0x0
  reset mask : 0x0
*/
volatile uint32_t SPINLOCK5;

/** SPINLOCK6 (offset: 0x118)
  Reading from a spinlock address will:

 - Return 0 if lock is already locked

 - Otherwise return nonzero, and simultaneously claim the lock


 Writing (any value) releases the lock.

 If core 0 and core 1 attempt to claim the same lock simultaneously, core 0 wins.

 The value returned on success is 0x1 &lt;&lt; lock number.
  access : read-write
  reset value : 0x0
  reset mask : 0x0
*/
volatile uint32_t SPINLOCK6;

/** SPINLOCK7 (offset: 0x11c)
  Reading from a spinlock address will:

 - Return 0 if lock is already locked

 - Otherwise return nonzero, and simultaneously claim the lock


 Writing (any value) releases the lock.

 If core 0 and core 1 attempt to claim the same lock simultaneously, core 0 wins.

 The value returned on success is 0x1 &lt;&lt; lock number.
  access : read-write
  reset value : 0x0
  reset mask : 0x0
*/
volatile uint32_t SPINLOCK7;

/** SPINLOCK8 (offset: 0x120)
  Reading from a spinlock address will:

 - Return 0 if lock is already locked

 - Otherwise return nonzero, and simultaneously claim the lock


 Writing (any value) releases the lock.

 If core 0 and core 1 attempt to claim the same lock simultaneously, core 0 wins.

 The value returned on success is 0x1 &lt;&lt; lock number.
  access : read-write
  reset value : 0x0
  reset mask : 0x0
*/
volatile uint32_t SPINLOCK8;

/** SPINLOCK9 (offset: 0x124)
  Reading from a spinlock address will:

 - Return 0 if lock is already locked

 - Otherwise return nonzero, and simultaneously claim the lock


 Writing (any value) releases the lock.

 If core 0 and core 1 attempt to claim the same lock simultaneously, core 0 wins.

 The value returned on success is 0x1 &lt;&lt; lock number.
  access : read-write
  reset value : 0x0
  reset mask : 0x0
*/
volatile uint32_t SPINLOCK9;

/** SPINLOCK10 (offset: 0x128)
  Reading from a spinlock address will:

 - Return 0 if lock is already locked

 - Otherwise return nonzero, and simultaneously claim the lock


 Writing (any value) releases the lock.

 If core 0 and core 1 attempt to claim the same lock simultaneously, core 0 wins.

 The value returned on success is 0x1 &lt;&lt; lock number.
  access : read-write
  reset value : 0x0
  reset mask : 0x0
*/
volatile uint32_t SPINLOCK10;

/** SPINLOCK11 (offset: 0x12c)
  Reading from a spinlock address will:

 - Return 0 if lock is already locked

 - Otherwise return nonzero, and simultaneously claim the lock


 Writing (any value) releases the lock.

 If core 0 and core 1 attempt to claim the same lock simultaneously, core 0 wins.

 The value returned on success is 0x1 &lt;&lt; lock number.
  access : read-write
  reset value : 0x0
  reset mask : 0x0
*/
volatile uint32_t SPINLOCK11;

/** SPINLOCK12 (offset: 0x130)
  Reading from a spinlock address will:

 - Return 0 if lock is already locked

 - Otherwise return nonzero, and simultaneously claim the lock


 Writing (any value) releases the lock.

 If core 0 and core 1 attempt to claim the same lock simultaneously, core 0 wins.

 The value returned on success is 0x1 &lt;&lt; lock number.
  access : read-write
  reset value : 0x0
  reset mask : 0x0
*/
volatile uint32_t SPINLOCK12;

/** SPINLOCK13 (offset: 0x134)
  Reading from a spinlock address will:

 - Return 0 if lock is already locked

 - Otherwise return nonzero, and simultaneously claim the lock


 Writing (any value) releases the lock.

 If core 0 and core 1 attempt to claim the same lock simultaneously, core 0 wins.

 The value returned on success is 0x1 &lt;&lt; lock number.
  access : read-write
  reset value : 0x0
  reset mask : 0x0
*/
volatile uint32_t SPINLOCK13;

/** SPINLOCK14 (offset: 0x138)
  Reading from a spinlock address will:

 - Return 0 if lock is already locked

 - Otherwise return nonzero, and simultaneously claim the lock


 Writing (any value) releases the lock.

 If core 0 and core 1 attempt to claim the same lock simultaneously, core 0 wins.

 The value returned on success is 0x1 &lt;&lt; lock number.
  access : read-write
  reset value : 0x0
  reset mask : 0x0
*/
volatile uint32_t SPINLOCK14;

/** SPINLOCK15 (offset: 0x13c)
  Reading from a spinlock address will:

 - Return 0 if lock is already locked

 - Otherwise return nonzero, and simultaneously claim the lock


 Writing (any value) releases the lock.

 If core 0 and core 1 attempt to claim the same lock simultaneously, core 0 wins.

 The value returned on success is 0x1 &lt;&lt; lock number.
  access : read-write
  reset value : 0x0
  reset mask : 0x0
*/
volatile uint32_t SPINLOCK15;

/** SPINLOCK16 (offset: 0x140)
  Reading from a spinlock address will:

 - Return 0 if lock is already locked

 - Otherwise return nonzero, and simultaneously claim the lock


 Writing (any value) releases the lock.

 If core 0 and core 1 attempt to claim the same lock simultaneously, core 0 wins.

 The value returned on success is 0x1 &lt;&lt; lock number.
  access : read-write
  reset value : 0x0
  reset mask : 0x0
*/
volatile uint32_t SPINLOCK16;

/** SPINLOCK17 (offset: 0x144)
  Reading from a spinlock address will:

 - Return 0 if lock is already locked

 - Otherwise return nonzero, and simultaneously claim the lock


 Writing (any value) releases the lock.

 If core 0 and core 1 attempt to claim the same lock simultaneously, core 0 wins.

 The value returned on success is 0x1 &lt;&lt; lock number.
  access : read-write
  reset value : 0x0
  reset mask : 0x0
*/
volatile uint32_t SPINLOCK17;

/** SPINLOCK18 (offset: 0x148)
  Reading from a spinlock address will:

 - Return 0 if lock is already locked

 - Otherwise return nonzero, and simultaneously claim the lock


 Writing (any value) releases the lock.

 If core 0 and core 1 attempt to claim the same lock simultaneously, core 0 wins.

 The value returned on success is 0x1 &lt;&lt; lock number.
  access : read-write
  reset value : 0x0
  reset mask : 0x0
*/
volatile uint32_t SPINLOCK18;

/** SPINLOCK19 (offset: 0x14c)
  Reading from a spinlock address will:

 - Return 0 if lock is already locked

 - Otherwise return nonzero, and simultaneously claim the lock


 Writing (any value) releases the lock.

 If core 0 and core 1 attempt to claim the same lock simultaneously, core 0 wins.

 The value returned on success is 0x1 &lt;&lt; lock number.
  access : read-write
  reset value : 0x0
  reset mask : 0x0
*/
volatile uint32_t SPINLOCK19;

/** SPINLOCK20 (offset: 0x150)
  Reading from a spinlock address will:

 - Return 0 if lock is already locked

 - Otherwise return nonzero, and simultaneously claim the lock


 Writing (any value) releases the lock.

 If core 0 and core 1 attempt to claim the same lock simultaneously, core 0 wins.

 The value returned on success is 0x1 &lt;&lt; lock number.
  access : read-write
  reset value : 0x0
  reset mask : 0x0
*/
volatile uint32_t SPINLOCK20;

/** SPINLOCK21 (offset: 0x154)
  Reading from a spinlock address will:

 - Return 0 if lock is already locked

 - Otherwise return nonzero, and simultaneously claim the lock


 Writing (any value) releases the lock.

 If core 0 and core 1 attempt to claim the same lock simultaneously, core 0 wins.

 The value returned on success is 0x1 &lt;&lt; lock number.
  access : read-write
  reset value : 0x0
  reset mask : 0x0
*/
volatile uint32_t SPINLOCK21;

/** SPINLOCK22 (offset: 0x158)
  Reading from a spinlock address will:

 - Return 0 if lock is already locked

 - Otherwise return nonzero, and simultaneously claim the lock


 Writing (any value) releases the lock.

 If core 0 and core 1 attempt to claim the same lock simultaneously, core 0 wins.

 The value returned on success is 0x1 &lt;&lt; lock number.
  access : read-write
  reset value : 0x0
  reset mask : 0x0
*/
volatile uint32_t SPINLOCK22;

/** SPINLOCK23 (offset: 0x15c)
  Reading from a spinlock address will:

 - Return 0 if lock is already locked

 - Otherwise return nonzero, and simultaneously claim the lock


 Writing (any value) releases the lock.

 If core 0 and core 1 attempt to claim the same lock simultaneously, core 0 wins.

 The value returned on success is 0x1 &lt;&lt; lock number.
  access : read-write
  reset value : 0x0
  reset mask : 0x0
*/
volatile uint32_t SPINLOCK23;

/** SPINLOCK24 (offset: 0x160)
  Reading from a spinlock address will:

 - Return 0 if lock is already locked

 - Otherwise return nonzero, and simultaneously claim the lock


 Writing (any value) releases the lock.

 If core 0 and core 1 attempt to claim the same lock simultaneously, core 0 wins.

 The value returned on success is 0x1 &lt;&lt; lock number.
  access : read-write
  reset value : 0x0
  reset mask : 0x0
*/
volatile uint32_t SPINLOCK24;

/** SPINLOCK25 (offset: 0x164)
  Reading from a spinlock address will:

 - Return 0 if lock is already locked

 - Otherwise return nonzero, and simultaneously claim the lock


 Writing (any value) releases the lock.

 If core 0 and core 1 attempt to claim the same lock simultaneously, core 0 wins.

 The value returned on success is 0x1 &lt;&lt; lock number.
  access : read-write
  reset value : 0x0
  reset mask : 0x0
*/
volatile uint32_t SPINLOCK25;

/** SPINLOCK26 (offset: 0x168)
  Reading from a spinlock address will:

 - Return 0 if lock is already locked

 - Otherwise return nonzero, and simultaneously claim the lock


 Writing (any value) releases the lock.

 If core 0 and core 1 attempt to claim the same lock simultaneously, core 0 wins.

 The value returned on success is 0x1 &lt;&lt; lock number.
  access : read-write
  reset value : 0x0
  reset mask : 0x0
*/
volatile uint32_t SPINLOCK26;

/** SPINLOCK27 (offset: 0x16c)
  Reading from a spinlock address will:

 - Return 0 if lock is already locked

 - Otherwise return nonzero, and simultaneously claim the lock


 Writing (any value) releases the lock.

 If core 0 and core 1 attempt to claim the same lock simultaneously, core 0 wins.

 The value returned on success is 0x1 &lt;&lt; lock number.
  access : read-write
  reset value : 0x0
  reset mask : 0x0
*/
volatile uint32_t SPINLOCK27;

/** SPINLOCK28 (offset: 0x170)
  Reading from a spinlock address will:

 - Return 0 if lock is already locked

 - Otherwise return nonzero, and simultaneously claim the lock


 Writing (any value) releases the lock.

 If core 0 and core 1 attempt to claim the same lock simultaneously, core 0 wins.

 The value returned on success is 0x1 &lt;&lt; lock number.
  access : read-write
  reset value : 0x0
  reset mask : 0x0
*/
volatile uint32_t SPINLOCK28;

/** SPINLOCK29 (offset: 0x174)
  Reading from a spinlock address will:

 - Return 0 if lock is already locked

 - Otherwise return nonzero, and simultaneously claim the lock


 Writing (any value) releases the lock.

 If core 0 and core 1 attempt to claim the same lock simultaneously, core 0 wins.

 The value returned on success is 0x1 &lt;&lt; lock number.
  access : read-write
  reset value : 0x0
  reset mask : 0x0
*/
volatile uint32_t SPINLOCK29;

/** SPINLOCK30 (offset: 0x178)
  Reading from a spinlock address will:

 - Return 0 if lock is already locked

 - Otherwise return nonzero, and simultaneously claim the lock


 Writing (any value) releases the lock.

 If core 0 and core 1 attempt to claim the same lock simultaneously, core 0 wins.

 The value returned on success is 0x1 &lt;&lt; lock number.
  access : read-write
  reset value : 0x0
  reset mask : 0x0
*/
volatile uint32_t SPINLOCK30;

/** SPINLOCK31 (offset: 0x17c)
  Reading from a spinlock address will:

 - Return 0 if lock is already locked

 - Otherwise return nonzero, and simultaneously claim the lock


 Writing (any value) releases the lock.

 If core 0 and core 1 attempt to claim the same lock simultaneously, core 0 wins.

 The value returned on success is 0x1 &lt;&lt; lock number.
  access : read-write
  reset value : 0x0
  reset mask : 0x0
*/
volatile uint32_t SPINLOCK31;
} SIO_type;

#define SIO ((SIO_type *) 0xD0000000)

#endif // HW_SIO_H
