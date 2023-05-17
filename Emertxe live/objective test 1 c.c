//1
#include <stdio.h>

int main()
{
    char a=167;
    
    int expr = a + !a +a ;
    
  
  printf("%d",expr);
}


//2
int main()
{
    int a=5 , b=10,c=5;
    
    if(a && b > c)
     {printf("emertxe %d", a&&b);}
}


//3

int main()
{
   int a,b;
   
   a=3,1,1;
   
   b= ((4,3), (4,15));
    
     printf("%d", a+b);
}


//4

int main()
{
   int k=1;
   
   printf("%d == 1 is ""%s",k,k==1?"TRUE":"FALSE");
}

//5

#include <stdio.h>

int main()
{
  char a,b,c;
  
  a=118;
  b=83;
  c=a+b;
  int x=0,y,z;
  
  y=(x++,x);
  
  z=y && (y=10);
  printf("%d",z);
}


//6

int main()
{
  for(int i=10 ==1;i<=10;i++)
  {
      printf("%d",i);
  }
  
}


//7
int main()
{
  int i =1;
  
  if(i=!i)
      printf("Hi");
 
  
  else if(i=!i)
    printf("Bye");
    
    else if(1)
        printf("Tata");
}

//8

int main()
{
  int num=25;
  int res=0,i,temp;
  
  for(i=0;i<32;i++)
  {
      temp=(num & (1<<i));
      if(temp)
      res|=(1<<(32-1)-i);
  }
  
  printf("%X\n",res);
}

//9

int main()
{
  if(-1)
  {
      printf("hello");
  }
  
  else
  {
      printf("world");
  }
}


//10

int main()
{
  for(char ch='0'; ch<127;ch++)
  {
        printf("%d\n",ch);
  }
    int a=4;
    
    printf("%d %d %d",a,++a,a++);
}


//11
 for(int ch=0; ch<2;ch++)
  {
      int i=5;
        printf("%d..",--i);
  }

  //12

  int main()
{
  
    int a=0X540;
   // signed char c=304;
    
   // c=304+4;
    
    if(1,5,2,0) printf("yes");
   // printf("%X",a-1);
   // printf("%d %d %d",a,++a,a++);
   
   unsigned char c=-7;
   
   printf("%hhu",c);
}