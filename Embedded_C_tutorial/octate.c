
/* C prog Print the output and provide reason why outputs are different */
#define TEST_NUM1 247
#define TEST_NUM2 0247

#include <stdio.h>
#include <stdint.h>

int main()
{   printf(" TYPE\tDECIMAL\t OCTATE\n");
    printf(" INT\t %d\t   %d\n",TEST_NUM1,TEST_NUM2);
    printf("FLOAT\t %2.2f\t %1.3f\n",TEST_NUM1,TEST_NUM2);
    printf(" OCT\t %o\t   %o\n",TEST_NUM1,TEST_NUM2);
    printf(" HEX\t %x\t   %x\n",TEST_NUM1,TEST_NUM2);
     printf("CHAR\t %c\t   %c\n",TEST_NUM1,TEST_NUM2);

    return 0;
}

/*_____________________NOTE______________________*
 * output dervied using diffrent type specifer for defined values in deciaml and oct.
 * also notice type specifer of FLOAT signifing decimal place after dot whereas no significance of value before dot.
 * 
 * CONVERSION:
 * DEC-OCT:  convert dec value to bin and convert 3bit pair into 1 decimal value whole being an oct.
 * same for reverse case OCT-DEC insteat 3 bit pair now 4bit pair.
/* |OUTPUT:|

 TYPE   DECIMAL  OCTATE
 INT     10        8
FLOAT    0.00    0.000
 OCT     12        10
 HEX     a         8
CHAR


#define TEST_NUM1 247
#define TEST_NUM2 247

 TYPE   DECIMAL  OCTATE
 INT     247       247
FLOAT    0.00    0.000
 OCT     367       367
 HEX     f7        f7
CHAR

#define TEST_NUM1 247
#define TEST_NUM2 0247

 TYPE   DECIMAL  OCTATE
 INT     247       167
FLOAT    0.00    0.000
 OCT     367       247
 HEX     f7        a7
CHAR

*/