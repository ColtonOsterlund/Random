################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
ASM_SRCS += \
../src/Idle_WaitForInterrupts_ASM.asm \
../src/ReadCycles_ASM.asm 

CPP_SRCS += \
../src/SPITest_uTTCOS_Core0_uTTCOSg2017_main.cpp \
../src/faultyLED1_Thread.cpp 

SRC_OBJS += \
./src/Idle_WaitForInterrupts_ASM.doj \
./src/ReadCycles_ASM.doj \
./src/SPITest_uTTCOS_Core0_uTTCOSg2017_main.doj \
./src/faultyLED1_Thread.doj 

ASM_DEPS += \
./src/Idle_WaitForInterrupts_ASM.d \
./src/ReadCycles_ASM.d 

CPP_DEPS += \
./src/SPITest_uTTCOS_Core0_uTTCOSg2017_main.d \
./src/faultyLED1_Thread.d 


# Each subdirectory must supply rules for building sources it contributes
src/Idle_WaitForInterrupts_ASM.doj: ../src/Idle_WaitForInterrupts_ASM.asm
	@echo 'Building file: $<'
	@echo 'Invoking: CrossCore Blackfin Assembler'
	easmblkfn -file-attr ProjectName="SPITest_uTTCOS_Core0" -proc ADSP-BF609 -si-revision any -g -DCORE0 -D_DEBUG -DADI_MCAPI @includes-43a0840c456fcb85680e8ad18fa053fe.txt -gnu-style-dependencies -MM -Mo "src/Idle_WaitForInterrupts_ASM.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/ReadCycles_ASM.doj: ../src/ReadCycles_ASM.asm
	@echo 'Building file: $<'
	@echo 'Invoking: CrossCore Blackfin Assembler'
	easmblkfn -file-attr ProjectName="SPITest_uTTCOS_Core0" -proc ADSP-BF609 -si-revision any -g -DCORE0 -D_DEBUG -DADI_MCAPI @includes-43a0840c456fcb85680e8ad18fa053fe.txt -gnu-style-dependencies -MM -Mo "src/ReadCycles_ASM.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/SPITest_uTTCOS_Core0_uTTCOSg2017_main.doj: ../src/SPITest_uTTCOS_Core0_uTTCOSg2017_main.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: CrossCore Blackfin C/C++ Compiler'
	ccblkfn -c -file-attr ProjectName="SPITest_uTTCOS_Core0" -proc ADSP-BF609 -flags-compiler --no_wrap_diagnostics -si-revision any -g -DCORE0 -D_DEBUG -DADI_MCAPI @includes-0f135b64f8ee7d39b7d43a184e3da33b.txt -structs-do-not-overlap -no-const-strings -no-multiline -warn-protos -double-size-32 -decls-strong -cplbs -gnu-style-dependencies -MD -Mo "src/SPITest_uTTCOS_Core0_uTTCOSg2017_main.d" -c++ -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/faultyLED1_Thread.doj: ../src/faultyLED1_Thread.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: CrossCore Blackfin C/C++ Compiler'
	ccblkfn -c -file-attr ProjectName="SPITest_uTTCOS_Core0" -proc ADSP-BF609 -flags-compiler --no_wrap_diagnostics -si-revision any -g -DCORE0 -D_DEBUG -DADI_MCAPI @includes-0f135b64f8ee7d39b7d43a184e3da33b.txt -structs-do-not-overlap -no-const-strings -no-multiline -warn-protos -double-size-32 -decls-strong -cplbs -gnu-style-dependencies -MD -Mo "src/faultyLED1_Thread.d" -c++ -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


