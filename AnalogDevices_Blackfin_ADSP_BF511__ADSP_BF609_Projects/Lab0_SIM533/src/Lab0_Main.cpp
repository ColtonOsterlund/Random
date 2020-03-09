/*****************************************************************************
 * Lab0_SIM533.cpp
 *****************************************************************************/

#include <sys/platform.h>
#include "adi_initialize.h"
#include "Lab0_SIM533.h"

/**
 * If you want to use command program arguments, then place them in the following string.
 */
char __argv_string[] = "";

int main(int argc, char *argv[])
{
	/**
	 * Initialize managed drivers and/or services that have been added to
	 * the project.
	 * @return zero on success
	 */
	adi_initComponents();

	/* Begin adding your custom code here */

#ifdef __ADSPBF533__
	printf("Starting Lab 0 for BF533\n");
	Start_Lab0();
#endif

#ifdef __ADSPBF609__
	printf("Starting Lab 0 for BF609\n");
	Start_Lab0();
#endif

#ifdef __EiE_ARM__
	printf("Starting Lab 0 for BF533\n");
	Start_Lab0();
#endif

#ifdef __Arduino__
	printf("Starting Lab 0 for BF533\n");
	Start_Lab0();
#endif

	printf("Finished Lab 0\n");
	return 0;
}
