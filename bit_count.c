#include<stdio.h>
#include<stdint.h>


int main()
{
    uint32_t data= 0xAA, bit_count=0;

    for(int i=0;i<(sizeof(data)*8);i++)
    {
        //printf("data=%x    i=%d\n",data,i);
        if((data & 0x001)==1)
        {
            bit_count++;
        }
        data=(data>>1);
        
    }
    printf("%x",data);
    printf("Total set bits:%d",bit_count);

}