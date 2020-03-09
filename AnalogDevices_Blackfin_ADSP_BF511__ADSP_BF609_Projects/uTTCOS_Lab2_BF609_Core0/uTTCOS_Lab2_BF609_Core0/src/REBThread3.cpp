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


/*
 * ON COMMAND display the values from the array stored by REB Thread 2 in REB LEDs 4 - 7
 * DISPLAY changes at 1.3 second intervals, stop when the array values have been displayed.
 * USE FP SW2 as the control to decide which should display.
 * communicate decision to switch with a global volatile message
 * when display is complete have the option to store new values.
 */
