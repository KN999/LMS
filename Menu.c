#include<stdio.h>
#include<stdlib.h>
#include "AdminMenu.h"
#include "StudentMenu.h"

int main()
{
	char LibraryNumber[10];

	printf("Enter the Library Number : ");
	fgets(LibraryNumber, 10, stdin);

	if((LibraryNumber[0] == '1') && (LibraryNumber[1] == '1') && (LibraryNumber[2] == '1'))
		{
			//printf("Admin Menu was called\n");
			AdminMenu();
		}
	else
		{
			//printf("Student Menu was called\n");
			StudentMenu();
		}
	
	return 0;
}

