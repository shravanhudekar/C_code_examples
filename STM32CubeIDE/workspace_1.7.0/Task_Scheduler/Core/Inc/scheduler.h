/*
 * scheduler.h
 *
 *  Created on: Jan 29, 2023
 *      Author: Manthan
 */

#ifndef INC_SCHEDULER_H_
#define INC_SCHEDULER_H_

#include "LED_control.h"

#define MAX_TASK 16

typedef struct scheduler
{
	uint8_t period;
	uint8_t elapse_time;
	void (*func)(void);

}task_t;

void LED_Scheduler_init(void);
void SchedularHandler (uint16_t CallInterval);

#endif /* INC_SCHEDULER_H_ */
