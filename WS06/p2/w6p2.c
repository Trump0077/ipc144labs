/*
*****************************************************************************
                          Workshop - #6 (P2)
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

#define MAX_NUM 10 //The maximum number of items

int main(void)
{
    const double minIncome = 500.00;    //unmodifiable variables minimum income
    const double maxIncome = 400000.00; //unmodifiable variables maximum income
    const double minCost = 100.00;      //unmodifiable variables minimum cost
    double income;
    int itemNum, i, totalMonth, keepLooking = 1;
    double totalCost = 0;
    double itemCost[MAX_NUM];       //the array to store item's cost
    int itemPriority[MAX_NUM];      //the array to store item's priority
    char financeOptions[MAX_NUM];   //the array to store item's finance options
    int option;                     //prompt the user for a valid menu selection
    int byPriority;                 //prompt the user to specify a priority level to filter by
    double priorityCost[3] = {0};   //the cost of different priority level
    
    printf("+--------------------------+\n");
    printf("+   Wish List Forecaster   |\n");
    printf("+--------------------------+\n\n");
    do {
        printf("Enter your monthly NET income: $");
        scanf("%lf", &income);
        if (income < minIncome)
            printf("ERROR: You must have a consistent monthly income of at least $500.00\n\n");
        if (income > maxIncome)
            printf("ERROR: Liar! I'll believe you if you enter a value no more than $400000.00\n\n");
    } while (income < minIncome || income > maxIncome);
    printf("\n");

    do {
        printf("How many wish list items do you want to forecast?: ");
        scanf("%d", &itemNum);
        if (itemNum < 1 || itemNum > MAX_NUM)
            printf("ERROR: List is restricted to between 1 and 10 items.\n\n");
    } while (itemNum < 1 || itemNum > MAX_NUM);
    printf("\n");

    for (i = 0; i < itemNum; i++)
    {
        printf("Item-%d Details:\n", i + 1);
        do {
            printf("   Item cost: $");
            scanf("%lf", &itemCost[i]);
            if (itemCost[i] < minCost)
                printf("      ERROR: Cost must be at least $100.00\n");
        } while (itemCost[i] < minCost);
        totalCost += itemCost[i];

        do {
            printf("   How important is it to you? [1=must have, 2=important, 3=want]: ");
            scanf("%d", &itemPriority[i]);
            if (itemPriority[i] < 1 || itemPriority[i] > 3)
                printf("      ERROR: Value must be between 1 and 3\n");
        } while (itemPriority[i] < 1 || itemPriority[i] > 3);

        switch (itemPriority[i])
        {
        case 1 :
            priorityCost[0] += itemCost[i];
            break;
        case 2 :
            priorityCost[1] += itemCost[i];
            break;
        case 3:
            priorityCost[2] += itemCost[i];
            break;
        }

        do {
            printf("   Does this item have financing options? [y/n]: ");
            scanf(" %c", &financeOptions[i]);
            if (financeOptions[i] != 'y' && financeOptions[i] != 'n')
                printf("      ERROR: Must be a lowercase 'y' or 'n'\n");
        } while (financeOptions[i] != 'y' && financeOptions[i] != 'n');
        printf("\n");
    }

    printf("Item Priority Financed        Cost\n");
    printf("---- -------- -------- -----------\n");
    for (i = 0; i < itemNum; i++)
    {
        printf("%3d  %5d    %5c    %11.2lf\n", 
            i + 1, itemPriority[i], financeOptions[i], itemCost[i]);
    }
    printf("---- -------- -------- -----------\n");
    printf("                      $%11.2lf\n\n", totalCost);

    do {
        do {
            printf("How do you want to forecast your wish list?\n");
            printf(" 1. All items (no filter)\n");
            printf(" 2. By priority\n");
            printf(" 0. Quit/Exit\n");
            printf("Selection: ");
            scanf("%d", &option);
            printf("\n");
            if (option != 0 && option != 1 && option != 2)
            {
                printf("ERROR: Invalid menu selection.\n\n");
            }
        } while (option != 0 && option != 1 && option != 2);

        if (option == 1)
        {
            printf("====================================================\n");
            printf("Filter:   All items\n");
            printf("Amount:   $%1.2lf\n", totalCost);
            //round up the total month
            totalMonth = (totalCost + (income - 1)) / income; 
            printf("Forecast: %d years, %d months\n", totalMonth / 12, totalMonth % 12);
            for (i = 0; i < itemNum && keepLooking; i++)
            {
                if (financeOptions[i] == 'y')
                {
                    printf("NOTE: Financing options are available on some items.\n");
                    printf("      You can likely reduce the estimated months.\n");
                    keepLooking = 0;
                }
            }
            printf("====================================================\n\n");
        }

        else if (option == 2)
        {
            printf("What priority do you want to filter by? [1-3]: ");
            scanf("%d", &byPriority);
            printf("\n====================================================\n");
            printf("Filter:   by priority (%d)\n", byPriority);
            printf("Amount:   $%1.2lf\n", priorityCost[byPriority - 1]);
            //round up the total month
            totalMonth = (priorityCost[byPriority - 1] + (income - 1)) / income; 
            printf("Forecast: %d years, %d months\n", totalMonth / 12, totalMonth % 12);
            keepLooking = 1;
            for (i = 0; i < itemNum && keepLooking; i++)
            {
                if (itemPriority[i] == byPriority && financeOptions[i] == 'y')
                {
                    printf("NOTE: Financing options are available on some items.\n");
                    printf("      You can likely reduce the estimated months.\n");
                    keepLooking = 0;
                }
            }
            printf("====================================================\n\n");
        }
    } while (option);
    printf("Best of luck in all your future endeavours!\n\n");

    return 0;
}