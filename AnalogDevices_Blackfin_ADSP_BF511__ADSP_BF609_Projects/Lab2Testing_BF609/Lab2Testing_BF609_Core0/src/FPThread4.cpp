/*
 * FPThread4.cpp
 *
 *  Created on: Oct 29, 2019
 *      Author: kfrie
 */


#include <uTTCOSg2017/uTTCOSg.h>
#include <GPIO2017/ADSP_GPIO_interface.h>
#include <stdio.h>

#include "FPThread4.h"

#if defined(__ADSPBF609__)

#elif defined(__ADSPBF533__)

#else
	#error "Unknown processor"
#endif

#define ARRAY_SIZE 10
unsigned char LEDArray[ARRAY_SIZE] = {0x18, 0x0c, 0x08, 0x14, 0x00, 0x08, 0x0c, 0x18, 0x08, 0x14};

//USE SWITCH 2 TO START
extern volatile char ID_FPThread4 = 0;
void TaskFPThread4(void){

	//DISPLAY LAB 0
	static int indexToDisplay = 0;
	unsigned char toDisplay = LEDArray[indexToDisplay] & 0x3c; //only use bits 3-6

	unsigned char currentLEDVal = Read_GPIO_FrontPanelLEDS() & 0xc3;

	toDisplay = currentLEDVal | toDisplay;

	Write_GPIO_FrontPanelLEDS(toDisplay);

	indexToDisplay += 1;
	if(indexToDisplay == ARRAY_SIZE){
		indexToDisplay = 0;
	}



}


