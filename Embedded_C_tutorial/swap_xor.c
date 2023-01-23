#include <stdio.h>
#include <stdint.h>

#define SWAP(x,y) (x^=y^=x^=y)

/* consider example x= 4 y=9
*
*  SWAP(4,9)    (x=4^9)  0100 ^ 1001  x= 1101 (12)
*               (y=9^12) 1001 ^ 1101  y= 0100 (4)
*               (x=12^4) 1101 ^ 0100  x= 1001 (9)
*
* Hence x=9 and y=4
*/ 

#define SWAP_NIBBLES(x) (((x & 0x0F))<<4) | (((x & 0xF0))>>4)
/* consider x = 63
*                   0011 1111 & 0000 1111 = 0000 1111  <<4(LEFT SHIFT BY 4)  = 1111 0000 |
*                   0011 1111 & 1111 0000 = 0011 0000  >>4(RIGHT SHIFT BY 4) = 0000 0011
*
* ORing both results u get 1111 0011 (243)
*/

#define SWAP_BYTE(x) (((x & 0xFF) << 8) | ((x & 0xFF00) >> 8))
/* above same methodology used here insted of 4 bit nibbles 8 bit i.e. 1 byte is swaped 
*  considering x is of 2bytes(16bits) 
*/

#define SWAP_ENDIANS(x) (((x & 0x000000FF) << 24) | \
                         ((x & 0x0000FF00) << 8)  | \
                         ((x & 0x00FF0000) >> 8)  | \
                         ((x & 0xFF000000) >> 24))

void printBinary8(uint8_t number)
{
   // printf("0b ");
    for(uint8_t bit_mask = 0x80; bit_mask; bit_mask >>= 1)      // loop until 'bit_mask' is '0'
    {
        printf("%d", (bit_mask & number)?1:0);
         if(bit_mask == 16)
        { printf(" ");}
    }
    printf("\n");
}

void printBinary16(uint16_t number)
{
   // printf("0b ");
    for(uint16_t bit_mask = 0x8000; bit_mask; bit_mask >>= 1)      // loop until 'bit_mask' is '0'
    {
        printf("%d", (bit_mask & number)?1:0);
        if(bit_mask & 0x1111)
        { printf(" ");}
    }
    printf("\n");
}

void printBinary32(uint32_t number)
{
   // printf("0b ");
    for(uint32_t bit_mask = 0x80000000; bit_mask; bit_mask >>= 1)      // loop until 'bit_mask' is '0'
    {
        printf("%d", (bit_mask & number)?1:0);
        if(bit_mask & 0x11111111)
        { printf(" ");}
    }
    printf("\n");
}
int main()
{
    // uint8_t a,b;                    // compiler overwrites 'a' after scanning 'b'
    //                                 // as it always update register value in terms on 32bits
    // uint16_t c= 1032;

    int a,b,c=9728;

    printf("Enter two no. (a,b): ");
    scanf("%u%u",&a,&b);
    
    SWAP(a,b);
    printf("swaped: a:%d b:%d\n",a,b);

    printBinary8(a);
    a=SWAP_NIBBLES(a);
    printf("swaped nibles x: %d\t",a);
    printBinary8(a);

    printBinary16(c|b);
    c = SWAP_BYTE((c|b));
    printf("Swped Bytes: %d\t",c);
    printBinary16(c);

    printBinary32(123876);
    int d=SWAP_ENDIANS(123876);
    printBinary32(d);

    return 0;
} 
/* |OUTPUT:|

enter two no. (a,b): 12 29
swaped: a:29 b:12
0001 1101

swaped nibles x: 209    1101 0001

                        0010 0110 0000 1100 
Swped Bytes: 3110       0000 1100 0010 0110

0000 0000 0000 0001 1110 0011 1110 0100  - 0x0001E3E4

1110 0100 0000 0000 0000 0000 0000 0000  - 0xE4000000       (x & 0x000000FF) <<24 |
0000 0000 1110 0011 0000 0000 0000 0000  - 0x00E30000       (x & 0x0000FF00) << 8 |   
0000 0000 0000 0000 0000 0001 0000 0000  - 0x00000100       (x & 0x00FF0000) >> 8 |
0000 0000 0000 0000 0000 0000 0000 0000  - 0x00000000       (x & 0xFF000000) >> 24

1110 0100 1110 0011 0000 0001 0000 0000  - 0xE4E30100
*/