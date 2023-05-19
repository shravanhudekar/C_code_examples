/****************** User referance **************************
Name: Shravan Hudekar
Description:  get 'n' bits from given position of a number
sample input:   12 3 4
sample output:  Result = 3
*************************************************************/

#include<stdio.h>

int get_nbits_from_pos(int, int, int);            //function defination

int main()
{
   int num, n,pos,res = 0;
    
    printf("Enter the number: ");
    scanf("%d", &num);

    printf("Enter number of bits: ");
    scanf("%d", &n);

    printf("Enter the pos: ");
    scanf("%d", &pos);
    
    res = get_nbits_from_pos(num, n, pos);     //function call
    
    printf("Result = %d\n", res);

    return 0;
}

/*
* AND num with mask to clear bits after pos
* right shift num by pos-n position*/

int get_nbits_from_pos(int num, int n, int pos)             //function declaration
{
    return ((num & ((1<<pos+1) -1)) >> (pos-n+1));           // +1 as bit position start with 0
}

