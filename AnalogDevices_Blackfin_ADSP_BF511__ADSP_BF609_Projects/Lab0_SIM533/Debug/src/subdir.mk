################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
ASM_SRCS += \
../src/ReadProcessorCyclesASM.asm 

CPP_SRCS += \
../src/Lab0_Main.cpp \
../src/Lab0_SIM533.cpp 

SRC_OBJS += \
./src/Lab0_Main.doj \
./src/Lab0_SIM533.doj \
./src/ReadProcessorCyclesASM.doj 

ASM_DEPS += \
./src/ReadProcessorCyclesASM.d 

CPP_DEPS += \
./src/Lab0_Main.d \
./src/Lab0_SIM533.d 


# Each subdirectory must supply rules for building sources it contributes
src/Lab0_Main.doj: ../src/Lab0_Main.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: CrossCore Blackfin C/C++ Compiler'
	ccblkfn -c -file-attr ProjectName="Lab0_SIM533" -proc ADSP-BF533 -flags-compiler --no_wrap_diagnostics -si-revision any -g -DCORE0 -D_DEBUG @includes-e9cb80dc62043345058eaeb5110d325a.txt -structs-do-not-overlap -no-const-strings -no-multiline -warn-protos -double-size-32 -decls-strong -cplbs -gnu-style-dependencies -MD -Mo "src/Lab0_Main.d" -c++ -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/Lab0_SIM533.doj: ../src/Lab0_SIM533.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: CrossCore Blackfin C/C++ Compiler'
	ccblkfn -c -file-attr ProjectName="Lab0_SIM533" -proc ADSP-BF533 -flags-compiler --no_wrap_diagnostics -si-revision any -g -DCORE0 -D_DEBUG @includes-e9cb80dc62043345058eaeb5110d325a.txt -structs-do-not-overlap -no-const-strings -no-multiline -warn-protos -double-size-32 -decls-strong -cplbs -gnu-style-dependencies -MD -Mo "src/Lab0_SIM533.d" -c++ -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/ReadProcessorCyclesASM.doj: ../src/ReadProcessorCyclesASM.asm
	@echo 'Building file: $<'
	@echo 'Invoking: CrossCore Blackfin Assembler'
	easmblkfn -file-attr ProjectName="Lab0_SIM533" -proc ADSP-BF533 -si-revision any -g -DCORE0 -D_DEBUG @includes-f7427bf6c72b64c5107f6d9da54a8ab6.txt -gnu-style-dependencies -MM -Mo "src/ReadProcessorCyclesASM.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


