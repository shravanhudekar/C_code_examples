/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>

int main()
{
    int num1 =1, num2=1;
    float num3=1.7, num4=1.5;
    
 //   num1+=num2 +=num3 +=num4;
    
    printf("float: %lu num: %lu\n",sizeof(0.5),sizeof(0.7));


    num1=1;
    
    if(num1-- && num2)
    {
        printf("True num1:%d num2: %d\n",num1,num2);
    }
    
    else
    {
        printf("False num1:%d num2: %d\n",num1,num2);
    }
    return 0;
    
}