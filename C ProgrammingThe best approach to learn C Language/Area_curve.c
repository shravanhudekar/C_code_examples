#include <stdio.h>

float fuction_x(float x);

float area_trap(float x,float width);


int main()
{
    //int a,b, no_trap;
    float a,b, no_trap,w,total_area;

    printf("enter below parameters:\n1. lower limit\n2. upper limit\n3. no. of trapezoids\n");
    scanf("%f%f%f",&a,&b,&no_trap);

    w=(b-a)/no_trap;
    //printf("%f   %f    %f   %f\n",a,b,no_trap,w);
   // for(float i=a;i<=b-w;i+=w)
    for(int i=0;i<no_trap;i++)
    {
        total_area+=area_trap(a,w);
        a+=w;
    }
    
    printf("total area of curve: %f",total_area);

    return 0;
}


float fuction_x(float x)
{
    return(x*x+1);
}

float area_trap(float x,float width)
{
    float area,h1,h2;

    h1= fuction_x(x);
    h2= fuction_x(x+width);
   // printf("%f   %f   %f\n",h1,h2,width);
    area= 0.5*(h1+h2)*width;

    return area;

}