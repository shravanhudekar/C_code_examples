#include <stdio.h>
/*
Add `int max_of_four(int a, int b, int c, int d)` here.
*/
int max(int x, int y)
{
    return (x>y ? x:y);             //Ternary operator     x>y ? TRUE:FALSE

}
int max_of_four(int a, int b, int c, int d)
{
    int expression;

    expression=max(a,b);
    expression=max(expression,c);
    expression=max(expression,d);

    return expression;
}

int main() {
    int a, b, c, d;
    scanf("%d %d %d %d", &a, &b, &c, &d);
    int ans = max_of_four(a, b, c, d);
    printf("%d", ans);
    
    return 0;
}