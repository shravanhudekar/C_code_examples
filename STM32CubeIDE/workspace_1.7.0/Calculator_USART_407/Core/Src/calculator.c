#include <stdio.h>
#include "calculator.h"


uint16_t calculator()
{
	int ch=0,x=0,y=0;
	double result;
	 printf("Enter your choice:\r\n");
	 printf("1. Addition\n\r2. Subtraction\n\r3. Multiplication\n\r4. Division\n\r");
	 scanf(" %d", &ch);
	 printf("enter 2 no.\n\r");
	 scanf("%d %d",&x,&y);

	switch(ch)
	{
		case 1: result=add(x,y);
				break;
		case 2: result=sub(x,y);
				break;
		case 3: result=mul(x,y);
				break;
		case 4: result=division(x,y);
				break;
		default: result=999;
				break;
	}

	printf("%0.2f\r\n\n",result);

	return result;
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
uint16_t division(uint8_t a, uint8_t b)
{
	if(b==0)
	{
		return 9999;
	}

	else
	{
		return (a/b);
	}

}
