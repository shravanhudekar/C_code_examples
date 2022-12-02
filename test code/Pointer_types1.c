#include <stdio.h>

int main()
{
    int *p;
    int a=1024;

    p=&a;

    printf("address of a= %d, value = %d\n",p,*p);
    printf("address of a+1= %d, value = %d\n",(p+1),*(p+1));

    char *p0;

    p0=(char*) p;

     printf("address of p0= %d, value = %d\n",p0,*p0);
    printf("address of p0+1= %d, value = %d\n",(p0+1),*(p0+1));

    return 0;
   
}