#include <blackfin.h>

.section program;

.global _My_Read_REB_SW_ASM; //extern "C" unsigned short int My_Read_REB_Switches_CPP(void){
_My_Read_REB_SW_ASM:

#define portPattern_R0 R0
#define portPointer_P0 P0
#define portMask_R1 R1

P0.H = hi(REG_PORTF_DATA); P0.L = lo(REG_PORTF_DATA); //unsigned short int portPattern = *pREG_PORTF_DATA;

portPattern_R0 = W[portPointer_P0](Z);

portMask_R1 = 0x0f00;
portPattern_R0 = portPattern_R0 & portMask_R1; //portPattern = portPattern & 0x0f00;

_My_Read_REB_SW_ASM.END: //return portPattern;
RTS;							//}


