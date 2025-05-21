/*
  automatically created from data available on https://chipselect.org/
*/
#ifndef HW_PADS_QSPI_H
#define HW_PADS_QSPI_H
/** Memory Block starting at 0x40020000 + 0x0 is 0x1000 bytes in size. It is used for registers. Protection: n */

#include <stdint.h>


#define PADS_QSPI_VOLTAGE_SELECT_VOLTAGE_SELECT_OFFSET     0u
#define PADS_QSPI_VOLTAGE_SELECT_VOLTAGE_SELECT_MASK       1u
#define PADS_QSPI_VOLTAGE_SELECT_VOLTAGE_SELECT_3V3        0u
#define PADS_QSPI_VOLTAGE_SELECT_VOLTAGE_SELECT_1V8        1u

#define PADS_QSPI_GPIO_QSPI_SCLK_OD_OFFSET                 7u
#define PADS_QSPI_GPIO_QSPI_SCLK_OD_MASK                   0x80u

#define PADS_QSPI_GPIO_QSPI_SCLK_IE_OFFSET                 6u
#define PADS_QSPI_GPIO_QSPI_SCLK_IE_MASK                   0x40u

#define PADS_QSPI_GPIO_QSPI_SCLK_DRIVE_OFFSET              4u
#define PADS_QSPI_GPIO_QSPI_SCLK_DRIVE_MASK                0x30u
#define PADS_QSPI_GPIO_QSPI_SCLK_DRIVE_2MA                 0u
#define PADS_QSPI_GPIO_QSPI_SCLK_DRIVE_4MA                 1u
#define PADS_QSPI_GPIO_QSPI_SCLK_DRIVE_8MA                 2u
#define PADS_QSPI_GPIO_QSPI_SCLK_DRIVE_12MA                3u

#define PADS_QSPI_GPIO_QSPI_SCLK_PUE_OFFSET                3u
#define PADS_QSPI_GPIO_QSPI_SCLK_PUE_MASK                  8u

#define PADS_QSPI_GPIO_QSPI_SCLK_PDE_OFFSET                2u
#define PADS_QSPI_GPIO_QSPI_SCLK_PDE_MASK                  4u

#define PADS_QSPI_GPIO_QSPI_SCLK_SCHMITT_OFFSET            1u
#define PADS_QSPI_GPIO_QSPI_SCLK_SCHMITT_MASK              2u

#define PADS_QSPI_GPIO_QSPI_SCLK_SLEWFAST_OFFSET           0u
#define PADS_QSPI_GPIO_QSPI_SCLK_SLEWFAST_MASK             1u

#define PADS_QSPI_GPIO_QSPI_SD0_OD_OFFSET                  7u
#define PADS_QSPI_GPIO_QSPI_SD0_OD_MASK                    0x80u

#define PADS_QSPI_GPIO_QSPI_SD0_IE_OFFSET                  6u
#define PADS_QSPI_GPIO_QSPI_SD0_IE_MASK                    0x40u

#define PADS_QSPI_GPIO_QSPI_SD0_DRIVE_OFFSET               4u
#define PADS_QSPI_GPIO_QSPI_SD0_DRIVE_MASK                 0x30u
#define PADS_QSPI_GPIO_QSPI_SD0_DRIVE_2MA                  0u
#define PADS_QSPI_GPIO_QSPI_SD0_DRIVE_4MA                  1u
#define PADS_QSPI_GPIO_QSPI_SD0_DRIVE_8MA                  2u
#define PADS_QSPI_GPIO_QSPI_SD0_DRIVE_12MA                 3u

#define PADS_QSPI_GPIO_QSPI_SD0_PUE_OFFSET                 3u
#define PADS_QSPI_GPIO_QSPI_SD0_PUE_MASK                   8u

#define PADS_QSPI_GPIO_QSPI_SD0_PDE_OFFSET                 2u
#define PADS_QSPI_GPIO_QSPI_SD0_PDE_MASK                   4u

#define PADS_QSPI_GPIO_QSPI_SD0_SCHMITT_OFFSET             1u
#define PADS_QSPI_GPIO_QSPI_SD0_SCHMITT_MASK               2u

#define PADS_QSPI_GPIO_QSPI_SD0_SLEWFAST_OFFSET            0u
#define PADS_QSPI_GPIO_QSPI_SD0_SLEWFAST_MASK              1u

#define PADS_QSPI_GPIO_QSPI_SD1_OD_OFFSET                  7u
#define PADS_QSPI_GPIO_QSPI_SD1_OD_MASK                    0x80u

#define PADS_QSPI_GPIO_QSPI_SD1_IE_OFFSET                  6u
#define PADS_QSPI_GPIO_QSPI_SD1_IE_MASK                    0x40u

#define PADS_QSPI_GPIO_QSPI_SD1_DRIVE_OFFSET               4u
#define PADS_QSPI_GPIO_QSPI_SD1_DRIVE_MASK                 0x30u
#define PADS_QSPI_GPIO_QSPI_SD1_DRIVE_2MA                  0u
#define PADS_QSPI_GPIO_QSPI_SD1_DRIVE_4MA                  1u
#define PADS_QSPI_GPIO_QSPI_SD1_DRIVE_8MA                  2u
#define PADS_QSPI_GPIO_QSPI_SD1_DRIVE_12MA                 3u

#define PADS_QSPI_GPIO_QSPI_SD1_PUE_OFFSET                 3u
#define PADS_QSPI_GPIO_QSPI_SD1_PUE_MASK                   8u

#define PADS_QSPI_GPIO_QSPI_SD1_PDE_OFFSET                 2u
#define PADS_QSPI_GPIO_QSPI_SD1_PDE_MASK                   4u

#define PADS_QSPI_GPIO_QSPI_SD1_SCHMITT_OFFSET             1u
#define PADS_QSPI_GPIO_QSPI_SD1_SCHMITT_MASK               2u

#define PADS_QSPI_GPIO_QSPI_SD1_SLEWFAST_OFFSET            0u
#define PADS_QSPI_GPIO_QSPI_SD1_SLEWFAST_MASK              1u

#define PADS_QSPI_GPIO_QSPI_SD2_OD_OFFSET                  7u
#define PADS_QSPI_GPIO_QSPI_SD2_OD_MASK                    0x80u

#define PADS_QSPI_GPIO_QSPI_SD2_IE_OFFSET                  6u
#define PADS_QSPI_GPIO_QSPI_SD2_IE_MASK                    0x40u

#define PADS_QSPI_GPIO_QSPI_SD2_DRIVE_OFFSET               4u
#define PADS_QSPI_GPIO_QSPI_SD2_DRIVE_MASK                 0x30u
#define PADS_QSPI_GPIO_QSPI_SD2_DRIVE_2MA                  0u
#define PADS_QSPI_GPIO_QSPI_SD2_DRIVE_4MA                  1u
#define PADS_QSPI_GPIO_QSPI_SD2_DRIVE_8MA                  2u
#define PADS_QSPI_GPIO_QSPI_SD2_DRIVE_12MA                 3u

#define PADS_QSPI_GPIO_QSPI_SD2_PUE_OFFSET                 3u
#define PADS_QSPI_GPIO_QSPI_SD2_PUE_MASK                   8u

#define PADS_QSPI_GPIO_QSPI_SD2_PDE_OFFSET                 2u
#define PADS_QSPI_GPIO_QSPI_SD2_PDE_MASK                   4u

#define PADS_QSPI_GPIO_QSPI_SD2_SCHMITT_OFFSET             1u
#define PADS_QSPI_GPIO_QSPI_SD2_SCHMITT_MASK               2u

#define PADS_QSPI_GPIO_QSPI_SD2_SLEWFAST_OFFSET            0u
#define PADS_QSPI_GPIO_QSPI_SD2_SLEWFAST_MASK              1u

#define PADS_QSPI_GPIO_QSPI_SD3_OD_OFFSET                  7u
#define PADS_QSPI_GPIO_QSPI_SD3_OD_MASK                    0x80u

#define PADS_QSPI_GPIO_QSPI_SD3_IE_OFFSET                  6u
#define PADS_QSPI_GPIO_QSPI_SD3_IE_MASK                    0x40u

#define PADS_QSPI_GPIO_QSPI_SD3_DRIVE_OFFSET               4u
#define PADS_QSPI_GPIO_QSPI_SD3_DRIVE_MASK                 0x30u
#define PADS_QSPI_GPIO_QSPI_SD3_DRIVE_2MA                  0u
#define PADS_QSPI_GPIO_QSPI_SD3_DRIVE_4MA                  1u
#define PADS_QSPI_GPIO_QSPI_SD3_DRIVE_8MA                  2u
#define PADS_QSPI_GPIO_QSPI_SD3_DRIVE_12MA                 3u

#define PADS_QSPI_GPIO_QSPI_SD3_PUE_OFFSET                 3u
#define PADS_QSPI_GPIO_QSPI_SD3_PUE_MASK                   8u

#define PADS_QSPI_GPIO_QSPI_SD3_PDE_OFFSET                 2u
#define PADS_QSPI_GPIO_QSPI_SD3_PDE_MASK                   4u

#define PADS_QSPI_GPIO_QSPI_SD3_SCHMITT_OFFSET             1u
#define PADS_QSPI_GPIO_QSPI_SD3_SCHMITT_MASK               2u

#define PADS_QSPI_GPIO_QSPI_SD3_SLEWFAST_OFFSET            0u
#define PADS_QSPI_GPIO_QSPI_SD3_SLEWFAST_MASK              1u

#define PADS_QSPI_GPIO_QSPI_SS_OD_OFFSET                   7u
#define PADS_QSPI_GPIO_QSPI_SS_OD_MASK                     0x80u

#define PADS_QSPI_GPIO_QSPI_SS_IE_OFFSET                   6u
#define PADS_QSPI_GPIO_QSPI_SS_IE_MASK                     0x40u

#define PADS_QSPI_GPIO_QSPI_SS_DRIVE_OFFSET                4u
#define PADS_QSPI_GPIO_QSPI_SS_DRIVE_MASK                  0x30u
#define PADS_QSPI_GPIO_QSPI_SS_DRIVE_2MA                   0u
#define PADS_QSPI_GPIO_QSPI_SS_DRIVE_4MA                   1u
#define PADS_QSPI_GPIO_QSPI_SS_DRIVE_8MA                   2u
#define PADS_QSPI_GPIO_QSPI_SS_DRIVE_12MA                  3u

#define PADS_QSPI_GPIO_QSPI_SS_PUE_OFFSET                  3u
#define PADS_QSPI_GPIO_QSPI_SS_PUE_MASK                    8u

#define PADS_QSPI_GPIO_QSPI_SS_PDE_OFFSET                  2u
#define PADS_QSPI_GPIO_QSPI_SS_PDE_MASK                    4u

#define PADS_QSPI_GPIO_QSPI_SS_SCHMITT_OFFSET              1u
#define PADS_QSPI_GPIO_QSPI_SS_SCHMITT_MASK                2u

#define PADS_QSPI_GPIO_QSPI_SS_SLEWFAST_OFFSET             0u
#define PADS_QSPI_GPIO_QSPI_SS_SLEWFAST_MASK               1u


typedef struct
{

/** VOLTAGE_SELECT (offset: 0x0)
  Voltage select. Per bank control
  access : read-write
  reset value : 0x0
  reset mask : 0x0
  Field: VOLTAGE_SELECT
  offset: 0, size: 1, access: read-write
  Enum:
  Value: 0 - 3v3 : Set voltage to 3.3V (DVDD &gt;= 2V5)
  Value: 1 - 1v8 : Set voltage to 1.8V (DVDD &lt;= 1V8)
*/
volatile uint32_t VOLTAGE_SELECT;

/** GPIO_QSPI_SCLK (offset: 0x4)
  Pad control register
  access : read-write
  reset value : 0x56
  reset mask : 0x0
  Field: OD
  offset: 7, size: 1, access: read-write
  Output disable. Has priority over output enable from peripherals
  Field: IE
  offset: 6, size: 1, access: read-write
  Input enable
  Field: DRIVE
  offset: 4, size: 2, access: read-write
  Drive strength.
  Enum:
  Value: 0 - 2mA
  Value: 1 - 4mA
  Value: 2 - 8mA
  Value: 3 - 12mA
  Field: PUE
  offset: 3, size: 1, access: read-write
  Pull up enable
  Field: PDE
  offset: 2, size: 1, access: read-write
  Pull down enable
  Field: SCHMITT
  offset: 1, size: 1, access: read-write
  Enable schmitt trigger
  Field: SLEWFAST
  offset: 0, size: 1, access: read-write
  Slew rate control. 1 = Fast, 0 = Slow
*/
volatile uint32_t GPIO_QSPI_SCLK;

/** GPIO_QSPI_SD0 (offset: 0x8)
  Pad control register
  access : read-write
  reset value : 0x52
  reset mask : 0x0
  Field: OD
  offset: 7, size: 1, access: read-write
  Output disable. Has priority over output enable from peripherals
  Field: IE
  offset: 6, size: 1, access: read-write
  Input enable
  Field: DRIVE
  offset: 4, size: 2, access: read-write
  Drive strength.
  Enum:
  Value: 0 - 2mA
  Value: 1 - 4mA
  Value: 2 - 8mA
  Value: 3 - 12mA
  Field: PUE
  offset: 3, size: 1, access: read-write
  Pull up enable
  Field: PDE
  offset: 2, size: 1, access: read-write
  Pull down enable
  Field: SCHMITT
  offset: 1, size: 1, access: read-write
  Enable schmitt trigger
  Field: SLEWFAST
  offset: 0, size: 1, access: read-write
  Slew rate control. 1 = Fast, 0 = Slow
*/
volatile uint32_t GPIO_QSPI_SD0;

/** GPIO_QSPI_SD1 (offset: 0xc)
  Pad control register
  access : read-write
  reset value : 0x52
  reset mask : 0x0
  Field: OD
  offset: 7, size: 1, access: read-write
  Output disable. Has priority over output enable from peripherals
  Field: IE
  offset: 6, size: 1, access: read-write
  Input enable
  Field: DRIVE
  offset: 4, size: 2, access: read-write
  Drive strength.
  Enum:
  Value: 0 - 2mA
  Value: 1 - 4mA
  Value: 2 - 8mA
  Value: 3 - 12mA
  Field: PUE
  offset: 3, size: 1, access: read-write
  Pull up enable
  Field: PDE
  offset: 2, size: 1, access: read-write
  Pull down enable
  Field: SCHMITT
  offset: 1, size: 1, access: read-write
  Enable schmitt trigger
  Field: SLEWFAST
  offset: 0, size: 1, access: read-write
  Slew rate control. 1 = Fast, 0 = Slow
*/
volatile uint32_t GPIO_QSPI_SD1;

/** GPIO_QSPI_SD2 (offset: 0x10)
  Pad control register
  access : read-write
  reset value : 0x52
  reset mask : 0x0
  Field: OD
  offset: 7, size: 1, access: read-write
  Output disable. Has priority over output enable from peripherals
  Field: IE
  offset: 6, size: 1, access: read-write
  Input enable
  Field: DRIVE
  offset: 4, size: 2, access: read-write
  Drive strength.
  Enum:
  Value: 0 - 2mA
  Value: 1 - 4mA
  Value: 2 - 8mA
  Value: 3 - 12mA
  Field: PUE
  offset: 3, size: 1, access: read-write
  Pull up enable
  Field: PDE
  offset: 2, size: 1, access: read-write
  Pull down enable
  Field: SCHMITT
  offset: 1, size: 1, access: read-write
  Enable schmitt trigger
  Field: SLEWFAST
  offset: 0, size: 1, access: read-write
  Slew rate control. 1 = Fast, 0 = Slow
*/
volatile uint32_t GPIO_QSPI_SD2;

/** GPIO_QSPI_SD3 (offset: 0x14)
  Pad control register
  access : read-write
  reset value : 0x52
  reset mask : 0x0
  Field: OD
  offset: 7, size: 1, access: read-write
  Output disable. Has priority over output enable from peripherals
  Field: IE
  offset: 6, size: 1, access: read-write
  Input enable
  Field: DRIVE
  offset: 4, size: 2, access: read-write
  Drive strength.
  Enum:
  Value: 0 - 2mA
  Value: 1 - 4mA
  Value: 2 - 8mA
  Value: 3 - 12mA
  Field: PUE
  offset: 3, size: 1, access: read-write
  Pull up enable
  Field: PDE
  offset: 2, size: 1, access: read-write
  Pull down enable
  Field: SCHMITT
  offset: 1, size: 1, access: read-write
  Enable schmitt trigger
  Field: SLEWFAST
  offset: 0, size: 1, access: read-write
  Slew rate control. 1 = Fast, 0 = Slow
*/
volatile uint32_t GPIO_QSPI_SD3;

/** GPIO_QSPI_SS (offset: 0x18)
  Pad control register
  access : read-write
  reset value : 0x5A
  reset mask : 0x0
  Field: OD
  offset: 7, size: 1, access: read-write
  Output disable. Has priority over output enable from peripherals
  Field: IE
  offset: 6, size: 1, access: read-write
  Input enable
  Field: DRIVE
  offset: 4, size: 2, access: read-write
  Drive strength.
  Enum:
  Value: 0 - 2mA
  Value: 1 - 4mA
  Value: 2 - 8mA
  Value: 3 - 12mA
  Field: PUE
  offset: 3, size: 1, access: read-write
  Pull up enable
  Field: PDE
  offset: 2, size: 1, access: read-write
  Pull down enable
  Field: SCHMITT
  offset: 1, size: 1, access: read-write
  Enable schmitt trigger
  Field: SLEWFAST
  offset: 0, size: 1, access: read-write
  Slew rate control. 1 = Fast, 0 = Slow
*/
volatile uint32_t GPIO_QSPI_SS;
} PADS_QSPI_type;

#define PADS_QSPI ((PADS_QSPI_type *) 0x40020000)

#endif // HW_PADS_QSPI_H
