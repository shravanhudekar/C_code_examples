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
char** split_string(char*);

int parse_int(char*);

int* breakingRecords(int scores_count, int* scores, int* result_count) 
{
    int min=0,max=0,s_min=0,s_max=0;
    *result_count = 2; 
    static int a[2];
    
    for (int i=0;i<scores_count;i++)
    {
        if(i==0)
        {
            s_max=scores[i];
            s_min=s_max;
        }
        else 
        {
            if(scores[i]>s_max) 
            {
                s_max=scores[i];
                max++; 
            }
            
            else if(scores[i]<s_min)
            {
                s_min=scores[i];
                min++;
            } 
        }  
             
    }
    a[0]=min;
    a[1]=max; 
    return a;
}

int main()
{
    FILE* fptr = fopen(getenv("OUTPUT_PATH"), "w");

    int n = parse_int(ltrim(rtrim(readline())));

    char** scores_temp = split_string(rtrim(readline()));

    int* scores = malloc(n * sizeof(int));

    for (int i = 0; i < n; i++) {
        int scores_item = parse_int(*(scores_temp + i));

        *(scores + i) = scores_item;
    }

    int result_count;
    int* result = breakingRecords(n, scores, &result_count);

    for (int i = 0; i < result_count; i++) {
        fprintf(fptr, "%d", *(result + i));

        if (i != result_count - 1) {
            fprintf(fptr, " ");
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
/* 


                                   Count
    Game  Score  Minimum  Maximum   Min Max
     0      10     10       10       0   0
     1       5      5       10       1   0
     2      20      5       20       1   1
     3      20      5       20       1   1
	 4     	 4      4       20       2   1
     5       5      4       20       2   1
     6       2      2       20       3   1
     7      25      2       25       3   2
	 8       1      1       25       4   2

Input: total game count = 9 scores of each game

output: 4 2  i.e total of min & max


*/