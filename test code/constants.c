#include<stdio.h>

int main()
{
    
    const int x=3;    // int const x; both are same
    int z=10;
    //const  int  *y=10; 
    int const *y=&z;        //data is Read-only
    z=10;
    int * const p=15; // pointer is read only variable data can be changed
   
    int  const const k ;  // both are read only



    printf("%d\n%d\n%d\n%d\n", x,*y,p,k);

}

