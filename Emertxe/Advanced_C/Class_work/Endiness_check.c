#include <stdio.h>

int main()
{
   int num=0x12345678;
  
   char *c=(char *)&num;
   
   if((num & 0xFF) ==(c[0]))
   {
       printf("little endian");
   }
   
   else
   {
       printf("big endian");
   }
}  