#include<stdio.h>

#if 0
int main()
{
    int a=5, b=10, c=1;

    //1
    //if((a && b) > c)
    if(a && b > c)
    {
        printf("and  %d\n",a && b > c );
    }

    else
    {
        break;
    }
}
#endif

#if 0

int main()
{
    printf("%d\n", sizeof('A'));

    char q='A';
    printf("%d\n", sizeof(q));
}
#endif

#if 0
{
    int x,y,z=1;

    z= (y=10);

    printf("%d\n",z);
}

#endif

#if 0

int main()
{

    char c=300;                                                                                                                                                     // 1 byte -> 1111 1111 -> -128 to 127  -> = 256  300-256 = 44

    switch(c)
    {
        case 300: printf("300: %d",c);
        break;

        case 44: printf("44: %d",c);
        break;

        case 50: printf("50: %d",c);
        break;

        default: printf("def : %d",c);
        break;
    }

    return 0;
}

#endif

#if 0

int main()
{

    int a= 4;

    printf("%d %d %d",a,++a,a++);                                                                                                                                               //undefined behaviour since you cannot change varaible value mutliple times in single statement
    return 0;
}

#endif

#if 0

int main()
{
    int i;

    for(i=0;i<10;i++)
    {
        if(i>010) break;
        printf("%d\n",i);
    }
}

#endif

#if 0

int main()
{
    int a=4;

    while(a-- >= 1)                                                                                                                                                                             //a=3
        while(a-- >= 0);                                                                                                                                                             //a=3, 2, 1, 0, -1,-2,-3

    printf("%d\n",a);
}

#endif

#if 0

int main()
{
    char a = 167;
    int expr;

    expr = a + !a + a;

    printf("a: %d   !a: %d   expr: %d",a,!a,expr);

    return 0;
}
#endif

#if 0

int main()
{

    switch(3)
    {
        case 3: printf("case 3");
                break;

        case 3.0f: printf("case 3.0f");
                    break;

        case 3.0L: printf("case 3.0L");
                    break;

        default: printf("default");
    }
}

#endif

#if 0

int main()
{
    int a,b;

    a=3,1,1;
    b=((4,3),(4,15));

    printf("%d",a+b);
}

#endif

#if 0

int main()
{
    int k=1;
    printf("%d == 1 is ""%s",k,k==1?"TRUE":"FALSE");
}

#endif

#if 0

int main()
{
   char a,b,c;

   a=118;
   b=83;
   c=a+b;

   printf("%d",c);
}

#endif

#if 0

int main()
{
    int y=42,z;

    z=(y+(y=50));

    printf("%d",z);
}
#endif

#if 0

int main()
{
    int x=0,y;

    y=(x++,x);

    printf("%d",y);
}

#endif