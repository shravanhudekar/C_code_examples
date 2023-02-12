/**************************************************************************************************************************
 * Functions that are executed before and after main() in C
 * 
 * To do this task we have to put attribute for these two functions. 
 * When the attribute is constructor attribute, then it will be executed before main(),
 * and when the attribute is destructor type, then it will be executed after main().
 * 
 * These features are used to do some startup task before executing the main, and some cleanup task after executing main.
 **************************************************************************************************************************/

#include <stdio.h>

void before_main() __attribute__((constructor));
void after_main() __attribute__((destructor));

void before_main() 
{
   printf("This is executed before main.\n");
}
void after_main() 
{
   printf("This is executed after main.\n");
}

int main() 
{
   printf("Inside main\n");

   return 0;
}