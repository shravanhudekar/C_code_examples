/****************** User referance **************************
Name: Shravan Hudekar
Description: check N th bit is set or not, If yes, clear the M th bit
sample input:   19
                1
                4
sample output:  Updated value of num is 3
*************************************************************/

#include<stdio.h>


int main()
{
    int num,n,m;

    //take user inputs
    printf("Enter the number: ");
    scanf("%d",&num);
    printf("Enter 'N': ");
    scanf("%d",&n);
    printf("Enter 'M': ");
    scanf("%d",&m);

    //check if n th bit is set
    if(num & (1<<n))
    {
        num &= ~(1<<m);         //clear m th bit and update
    }

    printf("Updated value of num is %d",num);

    return 0;
}