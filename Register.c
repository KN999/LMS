#include<stdio.h>
#include<stdlib.h>

struct member
{
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
	printf("Name : ");
	scanf("%s", &m.Name);
	printf("Address: ");
	scanf("%s", &m.Address);
	printf("Mobile Number: ");
	scanf("%s", &m.MobileNumber);
	printf("Email id: ");
	scanf("%s", &m.EmailID);

	printf("You have entered the following details:\n\n");
	printf("Name : %s\n", m.Name);
	printf("Address : %s\n", m.Address);
	printf("Mobile Number : %s\n", m.MobileNumber);
	printf("EmailID : %s\n", m.EmailID);

	return 0;
	
}
