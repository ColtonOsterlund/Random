/*
 * FPThread5.cpp
 *
 *  Created on: Oct 29, 2019
 *      Author: kfrie
 */

#include <uTTCOSg2017/uTTCOSg.h>
#include <GPIO2017/ADSP_GPIO_interface.h>
#include <stdio.h>

#include "FPThread5.h"

#if defined(__ADSPBF609__)

#elif defined(__ADSPBF533__)

#else
	#error "Unknown processor"
#endif

/*
 * USE FP SW1 control display rate of FPThread4
 * if FP SW1 pressed between 1 and 2 seconds speed up display FPThread4
 * if FP SW1 pressed between 3 and 4 seconds slow down display FPThread4
 * if press time is wrong Pause thread4 till valid command
 * Must have SW1 set up for press and released, and while pressed it does not pause the display
 * CHANGE DISPLAY RATE
 * 			1) passing a global volatile messages between threads or
 * 			2) by killing and relaunching threads
 */

//int numSecondsSW1Held = 0;
//float Lab0RuntimeFraction = 1;

void CountSecondsSW1PressedThread(void){
	numSecondsSW1Held += 1;
}

void ChangeFPThread5SpeedThread(void){
	//uTTCOSg_DeleteThread(ID_FPThread4); //delete thread

	printf("\n\n%d *****\n\n", numSecondsSW1Held);

	if(numSecondsSW1Held == 1){ //held between 1 and 2 seconds
		printf("\n\nheld 1-2 seconds\n\n");
		Lab0RuntimeFraction = Lab0RuntimeFraction * 0.5;
		//ID_FPThread4 = uTTCOSg_AddThread(TaskFPThread4, NO_DELAY, Lab0RuntimeFraction * ONE_SECOND); //restart thread
	}
	else if(numSecondsSW1Held == 3){ //held between 3 and 4 seconds
		printf("\n\nheld 3-4 seconds\n\n");
		Lab0RuntimeFraction = Lab0RuntimeFraction * 2;
		//ID_FPThread4 = uTTCOSg_AddThread(TaskFPThread4, NO_DELAY, Lab0RuntimeFraction * ONE_SECOND); //restart thread
	}
	else{
		printf("\n\nheld other seconds\n\n");
	}

	numSecondsSW1Held = 0; //reset num seconds

}

void setNumSecondsSW1Held(int i){
	numSecondsSW1Held = i;
}

float getLab0RuntimeFraction(void){
	return Lab0RuntimeFraction;
}
