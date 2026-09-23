#include <stdio.h>

#define MAX_SUPPLIERS 10

int main() {
    ///// TENDER EVALUATION /////
    // Variable declarations
    char suppName[50];
    float amount[MAX_SUPPLIERS];
    float budget[MAX_SUPPLIERS];
    int registered[MAX_SUPPLIERS];
    int documentsComplete[MAX_SUPPLIERS];
    int qualified[MAX_SUPPLIERS]; 

    // Additional variable declarations
    int numSuppliers;
    int i;
    int supplier = -1; // Index of the preferred supplier, -1 if none

    printf("Enter the number of suppliers (up to %d): ", MAX_SUPPLIERS);
    scanf("%d", &numSuppliers);

    if (numSuppliers <= 0 || numSuppliers > MAX_SUPPLIERS) {
        printf("suppliers entered is invalid.\n");
        return 1;
    }

    // Gather data for each supplier
    for (i = 0; i < numSuppliers; i++) {
        printf("\n--- Supplier %d ---\n", i + 1);

        printf("Enter the supplier name: ");
        scanf("%49s", suppName[i]);

        printf("Enter the tender amount: N$ ");
        scanf("%f", &amount[i]);

        printf("Enter the available budget: N$ ");
        scanf("%f", &budget[i]);

        printf("Is the supplier registered? (1=Yes, 0=No): ");
        scanf("%d", &registered[i]);

        printf("Are all documents complete? (1=Yes, 0=No): ");
        scanf("%d", &documentsComplete[i]);
    }

    // Determine the qualification status for each supplier
    for (int i = 0; i < numSuppliers; i++) {
        if (registered[i] == 0 || documentsComplete[i] == 0 || amount[i] > budget[i]) {
            qualified[i] = 0; // Disqualified
        } else {
            qualified[i] = 1; // Qualified
        }
    }

    // Identifying the preferred supplier: the qualified supplier with the lowest amount
    for (int i = 0; i < numSuppliers; i++) {
        if (qualified[i] == 1) {
            if (supplier == -1 || amount[i] < amount[supplier]) {
                supplier = i;
            }
        }
    }

    // Display results
    printf("\n===== Supplier Evaluation Results =====\n");
    for (int i = 0; i < numSuppliers; i++) {
        printf("\nSupplier: %s\n", suppName[i]);
        printf("Price: N$ %.2f\n", amount[i]);

        if (qualified[i] == 0) {
            printf("Status: Disqualified\n");
        } else if (i == supplier) {
            printf("Status: Preferred Supplier\n");
        } else {
            printf("Status: Qualified\n");
        }
    }

    return 0;
}