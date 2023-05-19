

/****************** User referance **************************
Name: Shravan Hudekar
Description:   implement Circular right shift
sample input:   -12 3
sample output:  Result : 10011111 11111111 11111111 11111110
*************************************************************/

#include<stdio.h>

int circular_right(int, int);
int print_bits(int);

int main()
{
   int num, n, ret;

   //user inputs
   printf("Enter the num: ");
   scanf("%d", &num);
   
   printf("Enter n: ");
   scanf("%d", &n);
   
   ret = circular_right(num, n);        //function call for circular right shift
   
   //printf("Result : ");
   printf("Result in Binary: ");
   print_bits(ret);                    //print binary of the generated no.

   return 0;
}
/*
 *stored the LSB bits which will be lost after shifting by n bits
 *AND num with mask to get only n bits which will be lost
 *then shift those bits by 32-n bits towards MSB 
 *shift num by n times clear the n bits of num MSB side and then OR it with retrived bits */
int circular_right(int num, int n)
{
   return ((num>>n) & ((1<<((sizeof(num)*8)-n))-1)) | ((num & ((1<<n)-1)) << ((sizeof(num)*8)-n));
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

     // if(n & 0x1010101)                         // mask to add space after printing every 8 bit
      //  { printf(" ");}
   }
}