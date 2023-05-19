

/****************** User referance **************************
Name: Shravan Hudekar
Description:  print 'n' bits from LSB of a number
sample input:   10 12
sample output:  Binary form of 10: 0 0 0 0 0 0 0 0 1 0 1 0
*************************************************************/

#include<stdio.h>

int print_bits(int, int);            //function defination

int main()
{
   int num, n,pos,res = 0;
    
    printf("Enter the number: ");
    scanf("%d", &num);

    printf("Enter number of bits: ");
    scanf("%d", &n);
    
    printf("Binary form of %d: ", num);
    print_bits(num, n);

    return 0;
}

int print_bits(int number,int n)
{
    /*
    * n is initisalized with mask of nth bit set 
    * AND n with number to check if bit is 0 or 1 and print it
    * loop until n is 0 as n is decremented by 1 bit 
    */
    for(n = 1<<n-1; n; n >>= 1)   
    {
        printf("%d ", (n & number)?1:0);
    }
}