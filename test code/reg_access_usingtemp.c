/********************************************************
 *  Application used in accessing whole                 *
 * register or each segment(byte by byte) of register   *
 * *****************************************************/

#include <stdio.h>
#include <stdint.h>

typedef union 
{
    //uint8_t data;
    uint32_t frame;

}combine_t;

void append(int num,int index,combine_t *d)
{
    static uint32_t temp=0;
    temp |= (num<<8*index);
    d->frame=temp;
}

int retrive(combine_t *d)
{

    uint8_t num = d->frame & 0xFF;
    d->frame=(d->frame>>8);

    return num;
}

void main()
{
    int arr[4]={0x10,0x20,0x30,0x40};
    combine_t d;

    d.frame=0;

    for(int i=0;i<4;i++)
    {
        append(arr[i],i,&d);   
    }
    printf("apeeded frame: %x \n",d.frame);

    for(int i=0;i<4;i++)
    {
        printf("retrive %d =  %d\n",i,retrive(&d));
    }
}

// OUTPUT:

// apeeded frame: 40302010 
// retrive 0 =  16
// retrive 1 =  32
// retrive 2 =  48
// retrive 3 =  64