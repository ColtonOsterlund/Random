################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
LDF_SRCS += \
../system/startup_ldf/app.ldf 

S_SRCS += \
../system/startup_ldf/app_startup.s 

C_SRCS += \
../system/startup_ldf/app_cplbtab.c \
../system/startup_ldf/app_handler_table.c \
../system/startup_ldf/app_heaptab.c 

SRC_OBJS += \
./system/startup_ldf/app_cplbtab.doj \
./system/startup_ldf/app_handler_table.doj \
./system/startup_ldf/app_heaptab.doj \
./system/startup_ldf/app_startup.doj 

S_DEPS += \
./system/startup_ldf/app_startup.d 

C_DEPS += \
./system/startup_ldf/app_cplbtab.d \
./system/startup_ldf/app_handler_table.d \
./system/startup_ldf/app_heaptab.d 


# Each subdirectory must supply rules for building sources it contributes
system/startup_ldf/app_cplbtab.doj: ../system/startup_ldf/app_cplbtab.c
	@echo 'Building file: $<'
	@echo 'Invoking: CrossCore Blackfin C/C++ Compiler'
	ccblkfn -c -file-attr ProjectName="Lab1_EMU609_Core0" -proc ADSP-BF609 -flags-compiler --no_wrap_diagnostics -si-revision any -g -DCORE0 -D_DEBUG -DADI_MCAPI @includes-254bd50914cad7ce9ae9c729bea2aede.txt -structs-do-not-overlap -no-const-strings -no-multiline -warn-protos -double-size-32 -decls-strong -cplbs -gnu-style-dependencies -MD -Mo "system/startup_ldf/app_cplbtab.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

system/startup_ldf/app_handler_table.doj: ../system/startup_ldf/app_handler_table.c
	@echo 'Building file: $<'
	@echo 'Invoking: CrossCore Blackfin C/C++ Compiler'
	ccblkfn -c -file-attr ProjectName="Lab1_EMU609_Core0" -proc ADSP-BF609 -flags-compiler --no_wrap_diagnostics -si-revision any -g -DCORE0 -D_DEBUG -DADI_MCAPI @includes-254bd50914cad7ce9ae9c729bea2aede.txt -structs-do-not-overlap -no-const-strings -no-multiline -warn-protos -double-size-32 -decls-strong -cplbs -gnu-style-dependencies -MD -Mo "system/startup_ldf/app_handler_table.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

system/startup_ldf/app_heaptab.doj: ../system/startup_ldf/app_heaptab.c
	@echo 'Building file: $<'
	@echo 'Invoking: CrossCore Blackfin C/C++ Compiler'
	ccblkfn -c -file-attr ProjectName="Lab1_EMU609_Core0" -proc ADSP-BF609 -flags-compiler --no_wrap_diagnostics -si-revision any -g -DCORE0 -D_DEBUG -DADI_MCAPI @includes-254bd50914cad7ce9ae9c729bea2aede.txt -structs-do-not-overlap -no-const-strings -no-multiline -warn-protos -double-size-32 -decls-strong -cplbs -gnu-style-dependencies -MD -Mo "system/startup_ldf/app_heaptab.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

system/startup_ldf/app_startup.doj: ../system/startup_ldf/app_startup.s
	@echo 'Building file: $<'
	@echo 'Invoking: CrossCore Blackfin Assembler'
	easmblkfn -file-attr ProjectName="Lab1_EMU609_Core0" -proc ADSP-BF609 -si-revision any -g -DCORE0 -D_DEBUG -DADI_MCAPI @includes-68e9f6bf72bbfa45b9332b3ac127b7b1.txt -gnu-style-dependencies -MM -Mo "system/startup_ldf/app_startup.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


