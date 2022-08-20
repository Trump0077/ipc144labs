/*
*****************************************************************************
                          Workshop - #3 (P2)
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
    const char patSize = 'S', salSize = 'M', tomSize = 'L';
    double Price_S, Price_M, Price_L; //Price of different size
    int patNum, salNum, tomNum, TotalNumber; //Number of shirts 
    double patSubTotal, salSubTotal, tomSubTotal, SubTotal; //Total price before tax
    double patTax, salTax, tomTax, Tax; //Tax
    double patTotal, salTotal, tomTotal, Total; //Total price after tax
    int Toonies, Loonies, Quarters, Dimes, Nickels, Pennies; //Number of coins
    double Toonies_Balance, Loonies_Balance, Quarters_Balance, Dimes_Balance, Nickels_Balance, Pennies_Balance;//Balance after deduction of the type of coins

    printf("Set Shirt Prices\n");
    printf("================\n");
    printf("Enter the price for a SMALL shirt: $");
    scanf("%lf", &Price_S);
    printf("Enter the price for a MEDIUM shirt: $");
    scanf("%lf", &Price_M);
    printf("Enter the price for a LARGE shirt: $");
    scanf("%lf", &Price_L);
    printf("\n");
    printf("Shirt Store Price List\n");
    printf("======================\n");
    printf("SMALL  : $%.2lf\n", Price_S);
    printf("MEDIUM : $%.2lf\n", Price_M);
    printf("LARGE  : $%.2lf\n", Price_L);
    printf("\n");
    printf("Patty's shirt size is '%c'\n", patSize);
    printf("Number of shirts Patty is buying: ");
    scanf(" %d", &patNum);
    printf("\n");
    printf("Tommy's shirt size is '%c'\n", tomSize);
    printf("Number of shirts Tommy is buying: ");
    scanf(" %d", &tomNum);
    printf("\n");
    printf("Sally's shirt size is '%c'\n", salSize);
    printf("Number of shirts Sally is buying: ");
    scanf(" %d", &salNum);
    printf("\n");

    patSubTotal = (int)(Price_S * patNum * 100.0 + 0.5) / 100.0;
    patTax = (int)(Price_S * patNum * TAX * 100.0 + 0.5) / 100.0;
    patTotal = (int)(Price_S * patNum * (1 + TAX) * 100.0 + 0.5) / 100.0;
    salSubTotal = (int)(Price_M * salNum * 100.0 + 0.5) / 100.0;
    salTax = (int)(Price_M * salNum * TAX * 100.0 + 0.5) / 100.0;
    salTotal = (int)(Price_M * salNum * (1 + TAX) * 100.0 + 0.5) / 100.0;
    tomSubTotal = (int)(Price_L * tomNum * 100.0 + 0.5) / 100.0;
    tomTax = (int)(Price_L * tomNum * TAX * 100.0 + 0.5) / 100.0;
    tomTotal = (int)(Price_L * tomNum * (1 + TAX) * 100.0 + 0.5) / 100.0;
    SubTotal = (int)((patSubTotal + salSubTotal + tomSubTotal) * 100.0 + 0.5) / 100.0;
    Tax = (int)((patTax + salTax + tomTax) * 100.0 + 0.5) / 100.0;
    Total = (int)((patTotal + salTotal + tomTotal) * 100.0 + 0.5) / 100.0;
    TotalNumber = patNum + salNum + tomNum;

    printf("Customer Size Price Qty Sub-Total       Tax     Total\n");
    printf("-------- ---- ----- --- --------- --------- ---------\n");
    printf("Patty    %-4c %5.2lf %3d %9.4lf %9.4lf %9.4lf\n", 
        patSize, Price_S, patNum, patSubTotal, patTax, patTotal);
    printf("Sally    %-4c %5.2lf %3d %9.4lf %9.4lf %9.4lf\n", 
        salSize, Price_M, salNum, salSubTotal, salTax, salTotal);
    printf("Tommy    %-4c %5.2lf %3d %9.4lf %9.4lf %9.4lf\n", 
        tomSize, Price_L, tomNum, tomSubTotal, tomTax, tomTotal);
    printf("-------- ---- ----- --- --------- --------- ---------\n");
    printf("%33.4lf %9.4lf %9.4lf\n\n", SubTotal, Tax, Total);

    Toonies = (int)SubTotal / 2;
    Toonies_Balance = SubTotal - Toonies * 2;
    Loonies = (int)Toonies_Balance / 1;
    Loonies_Balance = Toonies_Balance - Loonies * 1;
    Quarters = (int)(Loonies_Balance * 100) / 25;
    Quarters_Balance = Loonies_Balance - Quarters * 0.25;
    Dimes = (int)(Quarters_Balance * 100) / 10;
    Dimes_Balance = Quarters_Balance - Dimes * 0.10;
    Nickels = (int)(Dimes_Balance * 100) / 5;
    Nickels_Balance = Dimes_Balance - Nickels * 0.05;
    Pennies = ((int)(Nickels_Balance * 100.0 + 0.5) / 100.0) * 100 / 1;
    Pennies_Balance = (int)(Nickels_Balance * 100.0 + 0.5) / 100.0 - Pennies * 0.01;

    printf("Daily retail sales represented by coins\n");
    printf("=======================================\n\n");
    printf("Sales EXCLUDING tax\n");
    printf("Coin     Qty   Balance\n");
    printf("-------- --- ---------\n");
    printf("%22.4lf\n", (int)(SubTotal * 100.0 + 0.5) / 100.0);
    printf("Toonies  %3d %9.4lf\n", Toonies, Toonies_Balance);
    printf("Loonies  %3d %9.4lf\n", Loonies, Loonies_Balance);
    printf("Quarters %3d %9.4lf\n", Quarters, Quarters_Balance);
    printf("Dimes    %3d %9.4lf\n", Dimes, Dimes_Balance);
    printf("Nickels  %3d %9.4lf\n", Nickels, Nickels_Balance);
    printf("Pennies  %3d %9.4lf\n\n", Pennies, Pennies_Balance);
    printf("Average cost/shirt: $%.4lf\n\n", (int)((SubTotal / TotalNumber) * 10000.0 + 0.5) / 10000.0);

    Toonies = (int)Total / 2;
    Toonies_Balance = Total - Toonies * 2;
    Loonies = (int)Toonies_Balance / 1;
    Loonies_Balance = Toonies_Balance - Loonies * 1;
    Quarters = (int)(Loonies_Balance * 100) / 25;
    Quarters_Balance = Loonies_Balance - Quarters * 0.25;
    Dimes = (int)(Quarters_Balance * 100) / 10;
    Dimes_Balance = Quarters_Balance - Dimes * 0.10;
    Nickels = (int)(Dimes_Balance * 100) / 5;
    Nickels_Balance = Dimes_Balance - Nickels * 0.05;
    Pennies = ((int)(Nickels_Balance * 100.0 + 0.5) / 100.0) * 100 / 1;
    Pennies_Balance = (int)(Nickels_Balance * 100.0 + 0.5) / 100.0 - Pennies * 0.01;

    printf("Sales INCLUDING tax\n");
    printf("Coin     Qty   Balance\n");
    printf("-------- --- ---------\n");
    printf("%22.4lf\n", (int)(Total * 100.0 + 0.5) / 100.0);
    printf("Toonies  %3d %9.4lf\n", Toonies, Toonies_Balance);
    printf("Loonies  %3d %9.4lf\n", Loonies, Loonies_Balance);
    printf("Quarters %3d %9.4lf\n", Quarters, Quarters_Balance);
    printf("Dimes    %3d %9.4lf\n", Dimes, Dimes_Balance);
    printf("Nickels  %3d %9.4lf\n", Nickels, Nickels_Balance);
    printf("Pennies  %3d %9.4lf\n\n", Pennies, Pennies_Balance);
    printf("Average cost/shirt: $%.4lf\n\n", (int)((Total / TotalNumber) * 10000.0 + 0.5) / 10000.0);
    
    return 0;
}