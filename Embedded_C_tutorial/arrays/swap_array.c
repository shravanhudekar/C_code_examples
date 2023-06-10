#include<stdio.h>

int main()
{
    int arr[5]={6,8,10,3,5},temp;
    int *p=arr;

    for(int i=0;i<5;i++)
    {
        for(int j=0;j<5-1;j++)
        {
            if(*(p+j+1)<*(p+j))
            {
                temp=*(p+j+1);
                *(p+j+1)=*(p+j);
                *(p+j)=temp;
            }
        }
    }

    printf("min: %d max: %d\n",arr[0],arr[4]);
}