/*
*Declare a manifest constant that returns number of Seconds in a year using Preprocessor? 
Disregard Leap Years in your answer
*************************************************************
The purpose of this question is to test the following:

Basic knowledge of the #define syntax (for example, no semi-colon at the end, the need to parenthesize, and so on).
An understanding that the pre-processor will evaluate constant expressions for you. Thus, it is clearer, and penalty-free, to spell out how you are calculating the number of seconds in a year, rather than actually doing the calculation yourself.
A realization that the expression will overflow an integer argument on a 16-bit machinehence the need for the L, telling the compiler to treat the variable as a Long.
As a bonus, if you modified the expression with a UL (indicating unsigned long), then you are off to a great start. And remember, first impressions count!
**************************************************************
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdint.h>

#define SEC_PER_YEAR (unsigned long)(60*60*24*365)
//#define SEC_PER_YEAR (60*60*24*365)ul  // not working
#define CPU_INT  uint32_t
//#define SEC_PER_YEAR 31536000ul   // this works if u assgin this macro to variable type less thn 32bit it gives warning

/*******************************************************************
*Write standard "MIN" macro that is a macro that takes Two arguments 
and returns smaller of the two arguments 
********************************************************************/
#define MIN(A,B)((A)< (B) ? (A) : (B))  // ternary opertor  expression ? TRUE : FASLE


int main()
{
    CPU_INT sec= SEC_PER_YEAR,a,b;
    printf("%d",sec);

    printf("enter two no. ");
    scanf("%d%d",&a,&b);

    printf("\n min is: %d", MIN(a,b));

    
    return 0;
}