#include <stdio.h>


int main()
{
   static int x = 0;
   if(x < 10)
   {
        x++;
        main();
        printf("%d\n",x);
        
       
   }

    return 0;
}