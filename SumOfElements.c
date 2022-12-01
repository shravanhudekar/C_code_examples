#include <stdio.h>

int SumOfElements(int *a,int size)  //pointer only hold address of array witch is 8 bytes
{
    //int size= sizeof(a)/sizeof(a[0]);   // so doing this will result into 8/4 = 2 bytes
    int i=0, sum=0;
   
    for(i=0;i<size;i++)
    {
        sum+=a[i];
    }
    return sum;
}
int main()
{
    int a[]= {1,2,3,4,5};
    int size= sizeof(a)/sizeof(a[0]); 
    int total = SumOfElements(a,size); // sending array and its size

    printf("Total = %d\n",total);

    return 0;
}