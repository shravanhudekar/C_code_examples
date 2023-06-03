#include<stdio.h>

typedef struct sample
{
    int a;
    int b;
    const void (*operate)(void);
}complex;

void obj_add(complex* obj, complex *data)
{
    obj->operate = &Add;

    (void *)Add.operate(obj,data);
}
void Add(complex* obj, complex *data)
{
    obj->a = data->a;
    obj->b = data->b;
}


int main()
{

}