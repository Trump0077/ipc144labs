/*
*****************************************************************************
                          Workshop - #3 (P1)
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

int main(void)
{
    const double TAX = 0.13;
    const char patSize = 'S';
    double SMALL, MEDIUM, LARGE;
    int Number; //Number of shirts Patty 

    printf("Set Shirt Prices\n");
    printf("================\n");
    printf("Enter the price for a SMALL shirt: $");
    scanf("%lf", &SMALL);
    printf("Enter the price for a MEDIUM shirt: $");
    scanf("%lf", &MEDIUM);
    printf("Enter the price for a LARGE shirt: $");
    scanf("%lf", &LARGE);
    printf("\n");
    printf("Shirt Store Price List\n");
    printf("======================\n");
    printf("SMALL  : $%.2lf\n", SMALL);
    printf("MEDIUM : $%.2lf\n", MEDIUM);
    printf("LARGE  : $%.2lf\n", LARGE);
    printf("\n");
    printf("Patty's shirt size is '%c'\n", patSize);
    printf("Number of shirts Patty is buying: ");
    scanf("%d", &Number);
    printf("\n");
    printf("Patty's shopping cart...\n");
    printf("Contains : %d shirts\n", Number);
    printf("Sub-total: $%8.4lf\n", (int)(SMALL * Number * 100.0 + 0.5) / 100.0);
    printf("Taxes    : $%8.4lf\n", (int)(SMALL * Number * TAX * 100.0 + 0.5) / 100.0);
    printf("Total    : $%8.4lf\n\n", (int)(SMALL * Number * (1+TAX) * 100.0 + 0.5) / 100.0);
    
    return 0;
}