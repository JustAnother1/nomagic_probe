/*
  automatically created from data available on https://chipselect.org/
*/
#ifndef HW_UART0_H
#define HW_UART0_H
/** Interrupt : UART0_IRQ (Vector: 20)  */
/** Memory Block starting at 0x40034000 + 0x0 is 0x1000 bytes in size. It is used for registers. Protection: n */

#include <stdint.h>


#define UART0_UARTDR_OE_OFFSET                             11u
#define UART0_UARTDR_OE_MASK                               0x800u

#define UART0_UARTDR_BE_OFFSET                             10u
#define UART0_UARTDR_BE_MASK                               0x400u

#define UART0_UARTDR_PE_OFFSET                             9u
#define UART0_UARTDR_PE_MASK                               0x200u

#define UART0_UARTDR_FE_OFFSET                             8u
#define UART0_UARTDR_FE_MASK                               0x100u

#define UART0_UARTDR_DATA_OFFSET                           0u
#define UART0_UARTDR_DATA_MASK                             0xffu

#define UART0_UARTRSR_OE_OFFSET                            3u
#define UART0_UARTRSR_OE_MASK                              8u

#define UART0_UARTRSR_BE_OFFSET                            2u
#define UART0_UARTRSR_BE_MASK                              4u

#define UART0_UARTRSR_PE_OFFSET                            1u
#define UART0_UARTRSR_PE_MASK                              2u

#define UART0_UARTRSR_FE_OFFSET                            0u
#define UART0_UARTRSR_FE_MASK                              1u

#define UART0_UARTFR_RI_OFFSET                             8u
#define UART0_UARTFR_RI_MASK                               0x100u

#define UART0_UARTFR_TXFE_OFFSET                           7u
#define UART0_UARTFR_TXFE_MASK                             0x80u

#define UART0_UARTFR_RXFF_OFFSET                           6u
#define UART0_UARTFR_RXFF_MASK                             0x40u

#define UART0_UARTFR_TXFF_OFFSET                           5u
#define UART0_UARTFR_TXFF_MASK                             0x20u

#define UART0_UARTFR_RXFE_OFFSET                           4u
#define UART0_UARTFR_RXFE_MASK                             0x10u

#define UART0_UARTFR_BUSY_OFFSET                           3u
#define UART0_UARTFR_BUSY_MASK                             8u

#define UART0_UARTFR_DCD_OFFSET                            2u
#define UART0_UARTFR_DCD_MASK                              4u

#define UART0_UARTFR_DSR_OFFSET                            1u
#define UART0_UARTFR_DSR_MASK                              2u

#define UART0_UARTFR_CTS_OFFSET                            0u
#define UART0_UARTFR_CTS_MASK                              1u

#define UART0_UARTILPR_ILPDVSR_OFFSET                      0u
#define UART0_UARTILPR_ILPDVSR_MASK                        0xffu

#define UART0_UARTIBRD_BAUD_DIVINT_OFFSET                  0u
#define UART0_UARTIBRD_BAUD_DIVINT_MASK                    0xffffu

#define UART0_UARTFBRD_BAUD_DIVFRAC_OFFSET                 0u
#define UART0_UARTFBRD_BAUD_DIVFRAC_MASK                   0x3fu

#define UART0_UARTLCR_H_SPS_OFFSET                         7u
#define UART0_UARTLCR_H_SPS_MASK                           0x80u

#define UART0_UARTLCR_H_WLEN_OFFSET                        5u
#define UART0_UARTLCR_H_WLEN_MASK                          0x60u

#define UART0_UARTLCR_H_FEN_OFFSET                         4u
#define UART0_UARTLCR_H_FEN_MASK                           0x10u

#define UART0_UARTLCR_H_STP2_OFFSET                        3u
#define UART0_UARTLCR_H_STP2_MASK                          8u

#define UART0_UARTLCR_H_EPS_OFFSET                         2u
#define UART0_UARTLCR_H_EPS_MASK                           4u

#define UART0_UARTLCR_H_PEN_OFFSET                         1u
#define UART0_UARTLCR_H_PEN_MASK                           2u

#define UART0_UARTLCR_H_BRK_OFFSET                         0u
#define UART0_UARTLCR_H_BRK_MASK                           1u

#define UART0_UARTCR_CTSEN_OFFSET                          15u
#define UART0_UARTCR_CTSEN_MASK                            0x8000u

#define UART0_UARTCR_RTSEN_OFFSET                          14u
#define UART0_UARTCR_RTSEN_MASK                            0x4000u

#define UART0_UARTCR_OUT2_OFFSET                           13u
#define UART0_UARTCR_OUT2_MASK                             0x2000u

#define UART0_UARTCR_OUT1_OFFSET                           12u
#define UART0_UARTCR_OUT1_MASK                             0x1000u

#define UART0_UARTCR_RTS_OFFSET                            11u
#define UART0_UARTCR_RTS_MASK                              0x800u

#define UART0_UARTCR_DTR_OFFSET                            10u
#define UART0_UARTCR_DTR_MASK                              0x400u

#define UART0_UARTCR_RXE_OFFSET                            9u
#define UART0_UARTCR_RXE_MASK                              0x200u

#define UART0_UARTCR_TXE_OFFSET                            8u
#define UART0_UARTCR_TXE_MASK                              0x100u

#define UART0_UARTCR_LBE_OFFSET                            7u
#define UART0_UARTCR_LBE_MASK                              0x80u

#define UART0_UARTCR_SIRLP_OFFSET                          2u
#define UART0_UARTCR_SIRLP_MASK                            4u

#define UART0_UARTCR_SIREN_OFFSET                          1u
#define UART0_UARTCR_SIREN_MASK                            2u

#define UART0_UARTCR_UARTEN_OFFSET                         0u
#define UART0_UARTCR_UARTEN_MASK                           1u

#define UART0_UARTIFLS_RXIFLSEL_OFFSET                     3u
#define UART0_UARTIFLS_RXIFLSEL_MASK                       0x38u

#define UART0_UARTIFLS_TXIFLSEL_OFFSET                     0u
#define UART0_UARTIFLS_TXIFLSEL_MASK                       7u

#define UART0_UARTIMSC_OEIM_OFFSET                         10u
#define UART0_UARTIMSC_OEIM_MASK                           0x400u

#define UART0_UARTIMSC_BEIM_OFFSET                         9u
#define UART0_UARTIMSC_BEIM_MASK                           0x200u

#define UART0_UARTIMSC_PEIM_OFFSET                         8u
#define UART0_UARTIMSC_PEIM_MASK                           0x100u

#define UART0_UARTIMSC_FEIM_OFFSET                         7u
#define UART0_UARTIMSC_FEIM_MASK                           0x80u

#define UART0_UARTIMSC_RTIM_OFFSET                         6u
#define UART0_UARTIMSC_RTIM_MASK                           0x40u

#define UART0_UARTIMSC_TXIM_OFFSET                         5u
#define UART0_UARTIMSC_TXIM_MASK                           0x20u

#define UART0_UARTIMSC_RXIM_OFFSET                         4u
#define UART0_UARTIMSC_RXIM_MASK                           0x10u

#define UART0_UARTIMSC_DSRMIM_OFFSET                       3u
#define UART0_UARTIMSC_DSRMIM_MASK                         8u

#define UART0_UARTIMSC_DCDMIM_OFFSET                       2u
#define UART0_UARTIMSC_DCDMIM_MASK                         4u

#define UART0_UARTIMSC_CTSMIM_OFFSET                       1u
#define UART0_UARTIMSC_CTSMIM_MASK                         2u

#define UART0_UARTIMSC_RIMIM_OFFSET                        0u
#define UART0_UARTIMSC_RIMIM_MASK                          1u

#define UART0_UARTRIS_OERIS_OFFSET                         10u
#define UART0_UARTRIS_OERIS_MASK                           0x400u

#define UART0_UARTRIS_BERIS_OFFSET                         9u
#define UART0_UARTRIS_BERIS_MASK                           0x200u

#define UART0_UARTRIS_PERIS_OFFSET                         8u
#define UART0_UARTRIS_PERIS_MASK                           0x100u

#define UART0_UARTRIS_FERIS_OFFSET                         7u
#define UART0_UARTRIS_FERIS_MASK                           0x80u

#define UART0_UARTRIS_RTRIS_OFFSET                         6u
#define UART0_UARTRIS_RTRIS_MASK                           0x40u

#define UART0_UARTRIS_TXRIS_OFFSET                         5u
#define UART0_UARTRIS_TXRIS_MASK                           0x20u

#define UART0_UARTRIS_RXRIS_OFFSET                         4u
#define UART0_UARTRIS_RXRIS_MASK                           0x10u

#define UART0_UARTRIS_DSRRMIS_OFFSET                       3u
#define UART0_UARTRIS_DSRRMIS_MASK                         8u

#define UART0_UARTRIS_DCDRMIS_OFFSET                       2u
#define UART0_UARTRIS_DCDRMIS_MASK                         4u

#define UART0_UARTRIS_CTSRMIS_OFFSET                       1u
#define UART0_UARTRIS_CTSRMIS_MASK                         2u

#define UART0_UARTRIS_RIRMIS_OFFSET                        0u
#define UART0_UARTRIS_RIRMIS_MASK                          1u

#define UART0_UARTMIS_OEMIS_OFFSET                         10u
#define UART0_UARTMIS_OEMIS_MASK                           0x400u

#define UART0_UARTMIS_BEMIS_OFFSET                         9u
#define UART0_UARTMIS_BEMIS_MASK                           0x200u

#define UART0_UARTMIS_PEMIS_OFFSET                         8u
#define UART0_UARTMIS_PEMIS_MASK                           0x100u

#define UART0_UARTMIS_FEMIS_OFFSET                         7u
#define UART0_UARTMIS_FEMIS_MASK                           0x80u

#define UART0_UARTMIS_RTMIS_OFFSET                         6u
#define UART0_UARTMIS_RTMIS_MASK                           0x40u

#define UART0_UARTMIS_TXMIS_OFFSET                         5u
#define UART0_UARTMIS_TXMIS_MASK                           0x20u

#define UART0_UARTMIS_RXMIS_OFFSET                         4u
#define UART0_UARTMIS_RXMIS_MASK                           0x10u

#define UART0_UARTMIS_DSRMMIS_OFFSET                       3u
#define UART0_UARTMIS_DSRMMIS_MASK                         8u

#define UART0_UARTMIS_DCDMMIS_OFFSET                       2u
#define UART0_UARTMIS_DCDMMIS_MASK                         4u

#define UART0_UARTMIS_CTSMMIS_OFFSET                       1u
#define UART0_UARTMIS_CTSMMIS_MASK                         2u

#define UART0_UARTMIS_RIMMIS_OFFSET                        0u
#define UART0_UARTMIS_RIMMIS_MASK                          1u

#define UART0_UARTICR_OEIC_OFFSET                          10u
#define UART0_UARTICR_OEIC_MASK                            0x400u

#define UART0_UARTICR_BEIC_OFFSET                          9u
#define UART0_UARTICR_BEIC_MASK                            0x200u

#define UART0_UARTICR_PEIC_OFFSET                          8u
#define UART0_UARTICR_PEIC_MASK                            0x100u

#define UART0_UARTICR_FEIC_OFFSET                          7u
#define UART0_UARTICR_FEIC_MASK                            0x80u

#define UART0_UARTICR_RTIC_OFFSET                          6u
#define UART0_UARTICR_RTIC_MASK                            0x40u

#define UART0_UARTICR_TXIC_OFFSET                          5u
#define UART0_UARTICR_TXIC_MASK                            0x20u

#define UART0_UARTICR_RXIC_OFFSET                          4u
#define UART0_UARTICR_RXIC_MASK                            0x10u

#define UART0_UARTICR_DSRMIC_OFFSET                        3u
#define UART0_UARTICR_DSRMIC_MASK                          8u

#define UART0_UARTICR_DCDMIC_OFFSET                        2u
#define UART0_UARTICR_DCDMIC_MASK                          4u

#define UART0_UARTICR_CTSMIC_OFFSET                        1u
#define UART0_UARTICR_CTSMIC_MASK                          2u

#define UART0_UARTICR_RIMIC_OFFSET                         0u
#define UART0_UARTICR_RIMIC_MASK                           1u

#define UART0_UARTDMACR_DMAONERR_OFFSET                    2u
#define UART0_UARTDMACR_DMAONERR_MASK                      4u

#define UART0_UARTDMACR_TXDMAE_OFFSET                      1u
#define UART0_UARTDMACR_TXDMAE_MASK                        2u

#define UART0_UARTDMACR_RXDMAE_OFFSET                      0u
#define UART0_UARTDMACR_RXDMAE_MASK                        1u

#define UART0_UARTPERIPHID0_PARTNUMBER0_OFFSET             0u
#define UART0_UARTPERIPHID0_PARTNUMBER0_MASK               0xffu

#define UART0_UARTPERIPHID1_DESIGNER0_OFFSET               4u
#define UART0_UARTPERIPHID1_DESIGNER0_MASK                 0xf0u

#define UART0_UARTPERIPHID1_PARTNUMBER1_OFFSET             0u
#define UART0_UARTPERIPHID1_PARTNUMBER1_MASK               0xfu

#define UART0_UARTPERIPHID2_REVISION_OFFSET                4u
#define UART0_UARTPERIPHID2_REVISION_MASK                  0xf0u

#define UART0_UARTPERIPHID2_DESIGNER1_OFFSET               0u
#define UART0_UARTPERIPHID2_DESIGNER1_MASK                 0xfu

#define UART0_UARTPERIPHID3_CONFIGURATION_OFFSET           0u
#define UART0_UARTPERIPHID3_CONFIGURATION_MASK             0xffu

#define UART0_UARTPCELLID0_UARTPCELLID0_OFFSET             0u
#define UART0_UARTPCELLID0_UARTPCELLID0_MASK               0xffu

#define UART0_UARTPCELLID1_UARTPCELLID1_OFFSET             0u
#define UART0_UARTPCELLID1_UARTPCELLID1_MASK               0xffu

#define UART0_UARTPCELLID2_UARTPCELLID2_OFFSET             0u
#define UART0_UARTPCELLID2_UARTPCELLID2_MASK               0xffu

#define UART0_UARTPCELLID3_UARTPCELLID3_OFFSET             0u
#define UART0_UARTPCELLID3_UARTPCELLID3_MASK               0xffu


typedef struct
{

/** UARTDR (offset: 0x0)
  Data Register, UARTDR
  access : read-write
  reset value : 0x0
  reset mask : 0x0
  Field: OE
  offset: 11, size: 1, access: read-only
  Overrun error. This bit is set to 1 if data is received and the receive FIFO is already full. This is cleared to 0 once there is an empty space in the FIFO and a new character can be written to it.
  Field: BE
  offset: 10, size: 1, access: read-only
  Break error. This bit is set to 1 if a break condition was detected, indicating that the received data input was held LOW for longer than a full-word transmission time (defined as start, data, parity and stop bits). In FIFO mode, this error is associated with the character at the top of the FIFO. When a break occurs, only one 0 character is loaded into the FIFO. The next character is only enabled after the receive data input goes to a 1 (marking state), and the next valid start bit is received.
  Field: PE
  offset: 9, size: 1, access: read-only
  Parity error. When set to 1, it indicates that the parity of the received data character does not match the parity that the EPS and SPS bits in the Line Control Register, UARTLCR_H. In FIFO mode, this error is associated with the character at the top of the FIFO.
  Field: FE
  offset: 8, size: 1, access: read-only
  Framing error. When set to 1, it indicates that the received character did not have a valid stop bit (a valid stop bit is 1). In FIFO mode, this error is associated with the character at the top of the FIFO.
  Field: DATA
  offset: 0, size: 8, access: read-write
  Receive (read) data character. Transmit (write) data character.
*/
volatile uint32_t UARTDR;

/** UARTRSR (offset: 0x4)
  Receive Status Register/Error Clear Register, UARTRSR/UARTECR
  access : read-write
  reset value : 0x0
  reset mask : 0x0
  Field: OE
  offset: 3, size: 1, access: read-write
  Overrun error. This bit is set to 1 if data is received and the FIFO is already full. This bit is cleared to 0 by a write to UARTECR. The FIFO contents remain valid because no more data is written when the FIFO is full, only the contents of the shift register are overwritten. The CPU must now read the data, to empty the FIFO.
  Field: BE
  offset: 2, size: 1, access: read-write
  Break error. This bit is set to 1 if a break condition was detected, indicating that the received data input was held LOW for longer than a full-word transmission time (defined as start, data, parity, and stop bits). This bit is cleared to 0 after a write to UARTECR. In FIFO mode, this error is associated with the character at the top of the FIFO. When a break occurs, only one 0 character is loaded into the FIFO. The next character is only enabled after the receive data input goes to a 1 (marking state) and the next valid start bit is received.
  Field: PE
  offset: 1, size: 1, access: read-write
  Parity error. When set to 1, it indicates that the parity of the received data character does not match the parity that the EPS and SPS bits in the Line Control Register, UARTLCR_H. This bit is cleared to 0 by a write to UARTECR. In FIFO mode, this error is associated with the character at the top of the FIFO.
  Field: FE
  offset: 0, size: 1, access: read-write
  Framing error. When set to 1, it indicates that the received character did not have a valid stop bit (a valid stop bit is 1). This bit is cleared to 0 by a write to UARTECR. In FIFO mode, this error is associated with the character at the top of the FIFO.
*/
volatile uint32_t UARTRSR;
volatile uint32_t reserved0[4];

/** UARTFR (offset: 0x18)
  Flag Register, UARTFR
  access : read-write
  reset value : 0x90
  reset mask : 0x0
  Field: RI
  offset: 8, size: 1, access: read-only
  Ring indicator. This bit is the complement of the UART ring indicator, nUARTRI, modem status input. That is, the bit is 1 when nUARTRI is LOW.
  Field: TXFE
  offset: 7, size: 1, access: read-only
  Transmit FIFO empty. The meaning of this bit depends on the state of the FEN bit in the Line Control Register, UARTLCR_H. If the FIFO is disabled, this bit is set when the transmit holding register is empty. If the FIFO is enabled, the TXFE bit is set when the transmit FIFO is empty. This bit does not indicate if there is data in the transmit shift register.
  Field: RXFF
  offset: 6, size: 1, access: read-only
  Receive FIFO full. The meaning of this bit depends on the state of the FEN bit in the UARTLCR_H Register. If the FIFO is disabled, this bit is set when the receive holding register is full. If the FIFO is enabled, the RXFF bit is set when the receive FIFO is full.
  Field: TXFF
  offset: 5, size: 1, access: read-only
  Transmit FIFO full. The meaning of this bit depends on the state of the FEN bit in the UARTLCR_H Register. If the FIFO is disabled, this bit is set when the transmit holding register is full. If the FIFO is enabled, the TXFF bit is set when the transmit FIFO is full.
  Field: RXFE
  offset: 4, size: 1, access: read-only
  Receive FIFO empty. The meaning of this bit depends on the state of the FEN bit in the UARTLCR_H Register. If the FIFO is disabled, this bit is set when the receive holding register is empty. If the FIFO is enabled, the RXFE bit is set when the receive FIFO is empty.
  Field: BUSY
  offset: 3, size: 1, access: read-only
  UART busy. If this bit is set to 1, the UART is busy transmitting data. This bit remains set until the complete byte, including all the stop bits, has been sent from the shift register. This bit is set as soon as the transmit FIFO becomes non-empty, regardless of whether the UART is enabled or not.
  Field: DCD
  offset: 2, size: 1, access: read-only
  Data carrier detect. This bit is the complement of the UART data carrier detect, nUARTDCD, modem status input. That is, the bit is 1 when nUARTDCD is LOW.
  Field: DSR
  offset: 1, size: 1, access: read-only
  Data set ready. This bit is the complement of the UART data set ready, nUARTDSR, modem status input. That is, the bit is 1 when nUARTDSR is LOW.
  Field: CTS
  offset: 0, size: 1, access: read-only
  Clear to send. This bit is the complement of the UART clear to send, nUARTCTS, modem status input. That is, the bit is 1 when nUARTCTS is LOW.
*/
volatile uint32_t UARTFR;
volatile uint32_t reserved1;

/** UARTILPR (offset: 0x20)
  IrDA Low-Power Counter Register, UARTILPR
  access : read-write
  reset value : 0x0
  reset mask : 0x0
  Field: ILPDVSR
  offset: 0, size: 8, access: read-write
  8-bit low-power divisor value. These bits are cleared to 0 at reset.
*/
volatile uint32_t UARTILPR;

/** UARTIBRD (offset: 0x24)
  Integer Baud Rate Register, UARTIBRD
  access : read-write
  reset value : 0x0
  reset mask : 0x0
  Field: BAUD_DIVINT
  offset: 0, size: 16, access: read-write
  The integer baud rate divisor. These bits are cleared to 0 on reset.
*/
volatile uint32_t UARTIBRD;

/** UARTFBRD (offset: 0x28)
  Fractional Baud Rate Register, UARTFBRD
  access : read-write
  reset value : 0x0
  reset mask : 0x0
  Field: BAUD_DIVFRAC
  offset: 0, size: 6, access: read-write
  The fractional baud rate divisor. These bits are cleared to 0 on reset.
*/
volatile uint32_t UARTFBRD;

/** UARTLCR_H (offset: 0x2c)
  Line Control Register, UARTLCR_H
  access : read-write
  reset value : 0x0
  reset mask : 0x0
  Field: SPS
  offset: 7, size: 1, access: read-write
  Stick parity select. 0 = stick parity is disabled 1 = either: * if the EPS bit is 0 then the parity bit is transmitted and checked as a 1 * if the EPS bit is 1 then the parity bit is transmitted and checked as a 0. This bit has no effect when the PEN bit disables parity checking and generation.
  Field: WLEN
  offset: 5, size: 2, access: read-write
  Word length. These bits indicate the number of data bits transmitted or received in a frame as follows: b11 = 8 bits b10 = 7 bits b01 = 6 bits b00 = 5 bits.
  Field: FEN
  offset: 4, size: 1, access: read-write
  Enable FIFOs: 0 = FIFOs are disabled (character mode) that is, the FIFOs become 1-byte-deep holding registers 1 = transmit and receive FIFO buffers are enabled (FIFO mode).
  Field: STP2
  offset: 3, size: 1, access: read-write
  Two stop bits select. If this bit is set to 1, two stop bits are transmitted at the end of the frame. The receive logic does not check for two stop bits being received.
  Field: EPS
  offset: 2, size: 1, access: read-write
  Even parity select. Controls the type of parity the UART uses during transmission and reception: 0 = odd parity. The UART generates or checks for an odd number of 1s in the data and parity bits. 1 = even parity. The UART generates or checks for an even number of 1s in the data and parity bits. This bit has no effect when the PEN bit disables parity checking and generation.
  Field: PEN
  offset: 1, size: 1, access: read-write
  Parity enable: 0 = parity is disabled and no parity bit added to the data frame 1 = parity checking and generation is enabled.
  Field: BRK
  offset: 0, size: 1, access: read-write
  Send break. If this bit is set to 1, a low-level is continually output on the UARTTXD output, after completing transmission of the current character. For the proper execution of the break command, the software must set this bit for at least two complete frames. For normal use, this bit must be cleared to 0.
*/
volatile uint32_t UARTLCR_H;

/** UARTCR (offset: 0x30)
  Control Register, UARTCR
  access : read-write
  reset value : 0x300
  reset mask : 0x0
  Field: CTSEN
  offset: 15, size: 1, access: read-write
  CTS hardware flow control enable. If this bit is set to 1, CTS hardware flow control is enabled. Data is only transmitted when the nUARTCTS signal is asserted.
  Field: RTSEN
  offset: 14, size: 1, access: read-write
  RTS hardware flow control enable. If this bit is set to 1, RTS hardware flow control is enabled. Data is only requested when there is space in the receive FIFO for it to be received.
  Field: OUT2
  offset: 13, size: 1, access: read-write
  This bit is the complement of the UART Out2 (nUARTOut2) modem status output. That is, when the bit is programmed to a 1, the output is 0. For DTE this can be used as Ring Indicator (RI).
  Field: OUT1
  offset: 12, size: 1, access: read-write
  This bit is the complement of the UART Out1 (nUARTOut1) modem status output. That is, when the bit is programmed to a 1 the output is 0. For DTE this can be used as Data Carrier Detect (DCD).
  Field: RTS
  offset: 11, size: 1, access: read-write
  Request to send. This bit is the complement of the UART request to send, nUARTRTS, modem status output. That is, when the bit is programmed to a 1 then nUARTRTS is LOW.
  Field: DTR
  offset: 10, size: 1, access: read-write
  Data transmit ready. This bit is the complement of the UART data transmit ready, nUARTDTR, modem status output. That is, when the bit is programmed to a 1 then nUARTDTR is LOW.
  Field: RXE
  offset: 9, size: 1, access: read-write
  Receive enable. If this bit is set to 1, the receive section of the UART is enabled. Data reception occurs for either UART signals or SIR signals depending on the setting of the SIREN bit. When the UART is disabled in the middle of reception, it completes the current character before stopping.
  Field: TXE
  offset: 8, size: 1, access: read-write
  Transmit enable. If this bit is set to 1, the transmit section of the UART is enabled. Data transmission occurs for either UART signals, or SIR signals depending on the setting of the SIREN bit. When the UART is disabled in the middle of transmission, it completes the current character before stopping.
  Field: LBE
  offset: 7, size: 1, access: read-write
  Loopback enable. If this bit is set to 1 and the SIREN bit is set to 1 and the SIRTEST bit in the Test Control Register, UARTTCR is set to 1, then the nSIROUT path is inverted, and fed through to the SIRIN path. The SIRTEST bit in the test register must be set to 1 to override the normal half-duplex SIR operation. This must be the requirement for accessing the test registers during normal operation, and SIRTEST must be cleared to 0 when loopback testing is finished. This feature reduces the amount of external coupling required during system test. If this bit is set to 1, and the SIRTEST bit is set to 0, the UARTTXD path is fed through to the UARTRXD path. In either SIR mode or UART mode, when this bit is set, the modem outputs are also fed through to the modem inputs. This bit is cleared to 0 on reset, to disable loopback.
  Field: SIRLP
  offset: 2, size: 1, access: read-write
  SIR low-power IrDA mode. This bit selects the IrDA encoding mode. If this bit is cleared to 0, low-level bits are transmitted as an active high pulse with a width of 3 / 16th of the bit period. If this bit is set to 1, low-level bits are transmitted with a pulse width that is 3 times the period of the IrLPBaud16 input signal, regardless of the selected bit rate. Setting this bit uses less power, but might reduce transmission distances.
  Field: SIREN
  offset: 1, size: 1, access: read-write
  SIR enable: 0 = IrDA SIR ENDEC is disabled. nSIROUT remains LOW (no light pulse generated), and signal transitions on SIRIN have no effect. 1 = IrDA SIR ENDEC is enabled. Data is transmitted and received on nSIROUT and SIRIN. UARTTXD remains HIGH, in the marking state. Signal transitions on UARTRXD or modem status inputs have no effect. This bit has no effect if the UARTEN bit disables the UART.
  Field: UARTEN
  offset: 0, size: 1, access: read-write
  UART enable: 0 = UART is disabled. If the UART is disabled in the middle of transmission or reception, it completes the current character before stopping. 1 = the UART is enabled. Data transmission and reception occurs for either UART signals or SIR signals depending on the setting of the SIREN bit.
*/
volatile uint32_t UARTCR;

/** UARTIFLS (offset: 0x34)
  Interrupt FIFO Level Select Register, UARTIFLS
  access : read-write
  reset value : 0x12
  reset mask : 0x0
  Field: RXIFLSEL
  offset: 3, size: 3, access: read-write
  Receive interrupt FIFO level select. The trigger points for the receive interrupt are as follows: b000 = Receive FIFO becomes &gt;= 1 / 8 full b001 = Receive FIFO becomes &gt;= 1 / 4 full b010 = Receive FIFO becomes &gt;= 1 / 2 full b011 = Receive FIFO becomes &gt;= 3 / 4 full b100 = Receive FIFO becomes &gt;= 7 / 8 full b101-b111 = reserved.
  Field: TXIFLSEL
  offset: 0, size: 3, access: read-write
  Transmit interrupt FIFO level select. The trigger points for the transmit interrupt are as follows: b000 = Transmit FIFO becomes &lt;= 1 / 8 full b001 = Transmit FIFO becomes &lt;= 1 / 4 full b010 = Transmit FIFO becomes &lt;= 1 / 2 full b011 = Transmit FIFO becomes &lt;= 3 / 4 full b100 = Transmit FIFO becomes &lt;= 7 / 8 full b101-b111 = reserved.
*/
volatile uint32_t UARTIFLS;

/** UARTIMSC (offset: 0x38)
  Interrupt Mask Set/Clear Register, UARTIMSC
  access : read-write
  reset value : 0x0
  reset mask : 0x0
  Field: OEIM
  offset: 10, size: 1, access: read-write
  Overrun error interrupt mask. A read returns the current mask for the UARTOEINTR interrupt. On a write of 1, the mask of the UARTOEINTR interrupt is set. A write of 0 clears the mask.
  Field: BEIM
  offset: 9, size: 1, access: read-write
  Break error interrupt mask. A read returns the current mask for the UARTBEINTR interrupt. On a write of 1, the mask of the UARTBEINTR interrupt is set. A write of 0 clears the mask.
  Field: PEIM
  offset: 8, size: 1, access: read-write
  Parity error interrupt mask. A read returns the current mask for the UARTPEINTR interrupt. On a write of 1, the mask of the UARTPEINTR interrupt is set. A write of 0 clears the mask.
  Field: FEIM
  offset: 7, size: 1, access: read-write
  Framing error interrupt mask. A read returns the current mask for the UARTFEINTR interrupt. On a write of 1, the mask of the UARTFEINTR interrupt is set. A write of 0 clears the mask.
  Field: RTIM
  offset: 6, size: 1, access: read-write
  Receive timeout interrupt mask. A read returns the current mask for the UARTRTINTR interrupt. On a write of 1, the mask of the UARTRTINTR interrupt is set. A write of 0 clears the mask.
  Field: TXIM
  offset: 5, size: 1, access: read-write
  Transmit interrupt mask. A read returns the current mask for the UARTTXINTR interrupt. On a write of 1, the mask of the UARTTXINTR interrupt is set. A write of 0 clears the mask.
  Field: RXIM
  offset: 4, size: 1, access: read-write
  Receive interrupt mask. A read returns the current mask for the UARTRXINTR interrupt. On a write of 1, the mask of the UARTRXINTR interrupt is set. A write of 0 clears the mask.
  Field: DSRMIM
  offset: 3, size: 1, access: read-write
  nUARTDSR modem interrupt mask. A read returns the current mask for the UARTDSRINTR interrupt. On a write of 1, the mask of the UARTDSRINTR interrupt is set. A write of 0 clears the mask.
  Field: DCDMIM
  offset: 2, size: 1, access: read-write
  nUARTDCD modem interrupt mask. A read returns the current mask for the UARTDCDINTR interrupt. On a write of 1, the mask of the UARTDCDINTR interrupt is set. A write of 0 clears the mask.
  Field: CTSMIM
  offset: 1, size: 1, access: read-write
  nUARTCTS modem interrupt mask. A read returns the current mask for the UARTCTSINTR interrupt. On a write of 1, the mask of the UARTCTSINTR interrupt is set. A write of 0 clears the mask.
  Field: RIMIM
  offset: 0, size: 1, access: read-write
  nUARTRI modem interrupt mask. A read returns the current mask for the UARTRIINTR interrupt. On a write of 1, the mask of the UARTRIINTR interrupt is set. A write of 0 clears the mask.
*/
volatile uint32_t UARTIMSC;

/** UARTRIS (offset: 0x3c)
  Raw Interrupt Status Register, UARTRIS
  access : read-write
  reset value : 0x0
  reset mask : 0x0
  Field: OERIS
  offset: 10, size: 1, access: read-only
  Overrun error interrupt status. Returns the raw interrupt state of the UARTOEINTR interrupt.
  Field: BERIS
  offset: 9, size: 1, access: read-only
  Break error interrupt status. Returns the raw interrupt state of the UARTBEINTR interrupt.
  Field: PERIS
  offset: 8, size: 1, access: read-only
  Parity error interrupt status. Returns the raw interrupt state of the UARTPEINTR interrupt.
  Field: FERIS
  offset: 7, size: 1, access: read-only
  Framing error interrupt status. Returns the raw interrupt state of the UARTFEINTR interrupt.
  Field: RTRIS
  offset: 6, size: 1, access: read-only
  Receive timeout interrupt status. Returns the raw interrupt state of the UARTRTINTR interrupt. a
  Field: TXRIS
  offset: 5, size: 1, access: read-only
  Transmit interrupt status. Returns the raw interrupt state of the UARTTXINTR interrupt.
  Field: RXRIS
  offset: 4, size: 1, access: read-only
  Receive interrupt status. Returns the raw interrupt state of the UARTRXINTR interrupt.
  Field: DSRRMIS
  offset: 3, size: 1, access: read-only
  nUARTDSR modem interrupt status. Returns the raw interrupt state of the UARTDSRINTR interrupt.
  Field: DCDRMIS
  offset: 2, size: 1, access: read-only
  nUARTDCD modem interrupt status. Returns the raw interrupt state of the UARTDCDINTR interrupt.
  Field: CTSRMIS
  offset: 1, size: 1, access: read-only
  nUARTCTS modem interrupt status. Returns the raw interrupt state of the UARTCTSINTR interrupt.
  Field: RIRMIS
  offset: 0, size: 1, access: read-only
  nUARTRI modem interrupt status. Returns the raw interrupt state of the UARTRIINTR interrupt.
*/
volatile uint32_t UARTRIS;

/** UARTMIS (offset: 0x40)
  Masked Interrupt Status Register, UARTMIS
  access : read-write
  reset value : 0x0
  reset mask : 0x0
  Field: OEMIS
  offset: 10, size: 1, access: read-only
  Overrun error masked interrupt status. Returns the masked interrupt state of the UARTOEINTR interrupt.
  Field: BEMIS
  offset: 9, size: 1, access: read-only
  Break error masked interrupt status. Returns the masked interrupt state of the UARTBEINTR interrupt.
  Field: PEMIS
  offset: 8, size: 1, access: read-only
  Parity error masked interrupt status. Returns the masked interrupt state of the UARTPEINTR interrupt.
  Field: FEMIS
  offset: 7, size: 1, access: read-only
  Framing error masked interrupt status. Returns the masked interrupt state of the UARTFEINTR interrupt.
  Field: RTMIS
  offset: 6, size: 1, access: read-only
  Receive timeout masked interrupt status. Returns the masked interrupt state of the UARTRTINTR interrupt.
  Field: TXMIS
  offset: 5, size: 1, access: read-only
  Transmit masked interrupt status. Returns the masked interrupt state of the UARTTXINTR interrupt.
  Field: RXMIS
  offset: 4, size: 1, access: read-only
  Receive masked interrupt status. Returns the masked interrupt state of the UARTRXINTR interrupt.
  Field: DSRMMIS
  offset: 3, size: 1, access: read-only
  nUARTDSR modem masked interrupt status. Returns the masked interrupt state of the UARTDSRINTR interrupt.
  Field: DCDMMIS
  offset: 2, size: 1, access: read-only
  nUARTDCD modem masked interrupt status. Returns the masked interrupt state of the UARTDCDINTR interrupt.
  Field: CTSMMIS
  offset: 1, size: 1, access: read-only
  nUARTCTS modem masked interrupt status. Returns the masked interrupt state of the UARTCTSINTR interrupt.
  Field: RIMMIS
  offset: 0, size: 1, access: read-only
  nUARTRI modem masked interrupt status. Returns the masked interrupt state of the UARTRIINTR interrupt.
*/
volatile uint32_t UARTMIS;

/** UARTICR (offset: 0x44)
  Interrupt Clear Register, UARTICR
  access : read-write
  reset value : 0x0
  reset mask : 0x0
  Field: OEIC
  offset: 10, size: 1, access: read-write
  Overrun error interrupt clear. Clears the UARTOEINTR interrupt.
  Field: BEIC
  offset: 9, size: 1, access: read-write
  Break error interrupt clear. Clears the UARTBEINTR interrupt.
  Field: PEIC
  offset: 8, size: 1, access: read-write
  Parity error interrupt clear. Clears the UARTPEINTR interrupt.
  Field: FEIC
  offset: 7, size: 1, access: read-write
  Framing error interrupt clear. Clears the UARTFEINTR interrupt.
  Field: RTIC
  offset: 6, size: 1, access: read-write
  Receive timeout interrupt clear. Clears the UARTRTINTR interrupt.
  Field: TXIC
  offset: 5, size: 1, access: read-write
  Transmit interrupt clear. Clears the UARTTXINTR interrupt.
  Field: RXIC
  offset: 4, size: 1, access: read-write
  Receive interrupt clear. Clears the UARTRXINTR interrupt.
  Field: DSRMIC
  offset: 3, size: 1, access: read-write
  nUARTDSR modem interrupt clear. Clears the UARTDSRINTR interrupt.
  Field: DCDMIC
  offset: 2, size: 1, access: read-write
  nUARTDCD modem interrupt clear. Clears the UARTDCDINTR interrupt.
  Field: CTSMIC
  offset: 1, size: 1, access: read-write
  nUARTCTS modem interrupt clear. Clears the UARTCTSINTR interrupt.
  Field: RIMIC
  offset: 0, size: 1, access: read-write
  nUARTRI modem interrupt clear. Clears the UARTRIINTR interrupt.
*/
volatile uint32_t UARTICR;

/** UARTDMACR (offset: 0x48)
  DMA Control Register, UARTDMACR
  access : read-write
  reset value : 0x0
  reset mask : 0x0
  Field: DMAONERR
  offset: 2, size: 1, access: read-write
  DMA on error. If this bit is set to 1, the DMA receive request outputs, UARTRXDMASREQ or UARTRXDMABREQ, are disabled when the UART error interrupt is asserted.
  Field: TXDMAE
  offset: 1, size: 1, access: read-write
  Transmit DMA enable. If this bit is set to 1, DMA for the transmit FIFO is enabled.
  Field: RXDMAE
  offset: 0, size: 1, access: read-write
  Receive DMA enable. If this bit is set to 1, DMA for the receive FIFO is enabled.
*/
volatile uint32_t UARTDMACR;
volatile uint32_t reserved2[997];

/** UARTPERIPHID0 (offset: 0xfe0)
  UARTPeriphID0 Register
  access : read-write
  reset value : 0x11
  reset mask : 0x0
  Field: PARTNUMBER0
  offset: 0, size: 8, access: read-only
  These bits read back as 0x11
*/
volatile uint32_t UARTPERIPHID0;

/** UARTPERIPHID1 (offset: 0xfe4)
  UARTPeriphID1 Register
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
volatile uint32_t UARTPERIPHID1;

/** UARTPERIPHID2 (offset: 0xfe8)
  UARTPeriphID2 Register
  access : read-write
  reset value : 0x34
  reset mask : 0x0
  Field: REVISION
  offset: 4, size: 4, access: read-only
  This field depends on the revision of the UART: r1p0 0x0 r1p1 0x1 r1p3 0x2 r1p4 0x2 r1p5 0x3
  Field: DESIGNER1
  offset: 0, size: 4, access: read-only
  These bits read back as 0x4
*/
volatile uint32_t UARTPERIPHID2;

/** UARTPERIPHID3 (offset: 0xfec)
  UARTPeriphID3 Register
  access : read-write
  reset value : 0x0
  reset mask : 0x0
  Field: CONFIGURATION
  offset: 0, size: 8, access: read-only
  These bits read back as 0x00
*/
volatile uint32_t UARTPERIPHID3;

/** UARTPCELLID0 (offset: 0xff0)
  UARTPCellID0 Register
  access : read-write
  reset value : 0xD
  reset mask : 0x0
  Field: UARTPCELLID0
  offset: 0, size: 8, access: read-only
  These bits read back as 0x0D
*/
volatile uint32_t UARTPCELLID0;

/** UARTPCELLID1 (offset: 0xff4)
  UARTPCellID1 Register
  access : read-write
  reset value : 0xF0
  reset mask : 0x0
  Field: UARTPCELLID1
  offset: 0, size: 8, access: read-only
  These bits read back as 0xF0
*/
volatile uint32_t UARTPCELLID1;

/** UARTPCELLID2 (offset: 0xff8)
  UARTPCellID2 Register
  access : read-write
  reset value : 0x5
  reset mask : 0x0
  Field: UARTPCELLID2
  offset: 0, size: 8, access: read-only
  These bits read back as 0x05
*/
volatile uint32_t UARTPCELLID2;

/** UARTPCELLID3 (offset: 0xffc)
  UARTPCellID3 Register
  access : read-write
  reset value : 0xB1
  reset mask : 0x0
  Field: UARTPCELLID3
  offset: 0, size: 8, access: read-only
  These bits read back as 0xB1
*/
volatile uint32_t UARTPCELLID3;
} UART0_type;

#define UART0 ((UART0_type *) 0x40034000)

#endif // HW_UART0_H
