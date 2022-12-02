/*C prog- Define a macro to create  n th bit flag - BIT(n), SET_BIT(n), CLEAR_BIT(n)*/

#include<stdio.h>
#include<stdint.h>
#include<stdlib.h>

#define BIT(n)   (num >> n) & 1
#define SET(n)   (1<<n)
#define CLEAR_BIT(n)  (~(1<<n))    


int main()
{
    uint8_t num;

    printf("enter no.");
    scanf("%d",&num);

    printf("nth bit no. %d",BIT(2));

    printf("SET: %x\n",SET(num));


    printf("RESET: %x\n",CLEAR_BIT(num));




    
}