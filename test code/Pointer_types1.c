#include <stdio.h>

int main()
{
    int *p;
    int a=1024;

    p=&a;                                                           // pointer holding address of 'a'

    printf("address of a= %x, value = %d\n",p,*p);
    printf("address of a+1= %x, value = %d\n",(p+1),*(p+1));

    char *p0;

    p0=(char*) p;                                                   // pointer holding address of 'p0'

     printf("address of p0= %x, value = %d\n",p0,*p0);
    printf("address of p0+1= %x, value = %d\n",(p0+1),*(p0+1));

    return 0;
   
}

/* |OUTPUT:|

address of a= e6dff8ac, value = 1024                                   // int is of 4bytes 
address of a+1= e6dff8b0, value = -1216849040                          // pointer is incremented by 4 bytes

address of p0= e6dff8ac, value = 0                                      // char is of 1byte
address of p0+1= e6dff8ad, value = 4                                     // pointer is incremented by 1 bytes

*/