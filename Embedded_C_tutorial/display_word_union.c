/* C Prog- Program to take 32 bit integer and display Higher and lower words(16-bits) using union */

#include <stdio.h>
#include <stdint.h>
#include <string.h>


typedef union display_word
{
    uint32_t high;
    uint32_t low;
}word_t;


int main()
{

}