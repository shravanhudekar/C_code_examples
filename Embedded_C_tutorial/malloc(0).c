#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdint.h>

int main()
{
    int a[]={11,12,13,14,15,16,17,18,19,20};
   // int *p; // uninitialized pointer (may over write any memory location)
   // int *p = NULL; // givess segmentation fault
    int *p= (int*)malloc(0);   // malloc(0) will assign an address to pointer but no dynamic meomry will be allocated  

    memcpy(p,a,sizeof(a));      // this may overwrite data in memory

    // free(p);  // run time error

    for(int i=0;i<sizeof(a)/4;i++)
    printf("value: %d  address: %x\n",p[i], &p[i]);

    printf("%x %x",(malloc(0)),malloc(1));
}