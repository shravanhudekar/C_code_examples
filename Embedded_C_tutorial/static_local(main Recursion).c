#include<stdio.h>

int main()
{
    static int i = 5;

    if(--i)
    {
        main();
        //return main();
    }

    printf("i %d \n",i);

    return 0;
}

#if 0

int foo()
{
    static int i;

    return i;
}
int main()
{
    static int x = foo();       //compile time  foo() runtime    

    printf("x %d\n",x);

    return 0;
}

#endif

#if 0
int *foo()
{   
    int i = 10;             // runtime
    static int *j = &i;   //compile time

    return j;
}

int main()
{
    int *i;

    i=foo();

    printf("i: %d\n", *i);

    return 0;
}
#endif