/****************** User referance **************************
Name: Shravan Hudekar
Description: count number of set bits in a given number and print parity
sample input:   6 
sample output:  Number of set bits = 2
                Bit parity is Even
*************************************************************/

#include<stdio.h>

int main()
{
    int data, bit_count=0;

    printf("Enter the number : ");
    scanf("%d",&data);
    
    //loop until value of data is non-zero
    while(data != 0)
    {
        //METHOD 1
         // if((data & 0x001)==1)
        // {     bit_count++;  }
        // data=(data>>1); 

        //METHOD 2
        if(data){   bit_count++;  }                                             // LSB is set zero by ANDing with N-1

        data &= data-1; 
    }

    printf("Number of set bits = %d\n",bit_count);

    if(bit_count & 1)                                                   // check if bits are odd or even to print type of parity
    {
        printf("Bit parity is Odd\n");
    }

    else
    {
        printf("Bit parity is Even\n");
    }

}