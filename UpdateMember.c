/*#include<stdio.h>
#include<stdlib.h>
#include<string.h>*/
#include"LibraryHeader.h"

struct Member M;

int WhatUpdate();
//int Search(char *Name);

int UpdateMember()
{
	char UserName[30];
	int found = 0;

	system("clear");
		
	printf("\t\t\t\t\t\t\t\tUpdate Member\n\n\n\n");
		
	printf("Enter the Member Name : ");
	fgets(UserName, 30, stdin);

	//found = Search(UserName);

	FILE * Read;
	FILE * Write;

	Read = fopen("Members.txt", "r");
	Write = fopen("Temp.txt", "a");
	
	while(fread(&M, 1, sizeof(struct Member), Read))
	{
		if(strcmp(UserName, M.UserName) == 0)
		{
			found = 1;			
			WhatUpdate();
			fflush(stdin);
			fwrite(&M, sizeof(struct Member), 1, Write); 
		}
		else
		{
			fflush(stdin);
			fwrite(&M, sizeof(struct Member), 1, Write);	
		}	
		
	}
	if(found == 1)
		printf("Member Found and Updated\n");
	else 
		printf("Member Not Found\n");

	fclose(Read);
	fclose(Write);

	remove("Members.txt");
	rename("Temp.txt", "Members.txt");

	char more[5];

	printf("Do you want to Update more Member ?(y/n)\n");
	fgets(more, 5, stdin);
	
	if(strcmp(more, "y\n") == 0)
		UpdateMember();
	else
	{
		system("clear");
		printf("thanks for using Update Member\n");
		//AdminMenu();
	}

	
		//Update(Name);
	return 0;
	
}

int WhatUpdate()
{
	char choice[3];

	system("clear");

	printf("Enter what you want to Update : \n");	
	printf("1.Username\n");
	printf("2.Password\n");
	printf("3.Library Number\n");
	printf("4.Name\n");
	printf("5.Address\n");
	printf("6.Mobile Number\n");
	printf("7.EmailID\n");
	fgets(choice, 3, stdin);

	system("clear");

	switch(choice[0])
	{
		case '1':
			printf("Enter User Name : ");
			fgets(M.UserName, 30, stdin);
			break;
		case '2':
			printf("Enter Password : ");
			fgets(M.Password, 30, stdin);
			break;
		case '3':	
			printf("Enter Library Number : ");
			fgets(M.LibraryNumber, 10, stdin);
			break;
		case '4':
			printf("Enter Name : ");
			fgets(M.Name, 30, stdin);
			break;
		case '5':
			printf("Enter Address : ");
			fgets(M.Address, 100, stdin);
			break;
		case '6':
			printf("Enter Mobile Number : ");
			fgets(M.MobileNumber, 11, stdin);
			break;
		case '7':
			printf("Enter EmailID : ");
			fgets(M.EmailID, 30, stdin);
			break;
		default : 
			printf("Wrong Choice\n");
			break;
	}

	return 0;
}
/*
int Search(char *Name)
{
	struct Member M;
	
	FILE * Read;
	Read = fopen("Members.txt", "r");

	while(fread(&M, sizeof(struct Member), 1, Read));
	{
		if(strcmp(Name, M.UserName) == 0)
		{
			return 1;
		}
	}	

	fclose(Read);

	return 0;
}
*/

