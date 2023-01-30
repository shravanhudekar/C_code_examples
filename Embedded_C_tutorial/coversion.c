/* C Prog - Menu driven program for conversion
* -Decimal to binary
* -Decimal to hex
* -Decimal to oct
*/

#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include "print_binary.h"


void octal(int n)
{
    int oct=0,i=1;
    printf(" INT\t %d\t",n);
    while (n != 0)
    {
        oct+=((n & 0x07)*i);
        n=(n>>3);
        i*=10;
    }
    printf("\t%d",oct);   
}

void hexadecimal(int n)
{
    char hex[10]={0};
    int temp,i=0;
    printf(" INT\t %d\t",n);

    while(n != 0)
    {
        temp = n & (0x0F);
        if(temp < 10)
        {
            hex[i]= '0'+temp;
        }

        else
        {  
            // if(temp==10)
            // {
            //     hex[i]= 'A';
            // }
            // else if(temp == 15)
            // {
            //         hex[i]= 'F';
            // }
            // else
            // {
            //     hex[i]= 'A'+(temp % 5);
            // }
            hex[i]= 55 + temp;
        }

        n = (n>>4);
        i++;
    }

    printf(" 0x%s", strrev(hex));
}

int main()
{   
    // printf(" TYPE\tDECIMAL\t OCTATE\n");
    // octal(10);

     printf(" TYPE\t  DECIMAL\t HEXADECIMAL\n");
     hexadecimal(0xABCDEF);

    return 0;
}
