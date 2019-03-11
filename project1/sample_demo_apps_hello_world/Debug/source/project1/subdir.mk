################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../source/project1/allocate.c \
../source/project1/check_address.c \
../source/project1/displaymem.c \
../source/project1/freemem.c \
../source/project1/help.c \
../source/project1/invert.c \
../source/project1/pattern.c \
../source/project1/readin.c \
../source/project1/terminal.c \
../source/project1/write.c 

OBJS += \
./source/project1/allocate.o \
./source/project1/check_address.o \
./source/project1/displaymem.o \
./source/project1/freemem.o \
./source/project1/help.o \
./source/project1/invert.o \
./source/project1/pattern.o \
./source/project1/readin.o \
./source/project1/terminal.o \
./source/project1/write.o 

C_DEPS += \
./source/project1/allocate.d \
./source/project1/check_address.d \
./source/project1/displaymem.d \
./source/project1/freemem.d \
./source/project1/help.d \
./source/project1/invert.d \
./source/project1/pattern.d \
./source/project1/readin.d \
./source/project1/terminal.d \
./source/project1/write.d 


# Each subdirectory must supply rules for building sources it contributes
source/project1/%.o: ../source/project1/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -std=gnu99 -DCPU_MKL25Z128VFM4 -DCPU_MKL25Z128VFM4_cm0plus -DDEBUG -DCPU_MKL25Z128VLK4 -DPRINTF_FLOAT_ENABLE=0 -DSCANF_FLOAT_ENABLE=0 -DPRINTF_ADVANCED_ENABLE=0 -DSCANF_ADVANCED_ENABLE=0 -DFRDM_KL25Z -DFREEDOM -DCR_INTEGER_PRINTF -DSDK_DEBUGCONSOLE_ITM -D__MCUXPRESSO -D__USE_CMSIS -D__REDLIB__ -DSDK_DEBUGCONSOLE=1 -I../board -I/home/sam/ECEN5813/project1 -I../source -I../ -I../drivers -I../CMSIS -I../utilities -I../startup -I/home/sam/ECEN5813/project1 -O0 -fno-common -g -Wall -c -fmessage-length=0 -fno-builtin -ffunction-sections -fdata-sections -mcpu=cortex-m0plus -mthumb -D__REDLIB__ -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


