#include<stdio.h>


int main()
{


#if 0
    int age;
    char arr_1[10];
    char arr_2[10];

    sscanf("I am 30 years old", "");
#endif

#if 1
    char *str="1234";
    int sum=0;

    sscanf(str,"%d",&sum);    //converts char into integer   ASCII to integer (atoi)

    printf("%d\n",sum);

#endif

}