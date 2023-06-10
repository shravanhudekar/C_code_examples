#include <stdio.h>

int main()
{                           //addresses
    int a[] = {10,20};      //1000  1004
    int b[] = {30,40};      //1008  1012
    int c[] = {50,60};      //1016  1020

    int *ptr[3];

    ptr[0] = a;             //4000
    ptr[1] = b;             //4008
    ptr[2] = c;             //4016

    printf ("%d %d %d\n",*ptr[0],*ptr[1],*ptr[2]);
    printf ("%d %d %d\n",*(ptr[0]),*(ptr[1]),*(ptr[2]));
    printf ("%d %d \n",*(*(ptr+2)),*(*(ptr+2)+1));
     printf ("%d %d %d\n",ptr[0][0],ptr[1][0],ptr[2][1]);

    return 0;
}

/** address substitution
 * i=1 j=1
 * *((*ptr+i)+j)
 * =*((4000+1)+1)               //4000 base address of ptr[]
 * =*((4000+1*8)+4)             // size of pointer 8bytes in 64 bit system 
 * =*(1008+4)
 * =*(1012)
 * = 40
*/