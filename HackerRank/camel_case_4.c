#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

void SM(char *s,int len)
{
    char temp[len];
    int flag=0;
    
    for(int i=0;i<len-6;i++)
    {
        int j=i+4;

        if(s[j]<='Z')
        {
            temp[i]=' ';
            temp[i+1]=s[j]+32;
            flag=1;
        }

        else 
        {
            if(flag==1)
            {
                temp[i+1]=s[j];
            }
        
            else
            {
                temp[i]=s[j];
            }
        }
        printf("%s\n",temp);
    }
    memcpy(s,temp,sizeof(temp));

}
void SC(char *s,int len)
{
    char temp[len];
    int flag=0;
    
    for(int i=0;i<len-4;i++)
    {
        int j=i+4;
        if(j==4 && s[j]<='Z')
        {
             temp[i]=s[j]+32;
        }

        else if(j>4 && s[j]<='Z')
        {
            temp[i]=' ';
            temp[i+1]=s[j]+32;
            flag=1;
        }

        else 
        {
            if(flag==1)
            {
                temp[i+1]=s[j];
            }
        
            else
            {
                temp[i]=s[j];
            }
        }
       
    }
    memcpy(s,temp,sizeof(temp));

}
int main() 
{
    char *s[10][1024]={0},str[40];
    int i;

    // for(i=0;i<2;i++)
    // {
       // scanf("\n");
        scanf("%[^\n]",str);
        if (str[0]== 'S' && str[2]=='M')
        {
            SC(str,strlen(str));
        }

        else if (str[0]== 'S' && str[2]=='C')
        {
            SC(str,strlen(str));
        }

        printf("%s",str);
        // memcpy(s[i],str,strlen(str));
        
    // }

//    for(i=0;i<(strlen(s[0]));i++)
//     {
//         printf("%c\n",s[0][i]);

//     }
    return 0;
}

/*
1. take all string as input and store it in char pointer array
2. check 0th and 2nd char of every string and based on S(split) or C(combine)  and M(method), C(class), V(variable) jump to particular function.
3. first convert string based on M/C/V then call S/C.
4. split string to extract operation command through ';'
 
*/
