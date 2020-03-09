/*
 * REBThread2.h
 *
 *  Created on: Oct 29, 2019
 *      Author: kfrie
 */

#ifndef REBTHREAD2_H_
#define REBTHREAD2_H_


#include <stdio.h>
#include "../../../ENCM511_SpecificFiles/ENCM511_include/FrontPanel_LED_Switches.h"

void StoreSwitchValuesInArrayThread(void);
static unsigned short int arrayValues[100] = {0};
extern "C" void My_Init_REB_GPIO_ASM(void);
extern "C" void My_Write_REB_LEDS_ASM(unsigned short int);
extern "C" unsigned short int My_Read_REB_SW_ASM(void);
unsigned short int getArrayValues(int i);


#endif /* REBTHREAD2_H_ */
