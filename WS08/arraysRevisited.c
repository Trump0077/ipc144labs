/*  -------------------------------------------
	Passing Primitive Arrays to Functions!
	- Review Arrays
    ------------------------------------------- */

#include <stdio.h>

#define SZ 3

// Main entry-point to the application
int main(void)
{
	// Parallel array's:  Track height of a child every 5 years over 
	//                    a 10 year period:
	int year[SZ] =      { 2010, 2015, 2020 }; // Year the height was recorded
	double height[SZ] = { 5.24, 5.5,  5.7 };  // Height measured for the given year

	int i; // General purpose iterator
	int* y = year;      // &year[1]
	double* h = height; // &height[0]

	for (i = 0; i < SZ; i++)
	{
		printf("Year: %d Height (ft): %.2lf\n", year[i], height[i]);
		printf("Year: %d Height (ft): %.2lf\n", y[i], h[i]);
	}

	return 0;
}
