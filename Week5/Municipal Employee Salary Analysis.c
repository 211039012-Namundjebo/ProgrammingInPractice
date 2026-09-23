  #include <stdio.h>

#define EMPLOYEES 50

int main() {
    float salary;
    float total = 0;
    float highest = 0;
    float lowest = 0;
    float average;

    printf("=== Municipal Employee Salary Analysis ===\n\n");

    // Collect the salary for each employee
    for (int i = 1; i <= EMPLOYEES; i++) {
        printf("Enter salary for employee %d: ", i);
        scanf("%f", &salary);

        // Accumulate the total salary
        total += salary;

        // Initialize the highest and lowest salary variables with the first entry
        if (i == 1) {
            highest = salary;
            lowest = salary;
        }

        // Update the highest salary if the current salary is greater
        if (salary > highest) {
            highest = salary;
        }

        // Update the lowest salary if the current salary is less
        if (salary < lowest) {
            lowest = salary;
        }
    }

    // Compute the average salary
    average = total / EMPLOYEES;

    // Output the salary report
    printf("\n--- Salary Report ---\n");
    printf("Number of employees: %d\n", EMPLOYEES);
    printf("Total salary:   %.2f\n", total);
    printf("Average salary: %.2f\n", average);
    printf("Highest salary: %.2f\n", highest);
    printf("Lowest salary:  %.2f\n", lowest);

    return 0;
}