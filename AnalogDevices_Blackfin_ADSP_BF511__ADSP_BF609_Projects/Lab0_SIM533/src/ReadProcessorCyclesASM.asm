.section L1_data;

.section program;

.global _ReadProcessorCyclesASM;
#define GARBAGE_VALUE 0x0042
#define RETURN_REGISTER_R0 R0
#define RETURN_REGISTER_R1 R1

_ReadProcessorCyclesASM:
	LINK 20;
#if 0
	RETURN_REGISTER_R0 = GARBAGE_VALUE;
#else
	RETURN_REGISTER_R0 = CYCLES;
	RETURN_REGISTER_R1 = CYCLES2;
#endif

	UNLINK;
_ReadProcessorCyclesASM.END: RTS;