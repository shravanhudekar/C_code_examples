/****************** User referance **************************
Name: Shravan Hudekar
Description:  put the (b-a+1) lsb’s of num into val[b:a]
sample input:   11 3 5 174
sample output:  Result : 158
*************************************************************/

#include<stdio.h>

int replace_nbits_from_pos(int, int, int, int);            //function defination

int main()
{
   int num,a,b,val,res = 0;
    
    //user inputs
    printf("Enter the value of 'num' : ");
    scanf("%d", &num);

    printf("Enter the value of 'a' : ");
    scanf("%d", &a);

    printf("Enter the value of 'b' : ");
    scanf("%d", &b);

    printf("Enter the value of 'val': ");
    scanf("%d", &val);
    
    res = replace_nbits_from_pos(num, a, b, val);   // print result

    printf("Result : %d", res);

    return 0;
}

/*
* no. of bits(n) b - a + 1
* mask to get n bits from num
* pos gives no. of shift 
* to replace n bits from b position in val
*/
int replace_nbits_from_pos(int num,int a, int b, int val)
{
   int n = b - a + 1;
   int pos = b - n + 1;
   int mask = (1<<n) -1;

   num = num & mask;

   return ((val & ~(mask<<pos)) | (num<<pos));        // return generate value
}