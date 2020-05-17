#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
void student();
void admin();
void menu();
void editcls();
void editteach();
void editbus();
void editclg();
void delcls();
void delteach();
void delbus();
void delclg();
 void searchcls();
 void searchbus();
 void searchteach();
 void searchclg();
 void addteach();
 void addclg();
 void addbus();
 void addcls();
 void cse();
 void me();
 void civil();
 void ece();
 void searchcse();
 void searchece();
 void searchciv();
 void searchme();
 void editcse();
 void editme();
 void editciv();
 void editece();
 void delcse();
 void delece();
 void delme();
 void delciv();
 struct  //declaring the structure for bus schedule
 {
 char num[10];
 char time[10];
 char stop[20];
 }b;
 struct//declaring the structure for teacher information
 {
 char id[10];
 char name[20];
 char dept[10];
 char desg[15];
 char sub[15];
 }t;
 typedef struct  //structure for the class schedule
{
char id[10];
char day[10];
char course[10];
char sem[5];
char stream[10];
char one[10];
char two[10];
char three[10];
char four[10];
char five [10];
char six[10];

} cls;
cls c,c1,c2,c3;
char info[1000];
int isFound=0;
char ex,n,stre[20],course[10],user[20],pass[10],id[10],cw;
int main()
{
      menu();
      getch();
      return 0;
}

void menu()   //function for main menu
    {
    clrscr();
    gotoxy(20,10);
    printf("welcome to clginfo(college informationsystem)\n");
    gotoxy(20,11);
    printf("a.student\n");
    gotoxy(20,12);
    printf("b.admin\n");
    gotoxy(20,13);
    printf ("enter any one option\n");
    n=getch();
    switch(n){
    case'a':student();
    break;
    case'b':admin();
    break;
}
getch();
}

void student() //function for the student module
    {
    clrscr();
    gotoxy(10,10);
    printf("welocme to the student setion\n\n");
    gotoxy(10,11);
    printf("a.class schedule\n");
    gotoxy(10,12);
    printf("b.bus schedule\n");
    gotoxy(10,13);
    printf("c.teacher information\n");
    gotoxy(10,14);
    printf("d.college information\n");
    gotoxy(10,15);
    printf("enter one option:");
    n=getch();
    switch(n)
    {
    case'a':searchcls();
    break;
    case'b':searchbus();
    break;
    case'c':searchteach();
    break;
    case'd':searchclg();
    break;
    default:
    printf("wrong choice");
    break;
    }
     getch();
    }

void searchteach()
{
 char subj[15],another;
    FILE *fr;
fr=fopen("teach.txt","rb");
clrscr();
printf("************************ search teacher information");
 printf("enter subject");
 fflush(stdin);
 scanf("%s",&subj);
while(fread(&t,sizeof(t),1,fr)==1)
{
if(strcmp(t.sub,subj)==0)
{
  isFound=1;
  break;
}
}
 if(isFound==1)
{
 printf(" teacher id:%s\n",t.id);
printf("enter the name:%s\n",t.name );
printf("subject:%s\n",t.sub);
printf("department:%s\n",t.dept);
printf(" designation:%s\n",t.desg);


}
else
{
printf("record not found");
sleep(10);
searchcls();
}
fclose(fr);
getch();
 }



 void admin()   //function for the admin module to add ,update,search and delete records
    {
    int choice,op;
    clrscr();
    printf("enter username:\n");
    scanf("%s",&user);
    printf("enter password:\n");
    scanf("%s",&pass);
    if(strcmp(user,"admincoinfo")==0&&strcmp(pass,"pass")==0)
    {
    clrscr();
    printf("login successfull\n");
    gotoxy(10,5);
    printf("welcome to the admin section\n");
    gotoxy(10,6);
    printf("1.add information\n");
    gotoxy(10,7);
    printf("2.search information\n");
    gotoxy(10,8);
    printf("3.edit information\n");
    gotoxy(10,9);
    printf("4.delete information\n");
    gotoxy(10,10);
    printf("enter your option:");
    scanf("%d",&choice);
    switch(choice)
    {
    case 1:
    clrscr();
    gotoxy(10,5);
    printf("**********add information***********\n");
    gotoxy(10,6);
    printf("1.add class schedule\n");
    gotoxy(10,7);
    printf("2.add bus schedule\n");
    gotoxy(10,8);
    printf("3.add teacher information\n");
    gotoxy(10,9);

    printf("4.add college information\n");
    gotoxy(10,10);
    printf("enter any one option:");
    scanf("%d",&op);
    switch(op)
    {
    case 1: addcls();
    break;
    case 2:addbus();
    break;
    case 3:addteach();
    break;
    case 4:addclg();
    break;
    default:
    printf("wrong choice");
    break;
	  }
    case 2:
    clrscr();
    printf("**********search information***********\n");
    printf("\t1.search class schedule\n");
    printf("\t2.search bus schedule\n");
    printf("\t3.search teacher information\n");
    printf("\t4.search college information\n");
    printf("\tenter one option\n");
    scanf("%d",&op);
    switch(op)
    {
    case 1: searchcls();
    break;
    case 2:searchbus();
    break;
    case 3:searchteach();
    break;
    case 4:searchclg();
    break;
    default:
    printf("wrong choice");
    break;
}
case 3:
    clrscr();
    printf("**********edit information***********\n");
    printf("1.edit class schedule\n");
    printf("2.edit  bus schedule\n");
    printf("3.edit teacher information\n");
    printf("enter one option:\n");
    scanf("%d",&op);
    switch(op)
    {
    case 1: editcls();
    break;
    case 2:editbus();
    break;
    case 3:editteach();
    break;
    default:
    printf("wrong choice");
    break;
}
case 4:
    clrscr();
    printf("**********delete information***********\n");
    printf("1.delete class schedule\n");
    printf("2.delete  bus schedule\n");
    printf("3.delete teacher information\n");
    printf("4.delete college information\n");
    printf("enter one option\n");
    scanf("%d",&op);
    switch(op)
    {
    case 1: delcls();
    break;
    case 2:delbus();
    break;
    case 3:delteach();
    break;
    case 4:delclg();
    break;
    default:
    printf("wrong choice");
    break;
}
}
}
    else
{
    printf("password or username is incorrect\n");
    printf("DO YOU WANT TO CONTINUE(Y/N)\n");
    scanf("%s",&cw);

    if(cw=='y'||cw=='Y')
    {
    sleep(10);
    admin();
    }
    else
    {
    sleep(10);
    exit(1);
    }
}
getch();
}
void addcls()   //function to add class schedule
{
clrscr();
printf("enter the course of the schedule you want to add:\n");
scanf("%s",&course);
printf("enter cse for computer science\n");
printf("enter me for mechanical engneering\n");
printf("enter ece for electronics and communication engineering\n");
printf("enter ce for civil engineering\n");
printf("type the stream of your course:\n");
scanf("%s",&stre);
if(strcmp(stre,"cse")==0&&strcmp(course,"b.tech")==0)
{
cse();
   }
else if(strcmp(stre,"me")==0&&strcmp(course,"b.tech")==0)
{
me();
}
else if(strcmp(stre,"ce")==0&&strcmp(course,"b.tech")==0)
{
civil();
}
else if(strcmp(stre,"ece")==0&&strcmp(course,"b.tech")==0)
{
ece();
}
else

{
printf("wrong choice");
}
getch();
}
    void cse()
{

    FILE *fp;
    fp=fopen("csse.txt","ab+");
    fseek(fp,0,SEEK_END);
   if(fp==NULL)
{
  puts("cannot open file");
  exit(1);
}
    else
{
printf("enter class id\r\n");
scanf("%s",&c.id);
printf("enter day:\r\n");
scanf("%s",&c.day);
printf("enter cours:\r\n");
scanf("%s",&c.course);
printf("enter sem :\r\n");
scanf("%s",&c.sem);
printf("enter stream\r\n");
scanf("%s",&c.stream);
printf("enter first lecture:\r\n");
scanf("\n%s[^\n]",&c.one);
printf("enter second lecture:\r\n");
scanf("\n%s[^\n]",&c.two);
printf("enter thir lecture:\r\n");
scanf("\n%s[^\n]",&c.three);
printf("enter fourth lecture:\r\n");
scanf("\n%s[^\n]",&c.four);
printf("enter fifth lecture:\r\n");
scanf ("\n%s[^\n]",&c.five);
printf("enter sixth lecture:\r\n");
scanf("\n%s[^\n]",&c.six);
fwrite(&c,sizeof(c),1,fp);
fflush(stdin);
printf("recorded successfully");
printf("press ESC to exit");
ex=getch();
if(ex==27)
{
exit(1);
}
}
 fclose(fp);
 getch();
}

void me()
{
	    FILE *fptr;
    fptr=fopen("me.txt","ab+");
   if(fptr==NULL)
{
  puts("cannot open file");
  exit(1);
}
    else
{
printf("enter class id\r\n");
scanf("%s",&c1.id);
fseek(fptr,50,SEEK_CUR);
printf("enter day:\r\n");
scanf("%s",&c1.day);
fseek(fptr,50,SEEK_CUR);
printf("enter cours:\r\n");
scanf("%s",&c1.course);
fseek(fptr,50,SEEK_CUR);
printf("enter sem :\r\n");
scanf("%s",&c1.sem);
fseek(fptr,50,SEEK_CUR);
printf("enter stream\r\n");
scanf("%s",&c1.stream);
fseek(fptr,50,SEEK_CUR);
printf("enter first lecture:\r\n");
scanf("\n%s[^\n]",&c1.one);
fseek(fptr,50,SEEK_CUR);
printf("enter second lecture:\r\n");
scanf("\n%s[^\n]",&c1.two);
fseek(fptr,50,SEEK_CUR);
printf("enter thir lecture:\r\n");
scanf("\n%s[^\n]",&c1.three);
fseek(fptr,50,SEEK_CUR);
printf("enter fourth lecture:\r\n");
scanf("\n%s[^\n]",&c1.four);
fseek(fptr,50,SEEK_CUR);
printf("enter fifth lecture:\r\n");
scanf ("\n%s[^\n]",&c1.five);
fseek(fptr,50,SEEK_CUR);
printf("enter sixth lecture:\r\n");
scanf("\n%s[^\n]",&c1.six);
fwrite(&c1,sizeof(c1),1,fptr);
fflush(stdin);
printf("recorded successfully");
printf("press ESC to exit");
ex=getch();
if(ex==27)
{
exit(1);
}
}
 fclose(fptr);
 getch();

}
   void civil()
{
	    FILE *ft;
    ft=fopen("civil.txt","ab+");
   if(ft==NULL)
{
  puts("cannot open file");
  exit(1);
}
    else
{
printf("enter class id\r\n");
scanf("%s",&c2.id);
fseek(ft,50,SEEK_CUR);
printf("enter day:\r\n");
scanf("%s",&c2.day);
fseek(ft,50,SEEK_CUR);
printf("enter cours:\r\n");
scanf("%s",&c2.course);
fseek(ft,50,SEEK_CUR);
printf("enter sem :\r\n");
scanf("%s",&c2.sem);
fseek(ft,50,SEEK_CUR);
printf("enter stream\r\n");
scanf("%s",&c2.stream);
fseek(ft,50,SEEK_CUR);
printf("enter first lecture:\r\n");
scanf("\n%s[^\n]",&c2.one);
fseek(ft,50,SEEK_CUR);
printf("enter second lecture:\r\n");
scanf("\n%s[^\n]",&c2.two);
fseek(ft,50,SEEK_CUR);
printf("enter thir lecture:\r\n");
scanf("\n%s[^\n]",&c2.three);
fseek(ft,50,SEEK_CUR);
printf("enter fourth lecture:\r\n");
scanf("\n%s[^\n]",&c2.four);
fseek(ft,50,SEEK_CUR);
printf("enter fifth lecture:\r\n");
scanf ("\n%s[^\n]",&c2.five);
fseek(ft,50,SEEK_CUR);
printf("enter sixth lecture:\r\n");
scanf("\n%s[^\n]",&c2.six);
fwrite(&c2,sizeof(c2),1,ft);
fflush(stdin);
printf("record added");
printf("press ESC to exit");
ex=getch();
if(ex==27)
{
exit(1);
}
}
 fclose(ft);
 getch();

}
   void ece()
{
	    FILE *fe;
    fe=fopen("ece.txt","ab+");
   if(fe==NULL)
{
  puts("cannot open file");
  exit(1);
}
    else
{
printf("enter class id\r\n");
scanf("%s",&c3.id);
fseek(fe,50,SEEK_CUR);
printf("enter day:\r\n");
scanf("%s",&c3.day);
fseek(fe,50,SEEK_CUR);
printf("enter cours:\r\n");
scanf("%s",&c3.course);
fseek(fe,50,SEEK_CUR);
printf("enter sem :\r\n");
scanf("%s",&c3.sem);
fseek(fe,50,SEEK_CUR);
printf("enter stream\r\n");
scanf("%s",&c3.stream);
fseek(fe,50,SEEK_CUR);
printf("enter first lecture:\r\n");
scanf("\n%s[^\n]",&c3.one);
fseek(fe,50,SEEK_CUR);
printf("enter second lecture:\r\n");
scanf("\n%s[^\n]",&c3.two);
fseek(fe,50,SEEK_CUR);
printf("enter thir lecture:\r\n");
scanf("\n%s[^\n]",&c3.three);
fseek(fe,50,SEEK_CUR);
printf("enter fourth lecture:\r\n");
scanf("\n%s[^\n]",&c3.four);
fseek(fe,50,SEEK_CUR);
printf("enter fifth lecture:\r\n");
scanf ("\n%s[^\n]",&c3.five);
fseek(fe,50,SEEK_CUR);
printf("enter sixth lecture:\r\n");
scanf("\n%s[^\n]",&c3.six);
fwrite(&c3,sizeof(c3),1,fe);
fflush(stdin);
printf("recorded successfully");
printf("press ESC to exit");
ex=getch();
if(ex==27)
{
exit(1);
}
}
 fclose(fe);
 getch();

}
void addteach()
{
   FILE*fr;
   fr=fopen("teach.txt","ab+");
if(fr==NULL)
{
printf("file not found");
exit(1);
}
while(1)
{
printf("enter the teacher id:\n");
scanf("%s",&t.id);
printf("enter the name of teacher:\n ");
scanf("%s",&t.name);
printf("enter the subject teacher teaches");
scanf("%s",&t.sub);
printf("enter the departement of teacher:\n");
scanf("%s",&t.dept);
printf("enter the designation of teacher:\n");
scanf("%s",&t.desg);
fwrite(&t,sizeof(t),1,fr);
fflush(stdin);
printf("record added\n");
printf("press ESC to exit\n");
ex=getch();
if(ex==27)
{
exit(1);
}

  fclose(fr);
getch();
}
}
void searchcls()
   {
  int ch;
  clrscr();
  gotoxy(10,10);
   printf("1.CSE(Computer Science Engineering)\n");
   gotoxy(10,11);
   printf("2.ECE(Electronics And Communication Engineering)\n");
   gotoxy(10,12);
   printf("3.ME(Mechanical Engineering)\n");
   gotoxy(10,13);
   printf("4.CE(Civil Engineering)\n");
   gotoxy(10,14);
   printf("please select any one stream\n");
scanf("%d",&ch);
switch(ch)
{
case 1:
searchcse();
break;
case 2:
searchece();
break;
case 3:
searchme();
break;
case 4:
searchciv();
break;
default:
printf("wrong choice");
break;
}
}
  void searchcse()  //function for searching class schedule of cse branch
{

 char id[15],another;
    FILE *fp;
fp=fopen("csse.txt","rb");
clrscr();
 printf("enter id");
 fflush(stdin);
 scanf("%s",&id);
while(fread(&c,sizeof(c),1,fp)==1)
{
if(strcmp(c.id,id)==0)
{
  isFound=1;
  break;
}
}
 if(isFound==1)
{
clrscr();
gotoxy(20,7);
printf("*************class schedule****************\n");
printf("class id:%s\n",c.id);
printf(" day:%s\n",c.day);
printf(" course:%s\n",c.course);
printf("semster:%s\n",c.sem);
printf(" stream:%s\n",c.stream);
printf("first lecture(9:00 a.m.-10:00 a.m.):%s\n",c.one);
printf("second lecture(10:00 a.m.-11:00 a.m.):%s\n",c.two);
printf(" third lecture(11:00 a.m.-12:00 a.m.):%s\n",c.three);
printf("**********break*****************\n");
printf(" fourth lecture(1:00 p.m.-2:00 p.m.):%s\n",c.four);
printf(" fifth lecture(2:00 p.m.-3:00 p.m.):%s\n",c.five);
printf(" sixth lecture(3:00 p.m.-4:00 p.m.):%s\n",c.six);
fflush(stdin);

}

else
{
printf("record not found");
sleep(10);
searchcls();
}
printf("press ESC to exit");
ex=getch();
if(ex==27)
{
exit(1);
}


   fclose(fp);
getch();
 }


  void searchme()    //function for searching class schedule of me branch
{

  FILE *fptr;
fptr=fopen("me.txt","rb");
 printf("enter id");
 fflush(stdin);
 scanf("%s",&id);
if(fptr==NULL)
{
puts("file not fond");
exit(1);
}
rewind(fptr);
while(fread(&c1,sizeof(c1),1,fptr)==1)
{
if(strcmp(id,c1.id)==0)
{
isFound=1;
}
if(isFound==1)
{
clrscr();
gotoxy(10,10);
printf("*************class schedule****************\n");
printf("class id:%s\n",c1.id);
printf(" day:%s\n",c1.day);
printf(" course:%s\n",c1.course);
printf("semster:%s\n",c1.sem);
printf(" stream:%s\n",c1.stream);
printf("first lecture(9:00 a.m.-10:00 a.m.):%s\n",c1.one);
printf("second lecture(10:00 a.m.-11:00 a.m.):%s\n",c1.two);
printf(" third lecture(11:00 a.m.-12:00 a.m.):%s\n",c1.three);
printf("**********break*****************\n");
printf(" fourth lecture(1:00 p.m.-2:00 p.m.):%s\n",c1.four);
printf(" fifth lecture(2:00 p.m.-3:00 p.m.):%s\n",c1.five);
printf(" sixth lecture(3:00 p.m.-4:00 p.m.):%s\n",c1.six);
}fflush(stdin);
}
fclose(fptr);
getch();
  }

  void searchciv()      //function for searching class schedule of civil branch
{
 FILE *ft;
ft=fopen("civil.txt","rb");
 printf("enter id");
 fflush(stdin);
 scanf("%s",&id);
if(ft==NULL)
{
puts("file not fond");
exit(1);
}
rewind(ft);
while(fread(&c2,sizeof(c2),1,ft)==1)
{
if(strcmp(id,c2.id)==0)
{
isFound=1;
break;
}

if(isFound==1)
{
clrscr();
gotoxy(10,10);
printf("*************class schedule****************/n");
printf("class id:%s\n",c2.id);
printf(" day:%s\n",c2.day);
printf(" course:%s\n",c2.course);
printf("semster:%s\n",c2.sem);
printf(" stream:%s\n",c2.stream);
printf("first lecture(9:00 a.m.-10:00 a.m.):%s\n",c2.one);
printf("second lecture(10:00 a.m.-11:00 a.m.):%s\n",c2.two);
printf(" third lecture(11:00 a.m.-12:00 a.m.):%s\n",c2.three);
printf("**********break*****************/n");
printf(" fourth lecture(1:00 p.m.-2:00 p.m.):%s\n",c2.four);
printf(" fifth lecture(2:00 p.m.-3:00 p.m.):%s\n",c2.five);
printf(" sixth lecture(3:00 p.m.-4:00 p.m.):%s\n",c2.six);
}fflush(stdin);
}
fclose(ft);
getch();
  }

void searchece() //function for searching class schedule of ece branch
{
 FILE *fe;
fe=fopen("ece.txt","rb");
 printf("enter id");
 fflush(stdin);
 scanf("%s",&id);
if(fe==NULL)
{
puts("file not fond");
exit(1);
}
rewind(fe);
while(fread(&c3,sizeof(c3),1,fe)==1)
{
if(strcmp(id,c3.id)==0)
{
isFound=1;
break;
}
if(isFound==1)
{
clrscr();
gotoxy(10,10);
printf("*************class schedule****************/n");
printf("class id:%s\n",c3.id);
printf(" day:%s\n",c3.day);
printf(" course:%s\n",c3.course);
printf("semster:%s\n",c3.sem);
printf(" stream:%s\n",c3.stream);
printf("first lecture(9:00 a.m.-10:00 a.m.):%s\n",c3.one);
printf("second lecture(10:00 a.m.-11:00 a.m.):%s\n",c3.two);
printf(" third lecture(11:00 a.m.-12:00 a.m.):%s\n",c3.three);
printf("**********break*****************/n");
printf(" fourth lecture(1:00 p.m.-2:00 p.m.):%s\n",c3.four);
printf(" fifth lecture(2:00 p.m.-3:00 p.m.):%s\n",c3.five);
printf(" sixth lecture(3:00 p.m.-4:00 p.m.):%s\n",c3.six);
}fflush(stdin);
fclose(fe);
getch();
  }
  }

      void addbus()   //function for adding bus information
      {
      FILE *fa;
    fa= fopen("buss.txt","ab+");
if(fa==NULL)
  {
printf("file not found");
exit(1);
   }
   while(1)
{

clrscr();
printf("enter the bus number:\n");
scanf("%s",&b.num);
printf("enter the time of bus:\n ");
scanf("%s",&b.time);
printf("enter the stop of bus:\n");
scanf("%s",&b.stop);
fwrite(&b,sizeof(b),1,fa);
fflush(stdin);
printf("record added\n");
printf("press ESC to exit\n");
ex=getch();
if(ex==27)
{
exit(1);
}

  fclose(fa);
getch();
}
}
void searchbus()   //this function searches the time schedule of bus
{
char numb[5];
FILE *fa;
fa=fopen("buss.txt","rb");
clrscr();
printf("enter bus no.:\n");
scanf("%s",&numb);
if(fa==NULL)
{
puts("file not fond");
exit(1);
}
rewind(fa);
while(fread(&b,sizeof(b),1,fa)==1)
{
if(strcmp(b.num,numb)==0)
{
isFound=1;
break;
}
}
if(isFound==1)
{
clrscr();
printf("\t********************bus information**********************\t\n");
printf("bus number:%s\n",b.num);
printf("time of bus:%s\n",b.time);
printf("stop of bus:%s\n",b.stop);
fflush(stdin);
}
else
{
printf("record not found");
sleep(10);
searchbus();
}
fclose(fa);
getch();
 }
void addclg()
{
FILE *fd;
fd=fopen("clg.txt","w");
if(fd==NULL)
{
puts("file not found");
exit(1);
}
printf("**********************add college information***************\n");
while(1)
  {
  clrscr();
printf("enter college information:\n");
scanf("%s",&info);
fwrite(info,sizeof(info),1,fd);
fflush(stdin);
printf("record added\n");
printf("press ESC to exit\n");
ex=getch();
if(ex==27)
{
exit(1);
}
fclose(fd);
getch();
    }
  }


void searchclg()
{
FILE *fd;
fd=fopen("clg.txt","rb");
if(fd==NULL)
{
puts("file not fond");
exit(1);
}
rewind(fd);
while(fread(&info,sizeof(info),1,fd)==1)
{
clrscr();
printf("******************college information*************\n");
printf("%s",info);
printf("press ESC or any other key to exit\n");
ex=getch();
if(ex==27)
{
exit(1);
}
}
fclose(fd);
getch();
}

void editteach()
{
FILE*fr;
fr=fopen("teach.txt","rb+");
printf("enter teacher's id to be edited:\n");
scanf("%s",&id);
if(fr==NULL)
{
puts("file not fond");
exit(1);
}
rewind(fr);
while(fread(&t,sizeof(t),1,fr)==1)
{
if(strcmp(t.id,id)==0)
{
isFound=1;
break;
}
   }
if(isFound==1)
{
clrscr();
printf("record found");
clrscr();
printf("\t*******************edit teacher's information***************\t");
printf("enter the teacher id:\n");
scanf("%s",&t.id);
printf("enter the name of teacher:\n ");
scanf("%s",&t.name);
printf("enter the subject teacher teaches");
scanf("%s",&t.sub);
printf("enter the departement of teacher:\n");
scanf("%s",&t.dept);
printf("enter the designation of teacher:\n");
scanf("%s",&t.desg);
fseek(fr,-sizeof(t),SEEK_CUR);
fwrite(&t,sizeof(t),1,fr);
fflush(stdin);
printf("record added");
printf("press ESC to exit");
ex=getch();
if(ex==27)
{
exit(1);
}
fclose(fr);
getch();
    }
    }
void delteach()
{
FILE*temp,*fr;
temp=fopen("temp.txt","wb");
fr=fopen("teach.txt","rb");
if(fr==NULL)
{
puts("file not found");
exit(1);
}
if(temp==NULL)
{
 puts("file not found" );
 exit(1);
}

printf("enter the id which is to be deleted:\n");
scanf("%s",&id);
rewind(fr);
while(fread(&t,sizeof(t),1,fr)==1)
{
if(strcmp(t.id,id)==0)
{
clrscr();
printf("record found");
continue;
}

else

fwrite(&t,sizeof(t),1,temp);
}
fclose(temp);
fclose(fr);
remove("teach.txt");
rename("temp.txt","teach.txt");
printf("deleted");
printf("press ESC to exit");
ex=getch();
if(ex==27)
{
exit(1);
}


getch();
}

void editcls()
{
clrscr();
printf("enter cse for computer science engineering\n");
printf("enter me for mechanical engneering\n");
printf("enter ece for electronics and communication engineering\n");
printf("enter ce for civil engineering\n");
printf("type the stream whose class schedule you want to edit:\n");
scanf("%s",&stre);
if(strcmp(stre,"cse")==0)
{
editcse();
   }
else if(strcmp(stre,"me")==0)
{
editme();
}
else if(strcmp(stre,"ce")==0)
{
editciv();
}
else if(strcmp(stre,"ece")==0)
{
editece();
}
else

{
printf("wrong choice");
sleep(5);
exit(1);
}
getch();
}

void editcse()
{
FILE*fp;
fp=fopen("csse.txt","rb+");
printf("enter class id to be edited:\n");
scanf("%s",&id);
if(fp==NULL)
{
puts("file not fond");
exit(1);
}
rewind(fp);
while(fread(&c,sizeof(c),1,fp)==1)
{
if(strcmp(c.id,id)==0)
{
isFound=1;
break;
}
   }
if(isFound==1)
{
printf("****************edit class schedule***************\n");
printf("record found");
printf("enter class id\r\n");
scanf("%s",&c.id);
printf("enter day:\r\n");
scanf("%s",&c.day);
printf("enter cours:\r\n");
scanf("%s",&c.course);
printf("enter sem :\r\n");
scanf("%s",&c.sem);
printf("enter stream\r\n");
scanf("%s",&c.stream);
printf("enter first lecture:\r\n");
scanf("\n%s[^\n]",&c.one);
printf("enter second lecture:\r\n");
scanf("\n%s[^\n]",&c.two);
printf("enter thir lecture:\r\n");
scanf("\n%s[^\n]",&c.three);
printf("enter fourth lecture:\r\n");
scanf("\n%s[^\n]",&c.four);
printf("enter fifth lecture:\r\n");
scanf ("\n%s[^\n]",&c.five);
printf("enter sixth lecture:\r\n");
scanf("\n%s[^\n]",&c.six);
fseek(fp,-sizeof(c),SEEK_CUR);
fwrite(&c,sizeof(c),1,fp);
fflush(stdin);
printf("recorded successfully");
printf("press ESC to exit");
ex=getch();
if(ex==27)
{
exit(1);
}
}
 fclose(fp);
 getch();
}


void editme()
{
FILE*fptr;
fptr=fopen("me.txt","rb+");
printf("enter class id to be edited:\n");
scanf("%s",&id);
if(fptr==NULL)
{
puts("file not fond");
exit(1);
}
rewind(fptr);
while(fread(&c1,sizeof(c1),1,fptr)==1)
{
if(strcmp(c1.id,id)==0)
{
isFound=1;
break;
}
   }
if(isFound==1)
{
printf("****************edit class schedule***************\n");
printf("record found");
printf("enter class id\r\n");
scanf("%s",&c1.id);
printf("enter day:\r\n");
scanf("%s",&c1.day);
printf("enter cours:\r\n");
scanf("%s",&c1.course);
printf("enter sem :\r\n");
scanf("%s",&c1.sem);
printf("enter stream\r\n");
scanf("%s",&c1.stream);
printf("enter first lecture:\r\n");
scanf("\n%s[^\n]",&c1.one);
printf("enter second lecture:\r\n");
scanf("\n%s[^\n]",&c1.two);
printf("enter thir lecture:\r\n");
scanf("\n%s[^\n]",&c1.three);
printf("enter fourth lecture:\r\n");
scanf("\n%s[^\n]",&c1.four);
printf("enter fifth lecture:\r\n");
scanf ("\n%s[^\n]",&c1.five);
printf("enter sixth lecture:\r\n");
scanf("\n%s[^\n]",&c1.six);
fseek(fptr,-sizeof(c1),SEEK_CUR);
fwrite(&c1,sizeof(c1),1,fptr);
fflush(stdin);
printf("record updated");
printf("press ESC to exit");
ex=getch();
if(ex==27)
{
exit(1);
}
}
 fclose(fptr);
 getch();
}


void editciv()
{
FILE*ft;
ft=fopen("civil.txt","rb+");
printf("enter class id to be edited:\n");
scanf("%s",&id);
if(ft==NULL)
{
puts("file not fond");
exit(1);
}
rewind(ft);
while(fread(&c2,sizeof(c2),1,ft)==1)
{
if(strcmp(c2.id,id)==0)
{
isFound=1;
break;
}
   }
if(isFound==1)
{
printf("****************edit class schedule***************\n");
printf("record found");
printf("enter class id\r\n");
scanf("%s",&c2.id);
printf("enter day:\r\n");
scanf("%s",&c2.day);
printf("enter cours:\r\n");
scanf("%s",&c2.course);
printf("enter sem :\r\n");
scanf("%s",&c2.sem);
printf("enter stream\r\n");
scanf("%s",&c2.stream);
printf("enter first lecture:\r\n");
scanf("\n%s[^\n]",&c2.one);
printf("enter second lecture:\r\n");
scanf("\n%s[^\n]",&c2.two);
printf("enter thir lecture:\r\n");
scanf("\n%s[^\n]",&c2.three);
printf("enter fourth lecture:\r\n");
scanf("\n%s[^\n]",&c2.four);
printf("enter fifth lecture:\r\n");
scanf ("\n%s[^\n]",&c2.five);
printf("enter sixth lecture:\r\n");
scanf("\n%s[^\n]",&c2.six);
fseek(ft,-sizeof(c2),SEEK_CUR);
fwrite(&c2,sizeof(c2),1,ft);
fflush(stdin);
printf("recorded successfully");
printf("press ESC to exit");
ex=getch();
if(ex==27)
{
exit(1);
}
}
 fclose(ft);
 getch();
}

void editece()
{
FILE*fe;
fe=fopen("ece.txt","rb+");
printf("enter class id to be edited:\n");
scanf("%s",&id);
if(fe==NULL)
{
puts("file not fond");
exit(1);
}
rewind(fe);
while(fread(&c3,sizeof(c3),1,fe)==1)
{
if(strcmp(c3.id,id)==0)
{
isFound=1;
break;
}
   }
if(isFound==1)
{
printf("****************edit class schedule***************\n");
printf("record found");
printf("enter class id\r\n");
scanf("%s",&c3.id);
printf("enter day:\r\n");
scanf("%s",&c3.day);
printf("enter cours:\r\n");
scanf("%s",&c3.course);
printf("enter sem :\r\n");
scanf("%s",&c3.sem);
printf("enter stream\r\n");
scanf("%s",&c3.stream);
printf("enter first lecture:\r\n");
scanf("\n%s[^\n]",&c3.one);
printf("enter second lecture:\r\n");
scanf("\n%s[^\n]",&c3.two);
printf("enter thir lecture:\r\n");
scanf("\n%s[^\n]",&c3.three);
printf("enter fourth lecture:\r\n");
scanf("\n%s[^\n]",&c3.four);
printf("enter fifth lecture:\r\n");
scanf ("\n%s[^\n]",&c3.five);
printf("enter sixth lecture:\r\n");
scanf("\n%s[^\n]",&c3.six);
fseek(fe,-sizeof(c3),SEEK_CUR);
fwrite(&c3,sizeof(c3),1,fe);
fflush(stdin);
printf("recorded successfully");
printf("press ESC to exit");
ex=getch();
if(ex==27)
{
exit(1);
}
}
 fclose(fe);
 getch();
}
void editbus()
{
char number[10];
FILE*fa;
fa=fopen("buss.txt","rb+");
printf("enter bus no. to be edited:\n");
scanf("%s",&number);
if(fa==NULL)
{
puts("file not fond");
exit(1);
}
rewind(fa);
while(fread(&b,sizeof(b),1,fa)==1)
{
if(strcmp(b.num,number)==0)
{
isFound=1;
break;
}
   }
if(isFound==1)
{
printf("record found");
clrscr();
printf("\t*******************edit teacher's information***************\t");
printf("enter the bus number:\n");
scanf("%s",&b.num);
printf("enter the time of bus:\n ");
scanf("%s",&b.time);
printf("enter the stop of bus:\n");
scanf("%s",&b.stop);
fseek(fa,-sizeof(b),SEEK_CUR);
fwrite(&b,sizeof(b),1,fa);
fflush(stdin);
printf("record added\n");
printf("press ESC to exit\n");
ex=getch();
if(ex==27)
{
exit(1);
}

  fclose(fa);
getch();
}
}

void delbus()
{
char number[10];
FILE*temp,*fa;
	     temp=fopen("temp.txt","wb");
fa=fopen("buss.txt","rb");
if(fa==NULL)
{
puts("file not found");
exit(1);
}
//temp=fopen("temp.txt","wb")
if(temp==NULL)
{
 puts("file not found" );
 exit(1);
}

printf("enter the number of bus which record is to be deleted:\n");
scanf("%s",&number);
rewind(fa);
while(fread(&b,sizeof(b),1,fa)==1)
{
if(strcmp(b.num,number)==0)
{
printf("record found");
continue;
}

else

fwrite(&b,sizeof(b),1,temp);
}
fclose(temp);
fclose(fa);
remove("buss.txt");
rename("temp.txt","buss.txt");
printf("deleted");
printf("press ESC to exit");
ex=getch();
if(ex==27)
{
exit(1);
}


getch();
}

void delcls()
  {
  int ch;
  clrscr();
  gotoxy(10,10);
  printf("\t******************delete schedule***************\t");
   printf("1.CSE(Computer Science Engineering)\n");
   gotoxy(10,11);
   printf("2.ECE(Electronics And Communication Engineering)\n");
   gotoxy(10,12);
   printf("3.ME(Mechanical Engineering)\n");
   gotoxy(10,13);
   printf("4.CE(Civil Engineering)\n");
   gotoxy(10,14);
   printf("please select any one stream\n");
scanf("%d",&ch);
switch(ch)
{
case 1:
delcse();
break;
case 2:
delece();
break;
case 3:
delme();
break;
case 4:
delciv();
break;
default:
printf("wrong choice");
break;
}
printf("press ESC to exit");
ex=getch();
if(ex==27)
{
exit(1);
}


//break;
}
  getch();
}



void delcse()
{
FILE*temp,*fp;
	     temp=fopen("temp.txt","wb");
fp=fopen("csse.txt","rb");
if(fp==NULL)
{
puts("file not found");
exit(1);
}
if(temp==NULL)
{
 puts("file not found" );
 exit(1);
}

printf("enter the id:\n");
scanf("%s",&id);
rewind(fp);
while(fread(&c,sizeof(c),1,fp)==1)
{
if(strcmp(c.id,id)==0)
{
printf("record found");
continue;
}

else

fwrite(&c,sizeof(c),1,temp);
}
fclose(temp);
fclose(fp);
remove("csse.txt");
rename("temp.txt","csse.txt");
printf("deleted");
printf("press ESC to exit");
ex=getch();
if(ex==27)
{
exit(1);
}


getch();
}
       void delme()
{
FILE*temp,*fptr;
	     temp=fopen("temp.txt","wb");
fptr=fopen("csse.txt","rb");
if(fptr==NULL)
{
puts("file not found");
exit(1);
}
if(temp==NULL)
{
 puts("file not found" );
 exit(1);
}

printf("enter the id:\n");
scanf("%s",&id);
rewind(fptr);
while(fread(&c1,sizeof(c1),1,fptr)==1)
{
if(strcmp(c1.id,id)==0)
{
printf("record found");
continue;
}

else

fwrite(&c1,sizeof(c1),1,temp);
}
fclose(temp);
fclose(fptr);
remove("me.txt");
rename("temp.txt","me.txt");
printf("deleted");
getch();
}
void delece()
{
FILE*temp,*fe;
	     temp=fopen("temp.txt","wb");
fe=fopen("ece.txt","rb");
if(fe==NULL)
{
puts("file not found");
exit(1);
}
if(temp==NULL)
{
 puts("file not found" );
 exit(1);
}

printf("enter the id:\n");
scanf("%s",&id);
rewind(fe);
while(fread(&c3,sizeof(c3),1,fe)==1)
{
if(strcmp(c3.id,id)==0)
{
printf("record found");
continue;
}

else

fwrite(&c3,sizeof(c3),1,temp);
}
fclose(temp);
fclose(fe);
remove("ece.txt");
rename("temp.txt","ece.txt");
printf("deleted");
printf("press ESC to exit");
ex=getch();
if(ex==27)
{
exit(1);
}

getch();
}
void delciv()
{
FILE*temp,*ft;
	     temp=fopen("temp.txt","wb");
ft=fopen("civil.txt","rb");
if(ft==NULL)
{
puts("file not found");
exit(1);
}
if(temp==NULL)
{
 puts("file not found" );
 exit(1);
}

printf("enter the id:\n");
scanf("%s",&id);
rewind(ft);
while(fread(&c2,sizeof(c2),1,ft)==1)
{
if(strcmp(c2.id,id)==0)
{
printf("record found");
continue;
}

else

fwrite(&c2,sizeof(c2),1,temp);
}
fclose(temp);
fclose(ft);
remove("civil.txt");
rename("temp.txt","civil.txt");
printf("deleted");
printf("press ESC to exit");
ex=getch();
if(ex==27)
{
exit(1);
}

getch();
}

	   void delclg()
{
FILE*temp,*fd;
	     temp=fopen("temp.txt","wb");
fd=fopen("csse.txt","rb");
if(fd==NULL)
{
puts("file not found");
exit(1);
}
if(temp==NULL)
{
 puts("file not found" );
 exit(1);
}

rewind(fd);
while(fread(&info,sizeof(info),1,fd)==1)
{

printf("record found");

   fwrite(&info,sizeof(info),1,temp);
}
fclose(temp);
fclose(fd);
remove("clg.txt");
rename("temp.txt","clg.txt");
printf("deleted");
printf("press ESC to exit");
ex=getch();
if(ex==27)
{
exit(1);
}


getch();
}
