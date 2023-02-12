#include<stdio.h>

#define FOO 50

//to redefine macro first undefine it and the re-define
#undef FOO
#define FOO 60

int main()
{
// printing % and "" in string 
    printf("\nmy percentage in SSC is: \"%d%%\"",FOO);

    return 0;
}

/**|OUTPUT:|
 *  my percentage in SSC is: "60%"
 * /