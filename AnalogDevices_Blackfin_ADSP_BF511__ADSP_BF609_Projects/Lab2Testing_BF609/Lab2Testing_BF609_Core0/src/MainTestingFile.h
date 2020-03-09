/*************************************************************************************
* AUTO-GENERATED COMMENT - DO NOT MODIFY 
* Author: colto
* Date: Tue 2019/11/12 at 04:59:53 PM
* File Type: EUNIT Test Header File
*************************************************************************************/

#ifndef MAINTESTINGFILE_H
#define MAINTESTINGFILE_H

#include "FPThread1.h"
#include "FPThread2.h"
#include "FPThread3.h"
#include "REBThread1.h"
#include "FPThread5.h"
#include "REBThread2.h"
#include "REBThread3.h"

extern "C" void My_Init_REB_GPIO_ASM(void);
extern "C" void My_Write_REB_SW_ASM(unsigned short int);
extern "C" void My_Write_REB_LEDS_ASM(unsigned short int);
extern "C" unsigned short int My_Read_REB_SW_ASM(void);
void UpdateEunitGui(void);	// Update EUNIT GUI with results from previous test
extern "C" unsigned short int My_Read_REB_LEDS_ASM(void);

#endif
