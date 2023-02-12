/*****************************************************************************************
 * Create a function that accepts different types of Data arguments & returns an integer *
 *****************************************************************************************/ 

// currently not working
#include <stdio.h>

int func(void *n)
{

    int m=*n;

    return m;
}
int main()
{
    char c='A';

    printf("%d",func(&c));
    

    return 0;
}