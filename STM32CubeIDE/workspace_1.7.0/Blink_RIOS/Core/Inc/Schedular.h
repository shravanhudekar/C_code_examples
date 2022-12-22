/*
 * Schedular.h
 *
 *  Created on: Jun 30, 2022
 *      Author: incads1917
 */

#include <stdint.h>

#ifndef INC_SCHEDULAR_H_
#define INC_SCHEDULAR_H_


/*----------------------------------------------------------------------------+
 | Type Definition & Macro                                                     |
 +----------------------------------------------------------------------------*/
typedef struct RegFunctions
{
   uint32_t timeperiod;      			// Rate at which the task should tick
   uint32_t elapsedTime; 				// Time since task's last tick
   const void (*ScheduleFct)(void);     // Function to call
} RegFunctions_t;

/*----------------------------------------------------------------------------+
 | Constant Definition                                                         |
 +----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------+
 | Function Prototype                                                          |
 +----------------------------------------------------------------------------*/
void SchedularHandler (uint16_t CallInterval);

/*----------------------------------------------------------------------------+
 | End of header file                                                          |
 +----------------------------------------------------------------------------*/


#endif /* INC_SCHEDULAR_H_ */
