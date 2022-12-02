#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>

void main()
{
    uint8_t msk_odd = 0x1;
    int num;
    // uint8_t msk2_even = 0x2;
    scanf("%d",&num);
    if(num & msk_odd)
    {
        printf("odd");
    }
    else{
        printf("even");
    }


}