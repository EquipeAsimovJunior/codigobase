################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../libs-src/ev3dev.cpp 

OBJS += \
./libs-src/ev3dev.o 

CPP_DEPS += \
./libs-src/ev3dev.d 


# Each subdirectory must supply rules for building sources it contributes
libs-src/%.o: ../libs-src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	arm-linux-gnueabi-g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


