#include <stdio.h>
#include "calculator.h"

uint16_t calculator(uint8_t ch, uint8_t x, uint8_t y)
{
	uint16_t result=0;
	switch(ch)
	{
		case 1: result=add(x,y);
				break;
		case 2: result=sub(x,y);
				break;
		case 3: result=mul(x,y);
				break;
		case 4: result=div(x,y);
				break;
		default: result=9999;
				break;
	}
}

uint16_t add(uint8_t a, uint8_t b)
{
	return (a+b);
}
uint16_t sub(uint8_t a, uint8_t b)
{
	return (a-b);
}
uint16_t mul(uint8_t a, uint8_t b)
{
	return (a*b);
}
uint16_t div(uint8_t a, uint8_t b)
{
	if(b==0)
	{
		return 99999;
	}

	else
	{
		return (a/b);
	}
}
