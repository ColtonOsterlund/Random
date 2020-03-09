/*************************************************************************************
* AUTO-GENERATED COMMENT - DO NOT MODIFY 
* Author: colto
* Date: Thu 2019/11/28 at 05:41:54 PM
* File Type: uTTCOS Task Header File
*************************************************************************************/

#ifndef SPITEST_UTTCOS_CORE0_UTTCOSG2017_H
#define SPITEST_UTTCOS_CORE0_UTTCOSG2017_H

#include <uTTCOSg2017/uTTCOSg.h>
#include <GPIO2017/ADSP_GPIO_interface.h>

#include "/../../ENCM511_SpecificFiles/ENCM511_include/REB_SPI_Library.h"

// extern "C" void BlackfinBF533_uTTCOSg_Audio_Rx_Tx_Task(void); 
extern "C" void SHARC21469_uTTCOSg_Audio_Rx_Tx_Task(void);
extern "C" void ADSP_SC589_uTTCOSg_Audio_Rx_Tx_Task(void);

// TODO -- Once you have demonstrated the idea of uTTCOS working with print statements
// Comment out the following include statement
// DON'T USE PRINT STATEMENT INSIDE uTTCOS as it is a real time system and
// print statements run on the HIGH priority emulator interrupt and disrupt real time operations
#include "faultyLED1_Thread.h"

#include <stdio.h>

void Custom_uTTCOS_OS_Init(unsigned long int);
extern "C" void Idle_WaitForInterrupts_ASM(void);
void uTTCOSg_Start_CoreTimer_Scheduler(unsigned int maxNumberThreads);
void createThread(void);
void Init_Reset_LCD_Display(void);
void createThread(void);


#endif
