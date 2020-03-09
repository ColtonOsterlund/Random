/*
 * REBThread3.cpp
 *
 *  Created on: Oct 29, 2019
 *      Author: kfrie
 */
#include <uTTCOSg2017/uTTCOSg.h>
#include <GPIO2017/ADSP_GPIO_interface.h>
#include <stdio.h>

#include "REBThread3.h"

#if defined(__ADSPBF609__)

#elif defined(__ADSPBF533__)

#else
	#error "Unknown processor"
#endif


//Set up fake array
static unsigned short int arrayValues[100] = {0x1,0x2,0x3,0x4,0x5,0x6,0x7,0x8,0x9,0xa,0xb,0xc,0xd};
static int REBArrayLength = 13;
static int index = 0;

/*
 * ON COMMAND display the values from the array stored by REB Thread 2 in REB LEDs 4 - 7
 * DISPLAY changes at 1.3 second intervals, stop when the array values have been displayed.
 * USE FP SW2 as the control to decide which should display.
 * communicate decision to switch with a global volatile message
 * when display is complete have the option to store new values.
 */
int DisplayREBSwitchValuesThread(void){
		//send a volatile message that you display this one
		//if 1 then use REBthread1 if 0 then use REBThread3 to display;
		int previousIndex = index;
		unsigned short int REBLEDValueNew = arrayValues[index];
		//need to pause REBThread1 as it displays on 4-7
		//SHIFT ARRAY VALUES SO THEY ARE IN BITS 12-15
		REBLEDValueNew = REBLEDValueNew <<12;
		//for loop to move through array
		My_Write_REB_LEDS_ASM(REBLEDValueNew);
		index ++;
		if(index >= REBArrayLength){
			index = 0;
		}
		return previousIndex;
}
