#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdint.h>

#define MULTIPLYER 10
#define ASCII_CONVERSION 0X30

int sum=0;

void RX_Decvalue(char data)
{
    static int n=1;
    sum+= (data & ~(ASCII_CONVERSION))*n;         // (0x30)= 48 '0' conversion ASCII to decimal after reciving
    //printf("sum: %d\n",sum);
    n*=MULTIPLYER;
}
void TX_Decvalue(uint32_t data)
{
    char n;
    int i=1;
    while(data > 0)
    {
        n=data%10;
        printf("data transmit (%d byte): %c\n",i++,n|ASCII_CONVERSION);              // conversion decimal to ASCII for transmission
        RX_Decvalue(n);
        data/=10;   
    }
  
}
int main()
{
    TX_Decvalue(65978);

    printf("Data Recevied: %d\n",sum);

    return 0;
}

/* |OUTPUT:|

data transmit (1 byte): 8
data transmit (2 byte): 7
data transmit (3 byte): 9
data transmit (4 byte): 5
data transmit (5 byte): 6
Data Recevied: 65978

*/