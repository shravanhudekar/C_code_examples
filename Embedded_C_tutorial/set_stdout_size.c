#include<stdio.h>
#include<unistd.h>

int main()
{
#if 1
    char str[2] = "1";
    setbuf(stdout,NULL);  // 0 buffer size

    while(1)
    {
        printf("%s",str);  // so str will print every 1sec as thr is no storage area available
        sleep(1);
    }
#endif

#if 0
    int n;
    printf("enter a number ");
    scanf("%d", &n);

#endif
    return 0;
}