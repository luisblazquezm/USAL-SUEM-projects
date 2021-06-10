################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Generated_Code/CAN1.c \
../Generated_Code/Cpu.c \
../Generated_Code/II2C.c \
../Generated_Code/IntI2cLdd1.c \
../Generated_Code/MCUC1.c \
../Generated_Code/PE_LDD.c \
../Generated_Code/PPG1.c \
../Generated_Code/Pins1.c \
../Generated_Code/PpgLdd1.c \
../Generated_Code/WAIT1.c 

OBJS += \
./Generated_Code/CAN1.o \
./Generated_Code/Cpu.o \
./Generated_Code/II2C.o \
./Generated_Code/IntI2cLdd1.o \
./Generated_Code/MCUC1.o \
./Generated_Code/PE_LDD.o \
./Generated_Code/PPG1.o \
./Generated_Code/Pins1.o \
./Generated_Code/PpgLdd1.o \
./Generated_Code/WAIT1.o 

C_DEPS += \
./Generated_Code/CAN1.d \
./Generated_Code/Cpu.d \
./Generated_Code/II2C.d \
./Generated_Code/IntI2cLdd1.d \
./Generated_Code/MCUC1.d \
./Generated_Code/PE_LDD.d \
./Generated_Code/PPG1.d \
./Generated_Code/Pins1.d \
./Generated_Code/PpgLdd1.d \
./Generated_Code/WAIT1.d 


# Each subdirectory must supply rules for building sources it contributes
Generated_Code/%.o: ../Generated_Code/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m0plus -mthumb -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections  -g3 -I"C:/Users/bisite/Desktop/SUEM/AlarmReceiver/Static_Code/System" -I"C:/Users/bisite/Desktop/SUEM/AlarmReceiver/Static_Code/PDD" -I"C:/Users/bisite/Desktop/SUEM/AlarmReceiver/Static_Code/IO_Map" -I"C:\Freescale\KDS_v3\eclipse\ProcessorExpert/lib/Kinetis/pdd/inc" -I"C:/Users/bisite/Desktop/SUEM/AlarmReceiver/Sources" -I"C:/Users/bisite/Desktop/SUEM/AlarmReceiver/Generated_Code" -std=c99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


