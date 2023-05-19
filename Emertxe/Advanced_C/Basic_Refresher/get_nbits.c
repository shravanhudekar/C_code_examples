/****************** User referance **************************
Name: Shravan Hudekar
Description:  get 'n' bits of a given number
sample input:   10 3 
sample output:  Result = 2
*************************************************************/

#include<stdio.h>

int get_nbits(int, int);            //function defination

int main()
{
   int num, n, res = 0;
    
    printf("Enter the number: ");
    scanf("%d", &num);

    printf("Enter number of bits: ");
    scanf("%d", &n);
    
    res = get_nbits(num, n);        //function call
    
    printf("Result = %d\n", res);

    return 0;
}

int get_nbits(int num, int n)           //function declaration
{
    return num & ((1<<n) -1);           // if n=3 then, mask = n-1 will give 2 i.e. 0000 0011 
}