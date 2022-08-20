/*
*****************************************************************************
						  Workshop - #8 (P2)
Full Name  : Jiaheng Wang
Student ID#: 180562217
Email      : jwang522@myseneca.ca
Section    : NNN

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
*****************************************************************************
*/

#define _CRT_SECURE_NO_WARNINGS


// System Libraries
#include <stdio.h>

// User-Defined Libraries
#include "w8p2.h"

// ----------------------------------------------------------------------------
// PART-1

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
	printf("\nCat Food Product #%d\n", n + 1);
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



// ----------------------------------------------------------------------------
// PART-2

// 8. convert lbs: kg (divide by 2.20462)
double convertlbsKg(const double* lbs, double* kg)
{
	if (kg != NULL)
		*kg = *lbs / KG;	
	return *kg;
}

// 9. convert lbs: g (call convertKG, then * 1000)
int convertlbsG(const double* lbs, int* g)
{
	if (g != NULL)
		*g = (int)(convertlbsKg(&lbs, &g) * 1000);
	return *g;
}

// 10. convert lbs: kg and g
void convertLbs(const double* lbs, double* kg, int* g)
{
	*kg = covertlbsKg(&lbs, &kg);
	*g = convertlbsG(&lbs, &g);
	return;
}

// 11. calculate: servings based on gPerServ
double calculateServings(const int gramPerServing, const int totalGram, double* numberOfServing)
{
	if (numberOfServing != NULL)
		*numberOfServing = totalGram / gramPerServing;
	return *numberOfServing;
}

// 12. calculate: cost per serving
double calculateCostPerServing(const double* productPrice, const double* numberOfServings, double* costPerServing)
{
	if (costPerServing != NULL)
		*costPerServing = *productPrice / *numberOfServings;
	return *costPerServing;
}

// 13. calculate: cost per calorie
double calculateCostPerCal(const double* productPrice, const double* totalNumberOfCalories, double* costPerCalorie)
{
	if (costPerCalorie != NULL)
		*costPerCalorie = *productPrice / *totalNumberOfCalories;
	return *costPerCalorie;
}

// 14. Derive a reporting detail record based on the cat food product data
struct ReportData calculateReportData(const int n)
{
	struct ReportData report;
	getIntPositive(&report.sku);
	getDoublePositive(&report.price);
	getIntPositive(&report.calories);
	getDoublePositive(&report.weight_lbs);
	covertlbsKg(&report.weight_kg);
	convertlbsG(&report.weight_g);
	calculateServings(&report.totalServings);
	calculateCostPerServing(&report.cost);
	calculateCostPerServing(&report.caloriesCost);
	return report;
}

// 15. Display the formatted table header for the analysis results
void displayReportHeader(void)
{
	printf("Analysis Report (Note: Serving = %dg\n", GRAMS_PER_SERVING);
	printf("---------------\n");
	printf("SKU         $Price    Bag-lbs     Bag-kg     Bag-g Cal/Serv Servings  $/Serv   $/Cal\n");
	printf("------- ---------- ---------- ---------- --------- -------- -------- ------- -------\n");
}

// 16. Display the formatted data row in the analysis table
void displayReportData(int sku, double price, int calories, double weight_lbs, double weight_kg, 
	int weight_g, double totalServing, double cost, double caloriesCost)
{
	printf("%07d %10.2lf %10.1lf %10.4lf %9d %8d %8.1lf %7.2lf %7.5lf", sku, price, weight_lbs, weight_kg,
		weight_g, calories, totalServing, cost, caloriesCost);
	if (price != 0)
		printf("***");
	return;
}

// 17. Display the findings (cheapest)
void displayFinalAnalysis(const int *n, const double *d)
{
	printf("Final Analysis\n");
	printf("--------------\n");
	printf("Based on the comparison data, the PURRR-fect economical option is:\n");
	printf("SKU:%d Price: $%lf\n\n", *n, *d);
	printf("Happy shopping!\n");
	return;
}

// ----------------------------------------------------------------------------

// 7. Logic entry point
void start()
{
	struct CatFoodInfo food[MAX_NUM_PRODUCTS] = { {0} };
	struct ReportData report[MAX_NUM_PRODUCTS] = { {0} };
	int num_products = 3, i;
	int *cheapestSKU;
	double *cheapestPrice;
	openingMessage(num_products);
	for (i = 0; i < num_products; i++)
		food[i] = getCatFoodInfo(i);
	printf("\n");
	displayCatFoodHeader();
	for (i = 0; i < num_products; i++)
		displayCatFoodData(food[i].sku, &food[i].price, food[i].calories, &food[i].weight);
	displayReportHeader();
	for (i = 0; i < num_products; i++)
		displayReportData(report[i].sku, report[i].price, report[i].calories, report[i].weight_lbs, report[i].weight_kg,
			report[i].weight_g, report[i].totalServings, report[i].cost, report[i].caloriesCost);
	for (i = 0; i < num_products; i++)
	{
		if (*cheapestPrice > report[i].cost)
		{
			*cheapestPrice = report[i].cost;
			*cheapestSKU = report[i].sku;
		}
	}
	displayFinalAnalysis(&cheapestSKU, &cheapestPrice);
	return;
}