#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

void digit_word(int digit)
{
    switch(digit)
    {
        case 1:
                printf("one\n");
                break;
        case 2:
                printf("two\n");
                break;        
        case 3:
                printf("three\n");
                break;        
        case 4:
                printf("four\n"); 
                break;            
        case 5:
                printf("five\n");
                break;      
        case 6:
                printf("six\n");
                break;        
        case 7:
                printf("seven\n");
                break;  
        case 8:
                printf("eight\n"); 
                break; 
        case 9:
                printf("nine\n");
                break;

        default:  break;        
    }
}

int main() 
{
    int a, b;
    char *s[]={"one","two","three","four","five","six","seven","eight","nine"};      //not clear about pointers

   /* ________________________________ Representation of *s[] __________________________________________*/

   /*  (char [4])"one"   (char [4])"two"    (char [6])"three"    (char [5])"four"   (char [4])"two"    */
   /*__________________________________________________________________________________________________*/

    scanf("%d\n%d", &a, &b);
    
  	for(int i=a;i<=b;i++)
      {                                             
        
          if(i<10)
          {
              //digit_word(i);
              printf("%s\n",s[i-1]);                                
          }
          
          else 
          {
              if((i & 0x01)==0)
              {
                  printf("even\n");
              }
              
              else 
              {
                  printf("odd\n");
              }
          }
      }

    return 0;
}


        