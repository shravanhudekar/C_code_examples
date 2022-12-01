#include<stdio.h>
#include<stdint.h>

typedef struct set  //tag name
{
    char data1;
    int data2;
    char data3;
    short data4;
}DataSet;
//__attribute__((packed));

int main()
{
    DataSet data;
    uint8_t *ptr;
    uint32_t totalSize;

    data.data1 = 0x11;
    data.data2 = 0xFFFFEEEE;
    data.data3 = 0x22;
    data.data4 = 0xABCD;
    
    ptr = (uint8_t*)&data;

    totalSize = sizeof(DataSet);

    printf("Memory address     Content \n");
    printf("===========================\n");

    for(uint32_t i=0; i<totalSize; i++)
    {
        printf("%p ,     %X\n",ptr,*ptr);
        ptr++;
    } 
    printf("Total size of struct DataSet is: %d\n",totalSize);
}
