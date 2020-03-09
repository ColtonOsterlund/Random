/*
 * TempSensorFunctions.cpp
 *
 *  Created on: Nov 26, 2019
 *      Author: kfrie
 */

#include "TempSensorFunctions.h"
//TODO this should be here and set to 0 in the thread functions.
extern volatile float GLOBAL_TEMP;

void Init_Timer3(void){
	unsigned char whichTimer = 3;
	Init_GP_Timer(whichTimer);
	Start_GP_Timer(whichTimer);
}

extern volatile char ID_SetGlobalTemp = 0;
void SetGlobalTempZero(void){
	GLOBAL_TEMP = 0;
}


//TODO just need this in a thread to calculate temp
float CalculateTemperature(void){//TODO maybe change back to ints
	unsigned char whichTimer = 3;
	unsigned long int T2 = ReadWidth_GP_Timer(whichTimer);
	unsigned long int T1 =  ReadPeriod_GP_Timer(whichTimer) - T2;
	float temp = 235 -(400.0*T1)/T2;
	return temp;
	GLOBAL_TEMP = temp;
}

extern volatile char ID_CalcTemp = 0;
void CalculateTemperatureVoid(void){
	unsigned char whichTimer = 3;
		unsigned long int T2 = ReadWidth_GP_Timer(whichTimer);
		unsigned long int T1 =  ReadPeriod_GP_Timer(whichTimer) - T2;
		float temp = 235 -(400.0*T1)/T2;
		GLOBAL_TEMP = temp;
}






volatile char ID_TMP03_SW4 = 0;
void TMP03_SW4(void){


}

volatile char ID_Poll_Timer3 = 0;
float Poll_Timer3(void){
	unsigned char whichTimer = 3;
	float temp = 0;



	temp = CalculateTemperature();


	return temp;

	//clear poll signal

	//calculate temp and place in global
}
void ClearDoneSignal(void){
//Do we need this??
}

