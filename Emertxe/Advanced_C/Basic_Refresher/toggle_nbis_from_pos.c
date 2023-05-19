/****************** User referance **************************
Name: Shravan Hudekar
Description:  toggle 'n' bits from given position of a number
sample input:   12 3 4
sample output:  Result = 16
*************************************************************/

#include<stdio.h>

int toggle_nbits_from_pos(int, int, int);            //function defination

int main()
{
   int num, n,pos,res = 0;
    
    printf("Enter the number: ");
    scanf("%d", &num);

    printf("Enter number of bits: ");
    scanf("%d", &n);

    printf("Enter the pos: ");
    scanf("%d", &pos);
    
    res = toggle_nbits_from_pos(num, n, pos);     //function call
    
    printf("Result = %d\n", res);

    return 0;
}

/*
* create bit mask of n bits
* left shift created mask by pos-n position
* X-OR num with shifted mask to toggle n bits from postion pos
*/

int toggle_nbits_from_pos(int num, int n, int pos)             //function declaration
{
    return (num  ^ ((1<<n)-1)<<(pos-n+1));        // +1 as bit position start with 0
}

