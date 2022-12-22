

#include "toggle_LED.h"
#include "schedular.h"
#include "stm32f4xx.h"


CPU_INT08U state = T_INIT;
counter_t count;

void TickFct_Toggle()
{

   switch(state)
   {
      case T_INIT:
    	 HAL_GPIO_WritePin(GPIOD, GPIO_PIN_12|GPIO_PIN_13|GPIO_PIN_14|GPIO_PIN_15, GPIO_PIN_SET);
    	 count.counter = 0;
         state = T_START;
         break;

      case  T_START:

    	  HAL_GPIO_WritePin(GPIOD, GPIO_PIN_12|GPIO_PIN_13, GPIO_PIN_RESET);

    	  for (uint8_t i=0 ; i<5;i++ )
    	  {
    	  HAL_GPIO_TogglePin(GPIOD, GPIO_PIN_12|GPIO_PIN_13|GPIO_PIN_14|GPIO_PIN_15);
    	 HAL_Delay(250);
    	  }
    	  count.counter++;

    	  if (count.counter > 2)
    	  {
    		  state = T_RESET;
    	  }
         break;

      case T_RESET:

    	  HAL_GPIO_WritePin(GPIOD, GPIO_PIN_12|GPIO_PIN_13|GPIO_PIN_14|GPIO_PIN_15, GPIO_PIN_RESET);

    	  state = T_INIT;

         break;
      default:
         break;
   }

}

