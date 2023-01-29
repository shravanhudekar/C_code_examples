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

void clear_LED()
{
	void turn_Orange_Off();
	void turn_Green_Off ();
	void turn_Red_Off   ();
	void turn_Blue_Off  ();
}

void turn_Orange_On()
{
	HAL_GPIO_WritePin(GPIOD, GPIO_PIN_13, GPIO_PIN_SET);
}
void turn_Green_On ()
{
	HAL_GPIO_WritePin(GPIOD, GPIO_PIN_12, GPIO_PIN_SET);
}
void turn_Red_On   ()
{
	HAL_GPIO_WritePin(GPIOD, GPIO_PIN_14, GPIO_PIN_SET);
}
void turn_Blue_On  ()
{
	HAL_GPIO_WritePin(GPIOD, GPIO_PIN_15, GPIO_PIN_SET);
}
void turn_Orange_Off()
{
	HAL_GPIO_WritePin(GPIOD, GPIO_PIN_13, GPIO_PIN_RESET);
}
void turn_Green_Off ()
{
	HAL_GPIO_WritePin(GPIOD, GPIO_PIN_12, GPIO_PIN_RESET);
}
void turn_Red_Off   ()
{
	HAL_GPIO_WritePin(GPIOD, GPIO_PIN_14, GPIO_PIN_RESET);
}
void turn_Blue_Off  ()
{
	HAL_GPIO_WritePin(GPIOD, GPIO_PIN_15, GPIO_PIN_RESET);
}

