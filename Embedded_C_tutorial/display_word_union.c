/* C Prog- Program to take 32 bit integer and display Higher and lower words(16-bits) using union */

#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include "print_binary.h"

typedef union display_word
{
    uint32_t data;
    uint16_t high;
    uint16_t low;
}word_t;


int main()
{

    word_t word;

    printf("enter a no. ");
    scanf("%x",& word.data);

    printf("higher byte: %x     address:%x\n",word.high,&word.high);
    printBinary(word.high,SIXTEEN_BIT);

    printf("lower byte: %x     address:%x\n",word.low,&word.low);
    printBinary(word.low,SIXTEEN_BIT);

    return 0;

}