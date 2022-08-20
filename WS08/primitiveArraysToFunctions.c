/*  -------------------------------------------
	Passing Primitive Arrays to Functions!
	- Primitive Arrays to Functions
    ------------------------------------------- */

#include <stdio.h>

#define SZ 3

// Display parallel array data for heights by year
void displayHeightDataArray(int years[], double heights[], int arrSize);

// Display parallel array data for heights by year
void displayHeightData(int* years, double* heights, int arrSize);

// Main entry-point to the application
int main(void)
{
	// Parallel array's:  Track height of a child every 5 years over 
	//                    a 10 year period:
	int year[SZ] =      { 2010, 2015, 2020 }; // Year the height was recorded
	double height[SZ] = { 5.24, 5.5,  5.7 };  // Height measured for the given year

	displayHeightData(year, height, SZ);

	return 0;
}

void displayHeightDataArray(int years[], double heights[], int arrSize)
{
	int i; // General purpose iterator

	for (i = 0; i < arrSize; i++)
	{
		printf("Year: %d Height (ft): %.2lf\n", years[i], heights[i]);
	}
}

void displayHeightData(int* years, double* heights, int arrSize)
{
	int i; // General purpose iterator

	for (i = 0; i < arrSize; i++)
	{
		printf("Year: %d Height (ft): %.2lf\n", years[i], heights[i]);
	}
}