#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *a=(int *)malloc(2*sizeof(double));
    //int *a[]=(double *)malloc(2*sizeof(double));

   // for (int i=0; i<2;i++)
  //  {
        for (int j=0; j<4;j++)
        {
            scanf("%d",&a[j]);
          //  scanf("%d",&a[i][j]);
        }

  //  }
    return 0;
}