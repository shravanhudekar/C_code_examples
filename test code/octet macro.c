#include<stdio.h>
#include<stdint.h>

#define x 0b1011001000000000
#define OCT 017

#define MACRO1 "macro1"
#define MACRO2 MACRO1"|macro2"          //may give warning due to no spacing
#define APPEND(x, y) x ## y                  // need to added additional code

int main()
{
    int a=x;
 
    printf("%d\n",a);

    printf("%s\n",MACRO2);

    return 0;
}