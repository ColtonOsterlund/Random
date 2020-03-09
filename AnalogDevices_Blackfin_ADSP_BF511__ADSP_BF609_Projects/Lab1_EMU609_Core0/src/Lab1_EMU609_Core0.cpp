#include "Lab1_EMU609_Core0.h"

//vars
static bool My_InitLEDInterface_Done = false; //used to check whether the LED interface was initialized
static bool My_InitSwitchInterface_Done = false; //used to check whether the switch interface was initialized
static bool My_Init_CyclesTimer_Done = false; //used to check whether the cycles timer was initialized
#define GARBAGE_VALUE static_cast<unsigned char>(-1) //used to return garbage value if LED or switch is read before interface being initialized
static unsigned char lastLEDValueWritten = GARBAGE_VALUE; //used in the simulator since we don't have hardware to test - software version of LED
static unsigned char lastSwitchValueWritten = GARBAGE_VALUE; //used in the simulator since we don't have hardware to test - software version of switch
#define ARRAY_SIZE 10
unsigned char LEDArray[ARRAY_SIZE] = {0x01, 0x02, 0x03, 0x04, 0x05, 0x04, 0x03, 0x02, 0x01, 0x00}; //each of these values corresponds to one row of LEDs in order
unsigned char LEDArrayLab1[ARRAY_SIZE] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
static int LEDArrayLab1IndexCounter = 0;

//FP LEDS
#define MASK_KEEP_LOWER_5_BITS 0x1f
#define MASK_CHECK_SW1_INDEPENDANT 0x01 //used to isolate bit for switch 1 so that you can check whether it is pressed independantly of other switches
#define MASK_CHECK_SW2_INDEPENDANT 0x02 //used to isolate bit for switch 2 so that you can check whether it is pressed independantly of other switches
#define MASK_CHECK_SW3_INDEPENDANT 0x04 //used to isolate bit for switch 3 so that you can check whether it is pressed independantly of other switches
#define MASK_CHECK_SW4_INDEPENDANT 0x08
#define MASK_CHECK_SW5_INDEPENDANT 0x10
#define SW1BIT 0x01
#define SW2BIT 0x02
#define SW3BIT 0x04
#define SW4BIT 0x08
#define SW5BIT 0x10

//REB LEDS
#define MASK_CHECK_REB_SW1_INDEPENDANT 0x0100
#define MASK_CHECK_REB_SW2_INDEPENDANT 0X0200
#define MASK_CHECK_REB_SW3_INDEPENDANT 0X0400
#define MASK_CHECK_REB_SW4_INDEPENDANT 0x0800
#define REBSW1BIT 0x0100
#define REBSW2BIT 0x0200
#define REBSW3BIT 0x0400
#define REBSW4BIT 0x0800

//function stubs
void Start_Lab_General(void){
	printf("Successfully Entered Start_Lab_General"); //just enough code to C.L.L.R (Compile, Link, Load, Run)

	//QuickTest_FrontPanelSwitchesLEDS(); //test that front panel switches and LEDs are working
	//FirstTest_REBSwitchesV1(); //read from REB switches and print value
	//FirstTest_REBSwitchesV2(); //read from REB switches, display value on FP LEDs
	//FirstTest_REBSwitchesV3(); //read from REB switches, display on FP LEDs, display on REB LEDs

	My_Init_CyclesTimer(); //placeholder for initializing a real timer - fake init cycles timer
	Init_GPIO_FrontPanelLEDS(); //init front panel LEDS
	Init_GPIO_FrontPanelSwitches(); //init front panel swithces
	//Init_GPIO_REB_Input(); //init gpio REB input - this is for switches - needs to read pins from pins PF8 - PF11
	//Init_GPIO_REB_Output(); //init gpio REB output - this is for LEDs - need to write to pins PF12 - PF15
	My_Init_REB_GPIO_ASM();

	//STEP 1 : SET 4 BIT VALUE IN REB SWITCHES
	// -- this is done on hardware --
	//STEP 2 : WAIT FOR FP SWITCH 5 PRESSED AND RELEASED


	WaitTillSwitch5PressedAndReleased();


	//STEP 3 : READ REB SWITCHES USING OUR ASM FUNCTION
	unsigned short int Start_Lab_REB_Switch_Value = My_Read_REB_SW_ASM();

	//STEP 4 : IF SW1 OR SW2 PRESSED START LAB 0, IF SW3 OR SW4 PRESSED START LAB 1
	if(((Start_Lab_REB_Switch_Value & MASK_CHECK_REB_SW1_INDEPENDANT) == REBSW1BIT) || ((Start_Lab_REB_Switch_Value & MASK_CHECK_REB_SW2_INDEPENDANT) == REBSW2BIT)){
		Start_Lab_0(LEDArray); //start lab 0 using LEDArray
	}
	else if(((Start_Lab_REB_Switch_Value & MASK_CHECK_REB_SW3_INDEPENDANT) == REBSW3BIT) || ((Start_Lab_REB_Switch_Value & MASK_CHECK_REB_SW4_INDEPENDANT) == REBSW4BIT)){
		Start_Lab_1();
	}


	printf("Leaving start lab\n");
}

void Start_Lab_0(unsigned char LEDArrayToUse[]){

	printf("/nStarting lab 0/n");

	unsigned long long int timeAtLoopStart = ReadProcessorCyclesCPP();
	unsigned long long int timeToWait = 480000000;
	unsigned long long int timeNow = ReadProcessorCyclesCPP();

	int i = 0;

	while(1){
		unsigned char toDisplay = LEDArrayToUse[i];
		//Write_GPIO_FrontPanelLEDS(toDisplay);


		//**********************************************************THIS WAS ADDED TO WRITE TO REB LEDs ********************************************************************************
		unsigned short int modifiedValueForREBDisplay = toDisplay << 12;
		My_Write_REB_LEDS_ASM(modifiedValueForREBDisplay); //write to REB LEDs also



		if((~Read_GPIO_FrontPanelSwitches() & MASK_KEEP_LOWER_5_BITS) == SW1BIT){
			timeToWait *= 0.5;
		}
		else if((~Read_GPIO_FrontPanelSwitches() & MASK_KEEP_LOWER_5_BITS) == SW3BIT){
			timeToWait *= 2;
		}

		timeNow = ReadProcessorCyclesCPP();
		while(timeNow < (timeAtLoopStart + timeToWait)){
			timeNow = ReadProcessorCyclesCPP();
		}

		i++;
		if(i == ARRAY_SIZE + 1){
			i = 0;
		}
		timeAtLoopStart = ReadProcessorCyclesCPP();
	}


	LEDArrayLab1IndexCounter = 0; //reset the LEDArrayLab1IndexCounter at the end of running through the lab 0 code
									//so that you refill the array next time you run through lab 1
}

void Start_Lab_1(void){

	printf("\n\nstart lab 1\n\n");

	int value = 0;

	while(1){
		value = WaitTillSwitch5PressedAndReleased();

		printf("%d", value);

		if(value == 0){ //SW4 was not pressed when SW5 released
			unsigned char rebSwitchValue = (My_Read_REB_SW_ASM() >> 8);
			LEDArrayLab1[LEDArrayLab1IndexCounter++] = rebSwitchValue;

			if(LEDArrayLab1IndexCounter == ARRAY_SIZE + 1){
				Start_Lab_0(LEDArrayLab1); //IF YOU FILL THE ARRAY IT WILL AUTOMATICALLY START LAB 1
			}

		}

		else if(value == 1){ //SW4 was pressed when SW5 released
			Start_Lab_0(LEDArrayLab1);
		}
	}







//
//	//READ REB SWITCH VALUE INTO ARRAY IF FPSW5 IS PRESSED AND FPSW4 NOT PRESSED
//	while(1){ //this loop waits for switch 5 to be pressed
//
//		if(((~Read_GPIO_FrontPanelSwitches() & MASK_KEEP_LOWER_5_BITS) & MASK_CHECK_SW5_INDEPENDANT) == SW5BIT){
//
//			printf("/n/nswitch 5 oressed /n/n");
//
//			while(1){ //this loop waits for switch 5 to be released
//				if((((~Read_GPIO_FrontPanelSwitches() & MASK_KEEP_LOWER_5_BITS) & MASK_CHECK_SW5_INDEPENDANT) != SW5BIT) && (((~Read_GPIO_FrontPanelSwitches() & MASK_KEEP_LOWER_5_BITS) & MASK_CHECK_SW4_INDEPENDANT) != SW4BIT)){
//
//					printf("/n/nFP switch 5 pressed wo switch 4/n/n");
//
//
//
//				}
//			}
//		}
//
//		else if((((~Read_GPIO_FrontPanelSwitches() & MASK_KEEP_LOWER_5_BITS) & MASK_CHECK_SW5_INDEPENDANT) == SW5BIT) && (((~Read_GPIO_FrontPanelSwitches() & MASK_KEEP_LOWER_5_BITS) & MASK_CHECK_SW4_INDEPENDANT) == SW4BIT)){
//			while(1){ //this loop waits for switch 5 to be released
//				if((((~Read_GPIO_FrontPanelSwitches() & MASK_KEEP_LOWER_5_BITS) & MASK_CHECK_SW5_INDEPENDANT) != SW5BIT) && (((~Read_GPIO_FrontPanelSwitches() & MASK_KEEP_LOWER_5_BITS) & MASK_CHECK_SW4_INDEPENDANT) == SW4BIT)){
//
//					printf("/n/nFP switch 5 pressed with switch 4 pressed/n/n");
//
//					//SW5 PRESSED AND RELEASED WHILE SW4 PRESSED
//					//Start lab 0 using LEDArrayLab1
//					Start_Lab_0(LEDArrayLab1);
//
//				}
//			}
//		}
//
//	}

}

void FirstTest_REBSwitchesV1(void){ //READS AND PRINTS VALUE FROM REB SWITCHES
	My_Init_CyclesTimer(); //placeholder for initializing a real timer - fake init cycles timer
	Init_GPIO_FrontPanelLEDS(); //init front panel LEDS
	Init_GPIO_FrontPanelSwitches(); //init front panel swithces
	Init_GPIO_REB_Input(); //init gpio REB input - this is for switches - needs to read pins from pins PF8 - PF11
	Init_GPIO_REB_Output(); //init gpio REB output - this is for LEDs - need to write to pins PF12 - PF15

	unsigned long long int timeAtLoopStart = ReadProcessorCyclesCPP();
	unsigned long long int timeToWait = 480000000;
	unsigned long long int timeNow = NULL;

	unsigned short int switchValue_REB = GARBAGE_VALUE; //THIS IS AN UNSIGNED SHORT INT - 16 BITS
	unsigned char modified_switchValue_REB_for_FP_Display = GARBAGE_VALUE;

	while(1){
		switchValue_REB = My_Read_REB_SW_ASM();//Read_GPIO_REB_Input();
		printf("REB SWITCHES ORIGINAL VAL Decimal Value: %d, Hex Value: 0x%x\n", switchValue_REB, switchValue_REB); //reading from input - assuming ACTIVE HIGH (check this)

		//wait 1 second
		timeNow = ReadProcessorCyclesCPP();
		while(timeNow < (timeAtLoopStart + timeToWait)){
			timeNow = ReadProcessorCyclesCPP();
		}
		timeAtLoopStart = ReadProcessorCyclesCPP();
	}
}

void FirstTest_REBSwitchesV2(void){ //READS AND PRINTS VALUE FROM REB SWITCHES, MODIFIES VALUE TO BE SEND TO FP LEDS, DISPLAYS ON REB LEDS
	My_Init_CyclesTimer(); //placeholder for initializing a real timer - fake init cycles timer
	Init_GPIO_FrontPanelLEDS(); //init front panel LEDS
	Init_GPIO_FrontPanelSwitches(); //init front panel swithces
	Init_GPIO_REB_Input(); //init gpio REB input - this is for switches - reads from pins PF8 - PF11
	Init_GPIO_REB_Output(); //init gpio REB output - this is for LEDs - writes to pins PF12 - PF15

	unsigned long long int timeAtLoopStart = ReadProcessorCyclesCPP();
	unsigned long long int timeToWait = 480000000;
	unsigned long long int timeNow = NULL;

	unsigned short int switchValue_REB = GARBAGE_VALUE; //THIS IS AN UNSIGNED SHORT INT - 16 BITS
	unsigned char modified_switchValue_REB_for_FP_Display = GARBAGE_VALUE; //this will be sent to front panel LEDs

	while(1){
		switchValue_REB = Read_GPIO_REB_Input(); //read value from pins PF8 - PF11 (input pins)
		printf("REB SWITCHES ORIGINAL VAL Decimal Value: %d, Hex Value: 0x%x\n", switchValue_REB, switchValue_REB); //reading from input - assuming ACTIVE HIGH (check this)

		//must turn 4 bit switchValue_REB value into 8 bit modified_switchValue_REB_for_FP_Display value to display on FP LEDs
		modified_switchValue_REB_for_FP_Display = (switchValue_REB >> 8) & 15; //15 (decimal) = 1111 (binary) - only want to keep last 4 bits

		printf("FP LED MODIFIED VAL Decimal Value: %d, Hex Value: 0x%x\n", modified_switchValue_REB_for_FP_Display, modified_switchValue_REB_for_FP_Display);

		Write_GPIO_FrontPanelLEDS(modified_switchValue_REB_for_FP_Display); //print to front panel LEDs

		//wait 1 second
		timeNow = ReadProcessorCyclesCPP();
		while(timeNow < (timeAtLoopStart + timeToWait)){
			timeNow = ReadProcessorCyclesCPP();
		}
		timeAtLoopStart = ReadProcessorCyclesCPP();
	}

}

void FirstTest_REBSwitchesV3(void){ //READS AND PRINTS VALUE FROM REB SWITCHES, MODIFIES VALUE TO BE SEND TO FP LEDS, DISPLAYS ON REB LEDS
	My_Init_CyclesTimer(); //placeholder for initializing a real timer - fake init cycles timer
	Init_GPIO_FrontPanelLEDS(); //init front panel LEDS
	Init_GPIO_FrontPanelSwitches(); //init front panel swithces
	Init_GPIO_REB_Input(); //init gpio REB input - this is for switches - reads from pins PF8 - PF11
	Init_GPIO_REB_Output(); //init gpio REB output - this is for LEDs - writes to pins PF12 - PF15

	unsigned long long int timeAtLoopStart = ReadProcessorCyclesCPP();
	unsigned long long int timeToWait = 480000000;
	unsigned long long int timeNow = NULL;

	unsigned short int switchValue_REB = GARBAGE_VALUE; //THIS IS AN UNSIGNED SHORT INT BECAUSE IT READS IN 16 BITS
	unsigned char modified_switchValue_REB_for_FP_Display = GARBAGE_VALUE; //this will be sent to front panel LEDs - must turn 16 bit value into 8 bit value
	unsigned short int modified_switchValue_REB_for_REB_Display = GARBAGE_VALUE;

	while(1){
		switchValue_REB = Read_GPIO_REB_Input(); //read value from pins PF8 - PF11 (input pins)
		printf("REB SWITCHES ORIGINAL VAL Decimal Value: %d, Hex Value: 0x%x\n", switchValue_REB, switchValue_REB); //reading from input - assuming ACTIVE HIGH (check this)

		//must turn 4 bit switchValue_REB value into 8 bit modified_switchValue_REB_for_FP_Display value to display on FP LEDs
		modified_switchValue_REB_for_FP_Display = (switchValue_REB >> 8) & 15; //15 (decimal) = 1111 (binary) - only want to keep last 4 bits

		printf("FP LED MODIFIED VAL Decimal Value: %d, Hex Value: 0x%x\n", modified_switchValue_REB_for_FP_Display, modified_switchValue_REB_for_FP_Display);

		Write_GPIO_FrontPanelLEDS(modified_switchValue_REB_for_FP_Display); //print to front panel LEDs

		//use bitwise operations to modify switchValue_REB into a pattern you can display on REB_LEDs
		modified_switchValue_REB_for_REB_Display = (switchValue_REB & 0X0fff) | ((switchValue_REB << 4) & 0xf000); //copies bit values 8-11 into bit values 12-15 without changing any of the others
		printf("REB LED MODIFIED VAL Decimal Value: %d, Hex Value: 0x%x\n", modified_switchValue_REB_for_REB_Display, modified_switchValue_REB_for_REB_Display);

		Write_GPIO_REB_Output(modified_switchValue_REB_for_REB_Display);

		//wait 1 second
		timeNow = ReadProcessorCyclesCPP();
		while(timeNow < (timeAtLoopStart + timeToWait)){
			timeNow = ReadProcessorCyclesCPP();
		}
		timeAtLoopStart = ReadProcessorCyclesCPP();
	}

}

void QuickTest_FrontPanelSwitchesLEDS(void){
	//printf("Stub for QuickTest_FrontPanelSwitchedLEDS()\n");

	My_Init_CyclesTimer(); //init cycles timer
	Init_GPIO_FrontPanelLEDS(); //init front panel LEDS
	Init_GPIO_FrontPanelSwitches(); //init front panel swithces

	unsigned long long int timeAtLoopStart = ReadProcessorCyclesCPP();
	unsigned long long int timeToWait = 480000000;
	unsigned long long int timeNow = NULL;

	unsigned char switchValue_FP = GARBAGE_VALUE;

	while(1){
		//read FP switch value - display on FP LEDS and print in console
		switchValue_FP = Read_GPIO_FrontPanelSwitches(); //read front panel switches into switchValue_FP
		Write_GPIO_FrontPanelLEDS(~switchValue_FP); //display switchValue_FP on front panel LEDS - needs to be NOTed since switches are ACTIVE LOW and LEDS are ACTIVE HIGH
		printf("Decimal Value: %d, Hex Value: 0x%x - (These are printed as ACTIVE HIGH)\n", ~switchValue_FP, ~switchValue_FP);

		//wait 1 second
		timeNow = ReadProcessorCyclesCPP();
		while(timeNow < (timeAtLoopStart + timeToWait)){
			timeNow = ReadProcessorCyclesCPP();
		}
		timeAtLoopStart = ReadProcessorCyclesCPP();
	}
}

void My_Init_LEDInterface(void){
	printf("Stub for My_InitLEDInterface()\n");
	My_InitLEDInterface_Done = true;
}

void My_Init_SwitchInterface(void){
	printf("Stub for My_InitSwitchInterface()\n");
	My_InitSwitchInterface_Done = true;
}

void My_Init_CyclesTimer(void){
	printf("Stub for My_Init_CyclesTimer()\n");
	My_Init_CyclesTimer_Done = true;
}

void My_WriteLED(unsigned char valueToWrite){
	//printf("Stub for My_WriteLED()\n");

	if(My_InitLEDInterface_Done == false){
		printf("Error: LED Interface Not Initialized\n");
		return;
	}

	lastLEDValueWritten = valueToWrite;

}

void My_WriteSwitches(unsigned char valueToWrite){
	printf("Stub for My_WriteSwitch()\n");

	if(My_InitSwitchInterface_Done == false){
		printf("Error: Switch Interface Not Initialized\n");
		return;
	}

	lastSwitchValueWritten = valueToWrite;
}

unsigned char My_ReadLED(void){
	//printf("Stub for My_ReadLED()\n");

	if(My_InitLEDInterface_Done == false){
		printf("Error: LED Interface Not Initialized\n");
		return GARBAGE_VALUE;
	}

	return lastLEDValueWritten;
}

unsigned char My_ReadSwitches(void){
	printf("Stub for My_ReadSwitch()\n");

	if(My_InitSwitchInterface_Done == false){
		printf("Error: Switch Interface Not Initialized\n");
		return GARBAGE_VALUE;
	}

	return lastSwitchValueWritten;
}

void PrintBinaryValue(unsigned char LEDNumber){
	//PRINT BINARY VALUE OF LED NUMBER

	printf("Decimal Value: %03d | Hex Value: 0x%02x | Binary Value: ", LEDNumber, LEDNumber);

		unsigned char num = 0;

		for(int i = 7; i >= 0; i--){
			num = LEDNumber >> i;
			num = num & 1;
			if(num == 0){
				printf(" ");
			}
			else{
				printf("%d", num);
			}
		}

		printf("\n");
}

//Start display once
void WaitTillSwitch1PressedAndReleased(void){
	while(1){ //this loop waits for switch 1 to be pressed


			if(((~Read_GPIO_FrontPanelSwitches() & MASK_KEEP_LOWER_5_BITS) & MASK_CHECK_SW1_INDEPENDANT) == SW1BIT){

				while(1){
					if(((~Read_GPIO_FrontPanelSwitches() & MASK_KEEP_LOWER_5_BITS) & MASK_CHECK_SW1_INDEPENDANT) != SW1BIT){
						return;
					}
					}

				}

			}

}

//Step through display
void WaitTillSwitch2PressedAndReleased(void){
	while(1){ //this loop waits for switch 1 to be pressed


				if(((~Read_GPIO_FrontPanelSwitches() & MASK_KEEP_LOWER_5_BITS) & MASK_CHECK_SW2_INDEPENDANT) == SW2BIT){

					while(1){
						if(((~Read_GPIO_FrontPanelSwitches() & MASK_KEEP_LOWER_5_BITS) & MASK_CHECK_SW2_INDEPENDANT) != SW2BIT){
							return;
						}
						}

					}

				}
}

//Run display again and again without waiting
void WaitTillSwitch3PressedAndReleased(void){
	while(1){ //this loop waits for switch 1 to be pressed


				if(((~Read_GPIO_FrontPanelSwitches() & MASK_KEEP_LOWER_5_BITS) & MASK_CHECK_SW3_INDEPENDANT) == SW3BIT){

					while(1){
						if(((~Read_GPIO_FrontPanelSwitches() & MASK_KEEP_LOWER_5_BITS) & MASK_CHECK_SW3_INDEPENDANT) != SW3BIT){
							return;
						}
						}

					}

				}
}

void WaitTillSwitch4PressedAndReleased(void){
	while(1){ //this loop waits for switch 1 to be pressed


				if(((~Read_GPIO_FrontPanelSwitches() & MASK_KEEP_LOWER_5_BITS) & MASK_CHECK_SW4_INDEPENDANT) == SW4BIT){

					while(1){
						if(((~Read_GPIO_FrontPanelSwitches() & MASK_KEEP_LOWER_5_BITS) & MASK_CHECK_SW4_INDEPENDANT) != SW4BIT){
							return;
						}
						}

					}

				}
}

int WaitTillSwitch5PressedAndReleased(void){
	while(1){ //this loop waits for switch 1 to be pressed


					if(((~Read_GPIO_FrontPanelSwitches() & MASK_KEEP_LOWER_5_BITS) & MASK_CHECK_SW5_INDEPENDANT) == SW5BIT){

						while(1){
							if(((~Read_GPIO_FrontPanelSwitches() & MASK_KEEP_LOWER_5_BITS) & MASK_CHECK_SW5_INDEPENDANT) != SW5BIT){
								return ((~Read_GPIO_FrontPanelSwitches() & MASK_KEEP_LOWER_5_BITS) & MASK_CHECK_SW4_INDEPENDANT) >> 3;
							}
							}

						}

					}

}



unsigned long long int ReadProcessorCyclesCPP(void){

	if(My_Init_CyclesTimer_Done == false){ //do a self check that "Cycles Timer" was initialized
		printf("Error: Timer Not Initialized\n");
		return GARBAGE_VALUE;
	}

#if 0
	unsigned long long int cyclesValue = *pCYCLES;
#endif

#if 1
	unsigned long long int cyclesValue = ReadProcessorCyclesASM();
#endif

	return cyclesValue;
}




