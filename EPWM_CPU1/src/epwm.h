/*
 * epwm.h
 *
 *  Created on: Aug 4, 2019
 *      Author: Amr Halim
 */

#ifndef EPWM_EPWM_H_
#define EPWM_EPWM_H_

#include "F2837xD_device.h"

/* ePWM Timer Base counter CLK
 * T(ePWM Timer Base Clock) = PLLSYSCLK/(EPWM_PRESCALER * CLK_DIV * HIGH_SPEED_TB_CLK_PRESCALAR).
 */

/* Prescaler to the ePWM modules CLK; Max ePWM module input clock is 100 MHz.
 * EPWM_PRESCALER 0 or 1
 * 0 -> epwm modules clk = PLLSYSCLK
 * 1 -> epwm modules clk = PLLSYSCLK/2
 */
#define EPWM_PRESCALER 1

// EPWM Timer Base counter CLK Divider 3-Bit Divider.
#define CLK_DIV 1

// High Speed TBClock Prescaler to the ePWM Time Base counter CLK 3-Bit Divider.
#define HIGH_SPEED_TB_CLK_PRESCALAR 1

/*--------------------------------------------------------------------------------------------------------------------------------
[Function Name]: EPWM1A_setPeriodAndDuty.
[Description]: This function is responsible for enabling ePWM1 module and configure PWM period and duty cycle
                   to generate a PWM signal from ePWM1A on GPIO 0 pin.
[Args]:
[In]        pwmPeriod:
                Timer Base period value that represents PWM frequency.
                T(PWM) = (pwmPeriod + 1) * T(ePWM Timer Base Clock).
            pwmDuty:
                duty cycle ratio from 0(0%) to 1(100%).
[Returns]   No return.
--------------------------------------------------------------------------------------------------------------------------------*/
void EPWM1A_setPeriodAndDuty(uint16_t pwmPeriod, uint16_t pwmDuty);

#endif /* EPWM_EPWM_H_ */
