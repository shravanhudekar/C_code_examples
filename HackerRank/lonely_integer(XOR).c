/* |PROBLEM STATEMENT|
Given an array of integers, where all elements occur twice except one, find the unique element.
It is guaranteed that 'n' size is an odd number and that there is one unique element.

|SOLUTION|

There is to ways to solve this problem.
- normal way using two for loops searching for value with no occurance.
    -use two nested for loops 'i' 'j'.
    - check if a[i]==a[j] where i!=j;
    - if equal set flag as true and end te loop.
    - after end of 'j' loop check if flag is set.
    - if not set a[i] is unique no. break 'i' loop.
    - otherwise reset flag and continue.
    - retrun lonely integer at the end of function.

- using XOR.
    - set return varaible lonely as 0. 
    - run single for loop 'i'.
    - XOR a[i] with lonely every time and save it in lonely.
    - at the end lonely will have value of unique no. other all values will get clear with its second occourance except the unique one.
    - return lonely.

    |For e.g.|
    n = 5
    a[] = 0 0 1 2 1

    lonely     0000    0000    0000    0001    0011
    a[i]     ^ 0000    0000    0001    0010    0001       (^)XOR
               ----    ----    ----    ----    ----
    lonely     0000    0000    0001    0011    0010(2)

    NOTE: this is specific only where size'n' is odd that is occurance of no unique is twice only.

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

#define USING_XOR

char* readline();
char* ltrim(char*);
char* rtrim(char*);
char** split_string(char*);

int parse_int(char*);

int lonelyinteger(int a_count, int* a) 
{
    int i,j=0,count=0,flag=0,lonely=0;
    
    for(i=0;i<a_count;i++)
     {  

#ifdef USING_XOR 

        lonely^=a[i];

#else
        flag=0;
       for(j=0;j<a_count;j++)
       {    
           if((a[i]==a[j]) && (i!=j))
           {
               flag=1;
               break; 
           }
       }
       if(flag==0)
       {
           lonely=a[i];
           break;
       }
#endif
    }
    
    return lonely;
}

int main()
{
    FILE* fptr = fopen(getenv("OUTPUT_PATH"), "w");

    int n = parse_int(ltrim(rtrim(readline())));

    char** a_temp = split_string(rtrim(readline()));

    int* a = malloc(n * sizeof(int));

    for (int i = 0; i < n; i++) {
        int a_item = parse_int(*(a_temp + i));

        *(a + i) = a_item;
    }

    int result = lonelyinteger(n, a);

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

char** split_string(char* str) {
    char** splits = NULL;
    char* token = strtok(str, " ");

    int spaces = 0;

    while (token) {
        splits = realloc(splits, sizeof(char*) * ++spaces);

        if (!splits) {
            return splits;
        }

        splits[spaces - 1] = token;

        token = strtok(NULL, " ");
    }

    return splits;
}

int parse_int(char* str) {
    char* endptr;
    int value = strtol(str, &endptr, 10);

    if (endptr == str || *endptr != '\0') {
        exit(EXIT_FAILURE);
    }

    return value;
}
