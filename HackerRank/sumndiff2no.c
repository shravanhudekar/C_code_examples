#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main()
{
    int a,b;
    float c,d;
    
    scanf("%d%d%f%f",&a,&b,&c,&d);
    
    printf("%d %d\n",(a+b),abs(a-b));
    printf("%0.1f %0.1f\n",(c+d),(c-d));                            //abs is not alowed in float 
	 
    
    return 0;
}



// NOTE:- observe syntax of float decimal place in printf '%0.1f' for 1 decimal place