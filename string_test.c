#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>


void split(char * str , char * n_str) {

int i = 0 , k = 0 , len = 0; len = strlen(str); if( str[2] == 'C')
{ k = 0; str[4] += 32; for(i = 4 ; i < len ;i++,k++ ) { if(str[i] < 'a') { str[i] += 32; n_str[k] = ' '; k++; } n_str[k] = str[i]; } n_str[k] = '\0'; } else if( str[2] == 'M')
{ k = 0; for(i = 4 ; i < len - 2 ;i++,k++ ) { if(str[i] < 'a') { str[i] += 32; n_str[k] = ' '; k++; } n_str[k] = str[i]; } n_str[k] = '\0';
} else if( str[2] == 'V')
{ k = 0; for(i = 4 ; i < len ;i++,k++ ) { if(str[i] < 'a') { str[i] += 32; n_str[k] = ' '; k++; } n_str[k] = str[i]; } n_str[k] = '\0';
} printf("%s\n",n_str); }

void combine(char * str , char * n_str) {

int i = 0 , k = 0 , len = 0; len = strlen(str); if( str[2] == 'C')
{ k = 0; str[4] -= 32; for( i = 4 ; i < len ; i++,k++) { if(str[i] == ' ') { n_str[k] = str[i+1] - 32 ; k++; i+=2;

        }
        n_str[k] = str[i] ;

    }
      n_str[k] = '\0'; 

 }


 else if( str[2] == 'M')  
 {
      k = 0;

    for( i = 4 ; i < len ; i++,k++)
    {
        if(str[i] == ' ')
        {
            n_str[k] = str[i+1] - 32 ;
            k++;
            i+=2;

        }
        n_str[k] = str[i] ;

    }
     n_str[k] = '(';
     n_str[k+1] = ')';
     n_str[k+2] = '\0';
 }
 else if( str[2] == 'V')  
 {
      k = 0;

    for( i = 4 ; i < len ; i++,k++)
    {
        if(str[i] == ' ')
        {
            n_str[k] = str[i+1] - 32 ;
            k++;
            i+=2;

        }
        n_str[k] = str[i] ;

    }
      n_str[k] = '\0';

 }
printf("%s\n",n_str); }

int main() {

/* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
char str[100]; char n_str[110]; int t =0; 

while(t<4) // you can change 10 to any number of inputs u expected 
{ 
    scanf("\n"); 
    scanf("%[^\r\n]%*c",str); // take care from this line

    if( str[0] == 'S') 
    { 
        split(str,n_str); // 
        printf("%s\n",n_str); 
    } 
    else if (str[0] == 'C') 
    { 
        combine(str,n_str);
    } 
    else 
    { 
        break; 
    } 
    t++; 
    str[0] = 'b'; 
}

return 0;
}