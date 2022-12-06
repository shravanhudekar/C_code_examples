/********************************************************
 *  Application used in accessing whole register        *
 *  or each segment(byte by byte) of register           *
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
    combine_t d;
    uint8_t *ptr;
    d.frame = 0x10203040;

    ptr=&d.data;
  
    printf("frame: %x\n",d.frame);

    for(int i=0;i<sizeof(d.frame);i++)
    {    
        printf("data_%d: %x\n",i,*(ptr+i));                   //most preffered normally but, not preffered in code porting
    }
    
}

// OUTPUT:

// frame: 10203040
// data_0: 40
// data_1: 30
// data_2: 20
// data_3: 10