/*C Prog - Program using structure to take Student Name, Roll No, PCM marks, Calculate percentage */

#include<stdio.h>
#include<stdint.h>
#include<stdlib.h>
#include <math.h>


typedef struct stud
{
    char name[10];
    int roll_no;
    int PCM_marks;
    double percent;

}student_t;


int main()
{
    int n,i;
    printf("enter no. of students: ");
    scanf("%d",&n);

    student_t list_stud[n],S;

    for (i=0;i<n;i++)
    {
        //printf("\nenter student %d name: ",i+1);
        scanf("\n");
        scanf("%[^\n]%*c",&S.name);
      //  printf("roll no. ");
         scanf("%d",&S.roll_no);
     //   printf("PCM marks: ");
        scanf("%d",&S.PCM_marks);

        S.percent=(double)S.PCM_marks*0.833;

        list_stud[i]=S;
    }

    printf("Name\t Roll No.\t PCM Marks\t Percentage\n");

    for (i=0;i<n;i++)
    {
        printf(" %s\t   %d \t\t   %d\t\t   %.2f%%\n",list_stud[i].name,
                                                    list_stud[i].roll_no,
                                                    list_stud[i].PCM_marks,
                                                    list_stud[i].percent);
    }

    return 0;
}

/*
|OUTPUT:|

Name     Roll No.        PCM Marks       Percentage
 shr       11              93              77.47%
 man       23              45              37.48%
 qwer      24              60              49.98%
 asd       8               115             95.80%

 */