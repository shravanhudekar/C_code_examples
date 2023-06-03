#include <stdio.h>

int main()
{
    double x = 7.2;
    void *vptr = &x;

    printf("%hhx\n", *(char *)vptr);                       // derefrancing pointer by typcasting it from void to char
    printf("%hhx\n", *(char *)(vptr + 7));
    printf("%hx\n", *(short *)(vptr + 3));
    printf("%x\n", *(int *)(vptr + 0));

    return 0;
}