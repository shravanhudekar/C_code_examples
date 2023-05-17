#include<stdio.h>
#include<stdint.h>
#include "print_binary.h"

int main()
{
    uint32_t data, bit_count=0;

    printf("enter a no. ");
    scanf("%d",&data);
    printBinary(data,THIRTYTWO_BIT);

   // for(int i=0;i<(sizeof(data)*8);i++)                        // 4 bytes * 8 = 32bits
    while(data != 0)
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
