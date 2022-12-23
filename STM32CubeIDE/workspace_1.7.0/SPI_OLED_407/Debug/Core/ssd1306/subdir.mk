################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/ssd1306/ssd1306.c \
../Core/ssd1306/ssd1306_fonts.c \
../Core/ssd1306/ssd1306_tests.c 

C_DEPS += \
./Core/ssd1306/ssd1306.d \
./Core/ssd1306/ssd1306_fonts.d \
./Core/ssd1306/ssd1306_tests.d 

OBJS += \
./Core/ssd1306/ssd1306.o \
./Core/ssd1306/ssd1306_fonts.o \
./Core/ssd1306/ssd1306_tests.o 


# Each subdirectory must supply rules for building sources it contributes
Core/ssd1306/%.o: ../Core/ssd1306/%.c Core/ssd1306/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F407xx -c -I../Core/Inc -I"D:/My Git/C_code_examples/STM32CubeIDE/workspace_1.7.0/SPI_OLED_407/Core/ssd1306" -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

