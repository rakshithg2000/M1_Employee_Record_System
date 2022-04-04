#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

#include "add.h"
#include "modify.h"
#include "list.h"
#include "delete.h"

int add();
int modify();
int delete_details();
int list();

struct emp
{
    char name[40];
    int age;
    float bs;
};
struct emp e;

int main()
{
    FILE *fp, *ft;
    char a, choice;
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

    while(1)
    {
        system("cls"); //Clearing Console Window
        printf("\n**************EMPLOYEE RECORD SYSTEM**************\n\n");
        printf("1. Add Record\n");
        printf("2. List Records\n");
        printf("3. Modify Records\n");
        printf("4. Delete Records\n");
        printf("5. Exit\n");
        printf("\nYour Choice: "); //1,2,3,4,5
        fflush(stdin);
        choice  = getche();
        switch(choice)
        {
        case '1':
            //Adding Employee Details
            system("cls"); //Clearing Console Window
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
            break;
        case '2':
            //Listing Employee Details
            system("cls"); //Clearing Console Window
            rewind(fp);

            printf("\n**************LIST OF EMPLOYEE DETAILS**************\n\n");
            while(fread(&e,record_size,1,fp)==1)
            {
                printf("\n%s %d %.2f",e.name,e.age,e.bs);
            }
            getch();
            break;

        case '3':
            //Modifying Employee Details
            system("cls"); //Clearing Console Window

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
            break;
        case '4':
            //Deleting Employee Detials
            system("cls"); //Clearing Console Window
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
            break;
        case '5':
            fclose(fp); //Closing File
            exit(0);
        }
    }
    return 0;
}
