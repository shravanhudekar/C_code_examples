#include <stdio.h>

int main()
{
    int a[5] = {1,2,3,4,5};
    int *p;
    p=a;

    p[0]=6;

    printf("a= %d\n",a[0]);
    printf("*a= %d\n",*a);
    printf("a+1= %d\n",(p+1));
    printf("*a+1= %d\n",*(p+1));
    return 0;
}