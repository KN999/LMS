#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct member
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
	int found;

	char username[20], password[30];

	system("clear");

	printf("\t\t\tLogin\n\n");
	printf("Username : ");
	fgets(username, 30, stdin);
	printf("Password : ");
	fgets(password, 30, stdin);

	struct member m;
	
	FILE *infile;
	infile = fopen("Members.txt", "r");

	while(fread(&m, 1, sizeof(struct member), infile))
	{
		printf("Reading Records\n");		
	
		if(strcmp(username, m.Name) == 0 )
		{ if(strcmp(password, m.Address) == 0)
			{	
				found = 1;
				printf("Found one\n");
				
				system("clear");		
	
				printf("Username : %s", m.UserName);
				printf("Password : %s", m.Password);
				printf("Library Number : %s", m.LibraryNumber);
				printf("Name : %s", m.Name);
				printf("Address : %s", m.Address);
				printf("Mobile NUmber : %s", m.MobileNumber);
				printf("EmailID : %s", m.EmailID);
				// Menu(m.LibraryNumber);
				break;
			}
		}
		else
			{
				found = 0;
			}	

	}

	if(found == 1)
		printf("RECORD FOUND\n");
	else if(found == 0)
		printf("RECORD NOT FOUND\n");	
	
	fclose(infile);

	return 0;
}

