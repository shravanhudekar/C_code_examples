#include<stdio.h>

int main()
{
    int (*p)[3];
    p=malloc(sizeof(*p)*3);
    
    //2D array representation
    // int a[2][3]= {{1,2,3},{4,5,6}};   
    // p = a;    //p=&a;  //for 1D array
    //end 2D

    (*(p+0))[0]=1;
    (*(p+1))[1]=2;
    (*(p+2))[2]=3;

    printf("%d\n",p[0][0]);
    printf("%d\n",p[1][1]);
    printf("%d\n",p[2][2]);
}

/**
 * (*(p+1))[1]
 * 
*/