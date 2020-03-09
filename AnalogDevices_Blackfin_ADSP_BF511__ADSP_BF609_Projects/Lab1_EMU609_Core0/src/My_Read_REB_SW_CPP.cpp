#include <blackfin.h>

extern "C" unsigned short int My_Read_REB_SW_CPP(void){
	//with blackfin cpp extensions you can add a p in front od the peripheral register name to get a pointer to the peripheral register
	//memory location then use standard cpp pointer syntax to get the value

	unsigned short int portPattern = *pREG_PORTF_DATA; //equivalent of *pFIO_FLAG_D on the BF533

	portPattern = portPattern & 0x0f00;

	return portPattern;
}




