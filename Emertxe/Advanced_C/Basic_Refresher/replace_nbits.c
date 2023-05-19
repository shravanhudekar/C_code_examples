/****************** User referance **************************
Name: Shravan Hudekar
Description:  Replace 'n' bits of a given number
sample input:   10 3 12
sample output:  Result = 12
*************************************************************/

#include<stdio.h>

int replace_nbits(int, int, int);            //function defination

int main()
{
   int num, n,val,res = 0;
    
    printf("Enter the number: ");
    scanf("%d", &num);

    printf("Enter number of bits: ");
    scanf("%d", &n);

    printf("Enter the value: ");
    scanf("%d", &val);
    
    res = replace_nbits(num, n, val);        //function call
    
    printf("Result = %d\n", res);

    return 0;
}

/**
 * @brief 0000 1010   AND with ~MASK
 *        0000 1000 
 *        0000 1100   AND with MASK 
 *        0000 1000   OR
 *        0000 1100
 * 
 * @param num = 10
 * @param n = 3
 * @param val = 12
 * @return int = 12
 */
int replace_nbits(int num, int n, int val)           //function declaration
{
    return num & ~((1<<n) -1) | val & ((1<<n) -1);           
}