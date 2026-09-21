#include <stdio.h>
 
#define EMPLOYEES 50
 
int main() {
    float salary;
    float total = 0;
    float highest = 0;
    float lowest = 0;
    float average;
 
    printf("=== Municipal Employee Salary Analysis ===\n\n");
 
    ///Capture the salary of each employee */
    for (int i = 1; i <= EMPLOYEES; i++) {
        printf("Enter salary for employee %d: ", i);
        scanf("%f", &salary);
 
        ///Keep a running total */
        total = total + salary;
 
     ///The first salary initialises both highest and lowest,so every later salary is compared against real data. */
        if (i == 1) {
            highest = salary;
            lowest = salary;
        }
 
        ///Determine the highest salary */
        if (salary > highest) {
            highest = salary;
        }
 
        ///Determine the lowest salary */
        if (salary < lowest) {
            lowest = salary;
        }
    }
 
    ///Calculate the average salary */
    average = total / EMPLOYEES;
 
    ///Display the results */
    printf("\n--- Salary Report ---\n");
    printf("Number of employees: %d\n", EMPLOYEES);
    printf("Total salary:   %.2f\n", total);
    printf("Average salary: %.2f\n", average);
    printf("Highest salary: %.2f\n", highest);
    printf("Lowest salary:  %.2f\n", lowest);
 
    return 0;
}
