/*****************************************************************************
 * Lab0_EMU609_Core0.h
 *****************************************************************************/

#ifndef __LAB0_EMU609_CORE0_H__
#define __LAB0_EMU609_CORE0_H__

/* Add your custom header content here */
#include <stdio.h>
#include "../../ENCM511_SpecificFiles/ENCM511_include/FrontPanel_LED_Switches.h"
#include <blackfin.h>

//function prototypes
void Start_Lab0(void);
void My_Init_LEDInterface(void);
void My_Init_SwitchInterface(void);
void My_WriteLED(unsigned char);
void My_WriteSwitches(unsigned char);
unsigned char My_ReadLED(void);
unsigned char My_ReadSwitches(void);
void PrintBinaryValue(unsigned char);
void WaitTillSwitch1PressedAndReleased(void);
void WaitTillSwitch2PressedAndReleased(void);
void WaitTillSwitch3PressedAndReleased(void);
unsigned long long int ReadProcessorCyclesCPP(void);
extern "C" unsigned long long int ReadProcessorCyclesASM(void);





#endif /* __LAB0_EMU609_CORE0_H__ */
