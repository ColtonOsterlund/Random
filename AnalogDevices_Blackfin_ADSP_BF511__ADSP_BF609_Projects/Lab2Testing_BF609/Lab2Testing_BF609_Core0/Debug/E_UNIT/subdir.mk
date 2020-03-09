################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../E_UNIT/__EUNIT2017_TestControl_Lab2Testing_BF609_Core0.cpp 

SRC_OBJS += \
./E_UNIT/__EUNIT2017_TestControl_Lab2Testing_BF609_Core0.doj 

CPP_DEPS += \
./E_UNIT/__EUNIT2017_TestControl_Lab2Testing_BF609_Core0.d 


# Each subdirectory must supply rules for building sources it contributes
E_UNIT/__EUNIT2017_TestControl_Lab2Testing_BF609_Core0.doj: ../E_UNIT/__EUNIT2017_TestControl_Lab2Testing_BF609_Core0.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: CrossCore Blackfin C/C++ Compiler'
	ccblkfn -c -file-attr ProjectName="Lab2Testing_BF609_Core0" -proc ADSP-BF609 -flags-compiler --no_wrap_diagnostics -si-revision any -g -DCORE0 -D_DEBUG -DADI_MCAPI @includes-559323d4cc810c6974ee924577712455.txt -structs-do-not-overlap -no-const-strings -no-multiline -warn-protos -double-size-32 -decls-strong -cplbs -gnu-style-dependencies -MD -Mo "E_UNIT/__EUNIT2017_TestControl_Lab2Testing_BF609_Core0.d" -c++ -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


