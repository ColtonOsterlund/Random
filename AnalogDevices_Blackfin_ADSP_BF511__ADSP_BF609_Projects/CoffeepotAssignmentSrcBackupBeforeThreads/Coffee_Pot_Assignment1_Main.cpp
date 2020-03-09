#include <stdio.h>
#include "CoffeepotAssignment.h"

#define MAX_SECONDS 10
#define MAX_WATER_LEVEL 600
#define MAX_TEMPERATURE 80

#define LATER
#define EVEN_LATER
#define EVEN_LATER_ER
#define FINAL_CONTROL

void Coffee_Pot_Assignment1_Main(void){

#ifdef DESIGNPLAN1
	ShowNameProcessorUsed();

	Init_CoffeePotSimulation(1, USE_TEXT_AND_GRAPHICS_GUIS);

	Init_Coffee_Pot();//does not exist anymore - used for function stub to test if it would CLLR

	Activate_LED_Control();//does not exist anymore - used for function stub to test if it would CLLR

	bool continue_Demonstrate_LED_Control = true;
	unsigned long int secondsCounter = 0;

	while(continue_Demonstrate_LED_Control){
		Demonstrate_LED_Control_CPP();//does not exist anymore - used for function stub to test if it would CLLR
		if(++secondsCounter >= MAX_SECONDS)
			continue_Demonstrate_LED_Control = false;
	}

#endif

	ShowNameProcessorUsed();

	Init_CoffeePotSimulation(1, USE_TEXT_AND_GRAPHICS_GUIS);

	COFFEEPOT_DEVICE *pCoffeepot1 = Add_CoffeePotToSystem_PlugAndPlay(COFFEEPOT1, "Colton Osterlund Coffee Pot 1");

	Init_Coffee_Pot(pCoffeepot1);

	Activate_LED_Control(pCoffeepot1);

#ifdef DESIGNPLAN2

	bool continue_Demonstrate_LED_Control = true;
	unsigned long int secondsCounter = 0;

	while(continue_Demonstrate_LED_Control){
		Demonstrate_LED_Control_CPP(pCoffeepot1);
		if(++secondsCounter >= MAX_SECONDS)
			continue_Demonstrate_LED_Control = false;
	}

	printf("Completed all tests\n\n");

#endif

#ifdef LATER

	bool continue_Demonstrate_LED_Control = true;
	unsigned long int secondsCounter = 0;

	while(continue_Demonstrate_LED_Control){
		Demonstrate_LED_Control_ASM(pCoffeepot1);
		if(++secondsCounter >= MAX_SECONDS)
			continue_Demonstrate_LED_Control = false;
	}

	Shut_Off_All_LEDs(pCoffeepot1); //shut off all LEDs after running LED blinking test.

#endif

#ifdef EVEN_LATER

	Activate_Water_Control(pCoffeepot1); //turn on water control and LED0 to indicate that water control is on
//	bool continue_Demonstrate_Water_Control = true;
//	secondsCounter = 0;
//
//	while(continue_Demonstrate_Water_Control){
//		Fill_Coffee_Pot_To_Water_Level(MAX_WATER_LEVEL, pCoffeepot1);
//		if(++secondsCounter >= MAX_SECONDS)
//			continue_Demonstrate_Water_Control = false;
//	}

#endif

#ifdef EVEN_LATER_ER

	Activate_Heater_Control(pCoffeepot1); //turn on heater enable bit and LED1 to indicate that heater is turned on
//	bool continue_Demonstrate_Heater_Control = true;
//	secondsCounter = 0;
//
//	while(continue_Demonstrate_Heater_Control){
//		Heat_Water_To_Temperature(MAX_WATER_LEVEL, pCoffeepot1);
//		if(++secondsCounter >= MAX_SECONDS)
//			continue_Demonstrate_Heater_Control = false;
//	}

#endif

#ifdef FINAL_CONTROL

	bool continue_Demonstrate_Both_Temp_Water = true;
	secondsCounter = 0;

//	while(continue_Demonstrate_Both_Temp_Water){
//		Control_Both_Temp_Water(MAX_WATER_LEVEL, MAX_TEMPERATURE, pCoffeepot1);
//		if(++secondsCounter >= MAX_SECONDS)
//			continue_Demonstrate_Both_Temp_Water = false;
//	}

	while(1){
		Control_Both_Temp_Water(MAX_WATER_LEVEL, MAX_TEMPERATURE, pCoffeepot1);
	}

#endif


}
