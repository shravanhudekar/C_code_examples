#include <stdio.h>

int fun(int n)
{
    static int x=0;
    
    if(n>0)
    {
        x+=1;
        printf("n=%d x=%d\n",n,x);
        /* 
        ret + x
        0   + 5 = 5
        5   + 5 = 10
        5   + 5 = 15
        5   + 5 = 20
        5   + 5 = 25
        */
        return fun(n-1)+x;
    }
    
    return 0;
}
int main()
{
   int a=5;
   printf("%d\n",fun(a));
   

    return 0;
}