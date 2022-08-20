/*
*****************************************************************************
                          Workshop - #4 (P2)
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
    int Apples, Oranges, Pears, Tomatoes, Cabbages; // the number of different products
    int i; // the number of user picked every time
    int continueShopping; // do another shopping?

    do
    {
        printf("Grocery Shopping\n");
        printf("================\n");

        do
        {
            printf("How many APPLES do you need? : ");
            scanf("%d", &Apples);
            if (Apples < 0)
                printf("ERROR: Value must be 0 or more.\n");
        } while (Apples < 0);
        printf("\n");
        do
        {
            printf("How many ORANGES do you need? : ");
            scanf("%d", &Oranges);
            if (Oranges < 0)
                printf("ERROR: Value must be 0 or more.\n");
        } while (Oranges < 0);
        printf("\n");
        do
        {
            printf("How many PEARS do you need? : ");
            scanf("%d", &Pears);
            if (Pears < 0)
                printf("ERROR: Value must be 0 or more.\n");
        } while (Pears < 0);
        printf("\n");
        do
        {
            printf("How many TOMATOES do you need? : ");
            scanf("%d", &Tomatoes);
            if (Tomatoes < 0)
                printf("ERROR: Value must be 0 or more.\n");
        } while (Tomatoes < 0);
        printf("\n");
        do
        {
            printf("How many CABBAGES do you need? : ");
            scanf("%d", &Cabbages);
            if (Cabbages < 0)
                printf("ERROR: Value must be 0 or more.\n");
        } while (Cabbages < 0);

        printf("\n");
        printf("--------------------------\n");
        printf("Time to pick the products!\n");
        printf("--------------------------\n");
        printf("\n");

        if (Apples)
        {
            do
            {
                printf("Pick some APPLES... how many did you pick? : ");
                scanf("%d", &i);
                
                if (i < 1)
                    printf("ERROR: You must pick at least 1!\n");
                else
                { 
                    if (Apples < i)
                        printf("You picked too many... only %d more APPLE(S) are needed.\n", Apples);
                    else if (Apples)
                    {
                        Apples -= i;
                        if (Apples)
                            printf("Looks like we still need some APPLES...\n");
                    }
                }
            } while (Apples);
            printf("Great, that's the apples done!\n\n");
        }
        if (Oranges)
        {
            do
            {
                printf("Pick some ORANGES... how many did you pick? : ");
                scanf("%d", &i);

                if (i < 1)
                    printf("ERROR: You must pick at least 1!\n");
                else
                {
                    if (Oranges < i)
                        printf("You picked too many... only %d more ORANGE(S) are needed.\n", Oranges);
                    else if (Oranges)
                    {
                        Oranges -= i;
                        if (Oranges)
                            printf("Looks like we still need some ORANGES...\n");
                    }
                }
            } while (Oranges);
            printf("Great, that's the oranges done!\n\n");
        }
        if (Pears)
        {
            do
            {
                printf("Pick some PEARS... how many did you pick? : ");
                scanf("%d", &i);

                if (i < 1)
                    printf("ERROR: You must pick at least 1!\n");
                else
                {
                    if (Pears < i)
                        printf("You picked too many... only %d more PEAR(S) are needed.\n", Pears);
                    else if (Pears)
                    {
                        Pears -= i;
                        if (Pears)
                            printf("Looks like we still need some PEARS...\n");
                    }
                }
            } while (Pears);
            printf("Great, that's the pears done!\n\n");
        }
        if (Tomatoes)
        {
            do
            {
                printf("Pick some TOMATOES... how many did you pick? : ");
                scanf("%d", &i);

                if (i < 1)
                    printf("ERROR: You must pick at least 1!\n");
                else
                {
                    if (Tomatoes < i)
                        printf("You picked too many... only %d more TOMATO(ES) are needed.\n", Tomatoes);
                    else if (Tomatoes)
                    {
                        Tomatoes -= i;
                        if (Tomatoes)
                            printf("Looks like we still need some TOMATOES...\n");
                    }
                }
            } while (Tomatoes);
            printf("Great, that's the tomatoes done!\n\n");
        }
        if (Cabbages)
        {
            do
            {
                printf("Pick some CABBAGES... how many did you pick? : ");
                scanf("%d", &i);

                if (i < 1)
                    printf("ERROR: You must pick at least 1!\n");
                else
                {
                    if (Cabbages < i)
                        printf("You picked too many... only %d more CABBAGE(S) are needed.\n", Cabbages);
                    else if (Cabbages)
                    {
                        Cabbages -= i;
                        if (Cabbages)
                            printf("Looks like we still need some CABBAGES...\n");
                    }
                }
            } while (Cabbages);
            printf("Great, that's the cabbages done!\n\n");
        }
        printf("All the items are picked!\n\n");
        printf("Do another shopping? (0=NO): ");
        scanf("%d", &continueShopping);
        printf("\n");
    } while (continueShopping);

    printf("Your tasks are done for today - enjoy your free time!\n\n");

    return 0;
}