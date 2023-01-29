/*
 * scheduler.h
 *
 *  Created on: Jan 29, 2023
 *      Author: Manthan
 */

#ifndef INC_SCHEDULER_H_
#define INC_SCHEDULER_H_

#include "LED_control.h"

typedef struct scheduler
{
	uint8_t period;
	uint8_t elapse_time;

}task_t;

void LED_Scheduler_init(void);
void toggle_LED(void);

#endif /* INC_SCHEDULER_H_ */
