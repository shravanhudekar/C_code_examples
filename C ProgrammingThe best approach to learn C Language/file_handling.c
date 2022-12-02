#include <stdio.h>

int main(int argc, char* argv[])    // 'argc' is no. of arguments passed and 'argv' hold all the arguments
{
    FILE *p1;
    int i;
    char word[15];


p1=fopen(argv[i],"w");        // (filename,operation)
printf("no. of CLI arguments: %d",argc);

/* storing all arguments inside the file */
/* start with index to 2 bec 1st 2 arg hold filename and filepath*/
fclose(p1);

for(i=2;i<argc;i++)                  
{
    fprintf(p1,"%s",argv[i]);
}

p1=fopen(argv[1],"r");    

printf("content of %s file",argv[1]);

for(i=2;i<argc;i++)                  
{
    fscanf(p1,"%s",word);
    printf("%s",word);
}


fclose(p1);


}