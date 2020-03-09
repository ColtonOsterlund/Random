################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
ASM_SRCS += \
../src/Demonstrate_LED_Control_ASM.asm 

CPP_SRCS += \
../src/CoffeepotAssignmentMultiplePots_uTTCOSg2017_main.cpp \
../src/faultyLED1_Thread.cpp 

SRC_OBJS += \
./src/CoffeepotAssignmentMultiplePots_uTTCOSg2017_main.doj \
./src/Demonstrate_LED_Control_ASM.doj \
./src/faultyLED1_Thread.doj 

ASM_DEPS += \
./src/Demonstrate_LED_Control_ASM.d 

CPP_DEPS += \
./src/CoffeepotAssignmentMultiplePots_uTTCOSg2017_main.d \
./src/faultyLED1_Thread.d 


# Each subdirectory must supply rules for building sources it contributes
src/CoffeepotAssignmentMultiplePots_uTTCOSg2017_main.doj: ../src/CoffeepotAssignmentMultiplePots_uTTCOSg2017_main.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: CrossCore Blackfin C/C++ Compiler'
	ccblkfn -c -file-attr ProjectName="CoffeepotAssignmentMultiplePots" -proc ADSP-BF609 -flags-compiler --no_wrap_diagnostics -si-revision any -g -D_DEBUG -DCORE0 @includes-a551f75db827ed3da04033ed8abefefb.txt -structs-do-not-overlap -no-const-strings -no-multiline -warn-protos -double-size-32 -decls-strong -cplbs -gnu-style-dependencies -MD -Mo "src/CoffeepotAssignmentMultiplePots_uTTCOSg2017_main.d" -c++ -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/Demonstrate_LED_Control_ASM.doj: ../src/Demonstrate_LED_Control_ASM.asm
	@echo 'Building file: $<'
	@echo 'Invoking: CrossCore Blackfin Assembler'
	easmblkfn -file-attr ProjectName="CoffeepotAssignmentMultiplePots" -proc ADSP-BF609 -si-revision any -g -D_DEBUG -DCORE0 @includes-a98f4565a5dc3d6700a2ceda4a6c069a.txt -gnu-style-dependencies -MM -Mo "src/Demonstrate_LED_Control_ASM.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/faultyLED1_Thread.doj: ../src/faultyLED1_Thread.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: CrossCore Blackfin C/C++ Compiler'
	ccblkfn -c -file-attr ProjectName="CoffeepotAssignmentMultiplePots" -proc ADSP-BF609 -flags-compiler --no_wrap_diagnostics -si-revision any -g -D_DEBUG -DCORE0 @includes-a551f75db827ed3da04033ed8abefefb.txt -structs-do-not-overlap -no-const-strings -no-multiline -warn-protos -double-size-32 -decls-strong -cplbs -gnu-style-dependencies -MD -Mo "src/faultyLED1_Thread.d" -c++ -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


