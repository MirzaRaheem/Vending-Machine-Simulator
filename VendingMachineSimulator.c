#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

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
    printf("Total amount of sale is: %.2lf AED\n" , total_amount);
    printf("Reset total amount of sale to zero (y/n): ");
    char resetoption;
    scanf(" %c", &resetoption);
    
    if (resetoption == 'y'|| resetoption == 'Y') {
        printf("The amount of sale has been set to zero. Please collect the money from the machine\n");
        total_amount = 0.0;
    }
}

// Function to Display the Item Availability
void displayItemAvailability() {
    printf("***** ITEM AVAILABILITY *****\n");
    printf("Product A (Price: %.2lfAED) Quantity: %d\n", PriceA, qtyA);
    printf("Product B (Price: %.2lfAED) Quantity: %d\n", PriceB, qtyB);
    printf("Product C (Price: %.2lfAED) Quantity: %d\n", PriceC, qtyC);
    printf("Product D (Price: %.2lfAED) Quantity: %d\n", PriceD, qtyD);
    printf("Product E (Price: %.2lfAED) Quantity: %d\n", PriceE, qtyE);
    printf("*****************************\n");        
}

// Function for purchasing the item
void purchaseItem() {
    int choice;
    double coins_inserted = 0.0;

    while (1) {
        printf("\n***** PURCHASE ITEM *****\n");
        printf("Available Items:\n");
        printf("1. Product A (Price: %.2lf AED, Quantity: %d)\n", PriceA, qtyA);
        printf("2. Product B (Price: %.2lf AED, Quantity: %d)\n", PriceB, qtyB);
        printf("3. Product C (Price: %.2lf AED, Quantity: %d)\n", PriceC, qtyC);
        printf("4. Product D (Price: %.2lf AED, Quantity: %d)\n", PriceD, qtyD);
        printf("5. Product E (Price: %.2lf AED, Quantity: %d)\n", PriceE, qtyE);
        printf("0. Cancel Purchase\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 0) {
            printf("Purchase cancelled.\n");
            break;
        }

        // Handle item selection
        double item_price = 0.0;
        int* item_qty = NULL;

        switch (choice) {
            case 1:
                item_price = PriceA;
                item_qty = &qtyA;
                break;
            case 2:
                item_price = PriceB;
                item_qty = &qtyB;
                break;
            case 3:
                item_price = PriceC;
                item_qty = &qtyC;
                break;
            case 4:
                item_price = PriceD;
                item_qty = &qtyD;
                break;
            case 5:
                item_price = PriceE;
                item_qty = &qtyE;
                break;
            default:
                printf("Invalid choice. Please select the correct option.\n");
                continue;
        }

        // Confirming the item selection
        printf("You have selected Product %c (Price: %.2lf AED). Confirm? (y/n): ", 'A' + choice - 1, item_price);
        char confirm;
        scanf(" %c", &confirm);

        if (confirm != 'y' && confirm != 'Y') {
            printf("Purchase cancelled.\n");
            continue;
        }

        // Process for the Payment
        printf("\nInsert coins (1 AED, 0.5 AED, or 0.25 AED) to cover the price of Product %c.\n", 'A' + choice - 1);

        while (coins_inserted < item_price) {
            double coin;
            printf("Insert coin: ");
            scanf("%lf", &coin);

            if (coin != 1.0 && coin != 0.5 && coin != 0.25) {
                printf("Invalid coin. Please insert a valid coin.\n");
                continue;
            }

            coins_inserted += coin;
        }

        // Calculating the change
        double change = coins_inserted - item_price;
        total_amount += item_price; // Updating the total amount

        printf("You have purchased Product %c (Price: %.2lf AED).\n", 'A' + choice - 1, item_price);
        printf("Amount paid: %.2lf AED\n", coins_inserted);
        printf("Change: %.2lf AED\n", change);

        // Updating the quantity of the product and sending an alert if necessary
        (*item_qty)--;
        if (*item_qty <= Min) {
            printf("Alert: Quantity of Product %c is less than or equal to %.2lf.\n", 'A' + choice - 1, Min);
        }
        break;
    }
}

// Function for the admin menu
void adminMenu() {
    int adminChoice;

    while (1) {
        printf("\n===== ADMIN MENU =====\n");
        printf("1. Replenish Items\n");
        printf("2. Change Item Prices\n");
        printf("3. Display Total Sale\n");
        printf("4. Display Item Availability\n");
        printf("0. Exit Admin Mode\n");

        printf("Enter your choice: ");
        scanf("%d", &adminChoice);

        switch (adminChoice) {
            case 1:
                replenishItems();
                break;
            case 2:
                changeItemPrices();
                break;
            case 3:
                displayTotalSale();
                break;
            case 4:
                displayItemAvailability();
                break;
            case 0:
                printf("Exiting Admin Mode.\n");
                return; // Exit the admin menu
            default:
                printf("Invalid choice.\n");
        }
    }
}

int main() {
    int choice;

    while (1) {
        printf("\n===== VENDING MACHINE =====\n");
        printf("1. Purchase Item\n");
        printf("2. Admin Mode\n");
        printf("3. Exit\n");
        printf("=============================\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                purchaseItem();
                break;
            case 2:
                int adminPass;
                printf("Enter admin password: ");
                scanf("%d", &adminPass);

                if (adminPass == AdminPass) {
                    adminMenu();
                } else {
                    printf("Incorrect password.\n");
                }
                break;
            case 3:
                printf("Thank you for using the vending machine simulator.\n");
                return 0; // Exit the program
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}