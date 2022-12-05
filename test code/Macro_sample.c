#include <stdio.h>
#include<stdbool.h>

// #define x 5+5                              // fix #define x (5+5)     

// int main()
// {
//     int a=x*x;                            //due to precedence (BODMAS)
//     printf("%d\n",a);   

//     return 0;
// }

/*******************************/
/*     Macro vs Inline         */ 
/*******************************/

//#define ADD_TWO(x,y) x+= 2; y+=2
// void ADD_TWO(int x,int y);

//  void inline ADD_TWO(int x,int y)
// {
//     x+=2; 
//     y+=2;
// }


// int main()
// {
//     bool flag = true; 
//     int j = 5, k = 7;   

//     printf("%d %d\n",j,k);

//     if(flag)  ADD_TWO(j,k);

//     printf("%d %d\n",j,k);

//     return 0;

// }

/*******************************/
/*   Macro Parentheses Effect  */ 
/*******************************/

// #define MULTIPLY(a,b) a*b
// int main()
// {
//     int a = 5;
//     int b = 3;
//     printf("(a+4) x b = %d\n",MULTIPLY(a,4+b));                 // macro will replace this MULTIPLY(a,4) |OUTPUT:23|       fix MULTIPLY(a,(4+b)) 
//     return 0;
// }

/*******************************/
/*  Macro Multiple Increments  */ 
/*******************************/

#define SQUARE(a) (a)*(a)
int main()
{
    int a = 2;
    printf("Square of a = %d\n", SQUARE(++a));      // its treated as (++a)*(++a) |OUTPUT:16|   This is because of the fact that a is getting incremented 2 times due to the text substitutions.
    printf("a = %d\n",a);
    return 0;
}