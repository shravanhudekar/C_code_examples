#include<stdio.h>
#include<stdint.h>
//#include "print_binary.h"

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


int main()
{
    uint32_t data, bit_count=0;

    printf("enter a no. ");
    scanf("%d",&data);
    printBinary(data,THIRTYTWO_BIT);

    for(int i=0;i<(sizeof(data)*8);i++)                        // 4 bytes * 8 = 32bits
    {
      
        /**** Method 1 ****/                         // MSB is set to zero by right shift
        // if((data & 0x001)==1)
        // {     bit_count++;  }
        // data=(data>>1); 

        /**** Method 2 (Brian Kernighan's Algorithm) ****/                         
        if(data){   bit_count++;  }                                             // LSB is set zero by ANDing with N-1  (optimized compare to method 1 except(7,15))
        else { break;}  
        data &= data-1; 
    }

    printf("Total set bits:%d",bit_count);

}
