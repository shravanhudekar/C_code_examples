/*****************************************************************************************
 *  C prog- Define a macro to create  n th bit flag - BIT(n), SET_BIT(n), CLEAR_BIT(n)   *
 *****************************************************************************************/

#include<stdio.h>
#include<stdint.h>
#include<stdlib.h>
#include <math.h>
#include "print_binary.h"

#define BIT(n)        ((num >> n) & 1)   // left shit by nth time to check if nth bit is set or not 
#define SET(n)        (1<<n)             // nth bit will be set
#define CLEAR_BIT(n)  (~(1<<n))          // clears the nth bit (here nth bit is set and negate is calcualted)

#define MSB_SET(n)    ( n & ~(n-1))  

void bit_Setting()
{
     int num,bit,value;

    printf("enter no. and bit to set: ");
    scanf("%d%d",&num,&bit);             // 0000 0101 | 0000 0010

    if(BIT(bit) != 0)
    {    printf("%dth bit no. set\n",bit); }
    else
    {    printf("nth bit no. not set\n");  }
    
    value= (num | SET(bit));           // SET bit mask is ORed with num to set bit
    printf("SET: %d\n",value);
    value=(num & CLEAR_BIT(bit));      // CLEAR bit mask is added with num to clear bit
    printf("RESET: %d\n",value);
}

int main()
{
    int num;

    //bit_Setting();
    printf("Enter no.:");
    scanf("%d",&num);
     printBinary(num,EIGHT_BIT);

    printf("\nright most set bit is: %d  ",MSB_SET(num));   
    printBinary(MSB_SET(num),EIGHT_BIT);
}