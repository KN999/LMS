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
};

int RemoveBook()
{
	system("clear");
	
	char Name[40];
	int found = 0;
	
	printf("\t\t\t\t\t\t\t\tRemove Book\n\n\n\n");
	printf("Enter name of the Book : ");
	fgets(Name, 40, stdin);

	struct Book B;

	FILE * Read;
	Read = fopen("Books.txt", "r");

	FILE * Write;
	Write = fopen("Temp.txt", "a");

	while(fread(&B, sizeof(struct Book), 1, Read))
	{
		if(strcmp(Name, B.Name) == 0)
			found = 1;
		else
		{
			fwrite(&B, sizeof(struct Book), 1, Write);
			//printf("Successfully written\n");
		}		
	}

	if(found == 1)
		printf("Book Found and Deleted\n\n");
	else
		printf("Book Not Found\n\n");

	fclose(Read);
	fclose(Write);

	remove("Books.txt");
	rename("Temp.txt", "Books.txt");

	char more[5];

	printf("Do you want to Remove more Book ?(y/n)\n");
	fgets(more, 5, stdin);
	
	if(strcmp(more, "y\n") == 0)
		RemoveBook();
	else
	{
		system("clear");
		//printf("thanks for using Remove Book\n");
		AdminMenu();
	}
	
	return 0;	
}
