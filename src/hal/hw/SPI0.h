/*
  automatically created from data available on https://chipselect.org/
*/
#ifndef HW_SPI0_H
#define HW_SPI0_H
/** Interrupt : SPI0_IRQ (Vector: 18)  */
/** Memory Block starting at 0x4003C000 + 0x0 is 0x1000 bytes in size. It is used for registers. Protection: n */

#include <stdint.h>


#define SPI0_SSPCR0_SCR_OFFSET                             8u
#define SPI0_SSPCR0_SCR_MASK                               0xff00u

#define SPI0_SSPCR0_SPH_OFFSET                             7u
#define SPI0_SSPCR0_SPH_MASK                               0x80u

#define SPI0_SSPCR0_SPO_OFFSET                             6u
#define SPI0_SSPCR0_SPO_MASK                               0x40u

#define SPI0_SSPCR0_FRF_OFFSET                             4u
#define SPI0_SSPCR0_FRF_MASK                               0x30u

#define SPI0_SSPCR0_DSS_OFFSET                             0u
#define SPI0_SSPCR0_DSS_MASK                               0xfu

#define SPI0_SSPCR1_SOD_OFFSET                             3u
#define SPI0_SSPCR1_SOD_MASK                               8u

#define SPI0_SSPCR1_MS_OFFSET                              2u
#define SPI0_SSPCR1_MS_MASK                                4u

#define SPI0_SSPCR1_SSE_OFFSET                             1u
#define SPI0_SSPCR1_SSE_MASK                               2u

#define SPI0_SSPCR1_LBM_OFFSET                             0u
#define SPI0_SSPCR1_LBM_MASK                               1u

#define SPI0_SSPDR_DATA_OFFSET                             0u
#define SPI0_SSPDR_DATA_MASK                               0xffffu

#define SPI0_SSPSR_BSY_OFFSET                              4u
#define SPI0_SSPSR_BSY_MASK                                0x10u

#define SPI0_SSPSR_RFF_OFFSET                              3u
#define SPI0_SSPSR_RFF_MASK                                8u

#define SPI0_SSPSR_RNE_OFFSET                              2u
#define SPI0_SSPSR_RNE_MASK                                4u

#define SPI0_SSPSR_TNF_OFFSET                              1u
#define SPI0_SSPSR_TNF_MASK                                2u

#define SPI0_SSPSR_TFE_OFFSET                              0u
#define SPI0_SSPSR_TFE_MASK                                1u

#define SPI0_SSPCPSR_CPSDVSR_OFFSET                        0u
#define SPI0_SSPCPSR_CPSDVSR_MASK                          0xffu

#define SPI0_SSPIMSC_TXIM_OFFSET                           3u
#define SPI0_SSPIMSC_TXIM_MASK                             8u

#define SPI0_SSPIMSC_RXIM_OFFSET                           2u
#define SPI0_SSPIMSC_RXIM_MASK                             4u

#define SPI0_SSPIMSC_RTIM_OFFSET                           1u
#define SPI0_SSPIMSC_RTIM_MASK                             2u

#define SPI0_SSPIMSC_RORIM_OFFSET                          0u
#define SPI0_SSPIMSC_RORIM_MASK                            1u

#define SPI0_SSPRIS_TXRIS_OFFSET                           3u
#define SPI0_SSPRIS_TXRIS_MASK                             8u

#define SPI0_SSPRIS_RXRIS_OFFSET                           2u
#define SPI0_SSPRIS_RXRIS_MASK                             4u

#define SPI0_SSPRIS_RTRIS_OFFSET                           1u
#define SPI0_SSPRIS_RTRIS_MASK                             2u

#define SPI0_SSPRIS_RORRIS_OFFSET                          0u
#define SPI0_SSPRIS_RORRIS_MASK                            1u

#define SPI0_SSPMIS_TXMIS_OFFSET                           3u
#define SPI0_SSPMIS_TXMIS_MASK                             8u

#define SPI0_SSPMIS_RXMIS_OFFSET                           2u
#define SPI0_SSPMIS_RXMIS_MASK                             4u

#define SPI0_SSPMIS_RTMIS_OFFSET                           1u
#define SPI0_SSPMIS_RTMIS_MASK                             2u

#define SPI0_SSPMIS_RORMIS_OFFSET                          0u
#define SPI0_SSPMIS_RORMIS_MASK                            1u

#define SPI0_SSPICR_RTIC_OFFSET                            1u
#define SPI0_SSPICR_RTIC_MASK                              2u

#define SPI0_SSPICR_RORIC_OFFSET                           0u
#define SPI0_SSPICR_RORIC_MASK                             1u

#define SPI0_SSPDMACR_TXDMAE_OFFSET                        1u
#define SPI0_SSPDMACR_TXDMAE_MASK                          2u

#define SPI0_SSPDMACR_RXDMAE_OFFSET                        0u
#define SPI0_SSPDMACR_RXDMAE_MASK                          1u

#define SPI0_SSPPERIPHID0_PARTNUMBER0_OFFSET               0u
#define SPI0_SSPPERIPHID0_PARTNUMBER0_MASK                 0xffu

#define SPI0_SSPPERIPHID1_DESIGNER0_OFFSET                 4u
#define SPI0_SSPPERIPHID1_DESIGNER0_MASK                   0xf0u

#define SPI0_SSPPERIPHID1_PARTNUMBER1_OFFSET               0u
#define SPI0_SSPPERIPHID1_PARTNUMBER1_MASK                 0xfu

#define SPI0_SSPPERIPHID2_REVISION_OFFSET                  4u
#define SPI0_SSPPERIPHID2_REVISION_MASK                    0xf0u

#define SPI0_SSPPERIPHID2_DESIGNER1_OFFSET                 0u
#define SPI0_SSPPERIPHID2_DESIGNER1_MASK                   0xfu

#define SPI0_SSPPERIPHID3_CONFIGURATION_OFFSET             0u
#define SPI0_SSPPERIPHID3_CONFIGURATION_MASK               0xffu

#define SPI0_SSPPCELLID0_SSPPCELLID0_OFFSET                0u
#define SPI0_SSPPCELLID0_SSPPCELLID0_MASK                  0xffu

#define SPI0_SSPPCELLID1_SSPPCELLID1_OFFSET                0u
#define SPI0_SSPPCELLID1_SSPPCELLID1_MASK                  0xffu

#define SPI0_SSPPCELLID2_SSPPCELLID2_OFFSET                0u
#define SPI0_SSPPCELLID2_SSPPCELLID2_MASK                  0xffu

#define SPI0_SSPPCELLID3_SSPPCELLID3_OFFSET                0u
#define SPI0_SSPPCELLID3_SSPPCELLID3_MASK                  0xffu


typedef struct
{

/** SSPCR0 (offset: 0x0)
  Control register 0, SSPCR0 on page 3-4
  access : read-write
  reset value : 0x0
  reset mask : 0x0
  Field: SCR
  offset: 8, size: 8, access: read-write
  Serial clock rate. The value SCR is used to generate the transmit and receive bit rate of the PrimeCell SSP. The bit rate is: F SSPCLK CPSDVSR x (1+SCR) where CPSDVSR is an even value from 2-254, programmed through the SSPCPSR register and SCR is a value from 0-255.
  Field: SPH
  offset: 7, size: 1, access: read-write
  SSPCLKOUT phase, applicable to Motorola SPI frame format only. See Motorola SPI frame format on page 2-10.
  Field: SPO
  offset: 6, size: 1, access: read-write
  SSPCLKOUT polarity, applicable to Motorola SPI frame format only. See Motorola SPI frame format on page 2-10.
  Field: FRF
  offset: 4, size: 2, access: read-write
  Frame format: 00 Motorola SPI frame format. 01 TI synchronous serial frame format. 10 National Microwire frame format. 11 Reserved, undefined operation.
  Field: DSS
  offset: 0, size: 4, access: read-write
  Data Size Select: 0000 Reserved, undefined operation. 0001 Reserved, undefined operation. 0010 Reserved, undefined operation. 0011 4-bit data. 0100 5-bit data. 0101 6-bit data. 0110 7-bit data. 0111 8-bit data. 1000 9-bit data. 1001 10-bit data. 1010 11-bit data. 1011 12-bit data. 1100 13-bit data. 1101 14-bit data. 1110 15-bit data. 1111 16-bit data.
*/
volatile uint32_t SSPCR0;

/** SSPCR1 (offset: 0x4)
  Control register 1, SSPCR1 on page 3-5
  access : read-write
  reset value : 0x0
  reset mask : 0x0
  Field: SOD
  offset: 3, size: 1, access: read-write
  Slave-mode output disable. This bit is relevant only in the slave mode, MS=1. In multiple-slave systems, it is possible for an PrimeCell SSP master to broadcast a message to all slaves in the system while ensuring that only one slave drives data onto its serial output line. In such systems the RXD lines from multiple slaves could be tied together. To operate in such systems, the SOD bit can be set if the PrimeCell SSP slave is not supposed to drive the SSPTXD line: 0 SSP can drive the SSPTXD output in slave mode. 1 SSP must not drive the SSPTXD output in slave mode.
  Field: MS
  offset: 2, size: 1, access: read-write
  Master or slave mode select. This bit can be modified only when the PrimeCell SSP is disabled, SSE=0: 0 Device configured as master, default. 1 Device configured as slave.
  Field: SSE
  offset: 1, size: 1, access: read-write
  Synchronous serial port enable: 0 SSP operation disabled. 1 SSP operation enabled.
  Field: LBM
  offset: 0, size: 1, access: read-write
  Loop back mode: 0 Normal serial port operation enabled. 1 Output of transmit serial shifter is connected to input of receive serial shifter internally.
*/
volatile uint32_t SSPCR1;

/** SSPDR (offset: 0x8)
  Data register, SSPDR on page 3-6
  access : read-write
  reset value : 0x0
  reset mask : 0x0
  Field: DATA
  offset: 0, size: 16, access: read-write
  Transmit/Receive FIFO: Read Receive FIFO. Write Transmit FIFO. You must right-justify data when the PrimeCell SSP is programmed for a data size that is less than 16 bits. Unused bits at the top are ignored by transmit logic. The receive logic automatically right-justifies.
*/
volatile uint32_t SSPDR;

/** SSPSR (offset: 0xc)
  Status register, SSPSR on page 3-7
  access : read-write
  reset value : 0x3
  reset mask : 0x0
  Field: BSY
  offset: 4, size: 1, access: read-only
  PrimeCell SSP busy flag, RO: 0 SSP is idle. 1 SSP is currently transmitting and/or receiving a frame or the transmit FIFO is not empty.
  Field: RFF
  offset: 3, size: 1, access: read-only
  Receive FIFO full, RO: 0 Receive FIFO is not full. 1 Receive FIFO is full.
  Field: RNE
  offset: 2, size: 1, access: read-only
  Receive FIFO not empty, RO: 0 Receive FIFO is empty. 1 Receive FIFO is not empty.
  Field: TNF
  offset: 1, size: 1, access: read-only
  Transmit FIFO not full, RO: 0 Transmit FIFO is full. 1 Transmit FIFO is not full.
  Field: TFE
  offset: 0, size: 1, access: read-only
  Transmit FIFO empty, RO: 0 Transmit FIFO is not empty. 1 Transmit FIFO is empty.
*/
volatile uint32_t SSPSR;

/** SSPCPSR (offset: 0x10)
  Clock prescale register, SSPCPSR on page 3-8
  access : read-write
  reset value : 0x0
  reset mask : 0x0
  Field: CPSDVSR
  offset: 0, size: 8, access: read-write
  Clock prescale divisor. Must be an even number from 2-254, depending on the frequency of SSPCLK. The least significant bit always returns zero on reads.
*/
volatile uint32_t SSPCPSR;

/** SSPIMSC (offset: 0x14)
  Interrupt mask set or clear register, SSPIMSC on page 3-9
  access : read-write
  reset value : 0x0
  reset mask : 0x0
  Field: TXIM
  offset: 3, size: 1, access: read-write
  Transmit FIFO interrupt mask: 0 Transmit FIFO half empty or less condition interrupt is masked. 1 Transmit FIFO half empty or less condition interrupt is not masked.
  Field: RXIM
  offset: 2, size: 1, access: read-write
  Receive FIFO interrupt mask: 0 Receive FIFO half full or less condition interrupt is masked. 1 Receive FIFO half full or less condition interrupt is not masked.
  Field: RTIM
  offset: 1, size: 1, access: read-write
  Receive timeout interrupt mask: 0 Receive FIFO not empty and no read prior to timeout period interrupt is masked. 1 Receive FIFO not empty and no read prior to timeout period interrupt is not masked.
  Field: RORIM
  offset: 0, size: 1, access: read-write
  Receive overrun interrupt mask: 0 Receive FIFO written to while full condition interrupt is masked. 1 Receive FIFO written to while full condition interrupt is not masked.
*/
volatile uint32_t SSPIMSC;

/** SSPRIS (offset: 0x18)
  Raw interrupt status register, SSPRIS on page 3-10
  access : read-write
  reset value : 0x8
  reset mask : 0x0
  Field: TXRIS
  offset: 3, size: 1, access: read-only
  Gives the raw interrupt state, prior to masking, of the SSPTXINTR interrupt
  Field: RXRIS
  offset: 2, size: 1, access: read-only
  Gives the raw interrupt state, prior to masking, of the SSPRXINTR interrupt
  Field: RTRIS
  offset: 1, size: 1, access: read-only
  Gives the raw interrupt state, prior to masking, of the SSPRTINTR interrupt
  Field: RORRIS
  offset: 0, size: 1, access: read-only
  Gives the raw interrupt state, prior to masking, of the SSPRORINTR interrupt
*/
volatile uint32_t SSPRIS;

/** SSPMIS (offset: 0x1c)
  Masked interrupt status register, SSPMIS on page 3-11
  access : read-write
  reset value : 0x0
  reset mask : 0x0
  Field: TXMIS
  offset: 3, size: 1, access: read-only
  Gives the transmit FIFO masked interrupt state, after masking, of the SSPTXINTR interrupt
  Field: RXMIS
  offset: 2, size: 1, access: read-only
  Gives the receive FIFO masked interrupt state, after masking, of the SSPRXINTR interrupt
  Field: RTMIS
  offset: 1, size: 1, access: read-only
  Gives the receive timeout masked interrupt state, after masking, of the SSPRTINTR interrupt
  Field: RORMIS
  offset: 0, size: 1, access: read-only
  Gives the receive over run masked interrupt status, after masking, of the SSPRORINTR interrupt
*/
volatile uint32_t SSPMIS;

/** SSPICR (offset: 0x20)
  Interrupt clear register, SSPICR on page 3-11
  access : read-write
  reset value : 0x0
  reset mask : 0x0
  Field: RTIC
  offset: 1, size: 1, access: read-write
  Clears the SSPRTINTR interrupt
  Field: RORIC
  offset: 0, size: 1, access: read-write
  Clears the SSPRORINTR interrupt
*/
volatile uint32_t SSPICR;

/** SSPDMACR (offset: 0x24)
  DMA control register, SSPDMACR on page 3-12
  access : read-write
  reset value : 0x0
  reset mask : 0x0
  Field: TXDMAE
  offset: 1, size: 1, access: read-write
  Transmit DMA Enable. If this bit is set to 1, DMA for the transmit FIFO is enabled.
  Field: RXDMAE
  offset: 0, size: 1, access: read-write
  Receive DMA Enable. If this bit is set to 1, DMA for the receive FIFO is enabled.
*/
volatile uint32_t SSPDMACR;
volatile uint32_t reserved0[1006];

/** SSPPERIPHID0 (offset: 0xfe0)
  Peripheral identification registers, SSPPeriphID0-3 on page 3-13
  access : read-write
  reset value : 0x22
  reset mask : 0x0
  Field: PARTNUMBER0
  offset: 0, size: 8, access: read-only
  These bits read back as 0x22
*/
volatile uint32_t SSPPERIPHID0;

/** SSPPERIPHID1 (offset: 0xfe4)
  Peripheral identification registers, SSPPeriphID0-3 on page 3-13
  access : read-write
  reset value : 0x10
  reset mask : 0x0
  Field: DESIGNER0
  offset: 4, size: 4, access: read-only
  These bits read back as 0x1
  Field: PARTNUMBER1
  offset: 0, size: 4, access: read-only
  These bits read back as 0x0
*/
volatile uint32_t SSPPERIPHID1;

/** SSPPERIPHID2 (offset: 0xfe8)
  Peripheral identification registers, SSPPeriphID0-3 on page 3-13
  access : read-write
  reset value : 0x34
  reset mask : 0x0
  Field: REVISION
  offset: 4, size: 4, access: read-only
  These bits return the peripheral revision
  Field: DESIGNER1
  offset: 0, size: 4, access: read-only
  These bits read back as 0x4
*/
volatile uint32_t SSPPERIPHID2;

/** SSPPERIPHID3 (offset: 0xfec)
  Peripheral identification registers, SSPPeriphID0-3 on page 3-13
  access : read-write
  reset value : 0x0
  reset mask : 0x0
  Field: CONFIGURATION
  offset: 0, size: 8, access: read-only
  These bits read back as 0x00
*/
volatile uint32_t SSPPERIPHID3;

/** SSPPCELLID0 (offset: 0xff0)
  PrimeCell identification registers, SSPPCellID0-3 on page 3-16
  access : read-write
  reset value : 0xD
  reset mask : 0x0
  Field: SSPPCELLID0
  offset: 0, size: 8, access: read-only
  These bits read back as 0x0D
*/
volatile uint32_t SSPPCELLID0;

/** SSPPCELLID1 (offset: 0xff4)
  PrimeCell identification registers, SSPPCellID0-3 on page 3-16
  access : read-write
  reset value : 0xF0
  reset mask : 0x0
  Field: SSPPCELLID1
  offset: 0, size: 8, access: read-only
  These bits read back as 0xF0
*/
volatile uint32_t SSPPCELLID1;

/** SSPPCELLID2 (offset: 0xff8)
  PrimeCell identification registers, SSPPCellID0-3 on page 3-16
  access : read-write
  reset value : 0x5
  reset mask : 0x0
  Field: SSPPCELLID2
  offset: 0, size: 8, access: read-only
  These bits read back as 0x05
*/
volatile uint32_t SSPPCELLID2;

/** SSPPCELLID3 (offset: 0xffc)
  PrimeCell identification registers, SSPPCellID0-3 on page 3-16
  access : read-write
  reset value : 0xB1
  reset mask : 0x0
  Field: SSPPCELLID3
  offset: 0, size: 8, access: read-only
  These bits read back as 0xB1
*/
volatile uint32_t SSPPCELLID3;
} SPI0_type;

#define SPI0 ((SPI0_type *) 0x4003C000)

#endif // HW_SPI0_H
