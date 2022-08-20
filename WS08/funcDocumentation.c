/*  -------------------------------------------
	Function Documentation
	- Best coding practice: Clarity!
	- Clear concise naming and use of comments
	------------------------------------------- */

#include <stdio.h>

#include "funcDocumentation.h"

void dDPY(int* a, int* b, int c)
{
	int i;

	for (i = 0; i < c; i++)
	{
		printf("Year:%d Days:%d\n", a[i], b[i]);
	}
}


void displayDaysPerYear(int year[], int days[], int arrSize)
{
	int i;

	for (i = 0; i < arrSize; i++)
	{
		printf("Year:%d Days:%d\n", year[i], days[i]);
	}
}