#include <stdio.h>

void swap(void *a, void *b);

int main()
{
    double x = 5,y = 7;

    swap(&x,&y);

    return 0;
}

void swap(void *a, void *b)
{
    if (sizeof(*b) == 4)
    {
        printf("4");
    }

    else if(sizeof(*a) == 1)
    {
        printf("1\n");
    }

    else
    {
      
    }

      printf("%lld\n",sizeof(*a));
    // *a = *a + *b;
    // *b = *b - *a;
    // *a = *a - *b;
}

