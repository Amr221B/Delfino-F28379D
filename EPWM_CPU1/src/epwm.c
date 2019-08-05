/*
 * epwm.c
 *
 *  Created on: Aug 4, 2019
 *      Author: Amr Halim
 */
#include "epwm.h"

void EPWM1A_setPeriodAndDuty(unsigned short pwmPeriod, unsigned short pwmDuty){
    asm(" EALLOW");                             // Enable EALLOW protected register access
    // First configure GPIO 0 pin for EPWM1A output
    // Unlock the GPxLOCK register bits
    GpioCtrlRegs.GPACR.bit.GPIO0=0;
    // Disable the register locks
    GpioCtrlRegs.GPALOCK.bit.GPIO0=0;
    // Make GPA0 output
    GpioCtrlRegs.GPADIR.bit.GPIO0=1;
    // Select EPWM1A functionality
    GpioCtrlRegs.GPAGMUX1.bit.GPIO0=0;
    GpioCtrlRegs.GPAMUX1.bit.GPIO0=1;
    // Configure EPWM1 module
    ClkCfgRegs.PERCLKDIVSEL.bit.EPWMCLKDIV = EPWM_PRESCALER;     // EPWMCLK divider from PLLSYSCLK.
    // Configure timer control register
    // bit 15-14     11:     FREE/SOFT, 11 = ignore emulation suspend
    // bit 13        0:      PHSDIR, 0 = count down after sync event
    // bit 12-10     000:    CLKDIV, 000 => TBCLK = HSPCLK/1
    // bit 9-7       000:    HSPCLKDIV, 000 => HSPCLK = EPWMCLK/1
    // bit 6         0:      SWFSYNC, 0 = no software sync produced
    // bit 5-4       11:     SYNCOSEL, 11 = sync-out disabled
    // bit 3         0:      PRDLD, 0 = reload PRD on counter=0 from Shadow register
    // bit 2         0:      PHSEN, 0 = phase control disabled
    // bit 1-0       11:     CTRMODE, 11 = timer stopped (disabled)
    EPwm1Regs.TBCTL.all = 0xC033;
    EPwm1Regs.TBCTL.bit.HSPCLKDIV = HIGH_SPEED_TB_CLK_PRESCALAR;
    EPwm1Regs.TBCTL.bit.CLKDIV = CLK_DIV;
    EPwm1Regs.TBCTR = 0x0000;               // Clear timer counter
    EPwm1Regs.TBPHS.bit.TBPHS = 0x0000;     // Set timer phase
    EPwm1Regs.TBPRD = pwmPeriod;      // Set timer period
    EPwm1Regs.CMPCTL.all = 0x0002;          // LOADAMODE, 10 = load on zero or PRD match from shadow CMP A register
    EPwm1Regs.CMPA.bit.CMPA = pwmDuty*pwmPeriod;   // Set PWM duty cycle
    // Action-qualifier control register A
    // bit 11-10     00:     CBD, 00 = do nothing
    // bit 9-8       00:     CBU, 00 = do nothing
    // bit 7-6       01:     CAD, 00 = do nothing
    // bit 5-4       10:     CAU, 01 = clear
    // bit 3-2       00:     PRD, 10 = set
    // bit 1-0       00:     ZRO, 10 = set
    EPwm1Regs.AQCTLA.all = 0x0060;
    EPwm1Regs.AQSFRC.all = 0x0000;      // Action-qualifier s/w force register Disabled
    EPwm1Regs.AQCSFRC.all = 0x0000;     // Action-qualifier continuous s/w force register Disabled
    EPwm1Regs.DBCTL.bit.OUT_MODE = 0;   // Deadband disabled
    EPwm1Regs.PCCTL.bit.CHPEN = 0;      // PWM chopper unit disabled
    EPwm1Regs.TZDCSEL.all = 0x0000;     // All trip zone and DC compare actions disabled
    EPwm1Regs.TBCTL.bit.CTRMODE=0;      // Count up mode
    // Select CPU1 system clk as input clk to EPWM1 module
    DevCfgRegs.CPUSEL0.bit.EPWM1=1;
    // Enable clk to EPWM1 Module
    CpuSysRegs.PCLKCR2.bit.EPWM1=1;
    asm(" EDIS");                       // Disable EALLOW protected register access
}
