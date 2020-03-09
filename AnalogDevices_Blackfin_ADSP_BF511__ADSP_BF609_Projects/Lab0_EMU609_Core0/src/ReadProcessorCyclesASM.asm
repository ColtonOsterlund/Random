.section L1_data;

.section program;

.global _ReadProcessorCyclesASM;
#define GARBAGE_VALUE 0x0042

_ReadProcessorCyclesASM:
	LINK 20;
#if 0
	R0 = GARBAGE_VALUE;
#else
	R0 = CYCLES;
	R1 = CYCLES2;
#endif

	UNLINK;
_ReadProcessorCyclesASM.END: RTS;