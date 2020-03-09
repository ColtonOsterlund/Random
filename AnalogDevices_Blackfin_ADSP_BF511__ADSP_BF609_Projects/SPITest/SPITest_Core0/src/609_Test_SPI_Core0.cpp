/*****************************************************************************
 * 609_Test_SPI_Core0.cpp
 *****************************************************************************/

#include <sys/platform.h>
#include <sys/adi_core.h>
#include <ccblkfn.h>
#include "adi_initialize.h"
#include "609_Test_SPI_Core0.h"

/** 
 * If you want to use command program arguments, then place them in the following string. 
 */
char __argv_string[] = "";

int main(int argc, char *argv[])
{
	/**
	 * Initialize managed drivers and/or services that have been added to 
	 * the project.
	 * @return zero on success 
	 */
	adi_initComponents();
	
	/**
	 * The default startup code does not include any functionality to allow
	 * core 0 to enable core 1. A convenient way to enable
	 * core 1 is to use the adi_core_enable function. 
	 */
	adi_core_enable(ADI_CORE_1);
	Test_SPI_609();
	/* Begin adding your custom code here */

	return 0;
}

void Test_SPI_609(void){

	Init_REB_SPI();
	SetBoardLED_SPI_ConfigSoftSwitches();
	while(!REB_SPI_Ready());
	Start_REB_SPI();
	unsigned long int display = 0;
	while(1){
		REB_Write_SPI(display);
		display++;

	}

}
