#include<stdio.h>
#include<unistd.h>

int main()
{
    char ch='y';

    printf("Enter a string: ");

    while(ch != 'n')
    {
        scanf("%c",&ch);
        printf("\n");
        //_fpurge(stdin);    //erase content of stdin buffer
      //  while(getchar()!='\n');
        printf("%c",ch);
    } 
    return 0;
}