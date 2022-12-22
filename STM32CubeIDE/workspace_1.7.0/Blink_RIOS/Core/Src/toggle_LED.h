/*
 * toggle_LED.h
 *
 *  Created on: Jun 30, 2022
 *      Author: incads1917
 */
#include <stdint.h>

#ifndef SRC_TOGGLE_LED_H_
#define SRC_TOGGLE_LED_H_

typedef  unsigned  char        CPU_INT08U;



typedef enum State                                                              /*<< Enum used for open phase detection states*/
{
  T_INIT,
  T_START,
  T_Toggle,
  T_pattern,
  T_RESET
}ToggleState;

typedef enum alerttimerState                                                    /**< This is common typedef Enum that is used to define OC Timer state.*/
{
  OCTimerDisabled,                                                              /**< Timer is Disabled / Stopped */
  OCTimerActive,                                                                /**< Timer is Active / Running */
  OCTimerSaturated,                                                             /**< Timer is expired */
  OCTimerReset = 4                                                              /**< This member is not used */
}OCtimerState;

typedef struct OC_Timer                                                         /**< This is common typedef structure that is used to hold OC Timer state. */
{
  CPU_INT08U    State;                                                          /**< This member holds timer state */
//  CPU_INT16U    Value;
}OC_Alert_Timer;

typedef struct
{
	uint8_t counter;
}counter_t;

void TickFct_Toggle(void);



#endif /* SRC_TOGGLE_LED_H_ */
