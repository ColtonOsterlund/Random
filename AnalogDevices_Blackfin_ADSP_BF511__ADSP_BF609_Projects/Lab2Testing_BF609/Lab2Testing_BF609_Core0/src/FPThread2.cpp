/*
 * FPThread2.cpp
 *
 *  Created on: Oct 29, 2019
 *      Author: kfrie
 */


#include <uTTCOSg2017/uTTCOSg.h>
#include <GPIO2017/ADSP_GPIO_interface.h>
#include <stdio.h>

#include "FPThread2.h"

#if defined(__ADSPBF609__)

#elif defined(__ADSPBF533__)

#else
	#error "Unknown processor"
#endif

/*
 * Period 1.2 seconds
 * DUTY 2/3 on 1/3 off
 * LED 7
 */
extern volatile char ID_FPThread2 = 0;
void TaskFPThread2(void){

	static unsigned int previouslyOn = 0; //keeps track of whether it was previously on in the last cycle

	unsigned short int LEDState = Read_GPIO_FrontPanelLEDS() & 0x40;
	unsigned short int newLEDState = LEDState;

	switch(LEDState) {
	case 0x00:
		//printf("In TaskFPThread1 LED OFF at time 0x%8X system cycles\n", ReadProcessorCyclesASM());
		newLEDState = 0x40;
		previouslyOn = 0;
	break;

	case 0x40:
		//printf("In TaskFPThread1 LED  ON at time 0x%8X system cycles\n\n", ReadProcessorCyclesASM());

		if(previouslyOn == 1){
			newLEDState = 0x00;
			previouslyOn = 0;
		}
		else{
			newLEDState = 0x40;
			previouslyOn = 1;
		}

	break;
	}
	LEDState = newLEDState;

	unsigned short int FPLEDValueCurrent = Read_GPIO_FrontPanelLEDS();

	unsigned short int FPLEDValueNew = FPLEDValueCurrent & 0xbf;
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
