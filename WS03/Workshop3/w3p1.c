#include <stdio.h>
int main()
{
	int i=0, choice;
	printf("Enter your choice <1-5>:");
	scanf_s("%d", &choice);
	if (choice > 0 && choice < 6)



		/*while(i < choice)
		{
			printf("the value of i is %d\n", ++i);
		}
		*/

		/*for (i = 0; i < choice; i++)
			printf("The value of i is %d\n", i);*/
	else
		printf("%d is an invalid choice!\n", choice);
		


	/*
	int choice;
	printf("Enter your choice <0-3>:");
	scanf_s("%d", &choice);
	switch (choice)
	{
		case 0: printf("You entered 0\n");
			break;
		case 1: printf("You entered 1\n");
			break;
		case 2: printf("You entered 2\n");
			printf("You made a good choice!\n");
			break;
		case 3: printf("You entered 3\n");
			break;
		default: printf("%d is an invalid choice!\n", choice);
	}
	*/

	/*
	if (choice == 0)
		printf("You entered 0\n");
	else if (choice == 1)
		printf("You entered 1\n");
	else if (choice == 2)
		printf("You entered 2\n");
	printf("That's a good choice!\n");
	else if (choice == 3)
		printf("You entered 3\n");
	else
		printf("%d is an invalid choice!\n", choice);
	*/

	/*
	float amount, tax = 0.13;
	printf("Please enter amount:");
	scanf_s("%f", &amount);
	printf("Total including tax is $%.2f\n", amount * (1.0 + tax));
	*/
	return 0;
}