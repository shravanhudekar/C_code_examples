/****************** User referance **************************
Name: Shravan Hudekar
Description: find which day of the year
sample input:   9 
                2
sample output:  The day is Tuesday
*************************************************************/

#include<stdio.h>

int main()
{
    int n,ch;

    printf("Enter the value of 'n' : ");
    scanf("%d",&n);

    // validate input of day in year 
    if(n > 0 && n <= 365)       
    {
        printf("Choose First Day :\
                \n1. Sunday\
                \n2. Monday\
                \n3. Tuesday\
                \n4. Wednesday\
                \n5. Thursday\
                \n6. Friday\
                \n7. Saturday\
                \nEnter the option to set the first day : ");
        scanf("%d",&ch);

        // validate input of day in week
        if (ch > 0 && ch <=7)
        {
            ch=(n+ch)%7-1;      // this will calculate day of the week as per input n 

            //switch case to print respective output based on day
            switch (ch)
            {
                case 0:
                    printf("The day is Saturday");
                    break;

                case 1:
                    printf("The day is Sunday");
                    break;

                case 2:
                    printf("The day is Monday");
                    break;

                case 3:
                    printf("The day is Tuesday");
                    break;

                case 4:
                    printf("The day is Wednesday");
                    break;

                case 5:
                    printf("The day is Thursday");
                    break;

                case 6:
                    printf("The day is Friday");
                    break;

            default:
                break;
            }
        }
        else
        {
            printf("Error: Invalid input, first day should be > 0 and <= 7\n");
        }    
    }
    else
    {
        printf("Error: Invalid Input, n value should be > 0 and <= 365\n");
    }

    return 0;
}