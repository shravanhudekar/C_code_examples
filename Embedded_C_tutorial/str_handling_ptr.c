/* C Prog - Take Name as characters and add fixed string "SIEMENS" starting char 3 using pointers */
#include <stdio.h>
#include <stdint.h>
#include <string.h>

int main()
{
    char name[20], str[]={"SIEMENS"};
    int i=0;

    printf("enter your name: ");

    do
    {
        scanf("%c",&name[i]);

    }while(name[i++]!= '\n');

    printf("%s",name);
    return 0;
}