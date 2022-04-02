#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

#include "modify.h"

int modify();

FILE *fp, *ft;
char a, choice;

struct emp
{
    char name[40];
    int age;
    float bs;
};
struct emp e;

char empname[40];
long int record_size;

fp = fopen("EMP.DAT","rb+");
if(fp == NULL)
{
    fp = fopen("EMP.DAT","wb+");
    if(fp == NULL)
    {
        printf("Connot open file");
        exit(1);
    }
}

record_size = sizeof(e);

int modify(){
    printf("\n**************MODIFY EMPLOYEE DETAILS**************\n\n");
    a = 'y';
    while(a == 'y')
    {
        printf("\nEnter the employee name to modify: ");
        scanf("%s", &empname);
        rewind(fp);
        if(strcmp(e.name,empname) != 0){
            printf("\nEmployee Does not exist !!!\n");
        }
        while(fread(&e,record_size,1,fp)==1)
        {
            if(strcmp(e.name,empname) == 0)
            {
                printf("\nEnter New Name, Age and Salary: ");
                scanf("%s%d%f",&e.name,&e.age,&e.bs);
                fseek(fp,-record_size,SEEK_CUR);
                fwrite(&e,record_size,1,fp);

                break;
            }
        }
        printf("\nModify another record (y/n): ");
        fflush(stdin);
        a = getche();
        printf("\n\n");
    }
    return 0;
}
