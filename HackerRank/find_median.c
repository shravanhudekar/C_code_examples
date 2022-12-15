#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

int median(int *a,int n)
{
    int result,temp;

    for(int i=0;i<n;i++)
    {
        for(int j=i;j<n;j++)
        {
            if(a[j]<a[i])
            {
                temp=a[i];
                a[i]=a[j];
                a[j]=temp;
            }

        }
        printf("%d  ",a[i]);
    }


    return (a[n/2]);
}

int main()
{
    int n,result;
    scanf("%d",&n);
    int *arr=(int *)malloc(n*sizeof(int));

    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }

    result=median(arr,n);
    printf("\n%d\n",result);
    return 0;
    
}