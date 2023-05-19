/****************** User referance **************************
Name: Shravan Hudekar
Description:   implement Circular left shift
sample input:   -2 3
sample output:  Result in Binary: 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 0 1 1 1
*************************************************************/

#include<stdio.h>

int circular_left(int, int);
int print_bits(int);

int main()
{
   int num, n, ret;

   //user inputs
   printf("Enter the num: ");
   scanf("%d", &num);
   
   printf("Enter n: ");
   scanf("%d", &n);
   
   ret = circular_left(num, n);        //function call for circular left shift
   
   printf("Result in Binary: ");
   print_bits(ret);                    //print binary of the generated no.

   return 0;
}
/*
 *stored the MSB bits which will be lost after shifting by n bits
 *shifting MSB bit by 32-n postion AND with mask to get only those n bits
 *then shift the num by n times and OR with MSB bits retrived  */
int circular_left(int num, int n)
{
   return (num<<n)| ((num>>(sizeof(num)*8)-n) & ((1<<n)-1));
}

int print_bits(int number)
{
    /*
    * n is initisalized with mask of 31st bit set 
    * AND n with number to check if bit is 0 or 1 and print it
    * loop until n is 0 as n is decremented by 1 bit 
    */
  unsigned int n = 0x80000000;                    // unsigned as bit mask with MSB set as 1 is used which in case on signed will give negative no.

   for(; n; n >>= 1)   
   {
      printf("%d ", (n & number)?1:0);
   }
}