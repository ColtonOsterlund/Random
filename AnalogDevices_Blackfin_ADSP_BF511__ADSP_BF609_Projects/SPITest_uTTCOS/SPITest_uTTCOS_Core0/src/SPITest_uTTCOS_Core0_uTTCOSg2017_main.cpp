/*************************************************************************************
* AUTO-GENERATED COMMENT - DO NOT MODIFY 
* Author: colto 
* Date: Thu 2019/11/28 at 05:41:54 PM 
* File Type: TTCOS Main File
*************************************************************************************/

// This is an example TT_COS main( ) function with threads.
// Use this as a template for your own TT_COS main( ) for the various Threads

#include "SPITest_uTTCOS_Core0_uTTCOSg2017_main.h"

// TODO -- Update this code to use CORETIMER interrupts to allow slow uTTCOS in BF533 simulator
// TODO Just these values so that 100 TICS tacks about 1 second
#if defined(__ADSPBF609__)
#define  TIC_CONTROL_VALUE ((unsigned long int) 4800000)		// BF609 EMULATOR
#define TICS_PER_SECOND 	100
#define ONE_SECOND 			TICS_PER_SECOND		// If TICS_CONTROL_VALUE Adjusted correctly
#define RUN_ONCE			0
#define NO_DELAY			0
#else
#error "Unknown ADSP or ARM processor"
#endif



#define initResetLEDForMessageArrayLength 6
unsigned short int initResetLEDForMessageArray[initResetLEDForMessageArrayLength] = {0x0000, 0x0430, 0x0030, 0x003c, 0x000f, 0x0001};
unsigned short int ledMessageArray[] = {0};

void main(void) {
	// Make maxNumberThreads at least 5 larger than the 
	//            number of threads you plan to add
	int numBackgroundThreads = 5;
	int numberYourThreads = 4;
	int maxNumberThreads = numBackgroundThreads + numberYourThreads;  

	Custom_uTTCOS_OS_Init(TIC_CONTROL_VALUE);  // Need to update to handle coretimer interrupts

	// TODO -- Remove this TODO statement and next line when demo is finished and you start your Lab 2
	Set_Up_NOT_START_RemoveMeSoonTasks( );


	Init_REB_SPI();

	createThread();


#warning "You will need to activate the next line to start the uTTCOS Clock scheduler
	uTTCOSg_Start_CoreTimer_Scheduler(maxNumberThreads);   //  Start the scheduler timer
				// Execution time of TT_COS_Dispatch( ) and TT_COS_Update( ) improved by specifiying maxNumberTasks




	while (1) {

		// Wait, in low power mode, for an interrupt
		// The interrupt service routine calls TTCOS_Update( )
		// uTTCOSg_GoToSleep( );                // Need to update to handle coretimer interrupts
		Idle_WaitForInterrupts_ASM( );

		// Run all the threads in the system according
		// to whether their delays have expired
		uTTCOSg_DispatchThreads( );
	}
}


extern volatile char ID_Init_Reset_Display;

void createThread(void){
	ID_Init_Reset_Display = uTTCOSg_AddThread(Init_Reset_LCD_Display, NO_DELAY, ONE_SECOND * 5);
}


extern volatile char ID_Init_Reset_Display = 0;
void Init_Reset_LCD_Display(void){
	static int index = 0;

	REB_Write_SPI(initResetLEDForMessageArray[index]);

	if(index < initResetLEDForMessageArrayLength){
		index++;
	}
	else{
		index = 0;
		uTTCOSg_DeleteThread(ID_Init_Reset_Display);
	}
}



