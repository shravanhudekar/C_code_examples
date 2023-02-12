#include<stdio.h>
#include<stdint.h>
#include<stdlib.h>
#include <math.h>

#define LEN  10+1
#define ZERO  (10)+1

int main()
{
    int arr[LEN]={2};

    arr[0]=(5);

    printf("%d %d",arr[0],sizeof(arr));

    return 0;

}