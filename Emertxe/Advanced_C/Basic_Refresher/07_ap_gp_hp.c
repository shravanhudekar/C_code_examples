/****************** User referance **************************
Name: Shravan Hudekar
Description: Calculate AP GP and HP seires for given values.

sample input:   Enter the First Number 'A': 2
                Enter the Common Difference / Ratio 'R': 3
                Enter the number of terms 'N': 5

sample output:  AP = 2, 5, 8, 11, 14
                GP = 2, 6, 18, 54, 162
                HP = 0.500000, 0.200000, 0.125000, 0.090909, 0.071428
                
*************************************************************/
/* steps
1. take user inputs
    A = First number
    R = Common difference(AP & HP), Common ratio(GP)
    N = number of terms
2. generate series for AP (Arithmetic Progression)
    2.1 run loop (i=0;i<N;i+=2)
    2.2 print seq=i+A ..... so on
*/


#include<stdio.h>

int main ()
{

    int A,R,N,i,j;

    printf("Enter the First Number 'A': ");
    scanf("%d",&A);
    printf("Enter the Common Difference / Ratio 'R': ");
    scanf("%d",&R);
    printf("Enter the number of terms 'N': ");
    scanf("%d",&N);

    if(A>0 && R >0 && N >0)
    {
        printf("AP = ");
        j=0;
        for(i=A; j<N; i+=R)
        {
            printf("%d ",i);
            j++;
        }

        printf("\nGP = ");
        j=0;
        for(i=A; j<N; i*=R)
        {
            printf("%d ",i);
            j++;
        }

        printf("\nHP = ");
        j=0;
        for(i=A; j<N; i+=R)
        {
            printf("%lf ",(double)1/i);
            j++;
        }
    }

    else
    {
        printf("Invalid input\n");
    }
    
}