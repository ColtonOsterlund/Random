/*
 * My_Write_REB_SW_ASM.asm
 *
 *  Created on: Nov 19, 2019
 *      Author: colto
 */
 
 #include <blackfin.h>

.section program;

.global _My_Write_REB_SW_ASM; //extern "C" unsigned short int My_Write_REB_LEDS_CPP(unsigned short int valueToWrite){
_My_Write_REB_SW_ASM:
#define portPattern_R0 R0
#define portPointer_P0 P0
#define portMask_R1 R1
#define portMask_R2 R2
#define portPattern_R3 R3

//portPointer_P0.H = hi(REG_PORTF_DATA); portPointer_P0.L = lo(REG_PORTF_DATA); //portPattern = *pREG_PORTF_DATA; - port address is 32 bits, port itself is 16 btis
	P0.H = hi(REG_PORTF_DATA); P0.L = lo(REG_PORTF_DATA);
	

	R1.L = lo(0x0f00); R1.H = hi(0x0000);
	R2.L = lo(0xf0ff); R2.H = hi(0x0000);
	
	//mask portPattern_R0 to contain only bits 8-11 | need W since port is short int (16 bits) (extended with 0s) masked to contain bits 0-11
	//AND R0 and R1
	//AND P0 and R2
	//OR results together
	portPattern_R0 = portPattern_R0 & portMask_R1;
	portPattern_R3 = W[portPointer_P0](Z);
	portPattern_R3 = portPattern_R3 & portMask_R2;
	portPattern_R0 = portPattern_R0 | portPattern_R3;
	
	
	W[portPointer_P0] = R0.L; //do not need to extend with (Z) or (X) since portF is 16 bits. Upper 16 bits of portPattern_R0 do not matter for this same reason


_My_Write_REB_SW_ASM.END: 
RTS;




