/*
*****************************************************************************
                          Workshop - #5 (P2)
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

#include <stdio.h>

#define MIN_YEAR 2012
#define MAX_YEAR 2022
#define LOG_DAYS 3   //from 3-28

void printDate(int year, int month, int day);//function prototype

void printDate(int year, int month, int day)
{
    switch (month)
    {
    case 1: printf("%d-JAN-%02d\n", year, day); break;
    case 2: printf("%d-FEB-%02d\n", year, day); break;
    case 3: printf("%d-MAR-%02d\n", year, day); break;
    case 4: printf("%d-APR-%02d\n", year, day); break;
    case 5: printf("%d-MAY-%02d\n", year, day); break;
    case 6: printf("%d-JUN-%02d\n", year, day); break;
    case 7: printf("%d-JUL-%02d\n", year, day); break;
    case 8: printf("%d-AUG-%02d\n", year, day); break;
    case 9: printf("%d-SEP-%02d\n", year, day); break;
    case 10: printf("%d-OCT-%02d\n", year, day); break;
    case 11: printf("%d-NOV-%02d\n", year, day); break;
    case 12: printf("%d-DEC-%02d\n", year, day); break;
    }
    return;
}

int main(void)
{
    const int JAN = 1;
    const int DEC = 12;
    int month, year;
    int i;
    double morningRating, eveningRating;
    double morningTotal = 0, eveningTotal = 0, overallTotal;

    printf("General Well-being Log\n");
    printf("======================\n");
    do {
        printf("Set the year and month for the well-being log (YYYY MM): ");
        scanf("%d %d", &year, &month);
        if (year < MIN_YEAR || year > MAX_YEAR)
            printf("   ERROR: The year must be between 2012 and 2022 inclusive\n");
        if (month < JAN || month > DEC)
            printf("   ERROR: Jan.(1) - Dec.(12)\n");
    } while ((year < MIN_YEAR || year > MAX_YEAR) || (month < JAN || month > DEC));
    
    printf("\n*** Log date set! ***\n\n");
    
    for (i = 0; i < LOG_DAYS; i++)
    {
        printDate(year, month, i + 1);
        do {
            printf("   Morning rating (0.0-5.0): ");
            scanf("%lf", &morningRating);
            if (morningRating < 0 || morningRating > 5)
            {
                printf("      ERROR: Rating must be between 0.0 and 5.0 inclusive!\n");
            }
        } while (morningRating < 0 || morningRating > 5);
        morningTotal += morningRating;
        do {
            printf("   Evening rating (0.0-5.0): ");
            scanf("%lf", &eveningRating);
            if (eveningRating < 0 || eveningRating > 5)
            {
                printf("      ERROR: Rating must be between 0.0 and 5.0 inclusive!\n");
            }
        } while (eveningRating < 0 || eveningRating > 5);
        eveningTotal += eveningRating;
        printf("\n");   
    } 
    overallTotal = morningTotal + eveningTotal;
    printf("Summary\n");
    printf("=======\n");
    printf("Morning total rating:%7.3lf\n", morningTotal);
    printf("Evening total rating:%7.3lf\n", eveningTotal);
    printf("----------------------------\n");
    printf("Overall total rating:%7.3lf\n\n", overallTotal);
    printf("Average morning rating:%5.1lf\n", morningTotal / LOG_DAYS);
    printf("Average evening rating:%5.1lf\n", eveningTotal / LOG_DAYS);
    printf("----------------------------\n");
    printf("Average overall rating:%5.1lf\n\n", overallTotal / (LOG_DAYS * 2));
    return 0;
}