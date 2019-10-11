################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/eCliente.c \
../src/ePedidoPendiente.c \
../src/primerParcial.c \
../src/utn.c 

OBJS += \
./src/eCliente.o \
./src/ePedidoPendiente.o \
./src/primerParcial.o \
./src/utn.o 

C_DEPS += \
./src/eCliente.d \
./src/ePedidoPendiente.d \
./src/primerParcial.d \
./src/utn.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


