/*
 * scheduler.h
 *
 *  Created on: Jan 29, 2023
 *      Author: Manthan
 */

#ifndef INC_LED_CONTROL_H_
#define INC_LED_CONTROL_H_

#include <stdint.h>


#define GREEN_LED   0x01
#define ORANGE_LED  (GREEN_LED << 1)
#define RED_LED     (ORANGE_LED << 1)
#define BLUE_LED    (RED_LED << 1)

void turn_Orange_On();
void turn_Green_On ();
void turn_Red_On   ();
void turn_Blue_On  ();
void turn_Orange_Off();
void turn_Green_Off ();
void turn_Red_Off   ();
void turn_Blue_Off  ();
#endif /* INC_LED_CONTROL_H_ */
