/*
  automatically created from data available on https://chipselect.org/
*/
#ifndef HW_XIP_SSI_H
#define HW_XIP_SSI_H
/** DW_apb_ssi has the following features:

 * APB interface – Allows for easy integration into a DesignWare Synthesizable Components for AMBA 2 implementation.

 * APB3 and APB4 protocol support.

 * Scalable APB data bus width – Supports APB data bus widths of 8, 16, and 32 bits.

 * Serial-master or serial-slave operation – Enables serial communication with serial-master or serial-slave peripheral devices.

 * Programmable Dual/Quad/Octal SPI support in Master Mode.

 * Dual Data Rate (DDR) and Read Data Strobe (RDS) Support - Enables the DW_apb_ssi master to perform operations with the device in DDR and RDS modes when working in Dual/Quad/Octal mode of operation.

 * Data Mask Support - Enables the DW_apb_ssi to selectively update the bytes in the device. This feature is applicable only in enhanced SPI modes.

 * eXecute-In-Place (XIP) support - Enables the DW_apb_ssi master to behave as a memory mapped I/O and fetches the data from the device based on the APB read request. This feature is applicable only in enhanced SPI modes.

 * DMA Controller Interface – Enables the DW_apb_ssi to interface to a DMA controller over the bus using a handshaking interface for transfer requests.

 * Independent masking of interrupts – Master collision, transmit FIFO overflow, transmit FIFO empty, receive FIFO full, receive FIFO underflow, and receive FIFO overflow interrupts can all be masked independently.

 * Multi-master contention detection – Informs the processor of multiple serial-master accesses on the serial bus.

 * Bypass of meta-stability flip-flops for synchronous clocks – When the APB clock (pclk) and the DW_apb_ssi serial clock (ssi_clk) are synchronous, meta-stable flip-flops are not used when transferring control signals across these clock domains.

 * Programmable delay on the sample time of the received serial data bit (rxd) enables programmable control of routing delays resulting in higher serial data-bit rates.

 * Programmable features:

 - Serial interface operation – Choice of Motorola SPI, Texas Instruments Synchronous Serial Protocol or National Semiconductor Microwire.

 - Clock bit-rate – Dynamic control of the serial bit rate of the data transfer used in only serial-master mode of operation.

 - Data Item size (4 to 32 bits) – Item size of each data transfer under the control of the programmer.

 * Configured features:

 - FIFO depth – 16 words deep. The FIFO width is fixed at 32 bits.

 - 1 slave select output.

 - Hardware slave-select – Dedicated hardware slave-select line.

 - Combined interrupt line - one combined interrupt line from the DW_apb_ssi to the interrupt controller.

 - Interrupt polarity – active high interrupt lines.

 - Serial clock polarity – low serial-clock polarity directly after reset.

 - Serial clock phase – capture on first edge of serial-clock directly after reset. */
/** Memory Block starting at 0x18000000 + 0x0 is 0x100 bytes in size. It is used for registers. Protection: n */

#include <stdint.h>


#define XIP_SSI_CTRLR0_SSTE_OFFSET                         24u
#define XIP_SSI_CTRLR0_SSTE_MASK                           0x1000000u

#define XIP_SSI_CTRLR0_SPI_FRF_OFFSET                      21u
#define XIP_SSI_CTRLR0_SPI_FRF_MASK                        0x600000u
#define XIP_SSI_CTRLR0_SPI_FRF_STD                         0u
#define XIP_SSI_CTRLR0_SPI_FRF_DUAL                        1u
#define XIP_SSI_CTRLR0_SPI_FRF_QUAD                        2u

#define XIP_SSI_CTRLR0_DFS_32_OFFSET                       16u
#define XIP_SSI_CTRLR0_DFS_32_MASK                         0x1f0000u

#define XIP_SSI_CTRLR0_CFS_OFFSET                          12u
#define XIP_SSI_CTRLR0_CFS_MASK                            0xf000u

#define XIP_SSI_CTRLR0_SRL_OFFSET                          11u
#define XIP_SSI_CTRLR0_SRL_MASK                            0x800u

#define XIP_SSI_CTRLR0_SLV_OE_OFFSET                       10u
#define XIP_SSI_CTRLR0_SLV_OE_MASK                         0x400u

#define XIP_SSI_CTRLR0_TMOD_OFFSET                         8u
#define XIP_SSI_CTRLR0_TMOD_MASK                           0x300u
#define XIP_SSI_CTRLR0_TMOD_TX_AND_RX                      0u
#define XIP_SSI_CTRLR0_TMOD_TX_ONLY                        1u
#define XIP_SSI_CTRLR0_TMOD_RX_ONLY                        2u
#define XIP_SSI_CTRLR0_TMOD_EEPROM_READ                    3u

#define XIP_SSI_CTRLR0_SCPOL_OFFSET                        7u
#define XIP_SSI_CTRLR0_SCPOL_MASK                          0x80u

#define XIP_SSI_CTRLR0_SCPH_OFFSET                         6u
#define XIP_SSI_CTRLR0_SCPH_MASK                           0x40u

#define XIP_SSI_CTRLR0_FRF_OFFSET                          4u
#define XIP_SSI_CTRLR0_FRF_MASK                            0x30u

#define XIP_SSI_CTRLR0_DFS_OFFSET                          0u
#define XIP_SSI_CTRLR0_DFS_MASK                            0xfu

#define XIP_SSI_CTRLR1_NDF_OFFSET                          0u
#define XIP_SSI_CTRLR1_NDF_MASK                            0xffffu

#define XIP_SSI_SSIENR_SSI_EN_OFFSET                       0u
#define XIP_SSI_SSIENR_SSI_EN_MASK                         1u

#define XIP_SSI_MWCR_MHS_OFFSET                            2u
#define XIP_SSI_MWCR_MHS_MASK                              4u

#define XIP_SSI_MWCR_MDD_OFFSET                            1u
#define XIP_SSI_MWCR_MDD_MASK                              2u

#define XIP_SSI_MWCR_MWMOD_OFFSET                          0u
#define XIP_SSI_MWCR_MWMOD_MASK                            1u

#define XIP_SSI_SER_SER_OFFSET                             0u
#define XIP_SSI_SER_SER_MASK                               1u

#define XIP_SSI_BAUDR_SCKDV_OFFSET                         0u
#define XIP_SSI_BAUDR_SCKDV_MASK                           0xffffu

#define XIP_SSI_TXFTLR_TFT_OFFSET                          0u
#define XIP_SSI_TXFTLR_TFT_MASK                            0xffu

#define XIP_SSI_RXFTLR_RFT_OFFSET                          0u
#define XIP_SSI_RXFTLR_RFT_MASK                            0xffu

#define XIP_SSI_TXFLR_TFTFL_OFFSET                         0u
#define XIP_SSI_TXFLR_TFTFL_MASK                           0xffu

#define XIP_SSI_RXFLR_RXTFL_OFFSET                         0u
#define XIP_SSI_RXFLR_RXTFL_MASK                           0xffu

#define XIP_SSI_SR_DCOL_OFFSET                             6u
#define XIP_SSI_SR_DCOL_MASK                               0x40u

#define XIP_SSI_SR_TXE_OFFSET                              5u
#define XIP_SSI_SR_TXE_MASK                                0x20u

#define XIP_SSI_SR_RFF_OFFSET                              4u
#define XIP_SSI_SR_RFF_MASK                                0x10u

#define XIP_SSI_SR_RFNE_OFFSET                             3u
#define XIP_SSI_SR_RFNE_MASK                               8u

#define XIP_SSI_SR_TFE_OFFSET                              2u
#define XIP_SSI_SR_TFE_MASK                                4u

#define XIP_SSI_SR_TFNF_OFFSET                             1u
#define XIP_SSI_SR_TFNF_MASK                               2u

#define XIP_SSI_SR_BUSY_OFFSET                             0u
#define XIP_SSI_SR_BUSY_MASK                               1u

#define XIP_SSI_IMR_MSTIM_OFFSET                           5u
#define XIP_SSI_IMR_MSTIM_MASK                             0x20u

#define XIP_SSI_IMR_RXFIM_OFFSET                           4u
#define XIP_SSI_IMR_RXFIM_MASK                             0x10u

#define XIP_SSI_IMR_RXOIM_OFFSET                           3u
#define XIP_SSI_IMR_RXOIM_MASK                             8u

#define XIP_SSI_IMR_RXUIM_OFFSET                           2u
#define XIP_SSI_IMR_RXUIM_MASK                             4u

#define XIP_SSI_IMR_TXOIM_OFFSET                           1u
#define XIP_SSI_IMR_TXOIM_MASK                             2u

#define XIP_SSI_IMR_TXEIM_OFFSET                           0u
#define XIP_SSI_IMR_TXEIM_MASK                             1u

#define XIP_SSI_ISR_MSTIS_OFFSET                           5u
#define XIP_SSI_ISR_MSTIS_MASK                             0x20u

#define XIP_SSI_ISR_RXFIS_OFFSET                           4u
#define XIP_SSI_ISR_RXFIS_MASK                             0x10u

#define XIP_SSI_ISR_RXOIS_OFFSET                           3u
#define XIP_SSI_ISR_RXOIS_MASK                             8u

#define XIP_SSI_ISR_RXUIS_OFFSET                           2u
#define XIP_SSI_ISR_RXUIS_MASK                             4u

#define XIP_SSI_ISR_TXOIS_OFFSET                           1u
#define XIP_SSI_ISR_TXOIS_MASK                             2u

#define XIP_SSI_ISR_TXEIS_OFFSET                           0u
#define XIP_SSI_ISR_TXEIS_MASK                             1u

#define XIP_SSI_RISR_MSTIR_OFFSET                          5u
#define XIP_SSI_RISR_MSTIR_MASK                            0x20u

#define XIP_SSI_RISR_RXFIR_OFFSET                          4u
#define XIP_SSI_RISR_RXFIR_MASK                            0x10u

#define XIP_SSI_RISR_RXOIR_OFFSET                          3u
#define XIP_SSI_RISR_RXOIR_MASK                            8u

#define XIP_SSI_RISR_RXUIR_OFFSET                          2u
#define XIP_SSI_RISR_RXUIR_MASK                            4u

#define XIP_SSI_RISR_TXOIR_OFFSET                          1u
#define XIP_SSI_RISR_TXOIR_MASK                            2u

#define XIP_SSI_RISR_TXEIR_OFFSET                          0u
#define XIP_SSI_RISR_TXEIR_MASK                            1u

#define XIP_SSI_TXOICR_TXOICR_OFFSET                       0u
#define XIP_SSI_TXOICR_TXOICR_MASK                         1u

#define XIP_SSI_RXOICR_RXOICR_OFFSET                       0u
#define XIP_SSI_RXOICR_RXOICR_MASK                         1u

#define XIP_SSI_RXUICR_RXUICR_OFFSET                       0u
#define XIP_SSI_RXUICR_RXUICR_MASK                         1u

#define XIP_SSI_MSTICR_MSTICR_OFFSET                       0u
#define XIP_SSI_MSTICR_MSTICR_MASK                         1u

#define XIP_SSI_ICR_ICR_OFFSET                             0u
#define XIP_SSI_ICR_ICR_MASK                               1u

#define XIP_SSI_DMACR_TDMAE_OFFSET                         1u
#define XIP_SSI_DMACR_TDMAE_MASK                           2u

#define XIP_SSI_DMACR_RDMAE_OFFSET                         0u
#define XIP_SSI_DMACR_RDMAE_MASK                           1u

#define XIP_SSI_DMATDLR_DMATDL_OFFSET                      0u
#define XIP_SSI_DMATDLR_DMATDL_MASK                        0xffu

#define XIP_SSI_DMARDLR_DMARDL_OFFSET                      0u
#define XIP_SSI_DMARDLR_DMARDL_MASK                        0xffu

#define XIP_SSI_IDR_IDCODE_OFFSET                          0u
#define XIP_SSI_IDR_IDCODE_MASK                            0xffffffffu

#define XIP_SSI_SSI_VERSION_ID_SSI_COMP_VERSION_OFFSET     0u
#define XIP_SSI_SSI_VERSION_ID_SSI_COMP_VERSION_MASK       0xffffffffu

#define XIP_SSI_DR0_DR_OFFSET                              0u
#define XIP_SSI_DR0_DR_MASK                                0xffffffffu

#define XIP_SSI_RX_SAMPLE_DLY_RSD_OFFSET                   0u
#define XIP_SSI_RX_SAMPLE_DLY_RSD_MASK                     0xffu

#define XIP_SSI_SPI_CTRLR0_XIP_CMD_OFFSET                  24u
#define XIP_SSI_SPI_CTRLR0_XIP_CMD_MASK                    0xff000000u

#define XIP_SSI_SPI_CTRLR0_SPI_RXDS_EN_OFFSET              18u
#define XIP_SSI_SPI_CTRLR0_SPI_RXDS_EN_MASK                0x40000u

#define XIP_SSI_SPI_CTRLR0_INST_DDR_EN_OFFSET              17u
#define XIP_SSI_SPI_CTRLR0_INST_DDR_EN_MASK                0x20000u

#define XIP_SSI_SPI_CTRLR0_SPI_DDR_EN_OFFSET               16u
#define XIP_SSI_SPI_CTRLR0_SPI_DDR_EN_MASK                 0x10000u

#define XIP_SSI_SPI_CTRLR0_WAIT_CYCLES_OFFSET              11u
#define XIP_SSI_SPI_CTRLR0_WAIT_CYCLES_MASK                0xf800u

#define XIP_SSI_SPI_CTRLR0_INST_L_OFFSET                   8u
#define XIP_SSI_SPI_CTRLR0_INST_L_MASK                     0x300u
#define XIP_SSI_SPI_CTRLR0_INST_L_NONE                     0u
#define XIP_SSI_SPI_CTRLR0_INST_L_4B                       1u
#define XIP_SSI_SPI_CTRLR0_INST_L_8B                       2u
#define XIP_SSI_SPI_CTRLR0_INST_L_16B                      3u

#define XIP_SSI_SPI_CTRLR0_ADDR_L_OFFSET                   2u
#define XIP_SSI_SPI_CTRLR0_ADDR_L_MASK                     0x3cu

#define XIP_SSI_SPI_CTRLR0_TRANS_TYPE_OFFSET               0u
#define XIP_SSI_SPI_CTRLR0_TRANS_TYPE_MASK                 3u
#define XIP_SSI_SPI_CTRLR0_TRANS_TYPE_1C1A                 0u
#define XIP_SSI_SPI_CTRLR0_TRANS_TYPE_1C2A                 1u
#define XIP_SSI_SPI_CTRLR0_TRANS_TYPE_2C2A                 2u

#define XIP_SSI_TXD_DRIVE_EDGE_TDE_OFFSET                  0u
#define XIP_SSI_TXD_DRIVE_EDGE_TDE_MASK                    0xffu


typedef struct
{

/** CTRLR0 (offset: 0x0)
  Control register 0
  access : read-write
  reset value : 0x0
  reset mask : 0x0
  Field: SSTE
  offset: 24, size: 1, access: read-write
  Slave select toggle enable
  Field: SPI_FRF
  offset: 21, size: 2, access: read-write
  SPI frame format
  Enum:
  Value: 0 - STD : Standard 1-bit SPI frame format 1 bit per SCK, full-duplex
  Value: 1 - DUAL : Dual-SPI frame format two bits per SCK, half-duplex
  Value: 2 - QUAD : Quad-SPI frame format four bits per SCK, half-duplex
  Field: DFS_32
  offset: 16, size: 5, access: read-write
  Data frame size in 32b transfer mode

 Value of n -&gt; n+1 clocks per frame.
  Field: CFS
  offset: 12, size: 4, access: read-write
  Control frame size

 Value of n -&gt; n+1 clocks per frame.
  Field: SRL
  offset: 11, size: 1, access: read-write
  Shift register loop (test mode)
  Field: SLV_OE
  offset: 10, size: 1, access: read-write
  Slave output enable
  Field: TMOD
  offset: 8, size: 2, access: read-write
  Transfer mode
  Enum:
  Value: 0 - TX_AND_RX : Both transmit and receive
  Value: 1 - TX_ONLY : Transmit only (not for FRF == 0, standard SPI mode)
  Value: 2 - RX_ONLY : Receive only (not for FRF == 0, standard SPI mode)
  Value: 3 - EEPROM_READ : EEPROM read mode (TX then RX RX starts after control data TX&apos;d)
  Field: SCPOL
  offset: 7, size: 1, access: read-write
  Serial clock polarity
  Field: SCPH
  offset: 6, size: 1, access: read-write
  Serial clock phase
  Field: FRF
  offset: 4, size: 2, access: read-write
  Frame format
  Field: DFS
  offset: 0, size: 4, access: read-write
  Data frame size
*/
volatile uint32_t CTRLR0;

/** CTRLR1 (offset: 0x4)
  Master Control register 1
  access : read-write
  reset value : 0x0
  reset mask : 0x0
  Field: NDF
  offset: 0, size: 16, access: read-write
  Number of data frames
*/
volatile uint32_t CTRLR1;

/** SSIENR (offset: 0x8)
  SSI Enable
  access : read-write
  reset value : 0x0
  reset mask : 0x0
  Field: SSI_EN
  offset: 0, size: 1, access: read-write
  SSI enable
*/
volatile uint32_t SSIENR;

/** MWCR (offset: 0xc)
  Microwire Control
  access : read-write
  reset value : 0x0
  reset mask : 0x0
  Field: MHS
  offset: 2, size: 1, access: read-write
  Microwire handshaking
  Field: MDD
  offset: 1, size: 1, access: read-write
  Microwire control
  Field: MWMOD
  offset: 0, size: 1, access: read-write
  Microwire transfer mode
*/
volatile uint32_t MWCR;

/** SER (offset: 0x10)
  Slave enable
  access : read-write
  reset value : 0x0
  reset mask : 0x0
  Field: SER
  offset: 0, size: 1, access: read-write
  For each bit:

 0 -&gt; slave not selected

 1 -&gt; slave selected
*/
volatile uint32_t SER;

/** BAUDR (offset: 0x14)
  Baud rate
  access : read-write
  reset value : 0x0
  reset mask : 0x0
  Field: SCKDV
  offset: 0, size: 16, access: read-write
  SSI clock divider
*/
volatile uint32_t BAUDR;

/** TXFTLR (offset: 0x18)
  TX FIFO threshold level
  access : read-write
  reset value : 0x0
  reset mask : 0x0
  Field: TFT
  offset: 0, size: 8, access: read-write
  Transmit FIFO threshold
*/
volatile uint32_t TXFTLR;

/** RXFTLR (offset: 0x1c)
  RX FIFO threshold level
  access : read-write
  reset value : 0x0
  reset mask : 0x0
  Field: RFT
  offset: 0, size: 8, access: read-write
  Receive FIFO threshold
*/
volatile uint32_t RXFTLR;

/** TXFLR (offset: 0x20)
  TX FIFO level
  access : read-write
  reset value : 0x0
  reset mask : 0x0
  Field: TFTFL
  offset: 0, size: 8, access: read-only
  Transmit FIFO level
*/
volatile uint32_t TXFLR;

/** RXFLR (offset: 0x24)
  RX FIFO level
  access : read-write
  reset value : 0x0
  reset mask : 0x0
  Field: RXTFL
  offset: 0, size: 8, access: read-only
  Receive FIFO level
*/
volatile uint32_t RXFLR;

/** SR (offset: 0x28)
  Status register
  access : read-write
  reset value : 0x0
  reset mask : 0x0
  Field: DCOL
  offset: 6, size: 1, access: read-only
  Data collision error
  Field: TXE
  offset: 5, size: 1, access: read-only
  Transmission error
  Field: RFF
  offset: 4, size: 1, access: read-only
  Receive FIFO full
  Field: RFNE
  offset: 3, size: 1, access: read-only
  Receive FIFO not empty
  Field: TFE
  offset: 2, size: 1, access: read-only
  Transmit FIFO empty
  Field: TFNF
  offset: 1, size: 1, access: read-only
  Transmit FIFO not full
  Field: BUSY
  offset: 0, size: 1, access: read-only
  SSI busy flag
*/
volatile uint32_t SR;

/** IMR (offset: 0x2c)
  Interrupt mask
  access : read-write
  reset value : 0x0
  reset mask : 0x0
  Field: MSTIM
  offset: 5, size: 1, access: read-write
  Multi-master contention interrupt mask
  Field: RXFIM
  offset: 4, size: 1, access: read-write
  Receive FIFO full interrupt mask
  Field: RXOIM
  offset: 3, size: 1, access: read-write
  Receive FIFO overflow interrupt mask
  Field: RXUIM
  offset: 2, size: 1, access: read-write
  Receive FIFO underflow interrupt mask
  Field: TXOIM
  offset: 1, size: 1, access: read-write
  Transmit FIFO overflow interrupt mask
  Field: TXEIM
  offset: 0, size: 1, access: read-write
  Transmit FIFO empty interrupt mask
*/
volatile uint32_t IMR;

/** ISR (offset: 0x30)
  Interrupt status
  access : read-write
  reset value : 0x0
  reset mask : 0x0
  Field: MSTIS
  offset: 5, size: 1, access: read-only
  Multi-master contention interrupt status
  Field: RXFIS
  offset: 4, size: 1, access: read-only
  Receive FIFO full interrupt status
  Field: RXOIS
  offset: 3, size: 1, access: read-only
  Receive FIFO overflow interrupt status
  Field: RXUIS
  offset: 2, size: 1, access: read-only
  Receive FIFO underflow interrupt status
  Field: TXOIS
  offset: 1, size: 1, access: read-only
  Transmit FIFO overflow interrupt status
  Field: TXEIS
  offset: 0, size: 1, access: read-only
  Transmit FIFO empty interrupt status
*/
volatile uint32_t ISR;

/** RISR (offset: 0x34)
  Raw interrupt status
  access : read-write
  reset value : 0x0
  reset mask : 0x0
  Field: MSTIR
  offset: 5, size: 1, access: read-only
  Multi-master contention raw interrupt status
  Field: RXFIR
  offset: 4, size: 1, access: read-only
  Receive FIFO full raw interrupt status
  Field: RXOIR
  offset: 3, size: 1, access: read-only
  Receive FIFO overflow raw interrupt status
  Field: RXUIR
  offset: 2, size: 1, access: read-only
  Receive FIFO underflow raw interrupt status
  Field: TXOIR
  offset: 1, size: 1, access: read-only
  Transmit FIFO overflow raw interrupt status
  Field: TXEIR
  offset: 0, size: 1, access: read-only
  Transmit FIFO empty raw interrupt status
*/
volatile uint32_t RISR;

/** TXOICR (offset: 0x38)
  TX FIFO overflow interrupt clear
  access : read-write
  reset value : 0x0
  reset mask : 0x0
  Field: TXOICR
  offset: 0, size: 1, access: read-only
  Clear-on-read transmit FIFO overflow interrupt
*/
volatile uint32_t TXOICR;

/** RXOICR (offset: 0x3c)
  RX FIFO overflow interrupt clear
  access : read-write
  reset value : 0x0
  reset mask : 0x0
  Field: RXOICR
  offset: 0, size: 1, access: read-only
  Clear-on-read receive FIFO overflow interrupt
*/
volatile uint32_t RXOICR;

/** RXUICR (offset: 0x40)
  RX FIFO underflow interrupt clear
  access : read-write
  reset value : 0x0
  reset mask : 0x0
  Field: RXUICR
  offset: 0, size: 1, access: read-only
  Clear-on-read receive FIFO underflow interrupt
*/
volatile uint32_t RXUICR;

/** MSTICR (offset: 0x44)
  Multi-master interrupt clear
  access : read-write
  reset value : 0x0
  reset mask : 0x0
  Field: MSTICR
  offset: 0, size: 1, access: read-only
  Clear-on-read multi-master contention interrupt
*/
volatile uint32_t MSTICR;

/** ICR (offset: 0x48)
  Interrupt clear
  access : read-write
  reset value : 0x0
  reset mask : 0x0
  Field: ICR
  offset: 0, size: 1, access: read-only
  Clear-on-read all active interrupts
*/
volatile uint32_t ICR;

/** DMACR (offset: 0x4c)
  DMA control
  access : read-write
  reset value : 0x0
  reset mask : 0x0
  Field: TDMAE
  offset: 1, size: 1, access: read-write
  Transmit DMA enable
  Field: RDMAE
  offset: 0, size: 1, access: read-write
  Receive DMA enable
*/
volatile uint32_t DMACR;

/** DMATDLR (offset: 0x50)
  DMA TX data level
  access : read-write
  reset value : 0x0
  reset mask : 0x0
  Field: DMATDL
  offset: 0, size: 8, access: read-write
  Transmit data watermark level
*/
volatile uint32_t DMATDLR;

/** DMARDLR (offset: 0x54)
  DMA RX data level
  access : read-write
  reset value : 0x0
  reset mask : 0x0
  Field: DMARDL
  offset: 0, size: 8, access: read-write
  Receive data watermark level (DMARDLR+1)
*/
volatile uint32_t DMARDLR;

/** IDR (offset: 0x58)
  Identification register
  access : read-write
  reset value : 0x51535049
  reset mask : 0x0
  Field: IDCODE
  offset: 0, size: 32, access: read-only
  Peripheral dentification code
*/
volatile uint32_t IDR;

/** SSI_VERSION_ID (offset: 0x5c)
  Version ID
  access : read-write
  reset value : 0x3430312A
  reset mask : 0x0
  Field: SSI_COMP_VERSION
  offset: 0, size: 32, access: read-only
  SNPS component version (format X.YY)
*/
volatile uint32_t SSI_VERSION_ID;

/** DR0 (offset: 0x60)
  Data Register 0 (of 36)
  access : read-write
  reset value : 0x0
  reset mask : 0x0
  Field: DR
  offset: 0, size: 32, access: read-write
  First data register of 36
*/
volatile uint32_t DR0;
volatile uint32_t reserved0[35];

/** RX_SAMPLE_DLY (offset: 0xf0)
  RX sample delay
  access : read-write
  reset value : 0x0
  reset mask : 0x0
  Field: RSD
  offset: 0, size: 8, access: read-write
  RXD sample delay (in SCLK cycles)
*/
volatile uint32_t RX_SAMPLE_DLY;

/** SPI_CTRLR0 (offset: 0xf4)
  SPI control
  access : read-write
  reset value : 0x3000000
  reset mask : 0x0
  Field: XIP_CMD
  offset: 24, size: 8, access: read-write
  SPI Command to send in XIP mode (INST_L = 8-bit) or to append to Address (INST_L = 0-bit)
  Field: SPI_RXDS_EN
  offset: 18, size: 1, access: read-write
  Read data strobe enable
  Field: INST_DDR_EN
  offset: 17, size: 1, access: read-write
  Instruction DDR transfer enable
  Field: SPI_DDR_EN
  offset: 16, size: 1, access: read-write
  SPI DDR transfer enable
  Field: WAIT_CYCLES
  offset: 11, size: 5, access: read-write
  Wait cycles between control frame transmit and data reception (in SCLK cycles)
  Field: INST_L
  offset: 8, size: 2, access: read-write
  Instruction length (0/4/8/16b)
  Enum:
  Value: 0 - NONE : No instruction
  Value: 1 - 4B : 4-bit instruction
  Value: 2 - 8B : 8-bit instruction
  Value: 3 - 16B : 16-bit instruction
  Field: ADDR_L
  offset: 2, size: 4, access: read-write
  Address length (0b-60b in 4b increments)
  Field: TRANS_TYPE
  offset: 0, size: 2, access: read-write
  Address and instruction transfer format
  Enum:
  Value: 0 - 1C1A : Command and address both in standard SPI frame format
  Value: 1 - 1C2A : Command in standard SPI format, address in format specified by FRF
  Value: 2 - 2C2A : Command and address both in format specified by FRF (e.g. Dual-SPI)
*/
volatile uint32_t SPI_CTRLR0;

/** TXD_DRIVE_EDGE (offset: 0xf8)
  TX drive edge
  access : read-write
  reset value : 0x0
  reset mask : 0x0
  Field: TDE
  offset: 0, size: 8, access: read-write
  TXD drive edge
*/
volatile uint32_t TXD_DRIVE_EDGE;
} XIP_SSI_type;

#define XIP_SSI ((XIP_SSI_type *) 0x18000000)

#endif // HW_XIP_SSI_H
