/*
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License version 2
 * as published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program; if not, see <http://www.gnu.org/licenses/>
 *
 */
#ifndef HAL_WATCHDOG_H_
#define HAL_WATCHDOG_H_

#include <stdint.h>

#define ISSUE_NO_ISSUE                              0
#define ISSUE_UNEXPECTED_HANDLER_CALLED_NMI         1
#define ISSUE_UNEXPECTED_HANDLER_CALLED_HARD_FAULT  2
#define ISSUE_UNEXPECTED_HANDLER_CALLED_SVCALL      3
#define ISSUE_UNEXPECTED_HANDLER_CALLED_PENDSV      4
#define ISSUE_UNEXPECTED_HANDLER_CALLED_SYSTICK     5
#define ISSUE_UNEXPECTED_HANDLER_CALLED_TIMER_0     6
#define ISSUE_UNEXPECTED_HANDLER_CALLED_TIMER_1     7
#define ISSUE_UNEXPECTED_HANDLER_CALLED_TIMER_2     8
#define ISSUE_UNEXPECTED_HANDLER_CALLED_TIMER_3     9
#define ISSUE_UNEXPECTED_HANDLER_CALLED_PWM         10
#define ISSUE_UNEXPECTED_HANDLER_CALLED_USB_CTRL    11
#define ISSUE_UNEXPECTED_HANDLER_CALLED_XIP         12
#define ISSUE_UNEXPECTED_HANDLER_CALLED_PIO_0_0     13
#define ISSUE_UNEXPECTED_HANDLER_CALLED_PIO_0_1     14
#define ISSUE_UNEXPECTED_HANDLER_CALLED_PIO_1_0     15
#define ISSUE_UNEXPECTED_HANDLER_CALLED_PIO_1_1     16
#define ISSUE_UNEXPECTED_HANDLER_CALLED_DMA_0       17
#define ISSUE_UNEXPECTED_HANDLER_CALLED_DMA_1       18
#define ISSUE_UNEXPECTED_HANDLER_CALLED_GPIO_BANK_0 19
#define ISSUE_UNEXPECTED_HANDLER_CALLED_GPIO_QSPI   20
#define ISSUE_UNEXPECTED_HANDLER_CALLED_SIO_PROC_0  21
#define ISSUE_UNEXPECTED_HANDLER_CALLED_SIO_PROC_1  22
#define ISSUE_UNEXPECTED_HANDLER_CALLED_CLOCKS      23
#define ISSUE_UNEXPECTED_HANDLER_CALLED_SPI_0       24
#define ISSUE_UNEXPECTED_HANDLER_CALLED_SPI_1       25
#define ISSUE_UNEXPECTED_HANDLER_CALLED_UART_0      26
#define ISSUE_UNEXPECTED_HANDLER_CALLED_UART_1      27
#define ISSUE_UNEXPECTED_HANDLER_CALLED_ADC_FIFO    28
#define ISSUE_UNEXPECTED_HANDLER_CALLED_I2C_0       29
#define ISSUE_UNEXPECTED_HANDLER_CALLED_I2C_1       30
#define ISSUE_UNEXPECTED_HANDLER_CALLED_RTC         31
#define ISSUE_UNEXPECTED_HANDLER_CALLED_DEFAULT     32
#define ISSUE_UNEXPECTED_CODE_REACHED_MAIN_EXITED   33


void watchdog_enable(void);
//! if you don't feed the watch dog regularly it gets angry!
void watchdog_feed(void);
//! reports type of reset
void watchdog_report(void);
void watchdog_report_issue(uint32_t issue);

#endif /* HAL_WATCHDOG_H_ */
