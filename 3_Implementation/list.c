#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>

#include "list.h"

int list();
FILE *fp;
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

int list(){
    rewind(fp);

    printf("\n**************LIST OF EMPLOYEE DETAILS**************\n\n");
    while(fread(&e,record_size,1,fp)==1)
    {
        printf("\n%s %d %.2f",e.name,e.age,e.bs);
    }
    getch();
    return 0;
}
