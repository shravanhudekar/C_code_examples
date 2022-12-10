#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() 
{
    char *s[10]={0};

    for(int i=0;i<9;i++)
    {
        scanf("%*[\n] %[^\n]",s[i]);
    }

    for(int i=0;i<9;i++)
    {
        printf("%s\n",s[i]);
    }

    

    return 0;
}
