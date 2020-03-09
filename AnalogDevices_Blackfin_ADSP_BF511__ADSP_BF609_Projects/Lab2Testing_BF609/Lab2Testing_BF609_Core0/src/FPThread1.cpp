/*
 * FPThread1.cpp
 *
 *  Created on: Oct 29, 2019
 *      Author: kfrie
 */


#include <uTTCOSg2017/uTTCOSg.h>
#include <GPIO2017/ADSP_GPIO_interface.h>
#include <stdio.h>

#include "FPThread1.h"


#if defined(__ADSPBF609__)

#elif defined(__ADSPBF533__)

#else
	#error "Unknown processor"
#endif

/*
 * Period 0.5 seconds
 * DUTY .25s on .25s off
 * LED 8
 */

extern volatile char ID_FPThread1 = 0;
void Task_FPThread1(void){
	unsigned short int LEDState = Read_GPIO_FrontPanelLEDS() & 0x80;
		unsigned short int newLEDState = LEDState;

		switch(LEDState) {
		case 0x00:
			//printf("In TaskFPThread1 LED OFF at time 0x%8X system cycles\n", ReadProcessorCyclesASM());
			newLEDState = 0x80;
		break;

		case 0x80:
			//printf("In TaskFPThread1 LED  ON at time 0x%8X system cycles\n\n", ReadProcessorCyclesASM());
			newLEDState = 0x00;
		break;
		}
		LEDState = newLEDState;

		//printf("\n\nLEDState = %d\n\n", LEDState);

		unsigned short int FPLEDValueCurrent = Read_GPIO_FrontPanelLEDS();

		unsigned short int FPLEDValueNew = FPLEDValueCurrent & 0x7f;
		FPLEDValueNew = FPLEDValueNew | LEDState;

	//	printf("\nCURRENT VALUE = 0x%x\n", FPLEDValueCurrent);
	//	printf("\nNEW VALUE = 0x%x\n", FPLEDValueNew);

		Write_GPIO_FrontPanelLEDS(FPLEDValueNew);

		//now E Unit test to make sure the write value is written
		unsigned short int expectedLEDValue;
		//set up the expected LEDValue and what the LEDValue is
		// compare the expected value to what the value is
		// if they are equal return 1
		// if they are not equal return 0


}



