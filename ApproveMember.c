#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"AdminMenu.h"

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

int ApproveMember()
{
	struct Member M;

	char choice[5];

	system("clear");

	printf("\t\t\t\t\t\t\t\tApprove Member\n\n\n\n");

	FILE * Read;
	Read = fopen("Approval.txt", "r");
	
	FILE * Write;
	Write = fopen("Members.txt", "a");

	FILE * Write2;
	Write2 = fopen("Temp.txt", "a");
		
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
		printf("Do you want to approve this one as Member ?(y/n)\n");
		fgets(choice, 5, stdin);		

		if(strcmp(choice, "y\n")==0)
		{
			fwrite(&M, sizeof(struct Member), 1, Write);
			printf("Added as Member \n\n");
		}	
		else
		{
			printf("Person not Added as Member\n\n");
			fwrite(&M, sizeof(struct Member), 1, Write2);
		}
	}

	fclose(Read);
	fclose(Write);
	fclose(Write2);
	
	remove("Approval.txt");
	rename("Temp.txt", "Approval.txt");

	char more[5];

	printf("Do you want to Approve Members again?(y/n)\n");
	fgets(more, 5, stdin);
	
	if(strcmp(more, "y\n") == 0)
		ApproveMember();
	else
	{
		system("clear");
		//printf("thanks for using Remove Book\n");
		AdminMenu();
	}
	

	return 0;
}

