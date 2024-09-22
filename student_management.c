#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>

void menu();
void insert();
void display();
void add();
void search();
void delete(); 


struct student {
       char name[50];
       char course[50];
       int sem;
       char div[1];
       int roll;
       int marks[4];
       int total;
       float per;
  
}s;

void main()
{
   
menu();
getch();

}
void insert()
{

    FILE *fp;
    struct student s;
    int n,i;
    system("cls");

    fp = fopen("student.txt","w");
    printf("Enter how many students you want to insert : \n");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
    
	    if(fp==NULL)
	   {
		printf("\n file not opened \n");
		return;
	   }
	    else
       {
       printf("\nEnter your name     : "); 
       scanf("%s",&s.name);

       printf("\nEnter your Course   : ");
       scanf("%s",&s.course);

       printf("\nEnter sem           : ");
       scanf("%d",&s.sem);

       printf("\nEnter div           : ");
       scanf("%s",&s.div);
 
       printf("\nEnter roll no       : ");
       scanf("%d",&s.roll);
    
    
      for(;;) {
        printf("\nEnter marks of C Language   : ");
        scanf("%d",&s.marks[0]);

        if(s.marks[0]<=100) {
            break;
        }
        else {
           printf(" Invalid marks \n"); 
        }
       }
       
      for(;;) {
        printf("\nEnter marks of BM           : ");
        scanf("%d",&s.marks[1]);
        if(s.marks[1]<=100) {
            break;
        }
        else {
           printf("Invalid marks \n"); 
        }
       }
       
       for(;;) {
        printf("\nEnter marks of WDT          : ");
        scanf("%d",&s.marks[2]);
        if(s.marks[2]<=100) {
            break;
        }
        else {
           printf("Invalid marks \n"); 
        }
       }
       for(;;) {
        printf("\nEnter marks of  Java        : ");
        scanf("%d",&s.marks[3]);
        if(s.marks[3]<=100) {
            break;
        }
        else {
           printf(" Invalid marks \n"); 
        }
       }
       printf("\n");
       s.total = s.marks[0]+s.marks[1]+s.marks[2]+s.marks[3];
       printf("Total is : %d \n",s.total);
        printf("\n");
       s.per = (s.total*100)/400;
       
       printf("Percentage  is %f\n",s.per);
       fwrite(&s,sizeof(s),1,fp);
       }
    }
     
    fclose(fp);
     printf("\n\nPress any key to continue. \n");
     getch();
     menu();
}
void menu()
{
    int choice;
       system("cls");
 printf("<------------------------------Student Information Management System------------------------------>\n\n");

    printf("\n---:MENU:---\n");
 
    printf("\nEnter appropriate number to perform following task.\n");
    printf("\n");

    printf("[1] : Insert Students Info.\n");
    printf("\n");

    printf("[2] : Display Students Info.\n");
    printf("\n");

    printf("[3]:  Add Students Info.\n");
    printf("\n");

    printf("[4] : Search Students Info.\n");
    printf("\n");

    printf("[5] : Delete Students Info.\n");
    printf("\n");
   
    printf("[6] : Exit.\n");
    printf("\n");
    
    printf("Enter your choice:  ");
    scanf("%d",&choice);
    switch(choice)
    {
    case 1:
        insert();
        break;

    case 2:
        display();
        break;

    case 3:
        add();
        break;

    case 4:
        search();
        break;

    case 5:
        delete();
        break;

    case 6:
        exit(1);
        break;

    default:
     
        printf("Invalid Choice.");
    }

}
void display()
{
    FILE *fp;
    int i=1,j;
    struct student s;
    system("cls");
  
    printf("\n<--:DISPLAY STUDENT:-->\n\n");
    printf("\n\n ");

    printf("-------------------------------------------------------------------------------------------------------\n");
    
    printf(" Student's\n Name       Course    Sem    Div    Rollno    Marks :- C    BM     WDT    JAVA     Total     Percentage\n");
    
    printf("---------------------------------------------------------------------------------------------------------");
    printf("\n\n");
    
    fp = fopen("student.txt","rb+");
    if(fp == NULL){
       
        printf("Error opening file.");
        exit(1);
    }
    j=8;
    while(fread(&s,sizeof(s),1,fp) == 1){
       
        printf("%6s %10s %7d %5s %8d %13d %8d %6d %6d %9d %15f\n",s.name,s.course,s.sem,s.div,s.roll,s.marks[0],s.marks[1],s.marks[2],s.marks[3],s.total,s.per);
        i++;
        j++;
    }
    fclose(fp);
   
    printf("\n\nPress any key to continue. \n");
    getch();
    menu();
}

void add()
{
    FILE *fp;
    struct student s;
    char another ='y';
    system("cls");

    fp = fopen("student.txt","ab+");
    if(fp == NULL){
  
        printf("Error opening file");
        exit(1);
    }
    fflush(stdin);
    while(another == 'y')
    {
        printf("\n<--:ADD STUDENT:-->\n\n");
        
        printf("Enter details of student.\n");
      
        printf("\nEnter Name      : ");
        gets(s.name);
    
        
        printf("\nEnter Course    : ");
        gets(s.course);
     
        printf("\nEnter Sem       : ");
        scanf("%d",&s.sem);
        fflush(stdin);

        printf("\nEnter Div       : ");
        scanf("%s",&s.div);
     
        printf("\nEnter Roll No   : ");
        scanf("%d",&s.roll);
     
        for(;;) {
        printf("\nEnter marks of C Language   : ");
        scanf("%d",&s.marks[0]);

        if(s.marks[0]<=100) {
            break;
        }
        else {
           printf(" Invalid marks \n"); 
        }
       }
       
      for(;;) {
        printf("\nEnter marks of BM           : ");
        scanf("%d",&s.marks[1]);
        if(s.marks[1]<=100) {
            break;
        }
        else {
           printf("Invalid marks \n"); 
        }
       }
       
       for(;;) {
        printf("\nEnter marks of WDT          : ");
        scanf("%d",&s.marks[2]);
        if(s.marks[2]<=100) {
            break;
        }
        else {
           printf("Invalid marks \n"); 
        }
       }
       for(;;) {
        printf("\nEnter marks of  Java        : ");
        scanf("%d",&s.marks[3]);
        if(s.marks[3]<=100) {
            break;
        }
        else {
           printf(" Invalid marks \n"); 
        }
       }
       s.total = s.marks[0]+s.marks[1]+s.marks[2]+s.marks[3];
       printf("\nTotal is : %d \n",s.total);

       s.per = (s.total*100)/400;
       printf("\nPercentage  is %f\n ",s.per);
       fwrite(&s,sizeof(s),1,fp);
       
        printf("\nWant to add of another record? Then press 'y' else 'n'.");
        fflush(stdin);

        another = getch();
        system("cls");
        fflush(stdin);
    }
   fclose(fp);
  
    printf("\n\nPress any key to continue. \n");
    getch();
    menu();
}
void search()
{
    FILE *fp;
    struct student s;
    char stname[20];

    system("cls");
    printf("\n<--:SEARCH STUDENT:-->\n");
 
    printf("\n\nEnter name of student : ");
    fflush(stdin);
    gets(stname);
    fp = fopen("student.txt","rb+");
    if(fp == NULL){
      
        printf("Error opening file");
        exit(1);
    }
    while(fread(&s,sizeof(s),1,fp ) == 1){
        if(strcmp(stname,s.name) == 0)
        {
           
            printf("\nName         : %s",s.name);
            printf("\n");

            printf("\nCourse       : %s",s.course);
            printf("\n");

            printf("\nSem          : %d",s.sem);
            printf("\n");

            printf("\nDiv          : %s",s.div);
            printf("\n");

            printf("\nRoll No      : %d",s.roll);
            printf("\n");
        
            printf("\nMarks of C langauge    : %d",s.marks[0]);
            printf("\n");

            printf("\nMarks of BM            : %d",s.marks[1]);
            printf("\n");

            printf("\nMarks of WDT           : %d",s.marks[2]);
            printf("\n");

            printf("\nMarks of JAVA          : %d",s.marks[3]);
            printf("\n");

            printf("\nTotal      : %d",s.total);
            printf("\n");

            printf("\nPercentage : %f\n",s.per);
        }
    }
    fclose(fp);
  
    printf("\n\nPress any key to continue. \n");
    getch();
    menu();
}
void delete()
{
    char stname[20];
    FILE *fp,*ft;
    struct student s;
    system("cls");
 
    printf("\n<--:DELETE STUDENT:-->\n\n");
    
    printf("Enter name of student to delete record : ");
    fflush(stdin);
    gets(stname);

    fp = fopen("student.txt","rb+");
    if(fp == NULL){
       
        printf("Error opening file");
        exit(1);
    }
    ft = fopen("temp.txt","wb+");
    if(ft == NULL){
       
        printf("Error opening file");
        exit(1);
    }
    while(fread(&s,sizeof(s),1,fp) == 1){
        if(strcmp(stname,s.name)!=0)
            fwrite(&s,sizeof(s),1,ft);
    }
    fclose(fp);
    fclose(ft);
    remove("student.txt");
    rename("temp.txt","student.txt");
    
    printf("\n\nPress any key to continue. \n");
    getch();
    menu();
}