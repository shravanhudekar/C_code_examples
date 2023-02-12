/* C Prog - Menu driven program for conversion
* -Decimal to binary
* -Decimal to hex
* -Decimal to oct
*/

#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include "print_binary.h"


void octal(int n)   // octal( base 8) is 3bit value where every 3 bit of any size(8,16,32 bit) represent 1 decimal no.
{
    int oct=0,i=1;
    printf(" INT\t %d\t",n);
    while (n != 0)
    {
        oct+=((n & 0x07)*i);        // 3 bit mask is used and multiplied by 'i' to make decimal value 
        n=(n>>3);                      // right shit by 3 bits same as n%8
        i*=10;                       
    }
    printf("\t%d",oct);   
}

void hexadecimal(int n)        // hexadacimal (base 16) is 4 bit value range from 0-9 A-F
{
    char hex[10]={0};
    int temp,i=0;
    printf(" INT\t %d\t",n);

    while(n != 0)
    {
        temp = n & (0x0F);                  // taking first nibble of 'n' as hex is always 4bit value
        if(temp < 10)
        {
            hex[i]= '0'+temp;               // coverting no. to ASCII and storing in array
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
            hex[i]= 55 + temp;        // 55 + 10 = 65 i.e. 'A' 
        }

        n = (n>>4);                     // right shift to take next nibble sane as n%16
        i++;
    }

    printf(" 0x%s", strrev(hex));           // reversing string as converstion happens from LSB -> MSB
}

int main()
{   
    // printf(" TYPE\tDECIMAL\t OCTATE\n");
    // octal(10);

     printf(" TYPE\t  DECIMAL\t HEXADECIMAL\n");
     hexadecimal(0xABCDEF);

    return 0;
}
