################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
ASM_SRCS += \
../src/Demonstrate_LED_Control_ASM.asm 

CPP_SRCS += \
../src/Coffee_Pot_Assignment1_Main.cpp \
../src/CoffeepotAssignment.cpp \
../src/Coffeepot_Assignment_Functions.cpp 

SRC_OBJS += \
./src/Coffee_Pot_Assignment1_Main.doj \
./src/CoffeepotAssignment.doj \
./src/Coffeepot_Assignment_Functions.doj \
./src/Demonstrate_LED_Control_ASM.doj 

ASM_DEPS += \
./src/Demonstrate_LED_Control_ASM.d 

CPP_DEPS += \
./src/Coffee_Pot_Assignment1_Main.d \
./src/CoffeepotAssignment.d \
./src/Coffeepot_Assignment_Functions.d 


# Each subdirectory must supply rules for building sources it contributes
src/Coffee_Pot_Assignment1_Main.doj: ../src/Coffee_Pot_Assignment1_Main.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: CrossCore Blackfin C/C++ Compiler'
	ccblkfn -c -file-attr ProjectName="CoffeepotAssignmentOnePot" -proc ADSP-BF533 -flags-compiler --no_wrap_diagnostics -si-revision any -g -DCORE0 -D_DEBUG @includes-ede7b89c1d8e9cfbd385271d507db358.txt -structs-do-not-overlap -no-const-strings -no-multiline -warn-protos -double-size-32 -decls-strong -cplbs -gnu-style-dependencies -MD -Mo "src/Coffee_Pot_Assignment1_Main.d" -c++ -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/CoffeepotAssignment.doj: ../src/CoffeepotAssignment.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: CrossCore Blackfin C/C++ Compiler'
	ccblkfn -c -file-attr ProjectName="CoffeepotAssignmentOnePot" -proc ADSP-BF533 -flags-compiler --no_wrap_diagnostics -si-revision any -g -DCORE0 -D_DEBUG @includes-ede7b89c1d8e9cfbd385271d507db358.txt -structs-do-not-overlap -no-const-strings -no-multiline -warn-protos -double-size-32 -decls-strong -cplbs -gnu-style-dependencies -MD -Mo "src/CoffeepotAssignment.d" -c++ -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/Coffeepot_Assignment_Functions.doj: ../src/Coffeepot_Assignment_Functions.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: CrossCore Blackfin C/C++ Compiler'
	ccblkfn -c -file-attr ProjectName="CoffeepotAssignmentOnePot" -proc ADSP-BF533 -flags-compiler --no_wrap_diagnostics -si-revision any -g -DCORE0 -D_DEBUG @includes-ede7b89c1d8e9cfbd385271d507db358.txt -structs-do-not-overlap -no-const-strings -no-multiline -warn-protos -double-size-32 -decls-strong -cplbs -gnu-style-dependencies -MD -Mo "src/Coffeepot_Assignment_Functions.d" -c++ -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/Demonstrate_LED_Control_ASM.doj: ../src/Demonstrate_LED_Control_ASM.asm
	@echo 'Building file: $<'
	@echo 'Invoking: CrossCore Blackfin Assembler'
	easmblkfn -file-attr ProjectName="CoffeepotAssignmentOnePot" -proc ADSP-BF533 -si-revision any -g -DCORE0 -D_DEBUG @includes-8e0b3164671ceda4fee8917572e6e0d9.txt -gnu-style-dependencies -MM -Mo "src/Demonstrate_LED_Control_ASM.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


