#include<stdio.h>

int x ; 
int x = 10;   // value will be assigned at compile time (DEFAULT :  internal linkage)
//static int x = 10; //linkage disagreement compiler error (internal linkge due to its scope)
int x ;       
/*it won't allocate memory with 4 bytes , waites till the linker stage 
* if it finds any init, it will be linking to that or if it won't finds any init, 
* it will be allocated with memory and initialized with the default value zero 
* (only with global varaibles)  */ 
//int x = 29  // this will give error as multiple defination

void foo()
{
    printf("%d\n",x);
}

int main()
{
    foo();

    return 0;
}