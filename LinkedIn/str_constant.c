#include<stdio.h>

 void main()
{
    char *p = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int i,x=1,count=0;
    
    //printf("%d %c\n",i,*p); 
    for(i=0;i<5;i++) *p++; *p++;
    printf("%c\n",*p++); 

    while(x++<100)
    {     
        x*=x;
        count++;
        if(x<10) continue;
        if(x>50) break;
        //count++;                       // doesn't work after break or continue statement
     }
     printf("%d",count);
}