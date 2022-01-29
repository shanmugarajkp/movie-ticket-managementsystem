#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct book
{
	char code[20];
	char name[20];
	char date[20];
	int cost;
}b;
int seat = 60 ;
void insert_details();
void viewAll();
void find();
void book_ticket();
void old_record(); 
void main()
{
	int ch;
 	do{
	  printf("\n====================================================================");
  	printf("\n");	
  	printf("\t Moive Ticket booking ");
  	printf("\n");
  	printf("\n====================================================================");
  	printf("\nPress <1> Insert Movie");
    printf("\nPress <2> View All Movie");
	  printf("\nPress <3> Find Movie ");
	  printf("\nPress <4> Book Ticket");
	  printf("\nPress <5> View All Transections");
   	printf("\nPress <0> Exit ");
   	printf("\nEnter your Choice ::");
   	scanf("%d",&ch); 	

   	switch (ch)
   	{
    	case 1:
    		insert_details();
   		break;
		case 2:
    		viewAll();
   		break;

		case 3:
    		find();
   		break;

		case 4:
		    book_ticket();
		  break;

		case 5:
		    old_record();
		  break;

    case 0:
    		exit(0);
    	break;

    default:
    		printf("Wrong choice !");
    	break;
   	}
 }while(ch!=0);
}

void insert_details()
{

	FILE *fp;
	struct book b;
	printf("Enter Movie Code :- ");	
	scanf("%s",b.code);
	printf("Enter Movie Name :- ");	
	scanf("%s",b.name);
	printf("Enter Release Date:- ");	
	scanf("%s",b.date);
	printf("Enter Ticket Price:- ");	
	scanf("%d",&b.cost);

	fp=fopen("data.txt","a");
	if(fp == NULL)
	{
		printf("File not Found");
	}
	else
	{
		fprintf(fp,"%s %s %s %d \n",b.code,b.name,b.date,b.cost);
		printf("Record insert Successful");
	}
	printf("\n");
	fclose(fp);
}
void find() 
{
	struct book b;
	FILE *fp;
	char ch[20];
	printf("Enter movie code :");
	scanf("%s",ch);
	fp = fopen("data.txt","r");
	if(fp == NULL)
	{
		printf("File does not found !");
		exit(1);
	}
	else
	{	
		while(getc(fp) != EOF)
		{
			fscanf(fp,"%s %s %s %d",b.code,b.name,b.date,&b.cost);
			if(strcmp(b.code,ch) == 0)
			{	
			    printf("%s / %s / %s / %d\n",b.code,b.name,b.date,b.cost);
				printf("\n Record Found\n");
				printf("\n\t\tMovie Code ::%s",b.code);
				printf("\n\t\tMovie Name ::%s",b.name);
				printf("\n\t\tMovie Date ::%s",b.date);
				printf("\n\t\tPrice of Ticket::%d",b.cost);
				break;
			}
		}
	}
	fclose(fp);
}
void viewAll()
{
	char ch;
	FILE *fp;
	fp = fopen("data.txt","r");
	if(fp == NULL)
	{
		printf("file does not found !");
		exit(1);
	}
	else
	{	
		while( ( ch = fgetc(fp) ) != EOF )
      	printf("%c",ch);

	}
	fclose(fp);
}
void book_ticket()
{
  struct book b;
	FILE *fp;
	FILE *ufp;
	int total_seat,mobile,total_amount;
	char name[20];
	char ch;
	char movie_code[20];
  fp = fopen("data.txt","r");
	if(fp == NULL)
	{
		printf("file does not found !");
		exit(1);

	}
	else
	{	
		system("cls");
		while( ( ch = fgetc(fp) ) != EOF )
      	printf("%c",ch);
	}
	fclose(fp);
	printf("\n For Book ticket Choice Movie(Enter Movie Code First Letter Of Movie)\n");
	printf("\n Enter movie code :");
	scanf("%s",movie_code);
	fp = fopen("data.txt","r");
	if(fp == NULL)
	{
		printf("file does not found !");
		exit(1);

	}
	else
	{	
		while(getc(fp) != EOF)
		{
			fscanf(fp,"%s %s %s %d",b.code,b.name,b.date,&b.cost);
			if(strcmp(b.code,movie_code) == 0)
			{	
			  printf("%s / %s / %s / %d\n",b.code,b.name,b.date,b.cost);
				printf("\n Record Found\n");
				printf("\n\t\tCode ::%s",b.code);
				printf("\n\t\tMovie Name ::%s",b.name);
				printf("\n\t\tMovie Date ::%s",b.date);
				printf("\n\t\tPrice of Ticket ::%d",b.cost);
			}
		}

	}
	printf("\n* Fill Deatails  *");
	printf("\n Name :");
	scanf("%s",name);
	printf("\n Mobile number :");
	scanf("%d",&mobile);
	printf("\n Total number of tickets :");
	scanf("%d",&total_seat);

	total_amount = b.cost * total_seat;
	printf("\n ** ENJOY MOVIE ***\n");
	printf("\n\t\tName : %s",name);
	printf("\n\t\tMobile Number : %d",mobile);
	printf("\n\t\tMovie name : %s",b.name);
	printf("\n\t\tTotal seats : %d",total_seat);
	printf("\n\t\tCost per ticket : %d",b.cost);
	printf("\n\t\tTotal Amount : %d",total_amount);

	ufp=fopen("oldTransection.txt","a");
	if(ufp == NULL)
	{
		printf("File not Found");
	}
	else
	{
    fprintf(ufp,"%s %d %d %d %s %d \n", name, mobile, total_seat, total_amount, b.name, b.cost);
		printf("\n Record insert Successful to the old record file");
	}
	printf("\n");
	fclose(ufp);
	fclose(fp);
}
void old_record()
{
	char ch;
	FILE *fp;

	fp = fopen("oldTransection.txt","r");
	if(fp == NULL)
	{
		printf("file does not found !");
		exit(1);
	}
	else
	{	
		while( ( ch = fgetc(fp) ) != EOF )
      		printf("%c",ch);
	}
	fclose(fp);
}
