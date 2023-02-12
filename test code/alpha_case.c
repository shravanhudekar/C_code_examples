#include<stdio.h>
#include<stdint.h>

void lower_to_upper(uint8_t *alpha)
{
    int i=0;

    while(alpha[i] != '\0' )
    {
        //alpha[i++] &= '_';
        alpha[i++] &= ~' ';
    }
}

void upper_to_lower(uint8_t *alpha)
{
    int i=0;

    while(alpha[i] != '\0')
    {
        alpha[i++] |= ' ';
    }
}

void toggle_case(uint8_t *alpha)
{
    int i=0;

    while(alpha[i] != '\0')
    {
        alpha[i++] ^= ' ';
    }
}

void alpha_position(uint8_t *alpha)
{
    int i=0,pos;

    while(alpha[i] != '\0')
    {
        pos= alpha[i++] & 0x1F;      // any char is ANDed with 31 will give positon case will not matter here as AND with 31 will subtract 32 and 64 w.r.t character                
        printf("%d ",pos);
    }
    printf("\n");
}

int main()
{
    char str[1];
    printf("enter a string: ");
    scanf("\n");
    scanf("%[^\n]%*c",str);

    //lower_to_upper(str);
    //upper_to_lower(str);

    toggle_case(str);
    alpha_position(str);
    printf("%s",str);
    return 0;
}
