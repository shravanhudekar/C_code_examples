#include<stdio.h>
int c;
int* add(int *a, int *b)  // define return address as pointer type
{
    c = (*a)+(*b);
    printf("sum: %d\n",c);
    return &c;   // u cant send address of c as after execution of this instruction this function and its varable will be poped out 

}

int main()
{
    int a=2,b=4;
    int *ptr = add(&a,&b);

    printf("sum: %d\n",*ptr);

    return 0;
}