#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Member
{
	char UserName[30];
	char Password[30];
	char LibraryNumber[10];
	char Name[30];
	char Address[100];
	char MobileNumber[11];
	char EmailID[30];
};


int main()
{
	struct Member M;

	FILE * Read;
	Read = fopen("Members.txt", "r");

	FILE * Write;
	Write = fopen("Temp.txt", "a");

	char Username[40];

	system("clear");

	printf("Welcome to Remove Member\n\n");

	printf("Enter Username of the Member : ");
	fgets(Username, 40, stdin);

	while(fread(&M, sizeof(struct Member), 1, Read))
	{
			if(strcmp(M.UserName, Username) == 0)
			{
				printf("Member successfully deleted\n\n");
			}
			else
			{
				fwrite(&M, sizeof(struct Member), 1, Write);
			}
	}
	
	remove("Members.txt");
	rename("Temp.txt", "Members.txt");	
	
	fclose(Read);
	fclose(Write);
	
	return 0;
}
