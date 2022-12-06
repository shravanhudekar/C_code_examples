#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>


int main()
{
    char str[1001];
    int len,i=0,j,count=0;

    scanf("%s",str);

   for(i=0;i<10;i++)
   {    
        j=0,count=0;
        while(str[j] != '\0')
        {
            if((str[j]-'0')==i)
            {
                count++;
            }
            j++;
        }

        printf("%d ",count);
   }

    return 0;
}