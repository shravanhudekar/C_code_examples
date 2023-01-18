#include <stdio.h>
#include<stdint.h>
int main()
{
    uint8_t reg=0,cmd=0;
    uint16_t buff=0;
    
    reg=0x11;
    cmd=0x64;
    
     buff= (((0x80) | (reg & 0xff))  << 8);        //best approach
     buff= (((0x80) + (reg & 0xff)) *(1 << 8));    
     
     printf("%x",buff);
     
     return 0;
    
   
}
