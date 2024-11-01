/*
 * circular_buffer.c
 *
 *  Created on: Sep 17, 2022
 *      Author: incads1917
 */


#include"circular_buffer.h"

buffer_t  data_node;

void buffer_init()
{

	data_node.head=0;
	data_node.tail=0;
	memset(&data_node.data,0,sizeof(data_node.data));
	data_node.flag=false;
}

void write_buffer(uint8_t user_data)
{

	if (data_node.bufferlength == SIZE_OF_BUFFER)
	{
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_14, GPIO_PIN_SET);
		data_node.flag=true;
	}

	else
	{
		data_node.data[data_node.bufferlength]=user_data;
		data_node.bufferlength++;
		data_node.head++;
		HAL_GPIO_WritePin(GPIOE, GPIO_PIN_1, GPIO_PIN_RESET);
	}

}

void read_buffer()
{
	uint8_t read_data;
	if (data_node.bufferlength == 0)
	{
		HAL_GPIO_WritePin(GPIOE, GPIO_PIN_1, GPIO_PIN_SET);
	}

	else
	{
		read_data=data_node.data[data_node.bufferlength];
		data_node.bufferlength--;
		data_node.tail++;
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_14, GPIO_PIN_RESET);
	}

}
