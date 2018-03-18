#include<stdio.h>
#include<stdlib.h>

int StudentMenu()
{
	int choice;

	system("clear");
	printf("\t\t\tStudent Menu\n\n");
	printf("1.CheckoutBook\n");
	printf("2.CheckinBook\n");
	printf("3.BookIssued\n");
	printf("4.ReissueBook\n");

	printf("Enter a Value : ");
	scanf("%d", &choice);

	system ("clear");

	switch(choice)
	{
		case 1:
			//CheckoutBook();
			printf("Checkout was Called\n");
			break;
		case 2:
			//CheckinBook();
			printf("Checkin was Called\n");
			break;
		case 3:
			//BookIssue();
			printf("BookIssued called\n");
			break;
		case 4:
			//ReissueBook();
			printf("ReissueBook was Called\n");
			break;
		default :
			printf("WRONG CHOICE\n");
			break;
	}

	return 0;
}
