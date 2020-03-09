/*
 * FPThread5.h
 *
 *  Created on: Oct 29, 2019
 *      Author: kfrie
 */

#ifndef FPTHREAD5_H_
#define FPTHREAD5_H_


static int numSecondsSW1Held = 0;
static float Lab0RuntimeFraction = 1;
void CountSecondsSW1PressedThread(void);
void ChangeFPThread5SpeedThread(void);
void setNumSecondsSW1Held(int);
float getLab0RuntimeFraction(void);
#endif /* FPTHREAD5_H_ */
