/*
 * source_clk.c
 *
 *  Created on: Aug 4, 2019
 *      Author: Amr Halim
 */
#include "sys_configuration.h"

void clkInitialize(void){
    asm(" EALLOW");                     // Enable EALLOW protected register access
    // Set the clock source.  We are running from INTOSC2 by default after a reset.
    ClkCfgRegs.CLKSRCCTL1.bit.OSCCLKSRCSEL = 0;     // Set clock source to INTOSC2 (default)
    ClkCfgRegs.CLKSRCCTL1.bit.XTALOFF=1;            // Turn off XTALOSC
    // PLL configurations
    ClkCfgRegs.SYSPLLMULT.all=0x0A;            // Set system clk to 100 Mhz
    ClkCfgRegs.SYSCLKDIVSEL.bit.PLLSYSCLKDIV = 0;   // PLLSYSCLK divider from OSCCLK or PLLCLK.
    ClkCfgRegs.SYSPLLCTL1.bit.PLLEN=1;              // Enable PLL
    // Wait for PLL to lock.
    // During this time the CPU is still running from INTOSC2/PLLSYSCLKDIV.
    // Once the PLL is stable we must manually switch over to use the PLL output.
    // Code is not required to sit and wait for the PLL to lock.
    while(ClkCfgRegs.SYSPLLSTS.bit.LOCKS != 1){      // Wait for LOCKS bit to set

    }
    ClkCfgRegs.SYSPLLCTL1.bit.PLLCLKEN=1;           // Choose PLLSYSCLK as system clk
    //--- Finish up
    asm(" EDIS");                       // Disable EALLOW protected register access
}
