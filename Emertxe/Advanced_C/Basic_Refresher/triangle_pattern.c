/****************** User referance **************************
Name: Shravan Hudekar
Description: print triangle pattern
sample input: 5
sample output:  1 2 3 4 5
                6     7
                8    9
                10 11
                12
*************************************************************/

#include<stdio.h>

int main()
{
    int num,k=0;

    printf("Enter the number: ");
    scanf("%d",&num);

    for(int i=num; i>0; i--)                // run loop from num to 0
    {
        for(int j=1; j<=i; j++)           // run loop from 1 to num, num-1 .. 
        {
            /***** condition brief  ****
                k<=num   To print 1st line(horizontal line of triangle) with all value from 1 to num
                j==1     To generate stright line only with kth value 
                j==i     To generate diagonal line by kth value
             *************************/
            if(k <= num || j==1 || j==i)       // generate triangle pattern 
            {
                k++;                              //hold count of interation whenever condition is ture
                printf("%d ",k);                 // if true print value of k else print space          
            }

            else
            {
                printf("  ");
            }
        }

        printf("\n");                      // new line 

    }

    return 0;
}