#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() 
{
    char *s[10][1024]={0},str[40];

    for(int i=0;i<9;i++)
    {
        scanf("\n");
        scanf("%[^\n]",str);
        memcpy(s[i],str,strlen(str));
        
    }

   for(int i=0;i<9;i++)
    {
        printf("%s\n",s[i]);

    
    }
    return 0;
}

/*
1. take all string as input and store it in char pointer array
2. check 0th and 2nd char of every string and based on S(split) or C(combine)  and M(method), C(class), V(variable) jump to particular function.
3. first convert string based on M/C/V then call S/C.
 
*/
