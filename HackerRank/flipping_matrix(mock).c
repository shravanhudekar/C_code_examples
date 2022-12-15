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
int max(int *a, int n)
{
    int temp;

    for(int i=0;i<n;i++)
    {
        for(int j=i;j<n;j++)
        {
            if(a[j]<a[i])
            {
                temp=a[i];
                a[i]=a[j];
                a[j]=temp;
            }

        }
    }

    return a[n];

}

int flippingMatrix(int matrix_rows, int matrix_columns, int** matrix) {
    
    int i,j,temp,result=999,q[matrix_rows];
     result= matrix[0][0]+matrix[0][1]+matrix[1][0]+matrix[1][1];
    memset(q,0,sizeof(q));

    while (result != q[0])
    {
        for(i=0;i<matrix_rows;i++)
        {
        for(j=matrix_columns-1;j>=0;j--)
            {
                if(i!=j)
                {
                    temp=matrix[i][j];
                    matrix[i][j]=matrix[j][i];
                    matrix[j][i]=temp;
                }

                else{
                    break;
                }
           
            }

        }
    
     for(j=0;j<matrix_columns;j++)
        {
            for(i=0;i<matrix_rows/2;i++)
            {
                    temp=matrix[i][matrix_rows-i];
                    matrix[i][matrix_rows-i]=matrix[i][j];
                    matrix[i][j]=temp;
            }
        }
    
        q[0]= matrix[0][0]+matrix[0][1]+matrix[1][0]+matrix[1][1];
        q[1]= matrix[0][2]+matrix[0][3]+matrix[1][2]+matrix[1][3];
        q[2]= matrix[2][0]+matrix[2][1]+matrix[3][0]+matrix[3][1];
        q[3]= matrix[2][2]+matrix[2][3]+matrix[3][2]+matrix[3][3];
        
        result= max(q,matrix_rows);
    }
    
    return result;

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
