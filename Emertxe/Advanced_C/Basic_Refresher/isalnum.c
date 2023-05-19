/****************** User referance **************************
Name: Shravan Hudekar
Description:   implement your own isalnum() function
sample input:   a
sample output:  Entered character is alphanumeric character
*************************************************************/
#include <stdio.h>

int my_isalnum(int);                //function declaration

int main()
{
    char ch;
    int ret;
    
    printf("Enter the character: ");
    scanf("%c", &ch);
    
    ret = my_isalnum(ch);    // function call
   
    if(ret)
    {
        printf("Entered character is alphanumeric character\n");
    }

    else
    {
        printf("Entered character is not alphanumeric character\n");
    }
}
/*
 * function check if passed character is alpha numeric character
 * if it falls under range 'a' to 'z' or 'A' to 'Z' or '0 to '9'
 * then return true else false
 */
int my_isalnum(int ch)          //function defination
{
    if((ch >= 'a' &&  ch <= 'z') || (ch >= 'A' &&  ch <= 'Z')  || (ch >= '0' &&  ch <= '9'))
    {
        return 1;
    }

    else
    {
        return 0;
    }
}