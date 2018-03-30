#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"AdminMenu.h"

struct Book
{
	char Name[40];
	char Author[40];
	char Copies[5]; 
	char Available[5];
} B1;


int WhatUpdate();

int UpdateBook()
{
	char Name[40];
	int found = 0;

	system("clear");

	printf("\t\t\t\t\t\t\t\tUpdate Book\n\n\n\n");
		
	printf("Enter the Book Name : ");
	fgets(Name, 40, stdin);

	//found = Search(Name);

	FILE * Read;
	FILE * Write;

	Read = fopen("Books.txt", "r");
	Write = fopen("Temp.txt", "a");

	while(fread(&B1, 1, sizeof(struct Book), Read))
	{
		if(strcmp(Name, B1.Name) == 0)
		{
			found = 1;
			WhatUpdate();
			fflush(stdin);
			fwrite(&B1, sizeof(struct Book), 1, Write); 
			if(fwrite != 0)
				printf("Successfully Written\n");
			else
				printf("Error in Writing file\n");
		}
		else
		{
			fflush(stdin);
			fwrite(&B1, sizeof(struct Book), 1, Write);	
		}	
	
	}	

	if(found == 1)
		printf("File Found And Updated\n");
	else
		printf("File not Found\n");

	fclose(Read);
	fclose(Write);

	remove("Books.txt");
	rename("Temp.txt", "Books.txt");

	char more[5];

	printf("Do you want to Update more Book ?(y/n)\n");
	fgets(more, 5, stdin);
	
	if(strcmp(more, "y\n") == 0)
		UpdateBook();
	else
	{
		system("clear");
		//printf("thanks for using Update Book\n");
		AdminMenu();
	}

	
		//Update(Name);
	return 0;
	
}

int WhatUpdate()
{
	char choice[3];

	system("clear");

	printf("Enter what you want to Update : \n");	
	printf("1.Name\n");
	printf("2.Author Name\n");
	printf("3.Copies\n");
	printf("4.Available\n");
	fgets(choice, 3, stdin);

	system("clear");

	switch(choice[0])
	{
		case '1':
			printf("Enter Name : ");
			fgets(B1.Name, 40, stdin);
			break;
		case '2':
			printf("Enter Author Name : ");
			fgets(B1.Author, 40, stdin);
			break;
		case '3':	
			printf("Enter Copies : ");
			fgets(B1.Copies, 5, stdin);
			break;
		case '4':
			printf("Enter Available : ");
			fgets(B1.Available, 5, stdin);
			break;
		default : 
			printf("Wrong Choice\n");
			break;
	}	

	return 0;
}

/*
//Mehnat thi

//int Search(char *);
//int Update();
int Search(char *Name)
{
	struct Book B;
	
	FILE * Read;
	Read = fopen("Books.txt", "r");

	while(fread(&B, sizeof(struct Book), 1, Read));
	{
		if(strcmp(Name, B.Name) == 0)
		{
			return 1;
		}
	}	

	fclose(Read);

	return 0;
}

int Update(char *Name)
{
	//struct Book B;

	FILE * Read;
	FILE * Write;

	Read = fopen("Books.txt", "r");
	Write = fopen("Temp.txt", "a");

	while(fread(&B1, 1, sizeof(struct Book), Read));
	{
		if(strcmp(Name, B1.Name) == 0)
		{
			WhatUpdate();
			fflush(stdin);
			fwrite(&B1, 1, sizeof(struct Book), Write); 
			if(fwrite != 0)
				printf("Successfully Written\n");
			else
				printf("Error in Writing file\n");
		}
		else
		{
			fflush(stdin);
			fwrite(&B1, 1, sizeof(struct Book), Write);
			if(fwrite != 0)
				printf("Successfully Written\n");
			else
				printf("Error in Writing file\n");	
		}		
	}

	fclose(Read);
	fclose(Write);

	remove("Books.txt");
	rename("Temp.txt", "Books.txt");

	return 0;
}	*/


