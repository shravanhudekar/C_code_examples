#include <stdio.h>

int main()
{
    int i=0;
    while(i<10);                        //due to semicolon control never reaches the printf statement so 'i' is not incremented and while becomes infinite loop
    {
        printf("%d\n",i++);
    }

    return 0;
}