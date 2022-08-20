/*
*****************************************************************************
                          Workshop - #8 (P2)
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


// ----------------------------------------------------------------------------
// defines/macros
#define MAX_NUM_PRODUCTS 3
#define GRAMS_PER_SERVING 64
#define KG 2.20462

// ----------------------------------------------------------------------------
// structures
struct CatFoodInfo
{
    int sku;        //stock keeping unit
    double price;   //price of product
    int calories;   //per serving
    double weight;  //pounds
};
struct ReportData
{
    int sku;                //stock keeping unit
    double price;           //price of product
    int calories;           //per serving
    double weight_lbs;
    double weight_kg;
    int weight_g;
    double totalServings;
    double cost;            //per serving
    double caloriesCost;    //per serving
};

// ----------------------------------------------------------------------------
// function prototypes

// PART-1

// 1. Get user input of int type and validate for a positive non-zero number
//    (return the number while also assigning it to the pointer argument)
int getIntPositive(int* i);

// 2. Get user input of double type and validate for a positive non-zero number
//    (return the number while also assigning it to the pointer argument)
double getDoublePositive(double* d);

// 3. Opening Message (include the number of products that need entering)
void openingMessage(const int);

// 4. Get user input for the details of cat food product
struct CatFoodInfo getCatFoodInfo(const int);

// 5. Display the formatted table header
void displayCatFoodHeader(void);

// 6. Display a formatted record of cat food data
void displayCatFoodData(int, double*, int, double*);

// ----------------------------------------------------------------------------
// PART-2

// 8. convert lbs: kg
double covertlbsKg(const double* lbs, double* kg);

// 9. convert lbs: g
int convertlbsG(const double* lbs, int* g);

// 10. convert lbs: kg / g
void convertLbs(const double* lbs, double* kg, int* g);

// 11. calculate: servings based on gPerServ
double calculateServings(const int, const int, double*);

// 12. calculate: cost per serving
double calculateCostPerServing(const double*, const double*, double*);

// 13. calculate: cost per calorie
double calculateCostPerCal(const double*, const double*, double*);

// 14. Derive a reporting detail record based on the cat food product data
struct ReportData calculateReportData(const int);

// 15. Display the formatted table header for the analysis results
void displayReportHeader(void);

// 16. Display the formatted data row in the analysis table
void displayReportData(int sku, double price, int calories, double weight_lbs, double weight_kg,
    int weight_g, double totalServing, double cost, double caloriesCost);

// 17. Display the findings (cheapest)
void displayFinalAnalysis(int*, double*);

// ----------------------------------------------------------------------------

// 7. Logic entry point 
void start();
