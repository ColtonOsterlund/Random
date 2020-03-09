/*************************************************************************************
* AUTO-GENERATED COMMENT - DO NOT MODIFY 
* Author: kfrie 
* Date: Tue 2019/10/29 at 02:16:57 PM 
* File Type: TTCOS Main File
*************************************************************************************/

// This is an example TT_COS main( ) function with threads.
// Use this as a template for your own TT_COS main( ) for the various Threads

#include "uTTCOS_Lab2_BF609_Core0_uTTCOSg2017_main.h"
#include "../../../ENCM511_SpecificFiles/ENCM511_include/FrontPanel_LED_Switches.h"
#include "adi_initialize.h"
#include <sys/adi_core.h>
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

//////////////////////////////////////////Lab 2 Variables////////////////////////////////////////////////////////
float Lab0RuntimeFraction = 1;
static int numSecondsSW1Held = 0;
static unsigned short int arrayValues[100] = {0};
static int REBArrayLength = 0;
unsigned short int carArray[64] = {0x4, 0x0, 0x0, 0x0, 0x4, 0x0, 0x0, 0x0, 0x5, 0x1, 0x1, 0x1, 0x5, 0x1, 0x1, 0x1,
0x4, 0x0, 0x0, 0x0, 0xc, 0x8, 0x8, 0x8, 0xc, 0x8, 0x8, 0x8, 0x4, 0x0, 0x0, 0x0, 0x4, 0x0, 0x0, 0x0, 0xc, 0x8, 0x8,
0x8, 0xc, 0x8, 0x8, 0x8, 0x4, 0x0, 0x0, 0x0, 0x5, 0x1, 0x1, 0x1, 0x5, 0x1, 0x1, 0x1, 0x4, 0x0, 0x0, 0x0, 0x4, 0x0, 0x0, 0x0};

///////////////////////////////////////////Lab 4 Variables////////////////////////////////////////////////////////
static float ChinookTemp[10] = {24.0, 26.0, 28.0, 29.0, 33.0, -35.0, -34.0, -20.0};
float currentTemp = 0;
/*extern*/ bool commandStringBeingSent = false;
/*extern*/ bool commandStringToSend = false;
/*extern*/ bool commandStringIsInstruction = false;
/*extern*/ char SPI_MessageBuffer[256];
float currentTemp_Lab3 = 0;
#define LAB3_MOCKED 1
unsigned char commandsToSend = 0;
unsigned char commandsSent = 0;
extern unsigned char ID_SendSPICommandString;
#define SPI_MOCK_LEVEL 1
#define MOCK_LEVEL 1
bool newMessage = true;
static bool sendingMessageNow = false;
static int numberSPIBlocksStillToSend = 0;
static int numberSPIBlocksIndex = 0;
#define initResetLEDForMessageArrayLength 6
unsigned short int initResetLEDForMessageArray[initResetLEDForMessageArrayLength] = {0x0000, 0x0430, 0x0030, 0x003c, 0x000f, 0x0001};
unsigned short int ledMessageArray[] = {0};

//Kyles lab 4 variables
#define BIT_10 0x400
#define BIT_8 0x100
#define ARRAY_511SIZE 12
unsigned long int outputArray[ARRAY_511SIZE] = {0x20,0x20,0x35,0x31,0x31,0x20,0x20,0x52,0x55,0x4C,0x53,0x20};
#define INITAL_ARRAY_SIZE 10



void main(void) {

	adi_initComponents();

	// Make maxNumberThreads at least 5 larger than the 
	//            number of threads you plan to add
	int numBackgroundThreads = 5;
	int numberYourThreads = 8;
	int maxNumberThreads = numBackgroundThreads + numberYourThreads;
// initialize the front panel LED and Switches
	Init_GPIO_FrontPanelSwitches();
	Init_GPIO_FrontPanelLEDS();
	My_Init_REB_GPIO_ASM();

	Init_REB_SPI(); //this is stopping the code from running

	SetBoardLED_SPI_ConfigSoftSwitches();
	Start_REB_SPI();
	unsigned char timer = 3;

	Init_GP_Timer(timer);
	Start_GP_Timer(timer);

	Custom_uTTCOS_OS_Init(TIC_CONTROL_VALUE);  // Need to update to handle coretimer interrupts
#if 0
	// TODO -- Remove this TODO statement and next line when demo is finished and you start your Lab 2
	Set_Up_NOT_START_RemoveMeSoonTasks( );
#endif




	createThreads();

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

//Lab 2
extern volatile char ID_FPThread1;
extern volatile char ID_FPThread2;
extern volatile char ID_FPThread3;
extern volatile char ID_FPThread4;
extern volatile char ID_FPThread5;
extern volatile char ID_REBThread1;
extern volatile char ID_REBThread2;
extern volatile char ID_REBThread3;
extern volatile char ID_CheckSW2PressedReleasedThread;
extern volatile char ID_StopCheckSW2PressedReleasedThread;
extern volatile char ID_CheckSW1PressedReleasedThread;
extern volatile char ID_CountSecondsSW1PressedThread;
extern volatile char ID_ChangeFPThread5SpeedThread;
extern volatile char ID_CheckSW5PressedReleased;
extern volatile char ID_StoreSwitchValuesInArrayThread;
extern volatile char ID_CheckSW3PressedReleasedThread;
extern volatile char ID_REBThread3;

extern volatile char ID_DisplayMessage0_SPI;
extern volatile char ID_DisplayMessage1_SPI;
extern volatile char ID_DisplayMessage2_SPI;
extern volatile char ID_DisplayTemperature_SPI;
extern volatile char ID_CalcTemp;
extern volatile char ID_SetGlobalTemp;


//Lab 4
//extern volatile char ID_FlashLED6;
//extern volatile char ID_Mock_SPI;
//extern volatile char ID_InitSPI;
//extern volatile char ID_MSG0;
//extern volatile char ID_MSG1;
//extern volatile char ID_MSG2;
//extern volatile char ID_DisplayTemp;
//extern volatile char ID_initResetLCDREB;

void createThreads(void){
#if 0 //LAB 2 Threads
	ID_FPThread1 = uTTCOSg_AddThread(Task_FPThread1, NO_DELAY, 0.25 * ONE_SECOND); //need to switch LED every .25 seconds
	ID_FPThread2 = uTTCOSg_AddThread(TaskFPThread2, NO_DELAY, 0.33 * (1.2 * ONE_SECOND));
	ID_FPThread3 = uTTCOSg_AddThread(TaskFPThread3, NO_DELAY, 0.5 * ONE_SECOND);
	ID_CheckSW2PressedReleasedThread = uTTCOSg_AddThread(CheckSW2PressedReleasedThread, NO_DELAY, 0.1 * ONE_SECOND); //checks state of button every 10th of a second
	ID_REBThread1 = uTTCOSg_AddThread(TaskREBThread1, NO_DELAY, 0.25 * ONE_SECOND);
	ID_CheckSW1PressedReleasedThread = uTTCOSg_AddThread(CheckSW1PressedReleasedThread, NO_DELAY, 0.1 * ONE_SECOND);
	ID_CheckSW5PressedReleased = uTTCOSg_AddThread(CheckSW5PressedReleased, NO_DELAY, 0.1 * ONE_SECOND);
	ID_CheckSW3PressedReleasedThread = uTTCOSg_AddThread(CheckSW3PressedReleased, NO_DELAY, 0.1 * ONE_SECOND);
#endif

#if 0 //Lab 4A

	//SPI_controller - flash LED5
	//Init_SPI - turn on LED1
	//MSG0 - flash LED2
	//MSG1 - flash LED3
	//MSG2 - stub
	//DisplayLAB3Temp - flash LED4

	//ID_TMP03_SW4 =  uTTCOSg_AddThread(TMP03_SW4, NO_DELAY, EVERY_TICK);
	//ID_Start_Timer3 = uTTCOSg_AddThread(Start_Timer3, NO_DELAY, RUN_ONCE);
	//ID_Poll_Timer3 = uTTCOSg_AddThread(Poll_Timer3, ONE_SECOND, ONE_SECOND / 4);

	//ID_initResetLCDREB = uTTCOSg_AddThread(initResetLCDREB, NO_DELAY, ONE_SECOND * 5);

#endif

#if 0 //Lab 4B

	//FlashLED6 - NO_DELAY - EVERY_SECOND
		//MOCK_SPI_CONTROLLER - NO_DELAY - EVERY 1/20S
		//INIT_SPI - 1S DELAY - RUN_ONCE
		//MSGO - 3S DELAY + 0/2S - EVERY_2S
		//MSG1 - 3S DELAY + 1/2S - EVERY_2S
		//MSG2 - 3S DELAY + 2/2S - EVERY_2_SECS
		//DISPLAYLAB3TEMPERATURE - 2S DELAY + 3/2S, EVERY_15S

#endif

#if 0 //Lab 4C

	//FlashLED6 - NO_DELAY - EVERY_SECOND
		//MOCK_SPI_CONTROLLER - NO_DELAY - EVERY 1/20S
		//INIT_SPI - 1S DELAY - RUN_ONCE
		//MSGO - 3S DELAY + 0/2S - EVERY_2S
		//MSG1 - 3S DELAY + 1/2S - EVERY_2S
		//MSG2 - 3S DELAY + 2/2S - EVERY_2_SECS
		//DISPLAYLAB3TEMPERATURE - 2S DELAY + 3/2S, EVERY_15S

#endif

#if 1 //Lab 4D

	//FlashLED6 - NO_DELAY - EVERY_SECOND
		//MOCK_SPI_CONTROLLER - NO_DELAY - EVERY 1/20S
		//INIT_SPI - 1S DELAY - RUN_ONCE
		//MSGO - 3S DELAY + 0/2S - EVERY_2S
		//MSG1 - 3S DELAY + 1/2S - EVERY_2S
		//MSG2 - 3S DELAY + 2/2S - EVERY_2_SECS
		//DISPLAYLAB3TEMPERATURE - 2S DELAY + 3/2S, EVERY_15S

	ID_DisplayMessage0_SPI = uTTCOSg_AddThread(Display_511_RULS, ONE_SECOND, 5 * ONE_SECOND);
	ID_DisplayMessage1_SPI = uTTCOSg_AddThread(Display_Initials, 2 * ONE_SECOND, 5 * ONE_SECOND);
	ID_DisplayMessage2_SPI = uTTCOSg_AddThread(Display_Thanks, 3 * ONE_SECOND, 5 * ONE_SECOND);
	ID_SetGlobalTemp = uTTCOSg_AddThread(SetGlobalTempZero, 3 * ONE_SECOND, 5 * ONE_SECOND);
	ID_CalcTemp = uTTCOSg_AddThread(CalculateTemperatureVoid, 4 * ONE_SECOND, 5 * ONE_SECOND);
	ID_DisplayTemperature_SPI = uTTCOSg_AddThread(Display_Temp, 5 * ONE_SECOND, 5 * ONE_SECOND);



#endif

}


/////////////////////////////////////////LAB 3 FUNCTIONS//////////////////////////////////////////////////////
//TODO NEED TO INCLUDE THE .H FILE FOR THESE
//use uTTCOS to measure TMP03
//display temp in LED if SW4 pressed




////////////////////////////////////////LAB 4 FUNCTIONS////////////////////////////////////////////////////////

void SPI_controller(void){
	#if 1 //4A
	//write this as a 1s thread that deletes on the second go
		FlashLED5(); //turn on
		FlashLED5(); //turn off

		if(commandStringToSend == false)
			return;
		if(commandStringBeingSent == true)
			return;

		commandStringBeingSent = true;
		commandsToSend = strlen(SPI_MessageBuffer);
		commandsSent = 0;

		ID_SendSPICommandString = uTTCOSg_AddThread(SendSPICommandString, NO_DELAY, 0.05 * ONE_SECOND);

	#endif

	#if 0 //4B,C,D

	#endif
}





//KYLES FUNCTIONS FOR WRITING SPI TO LCD SCREEN

//extern volatile char ID_initResetLCDREB = 0;
//void initResetLCDREB(void){
//	unsigned long int writeSPIValue = 0x000;
//	while(!REB_SPI_Ready);
//	Write_Value_To_SPI(writeSPIValue);
//	writeSPIValue = 0x0030;
//	while(!REB_SPI_Ready);
//	Write_Value_To_SPI(writeSPIValue);
//	writeSPIValue = 0x0030;
//	while(!REB_SPI_Ready);
//	Write_Value_To_SPI(writeSPIValue);
//	writeSPIValue = 0x003c;
//	while(!REB_SPI_Ready);
//	Write_Value_To_SPI(writeSPIValue);
//	writeSPIValue = 0x000F;
//	while(!REB_SPI_Ready);
//	Write_Value_To_SPI(writeSPIValue);
//	writeSPIValue = 0x0001;
//	while(!REB_SPI_Ready);
//	Write_Value_To_SPI(writeSPIValue);
//	while(!REB_SPI_Ready);
//	uTTCOSg_DeleteThread(ID_initResetLCDREB); //this thread will run once then kill itself
//}
//
//void Display_511_RULS(void){
//	int i = 0;
//	unsigned long int outputArray[ARRAY_511SIZE] = {0x20,0x20,0x35,0x31,0x31,0x20,0x20,0x52,0x55,0x4C,0x53,0x20};
//
//	while(i<ARRAY_511SIZE){
//		while(!REB_SPI_Ready);
//		Write_Value_To_SPI(outputArray[i] | BIT_10);
//
//		i++;
//	}
//}
//
//void Display_Initials(void){
//int i = 0;
//unsigned long int initialsArray[INITAL_ARRAY_SIZE] = {0x20,0x20,0x43,0x4f,0x20,0x20,0x4b,0x46,0x20,0x20};
//
//while(i<INITAL_ARRAY_SIZE){
//while(!REB_SPI_Ready);
//Write_Value_To_SPI(initialsArray[i] | BIT_10);
//while(!REB_SPI_Ready);
//i++;
//}
//while(!REB_SPI_Ready);
//
//}
//
//
//
//void Write_Value_To_SPI(unsigned long int writeValue){
//
//	while(!REB_SPI_Ready);
//	REB_Write_SPI(writeValue&(~BIT_8)); //send 0 in bit 8
//	while(!REB_SPI_Ready);
//	REB_Write_SPI(writeValue|BIT_8); //send 1 in bit 8
//
//}








void Init_SPI_609(void){
	Init_REB_SPI();
	SetBoardLED_SPI_ConfigSoftSwitches();
	while(!REB_SPI_Ready());
	Start_REB_SPI();
//	unsigned long int display = 0;
//	while(1){
//		REB_Write_SPI(display);
//		display++;
//	}
}

//void Init_Reset_LCD_Display(void){
//	static int index = 0;
//
//	REB_Write_SPI(initResetLEDForMessageArray[index]);
//
//	if(index < initResetLEDForMessageArrayLength){
//		index++;
//		printf("\nsending\n");
//	}
//	else{
//		printf("\ndone\n");
//		index = 0;
//		uTTCOSg_DeleteThread(ID_Init_Reset_Display);
//	}
//}

void WriteMessageToLCDDisplay(unsigned short int message[]){

}













unsigned char ID_SendSPICommandString = 0;
void SendSPICommandString(void){
#if (MOCK_LEVEL == 1)
	if(commandStringIsInstruction)
		printf("INSTR: %s\n", SPI_MessageBuffer);
	else
		printf("DATA: %s\n", SPI_MessageBuffer);

	commandStringBeingSent = false;
	commandStringToSend = false;
	commandsToSend = 0;

	uTTCOSg_DeleteThread(ID_SendSPICommandString);
#endif

#if (MOCK_LEVEL == 2)
	if(commandsToSend == 0)
		return;
	if(MOCK_IS_SPI_READY() == false)
		return;

	MOCK_SPI_Send(commandStringIsInstruction, (unsigned int) '\n');
	commandsSent = 0;
	SPI_MessageBuffer[commandsSent++]; //THIS IS WHAT HE HAD WRITTEN IN THE SLIDE - WHAT IS THIS SUPPOSED TO DO?
	commandStringBeingSent = false;
	commandStringToSend = false;

	uTTCOSg_DeleteThread(ID_SendSPICommandString);
#endif
}

bool MOCK_IS_SPI_Ready(void){
	int value = rand() % 5;
	if(value == 1)
		return true;
	else
		return false;
}

void MOCK_SPI_Send(bool commandStringIsInstruction, unsigned int commandToSend){
	if(newMessage){
		newMessage = false;
		if(commandStringIsInstruction)
			printf("INSTR:");
		else
			printf("DATA:");
	}

	printf("%c", (char) commandToSend);
	if(commandToSend == (unsigned int) '\n')
		newMessage = true;
}


void Init_SPI(void){
	#if 1 //4A
		TurnOnLED1();
	#endif

	#if 0 //4B,C,D

	#endif
}

void MSG0(void){
	#if 1 //4A
		FlashLED2(); //turn on
		FlashLED2(); //turn off
	#endif

	#if 1 //4 2A
		if(commandStringBeingSent == true)
			return;
		if(commandStringToSend == true)
			return;

		commandStringToSend = 1; //uTTCOSg guarentees NO DATA RACE
		commandStringIsInstruction = false;

		strcpy(SPI_MessageBuffer, "This is Message 0");
	#endif
}

void MSG1(void){
	#if 1 //4A
	//write this as a 1s thread that deletes on the second go
		FlashLED3(); //turn on
		FlashLED3(); //turn off
	#endif

	#if 1 //4 2A
		if(commandStringBeingSent == true)
			return;
		if(commandStringToSend == true)
			return;

		commandStringToSend = 1; //uTTCOSg guarentees NO DATA RACE
		commandStringIsInstruction = false;

		strcpy(SPI_MessageBuffer, "This is Message 1");
	#endif
}

void MSG2(void){
	#if 1 //4A
		//stub
		printf("\nStub For MSG2\n");
	#endif

	#if 1 //4 2A
		if(commandStringBeingSent == true)
			return;
		if(commandStringToSend == true)
			return;

		commandStringToSend = 1; //uTTCOSg guarentees NO DATA RACE
		commandStringIsInstruction = false;

		strcpy(SPI_MessageBuffer, "This is Message 2");
	#endif
}

void DisplayLAB3Temp(void){
	#if 1 //4A
	//write this as a 1s thread that deletes on the second go
		FlashLED4(); //turn on
		FlashLED4(); //turn off
	#endif

	#if 1 //4 2B
		if(commandStringBeingSent == true)
			return;
		if(commandStringToSend == true)
			return;

		commandStringToSend = 1;
		commandStringIsInstruction = false;
		float currentTemp = GetTemperature_TMP03();
		sprintf(SPI_MessageBuffer, "Current temperature is %5.2f", currentTemp);
	#endif
}


void FlashLED5(void){
	//flash LED5
			unsigned short int FPLEDCurrent = Read_GPIO_FrontPanelLEDS();
			unsigned short int LED5 = FPLEDCurrent & 0x10;
			unsigned short int LED5State = LED5 >> 4;

			unsigned short int NewFPLEDValue;
			if(LED5State == 0){
				NewFPLEDValue = FPLEDCurrent | 0x10;
			}
			else{
				NewFPLEDValue = FPLEDCurrent & 0xef;
			}

			Write_GPIO_FrontPanelLEDS(NewFPLEDValue);
}

void TurnOnLED1(void){
	//turn on LED1
			unsigned short int FPLEDCurrent = Read_GPIO_FrontPanelLEDS();
			unsigned short int FPLEDNew = FPLEDCurrent | 0x01;
			Write_GPIO_FrontPanelLEDS(FPLEDNew);
}

void FlashLED2(void){
	unsigned short int FPLEDCurrent = Read_GPIO_FrontPanelLEDS();
			unsigned short int LED2 = FPLEDCurrent & 0x02;
			unsigned short int LED2State = LED2 >> 1;

			unsigned short int NewFPLEDValue;
			if(LED2State == 0){
				NewFPLEDValue = FPLEDCurrent | 0x02;
			}
			else{
				NewFPLEDValue = FPLEDCurrent & 0xfd;
			}

			Write_GPIO_FrontPanelLEDS(NewFPLEDValue);
}

void FlashLED3(void){
	//flash LED3
			unsigned short int FPLEDCurrent = Read_GPIO_FrontPanelLEDS();
			unsigned short int LED3 = FPLEDCurrent & 0x04;
			unsigned short int LED3State = LED3 >> 2;

			unsigned short int NewFPLEDValue;
			if(LED3State == 0){
				NewFPLEDValue = FPLEDCurrent | 0x04;
			}
			else{
				NewFPLEDValue = FPLEDCurrent & 0xfb;
			}

			Write_GPIO_FrontPanelLEDS(NewFPLEDValue);
}

void FlashLED4(void){
	//flash LED4
			unsigned short int FPLEDCurrent = Read_GPIO_FrontPanelLEDS();
			unsigned short int LED4 = FPLEDCurrent & 0x04;
			unsigned short int LED4State = LED4 >> 3;

			unsigned short int NewFPLEDValue;
			if(LED4State == 0){
				NewFPLEDValue = FPLEDCurrent | 0x08;
			}
			else{
				NewFPLEDValue = FPLEDCurrent & 0xf7;
			}

			Write_GPIO_FrontPanelLEDS(NewFPLEDValue);
}


float GetTemperature_TMP03(void){
#if LAB3_MOCKED
	static int mockTempIndex = -1;
	mockTempIndex++;

	if(mockTempIndex >= 10)
		mockTempIndex = 0;

	currentTemp_Lab3 = ChinookTemp[mockTempIndex];
#endif

	return currentTemp_Lab3;
}

void LAB3_temp(void){
	static int mockTempIndex = 0;
	currentTemp = ChinookTemp[mockTempIndex++];

	if(mockTempIndex >= 10)
		mockTempIndex = 0;
}



////////////////////////////////////////Lab 2 Functions/////////////////////////////////////////////////////////
extern volatile char ID_CheckSW2PressedReleasedThread = 0;
void CheckSW2PressedReleasedThread(void){
	static int SW2State = 0;

	unsigned char FPLEDValue = ~Read_GPIO_FrontPanelSwitches();
	unsigned char SW2Value = FPLEDValue & 0x02; //get value of SW2 only
	SW2Value = SW2Value >> 1; //SW2Value will be 1 if SW2 was on and 0 if SW2 was off

	if(SW2Value == 0 && SW2State == 1){ //was previously on and now is off
		//START SHOW LAB 0 THREAD FROM THIS THREAD & THEN STOP THIS THREAD AT THE BEGINNING OF SHOW LAB 0 THREAD
		//AND RESTART IT AT THE END OF SHOW LAB 0 THREAD
		//ID_DisplayLab0Thread = uTTCOSg_AddThread(Task_DisplayLab0Thread, NO_DELAY, RUN_ONCE); //start the ID_DisplayLab0Thread and run only once
		ID_FPThread4 = uTTCOSg_AddThread(TaskFPThread4, NO_DELAY, Lab0RuntimeFraction * ONE_SECOND); //initially runs every 1 second - the LAB_0_RUNTIME_FRACTION will be changed in FPThread5
		ID_StopCheckSW2PressedReleasedThread = uTTCOSg_AddThread(StopCheckSW2PressedAndReleasedThread, NO_DELAY, RUN_ONCE); //stop checking SW2 pressed and released
	}

	SW2State = SW2Value;
	//printf("\n\n%d\n\n", SW2State);
}

extern volatile char ID_StopCheckSW2PressedReleasedThread = 0;
void StopCheckSW2PressedAndReleasedThread(void){
	uTTCOSg_DeleteThread(ID_CheckSW2PressedReleasedThread);
}

extern volatile char ID_CheckSW1PressedReleasedThread = 0;
void CheckSW1PressedReleasedThread(void){
	static int SW1State = 0;
	unsigned char FPLEDValue = ~Read_GPIO_FrontPanelSwitches();
	unsigned char SW1Value = FPLEDValue & 0x01; //get value of SW2 only

	if(SW1Value == 1 && SW1State == 0){ //was previously off and now is on
		//start thread to count time that it is pressed down (using static variable)
		ID_CountSecondsSW1PressedThread = uTTCOSg_AddThread(CountSecondsSW1PressedThread, ONE_SECOND, ONE_SECOND); //delay one second so that it starts counting in one second
	}

	if(SW1Value == 0 && SW1State == 1){ //was previously on and now is off
		uTTCOSg_DeleteThread(ID_CountSecondsSW1PressedThread);
		ID_ChangeFPThread5SpeedThread = uTTCOSg_AddThread(ChangeFPThread5SpeedThread, ONE_SECOND, RUN_ONCE);
	}

	SW1State = SW1Value;
	//printf("\n\n%d\n\n", SW1State);

}

extern volatile char ID_ChangeFPThread5SpeedThread = 0;
void ChangeFPThread5SpeedThread(void){
	uTTCOSg_DeleteThread(ID_FPThread4); //delete thread

	if(numSecondsSW1Held == 1){ //held between 1 and 2 seconds
		printf("\n\nheld 1-2 seconds\n\n");
		Lab0RuntimeFraction = Lab0RuntimeFraction * 0.5;
		ID_FPThread4 = uTTCOSg_AddThread(TaskFPThread4, NO_DELAY, Lab0RuntimeFraction * ONE_SECOND); //restart thread
	}
	else if(numSecondsSW1Held == 3){ //held between 3 and 4 seconds
		printf("\n\nheld 3-4 seconds\n\n");
		Lab0RuntimeFraction = Lab0RuntimeFraction * 2;
		ID_FPThread4 = uTTCOSg_AddThread(TaskFPThread4, NO_DELAY, Lab0RuntimeFraction * ONE_SECOND); //restart thread
	}
	else{
		printf("\n\nheld other seconds\n\n");
	}

	numSecondsSW1Held = 0; //reset num seconds

}

extern volatile char ID_CountSecondsSW1PressedThread = 0;
void CountSecondsSW1PressedThread(void){
	numSecondsSW1Held += 1;
}

extern volatile char ID_CheckSW5PressedReleased = 0;
void CheckSW5PressedReleased(void){
	static int SW5State = 0;
	unsigned char FPLEDValue = ~Read_GPIO_FrontPanelSwitches();
	unsigned char SW5Value = FPLEDValue & 0x10; //get value of SW2 only
	SW5Value = SW5Value >> 4;

	if(SW5Value == 0 && SW5State == 1){ //was previously on and now is off
		//printf("switch 5 pressed\n\n");
		ID_StoreSwitchValuesInArrayThread = uTTCOSg_AddThread(StoreSwitchValuesInArrayThread, NO_DELAY, RUN_ONCE);
	}

	SW5State = SW5Value;
	//printf("\n\n%d\n\n", SW1State);

}

extern volatile char ID_StoreSwitchValuesInArrayThread = 0;
void StoreSwitchValuesInArrayThread(void){
	static int index = 0;

	arrayValues[index] = (My_Read_REB_SW_ASM() & 0x0f00) >> 8;

	//printf("\n\n0x%x\n\n", arrayValues[index]);

	index += 1;

	if(index == 100){
		index = 0; //start rewriting over the array
	}
	else{
		REBArrayLength += 1; //length will increase until == 100
	}
}

extern volatile char ID_CheckSW3PressedReleasedThread = 0;
void CheckSW3PressedReleased(void){
	static int SW3State = 0;
	unsigned char FPLEDValue = ~Read_GPIO_FrontPanelSwitches();
	unsigned char SW3Value = FPLEDValue & 0x04; //get value of SW2 only
	SW3Value = SW3Value >> 2;


	if(SW3Value == 0 && SW3State == 1){ //was previously on and now is off
		if(ID_REBThread1 == 0){
			uTTCOSg_DeleteThread(ID_REBThread3);
			ID_REBThread3 = 0;
			ID_REBThread1 = uTTCOSg_AddThread(TaskREBThread1, NO_DELAY, 0.25 * ONE_SECOND);
		}
		else if(ID_REBThread3 == 0){
			uTTCOSg_DeleteThread(ID_REBThread1);
			ID_REBThread1 = 0;
			ID_REBThread3 = uTTCOSg_AddThread(DisplayREBSwitchValuesThread, NO_DELAY, 0.25 * ONE_SECOND);
		}
	}

	SW3State = SW3Value;
	//printf("\n\n%d\n\n", SW1State);
}

extern volatile char ID_REBThread3 = 0;
void DisplayREBSwitchValuesThread(void){
#define REB_LED_MASK 0x0fff
    //send a volatile message that you display this one
    //if 1 then use REBthread1 if 0 then use REBThread3 to display;
   // static int REB_1_OR_3 = 1;


	//printf("/n/nIN THIS THREAD\n\n");

	static int index = 0;

    unsigned short int previousREBLEDValue = My_Read_REB_SW_ASM();
    //need to pause REBThread1 as it displays on 4-7

    unsigned short int REBLEDValueNew = arrayValues[index];
    //how far do I shift this??
    REBLEDValueNew = (REBLEDValueNew << 12);//led values are now in 12-15;
    //we have all the previous values, have to zero the LED Values from before
//    previousREBLEDValue = previousREBLEDValue & REB_LED_MASK; //switch values 12-15 to zero
//    REBLEDValueNew = previousREBLEDValue | REBLEDValueNew; //keep all other values not in 12-15 constant
    My_Write_REB_LEDS_ASM(REBLEDValueNew);

    index += 1;

    if(index == REBArrayLength){
    	index = 0;
    }

}

