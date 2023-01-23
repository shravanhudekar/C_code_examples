#include <stdio.h>

int main()
{
    int a=10,b,c;
   {
         b= a+20;   // int b=a+20;
         c= b+a;    // int c=b+a;
    }
    
    float d = c+(b/3);  // not working
    
    printf("%f",d);

    return 0;
}