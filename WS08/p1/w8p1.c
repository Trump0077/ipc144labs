/*
*****************************************************************************
                          Workshop - #8 (P1)
Full Name  : 
Student ID#: 
Email      : 
Section    : 

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
*****************************************************************************
*/

#define _CRT_SECURE_NO_WARNINGS


// System header files
#include <stdio.h>

// User header files
#include "w8p1.h"


// 1. Get user input of int type and validate for a positive non-zero number
//    (return the number while also assigning it to the pointer argument)
int getIntPositive(int* number)
{
	int n;
	do {
		scanf("%d", &n);
		if (n <= 0)
			printf("ERROR: Enter a positive value: ");	
	} while (n <= 0);
	if (number != NULL)
		*number = n;
	return n;
}


// 2. Get user input of double type and validate for a positive non-zero number
//    (return the number while also assigning it to the pointer argument)
double getDoublePositive(double* number)
{
	double n;
	do {
		scanf("%lf", &n);
		if (n <= 0)
			printf("ERROR: Enter a positive value: ");
	} while (n <= 0);
	if (number != NULL)
		*number = n;
	return n;
}

// 3. Opening Message (include the number of products that need entering)
void openingMessage(const int number)
{
	printf("Cat Food Cost Analysis\n");
	printf("======================\n\n");
	printf("Enter the details for %d dry food bags of product data for analysis.\n", number);
	printf("NOTE: A 'serving' is %dg\n", GRAMS_PER_SERVING);
	return;
}


// 4. Get user input for the details of cat food product
struct CatFoodInfo getCatFoodInfo(const int n)
{
	struct CatFoodInfo food;
	printf("\nCat Food Product #%d\n", n+1);
	printf("--------------------\n");
	printf("SKU           : ");
	getIntPositive(&food.sku);
	printf("PRICE         : $");
	getDoublePositive(&food.price);
	printf("WEIGHT (LBS)  : ");
	getDoublePositive(&food.weight);
	printf("CALORIES/SERV.: ");
	getIntPositive(&food.calories);
	return food;
}


// 5. Display the formatted table header
void displayCatFoodHeader(void)
{
	printf("SKU         $Price    Bag-lbs Cal/Serv\n");
	printf("------- ---------- ---------- --------\n");
}

// 6. Display a formatted record of cat food data
void displayCatFoodData(int sku, double* price, int calories, double* weight)
{
	printf("%07d %10.2lf %10.1lf %8d\n", sku, *price, *weight, calories);
	return;
}

// 7. Logic entry point
void start()
{
	struct CatFoodInfo food[MAX_NUM_PRODUCTS] = { {0} };
	int num_products = 3, i;
	openingMessage(num_products);
	for (i = 0; i < num_products; i++)
		food[i] = getCatFoodInfo(i);
	printf("\n");
	displayCatFoodHeader();
	for (i = 0; i < num_products; i++)
		displayCatFoodData(food[i].sku, &food[i].price, food[i].calories, &food[i].weight);
	return;
}