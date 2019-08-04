/*
 * epwm.h
 *
 *  Created on: Aug 4, 2019
 *      Author: Amr Halim
 */

#ifndef EPWM_EPWM_H_
#define EPWM_EPWM_H_
/* Prescaler to the ePWM modules.  Max ePWM input clock is 100 MHz.
 * epwm prescaler 0 or 1
 * 0 -> epwm modules clk = PLLSYSCLK
 * 1 -> epwm modules clk = PLLSYSCLK/2
 */
#include "F2837xD_device.h"

#define EPWM_PRESCALER 1
// System CLK 100 Mhz
#define SYSCLK 100000000

/*--------------------------------------------------------------------------------------------------------------------------------
[Function Name]: EPWM1A_setPeriodAndDuty.
[Description]: This function is responsible for enabling EPWM1 module and configure PWM period and duty cycle
                   to generate a PWM signal from EPWM1A module on GPIO 0 pin.
[Args]:
[In]        pwmPeriod:
                Timer Base period value that represents PWM frequency.
                T(PWM) = pwmPeriod * T(EPWM Timer Base Clock).
            pwmDuty:
                duty cycle ratio from 0(0%) to 1(100%).
[Returns]   No return.
--------------------------------------------------------------------------------------------------------------------------------*/
void EPWM1A_setPeriodAndDuty(unsigned short pwmPeriod, unsigned short pwmDuty);

#endif /* EPWM_EPWM_H_ */
