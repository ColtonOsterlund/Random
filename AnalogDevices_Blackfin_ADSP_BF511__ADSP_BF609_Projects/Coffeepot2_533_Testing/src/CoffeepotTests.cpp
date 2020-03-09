/*************************************************************************************
*   AUTOMATICALLY GENERATED COMMENT -- DO NOT MODIFY
* Author: colto
* Date: Mon 2019/11/25 at 06:38:06 PM
* File Type: EUNIT Test File
*************************************************************************************/

#define EMBEDDEDUNIT_LITE
#include <EmbeddedUnit2017/EmbeddedUnit2017.h>
//#include "CoffeepotTests_cpp.h"


TEST_CONTROL(CoffeepotTests_cpp);

#if 1
void UpdateEunitGui(void);
TEST(CoffeepotTests_cpp_GUIUpdate) {
	UpdateEunitGui();  // Conditionally compile this line (use #if 0) to stop an GUI update based on last completed test
}
#endif


unsigned short int TestBitwiseAND(unsigned short int bitPattern, unsigned short int bitMask);
unsigned short int TestBitwiseOR(unsigned short int bitPattern, unsigned short int bitMask);
​
​


TEST(TimerFunctions){
	unsigned long int period = PERIOD_TEST;
	Init_CoreTimer(period, period);
	//test start timer
	unsigned long int controlReg = *pTCNTL & ALL_CTL_BITS;
	CHECK(controlReg == PWR_BIT);
	StartCoreTimer();
	controlReg = *pTCNTL & ALL_CTL_BITS;
	CHECK(controlReg == ALL_CTL_BITS);
​
	//test stop coretimer
	StopCoreTimer();
	controlReg = *pTCNTL & ALL_CTL_BITS;
	XF_CHECK(controlReg == ALL_CTL_BITS );
	CHECK(controlReg == PWR_BIT);
	XF_CHECK(controlReg == (PWR_BIT | ENABLE_BIT));
​
	//test enable interrupts
	unsigned long int Imask = *pIMASK;
	Imask = Imask & CORETIMERINTERRUPT;
	XF_CHECK(Imask == CORETIMERINTERRUPT);
	EnableCoreTimerInterrupts();
	Imask = *pIMASK & CORETIMERINTERRUPT;
	CHECK(Imask == CORETIMERINTERRUPT);
​
}
#if 0
extern volatile bool TIMER_FLAG;
TEST(Interrupt){
	EnableCoreTimerInterrupts();
	LinkCTI_ToISR(CoffeePot_ISR);
	unsigned long int period = PERIOD_TEST;
	unsigned long int count = PERIOD_TEST;
	Init_CoreTimer(period, count);
	StartCoreTimer();
	bool check = false;
	int ISRcount = 0;
	while(ISRcount < 20){
		if(TIMER_FLAG == true){
			TIMER_FLAG = false;
			printf("interrupt happened \n");
			ISRcount++;
		}
	}
	CHECK(check == TIMER_FLAG);
	int countCheck = 20;
	CHECK(countCheck == ISRcount);
​
​
}
#endif
​
​
#if 0
TEST(InitCoreTimer)
{
	printf("Test Init\n");
	//tests before init
	unsigned long int period = PERIOD_TEST;
	unsigned long int count = COUNT_TEST;
	unsigned long int zero = 0;
	unsigned long int countRegVal = *pTCOUNT;
	CHECK(countRegVal == zero);
	unsigned long int periodRegVal = *pTPERIOD;
	CHECK(periodRegVal == zero);
	unsigned long int scaleRegVal = *pTSCALE;
	CHECK(scaleRegVal == zero);
	unsigned long int controlRegVal = *pTCNTL;
	controlRegVal = controlRegVal & CNTRL_BIT_MASK;
	CHECK(controlRegVal == zero);
​
	Init_CoreTimer(period, count);
	unsigned long int pwr = PWR_BIT;
	unsigned long int enable = ENABLE_BIT;
	unsigned long int autoEnable = AUTO_BIT;
	unsigned long int done = DONE_BIT;
	controlRegVal = *pTCNTL;
	CHECK(controlRegVal == pwr);// power bit should be on
	XF_CHECK(controlRegVal == (pwr | enable)); // The enable bit should be off
	XF_CHECK(controlRegVal == (pwr | autoEnable));//the autoEnable should be off
	CHECK((controlRegVal & done) == zero); //the done bit should be off
​
	countRegVal = *pTCOUNT;
	CHECK(countRegVal == count);
​
	periodRegVal = *pTPERIOD;
	CHECK(periodRegVal == period);
​
	scaleRegVal = *pTSCALE;
	scaleRegVal = scaleRegVal & SCALE_BIT_MASK;
	CHECK(scaleRegVal == zero);
​
​
}
#endif
#if 0
TEST(TimerPoll){
	printf("Test TimerPoll\n");
	unsigned long int pwr = PWR_BIT;
		unsigned long int enable = ENABLE_BIT;
		unsigned long int autoEnable = AUTO_BIT;
		unsigned long int done = DONE_BIT;
		unsigned long int period = BF_533_PERIOD;
		unsigned long int count = period;
		Init_CoreTimer(period, count);
		//enable the bits
		unsigned long int countRegVal = *pTCOUNT;
		unsigned long int periodRegVal = *pTPERIOD;
		unsigned long int controlRegVal = *pTCNTL;
		*pTCNTL = (controlRegVal | ENABLE_BIT | AUTO_BIT);
		unsigned long long int elapsedTimes[5];
		unsigned long long int expectedTimes[5] = {40000,40000,40000,40000,40000};
		unsigned long long int startCyclesTime[5];
		unsigned long long int endCyclesTime[5];
		unsigned long long int elapsedTime = 0;
		bool finished = false;
		for(int i =0; i< 5;i++){
			printf("loop number: %d\n", i);
			controlRegVal = *pTCNTL;
			*pTCNTL = (controlRegVal & ~DONE_BIT);
			countRegVal = *pTCOUNT;
			startCyclesTime[i] = ReadProcessorCyclesASM();
			while(!finished){
				finished = Completed_CoreTimer();
			}
			endCyclesTime[i] = ReadProcessorCyclesASM();
			elapsedTime = endCyclesTime[i] - startCyclesTime[i];
			elapsedTimes[i] = elapsedTime;
			printf("elapsed Time:  %d\n", elapsedTime);
			finished = false;
​
		}
		unsigned long long int tolerance = BF_533_PERIOD * VARIANCE;
​
		//CHECK_ARRAY_CLOSE(expectedTimes,elapsedTimes,5,tolerance*10);
		for(int i = 1; i < 5; i++){
				CHECK_CLOSE(elapsedTimes[i-1], elapsedTimes[i],tolerance);
			}
}
#endif
​
#if 0
TEST(TimerCylcesTimer){
	printf("Test TimerCylcesTimer\n");
	unsigned long int pwr = PWR_BIT;
	unsigned long int enable = ENABLE_BIT;
	unsigned long int autoEnable = AUTO_BIT;
	unsigned long int done = DONE_BIT;
	unsigned long int period = BF_533_PERIOD;
	unsigned long int count = period;
	Init_CoreTimer(period, count);
	//enable the bits
	unsigned long int periodRegVal = *pTPERIOD;
	unsigned long int controlRegVal = *pTCNTL;
	*pTCNTL = (controlRegVal | ENABLE_BIT | AUTO_BIT);
	unsigned long long int elapsedTimes[5];
	//unsigned long long int expectedTimes[5] = {40000,40000,40000,40000,40000};
	unsigned long long int startCyclesTime[5];
	unsigned long long int endCyclesTime[5];
	unsigned long long int elapsedTime = 0;
	for(int i =0; i< 5;i++){
		printf("loop number: %d\n", i);
		startCyclesTime[i] = ReadProcessorCyclesASM();
		TimedWaitOnCoreTimer();
		endCyclesTime[i] = ReadProcessorCyclesASM();
		elapsedTime = endCyclesTime[i] - startCyclesTime[i];
		elapsedTimes[i] = elapsedTime;
		printf("elapsed Time:  %d\n", elapsedTime);
	}
	unsigned long long int tolerance = BF_533_PERIOD * VARIANCE;
​
	//CHECK_ARRAY_CLOSE(expectedTimes,elapsedTimes,5,tolerance);
	//TODO re test this to make sure values are different
	for(int i = 1; i < 5; i++){
		CHECK_CLOSE(elapsedTimes[i-1], elapsedTimes[i],tolerance);
	}
​
​
​
}
#endif
​
​
​
#if 0
TEST(AutoEnable){
	printf("Test AutoEnable\n");
	unsigned long int period = PERIOD_TEST;
	unsigned long int count = COUNT_TEST;
	unsigned long int zero = 0;
	unsigned long int pwr = PWR_BIT;
	unsigned long int enable = ENABLE_BIT;
	unsigned long int autoEnable = AUTO_BIT;
	unsigned long int done = DONE_BIT;
​
	Init_CoreTimer(period, count);
	unsigned long int countRegVal = *pTCOUNT;
	unsigned long int periodRegVal = *pTPERIOD;
	unsigned long int controlRegVal = *pTCNTL;
	*pTCNTL = (controlRegVal | ENABLE_BIT);
	//run to zero without auto enable
	unsigned long int counter = 0;
	XF_CHECK(countRegVal == zero);
​
	while(countRegVal != 0){
​
		countRegVal = *pTCOUNT;
		counter ++;
	}
	//printf("The counter is %d \n", counter);
	CHECK(countRegVal == zero);
	controlRegVal = *pTCNTL;
	controlRegVal = controlRegVal & CNTRL_BIT_MASK;
	//controlRegVal = controlRegVal & DONE_BIT;
	CHECK(controlRegVal == (pwr | enable |  done));
	XF_CHECK(controlRegVal == (pwr | enable | autoEnable | done));
​
	//now clear done bit
	controlRegVal = *pTCNTL;
	*pTCNTL = controlRegVal & CLEAR_DONE;
	//check that done == 0
	controlRegVal = *pTCNTL;
	controlRegVal = controlRegVal & CNTRL_BIT_MASK;
	controlRegVal = controlRegVal & DONE_BIT;
	unsigned long int doneBit = controlRegVal;
	CHECK(doneBit == zero);
	//check that count == 0
	countRegVal = *pTCOUNT;
	CHECK(countRegVal == zero);
	for(int i =0; i < 1000; i++){
		//wait a bit
	}
	//check that count == 0;
	countRegVal = *pTCOUNT;
	CHECK(countRegVal == zero);
​
	//now turn on auto enable
	controlRegVal = *pTCNTL;
	controlRegVal = controlRegVal | AUTO_BIT;
	*pTCNTL = controlRegVal;
	//check values
	countRegVal = *pTCOUNT;
	XF_CHECK(countRegVal == zero);
	XF_CHECK(countRegVal == count);
	//printf("The countRegVal is %d \n", countRegVal);
​
​
}
#endif
​
​
#if 0
TEST(DoneCoreTimer){
​
	printf("Test DoneCoreTimer\n");
	//don't reset the count
	unsigned long int period = PERIOD_TEST;
	unsigned long int count = COUNT_TEST;
	unsigned long int zero = 0;
	unsigned long int pwr = PWR_BIT;
	unsigned long int enable = ENABLE_BIT;
	unsigned long int autoEnable = AUTO_BIT;
	unsigned long int done = DONE_BIT;
​
	Init_CoreTimer(period, count);
	unsigned long int countRegVal = *pTCOUNT;
	unsigned long int periodRegVal = *pTPERIOD;
	unsigned long int controlRegVal = *pTCNTL;
	*pTCNTL = (controlRegVal | ENABLE_BIT);
	controlRegVal = *pTCNTL;
	controlRegVal = controlRegVal & CNTRL_BIT_MASK;//just get the last 4 bits
	//check to see if the timer is enabled
	CHECK(controlRegVal == (pwr | enable));
	//test to see if done bit is 0
	XF_CHECK(controlRegVal == (pwr | enable | done));
	unsigned long int counter = 0;
	XF_CHECK(countRegVal == zero);
​
	while(countRegVal != 0){
​
		countRegVal = *pTCOUNT;
		counter ++;
	}
​
	CHECK(countRegVal == zero);
	controlRegVal = *pTCNTL;
	controlRegVal = controlRegVal & CNTRL_BIT_MASK;
	//test to see if done bit is 1
	CHECK(controlRegVal == (pwr | enable | done));
	//clear done bit
	controlRegVal = controlRegVal & (~DONE_BIT);
	*pTCNTL = controlRegVal;
​
	for(int i = 0; i < 100; i++){
		//wait
	}
	countRegVal = *pTCOUNT;
	CHECK(countRegVal == zero);
	//printf("The counter is %d \n", counter);
}
#endif
​
​
​
#if 1
TEST(StartCoreTimer){
	printf("Test StartCoreTimer\n");
	unsigned long int period = BF_533_PERIOD;
	unsigned long int count = BF_533_CYCLES;
	unsigned long int zero = 0;
	unsigned long int pwr = PWR_BIT;
	unsigned long int enable = ENABLE_BIT;
	unsigned long int autoEnable = AUTO_BIT;
	unsigned long int done = DONE_BIT;
​
	Init_CoreTimer(period, count);
	unsigned long int countRegVal = *pTCOUNT;
	unsigned long int periodRegVal = *pTPERIOD;
	unsigned long int controlRegVal = *pTCNTL;
	//make sure period and count are different after init
	XF_CHECK(countRegVal == periodRegVal);
	//enable core timer
	*pTCNTL = (controlRegVal | ENABLE_BIT);
	controlRegVal = *pTCNTL;
	unsigned long int controlRegTest = controlRegVal & ALL_CTL_BITS;
	CHECK(controlRegTest == (pwr | enable));
	unsigned long int countRegVal2 = *pTCOUNT;
	XF_CHECK(countRegVal2 == zero);
	printf("The count is at %d\n", countRegVal2);
	//after the timer has started
	for(int i = 0; i < 100; i++){
		//do something to see if counter changes
	}
	countRegVal2 = *pTCOUNT;
	printf("The count is at %d\n", countRegVal2);
	unsigned long int periodRegVal2 = *pTPERIOD;
​
​
	XF_CHECK(countRegVal2 == countRegVal);//value of count after init
	XF_CHECK(countRegVal2 == count);
	XF_CHECK(countRegVal2 == periodRegVal);
	CHECK(periodRegVal2 == period); //period should not change
	countRegVal2 = *pTCOUNT;
	XF_CHECK(countRegVal2 == countRegVal);
	//printf("The count is at %d\n", countRegVal2);
​
}
#endif




TEST_FILE_RUN_NOTIFICATION(CoffeepotTests_cpp);



