/*
 * REBThread1.h
 *
 *  Created on: Oct 29, 2019
 *      Author: kfrie
 */

#ifndef REBTHREAD1_H_
#define REBTHREAD1_H_

//#include "/../../../ENCM511_SpecificFiles/ENCM511_include/REB_GPIO_Input_Library.h"
//#include "/../../../ENCM511_SpecificFiles/ENCM511_include/REB_GPIO_Output_Library.h"

void TaskREBThread1(void);
extern "C" unsigned short int My_Read_REB_SW_ASM(void);
extern "C" void My_Write_REB_LEDS_ASM(unsigned short int);

#endif /* REBTHREAD1_H_ */
