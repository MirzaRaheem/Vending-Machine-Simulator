#include <stdio.h>
#include <math.h>

// Constants
const double Min = 5.0;      // An alert will be sent if the quantity of any product becomes 5
double PriceA = 3.25; // Price of product A
double PriceB = 2.5;  // Price of product B
double PriceC = 3.5;  // Price of product C
double PriceD = 1.5;  // Price of product D 
double PriceE = 1.75; // Price of product E

// Variables
int AdminPass = 9815;      // Admin Password to acess the admin mode
double total_amount = 0.0; // Total sales since last reset
int qtyA = 15; // Quantity of product A
int qtyB = 15; // Quantity of product B
int qtyC = 15; // Quantity of product C
int qtyD = 15; // Quantity of product D
int qtyE = 15; // Quantity of product E

// Function to reset the quantity of all the items to a random value in the range of [1:20]
void replenishItems() {
    srand(time(NULL));
    qtyA = rand() % 20 + 1;
    qtyB = rand() % 20 + 1;
    qtyC = rand() % 20 + 1;
    qtyD = rand() % 20 + 1;
    qtyE = rand() % 20 + 1;
    printf("Items replenished. New quantities are:- Product A: %d, Product B: %d, Product C: %d, Product D: %d, Product E: %d\n", qtyA, qtyB, qtyC, qtyD, qtyE);

}

// Function to change the prices of the items
void changeItemPrices() {
    double newPriceA, newPriceB, newPriceC, newPriceD, newPriceE;
    printf("Enter the new price for Product A: ");
    scanf("%lf", &newPriceA);
    printf("Enter the new price for Product B: ");
    scanf("%lf", &newPriceB);
    printf("Enter the new price for Product C: ");
    scanf("%lf", &newPriceC);
    printf("Enter the new price for Product D: ");
    scanf("%lf", &newPriceD);
    printf("Enter the new price for Product E: ");
    scanf("%lf", &newPriceE);

    PriceA = newPriceA;
    PriceB = newPriceB;
    PriceC = newPriceC;
    PriceD = newPriceD;
    PriceE = newPriceE;

    printf("The prices for the items has been updated successfully.\n");
}

// Function to display the total sale amount and also to reset if needed 
void displayTotalSale() {
    printf("Total amount of sale is: %.2lfAED , total_amount");
    printf("Reset total amount of sale to zero (yes/no): ");
    char resetoption;
    scanf("%c", &resetoption);
    if (resetoption == 'yes'|| resetoption == 'YES') {
        printf("The amount of sale has been set to zero. Please collect the money from the machine\n");
        total_amount = 0.0;
    }
}

// Function to Display the Item Availability
void displayItemAvailability() {
    printf("xxxxx ITEM AVAILABILITY xxxxx");
    printf("Product A (Price: %.2lfAED) Quantity: %d\n", PriceA, qtyA);
    printf("Product B (Price: %.2lfAED) Quantity: %d\n", PriceB, qtyB);
    printf("Product C (Price: %.2lfAED) Quantity: %d\n", PriceC, qtyC);
    printf("Product D (Price: %.2lfAED) Quantity: %d\n", PriceD, qtyD);
    printf("Product E (Price: %.2lfAED) Quantity: %d\n", PriceE, qtyE);
    printf("xxxxxxxxxxxx END xxxxxxxxxxxx");        
}
