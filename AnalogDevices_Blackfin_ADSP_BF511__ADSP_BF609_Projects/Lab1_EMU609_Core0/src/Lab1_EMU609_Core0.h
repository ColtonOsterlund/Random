/*****************************************************************************
 * Lab0_EMU609_Core0.h
 *****************************************************************************/

#ifndef __LAB0_EMU609_CORE0_H__
#define __LAB0_EMU609_CORE0_H__

/* Add your custom header content here */
#include <stdio.h>
#include "../../ENCM511_SpecificFiles/ENCM511_include/FrontPanel_LED_Switches.h"
#include "../../ENCM511_SpecificFiles/ENCM511_include/REB_GPIO_Input_Library.h"
#include "../../ENCM511_SpecificFiles/ENCM511_include/REB_GPIO_Output_Library.h"
//#include "../../ENCM511_SpecificFiles/ENCM511_include/REB_SPI_Library.h"
#include <blackfin.h>

//function prototypes
void Start_Lab_General(void);
void Start_Lab_0(unsigned char[]);
void Start_Lab_1(void);
void My_Init_LEDInterface(void);
void My_Init_SwitchInterface(void);
void My_Init_CyclesTimer(void);
void My_WriteLED(unsigned char);
void My_WriteSwitches(unsigned char);
unsigned char My_ReadLED(void);
unsigned char My_ReadSwitches(void);
void PrintBinaryValue(unsigned char);
void WaitTillSwitch1PressedAndReleased(void);
void WaitTillSwitch2PressedAndReleased(void);
void WaitTillSwitch3PressedAndReleased(void);
void WaitTillSwitch4PressedAndReleased(void);
int WaitTillSwitch5PressedAndReleased(void);
unsigned long long int ReadProcessorCyclesCPP(void);
extern "C" unsigned long long int ReadProcessorCyclesASM(void);
void QuickTest_FrontPanelSwitchesLEDS(void);
void FirstTest_REBSwitchesV1(void);
void FirstTest_REBSwitchesV2(void);
void FirstTest_REBSwitchesV3(void);
unsigned short int My_Read_REB_SW_CPP(void);
void My_Write_REB_LEDS_CPP(unsigned short int);
extern "C" unsigned short int My_Read_REB_SW_ASM(void);
extern "C" void My_Write_REB_LEDS_ASM(unsigned short int);
extern "C" unsigned short int My_Init_REB_GPIO_ASM(void);



#endif /* __LAB0_EMU609_CORE0_H__ */
