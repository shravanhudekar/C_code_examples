#include<stdio.h>

int main()
{
    char str1[5]={'H','E','L','L','O'};        //char array (not valid string)
    char str2[6]={'W','O','R','L','D','\0'};  //valid string
    char str[]  ={'H','E','L','L','O','\0'}; //valid string
    char str3[6]={"H","e","l","l","o"};     //invalid
    char str4[6]={"H" "e" "l" "l" "o"};    //valid string it automatically concatinate string with \0
    char str5[6]={"Hello"};               //valid
    char str6[] ={"Hello"};              //valid
    char str7[5]={"Hello"};             //invalid


    printf("%s",str1);
    printf("%s",str2);

    //output of above is HELLOWORLDWORLD
    //because 'str1' is stored followed by 'str2' and printf print till it gets null char
    //it may also give garbage value after 'str1'

}