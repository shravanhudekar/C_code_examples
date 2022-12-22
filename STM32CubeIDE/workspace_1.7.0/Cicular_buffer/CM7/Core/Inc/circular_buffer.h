/*
 * circular_buffer.h
 *
 *  Created on: Sep 17, 2022
 *      Author: incads1917
 */

#ifndef INC_CIRCULAR_BUFFER_H_
#define INC_CIRCULAR_BUFFER_H_

#include "stm32h7xx_hal.h"
#include <stdint.h>
#include<stdio.h>
#include<stdbool.h>

#endif /* INC_CIRCULAR_BUFFER_H_ */
#define SIZE_OF_BUFFER 10

typedef struct buffer
{
	uint8_t head;
	uint8_t tail;
	uint16_t *data[SIZE_OF_BUFFER];

	bool flag;
}buffer_t;


void buffer_init();
void write_buffer(uint8_t user_data);
void read_buffer();
