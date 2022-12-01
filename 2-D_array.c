#include <stdio.h>

int main()
{
    int B[2][3] = {1,2,3,4,5,6};
    int (*p)[3]=B;   // int *p[3]=B  is invalid
    

    //printf("First address : *B or B or &B[0]= %x\n",&(B[0][0]));
    //printf("First value: *B[0] or B[0][0]= %d\n",*B[0]);
    //printf("Second address: *(B+1) or B+1 or B[1] or &b[1]= %x\n",&B[1][0]);

    printf("*(B+1)+2(B[1]+2)or &b[1][2]= %d\n",*(B+1)+2);
    // printf("*(*B+1) or (&b[0][1])= %d\n",*(*B+1));
    return 0;
}