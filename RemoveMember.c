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


int RemoveMember()
{
	struct Member M;
	
	int found = 0;

	FILE * Read;
	Read = fopen("Members.txt", "r");

	FILE * Write;
	Write = fopen("Temp.txt", "a");

	char Username[40];

	system("clear");

	printf("\t\t\t\t\t\t\t\tRemove Member\n\n\n\n");

	printf("Enter Username of the Member : ");
	fgets(Username, 40, stdin);

	while(fread(&M, sizeof(struct Member), 1, Read))
	{
			if(strcmp(M.UserName, Username) == 0)
			{
				found = 1;
				//printf("Member successfully deleted\n\n");
			}
			else
			{
				fwrite(&M, sizeof(struct Member), 1, Write);
			}
	}

	if(found == 1)
		printf("Member Found and Deleted\n");
	else
		printf("Member not found\n");
	
	remove("Members.txt");
	rename("Temp.txt", "Members.txt");	
	
	fclose(Read);
	fclose(Write);

	char more[5];

	printf("Do you want to Remove more Member ?(y/n)\n");
	fgets(more, 5, stdin);
	
	if(strcmp(more, "y\n") == 0)
		RemoveMember();
	else
	{
		system("clear");
		//printf("thanks for using Remove Member\n");
		AdminMenu();
	}	

	return 0;
}
