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

void append(int num, combine_t *d)
{
    d->frame=(d->frame<<8);
    d->data=num;
      
}

void main()
{
    int arr[4]={0x10,0x20,0x30,0x40};                 //LSB-MSB
    combine_t d;

    d.frame=0;
    
    for(int i=3;i>=0;i--)
    {
        printf("data%d: %d\n",i,arr[i]);
        append(arr[i],&d);     
    }

    printf("%x \n",d.frame);
}    