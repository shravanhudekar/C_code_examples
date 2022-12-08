#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
//Complete the following function.

int Max(int a, int b, int k)
{
    return((a>b && a<k) ? a:b);
}
void calculate_the_maximum(int n, int k) 
{
    int i,j,Gre_AND=0,Gre_OR=0,Gre_XOR=0,temp1,temp2,temp3;
    
    for(i=1;i<=n;i++)
    {
        for(j=i+1;j<=n;j++)
        {
            
            temp1 = i & j;
            temp2 = i | j;
            temp3 = i ^ j;

           // printf("i: %d  j: %d   AND: %d    OR:%d    XOR:%d\n",i,j,temp1,temp2,temp3);

            Gre_AND=Max(temp1,Gre_AND,k);
            Gre_OR=Max(temp2,Gre_OR,k);
            Gre_XOR=Max(temp3,Gre_XOR,k);
        }
    }
    
    printf("%d\n%d\n%d\n",Gre_AND,Gre_OR,Gre_XOR);
 
}

int main() {
    int n, k;
  
    scanf("%d %d", &n, &k);
    calculate_the_maximum(n, k);
 
    return 0;
}


/***************************************************
 *                    |OUTPUT|                     *
 * *************************************************
7 4                                                              //INPUT

i: 1  j: 2   AND: 0    OR:3    XOR:3
i: 1  j: 3   AND: 1    OR:3    XOR:2
i: 1  j: 4   AND: 0    OR:5    XOR:5
i: 1  j: 5   AND: 1    OR:5    XOR:4
i: 1  j: 6   AND: 0    OR:7    XOR:7
i: 1  j: 7   AND: 1    OR:7    XOR:6
i: 2  j: 3   AND: 2    OR:3    XOR:1
i: 2  j: 4   AND: 0    OR:6    XOR:6
i: 2  j: 5   AND: 0    OR:7    XOR:7
i: 2  j: 6   AND: 2    OR:6    XOR:4
i: 2  j: 7   AND: 2    OR:7    XOR:5
i: 3  j: 4   AND: 0    OR:7    XOR:7
i: 3  j: 5   AND: 1    OR:7    XOR:6
i: 3  j: 6   AND: 2    OR:7    XOR:5
i: 3  j: 7   AND: 3    OR:7    XOR:4
i: 4  j: 5   AND: 4    OR:5    XOR:1
i: 4  j: 6   AND: 4    OR:6    XOR:2
i: 4  j: 7   AND: 4    OR:7    XOR:3
i: 5  j: 6   AND: 4    OR:7    XOR:3
i: 5  j: 7   AND: 5    OR:7    XOR:2
i: 6  j: 7   AND: 6    OR:7    XOR:1
3                                                         // MAX of AND
3                                                         // MAX of OR
3                                                         // MAX of XOR

*/