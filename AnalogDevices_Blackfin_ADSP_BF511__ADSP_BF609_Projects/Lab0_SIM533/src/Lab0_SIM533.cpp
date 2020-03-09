#include "Lab0_SIM533.h"

//vars
static bool My_InitLEDInterface_Done = false; //used to check whether the LED interface was initialized
static bool My_InitSwitchInterface_Done = false; //used to check whether the switch interface was initialized
#define GARBAGE_VALUE static_cast<unsigned char>(-1) //used to return garbage value if LED or switch is read before interface being initialized
static unsigned char lastLEDValueWritten = GARBAGE_VALUE; //used in the simulator since we don't have hardware to test - software version of LED
static unsigned char lastSwitchValueWritten = GARBAGE_VALUE; //used in the simulator since we don't have hardware to test - software version of switch
#define ARRAY_SIZE 10
unsigned char LEDArray[ARRAY_SIZE] = {0x7e, 0x42, 0x42, 0x00, 0x60, 0x00, 0x7e, 0x42, 0x7e, 0x60}; //each of these values corresponds to one row of LEDs in order
#define MASK_KEEP_LOWER_5_BITS 0x1f
#define MASK_CHECK_SW1_INDEPENDANT 0x01 //used to isolate bit for switch 1 so that you can check whether it is pressed independantly of other switches
#define MASK_CHECK_SW2_INDEPENDANT 0x02 //used to isolate bit for switch 2 so that you can check whether it is pressed independantly of other switches
#define MASK_CHECK_SW3_INDEPENDANT 0x04 //used to isolate bit for switch 3 so that you can check whether it is pressed independantly of other switches
#define SW1BIT 1
#define SW2BIT 2
#define SW3BIT 4

//function stubs
void Start_Lab0(void){
	printf("Successfully Entered StartLab0"); //just enough code to C.L.L.R (Compile, Link, Load, Run)

	My_Init_LEDInterface(); //Commented out to refactor code for apporpriate names Lab0
	My_Init_SwitchInterface(); //Commented out to refactor code for apporpriate names Lab0
	//Init_GPIO_FrontPanelSwitches(); //INITIALIZE THE FRONT PANEL SWITCHES ON THE 609
	//Init_GPIO_FrontPanelLEDS(); //INITIALIZE THE FRONT PANEL LEDS ON THE 609
	//Init_Timer(); //Timer so the switches have time to be pressed between clock cycles


#if 0 //switch test
	printf("Press switch 3\n");
	unsigned char switchValue = ~Read_GPIO_FrontPanelSwitches() & MASK_KEEP_LOWER_5_BITS; // My_ReadSwitch(); Refactored name for Lab0
	if(switchValue != 4){//SWITCH 3 IS ACTUALLY INTEGER VALUE 4, BINARY 0100
		printf("Failed Read Switch Test\n");
		printf("0x%x\n", switchValue);
	}
#endif

#if 0 //LED test
	unsigned char useLEDValue = 0x41;
	Write_GPIO_FrontPanelLEDS(useLEDValue); //My_WriteLED(useLEDValue); Refactored name for lab0

	unsigned char checkedLEDValue = Read_GPIO_FrontPanelLEDS();  //My_ReadLED(); refactored name for lab0
	if(useLEDValue != checkedLEDValue){
		printf("Failed Read / Write LED Test\n");
	}
#endif

#if 0 //loop through LED values test
	for(unsigned char useLEDValue = 0x00; useLEDValue <= 0x80; useLEDValue += 1){
		Write_GPIO_FrontPanelLEDS(useLEDValue); //My_WriteLED(useLEDValue); refactored name for lab0

		unsigned char checkedLEDValue = Read_GPIO_FrontPanelLEDS(); //My_ReadLED(); refactored name for lab0
		if(useLEDValue != checkedLEDValue){
			printf("Failed Read / Write LED Test\n");
		}

		else{
			PrintBinaryValue(My_ReadLED());
		}

	}
#endif

#if 1 //use LED array test

	for(int i = 0; i < 10; i++){
		My_WriteLED(LEDArray[i]); //Commented out to refactor code for apporpriate names Lab0
		//Write_GPIO_FrontPanelLEDS(LEDArray[i]);

		unsigned char checkedLEDValue = /*Read_GPIO_FrontPanelLEDS();*/ My_ReadLED(); //Refactored names for Lab0
		if(LEDArray[i] != checkedLEDValue){
			printf("Failed Read / Write LED Test\n");
		}

		else{
			PrintBinaryValue(/*Read_GPIO_FrontPanelLEDS()*/ My_ReadLED()); //My_ReadLED(); Refactored names for Lab0
		}
	}

#endif

#if 0 //Lab 0 SuperLoop Test

	WaitTillSwitch1PressedAndReleased(); //first wait until switch 1 is pressed and released to start the superloop

	unsigned long long int timeAtLoopStart = ReadProcessorCyclesCPP();
	unsigned long long int timeToWait = 480000000;
	unsigned long long int timeNow = NULL;

	int i = 0;

	while(1){ //superloop
		unsigned char toDisplay = LEDArray[i];
		Write_GPIO_FrontPanelLEDS(toDisplay);

		if(((~Read_GPIO_FrontPanelSwitches() & MASK_KEEP_LOWER_5_BITS) & MASK_CHECK_SW3_INDEPENDANT) != SW3BIT){ //if switch 3 is pressed bypass this
			WaitTillSwitch2PressedAndReleased();
		}


		timeNow = ReadProcessorCyclesCPP();
		while(timeNow < (timeAtLoopStart + timeToWait)){
			timeNow = ReadProcessorCyclesCPP();
		}


		i++;
		if(i == ARRAY_SIZE + 1){ //if i surpassed ARRAY_SIZE reset to 0
			i = 0;
		}

		timeAtLoopStart = ReadProcessorCyclesCPP();
	}

#endif

#if 0 // Lab 0 Switch to speed up/slow down LEDs test

unsigned long long int timeAtLoopStart = ReadProcessorCyclesCPP();
unsigned long long int timeToWait = 480000000;
unsigned long long int timeNow = NULL;

int i = 0;

while(1){
	unsigned char toDisplay = LEDArray[i];
	Write_GPIO_FrontPanelLEDS(toDisplay);

	if((~Read_GPIO_FrontPanelSwitches() & MASK_KEEP_LOWER_5_BITS) == SW1BIT){
		timeToWait *= 0.5;
	}
	else if((~Read_GPIO_FrontPanelSwitches() & MASK_KEEP_LOWER_5_BITS) == SW3BIT){
		timeToWait *= 2;
	}


	//DO ANOTHER THREAD ?? -> this was in the lab manual - ask about it (I think just another thread can be done here as long as it does not put the loop over the total time allowed (1s))


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

#endif

//#warning "ignore unreachable"
//printf("Leaving start lab\n");
}

void My_Init_LEDInterface(void){
	printf("Stub for My_InitLEDInterface()\n");
	My_InitLEDInterface_Done = true;
}

void My_Init_SwitchInterface(void){
	printf("Stub for My_InitSwitchInterface()\n");
	My_InitSwitchInterface_Done = true;
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
	while(1){ //this loop waits until switch 1 is pressed
		if(((~Read_GPIO_FrontPanelSwitches() & MASK_KEEP_LOWER_5_BITS) & MASK_CHECK_SW1_INDEPENDANT) == SW1BIT){ //checks for when switch 1 is pressed
			while(1){ //this loop waits for when switch 1 is released
				if(((~Read_GPIO_FrontPanelSwitches() & MASK_KEEP_LOWER_5_BITS) & MASK_CHECK_SW1_INDEPENDANT) != SW1BIT){ //checks for when switch 1 is released
					return; //returns once switch 1 is released
				}
			}
		}
	}
}

//Step through display
void WaitTillSwitch2PressedAndReleased(void){
	while(1){ //this loop waits for switch 2 to be pressed
			if(((~Read_GPIO_FrontPanelSwitches() & MASK_KEEP_LOWER_5_BITS) & MASK_CHECK_SW2_INDEPENDANT) == SW2BIT){ // || (~Read_GPIO_FrontPanelSwitches() & MASK_KEEP_LOWER_5_BITS) ==6 ){ THIS WOULD WORK IF BOTH WHERE PRESSED
				while(1){ //this loop waits for when switch 2 is released
					if(((~Read_GPIO_FrontPanelSwitches() & MASK_KEEP_LOWER_5_BITS) & MASK_CHECK_SW2_INDEPENDANT) != SW2BIT){
						return;
					}
				}

			}

		}
}

//Run display again and again without waiting
void WaitTillSwitch3PressedAndReleased(void){
	while(1){ //this loop waits for switch 3 to be pressed
			if(((~Read_GPIO_FrontPanelSwitches() & MASK_KEEP_LOWER_5_BITS) & MASK_CHECK_SW3_INDEPENDANT) == SW3BIT){
				while(1){ //this loop waits for switch 3 to be pressed
					if(((~Read_GPIO_FrontPanelSwitches() & MASK_KEEP_LOWER_5_BITS) & MASK_CHECK_SW3_INDEPENDANT) != SW3BIT){
						return;
					}
				}
			}
		}
}


unsigned long long int ReadProcessorCyclesCPP(void){

#if 0
	unsigned long long int cyclesValue = *pCYCLES;
#endif

#if 1
	unsigned long long int cyclesValue = ReadProcessorCyclesASM();
#endif

	return cyclesValue;
}








