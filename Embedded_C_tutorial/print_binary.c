#include<stdio.h>
#include<stdint.h>

void printBinary(uint8_t number)
{
    printf("0b");
    for(uint8_t bit_mask = 0x80; bit_mask; bit_mask >>= 1)      // loop until 'bit_mask' is '0'
    {
        printf("%d", (bit_mask & number)?1:0);
    }
}

int main()
{
    printBinary(127);
    return 0;

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