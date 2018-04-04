//TODO:- Some Error in Checkin
#include"LibraryHeader.h"

struct Issue
{
	char Username[40];
	char BookName[40];
	char Author[40];
};

int main()
{
	int found = 0;
	char Username[40];

	system("clear");

	printf("\t\t\t\t\t\t\t\tCheckIn\n\n\n\n");
	printf("Enter Username : ");
	fgets(Username, 40, stdin);

	struct Issue I;

	FILE * Read;
	Read = fopen("Issue.txt", "r");
	
	while(fread(&I, sizeof(struct Issue), 1, Read))
	{
		if(strcmp(Username, I.Username) == 0)
		{	
			found = 1;	
			printf("Username : %s", I.Username);
			printf("Book Name : %s", I.BookName);
			printf("Author : %s", I.Author);
		}
	
	}
	
	if(found == 0)
		printf("No Details\n");

	fclose(Read);

	return 0;	
}
