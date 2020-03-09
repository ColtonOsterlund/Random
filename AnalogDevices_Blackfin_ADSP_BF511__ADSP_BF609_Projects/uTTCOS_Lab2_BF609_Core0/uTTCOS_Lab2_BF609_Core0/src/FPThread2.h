/*
 * FPThread2.h
 *
 *  Created on: Oct 29, 2019
 *      Author: kfrie
 */

#ifndef FPTHREAD2_H_
#define FPTHREAD2_H_
#include "../../../ENCM511_SpecificFiles/ENCM511_include/FrontPanel_LED_Switches.h" //needs to go out 3 directories - see file in actual windows directory

void TaskFPThread2(void);
extern "C" unsigned long long int ReadProcessorCyclesASM(void);
#endif /* FPTHREAD2_H_ */
