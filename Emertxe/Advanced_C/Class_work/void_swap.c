#include <stdio.h>
/**
 * @brief This function will swap data of two varaible of any type based to data type size
 * 
 * @param a void pointer holding address of passed argument v1
 * @param b void pointer holding address of passed argument v2
 * @param size  size of type of which arguments passed
 */
void swap(void *a, void *b, int size)
{
    char temp;

    for(int i=0; i<size; i++)
    {
        temp = *(char *)(a + i);
        *(char *)(a + i) = *(char *)(b + i);
        *(char *)(b + i) = temp;
    }

}
 
int main()
{
    int x= 12345678, y= 87654321;

    swap(&x, &y,sizeof(x));
    printf("%d %d\n",x,y);

    char m = 'A', n = 'Z';

    swap(&m, &n, sizeof(m));
    printf("%c %c\n",m,n);

    return 0;
}