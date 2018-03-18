#include<stdio.h>
#include<stdlib.h>

int AdminMenu()
{
	int choice;

	system("clear");
	printf("\t\t\tAdmin Menu\n");
	printf("1.Add Book\n");
	printf("2.Update Book\n");
	printf("3.Remove Book\n");
	printf("4.Add Member\n");
	printf("5.Update Member\n");
	printf("6.Remove Membeer\n\n");
	printf("Enter a value : ");
	scanf("%d", &choice);

	system("clear");

	switch(choice)
	{
		case 1:
			printf("Add Book was Called \n");
			//AddBook();			
			break;
		
		case 2:
			printf("Update Book was Called\n");
			//UpdateBook();
			break;
		
		case 3:
			printf("Remove Book was Called\n");
			//RemoveBook();
			break;

		case 4:
			printf("Add Member Called\n");
			//AddMember();
			break;

		case 5:
			printf("Update Member Called\n");
			//UpdateMember();
			break;

		case 6:
			printf("Remove Member Called\n");
			//RemoveBook();
			break;
		
		default:
			printf("Wrong Choice\n");
			break;
	}

	return 0;
}
