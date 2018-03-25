#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Book
{
	char Name[40];
	char Author[40];
	char Copies[5];
	char Available[5];
};

int main()
{
	system("clear");
	
	char Name[40];
	
	printf("Welcome to Remove Book : \n");
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
			printf("Found File\n");
		else
		{
			fwrite(&B, sizeof(struct Book), 1, Write);
			printf("Successfully written\n");
		}		
	}

	fclose(Read);
	fclose(Write);

	remove("Books.txt");
	rename("Temp.txt", "Books.txt");
	
	return 0;	
}
