#include<stdio.h>

#if 0
static int x = 100;

int main()
{
    static int x = 50;
    {
        {
            extern int x;
            printf("x %d\n",x);
        }
        printf("x %d\n",x);
    }
    printf("x %d\n",x);

    return 0;
}
#endif

#if 0
int main()
{
     int x = 50;
    {
        {
            extern int x;
            printf("x %d\n",x);
        }
        printf("x %d\n",x);
    }
    printf("x %d\n",x);

    return 0;
}
static int x = 100;

#endif

#if 1

int main()
{
     int x;
    {
        int x = 10;
        {
            extern int x = 20;
            printf("x %d\n",x);
        }
        printf("x %d\n",x);
    }
    printf("x %d\n",x);

    return 0;
}

#endif