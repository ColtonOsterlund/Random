#include <blackfin.h>

.section program;

.global _My_Init_REB_GPIO_ASM; //extern "C" unsigned short int My_Write_REB_LEDS_CPP(unsigned short int valueToWrite){
_My_Init_REB_GPIO_ASM:

#define portPointer_P0 P0
#define portPattern_R0 R0
#define portMask_R1 R1

#define BITS_8_11 0x0F00
#define BITS_12_15 0xF000
#define BITS_0_7 0x00FF

#if 0
	P0.H = hi(REG_PORTF_DATA); P0.L = lo(REG_PORTF_DATA);
	R1 = W[P0] (Z);
	R2 = BITS_0_7;
	R1 = R1 & R2;
	R0 = 0x0000;
	R0 = R0 | R1;
	W[P0] = R0;
	
	P0.H = hi(REG_PORTF_DIR); P0.L = lo(REG_PORTF_DIR);	
	R1 = W[P0] (Z);
	R2 = BITS_0_7;
	R1 = R1 & R2;
	R0 = BITS_12_15 (Z);	
	R0 = R0 | R1;
	W[P0] = R0;
	
	P0.H = hi(REG_PORTF_INEN); P0.L = lo(REG_PORTF_INEN);
	R0 = BITS_8_11 (Z);
	W[P0] = R0;
	
	P0.H = hi(REG_PORTF_POL); P0.L = lo(REG_PORTF_POL);
	R0 = 0x0000 (Z);
	W[P0] = R0;

	ssync;
	
#endif

#if 1
	//SET DATA REGISTER
	R1.L = lo(0x0fff); //WRITE 0s TO ALL OUTPUT BITS
	P0.H = hi(REG_PORTF_DATA); P0.L = lo(REG_PORTF_DATA);
	portPattern_R0 = W[portPointer_P0](Z);
	portPattern_R0 = portPattern_R0 & portMask_R1;
	W[portPointer_P0] = R0.L;
	
	
	//SET DIRECTION REGISTER
	R1.L = lo(0xf000); //SET 1s FOR OUTPUT	
	P0.H = hi(REG_PORTF_DIR); P0.L = lo(REG_PORTF_DIR);
	portPattern_R0 = W[portPointer_P0](Z);
	portPattern_R0 = portPattern_R0 | portMask_R1;	
	W[portPointer_P0] = R0.L;
	
	
	//SET ENABLE REGISTER
	R1.L = lo(0x0f00); //SET 1s FOR INPUT	
	P0.H = hi(REG_PORTF_INEN); P0.L = lo(REG_PORTF_INEN);	
	portPattern_R0 = W[portPointer_P0](Z);
	portPattern_R0 = portPattern_R0 | portMask_R1;	
	W[portPointer_P0] = R0.L;
	
	
	//SET POLARITY REGISTER
	R1.L = lo(0xf0ff); //SET 0s FOR INPUT
	P0.H = hi(REG_PORTF_POL); P0.L = lo(REG_PORTF_POL);
	portPattern_R0 = W[portPointer_P0](Z);
	portPattern_R0 = portPattern_R0 & portMask_R1;
	W[portPointer_P0] = R0.L;
	
	ssync;
#endif
_My_Init_REB_GPIO_ASM.END: 
RTS;