/*
 * TempSensorFunctions.h
 *
 *  Created on: Nov 26, 2019
 *      Author: kfrie
 */

#ifndef TEMPSENSORFUNCTIONS_H_
#define TEMPSENSORFUNCTIONS_H_

#include "/../../ENCM511_SpecificFiles/ENCM511_include/GP_Timer_Library.h"


//TODO we use these
void Init_Timer3(void);
float CalculateTemperature(void);
void CalculateTemperatureVoid(void);
//*********************************************88

void ClearDoneSignal(void);
void TMP03_SW4(void);
float Poll_Timer3(void);
void SetGlobalTempZero(void);

#endif /* TEMPSENSORFUNCTIONS_H_ */
