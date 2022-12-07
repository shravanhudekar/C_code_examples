#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>


int main()
{
    char str[1001];
    int len,i=0,j,count=0;

    scanf("%s",str);                              //  |INPUT:| lw4n88j12n1
   // printf("%d\n",strlen(str));
   for(i=0;i<10;i++)                              // we need count of 0-9 digits 
   {    
        j=0,count=0;
        while(str[j] != '\0')                     
        {
            if((str[j]-'0')==i)                    // every digit(0-9) ASCII(48-57) checked across input string
            {
                count++;
            }
            j++;
        }

        printf("%d ",count);                       // print count of every digit 
   }                                                                             // |OUTPUT:|  0 2 1 0 1 0 0 0 2 0 

    return 0;
}