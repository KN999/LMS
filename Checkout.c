//TODO:-Checkout will take Username 
//TODO:-Make a structure Issue: Username, BookName, Author. 
#include"LibraryHeader.h"

struct Issue
{
	char Username[40];
	char BookName[40];
	char Author[40];
};

int main()
{
	char Name[40];
	int found = 0;
	char choice[3];
	char Username[30];

	FILE * Read;
	Read = fopen("Books.txt", "r");

	FILE * Write;
	Write = fopen("Temp.txt", "a");

	FILE * Write2;
	Write2 = fopen("Issue.txt", "a");

	struct Book B;
	struct Issue I;

	system("clear");

	printf("\t\t\t\t\t\t\t\tCheckout\n\n\n\n");
	printf("Enter Username : ");
	fgets(Username, 30, stdin);	
	printf("Enter Book Name : ");
	fgets(Name, 40, stdin);

	while(fread(&B, sizeof(struct Book), 1, Read))
	{
		if(strcmp(Name, B.Name) == 0)
		{
			system("clear");		

			printf("Name : %s", B.Name);
			printf("Author : %s", B.Author);
			printf("Copies : %s", B.Copies);
			printf("Available : %s", B.Available);		
	
			if(B.Available[0] != '0')
			{
				printf("Do you want to Checkout Book(y/n)\n");
				fgets(choice, 3, stdin);
				if(strcmp(choice, "y\n") == 0)
				{

					strcpy(Username, I.Username);
					strcpy(B.Name, I.BookName);
					strcpy(B.Author, I.Author);

					--B.Available[0];
					fwrite(&I, sizeof(struct Issue), 1, Write2);
				}				
								
			}
			else
				printf("You can't checkout Book\n");

			fwrite(&B, sizeof(struct Book), 1, Write);

		}
		else
			fwrite(&B, sizeof(struct Book), 1, Write);
	}


	fclose(Read);
	fclose(Write);
	fclose(Write2);

	remove("Books.txt");
	rename("Temp.txt", "Books.txt");

	printf("Want to Checkout Another Book\n");
	fflush(stdin);
	fgets(choice,3,stdin);

	if(strcmp(choice, "y\n") == 0)
		main();
	else
	printf("Thanks for using \n");


	return 0;
}
