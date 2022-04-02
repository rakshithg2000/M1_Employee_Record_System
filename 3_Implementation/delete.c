#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "delete.h"

int delete_details();

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

int delete_details(){
    printf("\n**************DELETE EMPLOYEE DETAILS**************\n\n");
    a = 'y';
    while(a == 'y')
    {
        printf("\nEnter name of employee to delete: ");
        scanf("%s",&empname);
        ft = fopen("Temp.dat","wb");
        rewind(fp);

        if(strcmp(e.name,empname) != 0){
            printf("\nEmployee Does not exist !!!\n");
        }
        while(fread(&e,record_size,1,fp) == 1)
        {
            if(strcmp(e.name,empname) == 0)
            {
                fwrite(&e,record_size,1,ft);
            }
        }
        fclose(fp);
        fclose(ft);
        remove("EMP.DAT");
        rename("Temp.dat","EMP.DAT");
        fp = fopen("EMP.DAT", "rb+");
        printf("\nDelete another record (y/n): ");
        fflush(stdin);
        a = getche();
        printf("\n\n");
    }
    return 0;
}
