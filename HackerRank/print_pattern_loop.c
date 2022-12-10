#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() 
{

    int n,i,j,k,l,m;
    scanf("%d", &n);

  	m = (2*n)-2;
    for(i=0;i<=m;i++)
    {   
        if(i>n-1) { l=m-i; }
        else { l=i; }

        k=l; 
        for(j=m;j>=0;j--)
        {
            if (j>l) {
                printf("%d ",n);
                if(k>0) { n--; k--;}
            }

            else {
                printf("%d ",n);
                if(k<l) { n++; k++;}
            }          
        }
        printf("\n");  
    }


    //   for(int i = 0; i<2*n-1; i++){
//       for(int j = 0; j<2*n-1; j++){
//             int min;
//             min =i<j? i:j;
//             min = 2*n-2-i < min? 2*n-2-i:min;
//             min = 2*n-2-j<min ? 2*n-2-j:min;
//             printf("%d ",n-min);
//       }printf("\n");
//   }

    return 0;
}

/*
Input: - n = 4

OUTPUT:
j:              6 5 4  3  2 1 0

i:0    l = 0    4 4 4  4  4 4 4
i:1    l = 1    4 3 3  3  3 3 4
i:2    l = 2    4 3 2  2  2 3 4  

i:3    l = 3    4 3 2  1  2 3 4

i:4    l = 2    4 3 2  2  2 3 4
i:5    l = 1    4 3 3  3  3 3 4
I:6    l = 0    4 4 4  4  4 4 4



1. start        loop1 i= 0 - n+2      
2. set k=i  m=n
3. start nested loop2 j= n+2 - 0 
    3.1 if j>i
            print m

            if k>0
                m-- , k--
        else
            print m

            if k<i
                m++ , k++


4. print '\n'

*/