/*
 * scheduler.c
 *
 *  Created on: Jan 29, 2023
 *      Author: Manthan
 */
#include "scheduler.h"

extern task_t Task;
task_t LED1,LED2,LED3,LED4;

void LED_Scheduler_init()
{
	Task.elapse_time=0;
	LED1.period=4;
	LED2.period=8;
	LED3.period=12;
	LED4.period=16;
}

void Create_Task_led()
{

}

void toggle_LED()
{
	if(Task.elapse_time == LED1.period)
	{
		turn_Green_On();
		turn_Red_Off();
		//turn_Blue_Off();
	}

	else if(Task.elapse_time == LED2.period)
	{
		turn_Orange_On();
		turn_Blue_Off();
		//turn_Green_Off();

	}
	else if(Task.elapse_time == LED3.period)
	{
		turn_Red_On();
		turn_Green_Off();
		//turn_Orange_Off();
	}
	else if(Task.elapse_time == LED4.period)
	{
		turn_Blue_On();
		turn_Orange_Off();
		//turn_Red_Off();
		Task.elapse_time=0;
	}

	else
	{

	}


}
