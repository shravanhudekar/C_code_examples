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
 * Complete the 'timeConversion' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING s as parameter.
 */

/*
 * To return the string from the function, you should either do static allocation or dynamic allocation
 *
 * For example,
 * char* return_string_using_static_allocation() {
 *     static char s[] = "static allocation of string";
 *
 *     return s;
 * }
 *
 * char* return_string_using_dynamic_allocation() {
 *     char* s = malloc(100 * sizeof(char));
 *
 *     s = "dynamic allocation of string";
 *
 *     return s;
 * }
 *
 */
char* timeConversion(char* s) {

    char hh,mm,ss,temp[5]={0},tstr[sizeof(s)]={0},str[5]={0};
    int time[5];
    int i=0,j=0,k=0;

    int s_size= sizeof(s);
    
    while(i < (s_size))
    {   //printf("%c",s[i]);
       
        if(s[i] != ':' && i < (s_size))
        {
            temp[j++]=s[i];          //spliting hh:mm:ssAM   07:05:49AM
            //printf("%d",s_size);
        }

        else
        {
           // sscanf(temp, "%d", time[k++]);
           time[k]=atoi(temp);
           // time[k++]=temp;

           if(s[s_size]=='A' && time[0]==0 )
           {   
                printf("00:");
                strcat(tstr,"00:");
           }

           else if(s[s_size] == 'P')
           {
                printf("%d:",(time[k]+12));
                //sprintf(str, "%s",(time[k]+12));
                strcat(tstr,str);
      
           }

           else if( s[i] != ':')
           {
                printf("%s:",temp);
           }

          // printf("%c",s[i]);
            j=0;
            k++;
        }

        i++;
    }
    // printf("%s",temp);
    //printf("%s\n",tstr);


}

int main()
{
    FILE* fptr = fopen(getenv("OUTPUT_PATH"), "w");

    char* s = readline();

    char* result = timeConversion(s);

    fprintf(fptr, "%s\n", result);

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
