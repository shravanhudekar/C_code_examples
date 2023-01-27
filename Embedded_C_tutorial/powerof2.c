#include<stdio.h>
#include<stdint.h>
#include<stdlib.h>
#include <math.h>
#include "print_binary.h"   

/* it tell whether no. is power of 2 or not*/

/* consider x=8 
*                   x= 0000 1000  & x-1= 0000 0111   =  0000 0000                         '!' it compliments the ans 1=0  0=1
* If ans. is 0 number is power of 2 
* else         number is not power of 2
*/
#define TWO_POWER   1
#define FOUR_POWER  2

#define FIND_TWO_POWER(x)  (!(x & (x-1)) && (x & x))
#define FIND_POW_OF(x,y)   ( FIND_TWO_POWER(x) && (!(x & 0xAAAAAAAA) || !(y-1)))                    //works for 2^y  4^y
#define POWOF(x,y)         (1<<(x<<(y-1)))                                                       //works for 2^y  4^y

int checkPowerOf2(int x)
{
    int mask=x-1;
    if(x==0) return 0;
    printBinary((x & mask),EIGHT_BIT);
    return !(x & mask);
}

int pow2(int x)
{
    return ( 1 << x);
}

int checkPowerOf4(int n)
{
    if(n==0) return 0;

    int powerof2= !(n&(n-1));   // cehcks for two's power

    int mask = !(n & 0xAAAAAAAA);       
    return powerof2 && mask;
}

int main()
{
    int num=0,n=0;

    printf("enter no. ");
    scanf("%d",&num);

    if(FIND_POW_OF(num,FOUR_POWER))                    
    
    {  printf("\npower of %d",FOUR_POWER*2); }

    else
    {  printf("\nnot power of %d",FOUR_POWER*2);}

    // printf("\nenter no. for power of %d: ",FOUR_POWER*2);
    // scanf("%d",&n);
    // printf("%d^%d is %d.\n",FOUR_POWER*2,n,POWOF(n,FOUR_POWER));
    // printBinary(POWOF(n,FOUR_POWER),SIXTEEN_BIT);
    // if(checkPowerOf4(n))
    // {  printf("is power of 4 \n");  }
    // else
    // {  printf("not power of 4\n");  }

     return 0;
}