#include<stdio.h>
#include<unistd.h>

int main()
{
    char ch='y';

    printf("Enter a string: ");

    while(ch != 'n')
    {
        scanf("%c",&ch);              // scan only 1 char
        printf("\n");
        __fpurge(stdin);    //erase content of stdin buffer
        //while(getchar()!='\n');     // takes string until \n is encounter
        printf("%c\n",ch);              // prints 1st char scanned
    } 
    return 0;
}