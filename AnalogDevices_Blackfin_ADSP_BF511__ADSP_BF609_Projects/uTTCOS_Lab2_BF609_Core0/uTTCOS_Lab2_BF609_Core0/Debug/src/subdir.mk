################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
ASM_SRCS += \
../src/Idle_WaitForInterrupts_ASM.asm \
../src/My_Init_REB_GPIO_ASM.asm \
../src/My_Read_REB_SW_ASM.asm \
../src/My_Write_REB_LEDS_ASM.asm \
../src/ReadCycles_ASM.asm \
../src/ReadProcessorCyclesASM.asm 

CPP_SRCS += \
../src/FPThread1.cpp \
../src/FPThread2.cpp \
../src/FPThread3.cpp \
../src/FPThread4.cpp \
../src/FPThread5.cpp \
../src/REBThread1.cpp \
../src/REBThread2.cpp \
../src/REBThread3.cpp \
../src/SPI_Display_Functions.cpp \
../src/SetBoard_LED_SPI_SoftConfig_BF609.cpp \
../src/Set_Pinmux_config.cpp \
../src/TempSensorFunctions.cpp \
../src/faultyLED1_Thread.cpp \
../src/uTTCOS_Lab2_BF609_Core0_uTTCOSg2017_main.cpp 

SRC_OBJS += \
./src/FPThread1.doj \
./src/FPThread2.doj \
./src/FPThread3.doj \
./src/FPThread4.doj \
./src/FPThread5.doj \
./src/Idle_WaitForInterrupts_ASM.doj \
./src/My_Init_REB_GPIO_ASM.doj \
./src/My_Read_REB_SW_ASM.doj \
./src/My_Write_REB_LEDS_ASM.doj \
./src/REBThread1.doj \
./src/REBThread2.doj \
./src/REBThread3.doj \
./src/ReadCycles_ASM.doj \
./src/ReadProcessorCyclesASM.doj \
./src/SPI_Display_Functions.doj \
./src/SetBoard_LED_SPI_SoftConfig_BF609.doj \
./src/Set_Pinmux_config.doj \
./src/TempSensorFunctions.doj \
./src/faultyLED1_Thread.doj \
./src/uTTCOS_Lab2_BF609_Core0_uTTCOSg2017_main.doj 

ASM_DEPS += \
./src/Idle_WaitForInterrupts_ASM.d \
./src/My_Init_REB_GPIO_ASM.d \
./src/My_Read_REB_SW_ASM.d \
./src/My_Write_REB_LEDS_ASM.d \
./src/ReadCycles_ASM.d \
./src/ReadProcessorCyclesASM.d 

CPP_DEPS += \
./src/FPThread1.d \
./src/FPThread2.d \
./src/FPThread3.d \
./src/FPThread4.d \
./src/FPThread5.d \
./src/REBThread1.d \
./src/REBThread2.d \
./src/REBThread3.d \
./src/SPI_Display_Functions.d \
./src/SetBoard_LED_SPI_SoftConfig_BF609.d \
./src/Set_Pinmux_config.d \
./src/TempSensorFunctions.d \
./src/faultyLED1_Thread.d \
./src/uTTCOS_Lab2_BF609_Core0_uTTCOSg2017_main.d 


# Each subdirectory must supply rules for building sources it contributes
src/FPThread1.doj: ../src/FPThread1.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: CrossCore Blackfin C/C++ Compiler'
	ccblkfn -c -file-attr ProjectName="uTTCOS_Lab2_BF609_Core0" -proc ADSP-BF609 -flags-compiler --no_wrap_diagnostics -si-revision any -g -DCORE0 -D_DEBUG -DADI_MCAPI @includes-0ceeb8cfebba7afe87ee4cb7c5fef160.txt -structs-do-not-overlap -no-const-strings -no-multiline -warn-protos -double-size-32 -decls-strong -cplbs -gnu-style-dependencies -MD -Mo "src/FPThread1.d" -c++ -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/FPThread2.doj: ../src/FPThread2.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: CrossCore Blackfin C/C++ Compiler'
	ccblkfn -c -file-attr ProjectName="uTTCOS_Lab2_BF609_Core0" -proc ADSP-BF609 -flags-compiler --no_wrap_diagnostics -si-revision any -g -DCORE0 -D_DEBUG -DADI_MCAPI @includes-0ceeb8cfebba7afe87ee4cb7c5fef160.txt -structs-do-not-overlap -no-const-strings -no-multiline -warn-protos -double-size-32 -decls-strong -cplbs -gnu-style-dependencies -MD -Mo "src/FPThread2.d" -c++ -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/FPThread3.doj: ../src/FPThread3.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: CrossCore Blackfin C/C++ Compiler'
	ccblkfn -c -file-attr ProjectName="uTTCOS_Lab2_BF609_Core0" -proc ADSP-BF609 -flags-compiler --no_wrap_diagnostics -si-revision any -g -DCORE0 -D_DEBUG -DADI_MCAPI @includes-0ceeb8cfebba7afe87ee4cb7c5fef160.txt -structs-do-not-overlap -no-const-strings -no-multiline -warn-protos -double-size-32 -decls-strong -cplbs -gnu-style-dependencies -MD -Mo "src/FPThread3.d" -c++ -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/FPThread4.doj: ../src/FPThread4.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: CrossCore Blackfin C/C++ Compiler'
	ccblkfn -c -file-attr ProjectName="uTTCOS_Lab2_BF609_Core0" -proc ADSP-BF609 -flags-compiler --no_wrap_diagnostics -si-revision any -g -DCORE0 -D_DEBUG -DADI_MCAPI @includes-0ceeb8cfebba7afe87ee4cb7c5fef160.txt -structs-do-not-overlap -no-const-strings -no-multiline -warn-protos -double-size-32 -decls-strong -cplbs -gnu-style-dependencies -MD -Mo "src/FPThread4.d" -c++ -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/FPThread5.doj: ../src/FPThread5.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: CrossCore Blackfin C/C++ Compiler'
	ccblkfn -c -file-attr ProjectName="uTTCOS_Lab2_BF609_Core0" -proc ADSP-BF609 -flags-compiler --no_wrap_diagnostics -si-revision any -g -DCORE0 -D_DEBUG -DADI_MCAPI @includes-0ceeb8cfebba7afe87ee4cb7c5fef160.txt -structs-do-not-overlap -no-const-strings -no-multiline -warn-protos -double-size-32 -decls-strong -cplbs -gnu-style-dependencies -MD -Mo "src/FPThread5.d" -c++ -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/Idle_WaitForInterrupts_ASM.doj: ../src/Idle_WaitForInterrupts_ASM.asm
	@echo 'Building file: $<'
	@echo 'Invoking: CrossCore Blackfin Assembler'
	easmblkfn -file-attr ProjectName="uTTCOS_Lab2_BF609_Core0" -proc ADSP-BF609 -si-revision any -g -DCORE0 -D_DEBUG -DADI_MCAPI @includes-d8743f4873ef9e7ac31056e55570e335.txt -gnu-style-dependencies -MM -Mo "src/Idle_WaitForInterrupts_ASM.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/My_Init_REB_GPIO_ASM.doj: ../src/My_Init_REB_GPIO_ASM.asm
	@echo 'Building file: $<'
	@echo 'Invoking: CrossCore Blackfin Assembler'
	easmblkfn -file-attr ProjectName="uTTCOS_Lab2_BF609_Core0" -proc ADSP-BF609 -si-revision any -g -DCORE0 -D_DEBUG -DADI_MCAPI @includes-d8743f4873ef9e7ac31056e55570e335.txt -gnu-style-dependencies -MM -Mo "src/My_Init_REB_GPIO_ASM.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/My_Read_REB_SW_ASM.doj: ../src/My_Read_REB_SW_ASM.asm
	@echo 'Building file: $<'
	@echo 'Invoking: CrossCore Blackfin Assembler'
	easmblkfn -file-attr ProjectName="uTTCOS_Lab2_BF609_Core0" -proc ADSP-BF609 -si-revision any -g -DCORE0 -D_DEBUG -DADI_MCAPI @includes-d8743f4873ef9e7ac31056e55570e335.txt -gnu-style-dependencies -MM -Mo "src/My_Read_REB_SW_ASM.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/My_Write_REB_LEDS_ASM.doj: ../src/My_Write_REB_LEDS_ASM.asm
	@echo 'Building file: $<'
	@echo 'Invoking: CrossCore Blackfin Assembler'
	easmblkfn -file-attr ProjectName="uTTCOS_Lab2_BF609_Core0" -proc ADSP-BF609 -si-revision any -g -DCORE0 -D_DEBUG -DADI_MCAPI @includes-d8743f4873ef9e7ac31056e55570e335.txt -gnu-style-dependencies -MM -Mo "src/My_Write_REB_LEDS_ASM.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/REBThread1.doj: ../src/REBThread1.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: CrossCore Blackfin C/C++ Compiler'
	ccblkfn -c -file-attr ProjectName="uTTCOS_Lab2_BF609_Core0" -proc ADSP-BF609 -flags-compiler --no_wrap_diagnostics -si-revision any -g -DCORE0 -D_DEBUG -DADI_MCAPI @includes-0ceeb8cfebba7afe87ee4cb7c5fef160.txt -structs-do-not-overlap -no-const-strings -no-multiline -warn-protos -double-size-32 -decls-strong -cplbs -gnu-style-dependencies -MD -Mo "src/REBThread1.d" -c++ -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/REBThread2.doj: ../src/REBThread2.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: CrossCore Blackfin C/C++ Compiler'
	ccblkfn -c -file-attr ProjectName="uTTCOS_Lab2_BF609_Core0" -proc ADSP-BF609 -flags-compiler --no_wrap_diagnostics -si-revision any -g -DCORE0 -D_DEBUG -DADI_MCAPI @includes-0ceeb8cfebba7afe87ee4cb7c5fef160.txt -structs-do-not-overlap -no-const-strings -no-multiline -warn-protos -double-size-32 -decls-strong -cplbs -gnu-style-dependencies -MD -Mo "src/REBThread2.d" -c++ -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/REBThread3.doj: ../src/REBThread3.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: CrossCore Blackfin C/C++ Compiler'
	ccblkfn -c -file-attr ProjectName="uTTCOS_Lab2_BF609_Core0" -proc ADSP-BF609 -flags-compiler --no_wrap_diagnostics -si-revision any -g -DCORE0 -D_DEBUG -DADI_MCAPI @includes-0ceeb8cfebba7afe87ee4cb7c5fef160.txt -structs-do-not-overlap -no-const-strings -no-multiline -warn-protos -double-size-32 -decls-strong -cplbs -gnu-style-dependencies -MD -Mo "src/REBThread3.d" -c++ -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/ReadCycles_ASM.doj: ../src/ReadCycles_ASM.asm
	@echo 'Building file: $<'
	@echo 'Invoking: CrossCore Blackfin Assembler'
	easmblkfn -file-attr ProjectName="uTTCOS_Lab2_BF609_Core0" -proc ADSP-BF609 -si-revision any -g -DCORE0 -D_DEBUG -DADI_MCAPI @includes-d8743f4873ef9e7ac31056e55570e335.txt -gnu-style-dependencies -MM -Mo "src/ReadCycles_ASM.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/ReadProcessorCyclesASM.doj: ../src/ReadProcessorCyclesASM.asm
	@echo 'Building file: $<'
	@echo 'Invoking: CrossCore Blackfin Assembler'
	easmblkfn -file-attr ProjectName="uTTCOS_Lab2_BF609_Core0" -proc ADSP-BF609 -si-revision any -g -DCORE0 -D_DEBUG -DADI_MCAPI @includes-d8743f4873ef9e7ac31056e55570e335.txt -gnu-style-dependencies -MM -Mo "src/ReadProcessorCyclesASM.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/SPI_Display_Functions.doj: ../src/SPI_Display_Functions.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: CrossCore Blackfin C/C++ Compiler'
	ccblkfn -c -file-attr ProjectName="uTTCOS_Lab2_BF609_Core0" -proc ADSP-BF609 -flags-compiler --no_wrap_diagnostics -si-revision any -g -DCORE0 -D_DEBUG -DADI_MCAPI @includes-0ceeb8cfebba7afe87ee4cb7c5fef160.txt -structs-do-not-overlap -no-const-strings -no-multiline -warn-protos -double-size-32 -decls-strong -cplbs -gnu-style-dependencies -MD -Mo "src/SPI_Display_Functions.d" -c++ -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/SetBoard_LED_SPI_SoftConfig_BF609.doj: ../src/SetBoard_LED_SPI_SoftConfig_BF609.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: CrossCore Blackfin C/C++ Compiler'
	ccblkfn -c -file-attr ProjectName="uTTCOS_Lab2_BF609_Core0" -proc ADSP-BF609 -flags-compiler --no_wrap_diagnostics -si-revision any -g -DCORE0 -D_DEBUG -DADI_MCAPI @includes-0ceeb8cfebba7afe87ee4cb7c5fef160.txt -structs-do-not-overlap -no-const-strings -no-multiline -warn-protos -double-size-32 -decls-strong -cplbs -gnu-style-dependencies -MD -Mo "src/SetBoard_LED_SPI_SoftConfig_BF609.d" -c++ -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/Set_Pinmux_config.doj: ../src/Set_Pinmux_config.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: CrossCore Blackfin C/C++ Compiler'
	ccblkfn -c -file-attr ProjectName="uTTCOS_Lab2_BF609_Core0" -proc ADSP-BF609 -flags-compiler --no_wrap_diagnostics -si-revision any -g -DCORE0 -D_DEBUG -DADI_MCAPI @includes-0ceeb8cfebba7afe87ee4cb7c5fef160.txt -structs-do-not-overlap -no-const-strings -no-multiline -warn-protos -double-size-32 -decls-strong -cplbs -gnu-style-dependencies -MD -Mo "src/Set_Pinmux_config.d" -c++ -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/TempSensorFunctions.doj: ../src/TempSensorFunctions.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: CrossCore Blackfin C/C++ Compiler'
	ccblkfn -c -file-attr ProjectName="uTTCOS_Lab2_BF609_Core0" -proc ADSP-BF609 -flags-compiler --no_wrap_diagnostics -si-revision any -g -DCORE0 -D_DEBUG -DADI_MCAPI @includes-0ceeb8cfebba7afe87ee4cb7c5fef160.txt -structs-do-not-overlap -no-const-strings -no-multiline -warn-protos -double-size-32 -decls-strong -cplbs -gnu-style-dependencies -MD -Mo "src/TempSensorFunctions.d" -c++ -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/faultyLED1_Thread.doj: ../src/faultyLED1_Thread.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: CrossCore Blackfin C/C++ Compiler'
	ccblkfn -c -file-attr ProjectName="uTTCOS_Lab2_BF609_Core0" -proc ADSP-BF609 -flags-compiler --no_wrap_diagnostics -si-revision any -g -DCORE0 -D_DEBUG -DADI_MCAPI @includes-0ceeb8cfebba7afe87ee4cb7c5fef160.txt -structs-do-not-overlap -no-const-strings -no-multiline -warn-protos -double-size-32 -decls-strong -cplbs -gnu-style-dependencies -MD -Mo "src/faultyLED1_Thread.d" -c++ -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/uTTCOS_Lab2_BF609_Core0_uTTCOSg2017_main.doj: ../src/uTTCOS_Lab2_BF609_Core0_uTTCOSg2017_main.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: CrossCore Blackfin C/C++ Compiler'
	ccblkfn -c -file-attr ProjectName="uTTCOS_Lab2_BF609_Core0" -proc ADSP-BF609 -flags-compiler --no_wrap_diagnostics -si-revision any -g -DCORE0 -D_DEBUG -DADI_MCAPI @includes-0ceeb8cfebba7afe87ee4cb7c5fef160.txt -structs-do-not-overlap -no-const-strings -no-multiline -warn-protos -double-size-32 -decls-strong -cplbs -gnu-style-dependencies -MD -Mo "src/uTTCOS_Lab2_BF609_Core0_uTTCOSg2017_main.d" -c++ -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


