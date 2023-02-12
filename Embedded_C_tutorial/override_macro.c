#include<stdio.h>

#define FOO 10

//to redefine macro first undefine it and the re-define
#undef FOO
#define FOO 20

int main()
{
    printf("%d", FOO);
// printing % and "" in string 
    printf("\nmy percentage in SSC is: \"62%%\"");

    return 0;
}