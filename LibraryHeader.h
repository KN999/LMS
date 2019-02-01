/*#include"AddBook.h"
#include"UpdateBook.h"
#include"RemoveBook.h"
#include"ApproveMember.h"
#include"UpdateMember.h"
#include"RemoveMember.h"
#include"AdminMenu.h"*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>


struct Book
{
	char Name[40];
	char Author[40];
	char Copies[5];
	char Available[5];	
	//char Tag[20];
	
};


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
