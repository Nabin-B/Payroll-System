
#include<stdio.h>
#include<iostream>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
#include<windows.h>
#include<time.h>
#include<iomanip>
#include<ctype.h>
#define max 50
using namespace std;

int num=0;
void gotoXY(int,int);                  //224           
void Cdelay(int);                      //103
void border(int, int,int, int);        //257
void borderNoDelay(int, int,int, int); //232
void loginFrame(int, int, int, int);   //289
void intro();                          //373
void login();                          //150
void menu();                           //421                                           
void insert();                         //293
void edit();                           //622
void editmenu();                       //530
void editname(int);                    //556
void editcode(int);                    //563
void editdes(int);                     //559
void editexp(int);                     //576
void editage(int);                     //582
void editsalary(int);                  //89
void list();                           //381
void deletes();                        //447
void search();                         //484
void setWindowSize(int,int);           //217
void saverecords();                    //85
void getrecords();                     //68
bool isFilePresent();                  //109
void displayPayslip();                 //669
void loading ();                       //409
bool isFilePresent();                  //110

class employee
{
public:
    char fname[20];
    char lname[20];
    int code;
    char designation[20];
    int exp;
    int age;
    int salary;
    char AnyLoan;
    
    int HRA;
    int PF;
    int tax;
    int MealAllowance;
    int TransportAllowance;
    int MedicalAllowance;
    int LoanBalance;
    int LoanDebit;
    int grosspay;
    int workingHours;
    int DA; 
    
};
employee emp[max],tempemp[max];


void getrecords()
{
    FILE *fp;
    fp = fopen("Records.txt","r");
    int c=0;
    if(fp!=NULL)
    {
        while(feof(fp)==0)
        {
            fscanf(fp,"%s\t%s\t%d\t%s\t%d\t%d\t%d\t%c\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\n",&emp[c].fname,&emp[c].lname,&emp[c].code,&emp[c].designation,&emp[c].exp,&emp[c].age,&emp[c].salary,&emp[c].AnyLoan,&emp[c].HRA,&emp[c].PF,&emp[c].tax,&emp[c].MealAllowance,&emp[c].TransportAllowance,&emp[c].MedicalAllowance,&emp[c].LoanBalance,&emp[c].LoanDebit,&emp[c].grosspay,&emp[c].workingHours,&emp[c].DA);
            c++;
        }
        num=c;
    }
    fclose(fp);
}


void saverecords()
{
    if(num==0)
    {
        system("del Records.txt");
    }
    else
    {
        FILE *fp;
        fp = fopen("Records.txt","a+");
        for(int i=0;i<num;i++)
        {
            fprintf(fp,"%s\t%s\t%d\t%s\t%d\t%d\t%d\t%c\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\n",emp[i].fname,emp[i].lname,emp[i].code,emp[i].designation,emp[i].exp,emp[i].age,emp[i].salary,emp[i].AnyLoan,emp[i].HRA,emp[i].PF,emp[i].tax,emp[i].MealAllowance,emp[i].TransportAllowance,emp[i].MedicalAllowance,emp[i].LoanBalance,emp[i].LoanDebit,emp[i].grosspay,emp[i].workingHours,emp[i].DA);
        }
        fclose(fp);
    }
}

void Cdelay(int msec)
{
    long goal = msec + (clock());
    while (goal > (clock()));
    
}
bool isFilePresent()
{
    FILE *fp;
    fp = fopen("Records.txt","r");
    if(fp==NULL)
        return false;
    else
        return true;
}
void loginFrame1(int xLenS = 18, int yLenS = 8, int xLenE = 55, int yLenE = 15)
{
    system("cls");
    gotoXY(xLenS,yLenS);printf("%c",201);
    
    gotoXY(xLenS,yLenE);printf("%c",200);
    
    for(int i=xLenS+1;i<=xLenE-1;i++)         //Top and Bottom Border line
    {
        //Cdelay(0);
        gotoXY(i,yLenS);
        printf("%c",205);
        //puts(style);
        gotoXY(i,yLenE);
        //puts(style);
        printf("%c",205);

    }
    gotoXY(xLenE,yLenS);printf("%c",187);
    gotoXY(xLenE,yLenE);printf("%c",188);
    for(int i=yLenS+1;i<=yLenE-1;i++)         //Left and Right Border Line
    {
        //Cdelay(20);
        gotoXY(xLenS, i);
        printf("%c",186);
        //puts(style);
        gotoXY(xLenE, i);
        printf("%c",186);
        //puts(style);
    }
    printf("\n\n");
}
void login()
{
    
    char UserName[30],Password[30],ch;int i=0;
    gotoXY(20,10);
    printf("Enter UserName : ");
    
    cin>>UserName;
    gotoXY(20,12);
    cout<<"Enter Password : ";
    while(1)
    {
        ch = getch();
        if(ch==13)
            break;
        if(ch==32||ch==9)
            continue;
        else
        {
            cout<<"*";
            Password[i]=ch;
            i++;
        }
    }
    Password[i] = '\0';
    if(strcmp(UserName,"admin")==0 && strcmp(Password,"password")==0)
    {
        system("cls");
        loginFrame1();
        gotoXY(27,10);
        cout<<"Login Success!!!";
        gotoXY(21,12);
        cout<<"Will be redirected in 3 Seconds...";
            gotoXY(56,12);
        Cdelay(1000);
        gotoXY(44,12);
        cout<<"\b \b2";
            gotoXY(56,12);
        Cdelay(1000);
        gotoXY(44,12);
        cout<<"\b \b1";
            gotoXY(56,12);
        Cdelay(1000);
    }
    else
    {
        system("cls");
        loginFrame1();
        gotoXY(27,10);
        printf("Access Denied!!!\a");
        gotoXY(21,12);
        cout<<"Will be redirected in 3 Seconds...";
            gotoXY(56,12);
        Cdelay(1000);
        gotoXY(44,12);
        cout<<"\b \b2";
            gotoXY(56,12);
        Cdelay(1000);
        gotoXY(44,12);
        cout<<"\b \b1";
            gotoXY(56,12);
        Cdelay(1000);
        system("cls");
        loginFrame1();
        login();
    }
}
void setWindowSize(int width=670,int height=445)
{
    HWND console = GetConsoleWindow();
    RECT r;
    GetWindowRect(console, &r);
    MoveWindow(console, r.left, r.top, width, height, TRUE);
}
void gotoXY(int X, int Y)
{
    COORD coordinates;
    coordinates.X = X;
    coordinates.Y = Y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coordinates);
}

void borderNoDelay(int xLenS = 2, int yLenS = 2,int xLenE = 85, int yLenE = 27)
{
    system("cls");
    gotoXY(xLenS,yLenS);printf("%c",201);
    
    gotoXY(xLenS,yLenE);printf("%c",200);
    
    for(int i=xLenS+1;i<=xLenE-1;i++)         //Top and Bottom Border line
    {
        gotoXY(i,yLenS);
        printf("%c",210);
        gotoXY(i,yLenE);
        printf("%c",210);
    }
    gotoXY(xLenE,yLenS);printf("%c",187);
    gotoXY(xLenE,yLenE);printf("%c",188);
    for(int i=yLenS+1;i<=yLenE-1;i++)         //Left and Right Border Line
    {
        gotoXY(xLenS, i);
        printf("%c",186);
        gotoXY(xLenE, i);
        printf("%c",186);
    }
    printf("\n\n");
}
void border(int xLenS = 2, int yLenS = 2,int xLenE = 80, int yLenE = 22 )
{
    system("cls");
    gotoXY(xLenS,yLenS);printf("%c",201);
    
    gotoXY(xLenS,yLenE);printf("%c",200);
    
    for(int i=xLenS+1;i<=xLenE-1;i++)         //Top and Bottom Border line
    {
        Cdelay(15);
        gotoXY(i,yLenS);
        printf("%c",205);
        //puts(style);
        gotoXY(i,yLenE);
        //puts(style);
        printf("%c",205);

    }
    gotoXY(xLenE,yLenS);printf("%c",187);
    gotoXY(xLenE,yLenE);printf("%c",188);
    for(int i=yLenS+1;i<=yLenE-1;i++)         //Left and Right Border Line
    {
        Cdelay(15);
        gotoXY(xLenS, i);
        printf("%c",186);
        //puts(style);
        gotoXY(xLenE, i);
        printf("%c",186);
        //puts(style);
        
    }
    printf("\n\n");
}
void loginFrame(int xLenS = 18, int yLenS = 8, int xLenE = 55, int yLenE = 15)
{
    border(xLenS,yLenS,xLenE,yLenE);
}
void insert()
{
    
    borderNoDelay();
    int i=num;
    int sal,Rate,PF,TAX,HRA,MealA,MedicalA,TransportA,LoanBal,LoanDeb,h,DA;
    char loan;
    num+=1;
    gotoXY(28,4);
    printf("Insert New Record");
    gotoXY(10,6);
    cout<<"First Name : ";
    //cin.getline(emp[i].name,sizeof(emp[i].name));
	cin>>emp[i].fname;
    gotoXY(10,8);
    cout<<"last name:";
    cin>>emp[i].lname;
    gotoXY(10,10);
    cout<<"Code : ";
    cin>>emp[i].code;
    gotoXY(10,12);
    cout<<"Designation : ";
    cin>>emp[i].designation;
    gotoXY(10,14);
    cout<<"Years of Experience : ";
    cin>>emp[i].exp;
    gotoXY(10,16);
    cout<<"Age : ";
    cin>>emp[i].age;
    gotoXY(10,18);
    cout<<"Enter Working Hours : ";    
    cin>>h;
    gotoXY(10,20);
    cout<<"Enter the working hour rate:";
    cin>>Rate;
    sal = h*Rate;
    emp[i].workingHours = h;
    do
    {
        gotoXY(10,22);
        cout<<"Any Loan (Y/N) ?: \b \b";
        loan=getche();
        if(loan=='Y'|| loan == 'y' || loan =='n' || loan == 'N')
            break;
    }while(1);
    if(loan=='y'|| loan=='Y')
    {
    gotoXY(10,24);
    cout<<"Enter Loan Balance : ";
    cin>>LoanBal;
    }
    else
    {
        LoanBal=0;
    }
    gotoXY(14,26);
    cout<<"Recorded Succesfully...!!!";
    
    TAX =  0.04 * sal;
    DA = 1.20 * sal;
    PF = 0.12 * sal;
    HRA = sal * 0.27;
    MealA = 300;
    MedicalA = 300;
    TransportA = 300;
    LoanDeb = sal * 0.09;
    if(LoanDeb > LoanBal)
    {
        LoanBal = 0;
        LoanDeb = LoanBal;
    }
    emp[i].salary = sal;
    emp[i].DA = DA;
    emp[i].tax=TAX;
    emp[i].PF = PF;
    emp[i].HRA = HRA;
    emp[i].MealAllowance = MealA;
    emp[i].MedicalAllowance = MedicalA;
    emp[i].TransportAllowance = TransportA;
    emp[i].LoanBalance = LoanBal-LoanDeb;
    emp[i].AnyLoan = loan;
    emp[i].LoanDebit = LoanDeb;
    emp[i].grosspay = (sal+MealA+MedicalA+TransportA+HRA+DA)-(PF+TAX+LoanDeb) ;
    getch();
}

void intro()
{
    gotoXY(26,5); printf("PAYROLL MANAGEMENT SYSTEM");
    gotoXY(25,15);printf("Press Any key to continue...");
    getch();
    
}

void  list()
{
    //system("cls");
    borderNoDelay();
    gotoXY(20,4);
    printf("       ******** List of the Employees ********");
    gotoXY(6,6);
    cout<<"Name\t\tCode\tDesignation\tYears(EXP)\tAge\tSalary "<<endl;
    gotoXY(6,7);
    cout<<"------------------------------------------------------------------"<<endl;
    for(int i=0,j=8;i<=num-1;i++,j++)
    {
        gotoXY(6,j);
        cout<<emp[i].fname;
        gotoXY(13,j);
        cout<<emp[i].lname;
        gotoXY(25,j);
        cout<<emp[i].code;
        gotoXY(35,j);
        cout<<emp[i].designation;
        gotoXY(50,j);
        cout<<emp[i].exp;
        gotoXY(60,j);
        cout<<emp[i].age;
        gotoXY(70,j);
        cout<<emp[i].grosspay;
    }
    getch();
}
void loading()
{
    system("cls");
    gotoXY(55,20);
    printf("Loading...");
    gotoXY(50,22);
    for(int i = 0; i<20; i++)
    {
        Cdelay(200);
        printf("%c",254);
    }
}
void menu()
{
    //system("cls");
    borderNoDelay();
    //gotoXY(0,0);
    //cout<<"Number of Records Avaliable : "<<num;
    gotoXY(16,4);
    printf("*****  Payroll Management System 1.0 ***** ");
    gotoXY(12,6);
    cout<<"Press  i ----> Insert New Record.";
    gotoXY(12,8);
    cout<<"Press  e ----> Edit a Record.";
    gotoXY(12,10);
    cout<<"Press  d ----> Delete a Record.";
    gotoXY(12,12);
    cout<<"Press  s ----> Search a Record.";
    gotoXY(12,14);
    cout<<"Press  l ----> List The Employee Table.";
    gotoXY(12,16);
    cout<<"Press  p ----> Print Employee PaySlip.";
    gotoXY(12,18);
    cout<<"Press  q ----> Quit Program.";
    gotoXY(16,22);
    cout<<"Select Your Option ====> ";
}

void deletes()
{
    for(int i=0;i<num;i++)
    {
        tempemp[i]=emp[i];
    }
    //system("cls");
    borderNoDelay();
    int code;
    int check=-1;
    gotoXY(28,4);
    printf("Delete a Record");
    gotoXY(10,6);
    cout<<"Enter the JobCode To Delete That Record  :";
    cin>>code;
    int i,j;
    for(i=0;i<=num-1;i++)
    {
         if(emp[i].code==code)
        {
            check=i;
        }
    }
    if(check!=-1)
    {
        for(i=0,j=0;i<=num-1;i++,j++)
        {
            if(i==check)
            {
                i++;
            }
            emp[j]=tempemp[i];
        }
        num--;
    }
    printf("Deleted successfully");
}

void search()
{
    //system("cls");
    borderNoDelay();
    int jobcode;
    bool found = false;
    gotoXY(10,4);
    cout<<"You can Search only through the Jobcode of an Employee";
    gotoXY(10,6);
    cout<<"Enter Code Of the Employee : ";
    cin>>jobcode;
    for(int i=0;i<=num-1;i++)
    {
        if(emp[i].code==jobcode)
        {
            gotoXY(6,8);
            cout<<"Name\tCode\tDesignation\tYears(EXP)\tAge\tSalary "<<endl;
            gotoXY(6,9);
            cout<<"------------------------------------------------------------------"<<endl;
            gotoXY(6,11);
            cout<<emp[i].fname;
            gotoXY(6,12);
            cout<<emp[i].lname;
            gotoXY(19,11);
            cout<<emp[i].code;
            gotoXY(26,11);
            cout<<emp[i].designation;
            gotoXY(47,11);
            cout<<emp[i].exp;
            gotoXY(58,11);
            cout<<emp[i].age;
            gotoXY(66,11);
            cout<<emp[i].grosspay;
            found = true;
        }
        //else
        //
    }
    if(!found)
    {
        gotoXY(26,11);
        cout<<"No records Found...!!!\a";
    }
    getch();
}



void editmenu()
{
    //system("cls");
    borderNoDelay();
    gotoXY(28,4);
    printf("Edit An Entry");
    gotoXY(10,6);
    cout<<"What Do You Want To edit";
    gotoXY(12,8);
    cout<<"f ---------> First Name ";
    gotoXY(12,10);
    cout<<"l ---------> Last Name";
    gotoXY(12,11);
    cout<<"c ---------> Code ";
    gotoXY(12,12);
    cout<<"d ---------> Designation";
    gotoXY(12,13);
    cout<<"e ---------> Experience ";
    gotoXY(12,14);
    cout<<"a ---------> Age";
    gotoXY(12,15);
    cout<<"s ---------> Salary";
    gotoXY(12,16);
    cout<<"q ---------> QUIT";
    gotoXY(12,17);
    cout<<"Enter Choice ---->>>  ";
}

void editfname(int i)
{
    gotoXY(10,18);
    cout<<"Enter New First Name----->  ";
    cin>>emp[i].fname;
}
void editlname(int i){
    gotoXY(10,19);
    cout<<"Enter last name-------->";
    cin>>emp[i].lname;
}

void editcode(int i)
{
    gotoXY(10,18);
    cout<<"Enter New Job Code----->  ";
    cin>>emp[i].code;
}
void editdes(int i)
{
    gotoXY(10,18);
    cout<<"enter new designation----->  ";
    cin>>emp[i].designation;
}

void editexp(int i)
{
    gotoXY(10,18);
    cout<<"Enter new Years of Experience";
    cin>>emp[i].exp;
}
void editage(int i)
{
    gotoXY(10,18);
    cout<<"Enter new Age ";
    cin>>emp[i].age;
}

void editsalary(int i)
{
    int sal,PF,TAX,HRA,MealA,MedicalA,TransportA,LoanBal=emp[i].LoanBalance,LoanDeb,DA;
    char loan;
    gotoXY(10,18);
    cout<<"Enter new Salary ";
    cin>>sal;
    DA = 1.20 * sal;    
    TAX =  0.04 * sal;
    PF = 0.12 * sal;
    HRA = 4000;
    MealA = 300;
    MedicalA = 300;
    TransportA = 300;
    LoanDeb = sal * 0.09;
    if(LoanDeb > LoanBal)
    {
        LoanBal = 0;
        LoanDeb = LoanBal;
    }
    emp[i].salary = sal;
    emp[i].tax=TAX;
    emp[i].PF = PF;
    emp[i].HRA = HRA;
    emp[i].MealAllowance = MealA;
    emp[i].MedicalAllowance = MedicalA;
    emp[i].TransportAllowance = TransportA;
    emp[i].LoanBalance = LoanBal;
    emp[i].AnyLoan = loan;
    emp[i].LoanDebit = LoanDeb;
    emp[i].grosspay = (sal+MealA+MedicalA+TransportA+HRA+DA)-(PF+TAX+LoanDeb) ;
}

void edit()
{
    //system("cls");
    borderNoDelay();
    int jobcode;
    gotoXY(28,4);
    printf("Edit a Record");
    int i;
    char option;
    gotoXY(10,6);
    cout<<"Enter the jobcode To Edit : ";
    cin>>jobcode;
    editmenu();
    for(i=0;i<=num-1;i++)
    {
        if(emp[i].code==jobcode)
        {
            while((option=cin.get())!='q')
            {
                switch(option)
                {
                    case 'f':
                        editfname(i);
                        break;
                    case 'l':
                    	editlname(i);
                    	break;
                    case 'c':
                        editcode(i);
                        break;
                    case 'd':
                        editdes(i);
                        break;
                    case 'e':
                        editexp(i);
                        break;
                    case 'a':
                        editage(i);
                        break;
                    case 's':
                        editsalary(i);
                        break;
                }
                   editmenu();
            }
        }
    }
}


void displayPayslip()
{
    system("cls");
    borderNoDelay();
    gotoXY(10,4);
    int code,i;
    cout<<"Enter Employee Job Code :";
    cin>>code;
    for(i=0;i<=num-1;i++)
    {
        if(emp[i].code==code)
        {
            gotoXY(12,6);
            cout<<"Name : "<<emp[i].fname <<emp[i].lname;
            gotoXY(45,6);
            cout<<"Working Hours : "<<emp[i].workingHours<<" Hrs";
            gotoXY(6,8);
            cout<<"Earnings :-";
            gotoXY(8,10);
            cout<<"Basic Pay : "<<emp[i].salary<<endl;
            gotoXY(8,12);
            cout<<"HRA(27% of Basic): "<<emp[i].HRA<<endl;
            gotoXY(8,14);
            cout<<"DA (120% of Basic):"<<emp[i].DA;
            gotoXY(8,16);
            cout<<"Meal Allowance : "<<emp[i].MealAllowance<<endl;
            gotoXY(8,18);
            cout<<"Medical Alowance : "<<emp[i].MedicalAllowance<<endl;
            gotoXY(8,20);
            cout<<"Transport Allowance : "<<emp[i].TransportAllowance<<endl;
            gotoXY(40,8);
            cout<<"Deductions :- "<<endl<<endl;
            gotoXY(42,10);
            cout<<"PF : "<<emp[i].PF<<endl;
            gotoXY(42,12);
            cout<<"Tax : "<<emp[i].tax<<endl;
            gotoXY(42,14);
            int l = emp[i].AnyLoan;
            char l2 = toupper(l);
            cout<<"Loan Status : "<<l2<<endl;
            gotoXY(42,16);
            cout<<"Loan Debit This Month : "<<emp[i].LoanDebit<<endl;
            gotoXY(42,18);
            cout<<"Loan Balance : "<<emp[i].LoanBalance<<endl;
            gotoXY(32,22);
            cout<<"Total Gross Pay : "<<emp[i].grosspay;
        }
    }
    getch();
}





int main()
{
    setWindowSize();    
    border();
    intro();
    loading();    
    loginFrame();
    login();
    menu();
    getrecords();
    char option;
    if(emp[0].code==0 && isFilePresent())
        num--;
    while(1)
    {
        option=getch();
        switch(option)
        {
            case 'l':
                list();
                break;
            case 'i':
                insert();
                break;
            case 'd':
                deletes();
                break;
            case 'e':
                edit();
                break;
            case 's':
                search();
                break;
            case 'p':
                displayPayslip();
                break;
            case 'q':
                saverecords();
                exit(0);
        }
        menu();
    }
    
    
    return 0;
}
