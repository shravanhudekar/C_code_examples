/****************** User referance **************************
Name: Shravan Hudekar
Description:   implement your own isxdigit() function
sample input:   a
sample output:  Entered character is an hexadecimal digit
*************************************************************/
#include <stdio.h>

int is_xdigit(int);                //function declaration

int main()
{
    char ch;
    int ret;
    
    printf("Enter the character: ");
    scanf("%c", &ch);
    
    ret = is_xdigit(ch);    // function call
   
    if(ret)
    {
        printf("Entered character is an hexadecimal digit\n");
    }

    else
    {
        printf("Entered character is not an hexadecimal digit\n");
    }
}
/*
 * function check if passed character is Hexa decimal character
 * if it falls under range 'a' to 'f' or 'A' to 'F' or '0 to '9'
 * then return true else false
 */
int is_xdigit(int ch)          //function defination
{
    if((ch >= 'a' &&  ch <= 'f') || (ch >= 'A' &&  ch <= 'F')  || (ch >= '0' &&  ch <= '9'))
    {
        return 1;
    }

    else
    {
        return 0;
    }
}