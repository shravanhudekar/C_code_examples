#include<stdio.h>

int main()
{
    char arr;

    scanf("%c",&arr);
    printf("%c\n",arr);

    // char str[100];
    // scanf("%s",str);
    // printf("%s\n",str);

    char sne[50];
  // scanf("\n");
  //printf("hello\n");
    scanf("%[^\n]%*c",sne);
    printf("%s\n",sne);
}