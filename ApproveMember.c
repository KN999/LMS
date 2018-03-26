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

	char choice[2];

	FILE * Read;
	Read = fopen("Approval.txt", "r");
	
	FILE * Write;
	Write = fopen("Members.txt", "a");
		
	while(fread(&M, sizeof(struct Member), 1, Read))
	{
		system("clear");

		printf("%s\n", M.UserName);
		printf("%s\n", M.Password);
		printf("%s\n", M.LibraryNumber);
		printf("%s\n", M.Name);
		printf("%s\n", M.Address);
		printf("%s\n", M.MobileNumber);
		printf("%s\n", M.EmailID);
		printf("Do you want to approve this one as Member ?(y/n)\n");
		fgets(choice, 2, stdin);

		if(choice[0] == 'y')
		{
			fwrite(&M, sizeof(struct Member), 1, Write);
			printf("Added as Member \n");
		}	
		else
			printf("As your Wish\n");
	}

	fclose(Read);
	fclose(Write);

	return 0;
}

