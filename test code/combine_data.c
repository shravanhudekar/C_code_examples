/********************************************************
 *  Application used in accessing whole                 *
 * register or each segment(byte by byte) of register   *
 * *****************************************************/
#include <stdio.h>
#include <stdint.h>

typedef union 
{
    uint8_t data;
    uint32_t frame;

}combine_t;



void main()
{
    combine_t d,*ptr;
    d.frame = 0x10203040;
    ptr=&d;
  
    printf("%d\n",d.frame);

    for(int i=1;i<=4;i++)
    {    
        printf("%x\n",(ptr+i)->data);
    }
    
}