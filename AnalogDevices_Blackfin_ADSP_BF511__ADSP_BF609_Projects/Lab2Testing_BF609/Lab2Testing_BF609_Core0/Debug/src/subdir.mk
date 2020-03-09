################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
ASM_SRCS += \
../src/My_Init_REB_GPIO_ASM.asm \
../src/My_Read_REB_LEDS_ASM.asm \
../src/My_Read_REB_SW_ASM.asm \
../src/My_Write_REB_LEDS_ASM.asm \
../src/My_Write_REB_SW_ASM.asm 

CPP_SRCS += \
../src/FPThread1.cpp \
../src/FPThread2.cpp \
../src/FPThread3.cpp \
../src/FPThread4.cpp \
../src/FPThread5.cpp \
../src/Lab2Testing_BF609_Core0_EUNIT2017_main.cpp \
../src/MainTestingFile.cpp \
../src/REBThread1.cpp \
../src/REBThread2.cpp \
../src/REBThread3.cpp 

SRC_OBJS += \
./src/FPThread1.doj \
./src/FPThread2.doj \
./src/FPThread3.doj \
./src/FPThread4.doj \
./src/FPThread5.doj \
./src/Lab2Testing_BF609_Core0_EUNIT2017_main.doj \
./src/MainTestingFile.doj \
./src/My_Init_REB_GPIO_ASM.doj \
./src/My_Read_REB_LEDS_ASM.doj \
./src/My_Read_REB_SW_ASM.doj \
./src/My_Write_REB_LEDS_ASM.doj \
./src/My_Write_REB_SW_ASM.doj \
./src/REBThread1.doj \
./src/REBThread2.doj \
./src/REBThread3.doj 

ASM_DEPS += \
./src/My_Init_REB_GPIO_ASM.d \
./src/My_Read_REB_LEDS_ASM.d \
./src/My_Read_REB_SW_ASM.d \
./src/My_Write_REB_LEDS_ASM.d \
./src/My_Write_REB_SW_ASM.d 

CPP_DEPS += \
./src/FPThread1.d \
./src/FPThread2.d \
./src/FPThread3.d \
./src/FPThread4.d \
./src/FPThread5.d \
./src/Lab2Testing_BF609_Core0_EUNIT2017_main.d \
./src/MainTestingFile.d \
./src/REBThread1.d \
./src/REBThread2.d \
./src/REBThread3.d 


# Each subdirectory must supply rules for building sources it contributes
src/FPThread1.doj: ../src/FPThread1.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: CrossCore Blackfin C/C++ Compiler'
	ccblkfn -c -file-attr ProjectName="Lab2Testing_BF609_Core0" -proc ADSP-BF609 -flags-compiler --no_wrap_diagnostics -si-revision any -g -DCORE0 -D_DEBUG -DADI_MCAPI @includes-559323d4cc810c6974ee924577712455.txt -structs-do-not-overlap -no-const-strings -no-multiline -warn-protos -double-size-32 -decls-strong -cplbs -gnu-style-dependencies -MD -Mo "src/FPThread1.d" -c++ -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/FPThread2.doj: ../src/FPThread2.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: CrossCore Blackfin C/C++ Compiler'
	ccblkfn -c -file-attr ProjectName="Lab2Testing_BF609_Core0" -proc ADSP-BF609 -flags-compiler --no_wrap_diagnostics -si-revision any -g -DCORE0 -D_DEBUG -DADI_MCAPI @includes-559323d4cc810c6974ee924577712455.txt -structs-do-not-overlap -no-const-strings -no-multiline -warn-protos -double-size-32 -decls-strong -cplbs -gnu-style-dependencies -MD -Mo "src/FPThread2.d" -c++ -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/FPThread3.doj: ../src/FPThread3.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: CrossCore Blackfin C/C++ Compiler'
	ccblkfn -c -file-attr ProjectName="Lab2Testing_BF609_Core0" -proc ADSP-BF609 -flags-compiler --no_wrap_diagnostics -si-revision any -g -DCORE0 -D_DEBUG -DADI_MCAPI @includes-559323d4cc810c6974ee924577712455.txt -structs-do-not-overlap -no-const-strings -no-multiline -warn-protos -double-size-32 -decls-strong -cplbs -gnu-style-dependencies -MD -Mo "src/FPThread3.d" -c++ -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/FPThread4.doj: ../src/FPThread4.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: CrossCore Blackfin C/C++ Compiler'
	ccblkfn -c -file-attr ProjectName="Lab2Testing_BF609_Core0" -proc ADSP-BF609 -flags-compiler --no_wrap_diagnostics -si-revision any -g -DCORE0 -D_DEBUG -DADI_MCAPI @includes-559323d4cc810c6974ee924577712455.txt -structs-do-not-overlap -no-const-strings -no-multiline -warn-protos -double-size-32 -decls-strong -cplbs -gnu-style-dependencies -MD -Mo "src/FPThread4.d" -c++ -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/FPThread5.doj: ../src/FPThread5.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: CrossCore Blackfin C/C++ Compiler'
	ccblkfn -c -file-attr ProjectName="Lab2Testing_BF609_Core0" -proc ADSP-BF609 -flags-compiler --no_wrap_diagnostics -si-revision any -g -DCORE0 -D_DEBUG -DADI_MCAPI @includes-559323d4cc810c6974ee924577712455.txt -structs-do-not-overlap -no-const-strings -no-multiline -warn-protos -double-size-32 -decls-strong -cplbs -gnu-style-dependencies -MD -Mo "src/FPThread5.d" -c++ -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/Lab2Testing_BF609_Core0_EUNIT2017_main.doj: ../src/Lab2Testing_BF609_Core0_EUNIT2017_main.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: CrossCore Blackfin C/C++ Compiler'
	ccblkfn -c -file-attr ProjectName="Lab2Testing_BF609_Core0" -proc ADSP-BF609 -flags-compiler --no_wrap_diagnostics -si-revision any -g -DCORE0 -D_DEBUG -DADI_MCAPI @includes-559323d4cc810c6974ee924577712455.txt -structs-do-not-overlap -no-const-strings -no-multiline -warn-protos -double-size-32 -decls-strong -cplbs -gnu-style-dependencies -MD -Mo "src/Lab2Testing_BF609_Core0_EUNIT2017_main.d" -c++ -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/MainTestingFile.doj: ../src/MainTestingFile.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: CrossCore Blackfin C/C++ Compiler'
	ccblkfn -c -file-attr ProjectName="Lab2Testing_BF609_Core0" -proc ADSP-BF609 -flags-compiler --no_wrap_diagnostics -si-revision any -g -DCORE0 -D_DEBUG -DADI_MCAPI @includes-559323d4cc810c6974ee924577712455.txt -structs-do-not-overlap -no-const-strings -no-multiline -warn-protos -double-size-32 -decls-strong -cplbs -gnu-style-dependencies -MD -Mo "src/MainTestingFile.d" -c++ -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/My_Init_REB_GPIO_ASM.doj: ../src/My_Init_REB_GPIO_ASM.asm
	@echo 'Building file: $<'
	@echo 'Invoking: CrossCore Blackfin Assembler'
	easmblkfn -file-attr ProjectName="Lab2Testing_BF609_Core0" -proc ADSP-BF609 -si-revision any -g -DCORE0 -D_DEBUG -DADI_MCAPI @includes-c376cb5fef6ea09e49524f58bf522bb3.txt -gnu-style-dependencies -MM -Mo "src/My_Init_REB_GPIO_ASM.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/My_Read_REB_LEDS_ASM.doj: ../src/My_Read_REB_LEDS_ASM.asm
	@echo 'Building file: $<'
	@echo 'Invoking: CrossCore Blackfin Assembler'
	easmblkfn -file-attr ProjectName="Lab2Testing_BF609_Core0" -proc ADSP-BF609 -si-revision any -g -DCORE0 -D_DEBUG -DADI_MCAPI @includes-c376cb5fef6ea09e49524f58bf522bb3.txt -gnu-style-dependencies -MM -Mo "src/My_Read_REB_LEDS_ASM.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/My_Read_REB_SW_ASM.doj: ../src/My_Read_REB_SW_ASM.asm
	@echo 'Building file: $<'
	@echo 'Invoking: CrossCore Blackfin Assembler'
	easmblkfn -file-attr ProjectName="Lab2Testing_BF609_Core0" -proc ADSP-BF609 -si-revision any -g -DCORE0 -D_DEBUG -DADI_MCAPI @includes-c376cb5fef6ea09e49524f58bf522bb3.txt -gnu-style-dependencies -MM -Mo "src/My_Read_REB_SW_ASM.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/My_Write_REB_LEDS_ASM.doj: ../src/My_Write_REB_LEDS_ASM.asm
	@echo 'Building file: $<'
	@echo 'Invoking: CrossCore Blackfin Assembler'
	easmblkfn -file-attr ProjectName="Lab2Testing_BF609_Core0" -proc ADSP-BF609 -si-revision any -g -DCORE0 -D_DEBUG -DADI_MCAPI @includes-c376cb5fef6ea09e49524f58bf522bb3.txt -gnu-style-dependencies -MM -Mo "src/My_Write_REB_LEDS_ASM.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/My_Write_REB_SW_ASM.doj: ../src/My_Write_REB_SW_ASM.asm
	@echo 'Building file: $<'
	@echo 'Invoking: CrossCore Blackfin Assembler'
	easmblkfn -file-attr ProjectName="Lab2Testing_BF609_Core0" -proc ADSP-BF609 -si-revision any -g -DCORE0 -D_DEBUG -DADI_MCAPI @includes-c376cb5fef6ea09e49524f58bf522bb3.txt -gnu-style-dependencies -MM -Mo "src/My_Write_REB_SW_ASM.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/REBThread1.doj: ../src/REBThread1.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: CrossCore Blackfin C/C++ Compiler'
	ccblkfn -c -file-attr ProjectName="Lab2Testing_BF609_Core0" -proc ADSP-BF609 -flags-compiler --no_wrap_diagnostics -si-revision any -g -DCORE0 -D_DEBUG -DADI_MCAPI @includes-559323d4cc810c6974ee924577712455.txt -structs-do-not-overlap -no-const-strings -no-multiline -warn-protos -double-size-32 -decls-strong -cplbs -gnu-style-dependencies -MD -Mo "src/REBThread1.d" -c++ -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/REBThread2.doj: ../src/REBThread2.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: CrossCore Blackfin C/C++ Compiler'
	ccblkfn -c -file-attr ProjectName="Lab2Testing_BF609_Core0" -proc ADSP-BF609 -flags-compiler --no_wrap_diagnostics -si-revision any -g -DCORE0 -D_DEBUG -DADI_MCAPI @includes-559323d4cc810c6974ee924577712455.txt -structs-do-not-overlap -no-const-strings -no-multiline -warn-protos -double-size-32 -decls-strong -cplbs -gnu-style-dependencies -MD -Mo "src/REBThread2.d" -c++ -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/REBThread3.doj: ../src/REBThread3.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: CrossCore Blackfin C/C++ Compiler'
	ccblkfn -c -file-attr ProjectName="Lab2Testing_BF609_Core0" -proc ADSP-BF609 -flags-compiler --no_wrap_diagnostics -si-revision any -g -DCORE0 -D_DEBUG -DADI_MCAPI @includes-559323d4cc810c6974ee924577712455.txt -structs-do-not-overlap -no-const-strings -no-multiline -warn-protos -double-size-32 -decls-strong -cplbs -gnu-style-dependencies -MD -Mo "src/REBThread3.d" -c++ -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


