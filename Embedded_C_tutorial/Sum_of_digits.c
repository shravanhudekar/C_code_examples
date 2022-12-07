#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
	
    int n,sum=0;
    scanf("%d", &n);                                           // 1234
    
    while(n!=0)                      
    {
        sum+=n%10;                                            //here you get remainder of 'n' wich nothing but LSB of 'n'
        printf("remainder & quotient(%4d): %d  ",n,n%10); 
        n/=10;                                               // 'n' is divide by 10 whose quotient is used to recalculate next digit of 'n'
        printf("%d\n",n); 
    }
    
    printf("\nSum of Digits: %d\n",sum);
    
    
    return 0;
}

/**************************************************
            |OUTPUT:|

1234
remainder & quotient(1234): 4  123
remainder & quotient( 123): 3  12
remainder & quotient(  12): 2  1
remainder & quotient(   1): 1  0

Sum of Digits: 10

**************************************************/