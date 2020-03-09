/*
 * FPThread3.h
 *
 *  Created on: Oct 29, 2019
 *      Author: kfrie
 */

#ifndef FPTHREAD3_H_
#define FPTHREAD3_H_

#include "../../../ENCM511_SpecificFiles/ENCM511_include/FrontPanel_LED_Switches.h" //needs to go out 3 directories - see file in actual windows directory

void TaskFPThread3(void);
extern "C" unsigned long long int ReadProcessorCyclesASM(void);
#endif /* FPTHREAD3_H_ */
