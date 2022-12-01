#include<stdio.h>

int main()
{
    
    const int x=3;    // int const x; both are same
    //const  int  *y=10;  //data is Read-only
    int const *y=10;
    int * const p=15; // pointer is read only varable data can be changed
   
    int  const const k ;  // both are read only



    printf("%d\n%d\n%d\n%d\n", x,*y,p,k);

}

