#include <stdio.h>
#include "CoffeepotAssignment.h"
#define TURN_ON_COFFEEPOT_BIT 0x1
#define COFFEEPOT_READY_BIT 0x10
#define LED_ENABLE_BIT 0x2
#define LED_BITS 0xf000
#define LED0_BIT 0x1000
#define LED1_BIT 0x2000
#define LED2_BIT 0x4000
#define LED3_BIT 0X8000
#define LED_BITS_OFF 0x0fff
#define WATER_ENABLE_BIT 0x4
#define HEATER_ENABLE_BIT 0X8
#define WATER_FULL_ON

void Init_Coffee_Pot(COFFEEPOT_DEVICE *pCoffeepot){
	printf("Init coffeepot:\n\n");

	//set the POWER_ON and INIT bit in Coffeepot control register
	unsigned short int currentControlRegValue = pCoffeepot -> controlRegister;
	unsigned short int newControlRegValue = currentControlRegValue | TURN_ON_COFFEEPOT_BIT;
	pCoffeepot -> controlRegister = newControlRegValue;

	FastForward_OneSimulationTIC(pCoffeepot); //use this to force simulator to respond to the command

	//then in a loop, read control register, use bitwise AND to see if device is ready
	while(1){
		currentControlRegValue = pCoffeepot -> controlRegister;

		if((currentControlRegValue & COFFEEPOT_READY_BIT) == COFFEEPOT_READY_BIT){
			printf("\n\nCoffeepot is ready\n\n");
			break;
		}

		printf("Waiting for coffeepot to be ready\n");
		FastForward_OneSimulationTIC(pCoffeepot); //use this to force simulator to respond to the command
	}

	//when ready - exit loop
}

void Activate_LED_Control(COFFEEPOT_DEVICE *pCoffeepot){
	printf("Activate LED Control\n\n");

	//Turn on LED_POWER bit in Coffeepot control register, without turning off other bits
	unsigned short int currentControlRegValue = pCoffeepot -> controlRegister;
	unsigned short int newControlRegValue = currentControlRegValue | LED_ENABLE_BIT;
	pCoffeepot -> controlRegister = newControlRegValue;

	FastForward_OneSimulationTIC(pCoffeepot); //use this to force simulator to respond to the command


	//build Activate_LED_Control_ASM using Activate_LED_Control_CPP code as a design idea
}

void Demonstrate_LED_Control_CPP(COFFEEPOT_DEVICE *pCoffeepot){
	printf("Demonstrate LED controls\n\n");

	//Use state machine ideas from lab 1
	//state 0 -- turn on LED1 and turn off LED0
	unsigned short int currentControlRegValue = pCoffeepot -> controlRegister;
	unsigned short int newControlRegValue;

	switch (currentControlRegValue & LED_BITS){
		case 0x0000:
			newControlRegValue = currentControlRegValue | LED0_BIT; //turn on LED0
		break;

		case 0x1000:
			newControlRegValue = currentControlRegValue & LED_BITS_OFF; //turn off all LEDs
			newControlRegValue |= LED1_BIT; //turn on LED1
		break;

		case 0x2000:
			newControlRegValue = currentControlRegValue & LED_BITS_OFF; //turn off all LEDs
			newControlRegValue |= LED0_BIT; //turn on LED0
		break;
	}

	pCoffeepot -> controlRegister = newControlRegValue;
	FastForward_OneSimulationTIC(pCoffeepot); //use this to force simulator to respond to the command

}

void Shut_Off_All_LEDs(COFFEEPOT_DEVICE *pCoffeepot){
	unsigned short int currentControlRegValue = pCoffeepot -> controlRegister;
	unsigned short int newControlRegValue = currentControlRegValue & LED_BITS_OFF;
	pCoffeepot -> controlRegister = newControlRegValue;

	FastForward_OneSimulationTIC(pCoffeepot);
}

void ShowNameProcessorUsed(void){
	//printf("Stub for ShowNameProcessorUsed()\n");
#if defined(__ADSPBF533__)
	char processor[] = "__ADSPBF533__";
#else defined(__ADPSBF609__)
	char processor[] = "__ADSPBF609__";
#endif
	printf("Coffeepot running on %s system\n\n", processor);
}

void Activate_Water_Control(COFFEEPOT_DEVICE *pCoffeepot){
	printf("\n\nActivate Water Control\n\n");

	//set water enable bit
	unsigned short int currentControlRegValue = pCoffeepot -> controlRegister;
	unsigned short int newControlRegValue = currentControlRegValue | WATER_ENABLE_BIT;

	//turn on LED0 to indicate that water control is on
	newControlRegValue = newControlRegValue | LED0_BIT;

	pCoffeepot -> controlRegister = newControlRegValue;

	FastForward_OneSimulationTIC(pCoffeepot);
}

void Fill_Coffee_Pot_To_Water_Level(int maxWaterLevel, COFFEEPOT_DEVICE *pCoffeepot){
	printf("Filling coffee pot\n");

	pCoffeepot->waterInFlowRegister = 0xff;

	FastForward_OneSimulationTIC(pCoffeepot);
}

void Activate_Heater_Control(COFFEEPOT_DEVICE *pCoffeepot){
	printf("\n\nActivating heater control\n\n");

	unsigned short int currentControlRegValue = pCoffeepot -> controlRegister;

	//turn on heater enable bit
	unsigned short int newControlRegValue = currentControlRegValue | HEATER_ENABLE_BIT;

	//turn on LED1 to indicate that heater is on
	newControlRegValue = newControlRegValue | LED1_BIT;

	pCoffeepot -> controlRegister = newControlRegValue;

	FastForward_OneSimulationTIC(pCoffeepot);
}

void Heat_Water_To_Temperature(int, COFFEEPOT_DEVICE *pCoffeepot){
	printf("\n\nHeating coffeepot\n\n");

	pCoffeepot -> heaterRegister = 0xff;
	pCoffeepot -> heaterBoostRegister = 0x0f;

	FastForward_OneSimulationTIC(pCoffeepot);
}

void Control_Both_Temp_Water(int, int, COFFEEPOT_DEVICE *pCoffeepot){
	printf("\n\nControlling both temperature and water\n\n");


	unsigned short int currentWaterLevel = CurrentWaterLevel_CPP(pCoffeepot); //OVERFLOWS AT 500
	unsigned short int currentWaterTemperature = CurrentTemperature_CPP(pCoffeepot);

	// CANNOT USE A SWITCH CASE FOR THIS, NEED RANGES OF VALUES AND SWITCH CASES CAN ONLY MATCH INTEGER VALUES

	//TAKE ACTION TO ADJUST WATER
	if(currentWaterLevel < 250){ //UNDER HALF FULL
		pCoffeepot -> waterInFlowRegister = 0xff; //WATER FULLY ON - 255
	}
	else if(currentWaterLevel >= 250 && currentWaterLevel < 400){ //BETWEEN HALF AND 80% FULL
		pCoffeepot -> waterInFlowRegister = 0xbf; // WATER 3/4 ON - 191
	}
	else if(currentWaterLevel >= 400 && currentWaterLevel < 450){ //BETWEEN 80% AND 90% FULL
		pCoffeepot -> waterInFlowRegister = 0x32; // WATER JUST UNDER 1/4 ON - 50
	}
	else if(currentWaterLevel >= 450){ //BETWEEN 90% AND 100% FULL
		pCoffeepot -> waterInFlowRegister = 0x00; // WATER OFF
	}

	//TAKE ACTION TO ADJUST TEMPERATURE
	if(currentWaterTemperature < 50){
		pCoffeepot -> heaterRegister = 0xff; //HEAT FULLY ON - 255
		pCoffeepot -> heaterBoostRegister = 0x0f; //HEATER BOOST FULLY ON - 15
	}
	else if(currentWaterTemperature >= 50 && currentWaterTemperature < 75){
		pCoffeepot -> heaterRegister = 0xbf; //HEAT 3/4 ON - 191
		pCoffeepot -> heaterBoostRegister = 0x0f; //HEATER BOOST FULLY ON - 15
	}
	else if(currentWaterTemperature >= 75 && currentWaterTemperature < 90){
		pCoffeepot -> heaterRegister = 0x80; //HEAT 1/2 ON - 128
		pCoffeepot -> heaterBoostRegister = 0x0f; //HEATER BOOST FULLY ON - 15
	}
	else if(currentWaterTemperature >= 90){
		pCoffeepot -> heaterRegister = 0x00; //HEAT OFF
		pCoffeepot -> heaterBoostRegister = 0x00; //HEATER BOOST OFF
	}


	FastForward_OneSimulationTIC(pCoffeepot);

}

