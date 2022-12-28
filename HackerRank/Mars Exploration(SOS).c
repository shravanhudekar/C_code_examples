/*
Letters in some of the SOS messages are altered by cosmic radiation during transmission. 
Given the signal received by Earth as a string, , determine how many letters of the SOS message have been changed by radiation.
|Example:|
The original message was SOSSOS. Two of the message's characters were changed in transit.
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

char* readline();

/*
 * Complete the 'marsExploration' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts STRING s as parameter.
 */

int marsExploration(char* s) {
    
    int i=0,count=0;
    char msg[]={"SOS"};
    
    while(s[i]!='\0')                         //run till end of string
    {
        if(s[i] != msg[i%3])                    // compare every msg is correct or not
        {
            count++;                            // count no. of character miss match
        }
        
        i++;
    }
    return count;
}

int main()
{
    FILE* fptr = fopen(getenv("OUTPUT_PATH"), "w");

    char* s = readline();

    int result = marsExploration(s);

    fprintf(fptr, "%d\n", result);

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

/*
|INPUT:|
SOS OOS OSO SOS OSS OSO SOS OSO SOS

|LOGIC|
SOS SOS SOS SOS SOS SOS SOS SOS SOS
    1   3       2   3       3       
|OUTPUT:|
12

*/