/*
 * My_Write_REB_LEDS_CPP.cpp
 *
 *  Created on: Oct 1, 2019
 *      Author: kyle.friedt
 */

#include <blackfin.h>

extern "C" void My_Write_REB_LEDS_CPP(unsigned short int valueToWrite){

	//BITBASH VALUE TO WRITE

	*pREG_PORTF_DATA = valueToWrite; //this writes the argument to the LED - THIS IS BAD, CHANGES BITS WE DO NOT WANT TO CHANGE IN THE REG_PORTF_DATA REGISTER

}



