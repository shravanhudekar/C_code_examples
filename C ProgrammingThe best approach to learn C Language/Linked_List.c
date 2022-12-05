#include <stdio.h>
#include <stdlib.h>
typedef struct 
{
    int item;
    struct node *next;
}node;


int create(node *n)
{
    printf("enter a value\n");
    scanf("%d",n->item);

    n=(node *)malloc(sizeof(node));
    n->next=NULL;



}

int print(node *n)
{
    while(n != NULL)
    {
        printf("&d",n->item);
        n = n->next;
    }

}
int main()
{
     node *data=NULL;
    data=(node *)malloc(sizeof(node));

    for(int i=0; i<5;i++)
    {
        create(data);
    }
    
    print(data);
    

    return 0;
}

