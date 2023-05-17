/****************** User referance **************************
Name: Shravan Hudekar
Description: print number in X format
sample input: 5
sample output:  1___5
                _2_4_
                __3__
                _2_4_
                1___5
*************************************************************/

#include<stdio.h>

int main()
{
    int num;

    printf("Enter the number: ");
    scanf("%d",&num);

    for(int i=num; i>0; i--)                // run loop from num to 0
    {
        for(int j=1; j<=num; j++)           // run loop from 1 to num
        {
            if(j==(num-i)+1 || j==i )       // generate X pattern by checking if j= 1,2 .. num or j= num, num-1 ... 1  
            {
                printf("%d",j);             // if true print value of j else print space
            }

            else
            {
                printf(" ");
            }
        }

        printf("\n");                      // new line 

    }

    return 0;
}