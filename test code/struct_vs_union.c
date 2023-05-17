#include<stdio.h>
#include<stdint.h>

typedef union pack
{
    uint16_t data;
    

    struct sample
    {
        uint8_t low;
        uint8_t high;
        
    }sample;
   
}packet_t;

typedef struct FCM
{
    packet_t config_data;
    uint8_t i;
}FCM_t;


int main()
{
    FCM_t frame,*ptr1;
    struct sample *ptr;

    ptr1=&frame;
    ptr=&ptr1->config_data; // not proper

    

    printf("%x %x",frame.config_data.sample.low,frame.config_data.sample.high);

    return 0;
}