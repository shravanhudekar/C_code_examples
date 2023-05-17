/********************************************************
 *  Application used in accessing whole                 *
 * register or each segment(byte by byte) of register   *
 * *****************************************************/

#include <stdio.h>
#include <stdint.h>

typedef union 
{
    struct combine_data
    {
        uint8_t  data_0;
        uint8_t  data_1;
        uint8_t  data_2;
        uint8_t  data_3;
    }combine_data_t;

    uint32_t frame;

}combine_t;

void main()
{
    combine_t d;
    d.frame = 0x10203040;
    
    printf("%x\n",d.frame);
 
/* access data individually from frame */

    printf("%x\n",d.combine_data_t.data_0);
    printf("%x\n",d.combine_data_t.data_1);
    printf("%x\n",d.combine_data_t.data_2);
    printf("%x\n",d.combine_data_t.data_3);
    
/* setting indiviual byte in frame */

    // d.combine_data_t.data_3=0x05;       //MSB
    // d.combine_data_t.data_2=0x04;
    // d.combine_data_t.data_1=0x03;
    // d.combine_data_t.data_0=0x02;       //LSB
    // printf("%d\n",d.frame);
    
}