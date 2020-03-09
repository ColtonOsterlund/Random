/*****************************************************************************
 * CoffeepotAssignment.h
 *****************************************************************************/

#ifndef __COFFEEPOTASSIGNMENT_H__
#define __COFFEEPOTASSIGNMENT_H__

#include "../../ENCM511_SpecificFiles/ENCM511_include/CoffeePot_SimulatorFunctions2017.h"
#include "../../ENCM511_SpecificFiles/ENCM511_include/CoffeePot_SimulatorStructures2017.h"

void Coffee_Pot_Assignment1_Main(void);
void Init_Coffee_Pot(COFFEEPOT_DEVICE *);
void Activate_LED_Control(COFFEEPOT_DEVICE *);
void Demonstrate_LED_Control_CPP(COFFEEPOT_DEVICE *);
extern "C" void Demonstrate_LED_Control_ASM(COFFEEPOT_DEVICE *);
void ShowNameProcessorUsed(void);
void Activate_Water_Control(COFFEEPOT_DEVICE *);
void Fill_Coffee_Pot_To_Water_Level(int, COFFEEPOT_DEVICE *);
void Activate_Heater_Control(COFFEEPOT_DEVICE *);
void Heat_Water_To_Temperature(int, COFFEEPOT_DEVICE *);
void Control_Both_Temp_Water(int, int, COFFEEPOT_DEVICE *);
void Shut_Off_All_LEDs(COFFEEPOT_DEVICE *);

#endif /* __COFFEEPOTASSIGNMENT_H__ */
