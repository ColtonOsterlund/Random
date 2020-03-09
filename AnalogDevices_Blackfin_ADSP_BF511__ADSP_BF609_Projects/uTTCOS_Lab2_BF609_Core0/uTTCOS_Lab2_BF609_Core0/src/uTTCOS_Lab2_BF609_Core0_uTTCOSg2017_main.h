/*************************************************************************************
* AUTO-GENERATED COMMENT - DO NOT MODIFY 
* Author: kfrie
* Date: Tue 2019/10/29 at 02:16:57 PM
* File Type: uTTCOS Task Header File
*************************************************************************************/

#ifndef UTTCOS_LAB2_BF609_CORE0_UTTCOSG2017_H
#define UTTCOS_LAB2_BF609_CORE0_UTTCOSG2017_H

#include <uTTCOSg2017/uTTCOSg.h>
#include <GPIO2017/ADSP_GPIO_interface.h>
// extern "C" void BlackfinBF533_uTTCOSg_Audio_Rx_Tx_Task(void); 
extern "C" void SHARC21469_uTTCOSg_Audio_Rx_Tx_Task(void);
extern "C" void ADSP_SC589_uTTCOSg_Audio_Rx_Tx_Task(void);

#include "../../../ENCM511_SpecificFiles/ENCM511_include/FrontPanel_LED_Switches.h"
#include "/../../ENCM511_SpecificFiles/ENCM511_include/REB_SPI_Library.h"

// TODO -- Once you have demonstrated the idea of uTTCOS working with print statements
// Comment out the following include statement
// DON'T USE PRINT STATEMENT INSIDE uTTCOS as it is a real time system and
// print statements run on the HIGH priority emulator interrupt and disrupt real time operations
#include "faultyLED1_Thread.h" // where prototypes are stored
#include "FPThread1.h"
#include "FPThread2.h"
#include "FPThread3.h"
#include "FPThread4.h"
#include "FPThread5.h"

#include "REBThread1.h"
#include "REBThread2.h"
#include "REBThread3.h"

#include "TempSensorFunctions.h"
#include "SPI_Display_Functions.h"


#include <stdio.h>
#include <string.h>

void createThreads(void);

//Lab 2
void Custom_uTTCOS_OS_Init(unsigned long int);
extern "C" void Idle_WaitForInterrupts_ASM(void);
extern "C" void My_Init_REB_GPIO_ASM(void);
void uTTCOSg_Start_CoreTimer_Scheduler(unsigned int maxNumberThreads);
void CheckSW2PressedReleasedThread(void);
void StopCheckSW2PressedAndReleasedThread(void);
void CheckSW1PressedReleasedThread(void);
void CountSecondsSW1PressedThread(void);
void ChangeFPThread5SpeedThread(void);
void CheckSW5PressedReleased(void);
void StoreSwitchValuesInArrayThread(void);
void CheckSW3PressedReleased(void);
void DisplayREBSwitchValuesThread(void);

//Lab 4
void SPI_controller(void);
void Init_SPI(void);
void MSG0(void);
void MSG1(void);
void MSG2(void);
void DisplayLAB3Temp(void);
void FlashLED5(void);
void TurnOnLED1(void);
void FlashLED2(void);
void FlashLED3(void);
void FlashLED4(void);
float GetTemperature_TMP03(void);
void LAB3_temp(void);
void SendSPICommandString(void);
bool MOCK_IS_SPI_Ready(void);
void MOCK_SPI_Send(bool commandStringIsInstruction, unsigned int commandToSend);
void Test_SPI_609(void);
//void initResetLCDREB(void);
void WriteMessageToLCDDisplay(unsigned short int message[]);
//void Display_511_RULS(void);
//void Write_Value_To_SPI(unsigned long int writeValue);
//void Display_Initials(void);




#endif
