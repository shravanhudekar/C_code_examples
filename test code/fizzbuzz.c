#include <stdio.h>
#include <stdint.h>

int main()
{
    int num;

    while(num!= 0)
    {
        
        printf("enter a no. ");
            scanf("%d",&num);       
        if (num !=0)
        {
            
            if((num%3)==0 && (num%5)==0)
            {
                printf("\nFizzBuzz!!!");
            }

            else if((num%3)==0)
            {
                printf("\nFizz!!!");
            }

            else if((num%5)==0)
            {
                printf("\nBuzz!!!");
            }

        }

    }


}
