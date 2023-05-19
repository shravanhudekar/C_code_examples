/****************** User referance **************************
Name: Shravan Hudekar
Description:  find the median of two unsorted arrays
sample input: 
Enter the 'n' value for Array A: 5
Enter the 'n' value for Array B: 5

Enter the elements one by one for Array A: 3 2 8 5 4
Enter the elements one by one for Array B: 12 3 7 8 5

sample output:  Result :
Median of array1 : 4
Median of array2 : 7
Median of both arrays : 5.5    
*************************************************************/

#include<stdio.h>

void get_array(int a[], int n)
{
    for(int i=0; i<n; i++)
    {
        scanf("%d",&a[i]);
    }
}
void bubble_sort(int a[], int size)
{
    int i,j,temp;

    for(i=0; i<size; i++)
    {
        for(j=0; j<size-1; j++)
        {
            if(a[j] > a[j+1])
            {
                temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }
    }
}

float median(int a[], int n)
{
    float mid;
    if(n%2 != 0)
    {
        mid=(float)a[n/2];
        printf("%g\n",mid);
    }

    else
    {
        n/=2;
        mid = ((float)(a[n]+a[n-1])/2);
        printf("%g\n",mid);
    }

    return mid;
}
int main()
{
    int n,m,i;
    float mid1,mid2;

    printf("Enter the 'n' value for Array A: ");
    scanf("%d",&n);
    printf("Enter the 'n' value for Array B: ");
    scanf("%d",&m);

    int arr1[n];
    int arr2[m];

    printf("Enter the elements one by one for Array A: ");
    get_array(arr1,n);

    printf("Enter the elements one by one for Array B: ");
    get_array(arr2,m);

    bubble_sort(arr1,n);    
    bubble_sort(arr2,m);

    printf("Median of array1 : ");
    mid1 = median(arr1,n);
    printf("Median of array2 : ");
    mid2 = median(arr2,m);

    printf("Median of both arrays : %g",(mid1+mid2)/2);

    return 0;
}
