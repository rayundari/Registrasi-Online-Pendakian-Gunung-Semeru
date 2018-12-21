/*Program ini dibuat oleh Kelompok 4
Judul : Registrasi Online Pendakian Gunung Semeru
-Ahmad Mufin Rosyadi 1706104483
-Rahayu Windasari 1706104584 */
	
#include<stdio.h>
#include<conio.h>
#include<ctype.h>
#include<windows.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>

void add(); 
void list();
void edit(); 
void delete1();
void search();


char ok[20];

struct node {
   char data[20];
   struct node *next;
};

struct node *head = NULL;

//display the list
void printList() {
   struct node *ptr = head;
   printf("\n[head] =>");
   while(ptr != NULL) {        
      printf(" %s =>",ptr->data);
      ptr = ptr->next;
   }
   printf(" [null]\n");
}

//insert link at the first location
void insert(char data[20]) {
   struct node *link = (struct node*) malloc(sizeof(struct node));
   strcpy(link->data, data);
   link->next = head;
   head = link;
}



void setcolor(int ForgC)
{ WORD wColor;
HANDLE hStdOut=GetStdHandle(STD_OUTPUT_HANDLE);
CONSOLE_SCREEN_BUFFER_INFO csbi;

if(GetConsoleScreenBufferInfo(hStdOut,&csbi))
{
	wColor=(csbi.wAttributes & 0xB0)+(ForgC & 0x0B);
//	SetConsoleTextAttributes(hStdOut,wColor);
	SetConsoleTextAttribute(hStdOut,wColor);
	
}
}

void login()
{
	
	int a=0,i=0;
    char uname[10],c=' '; 
    char pword[10],code[10];
    char user[10]="user";
    char pass[10]="pass";
    do
{
	system("cls");
	
    printf("\n  **************************  LOGIN FORM  **************************  ");
    printf(" \n\n                       ENTER USERNAME:");
	scanf("%s", &uname); 
	printf(" \n                       ENTER PASSWORD:");
	while(i<10)
	{
	    pword[i]=getch();
	    c=pword[i];
	    if(c==13) break;
	    else printf("*");
	    i++;
	}
	pword[i]='\0';
	//char code=pword;
	i=0;
	//scanf("%s",&pword); 
		if(strcmp(uname,user)==0 && strcmp(pword,pass)==0)
	{
	printf("  \n\n\n       WELCOME !!!! LOGIN IS SUCCESSFUL");
	
	break;
	}
	else
	{
		printf("\n        SORRY !!!!  LOGIN IS UNSUCCESSFUL");
		a++;
		
		getch();
		
	}
}
	while(a<=2);
	if (a>2)
	{
		printf("\nSorry you have entered the wrong username and password for four times!!!");
		
		getch();
		
		}
		system("cls");	
}

struct CustomerDetails   //STRUCTURE DECLARATION 
{
	int a;
	char nom[10];
	char name[20];
	char address[25];
	char phonenumber[15];
	char nationality[15];	
	char email[20];
	char period[10];
	char arrivaldate[10];
}s;

int main(){     // MAIN FUNCTION	
	int i=0;
	
	time_t t;
	time(&t);
	char customername;
	char choice;

	system("cls");   // FOR CLEARING SCREEN
	setcolor(10);
 	printf("\t\t******************************************************************\n");
	printf("\t\t*                                               		 *\n");
	printf("\t\t*      -------------------------------------------------         *\n");
	printf("\t\t*      SELAMAT DATANG DI REGISTRASI ONLINE GUNUNG SEMERU         *\n");
	printf("\t\t*      -------------------------------------------------         *\n");
	printf("\t\t*                                               		 *\n");
	printf("\t\t*                                               		 *\n");
	printf("\t\t*                                               		 *\n");
	printf("\t\t******************************************************************\n\n\n");
		for(i=0;i<80;i++)
		printf("-");
	    printf("\nCurrent date and time : %s",ctime(&t));
	    for(i=0;i<80;i++)
		printf("-");
	printf(" \n Press any key to continue:");
	
	getch();	
    system("cls");
    login();
    system("cls");
    
	while (1)      // INFINITE LOOP
	{
		system("cls");
		setcolor(15);
		 for(i=0;i<80;i++)
		printf("-");
		printf("\n");
		printf("   ******************************  |MAIN MENU|  ***************************** \n");
		for(i=0;i<80;i++)
		printf("-");
		printf("\n");
		setcolor(7);
		printf("\t\t *Please enter your choice for menu*:");
		printf("\n\n");
		printf(" \n Enter 1 -> Book For Hiking");
		printf("\n----------------------------------");
		printf(" \n Enter 2 -> View Record");
		printf("\n----------------------------------");
		printf(" \n Enter 3 -> Delete Record");
		printf("\n----------------------------------");
		printf(" \n Enter 4 -> Search Record");
		printf("\n----------------------------------");
		printf(" \n Enter 5 -> Edit Record");
		printf("\n----------------------------------");
		printf(" \n Enter 6 -> Exit");
		printf("\n----------------------------------");
		printf("\n");
		for(i=0;i<80;i++)
		printf("-");
	    printf("\nCurrent date and time : %s",ctime(&t));
	    for(i=0;i<80;i++)
		printf("-");
		
		choice=getche();
		choice=toupper(choice);
		switch(choice)           // SWITCH STATEMENT
		{	
			case '1':
				add();
				break;
			case '2':
				list();break;
			case '3':
				delete1();break;
			case '4':
				search();break;
			case '5':
				edit();break;
			case '6':
				system("cls");
				printf("\n\n\t *****THANK YOU*****");
				printf("\n\t FOR TRUSTING OUR SERVICE");
				
				printf("\n\n %s\n", s.name);
				printList();
				
			//	Sleep(2000);
				getch();
				exit(0);
				break;
			default:
				system("cls");
				printf("Incorrect Input");
				printf("\n Press any key to continue");
				getch();
		}
	}
}


void add()
{
	
	FILE *f;
	char test;
	f=fopen("add.txt","a+");
	if(f==0)
	{   f=fopen("add.txt","w+");
		system("cls");
		printf("Please hold on while we set our database in your computer!!");
		printf("\n Process completed press any key to continue!! ");
		getch();
	}
	while(1)
	{
		system("cls");
		if(s.a>=3){
			printf("\n\n Booking full!! (maximum 50 persons)");
			getch();
			break;
		}else if(s.a<=3){
		printf("\n Enter Customer Details:");
		printf("\n**************************");
		printf("\n Enter Number ID:\n");
		scanf("\n%s",s.nom);
		fflush(stdin);
		printf("Enter Name:\n");
		scanf("%s",s.name);
		
		strcpy(ok, s.name);
		printf("\n\n %s\n", ok);
		insert(ok);
		
		printf("Enter Address:\n");
		scanf("%s",s.address);
		printf("Enter Phone Number:\n");
		scanf("%s",s.phonenumber);
		printf("Enter Nationality:\n");
		scanf("%s",s.nationality);
		printf("Enter Email:\n");
		scanf(" %s",s.email);
		printf("Enter Period(\'x\'days):\n");
		scanf("%s",&s.period);
		printf("Enter Arrival date(dd\\mm\\yyyy):\n");
		scanf("%s",&s.arrivaldate);
		fwrite(&s,sizeof(s),1,f);
		fflush(stdin);
		s.a++;
		printf("\n\n Successfully booked!!");
		}
		printf("\n Press esc key to exit,  any other key to add another customer detail:");
		test=getche();
		
		if(test==27)
			break;
			
	}
	fclose(f);
}

void list()
{
	FILE *f;
	int i;
	if((f=fopen("add.txt","r"))==NULL)
		exit(0);
	system("cls");
	printf("NO ID    ");
	printf("NAME\t ");
	printf("\tADDRESS ");
	printf("\tPHONENUMBER ");
	printf("\tNATIONALITY ");
	printf("\tEMAIL ");
	printf("\t\t\t PERIOD ");
	printf("\t ARRIVALDATE \n");
	
	for(i=0;i<118;i++)
		printf("-");
	while(fread(&s,sizeof(s),1,f)==1)
	{
		printf("\n%s \t%s \t\t%s \t\t%s \t%s  \t%s  \t     %s  \t  %s",s.nom, s.name , s.address , s.phonenumber ,s.nationality ,s.email,s.period,  s.arrivaldate);
	}
	printf("\n");
	for(i=0;i<118;i++)
		printf("-");

	fclose(f);
	getch();
}

void delete1()
{
	FILE *f,*t;
	int i=1;
	char nom[20];
	if((t=fopen("temp.txt","w"))==NULL)
	exit(0);
	if((f=fopen("add.txt","r"))==NULL)
	exit(0);
	system("cls");
	printf("Enter the Number ID to be deleted from the database: \n");
	fflush(stdin);
	scanf("%s",nom);
	while(fread(&s,sizeof(s),1,f)==1)
	{
		if(strcmp(s.nom,nom)==0)
		{       i=0;
			continue;
		}
		else
			fwrite(&s,sizeof(s),1,t);
	}
	if(i==1)
	{       
		printf("\n\n Records of Customer in this  Number Of Member is not found!!");
		//remove("E:/file.txt");
	   //rename("E:/temp.txt","E:/file.txt");
		getch();
		fclose(f);
		fclose(t);
		main();
	}
	fclose(f);
	fclose(t);
	remove("add.txt");
	rename("temp.txt","add.txt");
	printf("\n\nThe Customer is successfully removed....");
	fclose(f);
	fclose(t);
	getch();
}

void search()
{
system("cls");
	FILE *f;
	char nom[20];
	int flag=1;
	f=fopen("add.txt","r+");
	if(f==0)
		exit(0);
	fflush(stdin);
	printf("Enter Number ID of the customer to search its details: \n");
	scanf("%s", nom);
	while(fread(&s,sizeof(s),1,f)==1)
	{
		if(strcmp(s.nom,nom)==0){
			flag=0;
			printf("\n\tRecord Found\n ");
			printf("\nNumber ID:\t%s",s.nom);
			printf("\nName:\t%s",s.name);
			printf("\nAddress:\t%s",s.address);
			printf("\nPhone number:\t%s",s.phonenumber);
			printf("\nNationality:\t%s",s.nationality);
			printf("\nEmail:\t%s",s.email);
			printf("\nPeriod:\t%s",s.period);
			printf("\nArrival date:\t%s",s.arrivaldate);
			flag=0;
			break;
		}
	}
	if(flag==1){	
		printf("\n\tRequested Customer could not be found!");
	}
	getch();
	fclose(f);
}

void edit()
{
	FILE *f;
	int k=1;
	char nom[20];
	long int size=sizeof(s);
	if((f=fopen("add.txt","r+"))==NULL)
		exit(0);
	system("cls");
	printf("Enter Number ID of the customer to edit:\n\n");
	scanf("%[^\n]",nom);
	fflush(stdin);
	while(fread(&s,sizeof(s),1,f)==1)
	{
		if(strcmp(s.nom,nom)==0)
		{
			k=0;
			printf("\nEnter Number ID     :");
			gets(s.nom);
			printf("\nEnter Name    :");
			fflush(stdin);
			scanf("%s",&s.name);
			printf("\nEnter Address        :");
			scanf("%s",&s.address);
			printf("\nEnter Phone number :");
			scanf("%f",&s.phonenumber);
			printf("\nEnter Nationality :");
			scanf("%s",&s.nationality);
			printf("\nEnter Email :");
			scanf("%s",&s.email);
			printf("\nEnter Period :");
			scanf("%s",&s.period);
			printf("\nEnter Arrival date :");
			scanf("%s",&s.arrivaldate);
			fseek(f,size,SEEK_CUR);  //to go to desired position infile
			fwrite(&s,sizeof(s),1,f);
			break;
		}
	}
	if(k==1){
		printf("\n\nTHE RECORD DOESN'T EXIST!!!!");
		fclose(f);
		getch();
	}else{
	fclose(f);
	printf("\n\n\t\tYOUR RECORD IS SUCCESSFULLY EDITED!!!");
	getch();
}
}
