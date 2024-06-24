################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../startup/startup_mcxn236.c 

C_DEPS += \
./startup/startup_mcxn236.d 

OBJS += \
./startup/startup_mcxn236.o 


# Each subdirectory must supply rules for building sources it contributes
startup/%.o: ../startup/%.c startup/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -D__REDLIB__ -DCPU_MCXN236VDF -DCPU_MCXN236VDF_cm33 -DSDK_OS_BAREMETAL -DSERIAL_PORT_TYPE_UART=1 -DSDK_DEBUGCONSOLE=1 -DCR_INTEGER_PRINTF -DPRINTF_FLOAT_ENABLE=0 -DSDK_OS_FREE_RTOS -D__MCUXPRESSO -D__USE_CMSIS -DDEBUG -I"C:\Users\willi\Documents\MCUXpressoIDE_11.9.1_2170\workspace\MCXN236_Systemplate\board" -I"C:\Users\willi\Documents\MCUXpressoIDE_11.9.1_2170\workspace\MCXN236_Systemplate\source" -I"C:\Users\willi\Documents\MCUXpressoIDE_11.9.1_2170\workspace\MCXN236_Systemplate\drivers" -I"C:\Users\willi\Documents\MCUXpressoIDE_11.9.1_2170\workspace\MCXN236_Systemplate\component\serial_manager" -I"C:\Users\willi\Documents\MCUXpressoIDE_11.9.1_2170\workspace\MCXN236_Systemplate\device" -I"C:\Users\willi\Documents\MCUXpressoIDE_11.9.1_2170\workspace\MCXN236_Systemplate\utilities" -I"C:\Users\willi\Documents\MCUXpressoIDE_11.9.1_2170\workspace\MCXN236_Systemplate\CMSIS" -I"C:\Users\willi\Documents\MCUXpressoIDE_11.9.1_2170\workspace\MCXN236_Systemplate\component\lists" -I"C:\Users\willi\Documents\MCUXpressoIDE_11.9.1_2170\workspace\MCXN236_Systemplate\component\uart" -I"C:\Users\willi\Documents\MCUXpressoIDE_11.9.1_2170\workspace\MCXN236_Systemplate\freertos\freertos-kernel\portable\GCC\ARM_CM33_NTZ\non_secure" -I"C:\Users\willi\Documents\MCUXpressoIDE_11.9.1_2170\workspace\MCXN236_Systemplate\freertos\freertos-kernel\include" -O0 -fno-common -g3 -gdwarf-4 -Wall -c -ffunction-sections -fdata-sections -ffreestanding -fno-builtin -fmerge-constants -fmacro-prefix-map="$(<D)/"= -mcpu=cortex-m33 -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -D__REDLIB__ -fstack-usage -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-startup

clean-startup:
	-$(RM) ./startup/startup_mcxn236.d ./startup/startup_mcxn236.o

.PHONY: clean-startup

