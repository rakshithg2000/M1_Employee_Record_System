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
            add();
            break;
        case '2':
            //Listing Employee Details
            system("cls"); //Clearing Console Window
            list();
            break;

        case '3':
            //Modifying Employee Details
            system("cls"); //Clearing Console Window

            modify();
            break;
        case '4':
            //Deleting Employee Detials
            system("cls"); //Clearing Console Window
            delete_details();
            break;
        case '5':
            fclose(fp); //Closing File
            exit(0);
        }
    }
    return 0;
}
