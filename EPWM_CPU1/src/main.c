/*
 * main.c
 *
 *  Created on: Aug 4, 2019
 *      Author: Amr Halim
 */

#include "sys_configuration.h"
#include "epwm.h"

void main(void){
    clkInitialize();
    // For 100 Khz PWM, 50% Duty Cycle
    EPWM1A_setPeriodAndDuty(2000, 0.5);
    while(1){

    }
}
