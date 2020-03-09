/*
 * FPThread3.cpp
 *
 *  Created on: Oct 29, 2019
 *      Author: kfrie
 */



#include <uTTCOSg2017/uTTCOSg.h>
#include <GPIO2017/ADSP_GPIO_interface.h>
#include <stdio.h>

#include "FPThread3.h"

#if defined(__ADSPBF609__)

#elif defined(__ADSPBF533__)

#else
	#error "Unknown processor"
#endif

/*
 * Period .5 seconds, tics at 1/2 second intervals
 * DUTY 1/2 counts between 0 and 3  00/01/10/11 4 different values
 * LED 1, 2
 */
extern volatile char ID_FPThread3 = 0;
void TaskFPThread3(void){

	static unsigned short int CounterValue = 0x01;
	unsigned short int newCounterValue = CounterValue;

	switch(CounterValue){
	case 0x01:
		newCounterValue = 0x02;
		break;

	case 0x02:
		newCounterValue = 0x03;
		break;

	case 0x03:
		newCounterValue = 0x01;
		break;
	}
	CounterValue = newCounterValue;

	unsigned short int FPLEDValueCurrent = Read_GPIO_FrontPanelLEDS();

	unsigned short int FPLEDValueNew = FPLEDValueCurrent & 0xfc;
	FPLEDValueNew = FPLEDValueNew | CounterValue;

	//	printf("\nCURRENT VALUE = 0x%x\n", FPLEDValueCurrent);
	//	printf("\nNEW VALUE = 0x%x\n", FPLEDValueNew);

	Write_GPIO_FrontPanelLEDS(FPLEDValueNew);


}
