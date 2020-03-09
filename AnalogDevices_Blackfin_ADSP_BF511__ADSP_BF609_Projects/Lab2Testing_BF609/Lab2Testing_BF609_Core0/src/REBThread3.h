/*
 * REBThread3.h
 *
 *  Created on: Oct 29, 2019
 *      Author: kfrie
 */

#ifndef REBTHREAD3_H_
#define REBTHREAD3_H_

int DisplayREBSwitchValuesThread(void);
extern "C" void My_Write_REB_LEDS_ASM(unsigned short int);
extern "C" void My_Init_REB_GPIO_ASM(void);

#endif /* REBTHREAD3_H_ */
