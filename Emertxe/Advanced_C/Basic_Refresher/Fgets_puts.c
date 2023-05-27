#include<stdio.h>
#include<ctype.h>

int main()
{
    char str[10];

    puts("Enter the string");
   // gets(str);                    //reads whole input string, omits null char and gives segmentaition fault if string length excceds size of str 
    fgets(str,10,stdin);
    puts(str);

    return 0;
}