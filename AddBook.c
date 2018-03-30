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
	//char Tag[20];
	
};

int AddBook()
{
	struct Book B;

	system("clear");
	printf("\t\t\t\t\t\t\t\tAdd Book\n\n\n\n");

	printf("Book Name : ");
	fgets(B.Name, 40, stdin);
	printf("Author : ");
	fgets(B.Author, 40, stdin);
	printf("Copies : ");
	fgets(B.Copies, 5, stdin);	
	printf("Available : ");
	fgets(B.Available, 5, stdin);
	//printf("Tag : ");
	//fgets(B.Tag, 20, stdin);
	
	printf("Book Name : %s", B.Name);
	printf("Book Author : %s", B.Author);
	printf("Book Copies : %s", B.Copies);
	printf("Book Available : %s", B.Available);

	FILE * infile;
	infile = fopen("Books.txt", "a");
	
	if(infile == NULL)
	{
		fprintf(stderr, "ERROR in Opening File\n");
		exit(1);	
	}

	fflush(stdin);

	fwrite(&B, sizeof(struct Book), 1, infile);

	if(fwrite != 0)
		printf("\nBook Successfully Added\n\n");
	else
		printf("Error in Writing file\n");	

	fclose(infile);

	char more[5];

	printf("Do you want to Add more Book ?(y/n)\n");
	fgets(more, 5, stdin);
	
	if(strcmp(more, "y\n") == 0)
		AddBook();
	else
	{
		system("clear");
		//printf("thanks for using Add Book\n");
		AdminMenu();
	}
	
	return 0;
}

