/****************** User referance **************************
Name: Shravan Hudekar
Description: print Pyramid pattern
sample input: 5
sample output:  5
                4 5
                3 4 5
                2 3 4 5
                1 2 3 4 5
                2 3 4 5
                3 4 5
                4 5
                5   
*************************************************************/

#include<stdio.h>

int main()
{
    int num,i,flag=0;

    printf("Enter the number: ");
    scanf("%d",&num);

    i= num;
    while(i > 0)              
    {
        for(int j=i; j<=num; j++)           
        {
            printf("%d ",j);                // print index 
        }
        printf("\n");   

        if(flag)
        {   
            i++;                            // increment i for 2nd set of pyramid
            if(i>num) break;                // break while loop if i = num
        }
        else
        {   
            i--;                            //decrement i for 1 set of pyramid
            flag = (i == 1) ? 1:0;          // set flag to know that 1 set is completed as i reaches to 1
        }                   
    }

    return 0;
}