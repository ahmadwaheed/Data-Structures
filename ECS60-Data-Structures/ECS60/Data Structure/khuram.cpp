
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#include<dos.h>
#include<graphics.h>

FILE *fp,*ft;
char opt,choice,another='Y',roll[20];
long int size;
int count;

struct student
{
 char roll[20],name[25],fname[25],add[30],sec;
 int age;
 char gpa;
};

 struct student std;
 char students[20];

 void start();
 void count_down()
 {
  int gd = DETECT, gm, q;
  char a[5];

  initgraph( &gd, &gm, "C:\\TC\\BGI");

 settextjustify(CENTER_TEXT,CENTER_TEXT);
 settextstyle(DEFAULT_FONT,HORIZ_DIR,3);
 setcolor(RED);

 for(q =11;q>=0;q--)
 {
  sprintf(a,"%d",q);
  outtextxy(getmaxx()/2, getmaxy()/2, a);
  delay(1000);

 if (q == 0)
 break;
 cleardevice();
 }
}

void graphics();
void massage(char *);
void graphics2()
{
 int gd = DETECT, gm;

 initgraph(&gd, &gm,"C:\\TC\\BGI");
 outtextxy(10,10,"thank you for visiting");

 outtextxy(10,20, "MOHAMMAD KHURAM");
 outtextxy(20,40, "MOHAMMAD TALHA");
 outtextxy(30,60, "MOHAMMAD BILAL");

 setcolor(BLUE);
 getch();
 closegraph( );
}

void main()
{
 
 size=sizeof(std);  // Size of student structure 

 fp=fopen("STUDENT.txt","rb+");
 if(fp == NULL)
 {
  fp=fopen("STUDENT.txt","wb+");
  if(fp == NULL)
  {
   printf("Can't Open File.....");
   exit(1);
   }
  }
 count_down();
 start();
 graphics();

do
{
 clrscr();
 massage(&choice);
 switch(choice)
 {
  case '1':
  while(another=='Y' || another == 'y')
  {
   clrscr();
   do
   {
    count=0;
    printf("\n\n\tEnter Student's Roll Number:  ");
    fflush(stdin);
    gets(roll);
    rewind(fp);
    while(fread(&std,size,1,fp) == 1)
    {
     if(strcmp(roll,std.roll) == 0)
	 {
	   printf("\n\tThis Student Exists... Plz Enter New:  ");
	   count=1;
	 }
    }
   }
  while(count==1);
  fflush(stdin);
  strcpy(std.roll,roll);
  printf("\tEnter Student's Name: ");
  fflush(stdin);
  gets(std.name);
  printf("\tEnter Student's Father Name: ");
  fflush(stdin);
  gets(std.fname);
  printf("\tEnter Student's Address: ");
  fflush(stdin);
  gets(std.add);
  printf("\tEnter Student's Section: ");
  scanf("%c", &std.sec);
  fflush(stdin);
  printf("\tEnter Student's Age: ");
  scanf("%d", &std.age);
  fflush(stdin);

  fseek(fp,0,SEEK_END);
  fwrite(&std,size,1,fp);

  fflush(stdin);
  printf("\n\n\tWanna Add Another Record(Y/N):  ");
  another=getche();
 }
break; // case '1' terminated
 case '2':
 do
 {
  clrscr();
  rewind(fp);
  printf("\n\tEnter Student's Roll Number:  ");
  fflush(stdin);
  gets(roll);
  while(fread(&std,size,1,fp) == 1)
  {
   if(strcmp(std.roll,roll) == 0)
   {
    printf("\n\n\n\tStudent's Roll Number:\t%s",std.roll);
    printf("\n\tStudent's Name       :\t%s",std.name);
    printf("\n\tStudent's Father Name:\t%s",std.fname);
    printf("\n\tStudent's Address    :\t%s",std.add);
    printf("\n\tStudent's Section    :\t%c",std.sec);
    printf("\n\tStudent's Age        :\t%d",std.age);
   // delay(1000);
   }
  }

  printf("\n\n\t\tWanna See Another Record (Y/N):  ");
  another=getche();
 }
  while(another == 'Y' || another == 'y');
  break; // case '2' Terminated
  case '3':
  another='y';
  while(another=='y'||another=='Y')
  {
   printf("\n\tenter roll tomodify record ");
   scanf("%s",students);
   rewind(fp);
   while(fread(&std,size,1,fp)==1)
   {
    if(strcmp(std.roll,students)==0)
    {
     printf("\n\tenter new roll\n\t,name\n\t,father name\n\t,address\n\t,section\n\t,age\n");
     scanf("%s%s%s%s%d%c",std.roll,std.name,std.fname,std.add,std.sec,std.age);
     fseek(fp,-size,SEEK_CUR);
     fwrite(&std,size,1,fp);
break;
    }
   }
  printf("\n\tmodify another record(y/n)");
  fflush(stdin);
  another=getche();
  }
break;
// case '3' terminated
case '4':
another='y';
while(another=='y'||another=='Y')
{
printf("enter roll of student to delete");
scanf("%s",students);
ft=fopen("TEMP.txt","wb");
rewind(fp);
while(fread(&std,size,1,fp)==1)
{
if(strcmp(std.roll,students)!=0)
fwrite(&std,size,1,ft);
}
fclose(fp);
fclose(ft);
remove("STUDENT.txt");
rename("TEMP.txt","STUDENT.txt");
fp=fopen("STUDENT.txt","rb+");
printf("delete another record(y/n)");
fflush(stdin);
another=getche();
}
break;
//case '4' terminated
case '5':
do
{
clrscr();
rewind(fp);
printf("\n\tEnter Student's name:  ");
fflush(stdin);
gets(roll);
while(fread(&std,size,1,fp) == 1)
  {
	 if(strcmp(std.name,roll) == 0)
	    {

    printf("\n\n\n\tStudent's Roll Number:\t%s",std.roll);
    printf("\n\tStudent's Name       :\t%s",std.name);
    printf("\n\tStudent's Father Name:\t%s",std.fname);
    printf("\n\tStudent's Address    :\t%s",std.add);
    printf("\n\tStudent's Section    :\t%c",std.sec);

    //printf("\n\tStudent's GPA        :\t%f",std.gpa);
    printf("\n\tStudent's Age        :\t%d",std.age);
   // delay(1000);
	   }

   }

printf("\n\n\t\tWanna See Another Record (Y/N):  ");
another=getche();
}while(another == 'Y' || another == 'y');


break; // case '5' Terminated
case '6':
do
{
clrscr();
rewind(fp);
printf("\n\tEnter Student's adderss:  ");
fflush(stdin);
gets(roll);
while(fread(&std,size,1,fp) == 1)
  {
	 if(strcmp(std.add,roll) == 0)
	    {

    printf("\n\n\n\tStudent's Roll Number:\t%s",std.roll);
    printf("\n\tStudent's Name       :\t%s",std.name);
    printf("\n\tStudent's Father Name:\t%s",std.fname);
    printf("\n\tStudent's Address    :\t%s",std.add);
    printf("\n\tStudent's Section    :\t%c",std.sec);

    //printf("\n\tStudent's GPA        :\t%f",std.gpa);
    printf("\n\tStudent's Age        :\t%d",std.age);
   // delay(1000);
	   }

   }

printf("\n\n\t\tWanna See Another Record (Y/N):  ");
another=getche();
}while(another == 'Y' || another == 'y');


break; // case '6' Terminated

case '7':
another='y';
while(another=='y'||another=='Y')
{
printf("\n\tenter roll tomodify record ");
scanf("%s",students);
rewind(fp);
while(fread(&std,size,1,fp)==1)
{
 if(strcmp(std.roll,students)==0)
{
printf("\n\tname\n\t");
scanf("%s",std.name);
fseek(fp,-size,SEEK_CUR);
fwrite(&std,size,1,fp);
break;
}
}
printf("\n\tmodify another record(y/n)");
fflush(stdin);
another=getche();
}
break;
// case '7' terminated
case '8':
another='y';
while(another=='y'||another=='Y')
{
printf("\n\tenter roll tomodify record ");
scanf("%s",students);
rewind(fp);
while(fread(&std,size,1,fp)==1)
{
 if(strcmp(std.roll,students)==0)
{
printf("\n\tenter new roll\n\t");
scanf("%s",std.roll);
fseek(fp,-size,SEEK_CUR);
fwrite(&std,size,1,fp);
break;
}
}
printf("\n\tmodify another record(y/n)");
fflush(stdin);
another=getche();
}
break;
// case '8' terminated

case '9':
clrscr();
rewind(fp);
fp=fopen("STUDENT.txt","r");
while(fread(&std,size,1,fp)==1)
{
    printf("\n\n\n\tStudent's Roll Number:\t%s",std.roll);
    printf("\n\tStudent's Name       :\t%s",std.name);
    printf("\n\tStudent's Father Name:\t%s",std.fname);
    printf("\n\tStudent's Address    :\t%s",std.add);
    printf("\n\tStudent's Section    :\t%c",std.sec);

    //printf("\n\tStudent's GPA        :\t%f",std.gpa);
    printf("\n\tStudent's Age        :\t%d",std.age);
   // delay(1000);


}
break;  //case '9' terminated
case '0':
fclose(fp);
graphics2();
exit(0);
}
	   //switch termination
fflush(stdin);
printf("\n\n\t\tWanna Goto Main MENU....(Y/N) ");
opt=getche();

}while(opt =='Y' || opt =='y');
fclose(fp);

getch();
}
	   //main termination


void massage(char *choice)
{

char ch;

gotoxy(30,10);
printf("Your Menu");
gotoxy(25,2);
printf("1. Add RECORD OF A NEW STUDENT");
gotoxy(25,4);
printf("2. View STUDENT'S RECORD");
gotoxy(25,6);
printf("3. Modify the record of student all");
gotoxy(25,8);
printf("4. Delete record if student");
gotoxy(25,10);
printf("5. view by name");
gotoxy(25,12);
printf("6. veiw by address");
gotoxy(25,14);
printf("7.to modify name only");
gotoxy(25,16);
printf("8.to modify roll number");
gotoxy(25,18);
printf("9.view all records");
gotoxy(25,20);
printf("0. Exit");
gotoxy(15,24);
printf("Plz Enter YOur Choice:  ");
scanf("%c", &ch);
*choice=ch;
}
void graphics()
{


    int gd = DETECT, gm;

    initgraph(&gd, &gm,"C:\\TC\\BGI");
    outtextxy(10,10, "WELCOME");
    outtextxy(10,20,"in univrsity database");
    outtextxy(30,40, "MOHAMMAD KHURAM");
    outtextxy(40,60, "MOHAMMAD TALHA");
    outtextxy(50,80, "MOHAMMAD BILAL");


    setcolor(BLUE);



    getch();
    closegraph( );

    }
void start()
{
   int x, y = 0,gd = DETECT, gm;

   initgraph(&gd,&gm,"C:\\TC\\BGI");

   settextstyle(DEFAULT_FONT,HORIZ_DIR,2);



   setviewport(0,0,639,440,1);

   for( x = 0 ; x <= 420 ; x = x + 10, y++ )
   {   outtextxy(25,240,"LOADING");
      rectangle(50+x,275,150+x,400);
      rectangle(150+x,350,200+x,400);
      circle(75+x,410,10);
      circle(175+x,410,10);
      setcolor(y);
      delay(100);

      if( x == 420 )
	 break;

      clearviewport();

   }
   }





