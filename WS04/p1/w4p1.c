/*
*****************************************************************************
                          Workshop - #4 (P1)
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
    char loopType; //D,W,F,Q
    int loopCount; //3-20
    int i; 
    printf("+----------------------+\n");
    printf("Loop application STARTED\n");
    printf("+----------------------+\n\n");
    do {
        printf("D = do/while | W = while | F = for | Q = quit\n");
        printf("Enter loop type and the number of times to iterate (Quit=Q0): ");
        scanf(" %c%d", &loopType, &loopCount);
        switch (loopType) 
        {
            case 'D': 
                if (loopCount < 3 || loopCount > 20) 
                    printf("ERROR: The number of iterations must be between 3-20 inclusive!");
                else 
                {
                    printf("DO-WHILE: ");
                    i = 0;
                    do
                    {
                        printf("D");
                        i++;
                    } while (i < loopCount);
                }
                printf("\n\n");
                break;
        
            case 'W':
                if (loopCount < 3 || loopCount > 20)
                    printf("ERROR: The number of iterations must be between 3-20 inclusive!");
                else
                {
                    printf("WHILE   : ");
                    i = 0;
                    while (i < loopCount)
                    {
                        printf("W");
                        i++;
                    }
                }
                printf("\n\n");
                break;

            case 'F': 
                if (loopCount < 3 || loopCount > 20)
                    printf("ERROR: The number of iterations must be between 3-20 inclusive!");
                else
                {
                    printf("FOR     : ");
                    for (i = 0; i < loopCount; i++)
                    {
                        printf("F");
                    }
                }
                printf("\n\n");
                break;

            case 'Q': 
                if (loopCount != 0)
                    printf("ERROR: To quit, the number of iterations should be 0!\n\n");
                else
                    printf("\n");
                break;

            default: printf("ERROR: Invalid entered value(s)!\n\n");
        }

    } while (loopType != 'Q' || loopCount != 0);
    printf("+--------------------+\n");
    printf("Loop application ENDED\n");
    printf("+--------------------+\n\n");

    return 0;
}