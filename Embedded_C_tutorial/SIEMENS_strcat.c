/* C Prog - Take Name as characters and add fixed string "SIEMENS" starting char 3 using pointers */
#include <stdio.h>
#include <stdint.h>
#include <string.h>

int main()
{
    char name[20],*str={"SIEMENS"},fname[30];
    int i=0,len=0;
    char *str1=name, *str2=fname;

    printf("enter your name: ");
    // do
    // {
    //     scanf("%c",&name[i]);
    // }while(name[i++]!= '\n');
    scanf("\n");
    scanf("%[^\n]%*c",&name);
    str1 += 3;
   // printf("%c",*str1);
    strcpy(str1,str);
    printf("%s",name);
    //  while(name[i] != '\0')
    //  {
    //     fname[i]=*(ptr+(i+3));
    //     *(ptr+(i+3))=str[i];
    //     i++;
    //  }
    // strcat(name,fname);
    len=strlen(name)+strlen(str);

    // while(i != len)
    // {
    //     if((*str != '\0') && (i>2))
    //     {
    //          *str2=*str;
    //          str++;
    //     }

    //     else
    //     {
    //         *str2=*str1;
    //         str1++;
    //     }
    //     str2++;
    //     i++;
    // }
    
       
    // printf("%s",fname);

    return 0;
}




  

  
