#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include<string.h>
COORD coord = {0,0};
void gotoxy(int x,int y)
{
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}
int main()
{
    FILE *fp,*fp1,*ft;
    int found=0;
    char choice,another;
    int ido;
    struct employee
    {
        int empnum;
        char name[100];
        char birthday[100];
        char address[100];
        char email[100];
        char education[100];
        char joindate[100];
        char mobile[15];
        char id[8];
        float salary;

    };
    struct employee emp;

    char empname[100];
    char employeeid[8];
    int password=12345;
    int pass;
    long int recsize;
    fp = fopen("EMP.txt","rb+");
    if(fp == NULL)
    {
        fp = fopen("EMP.txt","wb+");
        if(fp == NULL)
        {
            printf("Connot open file");
            exit(1);
        }
    }

    recsize = sizeof(emp);
    while(1)
    {
        system("cls");
        gotoxy(60, 0);
        printf(" _______________________");
        gotoxy(60, 1);
        printf("|Daffodil university EMS|");
        gotoxy(60, 2);
        printf("|_______________________|");
        gotoxy(35, 5);
        printf(" ______________________");
        gotoxy(35, 6);
        printf("|1. New Record         |");
        gotoxy(35, 7);
        printf("|______________________|");
        gotoxy(55, 5);
        printf("_______________________");
        gotoxy(55, 6);
        printf("|2. Employee Record    |");
        gotoxy(55, 7);
        printf("|______________________|\n");
        gotoxy(76, 5);
        printf("________________________ ");
        gotoxy(76, 6);
        printf("|3.Accounts management |");
        gotoxy(76, 7);
        printf("|______________________|");
        gotoxy(96, 5);
        printf("_____________________");
        gotoxy(96, 6);
        printf(" |4.Search Employee  |");
        gotoxy(96, 7);
        printf(" |___________________|");
        gotoxy(50, 8);
        printf("_____________________");
        gotoxy(50, 9);
        printf("|5.Delete Record   |");
        gotoxy(50, 10);
        printf("|__________________|");
        gotoxy(70, 8);
        printf("__________________");
        gotoxy(70, 9);
        printf(" 6.Update Record  |");
        gotoxy(70, 10);
        printf("__________________|");
        gotoxy(87, 8);
        printf("___________");
        gotoxy(87, 9);
        printf("| 7.EXIT   |");
        gotoxy(87, 10);
        printf("|__________|");
        gotoxy(85, 11);
        fseek(fp, 0, SEEK_END);
        gotoxy(65, 14);
        printf("enter your choice: ");
        choice=getche();
        fflush(stdin);
        switch(choice)
        {
        case '1':
            system("cls");
            fseek(fp, 0, SEEK_END);
            gotoxy(40, 0);
            printf(" ________________________");
            gotoxy(40, 1);
            printf("|Daffodil university EMS |");
            gotoxy(40, 2);
            printf("|________________________|");
            gotoxy(40, 4);
            printf("     <ADD NEW RECORD OPTION>");
            gotoxy(40, 5);
            printf(" __________________________________");
            gotoxy(30, 6);
            printf("<Only office management can use this option>");
            gotoxy(30, 7);
            printf("Enter admin password: ");
            scanf("%d", &pass);
            if(pass==password)
            {
                another = 'y';
                while(another == 'y')
                {
                    fp1 = fopen("id.txt","r");
                    fscanf(fp1,"%d",&ido);
                    emp.empnum=ido+1;
                    ido=emp.empnum;
                    fp1 = fopen("id.txt","w");
                    fprintf(fp1,"%d",ido);
                    printf("\nEmployee number:%d",emp.empnum);
                    printf("\n\t<Enter employee's personal details>");
                    printf("\nName: ");
                    scanf(" %[^\n]s",&emp.name);
                    printf("\nDate of birth: ");
                    scanf(" %[^\n]s", &emp.birthday);
                    printf("\nAddress: ");
                    scanf(" %[^\n]s", &emp.address);
                    printf("\nEducational Qualification: ");
                    scanf(" %[^\n]s", &emp.education);
                    printf("\nMobile number: ");
                    scanf(" %[^\n]s", &emp.mobile);
                    printf("\nEmail: ");
                    scanf(" %[^\n]s", &emp.email);
                    printf("\n\t<Enter employee's official details>");
                    printf("\nBasic salary:$");
                    scanf("%f", &emp.salary);
                    printf("\nJoining date: ");
                    scanf(" %[^\n]s",&emp.joindate);
                    printf("\nEnter 4 digit ID of this employee: ");
                    scanf(" %[^\n]s",&emp.id);
                    fwrite(&emp,recsize,1,fp);
                    printf("\nEmployee record successfully saved\n");
                    printf("\nWant to add another employee??"
                           "\nIf YES, press y/If NO, press n:__");
                    fflush(stdin);
                    another = getche();
                }
            }
            break;
        case '2':
            system("cls");
            rewind(fp);
            gotoxy(40, 0);
            printf(" ________________________");
            gotoxy(40, 1);
            printf("|Daffodil university EMS |");
            gotoxy(40, 2);
            printf("|________________________|");
            gotoxy(40, 4);
            printf("     <VIEW CURRENT RECORD>");
            gotoxy(40, 5);
            printf(" __________________________________");
            gotoxy(30, 6);
            printf("<Only office management can access to this option>");
            gotoxy(30, 7);
            printf("Enter admin password: ");
            scanf("%d", &pass);
            if(pass==password)
            {
                while(fread(&emp,recsize,1,fp)==1)
                {
                    printf("\n\nEmployee number: %d", emp.empnum);
                    printf("\n<Employee's personal details>");
                    printf("\nName         : %s", emp.name);
                    printf("\nDate of birth: %s", emp.birthday);
                    printf("\nAddress      : %s", emp.address);
                    printf("\nEducation    : %s", emp.education);
                    printf("\nMobile number: %s", emp.mobile);
                    printf("\nEmail        : %s", emp.email);
                    printf("\n<Employee's official details>");
                    printf("\nBasic salary : $%.2f", emp.salary);
                    printf("\nJoining Date : %s", emp.joindate);
                    printf("\nOfficial ID  : %s", emp.id);
                }
            }
            printf("\n\n<PRESS ANY KEY TO GO BACK TO MAIN MENU>");
            fflush(stdin);
            getch();
            break;
        case '3':
            system("cls");
            rewind(fp);
            char num;
            float salaryAmount;
            float houserent;
            float transport;
            float medical;
            float recreation;
            float tiffin;
            float total;
            char again;

            gotoxy(40, 0);
            printf(" ________________________");
            gotoxy(40, 1);
            printf("|Daffodil university EMS |");
            gotoxy(40, 2);
            printf("|________________________|");
            gotoxy(40, 4);
            printf("     <ACCOUNTS MANAGEMENT>");
            gotoxy(40, 5);
            printf(" __________________________________");
            gotoxy(30, 6);
            printf("<Only office management can access to this option>");
            gotoxy(30, 7);
            printf("Enter admin password: ");
            scanf("%d", &pass);
            if(pass==password)
            {
                system("cls");
                gotoxy(40, 0);
                printf(" _______________________");
                gotoxy(40, 1);
                printf("|Daffodil university EMS|");
                gotoxy(40, 2);
                printf("|_______________________|");
                gotoxy(40, 4);
                printf("     <ACCOUNTS MANAGEMENT>");
                gotoxy(40, 5);
                printf(" __________________________________");
                gotoxy(40, 9);
                printf("1.Basic Salary sheet");
                gotoxy(40, 11);
                printf("2.Final monthly salary");
                gotoxy(40, 13);
                printf("3. Exit");
                gotoxy(40, 15);
                printf("Enter your choice: ");
                num=getche();
                switch(num)
                {
                case '1':
                    system("cls");
                    gotoxy(40, 0);
                    printf(" ________________________");
                    gotoxy(40, 1);
                    printf("|Daffodil university EMS |");
                    gotoxy(40, 2);
                    printf("|________________________|");
                    gotoxy(40, 4);
                    printf("     <EMPLOYEE BASIC SALARY SHEET>");
                    gotoxy(40, 5);
                    printf(" __________________________________");
                    printf("\n\n%s\t%s\t%s\n", "ID", "NAME", "SALARY");
                    while(fread(&emp,recsize,1,fp)==1)
                    {
                        printf("%s\t%s\t%7.2f\n", emp.id, emp.name, emp.salary);
                    }
                    printf("\n\n<PRESS ANY KEY TO GO BACK!");
                    fflush(stdin);
                    getch();
                    break;
                case '2':
                    system("cls");
                    gotoxy(40, 0);
                    printf(" ________________________");
                    gotoxy(40, 1);
                    printf("|Daffodil university EMF |");
                    gotoxy(40, 2);
                    printf("|________________________|");
                    gotoxy(40, 4);
                    printf("     <FINAL MONTHLY SALARY STATUS>");
                    gotoxy(40, 5);
                    printf(" __________________________________");
                    again='y';
                    while(again=='y')
                    {

                        printf("\n\nEnter the employee ID number to check final salary status: ");
                        scanf(" %[^\n]s", &employeeid);
                        rewind(fp);
                        while(fread(&emp,recsize,1,fp)==1)
                        {
                            if(strcmp(emp.id,employeeid) == 0)
                            {
                                printf("Employee name: %s", emp.name);
                                printf("\nEmployee ID: %s", emp.id);
                                printf("\nBasic salary  : $%.2f", emp.salary);
                                salaryAmount=emp.salary;
                                tiffin=(salaryAmount/100)*5;
                                transport=(salaryAmount/100)*10;
                                houserent=(salaryAmount/100)*60;
                                medical=(salaryAmount/100)*10;
                                recreation=(salaryAmount/100)*5;
                                printf("\nHouse rent    : $%.2f", houserent);
                                printf("\nTransport fee : $%.2f", transport);
                                printf("\nMedical fee   : $%.2f", medical);
                                printf("\nRecreation fee: $%.2f", recreation);
                                printf("\nTiffin fee    : $%.2f", tiffin);
                                total=salaryAmount+houserent+transport+medical+recreation+tiffin;
                                printf("\nTotal salary per month: $%.2f", total);
                                printf("\n\n<PRESS ANY KEY TO GO BACK!");
                                fflush(stdin);
                                again=getch();

                            }

                        }

                    }

                }
                break;
            }

        case '4':
            system("cls");
            rewind(fp);
            gotoxy(40, 0);
            printf(" ________________________");
            gotoxy(40, 1);
            printf("|Daffodil university EMS |");
            gotoxy(40, 2);
            printf("|________________________|");
            gotoxy(40, 4);
            printf("        <EMPLOYEE SEARCH>");
            gotoxy(40, 5);
            printf(" __________________________________");
            gotoxy(30, 6);
            printf("Only office management can access to this option");
            gotoxy(30, 7);
            printf("Enter admin password: ");
            scanf("%d", &pass);
            if(pass==password)
            {
                printf("\nHere you can search any employee by his/her id number. ");
                rewind(fp);
                another='y';
                while(another == 'y')
                {
                    printf("\n\nEnter the employee ID to search: ");
                    scanf(" %[^\n]s", &employeeid);
                    rewind(fp);
                    while(fread(&emp,recsize,1,fp)==1)
                    {
                        if(strcmp(emp.id,employeeid) == 0)
                        {
                            printf("\n\nEmployee number: %d", emp.empnum);
                            printf("\n<Employee's personal details>");
                            printf("\nName: %s", emp.name);
                            printf("\nDate of birth: %s", emp.birthday);
                            printf("\nAddress: %s", emp.address);
                            printf("\nEducational Qualification: %s", emp.education);
                            printf("\nMobile number: %s", emp.mobile);
                            printf("\nEmail: %s", emp.email);
                            printf("\n<Employee's official details>");
                            printf("\nID: %s", emp.id);
                            printf("\nBasic salary: %.2f", emp.salary);
                            printf("\nJoining Date: %s", emp.joindate);
                            printf("\n");
                        }
                        another=getche();
                    }
                }
            }
            break;
        case '5':

            system("cls");
            rewind(fp);
            gotoxy(40, 0);
            printf(" ________________________");
            gotoxy(40, 1);
            printf("|Daffodil university EMS |");
            gotoxy(40, 2);
            printf("|________________________|");
            gotoxy(40, 4);
            printf(" <DELETE CURRENT RECORD>");
            gotoxy(40, 5);
            printf(" __________________________________");
            gotoxy(30, 6);
            printf("Only office management can access to this option");
            gotoxy(30, 7);
            printf("Enter admin password: ");
            scanf("%d", &pass);
            if(pass==password)
            {
                gotoxy(40, 0);
                printf(" ________________________");
                gotoxy(40, 1);
                printf("|Daffodil university EMS |");
                gotoxy(40, 2);
                printf("|________________________|");
                gotoxy(40, 4);
                printf(" <DELETE CURRENT RECORD>");
                gotoxy(40, 5);
                printf(" __________________________________");
                gotoxy(10, 8);
                printf("\nHere you can Delete any employee by his/her id number.");
                rewind(fp);
                another = 'y';
                while(another == 'y')
                {
                    printf("\n\nEnter ID of employee to delete: ");
                    scanf(" %[^\n]s", &employeeid);
                    ft = fopen("Temp.txt","wb+");
                    rewind(fp);
                    while(fread(&emp,recsize,1,fp) == 1)
                    {
                        if(strcmp(emp.id,employeeid) == 0)
                        {
                            found=1;
                        }
                        else
                        {
                            fwrite(&emp,recsize,1,ft);
                        }
                    }
                    fclose(fp);
                    fclose(ft);
                    fp = fopen("EMP.txt", "wb+");
                    ft = fopen("Temp.txt","rb+");

                    if(found==0)
                    {
                        printf("Data not found");
                    }
                    else
                    {
                        while(fread(&emp,recsize,1,ft) == 1)
                        {
                            fwrite(&emp,recsize,1,fp);
                        }
                    }
                    printf("\nEmployee record delete successfully saved\n");
                    printf("\nWant to delete another employee??"
                           "\nIf YES, press y/If NO, press n:__");
                    fflush(stdin);
                    another = getche();
                }
            }
        case '6':
            system("cls");
            gotoxy(40, 0);
            printf(" ________________________");
            gotoxy(40, 1);
            printf("|Daffodil university EMS |");
            gotoxy(40, 2);
            printf("|________________________|");
            gotoxy(40, 4);
            printf("     <UPDATE CURRENT RECORD>");
            gotoxy(40, 5);
            printf(" __________________________________");
            another = 'y';
            gotoxy(30, 6);
            printf("Only office management can access to this option");
            gotoxy(30, 7);
            printf("Enter admin password: ");
            scanf("%d", &pass);
            if(pass==password)
            {
                while(another == 'y')
                {
                    printf("\nEnter the employee name or ID to update: ");
                    scanf(" %[^\n]s", &empname);
                    rewind(fp);
                    while(fread(&emp,recsize,1,fp)==1)
                    {
                        if(strcmp(emp.name,empname) == 0)
                        {
                            printf("Employee name: %s", emp.name);
                            printf("\nEmployee ID: %s", emp.id);
                            printf("\n<Enter employee's personal details>\n");
                            printf("\nName: ");
                            scanf(" %[^\n]s", &emp.name);
                            printf("\nDate of birth: ");
                            scanf(" %[^\n]s", &emp.birthday);
                            printf("\nAddress: ");
                            scanf(" %[^\n]s", &emp.address);
                            printf("\nEducational Qualification: ");
                            scanf(" %[^\n]s", &emp.education);
                            printf("\nMobile number: ");
                            scanf(" %[^\n]s", &emp.mobile);
                            printf("\nEmail: ");
                            scanf(" %[^\n]s", &emp.email);
                            printf("\n<Enter employee's official details>");
                            printf("\nBasic salary:$ ");
                            scanf("%f", &emp.salary);
                            printf("\nJoining Date: ");
                            scanf(" %[^\n]s",&emp.joindate);
                            printf("\n");
                            fseek(fp,-recsize,SEEK_CUR);
                            fwrite(&emp,recsize,1,fp);
                            break;
                        }
                        else  if(strcmp(emp.id,empname) == 0)
                        {
                            printf("Employee name: %s", emp.name);

                            printf("\nDate of birth: %s", emp.birthday);
                            printf("\nAddress      : %s", emp.address);
                            printf("\nEducation    : %s", emp.education);
                            printf("\nMobile number: %s", emp.mobile);
                            printf("\nEmail        : %s", emp.email);
                            printf("\n<Employee's official details>");
                            printf("\nBasic salary : $%.2f", emp.salary);
                            printf("\nJoining Date : %s", emp.joindate);
                            printf("\nEmployee ID: %s", emp.id);
                            printf("\n<Enter employee's personal details>\n");
                            printf("\nName: ");
                            scanf(" %[^\n]s", &emp.name);
                            printf("\nDate of birth: ");
                            scanf(" %[^\n]s", &emp.birthday);
                            printf("\nAddress: ");
                            scanf(" %[^\n]s", &emp.address);
                            printf("\nEducational Qualification: ");
                            scanf(" %[^\n]s", &emp.education);
                            printf("\nMobile number: ");
                            scanf(" %[^\n]s", &emp.mobile);
                            printf("\nEmail: ");
                            scanf(" %[^\n]s", &emp.email);
                            printf("\n<Enter employee's official details>");
                            printf("\nBasic salary:$ ");
                            scanf("%f", &emp.salary);
                            printf("\nJoining Date: ");
                            scanf(" %[^\n]s",&emp.joindate);
                            printf("\n");
                            fseek(fp,-recsize,SEEK_CUR);
                            fwrite(&emp,recsize,1,fp);
                            break;
                        }
                    }
                    printf("Employee record successfully updated");
                    printf("\nWant to update another record??\n"
                           "If YES, press y/ If NO, press n:__");
                    fflush(stdin);
                    another = getche();
                }
            }
            break;

        }
    }
}
