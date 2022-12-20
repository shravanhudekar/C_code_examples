#include <stdio.h>
#include <stdlib.h>

void swap(int *a,int *b) //swap without temp variable
{
    *a+=*b;
    *b=*a-*b;
    *a-=*b;
}

int main()
{
    int num, *arr, i;
    scanf("%d", &num);
    arr = (int*) malloc(num * sizeof(int));
    for(i = 0; i < num; i++) {
        scanf("%d", arr + i);
    }
    
    for(i=0;i<(num/2);i++)                   
    {
        swap(&arr[i],&arr[num-i-1]);
    }

    /* Write the logic to reverse the array. */

    for(i = 0; i <num; i++)
        printf("%d ", *(arr + i));
    return 0;
}