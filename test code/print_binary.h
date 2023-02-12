/* PRINT_BINARY H */

#include<stdint.h>

#define EIGHT_BIT 0x80
#define SIXTEEN_BIT 0x8000
#define THIRTYTWO_BIT 0x80000000


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
