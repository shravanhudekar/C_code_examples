/******************************* User referance *****************************************
Name: Shravan Hudekar
Description:  print all primes using Sieve of Eratosthenes method
sample input:   20
sample output:  The primes less than or equal to 20 are : 2, 3, 5, 7, 11, 13, 17, 19
*****************************************************************************************/

#include<stdio.h>

int main()
{
   int n,i,j;
    
    //user inputs
    printf("Enter the value of 'n' : ");
    scanf("%d", &n);

    if(n>1)
    {
        int arr[n-1];                           //create array of size n-1

        for (i=2; i<=n; i++)
        {
            arr[i-2]=i;
        }

        for(i=2; i*i<=n; i++)
        {
            for(j=0; j<n; j++)
            {
                if(arr[j]%i == 0)                //check array element is divisible 
                {
                    if (arr[j] != 0)             //avoid if array element is 0
                    {
                        if(arr[j] != i)          // element should not be equal to divisor
                        {
                            arr[j]=0;           //clear array element if divisible
                        }
                    }
                }     
            }
        }


        printf("The primes less than or equal to %d are : ",n);

        for (i=0; i<n; i++)
        {
            if(arr[i])
            {
                printf("%d ",arr[i]);           // print prime no.
            }  
        }
    }

    else
    {
        printf("Please enter a positive number which is > 1\n");
    }

    return 0;
}
