/*  -------------------------------------------
	Passing Structure(s) to Functions!
	- Pass "By Value" 
	- Pass "By Address"
    ------------------------------------------- */

#include <stdio.h>

// Structure representing a height reading
struct HeightInfo
{
	int year;
	double height;
};

// Display height data (pass by value)
void displayHeightDataBV(struct HeightInfo data);

// Display height data (pass by address)
void displayHeightDataBA(struct HeightInfo* data);

// Main entry-point to the application
int main(void)
{
	// Height Measurement in year 2010
	struct HeightInfo heightData = { 2010, 5.24 };

	// Display height data information:

	// Pass by value:
	displayHeightDataBV(heightData);
	
	// Pass by address:
	displayHeightDataBA(&heightData);

	return 0;
}

// Pass by value:
void displayHeightDataBV(struct HeightInfo data)
{
	printf("Year: %d Height (ft): %.2lf\n", data.year, data.height);
}

// Pass by Address:
void displayHeightDataBA(struct HeightInfo* data)
{
	printf("Year: %d Height (ft): %.2lf\n", data->year, data->height);
}