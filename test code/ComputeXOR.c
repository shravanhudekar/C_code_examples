//Find XOR of numbers from the range [L,R]
#include<stdio.h>
#include<stdint.h>


int find_XOR(int n)
{
   // if n multiple of 4 its n
   if(n%4 == 0)
    return 0;
    
    // if n%4 gives remainder 1
    if(n%4 == 1)
     return 1;

    // if n%4 gives remainder 2
    if(n%4 == 2)
    return n+1;

    // else n%4 gives remainder 3
    return 0;
}

int findXOR(int l, int r)
{
    return (find_XOR(l-1) ^ find_XOR(r)); 
}

int main()
{
    int x,y,z;

    printf("enter value x and y: ");
    scanf("%d%d",&x,&y);

    z=findXOR(x,y);

    printf("%d",z);
    
    return 0;
}