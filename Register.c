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

	system("clear");
	printf("\t\t\tRegister\n\n");
	printf("Enter Following Details:\n");
	printf("Username : ");
	//fflush(stdin);
	fgets(M.UserName, 30, stdin);
	//scanf("%s", &m.UserName);
	printf("Password : ");
	//fflush(stdin);
	fgets(M.Password, 30, stdin);
	//scanf("%s", &m.Password);
	printf("Library Number : ");
	//fflush(stdin);	
	fgets(M.LibraryNumber, 10, stdin);
	//scanf("%s" , &m.LibraryNumber);
	printf("Name : ");
	//fflush(stdin);
	fgets(M.Name, 30, stdin);
	//scanf("%s", &m.Name);

	printf("Address: ");
	//fflush(stdin);
	fgets(M.Address, 100, stdin);
	//scanf("%s", &m.Address);
	printf("Mobile Number: ");
	//fflush(stdin);
	fgets(M.MobileNumber, 11, stdin);
	//scanf("%s", &m.MobileNumber);
	printf("Email id: ");
	//fflush(stdin);
	fgets(M.EmailID, 30, stdin);
	//scanf("%s", &m.EmailID);

	printf("You have entered the following details:\n\n");
	printf("Username : %s\n", M.UserName);
	printf("Password : %s\n", M.Password);
	printf("Library Number : %s\n", M.LibraryNumber);
	printf("Name : %s\n", M.Name);
	printf("Address : %s\n", M.Address);
	printf("Mobile Number : %s\n", M.MobileNumber);
	printf("EmailID : %s\n xx", M.EmailID);

	FILE * outfile;
	outfile = fopen("Approval.txt", "a");

	if(outfile == NULL)
	{
		fprintf(stderr ,"ERROR opening file\n");
		exit(1);
	}
	
	fflush(stdin);

	fwrite(&M, sizeof(struct Member), 1, outfile);

	if(fwrite != 0)
		printf("Successfully Written\n");
	else
		printf("Error in Writing \n");

	fclose(outfile);

	return 0;
	
}
