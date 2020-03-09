/*
 * REBThread1.cpp
 *
 *  Created on: Oct 29, 2019
 *      Author: kfrie
 */

#include <uTTCOSg2017/uTTCOSg.h>
#include <GPIO2017/ADSP_GPIO_interface.h>
#include <stdio.h>

#include "REBThread1.h"


#if defined(__ADSPBF609__)

#elif defined(__ADSPBF533__)

#else
	#error "Unknown processor"
#endif


/*
 * Count 0 - 15 in 1/4 second intervals
 * LEDS REB 4 - 7
 */
extern volatile char ID_REBThread1 = 0;
void TaskREBThread1(void){

	static unsigned short int CounterValue = 0x0001;
	unsigned short int newCounterValue = CounterValue;

	if(CounterValue == 0x000f){
		newCounterValue = 0x0001;
	}
	else{
		newCounterValue = CounterValue + 1;
	}

	CounterValue = newCounterValue;

	unsigned short REBLEDValueCurrent = My_Read_REB_SW_ASM();
	unsigned short REBLEDValueNew = REBLEDValueCurrent & 0x0fff;

	REBLEDValueNew = REBLEDValueNew | (CounterValue << 12);

	//	printf("\nCURRENT VALUE = 0x%x\n", FPLEDValueCurrent);
	//	printf("\nNEW VALUE = 0x%x\n", FPLEDValueNew);

	My_Write_REB_LEDS_ASM(REBLEDValueNew);

}
