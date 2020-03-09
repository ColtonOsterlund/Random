/*
 * FPThread1.h
 *
 *  Created on: Oct 29, 2019
 *      Author: kfrie
 */

#ifndef FPTHREAD1_H_
#define FPTHREAD1_H_

#include "../../../ENCM511_SpecificFiles/ENCM511_include/FrontPanel_LED_Switches.h" //needs to go out 3 directories - see file in actual windows directory

void Task_FPThread1(void);
extern "C" unsigned long long int ReadProcessorCyclesASM(void);


#endif /* FPTHREAD1_H_ */
