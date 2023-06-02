#include<stdio.h>

int main()
{
    int a[2][3] = { {1, 2, 3}, {4, 5, 6}};

//     100     104     108
//   _______________________
//  |   1   |   2   |   3   |
//  |   4   |   5   |   6   |
//   -----------------------
//     112     116     120

    printf("%hx\n",&a);             //address of whole array  100
    printf("%hx\n",*a);             //starting address of array  1st element 100
    printf("%hx\n",&a+1);           //address will next to arrays last element 124 (after end of array)
    printf("%hx\n",a+1);            // address of next row 1st element  112
    printf("%hx\n",*a+1);           //  starting address of array 2nd element   104     

    // **a          = 1
    // *(*a + 1)    = 2
    // *(*a + 2)      = 3
    // *(*(a + 1))    = 4
    // *(*(a + 1) + 1)  = 5
    // *(*(a + 1) + 2)  = 6     // *(*(a + i) + j)

    return 0;
}