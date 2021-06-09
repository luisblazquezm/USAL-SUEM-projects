################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Generated_Code/AD1.c \
../Generated_Code/ASerialLdd1.c \
../Generated_Code/AdcLdd1.c \
../Generated_Code/BitsIoLdd1.c \
../Generated_Code/BitsIoLdd2.c \
../Generated_Code/Bits_Botones.c \
../Generated_Code/Bits_RGB.c \
../Generated_Code/Cpu.c \
../Generated_Code/Inhr1.c \
../Generated_Code/MCUC1.c \
../Generated_Code/PE_LDD.c \
../Generated_Code/PPG1.c \
../Generated_Code/Pins1.c \
../Generated_Code/PpgLdd1.c \
../Generated_Code/TI1.c \
../Generated_Code/TU1.c \
../Generated_Code/Term1.c \
../Generated_Code/TimerIntLdd1.c \
../Generated_Code/UTIL1.c \
../Generated_Code/WAIT.c 

OBJS += \
./Generated_Code/AD1.o \
./Generated_Code/ASerialLdd1.o \
./Generated_Code/AdcLdd1.o \
./Generated_Code/BitsIoLdd1.o \
./Generated_Code/BitsIoLdd2.o \
./Generated_Code/Bits_Botones.o \
./Generated_Code/Bits_RGB.o \
./Generated_Code/Cpu.o \
./Generated_Code/Inhr1.o \
./Generated_Code/MCUC1.o \
./Generated_Code/PE_LDD.o \
./Generated_Code/PPG1.o \
./Generated_Code/Pins1.o \
./Generated_Code/PpgLdd1.o \
./Generated_Code/TI1.o \
./Generated_Code/TU1.o \
./Generated_Code/Term1.o \
./Generated_Code/TimerIntLdd1.o \
./Generated_Code/UTIL1.o \
./Generated_Code/WAIT.o 

C_DEPS += \
./Generated_Code/AD1.d \
./Generated_Code/ASerialLdd1.d \
./Generated_Code/AdcLdd1.d \
./Generated_Code/BitsIoLdd1.d \
./Generated_Code/BitsIoLdd2.d \
./Generated_Code/Bits_Botones.d \
./Generated_Code/Bits_RGB.d \
./Generated_Code/Cpu.d \
./Generated_Code/Inhr1.d \
./Generated_Code/MCUC1.d \
./Generated_Code/PE_LDD.d \
./Generated_Code/PPG1.d \
./Generated_Code/Pins1.d \
./Generated_Code/PpgLdd1.d \
./Generated_Code/TI1.d \
./Generated_Code/TU1.d \
./Generated_Code/Term1.d \
./Generated_Code/TimerIntLdd1.d \
./Generated_Code/UTIL1.d \
./Generated_Code/WAIT.d 


# Each subdirectory must supply rules for building sources it contributes
Generated_Code/%.o: ../Generated_Code/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m0plus -mthumb -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections  -g3 -I"C:\Freescale\KDS_v3\eclipse\ProcessorExpert/Repositories/Kinetis_Repository/lib/Kinetis/pdd2/MKE06Z128LK4/system" -I"C:\Freescale\KDS_v3\eclipse\ProcessorExpert/lib/Kinetis/pdd/inc" -I"C:\Freescale\KDS_v3\eclipse\ProcessorExpert/lib/Kinetis/iofiles" -I"C:/Users/bisite/Desktop/SUEM/laberinto/Sources" -I"C:/Users/bisite/Desktop/SUEM/laberinto/Generated_Code" -std=c99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


