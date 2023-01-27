#include <stdio.h>
#include <stdint.h>
#include "print_binary.h"

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
/* above same methodology used here instead of 4 bit nibbles 8 bit i.e. 1 byte is swaped 
*  considering x is of 2bytes(16bits) 
*/

#define SWAP_ENDIANS(x) (((x & 0x000000FF) << 24) | \
                         ((x & 0x0000FF00) << 8)  | \
                         ((x & 0x00FF0000) >> 8)  | \
                         ((x & 0xFF000000) >> 24))

<<<<<<< HEAD
#define TWOS_COMPLIMENT(x)  (~(x)+1)

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
int main()
{
    uint8_t a,b;      // compiler overwrites 'a' after scanning 'b'
                        // as it always update register value in terms on 32bits                              
    uint16_t c= 9728;
 
#ifdef SWAPING
    printf("Enter two no. (a,b): ");
=======

int main()
{
    uint8_t a,b;                                   
    uint16_t c= 9728;

 /*******************************************************************************************
  * Because %u stands for "unsigned", it well may be uint64_t and is architecture dependent. 
  * According to man 3 printf, you may want to use length modifier to get sought behaviour, 
  * i.e. %hu (uint16_t) and %hhu (uint8_t).
  * *****************************************************************************************/

    printf("Enter two no. (a,b): ");                  
>>>>>>> 3f189f69f52b6a4b603a1fa021833a5719b2f3d1
    scanf("%hhu%hhu",&a,&b);
    
    SWAP(a,b);
    printf("swaped: a:%d b:%d\n",a,b);

    printBinary(a,EIGHT_BIT);
    a=SWAP_NIBBLES(a);
    printf("swaped nibles x: %d\t",a);
    printBinary(a,EIGHT_BIT);

    printBinary((c|b),SIXTEEN_BIT);
    c = SWAP_BYTE((c|b));
    printf("Swped Bytes: %d\t",c);
    printBinary(c,SIXTEEN_BIT);

    printBinary(123876,THIRTYTWO_BIT);
    int d=SWAP_ENDIANS(123876);
    printBinary(d,THIRTYTWO_BIT);

#else 
    int num,comp;

    printf("Enter unsigned negative no.");
    scanf("%u",&num);

    printf("\nenter no. is: %d\t ~x: %d\n",num,~num);
    printBinary(num,EIGHT_BIT);
    printBinary(~num,EIGHT_BIT);

    comp=TWOS_COMPLIMENT(~num);
    num=TWOS_COMPLIMENT(num);
    

    printf("\n2's comp. is: %d\n",num);
    printBinary(num,EIGHT_BIT);

    printf("\n2's comp. of ~x.: %d\n",comp);
    printBinary(comp,EIGHT_BIT);


#endif

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