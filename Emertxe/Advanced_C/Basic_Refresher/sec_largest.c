#include <stdio.h>

int third_largest(int [], int);

int main()
{
    int size, ret;
    
    //Read size from the user
    printf("Enter the size of the array : ");
    scanf("%d", &size);
    
    int arr[size];
    
    //Read elements into the array
    printf("Enter the elements into the array: ");

    for(int i=0; i<size; i++)
    {
        scanf("%d",&arr[i]);
    }
    
    //funtion call
    ret = third_largest(arr, size);
    
    printf("Third largest element of the array is %d\n", ret);
}

int third_largest(int a[], int n)
{
    int first=0,sec=0,third=0;

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(first < a[j])
            {
                first=a[j];                         // update largest first element every time when new largest element is found in array
            }

            if((a[j] < first) && (a[j] > sec))
            {
                sec = a[j];                         // update largest second element every time when new largest element is found in array which is smaller then first
            }

              if((a[j] < sec) && (a[j] > third))
            {
                third = a[j];                         // update largest second element every time when new largest element is found in array which is smaller then first
            }
        }
    }

    return third;
}