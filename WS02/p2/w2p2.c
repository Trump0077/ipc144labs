/*
*****************************************************************************
                          Workshop - #2 (P2)
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
    // You will need this when converting from grams to pounds (lbs)
    const double GRAMS_IN_LBS = 453.5924;
    char Type_1, Type_2, Type_3;//Coffee Type
    char Grind_Size_1, Grind_Size_2, Grind_Size_3;//Coffee Grind Size
    int Bag_Weight_1, Bag_Weight_2, Bag_Weight_3;//Coffee Package Weight
    char Cream_1, Cream_2, Cream_3;//Suggest Serving with Cream
    double Temperature_1, Temperature_2, Temperature_3;//Serving Temperature
    char Strength;//Coffee Strength
    char Maker;//Coffee Making Equipment
    int Daily_Servings;//Daily Servings
    char Like_Cream;//Like Cream with Coffee

    printf("Take a Break - Coffee Shop\n");
    printf("==========================\n");
    printf("\n");
    printf("Enter the coffee product information being sold today...\n");
    printf("\n");

    printf("COFFEE-1...\n");
    printf("Type ([L]ight,[B]lend): ");
    scanf(" %c", &Type_1);
    printf("Grind size ([C]ourse,[F]ine): ");
    scanf(" %c", &Grind_Size_1);
    printf("Bag weight (g): ");
    scanf(" %d", &Bag_Weight_1);
    printf("Best served with cream ([Y]es,[N]o): ");
    scanf(" %c", &Cream_1);
    printf("Ideal serving temperature (Celsius): ");
    scanf(" %lf", &Temperature_1);
    printf("\n");
    
    printf("COFFEE-2...\n");
    printf("Type ([L]ight,[B]lend): ");
    scanf(" %c", &Type_2);
    printf("Grind size ([C]ourse,[F]ine): ");
    scanf(" %c", &Grind_Size_2);
    printf("Bag weight (g): ");
    scanf(" %d", &Bag_Weight_2);
    printf("Best served with cream ([Y]es,[N]o): ");
    scanf(" %c", &Cream_2);
    printf("Ideal serving temperature (Celsius): ");
    scanf(" %lf", &Temperature_2);
    printf("\n");
    
    printf("COFFEE-3...\n");
    printf("Type ([L]ight,[B]lend): ");
    scanf(" %c", &Type_3);
    printf("Grind size ([C]ourse,[F]ine): ");
    scanf(" %c", &Grind_Size_3);
    printf("Bag weight (g): ");
    scanf(" %d", &Bag_Weight_3);
    printf("Best served with cream ([Y]es,[N]o): ");
    scanf(" %c", &Cream_3);
    printf("Ideal serving temperature (Celsius): ");
    scanf(" %lf", &Temperature_3);
    printf("\n");
    
    printf("---+---------------+---------------+---------------+-------+--------------\n");
    printf("   |    Coffee     |    Coffee     |   Packaged    | Best  |   Serving\n");
    printf("   |     Type      |  Grind Size   |  Bag Weight   | Served| Temperature\n");
    printf("   +---------------+---------------+---------------+ With  +--------------\n");
    printf("ID | Light | Blend | Course | Fine |  (G) | Lbs    | Cream |   (C) |   (F)\n");
    printf("---+---------------+---------------+---------------+-------+--------------\n");
    printf(" 1 |   %d   |   %d   |    %d   |   %d  |  %d |  %.3lf |   %d   |  %.1lf | %.1lf\n", Type_1 == 'l' || Type_1 == 'L', Type_1 == 'b' || Type_1 == 'B', Grind_Size_1 == 'c' || Grind_Size_1 == 'C', Grind_Size_1 == 'f' || Grind_Size_1 == 'F', Bag_Weight_1, Bag_Weight_1 / GRAMS_IN_LBS, Cream_1 == 'y' || Cream_1 == 'Y', Temperature_1, (32 + Temperature_1 * 1.8));
    printf(" 2 |   %d   |   %d   |    %d   |   %d  |  %d |  %.3lf |   %d   |  %.1lf | %.1lf\n", Type_2 == 'l' || Type_2 == 'L', Type_2 == 'b' || Type_2 == 'B', Grind_Size_2 == 'c' || Grind_Size_2 == 'C', Grind_Size_2 == 'f' || Grind_Size_2 == 'F', Bag_Weight_2, Bag_Weight_2 / GRAMS_IN_LBS, Cream_2 == 'y' || Cream_2 == 'Y', Temperature_2, (32 + Temperature_2 * 1.8));
    printf(" 3 |   %d   |   %d   |    %d   |   %d  | %d |  %.3lf |   %d   |  %.1lf | %.1lf\n", Type_3 == 'l' || Type_3 == 'L', Type_3 == 'b' || Type_3 == 'B', Grind_Size_3 == 'c' || Grind_Size_3 == 'C', Grind_Size_3 == 'f' || Grind_Size_3 == 'F', Bag_Weight_3, Bag_Weight_3 / GRAMS_IN_LBS, Cream_3 == 'y' || Cream_3 == 'Y', Temperature_3, (32 + Temperature_3 * 1.8));
    printf("\n");

    printf("Enter how you like your coffee and the coffee maker equipment you use...\n");
    printf("\n");
    printf("Coffee strength ([M]ild,[R]ich): ");
    scanf(" %c", &Strength);
    printf("Do you like your coffee with cream ([Y]es,[N]o): ");
    scanf(" %c", &Like_Cream);
    printf("Typical number of daily servings: ");
    scanf(" %d", &Daily_Servings);
    printf("Maker ([R]esidential,[C]ommercial): ");
    scanf(" %c", &Maker);
    printf("\n");
    printf("The below table shows how your preferences align to the available products:\n\n");
    printf("--------------------+--------------------+-------------+-------+--------------\n");
    printf("  |     Coffee      |       Coffee       |  Packaged   | With  |   Serving\n");
    printf("ID|      Type       |     Grind Size     | Bag Weight  | Cream | Temperature\n");
    printf("--+-----------------+--------------------+-------------+-------+--------------\n");
    printf(" 1|       %d         |         %d          |      %d      |   %d   |      %d\n", ((Strength == 'm' || Strength == 'M') && (Type_1 == 'l' || Type_1 == 'L')) || ((Strength == 'r' || Strength == 'R') && (Type_1 == 'b' || Type_1 == 'B')), ((Maker == 'r' || Maker == 'R') && (Grind_Size_1 == 'c' || Grind_Size_1 == 'C')) || ((Maker == 'c' || Maker == 'C') && (Grind_Size_1 == 'f' || Grind_Size_1 == 'F')), ((1 <= Daily_Servings && Daily_Servings <= 4) && (0 <= Bag_Weight_1 && Bag_Weight_1 <= 250)) || ((5 <= Daily_Servings && Daily_Servings <= 9) && (Bag_Weight_1 == 500)) || ((Daily_Servings >= 10) && (Bag_Weight_1 == 1000)), ((Like_Cream == 'y' || Like_Cream == 'Y') && (Cream_1 == 'y' || Cream_1 == 'Y')) || ((Like_Cream == 'n' || Like_Cream == 'N') && (Cream_1 == 'n' || Cream_1 == 'N')), ((Maker == 'r' || Maker == 'R') && ((60 <= Temperature_1) && (Temperature_1 <= 69.9))) || ((Maker == 'c' || Maker == 'C') && Temperature_1 >= 70.0));
    printf(" 2|       %d         |         %d          |      %d      |   %d   |      %d\n", ((Strength == 'm' || Strength == 'M') && (Type_2 == 'l' || Type_2 == 'L')) || ((Strength == 'r' || Strength == 'R') && (Type_2 == 'b' || Type_2 == 'B')), ((Maker == 'r' || Maker == 'R') && (Grind_Size_2 == 'c' || Grind_Size_2 == 'C')) || ((Maker == 'c' || Maker == 'C') && (Grind_Size_2 == 'f' || Grind_Size_2 == 'F')), ((1 <= Daily_Servings && Daily_Servings <= 4) && (0 <= Bag_Weight_2 && Bag_Weight_2 <= 250)) || ((5 <= Daily_Servings && Daily_Servings <= 9) && (Bag_Weight_2 == 500)) || ((Daily_Servings >= 10) && (Bag_Weight_2 == 1000)), ((Like_Cream == 'y' || Like_Cream == 'Y') && (Cream_2 == 'y' || Cream_2 == 'Y')) || ((Like_Cream == 'n' || Like_Cream == 'N') && (Cream_2 == 'n' || Cream_2 == 'N')), ((Maker == 'r' || Maker == 'R') && ((60 <= Temperature_2) && (Temperature_2 <= 69.9))) || ((Maker == 'c' || Maker == 'C') && Temperature_2 >= 70.0));
    printf(" 3|       %d         |         %d          |      %d      |   %d   |      %d\n", ((Strength == 'm' || Strength == 'M') && (Type_3 == 'l' || Type_3 == 'L')) || ((Strength == 'r' || Strength == 'R') && (Type_3 == 'b' || Type_3 == 'B')), ((Maker == 'r' || Maker == 'R') && (Grind_Size_3 == 'c' || Grind_Size_3 == 'C')) || ((Maker == 'c' || Maker == 'C') && (Grind_Size_3 == 'f' || Grind_Size_3 == 'F')), ((1 <= Daily_Servings && Daily_Servings <= 4) && (0 <= Bag_Weight_3 && Bag_Weight_3 <= 250)) || ((5 <= Daily_Servings && Daily_Servings <= 9) && (Bag_Weight_3 == 500)) || ((Daily_Servings >= 10) && (Bag_Weight_3 == 1000)), ((Like_Cream == 'y' || Like_Cream == 'Y') && (Cream_3 == 'y' || Cream_3 == 'Y')) || ((Like_Cream == 'n' || Like_Cream == 'N') && (Cream_3 == 'n' || Cream_3 == 'N')), ((Maker == 'r' || Maker == 'R') && ((60 <= Temperature_3) && (Temperature_3 <= 69.9))) || ((Maker == 'c' || Maker == 'C') && Temperature_3 >= 70.0));
    printf("\n");

    printf("Enter how you like your coffee and the coffee maker equipment you use...\n");
    printf("\n");
    printf("Coffee strength ([M]ild,[R]ich): ");
    scanf(" %c", &Strength);
    printf("Do you like your coffee with cream ([Y]es,[N]o): ");
    scanf(" %c", &Like_Cream);
    printf("Typical number of daily servings: ");
    scanf(" %d", &Daily_Servings);
    printf("Maker ([R]esidential,[C]ommercial): ");
    scanf(" %c", &Maker);
    printf("\n");
    printf("The below table shows how your preferences align to the available products:\n\n");
    printf("--------------------+--------------------+-------------+-------+--------------\n");
    printf("  |     Coffee      |       Coffee       |  Packaged   | With  |   Serving\n");
    printf("ID|      Type       |     Grind Size     | Bag Weight  | Cream | Temperature\n");
    printf("--+-----------------+--------------------+-------------+-------+--------------\n");
    printf(" 1|       %d         |         %d          |      %d      |   %d   |      %d\n", ((Strength == 'm' || Strength == 'M') && (Type_1 == 'l' || Type_1 == 'L')) || ((Strength == 'r' || Strength == 'R') && (Type_1 == 'b' || Type_1 == 'B')), ((Maker == 'r' || Maker == 'R') && (Grind_Size_1 == 'c' || Grind_Size_1 == 'C')) || ((Maker == 'c' || Maker == 'C') && (Grind_Size_1 == 'f' || Grind_Size_1 == 'F')), ((1 <= Daily_Servings && Daily_Servings <= 4) && (0 <= Bag_Weight_1 && Bag_Weight_1 <= 250)) || ((5 <= Daily_Servings && Daily_Servings <= 9) && (Bag_Weight_1 == 500)) || ((Daily_Servings >= 10) && (Bag_Weight_1 == 1000)), ((Like_Cream == 'y' || Like_Cream == 'Y') && (Cream_1 == 'y' || Cream_1 == 'Y')) || ((Like_Cream == 'n' || Like_Cream == 'N') && (Cream_1 == 'n' || Cream_1 == 'N')), ((Maker == 'r' || Maker == 'R') && ((60 <= Temperature_1) && (Temperature_1 <= 69.9))) || ((Maker == 'c' || Maker == 'C') && Temperature_1 >= 70.0));
    printf(" 2|       %d         |         %d          |      %d      |   %d   |      %d\n", ((Strength == 'm' || Strength == 'M') && (Type_2 == 'l' || Type_2 == 'L')) || ((Strength == 'r' || Strength == 'R') && (Type_2 == 'b' || Type_2 == 'B')), ((Maker == 'r' || Maker == 'R') && (Grind_Size_2 == 'c' || Grind_Size_2 == 'C')) || ((Maker == 'c' || Maker == 'C') && (Grind_Size_2 == 'f' || Grind_Size_2 == 'F')), ((1 <= Daily_Servings && Daily_Servings <= 4) && (0 <= Bag_Weight_2 && Bag_Weight_2 <= 250)) || ((5 <= Daily_Servings && Daily_Servings <= 9) && (Bag_Weight_2 == 500)) || ((Daily_Servings >= 10) && (Bag_Weight_2 == 1000)), ((Like_Cream == 'y' || Like_Cream == 'Y') && (Cream_2 == 'y' || Cream_2 == 'Y')) || ((Like_Cream == 'n' || Like_Cream == 'N') && (Cream_2 == 'n' || Cream_2 == 'N')), ((Maker == 'r' || Maker == 'R') && ((60 <= Temperature_2) && (Temperature_2 <= 69.9))) || ((Maker == 'c' || Maker == 'C') && Temperature_2 >= 70.0));
    printf(" 3|       %d         |         %d          |      %d      |   %d   |      %d\n", ((Strength == 'm' || Strength == 'M') && (Type_3 == 'l' || Type_3 == 'L')) || ((Strength == 'r' || Strength == 'R') && (Type_3 == 'b' || Type_3 == 'B')), ((Maker == 'r' || Maker == 'R') && (Grind_Size_3 == 'c' || Grind_Size_3 == 'C')) || ((Maker == 'c' || Maker == 'C') && (Grind_Size_3 == 'f' || Grind_Size_3 == 'F')), ((1 <= Daily_Servings && Daily_Servings <= 4) && (0 <= Bag_Weight_3 && Bag_Weight_3 <= 250)) || ((5 <= Daily_Servings && Daily_Servings <= 9) && (Bag_Weight_3 == 500)) || ((Daily_Servings >= 10) && (Bag_Weight_3 == 1000)), ((Like_Cream == 'y' || Like_Cream == 'Y') && (Cream_3 == 'y' || Cream_3 == 'Y')) || ((Like_Cream == 'n' || Like_Cream == 'N') && (Cream_3 == 'n' || Cream_3 == 'N')), ((Maker == 'r' || Maker == 'R') && ((60 <= Temperature_3) && (Temperature_3 <= 69.9))) || ((Maker == 'c' || Maker == 'C') && Temperature_3 >= 70.0));
    printf("\n");
    printf("Hope you found a product that suits your likes!\n");
    printf("\n");
    
    return 0;
}
