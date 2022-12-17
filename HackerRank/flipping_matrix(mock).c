/*
Aim: flip matrix such a way that you get sum of 1st quadrant as MAX for n*n matrix.

|INPUT|

STDIN           Function
-----           --------
1               q = 1
2               n = 2
112 42 83 119   matrix = [[112, 42, 83, 119], [56, 125, 56, 49], \
56 125 56 49              [15, 78, 101, 43], [62, 98, 114, 108]]
15 78 101 43
62 98 114 108

|Expected output:| 414

|PROGRAM FLOW:|
1. run nested loop to access each element of array.
2. find MAX between its corresponding elements.
for e.g.
 __            __
|                |
| A1  B1  B2  A2 |
| C1  D1  D2  C2 |
| C3  D3  D4  C4 |
| A3  B3  B4  A4 |
|__            __|

* A can be only be replaced by corresponding A, similar for B, C, D.

3. find sum of MAX(A,B,C,D).
4. return sum
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
char* ltrim(char*);
char* rtrim(char*);
char** split_string(char*);

int parse_int(char*);



/*
 * Complete the 'flippingMatrix' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts 2D_INTEGER_ARRAY matrix as parameter.
 */
int max(int a, int b)
{
    return a>b ? a:b;
}

int flippingMatrix(int matrix_rows, int matrix_columns, int** matrix) 
{  
    int i,j,sum=0,n;
    n=matrix_rows;
    for(i=0;i<n/2;i++)
    {
        for(j=0;j<n/2;j++)
        {
            sum+=max(max(matrix[i][j],matrix[i][n-j-1]),max(matrix[n-i-1][j],matrix[n-i-1][n-j-1]));
        }
    }
    return sum;
}

int main()
{
    FILE* fptr = fopen(getenv("OUTPUT_PATH"), "w");

    int q = parse_int(ltrim(rtrim(readline())));

    for (int q_itr = 0; q_itr < q; q_itr++) {
        int n = parse_int(ltrim(rtrim(readline())));

        int** matrix = malloc((2 * n) * sizeof(int*));

        for (int i = 0; i < 2 * n; i++) {
            *(matrix + i) = malloc((2 * n) * (sizeof(int)));

            char** matrix_item_temp = split_string(rtrim(readline()));

            for (int j = 0; j < 2 * n; j++) {
                int matrix_item = parse_int(*(matrix_item_temp + j));

                *(*(matrix + i) + j) = matrix_item;
            }
        }

        int result = flippingMatrix(2 * n, 2 * n, matrix);

        printf("\n%d\n", result);
    }

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
