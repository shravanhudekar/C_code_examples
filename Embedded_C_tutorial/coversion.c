/* C Prog - Menu driven program for conversion
* -Decimal to binary
* -Decimal to hex
* -Decimal to oct
*/

#include <stdio.h>
#include <stdint.h>

void octate(int n)
{
    int oct=0,i=1;
 printf(" INT\t %d\t",n);
    while (n != 0)
    {
        oct+=((n & 0x07)*i);
        n=(n>>3);
        i*=10;
    }

    printf("   %d",oct);
    
}

int main()
{   printf(" TYPE\tDECIMAL\t OCTATE\n");
    octate(367);
    // printf(" INT\t %d\t   %d\n",TEST_NUM1,TEST_NUM2);
    // printf("FLOAT\t %2.2f\t %1.3f\n",TEST_NUM1,TEST_NUM2);
    // printf(" OCT\t %o\t   %o\n",TEST_NUM1,TEST_NUM2);
    // printf(" HEX\t %x\t   %x\n",TEST_NUM1,TEST_NUM2);
    //  printf("CHAR\t %c\t   %c\n",TEST_NUM1,TEST_NUM2);

    return 0;
}
