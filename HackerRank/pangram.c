/* |PROBLEM STATEMENT|
A pangram is a string that contains every letter of the alphabet. 
Given a sentence determine whether it is a pangram in the English alphabet.
Return either pangram or not pangram as appropriate.

|PROGRAM FLOW:|

* Run a while loop to check every character of input string 's' until '\0'(NULL).
* find the charater index by subtracting  s[i]- 97('a' in ASCII).
* if index is >= 0 set index bit in 32 bit variable.
* else subtract 32-index ('32' is diff between 'A' & 'a' ASCII) and set resultant bit in 32 bit variable.
* ignore s bit is already set. and dont include ' ' character.
* after end of loop if 32bit varable value is equal to 0x3FF FFFF return string as 'pangram'.
* else 'not pangram'. 
  
*/

#include <assert.h>
#include <ctype.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<stdint.h>

#define SET(x,y)          x |= (1<<y)
#define CHECK_BIT(x,y)    x &= (1<<y)
char* readline();

char* pangrams(char* s) 
{
    int i=0,index=0;
    uint32_t result=0;
    static char str[12]={0};

    while(s[i] != '\0')
    {
        index=s[i]-'a';

        //if((CHECK_BIT(result,index)!=1 || CHECK_BIT(result,index+32)!=1) &&
        if(index >= -32)   //)
        {
            if(index >= 0)
            {
                SET(result,index);
            }

            else
            {
                index+=32;
                SET(result,index);
            }
        }
        
        i++;
    }

    if(result == 0x03FFFFFF)
    {
        strcpy(str,"pangram");
    }   
      
    else
    {
        strcpy(str,"not pangram");
    } 
    
    printf("%x\n",result);
    return str;


}

int main()
{
    FILE* fptr = fopen(getenv("OUTPUT_PATH"), "w");

    char* s = readline();

    char* result = pangrams(s);

    printf("%s\n", result);

    fclose(fptr);

    return 0;
}

char* readline() {
    size_t alloc_length = 1024;
    size_t data_length = 0;

    char* data = malloc(alloc_length);

    while (true) {
        char* cursor = data + data_length;
        char* line = fgets(cursor, alloc_length - data_length, stdin);

        if (!line) {
            break;
        }

        data_length += strlen(cursor);

        if (data_length < alloc_length - 1 || data[data_length - 1] == '\n') {
            break;
        }

        alloc_length <<= 1;

        data = realloc(data, alloc_length);

        if (!data) {
            data = '\0';

            break;
        }
    }

    if (data[data_length - 1] == '\n') {
        data[data_length - 1] = '\0';

        data = realloc(data, data_length);

        if (!data) {
            data = '\0';
        }
    } else {
        data = realloc(data, data_length + 1);

        if (!data) {
            data = '\0';
        } else {
            data[data_length] = '\0';
        }
    }

    return data;
}
