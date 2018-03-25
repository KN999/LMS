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
	struct member m;

	system("clear");
	printf("\t\t\tRegister\n\n");
	printf("Enter Following Details:\n");
	printf("Username : ");
	//fflush(stdin);
	fgets(m.UserName, 30, stdin);
	//scanf("%s", &m.UserName);
	printf("Password : ");
	//fflush(stdin);
	fgets(m.Password, 30, stdin);
	//scanf("%s", &m.Password);
	printf("Library Number : ");
	//fflush(stdin);	
	fgets(m.LibraryNumber, 10, stdin);
	//scanf("%s" , &m.LibraryNumber);
	printf("Name : ");
	//fflush(stdin);
	fgets(m.Name, 30, stdin);
	//scanf("%s", &m.Name);

	printf("Address: ");
	//fflush(stdin);
	fgets(m.Address, 100, stdin);
	//scanf("%s", &m.Address);
	printf("Mobile Number: ");
	//fflush(stdin);
	fgets(m.MobileNumber, 11, stdin);
	//scanf("%s", &m.MobileNumber);
	printf("Email id: ");
	//fflush(stdin);
	fgets(m.EmailID, 30, stdin);
	//scanf("%s", &m.EmailID);

	printf("You have entered the following details:\n\n");
	printf("Username : %s\n", m.UserName);
	printf("Password : %s\n", m.Password);
	printf("Library Number : %s\n", m.LibraryNumber);
	printf("Name : %s\n", m.Name);
	printf("Address : %s\n", m.Address);
	printf("Mobile Number : %s\n", m.MobileNumber);
	printf("EmailID : %s\n xx", m.EmailID);

	FILE * outfile;
	outfile = fopen("Members.txt", "a");

	if(outfile == NULL)
	{
		fprintf(stderr ,"ERROR opening file\n");
		exit(1);
	}
	
	fflush(stdin);

	fwrite(&m, sizeof(struct member), 1, outfile);

	if(fwrite != 0)
		printf("Successfully Written\n");
	else
		printf("Error in Writing \n");

	fclose(outfile);

	return 0;
	
}
