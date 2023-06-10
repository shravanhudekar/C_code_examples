#include <stdio.h>

int main()
{
    int a = 10;
    int b = 20;
    int c = 30;

    int *ptr[3];

    ptr[0] = &a;
    ptr[1] = &b;
    ptr[2] = &c;

    printf ("%d %d %d\n",*ptr[0],*ptr[1],*ptr[2]);
    printf ("%d %d %d\n",*(ptr[0]),*(ptr[1]),*(ptr[2]));
    printf ("%d %d %d\n",*(*(ptr+0)),*(*(ptr+1)),*(*(ptr+2)));
   // printf ("%x %x %x\n",&a,&b,&c);

    return 0;
}