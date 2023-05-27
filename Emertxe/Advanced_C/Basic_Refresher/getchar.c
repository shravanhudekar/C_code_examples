#include<stdio.h>
#include<ctype.h>

int main()
{
    char ch;

    for(;(ch=getchar()); ch != EOF)
    {
        putchar(toupper(ch));
    }

    puts("EOF Received");
    return 0;
}

/**
 * @brief OUTPUT
a
A
b
B
c
C
d
D
 * 
 */