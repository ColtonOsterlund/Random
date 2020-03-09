################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
ASM_SRCS += \
../src/My_Init_REB_GPIO_ASM.asm \
../src/My_Read_REB_SW_ASM.asm \
../src/My_Write_REB_LEDS_ASM.asm \
../src/ReadProcessorCyclesASM.asm 

CPP_SRCS += \
../src/Lab1_EMU609_Core0.cpp \
../src/Lab1_Main.cpp \
../src/My_Read_REB_SW_CPP.cpp \
../src/My_Write_REB_LEDS_CPP.cpp 

SRC_OBJS += \
./src/Lab1_EMU609_Core0.doj \
./src/Lab1_Main.doj \
./src/My_Init_REB_GPIO_ASM.doj \
./src/My_Read_REB_SW_ASM.doj \
./src/My_Read_REB_SW_CPP.doj \
./src/My_Write_REB_LEDS_ASM.doj \
./src/My_Write_REB_LEDS_CPP.doj \
./src/ReadProcessorCyclesASM.doj 

ASM_DEPS += \
./src/My_Init_REB_GPIO_ASM.d \
./src/My_Read_REB_SW_ASM.d \
./src/My_Write_REB_LEDS_ASM.d \
./src/ReadProcessorCyclesASM.d 

CPP_DEPS += \
./src/Lab1_EMU609_Core0.d \
./src/Lab1_Main.d \
./src/My_Read_REB_SW_CPP.d \
./src/My_Write_REB_LEDS_CPP.d 


# Each subdirectory must supply rules for building sources it contributes
src/Lab1_EMU609_Core0.doj: ../src/Lab1_EMU609_Core0.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: CrossCore Blackfin C/C++ Compiler'
	ccblkfn -c -file-attr ProjectName="Lab1_EMU609_Core0" -proc ADSP-BF609 -flags-compiler --no_wrap_diagnostics -si-revision any -g -DCORE0 -D_DEBUG -DADI_MCAPI @includes-254bd50914cad7ce9ae9c729bea2aede.txt -structs-do-not-overlap -no-const-strings -no-multiline -warn-protos -double-size-32 -decls-strong -cplbs -gnu-style-dependencies -MD -Mo "src/Lab1_EMU609_Core0.d" -c++ -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/Lab1_Main.doj: ../src/Lab1_Main.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: CrossCore Blackfin C/C++ Compiler'
	ccblkfn -c -file-attr ProjectName="Lab1_EMU609_Core0" -proc ADSP-BF609 -flags-compiler --no_wrap_diagnostics -si-revision any -g -DCORE0 -D_DEBUG -DADI_MCAPI @includes-254bd50914cad7ce9ae9c729bea2aede.txt -structs-do-not-overlap -no-const-strings -no-multiline -warn-protos -double-size-32 -decls-strong -cplbs -gnu-style-dependencies -MD -Mo "src/Lab1_Main.d" -c++ -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/My_Init_REB_GPIO_ASM.doj: ../src/My_Init_REB_GPIO_ASM.asm
	@echo 'Building file: $<'
	@echo 'Invoking: CrossCore Blackfin Assembler'
	easmblkfn -file-attr ProjectName="Lab1_EMU609_Core0" -proc ADSP-BF609 -si-revision any -g -DCORE0 -D_DEBUG -DADI_MCAPI @includes-68e9f6bf72bbfa45b9332b3ac127b7b1.txt -gnu-style-dependencies -MM -Mo "src/My_Init_REB_GPIO_ASM.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/My_Read_REB_SW_ASM.doj: ../src/My_Read_REB_SW_ASM.asm
	@echo 'Building file: $<'
	@echo 'Invoking: CrossCore Blackfin Assembler'
	easmblkfn -file-attr ProjectName="Lab1_EMU609_Core0" -proc ADSP-BF609 -si-revision any -g -DCORE0 -D_DEBUG -DADI_MCAPI @includes-68e9f6bf72bbfa45b9332b3ac127b7b1.txt -gnu-style-dependencies -MM -Mo "src/My_Read_REB_SW_ASM.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/My_Read_REB_SW_CPP.doj: ../src/My_Read_REB_SW_CPP.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: CrossCore Blackfin C/C++ Compiler'
	ccblkfn -c -file-attr ProjectName="Lab1_EMU609_Core0" -proc ADSP-BF609 -flags-compiler --no_wrap_diagnostics -si-revision any -g -DCORE0 -D_DEBUG -DADI_MCAPI @includes-254bd50914cad7ce9ae9c729bea2aede.txt -structs-do-not-overlap -no-const-strings -no-multiline -warn-protos -double-size-32 -decls-strong -cplbs -gnu-style-dependencies -MD -Mo "src/My_Read_REB_SW_CPP.d" -c++ -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/My_Write_REB_LEDS_ASM.doj: ../src/My_Write_REB_LEDS_ASM.asm
	@echo 'Building file: $<'
	@echo 'Invoking: CrossCore Blackfin Assembler'
	easmblkfn -file-attr ProjectName="Lab1_EMU609_Core0" -proc ADSP-BF609 -si-revision any -g -DCORE0 -D_DEBUG -DADI_MCAPI @includes-68e9f6bf72bbfa45b9332b3ac127b7b1.txt -gnu-style-dependencies -MM -Mo "src/My_Write_REB_LEDS_ASM.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/My_Write_REB_LEDS_CPP.doj: ../src/My_Write_REB_LEDS_CPP.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: CrossCore Blackfin C/C++ Compiler'
	ccblkfn -c -file-attr ProjectName="Lab1_EMU609_Core0" -proc ADSP-BF609 -flags-compiler --no_wrap_diagnostics -si-revision any -g -DCORE0 -D_DEBUG -DADI_MCAPI @includes-254bd50914cad7ce9ae9c729bea2aede.txt -structs-do-not-overlap -no-const-strings -no-multiline -warn-protos -double-size-32 -decls-strong -cplbs -gnu-style-dependencies -MD -Mo "src/My_Write_REB_LEDS_CPP.d" -c++ -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/ReadProcessorCyclesASM.doj: ../src/ReadProcessorCyclesASM.asm
	@echo 'Building file: $<'
	@echo 'Invoking: CrossCore Blackfin Assembler'
	easmblkfn -file-attr ProjectName="Lab1_EMU609_Core0" -proc ADSP-BF609 -si-revision any -g -DCORE0 -D_DEBUG -DADI_MCAPI @includes-68e9f6bf72bbfa45b9332b3ac127b7b1.txt -gnu-style-dependencies -MM -Mo "src/ReadProcessorCyclesASM.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


