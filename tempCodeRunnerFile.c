/*C prog - Program to swap to variables without using third variable*/

#include<stdio.h>


int swap(int *a, int *b)
{

    *a=*a+*b;
    *b=*a-*b;
    *a=*a-*b;

}

int main()
{
    int x,y;

    printf("enter two no.: ");
    scanf("%d%d",&x,&y);

    swap(&x,&y);

    printf("swaped no. x:%d y:%d",x,y);
}