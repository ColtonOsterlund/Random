/*****************************************************************************
 * CoffeepotAssignment.cpp
 *****************************************************************************/

#include <sys/platform.h>
#include "adi_initialize.h"
#include "CoffeepotAssignment.h"

/** 
 * If you want to use command program arguments, then place them in the following string. 
 */
char __argv_string[] = "";

int main(int argc, char *argv[])
{
	adi_initComponents();
	
	Coffee_Pot_Assignment1_Main();

	return 0;
}

