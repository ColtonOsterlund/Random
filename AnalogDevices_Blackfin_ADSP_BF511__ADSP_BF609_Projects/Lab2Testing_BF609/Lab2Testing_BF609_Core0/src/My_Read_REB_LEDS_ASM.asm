/*
 * My_Read_REB_LEDS.asm
 *
 *  Created on: Nov 19, 2019
 *      Author: colto
 */

/*
 * My_Read_REB_LEDS_ASM.asm
 *
 *  Created on: Nov 19, 2019
 *      Author: kfrie
 */
#include <blackfin.h>
.section program;
.global _My_Read_REB_LEDS_ASM; //extern "C" unsigned short int My_Read_REB_Switches_CPP(void){
_My_Read_REB_LEDS_ASM:
#define portPattern_R0 R0
#define portPointer_P0 P0
#define portMask_R1 R1
P0.H = hi(REG_PORTF_DATA); P0.L = lo(REG_PORTF_DATA); //unsigned short int portPattern = *pREG_PORTF_DATA;
portPattern_R0 = W[portPointer_P0](Z);
R1.L = lo(0xf000); R1.H = hi(0xf000);//no mask just send what the values are to make sure the old ones aren't changed. 
portPattern_R0 = portPattern_R0; //& portMask_R1; //portPattern = portPattern & 0x0f00;
_My_Read_REB_LEDS_ASM.END: //return portPattern;
RTS;							//}



