/*
*****************************************************************************
                          Workshop - #8 (P1)
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

//macros
#define MAX_NUM_PRODUCTS 3
#define GRAMS_PER_SERVING 64

// ----------------------------------------------------------------------------
// structures
struct CatFoodInfo
{
    int sku;        //stock keeping unit
    double price;   //price of product
    int calories;   //per serving
    double weight;  //pounds
};

// ----------------------------------------------------------------------------
// function prototypes

// 1. Get user input of int type and validate for a positive non-zero number
//    (return the number while also assigning it to the pointer argument)
int getIntPositive(int* i); //the formal parameter name is optional in header file

// 2. Get user input of double type and validate for a positive non-zero number
//    (return the number while also assigning it to the pointer argument)
double getDoublePositive(double* d);

// 3. Opening Message (include the number of products that need entering)
void openingMessage(const int); // this function cannot change this integer

// 4. Get user input for the details of cat food product
struct CatFoodInfo getCatFoodInfo(const int);

// 5. Display the formatted table header
void displayCatFoodHeader();

// 6. Display a formatted record of cat food data
void displayCatFoodData(int, double*, int, double*);

// 7. Logic entry point
void start();
