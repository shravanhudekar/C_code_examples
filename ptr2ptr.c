#include<stdio.h>

int main()
{
    int x=5;
    int *p=&x;                 // &x=61ff18
    
    int **q=&p;                //&p=61ff14  
    *p=6;              // x=6
    int ***r = &q;             // &q=61ff10    
    **q=*p+2;
    printf("value= %x\n",***r);
}