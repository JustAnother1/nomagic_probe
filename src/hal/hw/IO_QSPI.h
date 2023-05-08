#ifndef HW_IO_QSPI_H
#define HW_IO_QSPI_H
/* Interrupt : IO_IRQ_QSPI (Vector: 14)  */
/* Memory Block starting at 0x40018000 + 0x0 is 0x1000 bytes in size. It is used for registers. Protection: n */

#include <stdint.h>

typedef struct
{

/* GPIO_QSPI_SCLK_STATUS (offset: 0x0)
  GPIO status
  access : read-write
  reset value : 0x0
  reset mask : 0x0
  Field: IRQTOPROC
  offset: 26, size: 1, access: read-only
  interrupt to processors, after override is applied
  Field: IRQFROMPAD
  offset: 24, size: 1, access: read-only
  interrupt from pad before override is applied
  Field: INTOPERI
  offset: 19, size: 1, access: read-only
  input signal to peripheral, after override is applied
  Field: INFROMPAD
  offset: 17, size: 1, access: read-only
  input signal from pad, before override is applied
  Field: OETOPAD
  offset: 13, size: 1, access: read-only
  output enable to pad after register override is applied
  Field: OEFROMPERI
  offset: 12, size: 1, access: read-only
  output enable from selected peripheral, before register override is applied
  Field: OUTTOPAD
  offset: 9, size: 1, access: read-only
  output signal to pad after register override is applied
  Field: OUTFROMPERI
  offset: 8, size: 1, access: read-only
  output signal from selected peripheral, before register override is applied
*/
volatile uint32_t GPIO_QSPI_SCLK_STATUS;

/* GPIO_QSPI_SCLK_CTRL (offset: 0x4)
  GPIO control including function select and overrides.
  access : read-write
  reset value : 0x1F
  reset mask : 0x0
  Field: IRQOVER
  offset: 28, size: 2, access: read-write
  Enum: 
  Value: 0 - NORMAL : don&apos;t invert the interrupt
  Value: 1 - INVERT : invert the interrupt
  Value: 2 - LOW : drive interrupt low
  Value: 3 - HIGH : drive interrupt high
  Field: INOVER
  offset: 16, size: 2, access: read-write
  Enum: 
  Value: 0 - NORMAL : don&apos;t invert the peri input
  Value: 1 - INVERT : invert the peri input
  Value: 2 - LOW : drive peri input low
  Value: 3 - HIGH : drive peri input high
  Field: OEOVER
  offset: 12, size: 2, access: read-write
  Enum: 
  Value: 0 - NORMAL : drive output enable from peripheral signal selected by funcsel
  Value: 1 - INVERT : drive output enable from inverse of peripheral signal selected by funcsel
  Value: 2 - DISABLE : disable output
  Value: 3 - ENABLE : enable output
  Field: OUTOVER
  offset: 8, size: 2, access: read-write
  Enum: 
  Value: 0 - NORMAL : drive output from peripheral signal selected by funcsel
  Value: 1 - INVERT : drive output from inverse of peripheral signal selected by funcsel
  Value: 2 - LOW : drive output low
  Value: 3 - HIGH : drive output high
  Field: FUNCSEL
  offset: 0, size: 5, access: read-write
  0-31 -&gt; selects pin function according to the gpio table

 31 == NULL
  Enum: 
  Value: 0 - xip_sclk
  Value: 5 - sio_30
  Value: 0x1f - null
*/
volatile uint32_t GPIO_QSPI_SCLK_CTRL;

/* GPIO_QSPI_SS_STATUS (offset: 0x8)
  GPIO status
  access : read-write
  reset value : 0x0
  reset mask : 0x0
  Field: IRQTOPROC
  offset: 26, size: 1, access: read-only
  interrupt to processors, after override is applied
  Field: IRQFROMPAD
  offset: 24, size: 1, access: read-only
  interrupt from pad before override is applied
  Field: INTOPERI
  offset: 19, size: 1, access: read-only
  input signal to peripheral, after override is applied
  Field: INFROMPAD
  offset: 17, size: 1, access: read-only
  input signal from pad, before override is applied
  Field: OETOPAD
  offset: 13, size: 1, access: read-only
  output enable to pad after register override is applied
  Field: OEFROMPERI
  offset: 12, size: 1, access: read-only
  output enable from selected peripheral, before register override is applied
  Field: OUTTOPAD
  offset: 9, size: 1, access: read-only
  output signal to pad after register override is applied
  Field: OUTFROMPERI
  offset: 8, size: 1, access: read-only
  output signal from selected peripheral, before register override is applied
*/
volatile uint32_t GPIO_QSPI_SS_STATUS;

/* GPIO_QSPI_SS_CTRL (offset: 0xc)
  GPIO control including function select and overrides.
  access : read-write
  reset value : 0x1F
  reset mask : 0x0
  Field: IRQOVER
  offset: 28, size: 2, access: read-write
  Enum: 
  Value: 0 - NORMAL : don&apos;t invert the interrupt
  Value: 1 - INVERT : invert the interrupt
  Value: 2 - LOW : drive interrupt low
  Value: 3 - HIGH : drive interrupt high
  Field: INOVER
  offset: 16, size: 2, access: read-write
  Enum: 
  Value: 0 - NORMAL : don&apos;t invert the peri input
  Value: 1 - INVERT : invert the peri input
  Value: 2 - LOW : drive peri input low
  Value: 3 - HIGH : drive peri input high
  Field: OEOVER
  offset: 12, size: 2, access: read-write
  Enum: 
  Value: 0 - NORMAL : drive output enable from peripheral signal selected by funcsel
  Value: 1 - INVERT : drive output enable from inverse of peripheral signal selected by funcsel
  Value: 2 - DISABLE : disable output
  Value: 3 - ENABLE : enable output
  Field: OUTOVER
  offset: 8, size: 2, access: read-write
  Enum: 
  Value: 0 - NORMAL : drive output from peripheral signal selected by funcsel
  Value: 1 - INVERT : drive output from inverse of peripheral signal selected by funcsel
  Value: 2 - LOW : drive output low
  Value: 3 - HIGH : drive output high
  Field: FUNCSEL
  offset: 0, size: 5, access: read-write
  0-31 -&gt; selects pin function according to the gpio table

 31 == NULL
  Enum: 
  Value: 0 - xip_ss_n
  Value: 5 - sio_31
  Value: 0x1f - null
*/
volatile uint32_t GPIO_QSPI_SS_CTRL;

/* GPIO_QSPI_SD0_STATUS (offset: 0x10)
  GPIO status
  access : read-write
  reset value : 0x0
  reset mask : 0x0
  Field: IRQTOPROC
  offset: 26, size: 1, access: read-only
  interrupt to processors, after override is applied
  Field: IRQFROMPAD
  offset: 24, size: 1, access: read-only
  interrupt from pad before override is applied
  Field: INTOPERI
  offset: 19, size: 1, access: read-only
  input signal to peripheral, after override is applied
  Field: INFROMPAD
  offset: 17, size: 1, access: read-only
  input signal from pad, before override is applied
  Field: OETOPAD
  offset: 13, size: 1, access: read-only
  output enable to pad after register override is applied
  Field: OEFROMPERI
  offset: 12, size: 1, access: read-only
  output enable from selected peripheral, before register override is applied
  Field: OUTTOPAD
  offset: 9, size: 1, access: read-only
  output signal to pad after register override is applied
  Field: OUTFROMPERI
  offset: 8, size: 1, access: read-only
  output signal from selected peripheral, before register override is applied
*/
volatile uint32_t GPIO_QSPI_SD0_STATUS;

/* GPIO_QSPI_SD0_CTRL (offset: 0x14)
  GPIO control including function select and overrides.
  access : read-write
  reset value : 0x1F
  reset mask : 0x0
  Field: IRQOVER
  offset: 28, size: 2, access: read-write
  Enum: 
  Value: 0 - NORMAL : don&apos;t invert the interrupt
  Value: 1 - INVERT : invert the interrupt
  Value: 2 - LOW : drive interrupt low
  Value: 3 - HIGH : drive interrupt high
  Field: INOVER
  offset: 16, size: 2, access: read-write
  Enum: 
  Value: 0 - NORMAL : don&apos;t invert the peri input
  Value: 1 - INVERT : invert the peri input
  Value: 2 - LOW : drive peri input low
  Value: 3 - HIGH : drive peri input high
  Field: OEOVER
  offset: 12, size: 2, access: read-write
  Enum: 
  Value: 0 - NORMAL : drive output enable from peripheral signal selected by funcsel
  Value: 1 - INVERT : drive output enable from inverse of peripheral signal selected by funcsel
  Value: 2 - DISABLE : disable output
  Value: 3 - ENABLE : enable output
  Field: OUTOVER
  offset: 8, size: 2, access: read-write
  Enum: 
  Value: 0 - NORMAL : drive output from peripheral signal selected by funcsel
  Value: 1 - INVERT : drive output from inverse of peripheral signal selected by funcsel
  Value: 2 - LOW : drive output low
  Value: 3 - HIGH : drive output high
  Field: FUNCSEL
  offset: 0, size: 5, access: read-write
  0-31 -&gt; selects pin function according to the gpio table

 31 == NULL
  Enum: 
  Value: 0 - xip_sd0
  Value: 5 - sio_32
  Value: 0x1f - null
*/
volatile uint32_t GPIO_QSPI_SD0_CTRL;

/* GPIO_QSPI_SD1_STATUS (offset: 0x18)
  GPIO status
  access : read-write
  reset value : 0x0
  reset mask : 0x0
  Field: IRQTOPROC
  offset: 26, size: 1, access: read-only
  interrupt to processors, after override is applied
  Field: IRQFROMPAD
  offset: 24, size: 1, access: read-only
  interrupt from pad before override is applied
  Field: INTOPERI
  offset: 19, size: 1, access: read-only
  input signal to peripheral, after override is applied
  Field: INFROMPAD
  offset: 17, size: 1, access: read-only
  input signal from pad, before override is applied
  Field: OETOPAD
  offset: 13, size: 1, access: read-only
  output enable to pad after register override is applied
  Field: OEFROMPERI
  offset: 12, size: 1, access: read-only
  output enable from selected peripheral, before register override is applied
  Field: OUTTOPAD
  offset: 9, size: 1, access: read-only
  output signal to pad after register override is applied
  Field: OUTFROMPERI
  offset: 8, size: 1, access: read-only
  output signal from selected peripheral, before register override is applied
*/
volatile uint32_t GPIO_QSPI_SD1_STATUS;

/* GPIO_QSPI_SD1_CTRL (offset: 0x1c)
  GPIO control including function select and overrides.
  access : read-write
  reset value : 0x1F
  reset mask : 0x0
  Field: IRQOVER
  offset: 28, size: 2, access: read-write
  Enum: 
  Value: 0 - NORMAL : don&apos;t invert the interrupt
  Value: 1 - INVERT : invert the interrupt
  Value: 2 - LOW : drive interrupt low
  Value: 3 - HIGH : drive interrupt high
  Field: INOVER
  offset: 16, size: 2, access: read-write
  Enum: 
  Value: 0 - NORMAL : don&apos;t invert the peri input
  Value: 1 - INVERT : invert the peri input
  Value: 2 - LOW : drive peri input low
  Value: 3 - HIGH : drive peri input high
  Field: OEOVER
  offset: 12, size: 2, access: read-write
  Enum: 
  Value: 0 - NORMAL : drive output enable from peripheral signal selected by funcsel
  Value: 1 - INVERT : drive output enable from inverse of peripheral signal selected by funcsel
  Value: 2 - DISABLE : disable output
  Value: 3 - ENABLE : enable output
  Field: OUTOVER
  offset: 8, size: 2, access: read-write
  Enum: 
  Value: 0 - NORMAL : drive output from peripheral signal selected by funcsel
  Value: 1 - INVERT : drive output from inverse of peripheral signal selected by funcsel
  Value: 2 - LOW : drive output low
  Value: 3 - HIGH : drive output high
  Field: FUNCSEL
  offset: 0, size: 5, access: read-write
  0-31 -&gt; selects pin function according to the gpio table

 31 == NULL
  Enum: 
  Value: 0 - xip_sd1
  Value: 5 - sio_33
  Value: 0x1f - null
*/
volatile uint32_t GPIO_QSPI_SD1_CTRL;

/* GPIO_QSPI_SD2_STATUS (offset: 0x20)
  GPIO status
  access : read-write
  reset value : 0x0
  reset mask : 0x0
  Field: IRQTOPROC
  offset: 26, size: 1, access: read-only
  interrupt to processors, after override is applied
  Field: IRQFROMPAD
  offset: 24, size: 1, access: read-only
  interrupt from pad before override is applied
  Field: INTOPERI
  offset: 19, size: 1, access: read-only
  input signal to peripheral, after override is applied
  Field: INFROMPAD
  offset: 17, size: 1, access: read-only
  input signal from pad, before override is applied
  Field: OETOPAD
  offset: 13, size: 1, access: read-only
  output enable to pad after register override is applied
  Field: OEFROMPERI
  offset: 12, size: 1, access: read-only
  output enable from selected peripheral, before register override is applied
  Field: OUTTOPAD
  offset: 9, size: 1, access: read-only
  output signal to pad after register override is applied
  Field: OUTFROMPERI
  offset: 8, size: 1, access: read-only
  output signal from selected peripheral, before register override is applied
*/
volatile uint32_t GPIO_QSPI_SD2_STATUS;

/* GPIO_QSPI_SD2_CTRL (offset: 0x24)
  GPIO control including function select and overrides.
  access : read-write
  reset value : 0x1F
  reset mask : 0x0
  Field: IRQOVER
  offset: 28, size: 2, access: read-write
  Enum: 
  Value: 0 - NORMAL : don&apos;t invert the interrupt
  Value: 1 - INVERT : invert the interrupt
  Value: 2 - LOW : drive interrupt low
  Value: 3 - HIGH : drive interrupt high
  Field: INOVER
  offset: 16, size: 2, access: read-write
  Enum: 
  Value: 0 - NORMAL : don&apos;t invert the peri input
  Value: 1 - INVERT : invert the peri input
  Value: 2 - LOW : drive peri input low
  Value: 3 - HIGH : drive peri input high
  Field: OEOVER
  offset: 12, size: 2, access: read-write
  Enum: 
  Value: 0 - NORMAL : drive output enable from peripheral signal selected by funcsel
  Value: 1 - INVERT : drive output enable from inverse of peripheral signal selected by funcsel
  Value: 2 - DISABLE : disable output
  Value: 3 - ENABLE : enable output
  Field: OUTOVER
  offset: 8, size: 2, access: read-write
  Enum: 
  Value: 0 - NORMAL : drive output from peripheral signal selected by funcsel
  Value: 1 - INVERT : drive output from inverse of peripheral signal selected by funcsel
  Value: 2 - LOW : drive output low
  Value: 3 - HIGH : drive output high
  Field: FUNCSEL
  offset: 0, size: 5, access: read-write
  0-31 -&gt; selects pin function according to the gpio table

 31 == NULL
  Enum: 
  Value: 0 - xip_sd2
  Value: 5 - sio_34
  Value: 0x1f - null
*/
volatile uint32_t GPIO_QSPI_SD2_CTRL;

/* GPIO_QSPI_SD3_STATUS (offset: 0x28)
  GPIO status
  access : read-write
  reset value : 0x0
  reset mask : 0x0
  Field: IRQTOPROC
  offset: 26, size: 1, access: read-only
  interrupt to processors, after override is applied
  Field: IRQFROMPAD
  offset: 24, size: 1, access: read-only
  interrupt from pad before override is applied
  Field: INTOPERI
  offset: 19, size: 1, access: read-only
  input signal to peripheral, after override is applied
  Field: INFROMPAD
  offset: 17, size: 1, access: read-only
  input signal from pad, before override is applied
  Field: OETOPAD
  offset: 13, size: 1, access: read-only
  output enable to pad after register override is applied
  Field: OEFROMPERI
  offset: 12, size: 1, access: read-only
  output enable from selected peripheral, before register override is applied
  Field: OUTTOPAD
  offset: 9, size: 1, access: read-only
  output signal to pad after register override is applied
  Field: OUTFROMPERI
  offset: 8, size: 1, access: read-only
  output signal from selected peripheral, before register override is applied
*/
volatile uint32_t GPIO_QSPI_SD3_STATUS;

/* GPIO_QSPI_SD3_CTRL (offset: 0x2c)
  GPIO control including function select and overrides.
  access : read-write
  reset value : 0x1F
  reset mask : 0x0
  Field: IRQOVER
  offset: 28, size: 2, access: read-write
  Enum: 
  Value: 0 - NORMAL : don&apos;t invert the interrupt
  Value: 1 - INVERT : invert the interrupt
  Value: 2 - LOW : drive interrupt low
  Value: 3 - HIGH : drive interrupt high
  Field: INOVER
  offset: 16, size: 2, access: read-write
  Enum: 
  Value: 0 - NORMAL : don&apos;t invert the peri input
  Value: 1 - INVERT : invert the peri input
  Value: 2 - LOW : drive peri input low
  Value: 3 - HIGH : drive peri input high
  Field: OEOVER
  offset: 12, size: 2, access: read-write
  Enum: 
  Value: 0 - NORMAL : drive output enable from peripheral signal selected by funcsel
  Value: 1 - INVERT : drive output enable from inverse of peripheral signal selected by funcsel
  Value: 2 - DISABLE : disable output
  Value: 3 - ENABLE : enable output
  Field: OUTOVER
  offset: 8, size: 2, access: read-write
  Enum: 
  Value: 0 - NORMAL : drive output from peripheral signal selected by funcsel
  Value: 1 - INVERT : drive output from inverse of peripheral signal selected by funcsel
  Value: 2 - LOW : drive output low
  Value: 3 - HIGH : drive output high
  Field: FUNCSEL
  offset: 0, size: 5, access: read-write
  0-31 -&gt; selects pin function according to the gpio table

 31 == NULL
  Enum: 
  Value: 0 - xip_sd3
  Value: 5 - sio_35
  Value: 0x1f - null
*/
volatile uint32_t GPIO_QSPI_SD3_CTRL;

/* INTR (offset: 0x30)
  Raw Interrupts
  access : read-write
  reset value : 0x0
  reset mask : 0x0
  Field: GPIO_QSPI_SD3_EDGE_HIGH
  offset: 23, size: 1, access: read-write
  Field: GPIO_QSPI_SD3_EDGE_LOW
  offset: 22, size: 1, access: read-write
  Field: GPIO_QSPI_SD3_LEVEL_HIGH
  offset: 21, size: 1, access: read-only
  Field: GPIO_QSPI_SD3_LEVEL_LOW
  offset: 20, size: 1, access: read-only
  Field: GPIO_QSPI_SD2_EDGE_HIGH
  offset: 19, size: 1, access: read-write
  Field: GPIO_QSPI_SD2_EDGE_LOW
  offset: 18, size: 1, access: read-write
  Field: GPIO_QSPI_SD2_LEVEL_HIGH
  offset: 17, size: 1, access: read-only
  Field: GPIO_QSPI_SD2_LEVEL_LOW
  offset: 16, size: 1, access: read-only
  Field: GPIO_QSPI_SD1_EDGE_HIGH
  offset: 15, size: 1, access: read-write
  Field: GPIO_QSPI_SD1_EDGE_LOW
  offset: 14, size: 1, access: read-write
  Field: GPIO_QSPI_SD1_LEVEL_HIGH
  offset: 13, size: 1, access: read-only
  Field: GPIO_QSPI_SD1_LEVEL_LOW
  offset: 12, size: 1, access: read-only
  Field: GPIO_QSPI_SD0_EDGE_HIGH
  offset: 11, size: 1, access: read-write
  Field: GPIO_QSPI_SD0_EDGE_LOW
  offset: 10, size: 1, access: read-write
  Field: GPIO_QSPI_SD0_LEVEL_HIGH
  offset: 9, size: 1, access: read-only
  Field: GPIO_QSPI_SD0_LEVEL_LOW
  offset: 8, size: 1, access: read-only
  Field: GPIO_QSPI_SS_EDGE_HIGH
  offset: 7, size: 1, access: read-write
  Field: GPIO_QSPI_SS_EDGE_LOW
  offset: 6, size: 1, access: read-write
  Field: GPIO_QSPI_SS_LEVEL_HIGH
  offset: 5, size: 1, access: read-only
  Field: GPIO_QSPI_SS_LEVEL_LOW
  offset: 4, size: 1, access: read-only
  Field: GPIO_QSPI_SCLK_EDGE_HIGH
  offset: 3, size: 1, access: read-write
  Field: GPIO_QSPI_SCLK_EDGE_LOW
  offset: 2, size: 1, access: read-write
  Field: GPIO_QSPI_SCLK_LEVEL_HIGH
  offset: 1, size: 1, access: read-only
  Field: GPIO_QSPI_SCLK_LEVEL_LOW
  offset: 0, size: 1, access: read-only
*/
volatile uint32_t INTR;

/* PROC0_INTE (offset: 0x34)
  Interrupt Enable for proc0
  access : read-write
  reset value : 0x0
  reset mask : 0x0
  Field: GPIO_QSPI_SD3_EDGE_HIGH
  offset: 23, size: 1, access: read-write
  Field: GPIO_QSPI_SD3_EDGE_LOW
  offset: 22, size: 1, access: read-write
  Field: GPIO_QSPI_SD3_LEVEL_HIGH
  offset: 21, size: 1, access: read-write
  Field: GPIO_QSPI_SD3_LEVEL_LOW
  offset: 20, size: 1, access: read-write
  Field: GPIO_QSPI_SD2_EDGE_HIGH
  offset: 19, size: 1, access: read-write
  Field: GPIO_QSPI_SD2_EDGE_LOW
  offset: 18, size: 1, access: read-write
  Field: GPIO_QSPI_SD2_LEVEL_HIGH
  offset: 17, size: 1, access: read-write
  Field: GPIO_QSPI_SD2_LEVEL_LOW
  offset: 16, size: 1, access: read-write
  Field: GPIO_QSPI_SD1_EDGE_HIGH
  offset: 15, size: 1, access: read-write
  Field: GPIO_QSPI_SD1_EDGE_LOW
  offset: 14, size: 1, access: read-write
  Field: GPIO_QSPI_SD1_LEVEL_HIGH
  offset: 13, size: 1, access: read-write
  Field: GPIO_QSPI_SD1_LEVEL_LOW
  offset: 12, size: 1, access: read-write
  Field: GPIO_QSPI_SD0_EDGE_HIGH
  offset: 11, size: 1, access: read-write
  Field: GPIO_QSPI_SD0_EDGE_LOW
  offset: 10, size: 1, access: read-write
  Field: GPIO_QSPI_SD0_LEVEL_HIGH
  offset: 9, size: 1, access: read-write
  Field: GPIO_QSPI_SD0_LEVEL_LOW
  offset: 8, size: 1, access: read-write
  Field: GPIO_QSPI_SS_EDGE_HIGH
  offset: 7, size: 1, access: read-write
  Field: GPIO_QSPI_SS_EDGE_LOW
  offset: 6, size: 1, access: read-write
  Field: GPIO_QSPI_SS_LEVEL_HIGH
  offset: 5, size: 1, access: read-write
  Field: GPIO_QSPI_SS_LEVEL_LOW
  offset: 4, size: 1, access: read-write
  Field: GPIO_QSPI_SCLK_EDGE_HIGH
  offset: 3, size: 1, access: read-write
  Field: GPIO_QSPI_SCLK_EDGE_LOW
  offset: 2, size: 1, access: read-write
  Field: GPIO_QSPI_SCLK_LEVEL_HIGH
  offset: 1, size: 1, access: read-write
  Field: GPIO_QSPI_SCLK_LEVEL_LOW
  offset: 0, size: 1, access: read-write
*/
volatile uint32_t PROC0_INTE;

/* PROC0_INTF (offset: 0x38)
  Interrupt Force for proc0
  access : read-write
  reset value : 0x0
  reset mask : 0x0
  Field: GPIO_QSPI_SD3_EDGE_HIGH
  offset: 23, size: 1, access: read-write
  Field: GPIO_QSPI_SD3_EDGE_LOW
  offset: 22, size: 1, access: read-write
  Field: GPIO_QSPI_SD3_LEVEL_HIGH
  offset: 21, size: 1, access: read-write
  Field: GPIO_QSPI_SD3_LEVEL_LOW
  offset: 20, size: 1, access: read-write
  Field: GPIO_QSPI_SD2_EDGE_HIGH
  offset: 19, size: 1, access: read-write
  Field: GPIO_QSPI_SD2_EDGE_LOW
  offset: 18, size: 1, access: read-write
  Field: GPIO_QSPI_SD2_LEVEL_HIGH
  offset: 17, size: 1, access: read-write
  Field: GPIO_QSPI_SD2_LEVEL_LOW
  offset: 16, size: 1, access: read-write
  Field: GPIO_QSPI_SD1_EDGE_HIGH
  offset: 15, size: 1, access: read-write
  Field: GPIO_QSPI_SD1_EDGE_LOW
  offset: 14, size: 1, access: read-write
  Field: GPIO_QSPI_SD1_LEVEL_HIGH
  offset: 13, size: 1, access: read-write
  Field: GPIO_QSPI_SD1_LEVEL_LOW
  offset: 12, size: 1, access: read-write
  Field: GPIO_QSPI_SD0_EDGE_HIGH
  offset: 11, size: 1, access: read-write
  Field: GPIO_QSPI_SD0_EDGE_LOW
  offset: 10, size: 1, access: read-write
  Field: GPIO_QSPI_SD0_LEVEL_HIGH
  offset: 9, size: 1, access: read-write
  Field: GPIO_QSPI_SD0_LEVEL_LOW
  offset: 8, size: 1, access: read-write
  Field: GPIO_QSPI_SS_EDGE_HIGH
  offset: 7, size: 1, access: read-write
  Field: GPIO_QSPI_SS_EDGE_LOW
  offset: 6, size: 1, access: read-write
  Field: GPIO_QSPI_SS_LEVEL_HIGH
  offset: 5, size: 1, access: read-write
  Field: GPIO_QSPI_SS_LEVEL_LOW
  offset: 4, size: 1, access: read-write
  Field: GPIO_QSPI_SCLK_EDGE_HIGH
  offset: 3, size: 1, access: read-write
  Field: GPIO_QSPI_SCLK_EDGE_LOW
  offset: 2, size: 1, access: read-write
  Field: GPIO_QSPI_SCLK_LEVEL_HIGH
  offset: 1, size: 1, access: read-write
  Field: GPIO_QSPI_SCLK_LEVEL_LOW
  offset: 0, size: 1, access: read-write
*/
volatile uint32_t PROC0_INTF;

/* PROC0_INTS (offset: 0x3c)
  Interrupt status after masking &amp; forcing for proc0
  access : read-write
  reset value : 0x0
  reset mask : 0x0
  Field: GPIO_QSPI_SD3_EDGE_HIGH
  offset: 23, size: 1, access: read-only
  Field: GPIO_QSPI_SD3_EDGE_LOW
  offset: 22, size: 1, access: read-only
  Field: GPIO_QSPI_SD3_LEVEL_HIGH
  offset: 21, size: 1, access: read-only
  Field: GPIO_QSPI_SD3_LEVEL_LOW
  offset: 20, size: 1, access: read-only
  Field: GPIO_QSPI_SD2_EDGE_HIGH
  offset: 19, size: 1, access: read-only
  Field: GPIO_QSPI_SD2_EDGE_LOW
  offset: 18, size: 1, access: read-only
  Field: GPIO_QSPI_SD2_LEVEL_HIGH
  offset: 17, size: 1, access: read-only
  Field: GPIO_QSPI_SD2_LEVEL_LOW
  offset: 16, size: 1, access: read-only
  Field: GPIO_QSPI_SD1_EDGE_HIGH
  offset: 15, size: 1, access: read-only
  Field: GPIO_QSPI_SD1_EDGE_LOW
  offset: 14, size: 1, access: read-only
  Field: GPIO_QSPI_SD1_LEVEL_HIGH
  offset: 13, size: 1, access: read-only
  Field: GPIO_QSPI_SD1_LEVEL_LOW
  offset: 12, size: 1, access: read-only
  Field: GPIO_QSPI_SD0_EDGE_HIGH
  offset: 11, size: 1, access: read-only
  Field: GPIO_QSPI_SD0_EDGE_LOW
  offset: 10, size: 1, access: read-only
  Field: GPIO_QSPI_SD0_LEVEL_HIGH
  offset: 9, size: 1, access: read-only
  Field: GPIO_QSPI_SD0_LEVEL_LOW
  offset: 8, size: 1, access: read-only
  Field: GPIO_QSPI_SS_EDGE_HIGH
  offset: 7, size: 1, access: read-only
  Field: GPIO_QSPI_SS_EDGE_LOW
  offset: 6, size: 1, access: read-only
  Field: GPIO_QSPI_SS_LEVEL_HIGH
  offset: 5, size: 1, access: read-only
  Field: GPIO_QSPI_SS_LEVEL_LOW
  offset: 4, size: 1, access: read-only
  Field: GPIO_QSPI_SCLK_EDGE_HIGH
  offset: 3, size: 1, access: read-only
  Field: GPIO_QSPI_SCLK_EDGE_LOW
  offset: 2, size: 1, access: read-only
  Field: GPIO_QSPI_SCLK_LEVEL_HIGH
  offset: 1, size: 1, access: read-only
  Field: GPIO_QSPI_SCLK_LEVEL_LOW
  offset: 0, size: 1, access: read-only
*/
volatile uint32_t PROC0_INTS;

/* PROC1_INTE (offset: 0x40)
  Interrupt Enable for proc1
  access : read-write
  reset value : 0x0
  reset mask : 0x0
  Field: GPIO_QSPI_SD3_EDGE_HIGH
  offset: 23, size: 1, access: read-write
  Field: GPIO_QSPI_SD3_EDGE_LOW
  offset: 22, size: 1, access: read-write
  Field: GPIO_QSPI_SD3_LEVEL_HIGH
  offset: 21, size: 1, access: read-write
  Field: GPIO_QSPI_SD3_LEVEL_LOW
  offset: 20, size: 1, access: read-write
  Field: GPIO_QSPI_SD2_EDGE_HIGH
  offset: 19, size: 1, access: read-write
  Field: GPIO_QSPI_SD2_EDGE_LOW
  offset: 18, size: 1, access: read-write
  Field: GPIO_QSPI_SD2_LEVEL_HIGH
  offset: 17, size: 1, access: read-write
  Field: GPIO_QSPI_SD2_LEVEL_LOW
  offset: 16, size: 1, access: read-write
  Field: GPIO_QSPI_SD1_EDGE_HIGH
  offset: 15, size: 1, access: read-write
  Field: GPIO_QSPI_SD1_EDGE_LOW
  offset: 14, size: 1, access: read-write
  Field: GPIO_QSPI_SD1_LEVEL_HIGH
  offset: 13, size: 1, access: read-write
  Field: GPIO_QSPI_SD1_LEVEL_LOW
  offset: 12, size: 1, access: read-write
  Field: GPIO_QSPI_SD0_EDGE_HIGH
  offset: 11, size: 1, access: read-write
  Field: GPIO_QSPI_SD0_EDGE_LOW
  offset: 10, size: 1, access: read-write
  Field: GPIO_QSPI_SD0_LEVEL_HIGH
  offset: 9, size: 1, access: read-write
  Field: GPIO_QSPI_SD0_LEVEL_LOW
  offset: 8, size: 1, access: read-write
  Field: GPIO_QSPI_SS_EDGE_HIGH
  offset: 7, size: 1, access: read-write
  Field: GPIO_QSPI_SS_EDGE_LOW
  offset: 6, size: 1, access: read-write
  Field: GPIO_QSPI_SS_LEVEL_HIGH
  offset: 5, size: 1, access: read-write
  Field: GPIO_QSPI_SS_LEVEL_LOW
  offset: 4, size: 1, access: read-write
  Field: GPIO_QSPI_SCLK_EDGE_HIGH
  offset: 3, size: 1, access: read-write
  Field: GPIO_QSPI_SCLK_EDGE_LOW
  offset: 2, size: 1, access: read-write
  Field: GPIO_QSPI_SCLK_LEVEL_HIGH
  offset: 1, size: 1, access: read-write
  Field: GPIO_QSPI_SCLK_LEVEL_LOW
  offset: 0, size: 1, access: read-write
*/
volatile uint32_t PROC1_INTE;

/* PROC1_INTF (offset: 0x44)
  Interrupt Force for proc1
  access : read-write
  reset value : 0x0
  reset mask : 0x0
  Field: GPIO_QSPI_SD3_EDGE_HIGH
  offset: 23, size: 1, access: read-write
  Field: GPIO_QSPI_SD3_EDGE_LOW
  offset: 22, size: 1, access: read-write
  Field: GPIO_QSPI_SD3_LEVEL_HIGH
  offset: 21, size: 1, access: read-write
  Field: GPIO_QSPI_SD3_LEVEL_LOW
  offset: 20, size: 1, access: read-write
  Field: GPIO_QSPI_SD2_EDGE_HIGH
  offset: 19, size: 1, access: read-write
  Field: GPIO_QSPI_SD2_EDGE_LOW
  offset: 18, size: 1, access: read-write
  Field: GPIO_QSPI_SD2_LEVEL_HIGH
  offset: 17, size: 1, access: read-write
  Field: GPIO_QSPI_SD2_LEVEL_LOW
  offset: 16, size: 1, access: read-write
  Field: GPIO_QSPI_SD1_EDGE_HIGH
  offset: 15, size: 1, access: read-write
  Field: GPIO_QSPI_SD1_EDGE_LOW
  offset: 14, size: 1, access: read-write
  Field: GPIO_QSPI_SD1_LEVEL_HIGH
  offset: 13, size: 1, access: read-write
  Field: GPIO_QSPI_SD1_LEVEL_LOW
  offset: 12, size: 1, access: read-write
  Field: GPIO_QSPI_SD0_EDGE_HIGH
  offset: 11, size: 1, access: read-write
  Field: GPIO_QSPI_SD0_EDGE_LOW
  offset: 10, size: 1, access: read-write
  Field: GPIO_QSPI_SD0_LEVEL_HIGH
  offset: 9, size: 1, access: read-write
  Field: GPIO_QSPI_SD0_LEVEL_LOW
  offset: 8, size: 1, access: read-write
  Field: GPIO_QSPI_SS_EDGE_HIGH
  offset: 7, size: 1, access: read-write
  Field: GPIO_QSPI_SS_EDGE_LOW
  offset: 6, size: 1, access: read-write
  Field: GPIO_QSPI_SS_LEVEL_HIGH
  offset: 5, size: 1, access: read-write
  Field: GPIO_QSPI_SS_LEVEL_LOW
  offset: 4, size: 1, access: read-write
  Field: GPIO_QSPI_SCLK_EDGE_HIGH
  offset: 3, size: 1, access: read-write
  Field: GPIO_QSPI_SCLK_EDGE_LOW
  offset: 2, size: 1, access: read-write
  Field: GPIO_QSPI_SCLK_LEVEL_HIGH
  offset: 1, size: 1, access: read-write
  Field: GPIO_QSPI_SCLK_LEVEL_LOW
  offset: 0, size: 1, access: read-write
*/
volatile uint32_t PROC1_INTF;

/* PROC1_INTS (offset: 0x48)
  Interrupt status after masking &amp; forcing for proc1
  access : read-write
  reset value : 0x0
  reset mask : 0x0
  Field: GPIO_QSPI_SD3_EDGE_HIGH
  offset: 23, size: 1, access: read-only
  Field: GPIO_QSPI_SD3_EDGE_LOW
  offset: 22, size: 1, access: read-only
  Field: GPIO_QSPI_SD3_LEVEL_HIGH
  offset: 21, size: 1, access: read-only
  Field: GPIO_QSPI_SD3_LEVEL_LOW
  offset: 20, size: 1, access: read-only
  Field: GPIO_QSPI_SD2_EDGE_HIGH
  offset: 19, size: 1, access: read-only
  Field: GPIO_QSPI_SD2_EDGE_LOW
  offset: 18, size: 1, access: read-only
  Field: GPIO_QSPI_SD2_LEVEL_HIGH
  offset: 17, size: 1, access: read-only
  Field: GPIO_QSPI_SD2_LEVEL_LOW
  offset: 16, size: 1, access: read-only
  Field: GPIO_QSPI_SD1_EDGE_HIGH
  offset: 15, size: 1, access: read-only
  Field: GPIO_QSPI_SD1_EDGE_LOW
  offset: 14, size: 1, access: read-only
  Field: GPIO_QSPI_SD1_LEVEL_HIGH
  offset: 13, size: 1, access: read-only
  Field: GPIO_QSPI_SD1_LEVEL_LOW
  offset: 12, size: 1, access: read-only
  Field: GPIO_QSPI_SD0_EDGE_HIGH
  offset: 11, size: 1, access: read-only
  Field: GPIO_QSPI_SD0_EDGE_LOW
  offset: 10, size: 1, access: read-only
  Field: GPIO_QSPI_SD0_LEVEL_HIGH
  offset: 9, size: 1, access: read-only
  Field: GPIO_QSPI_SD0_LEVEL_LOW
  offset: 8, size: 1, access: read-only
  Field: GPIO_QSPI_SS_EDGE_HIGH
  offset: 7, size: 1, access: read-only
  Field: GPIO_QSPI_SS_EDGE_LOW
  offset: 6, size: 1, access: read-only
  Field: GPIO_QSPI_SS_LEVEL_HIGH
  offset: 5, size: 1, access: read-only
  Field: GPIO_QSPI_SS_LEVEL_LOW
  offset: 4, size: 1, access: read-only
  Field: GPIO_QSPI_SCLK_EDGE_HIGH
  offset: 3, size: 1, access: read-only
  Field: GPIO_QSPI_SCLK_EDGE_LOW
  offset: 2, size: 1, access: read-only
  Field: GPIO_QSPI_SCLK_LEVEL_HIGH
  offset: 1, size: 1, access: read-only
  Field: GPIO_QSPI_SCLK_LEVEL_LOW
  offset: 0, size: 1, access: read-only
*/
volatile uint32_t PROC1_INTS;

/* DORMANT_WAKE_INTE (offset: 0x4c)
  Interrupt Enable for dormant_wake
  access : read-write
  reset value : 0x0
  reset mask : 0x0
  Field: GPIO_QSPI_SD3_EDGE_HIGH
  offset: 23, size: 1, access: read-write
  Field: GPIO_QSPI_SD3_EDGE_LOW
  offset: 22, size: 1, access: read-write
  Field: GPIO_QSPI_SD3_LEVEL_HIGH
  offset: 21, size: 1, access: read-write
  Field: GPIO_QSPI_SD3_LEVEL_LOW
  offset: 20, size: 1, access: read-write
  Field: GPIO_QSPI_SD2_EDGE_HIGH
  offset: 19, size: 1, access: read-write
  Field: GPIO_QSPI_SD2_EDGE_LOW
  offset: 18, size: 1, access: read-write
  Field: GPIO_QSPI_SD2_LEVEL_HIGH
  offset: 17, size: 1, access: read-write
  Field: GPIO_QSPI_SD2_LEVEL_LOW
  offset: 16, size: 1, access: read-write
  Field: GPIO_QSPI_SD1_EDGE_HIGH
  offset: 15, size: 1, access: read-write
  Field: GPIO_QSPI_SD1_EDGE_LOW
  offset: 14, size: 1, access: read-write
  Field: GPIO_QSPI_SD1_LEVEL_HIGH
  offset: 13, size: 1, access: read-write
  Field: GPIO_QSPI_SD1_LEVEL_LOW
  offset: 12, size: 1, access: read-write
  Field: GPIO_QSPI_SD0_EDGE_HIGH
  offset: 11, size: 1, access: read-write
  Field: GPIO_QSPI_SD0_EDGE_LOW
  offset: 10, size: 1, access: read-write
  Field: GPIO_QSPI_SD0_LEVEL_HIGH
  offset: 9, size: 1, access: read-write
  Field: GPIO_QSPI_SD0_LEVEL_LOW
  offset: 8, size: 1, access: read-write
  Field: GPIO_QSPI_SS_EDGE_HIGH
  offset: 7, size: 1, access: read-write
  Field: GPIO_QSPI_SS_EDGE_LOW
  offset: 6, size: 1, access: read-write
  Field: GPIO_QSPI_SS_LEVEL_HIGH
  offset: 5, size: 1, access: read-write
  Field: GPIO_QSPI_SS_LEVEL_LOW
  offset: 4, size: 1, access: read-write
  Field: GPIO_QSPI_SCLK_EDGE_HIGH
  offset: 3, size: 1, access: read-write
  Field: GPIO_QSPI_SCLK_EDGE_LOW
  offset: 2, size: 1, access: read-write
  Field: GPIO_QSPI_SCLK_LEVEL_HIGH
  offset: 1, size: 1, access: read-write
  Field: GPIO_QSPI_SCLK_LEVEL_LOW
  offset: 0, size: 1, access: read-write
*/
volatile uint32_t DORMANT_WAKE_INTE;

/* DORMANT_WAKE_INTF (offset: 0x50)
  Interrupt Force for dormant_wake
  access : read-write
  reset value : 0x0
  reset mask : 0x0
  Field: GPIO_QSPI_SD3_EDGE_HIGH
  offset: 23, size: 1, access: read-write
  Field: GPIO_QSPI_SD3_EDGE_LOW
  offset: 22, size: 1, access: read-write
  Field: GPIO_QSPI_SD3_LEVEL_HIGH
  offset: 21, size: 1, access: read-write
  Field: GPIO_QSPI_SD3_LEVEL_LOW
  offset: 20, size: 1, access: read-write
  Field: GPIO_QSPI_SD2_EDGE_HIGH
  offset: 19, size: 1, access: read-write
  Field: GPIO_QSPI_SD2_EDGE_LOW
  offset: 18, size: 1, access: read-write
  Field: GPIO_QSPI_SD2_LEVEL_HIGH
  offset: 17, size: 1, access: read-write
  Field: GPIO_QSPI_SD2_LEVEL_LOW
  offset: 16, size: 1, access: read-write
  Field: GPIO_QSPI_SD1_EDGE_HIGH
  offset: 15, size: 1, access: read-write
  Field: GPIO_QSPI_SD1_EDGE_LOW
  offset: 14, size: 1, access: read-write
  Field: GPIO_QSPI_SD1_LEVEL_HIGH
  offset: 13, size: 1, access: read-write
  Field: GPIO_QSPI_SD1_LEVEL_LOW
  offset: 12, size: 1, access: read-write
  Field: GPIO_QSPI_SD0_EDGE_HIGH
  offset: 11, size: 1, access: read-write
  Field: GPIO_QSPI_SD0_EDGE_LOW
  offset: 10, size: 1, access: read-write
  Field: GPIO_QSPI_SD0_LEVEL_HIGH
  offset: 9, size: 1, access: read-write
  Field: GPIO_QSPI_SD0_LEVEL_LOW
  offset: 8, size: 1, access: read-write
  Field: GPIO_QSPI_SS_EDGE_HIGH
  offset: 7, size: 1, access: read-write
  Field: GPIO_QSPI_SS_EDGE_LOW
  offset: 6, size: 1, access: read-write
  Field: GPIO_QSPI_SS_LEVEL_HIGH
  offset: 5, size: 1, access: read-write
  Field: GPIO_QSPI_SS_LEVEL_LOW
  offset: 4, size: 1, access: read-write
  Field: GPIO_QSPI_SCLK_EDGE_HIGH
  offset: 3, size: 1, access: read-write
  Field: GPIO_QSPI_SCLK_EDGE_LOW
  offset: 2, size: 1, access: read-write
  Field: GPIO_QSPI_SCLK_LEVEL_HIGH
  offset: 1, size: 1, access: read-write
  Field: GPIO_QSPI_SCLK_LEVEL_LOW
  offset: 0, size: 1, access: read-write
*/
volatile uint32_t DORMANT_WAKE_INTF;

/* DORMANT_WAKE_INTS (offset: 0x54)
  Interrupt status after masking &amp; forcing for dormant_wake
  access : read-write
  reset value : 0x0
  reset mask : 0x0
  Field: GPIO_QSPI_SD3_EDGE_HIGH
  offset: 23, size: 1, access: read-only
  Field: GPIO_QSPI_SD3_EDGE_LOW
  offset: 22, size: 1, access: read-only
  Field: GPIO_QSPI_SD3_LEVEL_HIGH
  offset: 21, size: 1, access: read-only
  Field: GPIO_QSPI_SD3_LEVEL_LOW
  offset: 20, size: 1, access: read-only
  Field: GPIO_QSPI_SD2_EDGE_HIGH
  offset: 19, size: 1, access: read-only
  Field: GPIO_QSPI_SD2_EDGE_LOW
  offset: 18, size: 1, access: read-only
  Field: GPIO_QSPI_SD2_LEVEL_HIGH
  offset: 17, size: 1, access: read-only
  Field: GPIO_QSPI_SD2_LEVEL_LOW
  offset: 16, size: 1, access: read-only
  Field: GPIO_QSPI_SD1_EDGE_HIGH
  offset: 15, size: 1, access: read-only
  Field: GPIO_QSPI_SD1_EDGE_LOW
  offset: 14, size: 1, access: read-only
  Field: GPIO_QSPI_SD1_LEVEL_HIGH
  offset: 13, size: 1, access: read-only
  Field: GPIO_QSPI_SD1_LEVEL_LOW
  offset: 12, size: 1, access: read-only
  Field: GPIO_QSPI_SD0_EDGE_HIGH
  offset: 11, size: 1, access: read-only
  Field: GPIO_QSPI_SD0_EDGE_LOW
  offset: 10, size: 1, access: read-only
  Field: GPIO_QSPI_SD0_LEVEL_HIGH
  offset: 9, size: 1, access: read-only
  Field: GPIO_QSPI_SD0_LEVEL_LOW
  offset: 8, size: 1, access: read-only
  Field: GPIO_QSPI_SS_EDGE_HIGH
  offset: 7, size: 1, access: read-only
  Field: GPIO_QSPI_SS_EDGE_LOW
  offset: 6, size: 1, access: read-only
  Field: GPIO_QSPI_SS_LEVEL_HIGH
  offset: 5, size: 1, access: read-only
  Field: GPIO_QSPI_SS_LEVEL_LOW
  offset: 4, size: 1, access: read-only
  Field: GPIO_QSPI_SCLK_EDGE_HIGH
  offset: 3, size: 1, access: read-only
  Field: GPIO_QSPI_SCLK_EDGE_LOW
  offset: 2, size: 1, access: read-only
  Field: GPIO_QSPI_SCLK_LEVEL_HIGH
  offset: 1, size: 1, access: read-only
  Field: GPIO_QSPI_SCLK_LEVEL_LOW
  offset: 0, size: 1, access: read-only
*/
volatile uint32_t DORMANT_WAKE_INTS;
} IO_QSPI_type;

#define IO_QSPI ((IO_QSPI_type *) 0x40018000)

#endif // HW_IO_QSPI_H
