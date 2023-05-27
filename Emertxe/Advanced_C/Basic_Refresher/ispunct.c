/****************** User referance **************************
Name: Shravan Hudekar
Description:   implement your own ispunct() function
sample input:   a
sample output:  Entered character is not punctuation character
*************************************************************/
#include <stdio.h>

int my_islower(int);                //function declaration

int main()
{
    char ch;
    int ret;
    
    printf("Enter the character: ");
    scanf("%c", &ch);
    
    ret = my_islower(ch);    // function call
   
    if(ret)
    {
        printf("Entered character is punctuation character\n");
    }

    else
    {
        printf("Entered character is not punctuation character\n");
    }
}
/*
 * function check if passed character is lower case alphabet
 * if it falls under range 'a' to 'z' then return true else false
 */
int my_islower(int ch)          //function defination
{
     if(!((ch >= 'a' &&  ch <= 'z') || (ch >= 'A' &&  ch <= 'Z')  || (ch >= '0' &&  ch <= '9') || ch == ' '))
    {
        return 1;
    }

    else
    {
        return 0;
    }
}