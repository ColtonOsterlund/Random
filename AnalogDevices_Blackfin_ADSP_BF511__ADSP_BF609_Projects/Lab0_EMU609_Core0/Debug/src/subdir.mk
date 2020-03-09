################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
ASM_SRCS += \
../src/ReadProcessorCyclesASM.asm 

CPP_SRCS += \
../src/Lab0_EMU609_Core0.cpp \
../src/Lab0_Main.cpp 

SRC_OBJS += \
./src/Lab0_EMU609_Core0.doj \
./src/Lab0_Main.doj \
./src/ReadProcessorCyclesASM.doj 

ASM_DEPS += \
./src/ReadProcessorCyclesASM.d 

CPP_DEPS += \
./src/Lab0_EMU609_Core0.d \
./src/Lab0_Main.d 


# Each subdirectory must supply rules for building sources it contributes
src/Lab0_EMU609_Core0.doj: ../src/Lab0_EMU609_Core0.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: CrossCore Blackfin C/C++ Compiler'
	ccblkfn -c -file-attr ProjectName="Lab0_EMU609_Core0" -proc ADSP-BF609 -flags-compiler --no_wrap_diagnostics -si-revision any -g -DCORE0 -D_DEBUG -DADI_MCAPI @includes-4bb24ec862d959bb8dee087ac80e7e50.txt -structs-do-not-overlap -no-const-strings -no-multiline -warn-protos -double-size-32 -decls-strong -cplbs -gnu-style-dependencies -MD -Mo "src/Lab0_EMU609_Core0.d" -c++ -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/Lab0_Main.doj: ../src/Lab0_Main.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: CrossCore Blackfin C/C++ Compiler'
	ccblkfn -c -file-attr ProjectName="Lab0_EMU609_Core0" -proc ADSP-BF609 -flags-compiler --no_wrap_diagnostics -si-revision any -g -DCORE0 -D_DEBUG -DADI_MCAPI @includes-4bb24ec862d959bb8dee087ac80e7e50.txt -structs-do-not-overlap -no-const-strings -no-multiline -warn-protos -double-size-32 -decls-strong -cplbs -gnu-style-dependencies -MD -Mo "src/Lab0_Main.d" -c++ -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/ReadProcessorCyclesASM.doj: ../src/ReadProcessorCyclesASM.asm
	@echo 'Building file: $<'
	@echo 'Invoking: CrossCore Blackfin Assembler'
	easmblkfn -file-attr ProjectName="Lab0_EMU609_Core0" -proc ADSP-BF609 -si-revision any -g -DCORE0 -D_DEBUG -DADI_MCAPI @includes-d72d853b2e7c7efcca9603cf5c51cff2.txt -gnu-style-dependencies -MM -Mo "src/ReadProcessorCyclesASM.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


