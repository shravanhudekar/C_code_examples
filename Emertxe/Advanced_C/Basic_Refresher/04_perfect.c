/****************** User referance **************************
Name: Shravan Hudekar
Description: check if number is perfect or not.
sample input: 6
sample output: Yes, entered number is perfect number
*************************************************************/
/***** excluding method *********
1. take 'num' as input from user
2. run loop i=0 till num/2
    2.1 check if i is perfect positive divisor of num.
    2.2 if true add to sum
3. check if sum=num
    3.1 if true, print no. is perfect 
    3.2 else not a perfect no.
*********************************/


#include<stdio.h>

int main ()
{
    int num,sum=0;

    printf("Enter a number: ");
    scanf("%d",&num);

    if(num < 0)
    {
        printf("Error : Invalid Input, Enter only positive number\n");
    }

    //if Entered number is postive
    else
    {
        for(int i=1; i<=num/2; i++)                     //loop until proper positive divisor is available 
        {
            //if remainder is 0 its a proper positive divisor
            if(num%i == 0)                              
            {
                sum+=i;                                 //calculate sum
            }
        }

        if(num == sum)                          
        {
            printf("Yes, entered number is perfect number\n");
        }

        else
        {
            printf("No, entered number is not a perfect number\n");
        }
    }
}

