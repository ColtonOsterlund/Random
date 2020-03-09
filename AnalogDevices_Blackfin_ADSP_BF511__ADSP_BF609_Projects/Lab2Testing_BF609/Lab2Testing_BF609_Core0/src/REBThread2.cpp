/*
 * REBThread2.cpp
 *
 *  Created on: Oct 29, 2019
 *      Author: kfrie
 */
#include <uTTCOSg2017/uTTCOSg.h>
#include <GPIO2017/ADSP_GPIO_interface.h>
#include <stdio.h>

#include "REBThread2.h"


#if defined(__ADSPBF609__)

#elif defined(__ADSPBF533__)

#else
	#error "Unknown processor"
#endif


/*
 * ON COMMAND
 * read REB SW 0 - 3 and store them in an array
 * number of values must be changeable at demo time (no more than 100)
 * FP SW5 and SW4 are available to help control this task
 */

float Lab0RuntimeFraction = 1;
static int numSecondsSW1Held = 0;
//arrayValues[100] = {0};
static int REBArrayLength = 0;

extern volatile char ID_StoreSwitchValuesInArrayThread = 0;
void StoreSwitchValuesInArrayThread(void){
	static int index = 0;

	arrayValues[index] = (My_Read_REB_SW_ASM() & 0xf000) >> 12;

	//printf("\n\n0x%x\n\n", arrayValues[index]);

	index += 1;

	if(index == 100){
		index = 0; //start rewriting over the array
	}
	else{
		REBArrayLength += 1; //length will increase until == 100
	}
}

unsigned short int getArrayValues(int i){
	return arrayValues[i];
}
