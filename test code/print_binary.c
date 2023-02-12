#include<stdio.h>
#include "print_binary.h"

void printBinary(uint32_t number,uint32_t bit_mask)
{
   // printf("0b ");
    for(;bit_mask; bit_mask >>= 1)      // loop until 'bit_mask' is '0'
    {
        printf("%d", (bit_mask & number)?1:0);
        if(bit_mask & 0x11111111)
        { printf(" ");}
    }
    printf("\n");
}

/*
bit_mask  1000 0000 (0)
>>1       0100 0000 (1)
>>1       0010 0000 (2)
>>1       0001 0000 (3)
>>1       0000 1000 (4)
>>1       0000 0100 (5)
>>1       0000 0010 (6)
>>1       0000 0001 (7)

number    0111 1111

*/