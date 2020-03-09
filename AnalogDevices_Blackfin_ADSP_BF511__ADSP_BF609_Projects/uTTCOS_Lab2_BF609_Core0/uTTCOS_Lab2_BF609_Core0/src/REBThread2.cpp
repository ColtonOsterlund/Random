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
