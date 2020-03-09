/*************************************************************************************
*   AUTOMATICALLY GENERATED COMMENT -- DO NOT MODIFY
* Author: colto
* Date: Tue 2019/11/12 at 04:59:53 PM
* File Type: EUNIT Test File
*************************************************************************************/

#define EMBEDDEDUNIT_LITE
#include <EmbeddedUnit2017/EmbeddedUnit2017.h>
#include "MainTestingFile.h"


TEST_CONTROL(MainTestingFile_cpp);

#if 1
void UpdateEunitGui(void);
TEST(MainTestingFile_cpp_GUIUpdate) {
	UpdateEunitGui();  // Conditionally compile this line (use #if 0) to stop an GUI update based on last completed test
}
#endif


unsigned short int TestBitwiseAND(unsigned short int bitPattern, unsigned short int bitMask);
unsigned short int TestBitwiseOR(unsigned short int bitPattern, unsigned short int bitMask);

#if 0
TEST(FPThread1Test_MoreComplexTest)
{ 
	#warning 'Dummy test has been inserted -- replace with your own -- Tue 2019/11/12 at 04:59:53 PM '
	// TODO -- 'Dummy test has been inserted  -- replace with your own -- Tue 2019/11/12 at 04:59:53 PM '
	printf("Dummy test has been inserted -- replace with your own -- Tue 2019/11/12 at 04:59:53 PM \n");
	
	unsigned long int value  			= 0x01FF01FF;
	unsigned long int ORmask 			= 0x0F000F0F;
	unsigned long int expectedORResult 	= 0x0100010F;
	unsigned long int resultOR  = TestBitwiseOR(value, ORmask);
	CHECK(expectedORResult == resultOR);
	CHECK_EQUAL(expectedORResult, resultOR);
	
	#error("You insert the 'wrong' test for TestBitwiseAND";
}

unsigned short int TestBitwiseAND(unsigned short int bitPattern, unsigned short int bitMask) {
	return bitPattern && bitMask;
}

unsigned short int TestBitwiseOR(unsigned short int bitPattern, unsigned short int bitMask) {
	return bitPattern || bitMask;
}

TEST(FPThread1Test_Successes)
{ 
	#warning 'Dummy test has been inserted -- replace with your own -- Tue 2019/11/12 at 04:59:53 PM '
	// TODO -- 'Dummy test has been inserted  -- replace with your own -- Tue 2019/11/12 at 04:59:53 PM '
	printf("Dummy test has been inserted -- replace with your own -- Tue 2019/11/12 at 04:59:53 PM \n");
	
	CHECK(false == false);
	CHECK_EQUAL(false, false);
	
	XF_CHECK(false == true);    // Expected failure occurs
	XF_CHECK_EQUAL(false, true); // Expected failure occurs
	XF_CHECK(false == false);    // Expected failure does not occur
	XF_CHECK_EQUAL(false, false); // Expected failure does not occur
	
	#error("You insert the 'wrong' test for TestBitwiseAND";
}

#endif

TEST(FPThread1Test)
{

	//XF_CHECK INITIALIZATION
	unsigned short int CurrentLEDValue = Read_GPIO_FrontPanelLEDS();
	unsigned short int newLEDValue = CurrentLEDValue & 0x7f; //turn off LED 8
	Write_GPIO_FrontPanelLEDS(newLEDValue); //turn off LED 8

	Task_FPThread1();

	unsigned short int expectedValue = newLEDValue | 0x80;
	unsigned short int actualValue = Read_GPIO_FrontPanelLEDS();
	XF_CHECK(expectedValue == actualValue);


	//CHECK TURNING ON
	Init_GPIO_FrontPanelLEDS();
	CurrentLEDValue = Read_GPIO_FrontPanelLEDS();
	newLEDValue = CurrentLEDValue & 0x7f; //turn off LED 8
	Write_GPIO_FrontPanelLEDS(newLEDValue); //turn off LED 8

	Task_FPThread1();

	expectedValue = newLEDValue | 0x80;
	actualValue = Read_GPIO_FrontPanelLEDS();
	CHECK(expectedValue == actualValue);

	//CHECK TURNING OFF
	CurrentLEDValue = Read_GPIO_FrontPanelLEDS();
	newLEDValue = CurrentLEDValue | 0x80; //turn on LED 8
	Write_GPIO_FrontPanelLEDS(newLEDValue); //turn on LED 8

	Task_FPThread1();

	expectedValue = newLEDValue & 0x7f;
	actualValue = Read_GPIO_FrontPanelLEDS();
	CHECK(expectedValue == actualValue);


	//XF_CHECK TURNING ON
	Init_GPIO_FrontPanelLEDS();
	CurrentLEDValue = Read_GPIO_FrontPanelLEDS();
	newLEDValue = CurrentLEDValue & 0x7f; //turn off LED 8
	Write_GPIO_FrontPanelLEDS(newLEDValue); //turn off LED 8

	Task_FPThread1();

	expectedValue = newLEDValue | 0x80;
	actualValue = Read_GPIO_FrontPanelLEDS();
	CHECK(expectedValue == actualValue);

	//XF_CHECK TURNING OFF
	Init_GPIO_FrontPanelLEDS();
	CurrentLEDValue = Read_GPIO_FrontPanelLEDS();
	newLEDValue = CurrentLEDValue | 0x80; //turn on LED 8
	Write_GPIO_FrontPanelLEDS(newLEDValue); //turn on LED 8

	Task_FPThread1();

	expectedValue = CurrentLEDValue & 0x7f;
	actualValue = Read_GPIO_FrontPanelLEDS();
	CHECK(expectedValue == actualValue);

}

TEST(FPThread2Test){
#if 0	//not working - figure out later

	//XF_CHECK ON (first 1/3 s) PRE INIT ** THIS WILL SUCCEED IF FPThread1Test IS RUN BEFORE THIS AS IT WILL INITIALIZE THE LEDs IN THAT TEST **
	unsigned short int CurrentLEDValue = Read_GPIO_FrontPanelLEDS();
	unsigned short int newLEDValue = CurrentLEDValue & 0xbf; //turn off LED 7
	Write_GPIO_FrontPanelLEDS(newLEDValue); //turn off LED 7

	TaskFPThread2();

	unsigned short int expectedValue = newLEDValue | 0x40;
	unsigned short int actualValue = Read_GPIO_FrontPanelLEDS();
	XF_CHECK(expectedValue == actualValue);

	//XF_CHECK ON (second 1/3 s) PRE INIT
	TaskFPThread2();

	expectedValue = newLEDValue | 0x40;
	actualValue = Read_GPIO_FrontPanelLEDS();
	XF_CHECK(expectedValue == actualValue);


	//XF_CHECK OFF (third 1/3 s) PRE INIT
	TaskFPThread2();

	expectedValue = newLEDValue; //LED 7 should turn back off
	actualValue = Read_GPIO_FrontPanelLEDS();
	XF_CHECK(expectedValue == actualValue);

#endif

#if 1	//CHECK ON (first 1/3 s)
	Init_GPIO_FrontPanelLEDS();
	unsigned short int CurrentLEDValue = Read_GPIO_FrontPanelLEDS();
	unsigned short int newLEDValue = CurrentLEDValue & 0xbf; //turn off LED 7
	Write_GPIO_FrontPanelLEDS(newLEDValue); //turn off LED 7

	TaskFPThread2();

	unsigned short int expectedValue = newLEDValue | 0x40;
	unsigned short int actualValue = Read_GPIO_FrontPanelLEDS();
	CHECK(expectedValue == actualValue);

	//CHECK ON (second 1/3 s)
	TaskFPThread2();

	expectedValue = newLEDValue | 0x40;
	actualValue = Read_GPIO_FrontPanelLEDS();
	CHECK(expectedValue == actualValue);


	//CHECK OFF (third 1/3 s)
	TaskFPThread2();

	expectedValue = newLEDValue; //LED 7 should turn back off
	actualValue = Read_GPIO_FrontPanelLEDS();
	CHECK(expectedValue == actualValue);
#endif
}

TEST(FPThread3Test){
	//CHECK POST INIT
	Init_GPIO_FrontPanelLEDS();
	TaskFPThread3();

	unsigned short int currentLEDVal = Read_GPIO_FrontPanelLEDS() & 0x03;

	TaskFPThread3();

	unsigned short int expectedVal;
	if(currentLEDVal == 0x03){
		expectedVal = 0x00;
	}
	else{
		expectedVal = currentLEDVal + 1;
	}
	unsigned short int actualVal = Read_GPIO_FrontPanelLEDS();

	CHECK(actualVal == expectedVal);
}

TEST(FPThread5Test){
	setNumSecondsSW1Held(1);
	float currentLab0RuntimeFraction = getLab0RuntimeFraction();
	ChangeFPThread5SpeedThread();

	printf("\n\n%f -- %f\n\n", currentLab0RuntimeFraction, getLab0RuntimeFraction());

	CHECK(getLab0RuntimeFraction() < currentLab0RuntimeFraction);

	numSecondsSW1Held = 3;
	currentLab0RuntimeFraction = getLab0RuntimeFraction();
	ChangeFPThread5SpeedThread();

	XF_CHECK(getLab0RuntimeFraction() < currentLab0RuntimeFraction);
}

TEST(REBThread1Test){

	My_Init_REB_GPIO_ASM(); //this sets REB LEDs to 0

	//My_Write_REB_LEDS_ASM(0x1000); //turn on REB LED 1
	My_Write_REB_LEDS_ASM(0x1000); //turn on REB LED 1


	unsigned short int currentVal = My_Read_REB_SW_ASM();

	TaskREBThread1();

	unsigned short int expectedVal;
	if(currentVal == 0xf000){
		expectedVal = 0x0000;
	}
	else{
		expectedVal = currentVal + 0x1000;
	}
	unsigned short int actualVal = My_Read_REB_SW_ASM() & 0xf000;

	CHECK(actualVal == expectedVal);
}


TEST(REBThread2Test){

	My_Init_REB_GPIO_ASM(); //this sets REB LEDs to 0

	unsigned short int CurrentREB = My_Read_REB_SW_ASM();
	unsigned short int newREB = CurrentREB & 0x0fff;
	newREB = newREB | 0xc000; //first array value = 0xc
	My_Write_REB_LEDS_ASM(newREB);

	StoreSwitchValuesInArrayThread();

	CurrentREB = My_Read_REB_SW_ASM();
	newREB = CurrentREB & 0x0fff;
	newREB = newREB | 0x1000; //second array value = 0x1
	My_Write_REB_LEDS_ASM(newREB);

	StoreSwitchValuesInArrayThread();

	CurrentREB = My_Read_REB_SW_ASM();
	newREB = CurrentREB & 0x0fff;
	newREB = newREB | 0x3000; //third array value = 0x3
	My_Write_REB_LEDS_ASM(newREB);

	StoreSwitchValuesInArrayThread();

	printf("\n0x%x\n", getArrayValues(0));
	printf("\n0x%x\n", getArrayValues(1));
	printf("\n0x%x\n", getArrayValues(2));

	CHECK(getArrayValues(0) == 0xc);
	CHECK(getArrayValues(1) == 0x1);
	CHECK(getArrayValues(2) == 0x3);
}

TEST(REBThread3){

	My_Init_REB_GPIO_ASM();
	//array with same array values from the function.
	unsigned short int testArrayValues[100] = {0x1,0x2,0x3,0x4,0x5,0x6,0x7,0x8,0x9,0xa,0xb,0xc,0xd};
	int testArrayLength = 13;
	int testIndex = 0;
	int callsToFunc = 0;
	int REBIndex = 0;
	int LEDMASK = 0xf000;
	unsigned short int actualValue = 0;
	unsigned short int expectedValue = 0;
	//read array will get all the values that are in the array NO MASK
	actualValue = My_Read_REB_LEDS_ASM();
	actualValue = actualValue & LEDMASK;
	expectedValue = testArrayValues[0];
	expectedValue = expectedValue << 12;
	XF_CHECK(actualValue == expectedValue);
	DisplayREBSwitchValuesThread();
	callsToFunc ++;
	//check if the led is equal to the first array value XF
	actualValue = My_Read_REB_LEDS_ASM();
	actualValue = actualValue & LEDMASK;
	//read array
	CHECK(actualValue == expectedValue);
	DisplayREBSwitchValuesThread();
	callsToFunc ++;
	actualValue = My_Read_REB_LEDS_ASM();
	actualValue = actualValue & LEDMASK;
	//check again if the led is equal to the first array value XF
	XF_CHECK(actualValue == expectedValue);
}




TEST_FILE_RUN_NOTIFICATION(MainTestingFile_cpp);



