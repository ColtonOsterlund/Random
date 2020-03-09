/*****************************************************************************
 * 609_Test_SPI_Core0.h
 *****************************************************************************/

#ifndef __609_TEST_SPI_CORE0_H__
#define __609_TEST_SPI_CORE0_H__

/* Add your custom header content here */

#include "/../../ENCM511_SpecificFiles/ENCM511_include/REB_SPI_Library.h"
#include "TempSensorFunctions.h"//TODO we can remove this don't need to calculate temp in here
//Temp is calculated by a different thread.
//TODO 4 threads for these
void Display_Thanks(void);
void Display_511_RULS(void);
void Display_Initials(void);
void Display_Temp(void);
//**************************************
//TODO one more thread to calculate temp and update global value.
void Test_SPI_609(void);
void initResetLCDREB(void);

void Write_Value_To_SPI(unsigned long int writeValue);
void SPI_Wait(void);
int Convert_Temp_To_HEX(float temp);
extern "C" unsigned long long int ReadProcessorCyclesASM(void);

void Print_Temp_To_SPI(void);

#endif /* __609_TEST_SPI_CORE0_H__ */
