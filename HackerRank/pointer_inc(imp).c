	#include <stdio.h>
    
    void increment(int *v) {                                       // OUTPUT: ADDRESS  VALUE
         (*v)++;                //pointer increment NOTE braces()             935ff76c  5
        //*(v)++;                                                          // aefffa50  -1971252032
        //*v++;                                                            // 483ff990  272176320  
        //*(v++);                                                          // bffff6c0  -1363405632
        printf("%x  %d\n",v,*v);
                                     
    }
      	int main() {
        int a;
        scanf("%d", &a);
        increment(&a);
        printf("%d", a);
    	return 0;      
    }     