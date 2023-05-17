#include<stdio.h>

int fact(n)
{
    static int facto=1;
    if(n>0)
    {

        facto=n*n-1;
       return fact(n-1);
    }
    printf("%d\n",facto);
    return 1;
   
}
int main()
{
   int n=5;

    printf("%d",fact(n));
}