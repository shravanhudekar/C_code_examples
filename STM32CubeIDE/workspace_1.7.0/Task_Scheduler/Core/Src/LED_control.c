/*
 * scheduler.c
 *
 *  Created on: Jan 29, 2023
 *      Author: Manthan
 */

#include "LED_control.h"
#include "main.h"

/*
 *  GPIO_PIN_12 GREEN  LED
 *  GPIO_PIN_13 ORNGE  LED
 *  GPIO_PIN_14 RED    LED
 *  GPIO_PIN_15 BLUE   LED
 */
uint8_t LED_Control_Reg=0;
void clear_LED()
{
	turn_Orange_Off();
	turn_Green_Off ();
	turn_Red_Off   ();
	turn_Blue_Off  ();

	LED_Control_Reg &=0x00;
}

void turn_Orange_On()
{
	HAL_GPIO_WritePin(GPIOD, GPIO_PIN_13, GPIO_PIN_SET);
	LED_Control_Reg |= ORANGE_LED;
}
void turn_Green_On ()
{
	HAL_GPIO_WritePin(GPIOD, GPIO_PIN_12, GPIO_PIN_SET);
	LED_Control_Reg |= GREEN_LED;
}
void turn_Red_On   ()
{
	HAL_GPIO_WritePin(GPIOD, GPIO_PIN_14, GPIO_PIN_SET);
	LED_Control_Reg |= RED_LED;
}
void turn_Blue_On  ()
{
	HAL_GPIO_WritePin(GPIOD, GPIO_PIN_15, GPIO_PIN_SET);
	LED_Control_Reg |= BLUE_LED;
}
void turn_Orange_Off()
{
	HAL_GPIO_WritePin(GPIOD, GPIO_PIN_13, GPIO_PIN_RESET);
	LED_Control_Reg &= ~ORANGE_LED;
}
void turn_Green_Off ()
{
	HAL_GPIO_WritePin(GPIOD, GPIO_PIN_12, GPIO_PIN_RESET);
	LED_Control_Reg &= ~GREEN_LED;
}
void turn_Red_Off   ()
{
	HAL_GPIO_WritePin(GPIOD, GPIO_PIN_14, GPIO_PIN_RESET);
	LED_Control_Reg &= ~RED_LED;
}
void turn_Blue_Off  ()
{
	HAL_GPIO_WritePin(GPIOD, GPIO_PIN_15, GPIO_PIN_RESET);
	LED_Control_Reg &= ~BLUE_LED;
}

