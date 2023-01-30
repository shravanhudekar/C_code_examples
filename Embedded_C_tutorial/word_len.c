/*
C Prog - Find processor word length(16bit, 32-bit,64-bit)
*/
#include <stdio.h>
#include <stdint.h>

int main()
{

    long a,count=0;
   // long b=0;
    unsigned b=~0;        // other way of complimenting value to init vriable with higest word length processor supports

    printf("long: %d bytes\n",sizeof(a));

/***********************************************************************************************************************************************************
 *  if 'b' is signed '~b' will be '-1' for which (b>>1) wont make any change as -1 is least no. in negative, so use (b<<1) where highest value will be '0'.
 *  if 'b' is unsigned '~b' will be  MAX of size of word for which (b>>1) will make decrement by power of 2 till '0'.
 ***********************************************************************************************************************************************************/
   // b=~b;

    while(b != 0)
    {
        count++;
      //  b<<=1;     //signed
        b>>=1;     //unsigned
    }
    printf("%d bits = %d bytes",count,count/8);
}