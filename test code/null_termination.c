#include<stdio.h>

void print (char *c)
{
    while(*c!='\0')
    {
        printf("%c",*c);
        c++;
    }
}

// void print (const char *c)
// {
//    c[0]= 'A';    // invalid
// }


int main()
{
    char c[20]="Hello";         //string gets stored in the space of array
    // char *c = "hello";       // string get stored at compile time as constant in code(.text)
    // c[0]= 'A';               // is invalid for above case

    print(c);
}