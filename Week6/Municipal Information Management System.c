#include <stdio.h>
#include <string.h>
 
#define NUM_SALARIES       50
#define NUM_BUDGETS        10
#define NUM_REGISTRATIONS  20
#define REG_LENGTH         20
 
int main() {
 

    ///PART A: EMPLOYEE SALARIES */
    
    float salaries[NUM_SALARIES];
    float salaryTotal = 0;
    float salaryAverage;
    float highestSalary;
    float lowestSalary;
    float searchSalary;
    int salaryFound = 0;
 
    printf("==============================================\n");
    printf("  PART A: EMPLOYEE SALARIES\n");
    printf("==============================================\n\n");
 
    ///Capture 50 salaries */
    for (int i = 0; i < NUM_SALARIES; i++) {
        printf("Enter salary for employee %d: ", i + 1);
        scanf("%f", &salaries[i]);
    }
 
    ///Display all salaries */
    printf("\n--- All Employee Salaries ---\n");
    for (int i = 0; i < NUM_SALARIES; i++) {
        printf("Employee %2d: %.2f\n", i + 1, salaries[i]);
    }
 
    ///Calculate total, average, highest and lowest.The first element initialises highest and lowest. */
    highestSalary = salaries[0];
    lowestSalary = salaries[0];
 
    for (int i = 0; i < NUM_SALARIES; i++) {
        salaryTotal = salaryTotal + salaries[i];
 
        if (salaries[i] > highestSalary) {
            highestSalary = salaries[i];
        }
        if (salaries[i] < lowestSalary) {
            lowestSalary = salaries[i];
        }
    }
    salaryAverage = salaryTotal / NUM_SALARIES;
 
    printf("\n--- Salary Summary ---\n");
    printf("Average salary: %.2f\n", salaryAverage);
    printf("Highest salary: %.2f\n", highestSalary);
    printf("Lowest salary:  %.2f\n", lowestSalary);
 
    ///Search for a particular salary (linear search).
    
    printf("\nEnter a salary to search for: ");
    scanf("%f", &searchSalary);
 
    for (int i = 0; i < NUM_SALARIES; i++) {
        if (salaries[i] == searchSalary) {
            printf("Salary %.2f found at position %d (employee %d).\n",
                   searchSalary, i, i + 1);
            salaryFound = 1;
        }
    }
    if (!salaryFound) {
        printf("Salary %.2f not found.\n", searchSalary);
    }
 
    ///PART B: DEPARTMENT BUDGETS */
    float budgets[NUM_BUDGETS];
    float budgetTotal = 0;
    float budgetAverage;
    float temp;
 
    printf("\n==============================================\n");
    printf("  PART B: DEPARTMENT BUDGETS\n");
    printf("==============================================\n\n");
 
    ///Capture 10 department budgets */
    for (int i = 0; i < NUM_BUDGETS; i++) {
        printf("Enter budget for department %d: ", i + 1);
        scanf("%f", &budgets[i]);
    }
 
    ///Display the budgets */
    printf("\n--- Department Budgets (as entered) ---\n");
    for (int i = 0; i < NUM_BUDGETS; i++) {
        printf("Department %2d: %.2f\n", i + 1, budgets[i]);
    }
 
    ///Calculate the total and average budget */
    for (int i = 0; i < NUM_BUDGETS; i++) {
        budgetTotal = budgetTotal + budgets[i];
    }
    budgetAverage = budgetTotal / NUM_BUDGETS;
 
    printf("\nTotal budget:   %.2f\n", budgetTotal);
    printf("Average budget: %.2f\n", budgetAverage);
 
    ///Sort budgets from lowest to highest (bubble sort) */
    for (int i = 0; i < NUM_BUDGETS - 1; i++) {
        for (int j = 0; j < NUM_BUDGETS - i - 1; j++) {
            if (budgets[j] > budgets[j + 1]) {
                temp = budgets[j];
                budgets[j] = budgets[j + 1];
                budgets[j + 1] = temp;
            }
        }
    }
 
    printf("\n--- Budgets Sorted (Lowest to Highest) ---\n");
    for (int i = 0; i < NUM_BUDGETS; i++) {
        printf("%2d. %.2f\n", i + 1, budgets[i]);
    }
 
    ///PART C: VEHICLE REGISTRATION NUMBERS */
    
    char registrations[NUM_REGISTRATIONS][REG_LENGTH];
    char searchReg[REG_LENGTH];
    int regFound = 0;
 
    printf("\n==============================================\n");
    printf("  PART C: VEHICLE REGISTRATION NUMBERS\n");
    printf("==============================================\n\n");
 
    ///Capture 20 registration numbers (no spaces; max 19 characters) */
    for (int i = 0; i < NUM_REGISTRATIONS; i++) {
        printf("Enter vehicle registration %d: ", i + 1);
        scanf("%19s", registrations[i]);
    }
 
    ///Display all registration numbers */
    
    printf("\n--- Vehicle Registrations ---\n");
    for (int i = 0; i < NUM_REGISTRATIONS; i++) {
        printf("%2d. %s\n", i + 1, registrations[i]);
    }
 
    ///Search for a particular registration number. */
    
    printf("\nEnter a registration number to search for: ");
    scanf("%19s", searchReg);
 
    for (int i = 0; i < NUM_REGISTRATIONS; i++) {
        if (strcmp(registrations[i], searchReg) == 0) {
            printf("Registration %s found at position %d.\n", searchReg, i + 1);
            regFound = 1;
            break;
        }
    }
    if (!regFound) {
        printf("Registration %s not found.\n", searchReg);
    }
 
    return 0;
}
