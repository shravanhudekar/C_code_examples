#include<stdio.h>

int main()
{
    int a,b,c=0;

    a = 13;
    b = 5;
    c = (1,2,3,4555)+b++; //printf("%d %d %d\n",a,b,c) + b++;               
    printf("%d",c);

    return 0;
}