#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

int median(int *arr,int n)
{
    int result,temp;

    for(int i=0;i<n;i++)
    {
        for(int j=i;j<n;j++)  //bubble sort
        {
            if(arr[j]<arr[i])
            {
                temp=arr[i];
                arr[i]=arr[j];
                arr[j]=temp;
            }

        }
       // printf("%d  ",arr[i]);
    }


    return (arr[n/2]);
}

void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}
  
/* This function takes last element as pivot, places
the pivot element at its correct position in sorted
array, and places all smaller (smaller than pivot)
to left of pivot and all greater elements to right
of pivot */
int partition(int *arr, int low, int high)
{
    int pivot = arr[high]; // pivot
    int i
        = (low
           - 1); // Index of smaller element and indicates
                 // the right position of pivot found so far
  
    for (int j = low; j <= high - 1; j++) {
        // If current element is smaller than the pivot
        if (arr[j] < pivot) {
            i++; // increment index of smaller element
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quickSort(int arr[], int low, int high)
{
    if (low < high) {
        /* pi is partitioning index, arr[p] is now
        at right place */
        int pi = partition(arr, low, high);
  
        // Separately sort elements before
        // partition and after partition
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}
// NOT working for n=1001, finding median without sorting
//  for(int j=1;j<=n/2;j++)
//         {
//             if(a[n/2]<a[(n/2)+j])
//             {
//                 temp=a[(n/2)+j];
//                 a[n/2]=a[(n/2)+j];
//                 a[(n/2)+j]=temp;
//             }

//             else if(a[n/2]>a[(n/2)-j])
//             {
//                 temp=a[(n/2)-j];
//                 a[n/2]=a[(n/2)-j];
//                 a[(n/2)-j]=temp;

//             }
//         }
//      //   printf("%d  ",a[i]);
//    // }


//     return (a[n/2]);

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