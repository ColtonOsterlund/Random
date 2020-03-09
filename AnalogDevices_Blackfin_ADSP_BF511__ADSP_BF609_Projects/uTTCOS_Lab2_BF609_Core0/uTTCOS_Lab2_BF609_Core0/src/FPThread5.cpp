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


