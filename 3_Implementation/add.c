#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

#include "add.h"

FILE *fp, *ft;
char a;
struct emp
{
    char name[40];
    int age;
    float bs;
};
struct emp e;

char empname[40];
long int record_size;

fp = fopen("EMP.DAT","r");
if(fp == NULL)
{
    fp = fopen("EMP.DAT","w");
    if(fp == NULL)
    {
        printf("Connot open file");
        exit(1);
    }
}

record_size = sizeof(e);

int add(){
    fseek(fp,0,SEEK_END);

    printf("\n**************ADD EMPLOYEE DETAILS**************\n\n");
    a = 'y';
    while(a == 'y')
    {
        printf("\nEnter name: ");
        scanf("%s",&em.name);
        printf("\nEnter age: ");
        scanf("%d",&em.age);
        printf("\nEnter basic salary: ");
        scanf("%f",&em.bs);

        fwrite(&em,record_size,1,fp);

        printf("\nAdd another record (y/n): ");
        fflush(stdin);
        printf("\n\n");
        a = getche();
    }
    return 0;
}
