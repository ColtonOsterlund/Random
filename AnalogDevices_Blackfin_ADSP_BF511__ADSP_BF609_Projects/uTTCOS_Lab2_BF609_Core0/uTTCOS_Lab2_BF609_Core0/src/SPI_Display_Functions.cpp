/*****************************************************************************
 * 609_Test_SPI_Core0.cpp
 *****************************************************************************/

#include "SPI_Display_Functions.h"

#include <sys/platform.h>
#include <sys/adi_core.h>
#include <ccblkfn.h>
#include "adi_initialize.h"
#include <stdio.h>

/** 
 * If you want to use command program arguments, then place them in the following string. 
 */
char __argv_string[] = "";

#define RS_BIT 0x400 //bit 10
#define E_BIT 0x100 //bit 8
#define RW_BIT 0x200 //bit 9
#define ARRAY_511SIZE 12
#define INITAL_ARRAY_SIZE 10

#define WAIT_TIME 9600000 // 1/50 of a second based on 480,000,000 cycles/second


char BUFFER[32];//buffer for the temp  NEED TO CHANGE TEMP TO A FLOAT
volatile float GLOBAL_TEMP = 0;
void Test_SPI_609(void){
	Init_REB_SPI();
	SetBoardLED_SPI_ConfigSoftSwitches();

	Start_REB_SPI();
	unsigned long int display = 0;
	while(1){
		while(!REB_SPI_Ready());//Moved this down here when we changed the speed
		REB_Write_SPI(display);
		SPI_Wait();
		display++;
	}
}



void initResetLCDREB(void){
	unsigned long int writeSPIValue = 0x000;
	while(!REB_SPI_Ready());//FORGOT TO PUT () after function this may be why none of it worked the second time.....
	Write_Value_To_SPI(writeSPIValue);
	SPI_Wait();
	writeSPIValue = 0x030;

	Write_Value_To_SPI(writeSPIValue);
	SPI_Wait();
	writeSPIValue = 0x0030;

	Write_Value_To_SPI(writeSPIValue);
	SPI_Wait();
	writeSPIValue = 0x003c;

	Write_Value_To_SPI(writeSPIValue);
	SPI_Wait();
	writeSPIValue = 0x000F;

	Write_Value_To_SPI(writeSPIValue);
	SPI_Wait();
	writeSPIValue = 0x0001;

	Write_Value_To_SPI(writeSPIValue);
	SPI_Wait();


}

extern volatile char ID_DisplayTemperature_SPI = 0;
void Display_Temp(void){
	int size = 0;
	initResetLCDREB();

	//Global Temp will be set by seperate thread that calculates the temp
	size = Convert_Temp_To_HEX(GLOBAL_TEMP);
	Write_Value_To_SPI(0x20 | RS_BIT);//bit 10
	SPI_Wait();

	Write_Value_To_SPI(0x54 | RS_BIT);
	SPI_Wait();
	Write_Value_To_SPI(0x45 | RS_BIT);
	SPI_Wait();
	Write_Value_To_SPI(0x4D | RS_BIT);
	SPI_Wait();
	Write_Value_To_SPI(0x50 | RS_BIT);
	SPI_Wait();
	Write_Value_To_SPI(0x20 | RS_BIT);
	SPI_Wait();

//	Write_Value_To_SPI(50 | RS_BIT); //GET THE THERMOMETER TO UPDATE GLOBAL TEMP
//	SPI_Wait();
//	Write_Value_To_SPI(53 | RS_BIT); //GET THE THERMOMETER TO UPDATE GLOBAL TEMP
//	SPI_Wait();
	for(int i = 0; i<size;i++){
		Write_Value_To_SPI(BUFFER[i] | RS_BIT);
		SPI_Wait();
	}
	Write_Value_To_SPI(0x20 | RS_BIT);
	SPI_Wait();


	SPI_Wait();

}

extern volatile char ID_DisplayMessage0_SPI = 0;
void Display_511_RULS(void){
	initResetLCDREB();
	int i = 0;
	unsigned long int outputArray[ARRAY_511SIZE] = {0x20,0x20,0x35,0x31,0x31,0x20,0x20,0x52,0x55,0x4C,0x53,0x20};

	while(i<ARRAY_511SIZE){
		while(!REB_SPI_Ready());
		Write_Value_To_SPI(outputArray[i] | RS_BIT); //bit 10
		SPI_Wait();
		i++;
	}
}

extern volatile char ID_DisplayMessage1_SPI = 0;
void Display_Initials(void){
	initResetLCDREB();
	int i = 0;
	unsigned long int initialsArray[INITAL_ARRAY_SIZE] = {0x20,0x20,0x43,0x4f,0x20,0x20,0x4b,0x46,0x20,0x20};

		while(i<INITAL_ARRAY_SIZE){
			while(!REB_SPI_Ready());
			Write_Value_To_SPI(initialsArray[i] | RS_BIT);//bit 10
			SPI_Wait();

			i++;
		}
		while(!REB_SPI_Ready());

}

void Write_Value_To_SPI(unsigned long int writeValue){

	SPI_Wait();
	REB_Write_SPI(writeValue&(~E_BIT)); //send 0 in bit 8

	SPI_Wait();
	REB_Write_SPI(writeValue|E_BIT); //send 1 in bit 8
	SPI_Wait();
}
//waits WAIT_TIME,
void SPI_Wait(void){
	unsigned long long int startTime = ReadProcessorCyclesASM();
	unsigned long long int timeToWait = WAIT_TIME;

	unsigned long long int currentTime = ReadProcessorCyclesASM();

	while(currentTime < (startTime + timeToWait)){

		currentTime = ReadProcessorCyclesASM();
	}
}

extern volatile char ID_DisplayMessage2_SPI = 0;
void Display_Thanks(void){
	initResetLCDREB();
	unsigned long int thanksArray[16] = {0x54,0x48,0x41,0x4E,0x4B,0x53,0x20,0x44,0x52,0x20,0x53,0x4D,0x49,0x54,0x48,0x20};
	int i = 0;
	while(i < 16){
		while(!REB_SPI_Ready()); //Test writing this array to the SPI with the function brackets.
		Write_Value_To_SPI(thanksArray[i] | RS_BIT);

		i++;
	}

}

int Convert_Temp_To_HEX(float temp){

	int ret = snprintf(BUFFER, sizeof BUFFER, "%f", temp);

	if (ret >= sizeof BUFFER){
		printf("buffer too small\n");
	}
	return ret;
}
//TODO we don't need this it was just a test, when we remove "TempSensorFunctions.h" we should remove this.
void Print_Temp_To_SPI(void){
	unsigned char whichTimer = 3;
	//THESE WILL BE DONE IN THE LAB4 MAIN
//	Init_REB_SPI();
//	SetBoardLED_SPI_ConfigSoftSwitches();
//	Start_REB_SPI();
//	Init_Timer3();
	initResetLCDREB();


//		while(1){

			initResetLCDREB();
			GLOBAL_TEMP = Poll_Timer3();
			Display_Temp();

//			for(int i = 0; i < 25;i++){
//				SPI_Wait();
//			}
//		}
}
