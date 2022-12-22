
/*******************************************************************************
                   				INCLUDES FILES
*******************************************************************************/
#include "Schedular.h"

#include "toggle_LED.h"
/*******************************************************************************
                    			PRIVATE CONSTANTS
*******************************************************************************/
#define TOTAL_ACTIVITY	sizeof(ListOfActivity)/sizeof(RegFunctions_t)

/*******************************************************************************
                               TYPE DEFINITIONS
*******************************************************************************/

/*******************************************************************************
                             FORWARD DECALRATIONS
*******************************************************************************/

/*******************************************************************************
                               GLOBAL VARIABLES
*******************************************************************************/
static RegFunctions_t ListOfActivity [] =
{
		// Warning: Dont do lots of activity at same time, this can increase
		// tasks execution time.

		// All the timing are instep of 5mSec only of TIME_INTERVAL
		//Time Period		//Time Elapsed			//Activity
		{8000,            	0,                   	(void *)TickFct_Toggle                  },


};
/*******************************************************************************
                               EXTERN VARIABLES
*******************************************************************************/

/*******************************************************************************
                               STATIC VARIABLES
*******************************************************************************/

/*******************************************************************************
                                     CODE
*******************************************************************************/

/****************************************************************************
  Function		:	SchedularHandler

  Description	:
    this function will schedule other activity
*****************************************************************************/
void SchedularHandler (uint16_t CallInterval)
{
	uint16_t i;

	for (i=0; i < TOTAL_ACTIVITY; i++)
	{
		if (ListOfActivity[i].elapsedTime >= ListOfActivity[i].timeperiod)
		{
			if(ListOfActivity[i].ScheduleFct)
			{
				ListOfActivity[i].ScheduleFct(); //execute task tick
			}
			else
			{
				// NULL do nothing
			}
			ListOfActivity[i].elapsedTime = 0;
		}
		ListOfActivity[i].elapsedTime += CallInterval;
	}
}


/*******************************************************************************
 	 	 	 	 	 	 	 	 End of file                                                          |
*******************************************************************************/
