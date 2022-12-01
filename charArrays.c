#include <stdio.h>

int main()
{
    char c1[6]= "Hello";
  //char c1[6]= {'H','e','l','l','o','\0'};
    char *c2;
    c2=c1;

    printf("c2= %c\n",c2[1]);
    c2[0]='A';
    printf("%s\n",c2);
    
    return 0;
}