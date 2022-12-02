#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>
int main()
{
  uint8_t x;
    uint8_t y;
  printf("Enter two number: ");
  scanf("%u",&y);
  scanf("%u",&x);

  // method 1
  printf("%d\n", x-(-y));

  // method 2
  printf("%d\n", -(-x-y));

  // method 3
  printf("%d\n", abs(-x-y));

  // method 4-(~y)
  printf("%d", x-(~y)-1);

  return 0;
}