#include <blackfin.h>

.section L1_data;

.section program;
.global _Demonstrate_LED_Control_ASM;

#define CONTROL_REG_P0 P0
#define CURRENT_CONTROL_REG_VALUE_R0 R0
#define NEW_CONTROL_REG_VALUE_R1 R1
#define SWITCH_CASE_COMPARE_BITS_R2 R2
#define CURRENT_CONTROL_REG_LED_VALUE_R3 R3
#define LED_BITS 0xf000
#define LED0_BIT 0x1000
#define LED1_BIT 0x2000
#define LED2_BIT 0x4000
#define LED3_BIT 0X8000
#define LED_BITS_OFF 0x0fff

_Demonstrate_LED_Control_ASM: //NEED TO REFACTOR THIS CODE SO THAT THE SWITCH CASE THAT IS MOST OFTEN USED IS PLACED AT THE START
							//THESE SHOULD ALL BE USED EQUALLY AS IT GOES FROM 0 - 1 - 2 - 1 - 2 - 1 - 2 - ETC.
							//DO NOT HAVE 0 AT THE START, SHOULD START WITH EITHER 1 OR 2 - PUT 0 AT THE END. ONLY USED ONCE
LINK 20;

//unsigned short int currentControlRegValue = pCoffeepot -> controlRegister;

P0 = R0; //P0 is now assigned to pCoffeepot (32-32 bit register transfer)
R0 = W[P0](z); //CURRENT_CONTROL_REG_VALUE_R0 = pCoffeepot -> controlRegister

//	unsigned short int newControlRegValue;

//	switch (currentControlRegValue & LED_BITS){

R3 = R0; //CURRENT_CONTROL_REG_LED_VALUE_R3 = CURRENT_CONTROL_REG_VALUE_R0 & LED_BITS
//R0.L = lo(LED_BITS); R0.H = hi(LED_BITS);
//R3 = R0 & R3;

//R3 = R3 & LED_BITS;

//		case 0x0000:
R0.L = lo(LED_BITS); R0.H = hi(LED_BITS);
R0 = R0 & R3;
R2.L = lo(0x0000); R2.H = hi(0x0000);
CC = R0 == R2; //CURRENT_CONTROL_REG_LED_VALUE_R3 == SWITCH_CASE_COMPATE_BITS_R2
IF !CC JUMP Switch2Label;

//	newControlRegValue = currentControlRegValue | LED0_BIT; //turn on LED0
R2.H = hi(LED0_BIT); R2.L = lo(LED0_BIT);
NEW_CONTROL_REG_VALUE_R1 = R3 | R2;

//	break;
JUMP EndSwitchLabel;

Switch2Label :
//		case 0x1000:
R0.L = lo(LED_BITS); R0.H = hi(LED_BITS);
R0 = R0 & R3;
R2.H = hi(0x1000); R2.L = lo(0x1000);
CC = R0 == R2; //CURRENT_CONTROL_REG_LED_VALUE_R3 == SWITCH_CASE_COMPATE_BITS_R2
IF !CC JUMP Switch3Label;
//			newControlRegValue = currentControlRegValue & LED_BITS_OFF; //turn off all LEDs
R2.H = hi(LED_BITS_OFF); R2.L = lo(LED_BITS_OFF);
NEW_CONTROL_REG_VALUE_R1 = R3 & R2;
//			newControlRegValue |= LED1_BIT; //turn on LED1
R2.H = hi(LED1_BIT); R2.L = lo(LED1_BIT);
NEW_CONTROL_REG_VALUE_R1 = R1 | R2;
//		break;
JUMP EndSwitchLabel;

Switch3Label :
//		case 0x2000:
R2.H = hi(0x2000); R2.L = lo(0x2000);
R0.L = lo(LED_BITS); R0.H = hi(LED_BITS);
R0 = R0 & R3;
CC = R0 == R2; //CURRENT_CONTROL_REG_LED_VALUE_R3 == SWITCH_CASE_COMPATE_BITS_R2
IF !CC JUMP EndSwitchLabel;
//			newControlRegValue = currentControlRegValue & LED_BITS_OFF; //turn off all LEDs
R2.H = hi(LED_BITS_OFF); R2.L = lo(LED_BITS_OFF);
NEW_CONTROL_REG_VALUE_R1 = R3 & R2;
//			newControlRegValue |= LED0_BIT; //turn on LED0
R2.H = hi(LED0_BIT); R2.L = lo(LED0_BIT);
NEW_CONTROL_REG_VALUE_R1 = R1 | R2;
//		break;
//	}

EndSwitchLabel :

//	pCoffeepot -> controlRegister = newControlRegValue;

W[P0] = R1.L;

//put pCoffeepot back into R0 to send as argument to function 

R0 = P0; //32 bit-32 bit register transfer - R0 is now assigned to pCoffeepot (32-32 bit register transfer)

//.extern _FastForward_OneSimulationTIC; //use this to force simulator to respond to the command
//CALL _FastForward_OneSimulationTIC;
.extern __Z28FastForward_OneSimulationTICP16COFFEEPOT_DEVICE;
CALL __Z28FastForward_OneSimulationTICP16COFFEEPOT_DEVICE;

ssync;
UNLINK;
_Demonstrate_LED_Control_ASM.END:
RTS;