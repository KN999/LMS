#include<stdio.h>
#include<stdlib.h>

int main()
{
	int choice;
	
	system("clear");

	printf("\t\t\tLibrary Management System\n");
	printf("What you want to do\n");	
	printf("1.Register\n");
	printf("2.Login\n");

	scanf("%d", &choice);
	
	switch(choice)
	{
		case 1:
			//Register();
			printf("Register was called\n");
			break;
		
		case 2:
			//Login();
			printf("Login was called\n");
			break;
		
		default:
			printf("Wrong Choice\n");
			break;
	}

	return 0;
}
