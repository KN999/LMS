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

	char choice[5];

	FILE * Read;
	Read = fopen("Approval.txt", "r");
	
	FILE * Write;
	Write = fopen("Members.txt", "a");
		
	while(fread(&M, sizeof(struct Member), 1, Read))
	{
		//system("clear");
		//choice = NULL;

		fflush(stdin);

		printf("UserName : %s", M.UserName);
		printf("Password : %s", M.Password);
		printf("Library Number : %s", M.LibraryNumber);
		printf("Name : %s", M.Name);
		printf("Address : %s", M.Address);
		printf("Mobile Number : %s", M.MobileNumber);
		printf("EmailID : %s", M.EmailID);
		printf("Do you want to approve this one as Member ?(yes/no)\n");
		fgets(choice, 5, stdin);		

		if(strcmp(choice, "yes\n")==0)
		{
			fwrite(&M, sizeof(struct Member), 1, Write);
			printf("Added as Member \n\n");
		}	
		else
			printf("As your Wish\n\n");
	}

	fclose(Read);
	fclose(Write);

	return 0;
}

