#include <stdio.h>

#define MAX_SUPPLIERS 10

int main()
{

    /////TENDER EVALUATION/////
    //Declaring variables   
    char supplierName[MAX_SUPPLIERS][50];
    float price[MAX_SUPPLIERS];
    float budget[MAX_SUPPLIERS];
    int registered[MAX_SUPPLIERS];
    int documentsComplete[MAX_SUPPLIERS];
    int qualified[MAX_SUPPLIERS]; //1 = qualified, 0 = disqualified

    //Declaring other variables
    int numSuppliers;
    int i;
    int preferredIndex = -1; //index of the preferred supplier, -1 if none

    printf("Enter number of suppliers (max %d): ", MAX_SUPPLIERS);
    scanf("%d", &numSuppliers);

    if (numSuppliers <= 0 || numSuppliers > MAX_SUPPLIERS)
    {
        printf("Invalid number of suppliers.\n");
        return 1;
    }

    //Collect data for each supplier
    for (i = 0; i < numSuppliers; i++)
    {
        printf("\n--- Supplier %d ---\n", i + 1);

        printf("Enter supplier name: ");
        scanf("%49s", supplierName[i]);

        printf("Enter tender price: N$ ");
        scanf("%f", &price[i]);

        printf("Enter available budget: N$ ");
        scanf("%f", &budget[i]);

        printf("Is supplier registered? (1=Yes, 0=No): ");
        scanf("%d", &registered[i]);

        printf("Are all documents complete? (1=Yes, 0=No): ");
        scanf("%d", &documentsComplete[i]);
    }

    //Determine qualification status for each supplier
    for (i = 0; i < numSuppliers; i++)
    {
        if (registered[i] == 0 || documentsComplete[i] == 0)
        {
            qualified[i] = 0; // Disqualified
        }
        else if (price[i] > budget[i])
        {
            qualified[i] = 0; // Disqualified
        }
        else
        {
            qualified[i] = 1; // Qualified
        }
    }

    // Find the preferred supplier: qualified supplier with the lowest price
    for (i = 0; i < numSuppliers; i++)
    {
        if (qualified[i] == 1)
        {
            if (preferredIndex == -1 || price[i] < price[preferredIndex])
            {
                preferredIndex = i;
            }
        }
    }

    //Print results
    printf("\n===== Supplier Evaluation Results =====\n");
    for (i = 0; i < numSuppliers; i++)
    {
        printf("\nSupplier: %s\n", supplierName[i]);
        printf("Price: N$ %.2f\n", price[i]);

        if (qualified[i] == 0)
        {
            printf("Status: Disqualified\n");
        }
        else if (i == preferredIndex)
        {
            printf("Status: Preferred Supplier\n");
        }
        else
        {
            printf("Status: Qualified\n");
        }
    }

    return 0;
}