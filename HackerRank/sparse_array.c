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
char* ltrim(char*);
char* rtrim(char*);

int parse_int(char*);

/*
The return value from strcmp is 0 if the two strings are equal, less than 0 if str1 compares less than str2 , 
and greater than 0 if str1 compares greater than str2 . 
No other assumptions should be made about the value returned by strcmp .

1. dynamically allocated array 'a' 
**************************************************
*as it is return type and of variable length
* so cannot be defined as static and  
*int a[len]={0};  is invalid due len is not fixed.
**************************************************
2. nested for loop for queries then strings with their respective size.
3. compare string using 'strcmp' if result is 0 increment value of a[queries].
4. update result_count and return address 'a'.
 */

int* matchingStrings(int strings_count, char** strings, int queries_count, char** queries, int* result_count) {
    
    int *a = calloc(queries_count, sizeof(int));
    
        for(int i=0;i<queries_count;i++)
        {   
            for(int j=0;j<strings_count;j++)
            {
                if(strcmp((strings[j]),(queries[i]))==0)
                {
                    printf("%s   %s\n",strings[j],queries[i]);
                    a[i]++;
                }
            }
        }
        
        *result_count=queries_count;
        return a;
}

int main()
{
    FILE* fptr = fopen(getenv("OUTPUT_PATH"), "w");

    int strings_count = parse_int(ltrim(rtrim(readline())));

    char** strings = malloc(strings_count * sizeof(char*));

    for (int i = 0; i < strings_count; i++) {
        char* strings_item = readline();

        *(strings + i) = strings_item;
    }

    int queries_count = parse_int(ltrim(rtrim(readline())));

    char** queries = malloc(queries_count * sizeof(char*));

    for (int i = 0; i < queries_count; i++) {
        char* queries_item = readline();

        *(queries + i) = queries_item;
    }

    int res_count;
    int* res = matchingStrings(strings_count, strings, queries_count, queries, &res_count);

    for (int i = 0; i < res_count; i++) {
        fprintf(fptr, "%d", *(res + i));

        if (i != res_count - 1) {
            fprintf(fptr, "\n");
        }
    }

    fprintf(fptr, "\n");

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

char* ltrim(char* str) {
    if (!str) {
        return '\0';
    }

    if (!*str) {
        return str;
    }

    while (*str != '\0' && isspace(*str)) {
        str++;
    }

    return str;
}

char* rtrim(char* str) {
    if (!str) {
        return '\0';
    }

    if (!*str) {
        return str;
    }

    char* end = str + strlen(str) - 1;

    while (end >= str && isspace(*end)) {
        end--;
    }

    *(end + 1) = '\0';

    return str;
}

int parse_int(char* str) {
    char* endptr;
    int value = strtol(str, &endptr, 10);

    if (endptr == str || *endptr != '\0') {
        exit(EXIT_FAILURE);
    }

    return value;
}
