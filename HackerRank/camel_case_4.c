#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

void SMV(char *s,int len)
{
    char temp[len];
    int flag=0;
    memset(temp,0,sizeof(temp));

    for(int i=0;i<len;i++)
    {
        int j=i+4;

        if(s[j]<='Z')
        {
           temp[i+flag]=' ';
            temp[i+1+flag]=s[j]+32;
            flag++;
        }

        else 
        {
             if(flag>0)
            {
                temp[i+flag]=s[j];
            }
        
            else
            {
                temp[i]=s[j];
            }
        }
        printf("%s\n",temp);
    }
   
    memcpy(s,temp,strlen(temp));

}
void SC(char *s,int len)

{
    char temp[len];
    int flag=0;
    memset(temp,0,sizeof(temp));
    for(int i=0;i<len-4;i++)
    {
        int j=i+4;
        if(j==4 && s[j]<='Z')
        {
             temp[i]=s[j]+32;
        }

        else if(j>4 && s[j]<='Z')
        {
            temp[i+flag]=' ';
            temp[i+1+flag]=s[j]+32;
            flag++;
        }

        else 
        {
            if(flag>0)
            {
                temp[i+flag]=s[j];
            }
        
            else
            {
                temp[i]=s[j];
            }
        }
    }
    memcpy(s,temp,sizeof(temp));
}
void CMV(char *s,int len,char c)
{
    char temp[len+2],br[]="()";
    int flag=0;
    
    for(int i=0;i<len;i++)
    {
        int j=i+4;
        if(s[j+flag]==' ')
        {
            temp[i]=s[j+1+flag]-32;
            flag++;
        }

        else 
        {
            if(flag>0)
            {
                temp[i]=s[j+flag];
            }
        
            else
            {
                temp[i]=s[j];
            }
        }
    }
    if(c=='M')
    {
        strcat(temp,br);
    }
   
    memcpy(s,temp,sizeof(temp));

}
void CC(char *s,int len)
{
    char temp[len],br[]="()";
    int flag=0;
    
    for(int i=0;i<len;i++)
    {
        int j=i+4;
        if(j==4 && s[j]>='a')
        {
             temp[i]=s[j]-32;
        }

        else if(j>4 && s[j+flag]==' ')
        {
            temp[i]=s[j+1+flag]-32;
            flag++;
        }

        else 
        {
            if(flag>0)
            {
                temp[i]=s[j+flag];
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
    char *s[10][100]={0},str[40]={0};
    int i,len=0;

    for(i=0;i<1;i++)
     {
        scanf("\n");
        scanf("%[^\n]%*c",str);
        // if(strcmp(str,"")){
        //     break;
        // }
        if (str[0]== 'S' && str[2]=='M')
        {
            SMV(str,strlen(str)-4);
        }

        else if (str[0]== 'S' && str[2]=='C')
        {
            SC(str,strlen(str));
        }

        else if (str[0]== 'S' && str[2]=='V')
        {
            SMV(str,strlen(str)+2);
        }

        else if (str[0]== 'C' && str[2]=='M')
        {
            CMV(str,strlen(str),str[2]);
        }

        else if (str[0]== 'C' && str[2]=='V')
        {
            CMV(str,strlen(str),str[2]);
        }

        else if (str[0]== 'C' && str[2]=='C')
        {
            CC(str,strlen(str));
        }
         memcpy(s[i],str,strlen(str)); 
         
          
     }

        for(i=0;i<1;i++)
        {
          printf("%s\n",s[i]);

        }

    return 0;
}

/*
1. take all string as input and store it in char pointer array
2. check 0th and 2nd char of every string and based on S(split) or C(combine)  and M(method), C(class), V(variable) jump to particular function.
3. first convert string based on M/C/V then call S/C.
4. split string to extract operation command through ';'
 
*/
