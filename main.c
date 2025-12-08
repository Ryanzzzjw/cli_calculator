/*
 * Command Line Calculator v7.0
 * Pointer Basics Edition
 * Author: Ryan Zhang
 */

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

/*
 * Safely read an integer from stdin using fgets + sscanf
 * Returns: 1 on success, 0 on failure
 */
int safe_read_int(int *value) {
    char buffer[100];
    if (fgets(buffer, sizeof(buffer), stdin) == NULL) {
        return 0;
    }
    if (sscanf(buffer, "%d", value) != 1) {
        return 0;
    }
    return 1;
}

/*
 * Safely read a double from stdin using fgets + sscanf
 * Returns: 1 on success, 0 on failure
 */
int safe_read_double(double *value) {
    char buffer[100];
    if (fgets(buffer, sizeof(buffer), stdin) == NULL) {
        return 0;
    }
    if (sscanf(buffer, "%lf", value) != 1) {
        return 0;
    }
    return 1;
}

/*
 * Swap function (pass by value) - demonstrates why this doesn't work
 * This function swaps local copies, not the original variables
 */
void swap_wrong(double a, double b) {
    double temp;
    temp = a;
    a = b;
    b = temp;
    printf("  [Inside swap_wrong] a = %.2lf, b = %.2lf\n", a, b);
}

/*
 * Swap function (pass by reference) - correct implementation using pointers
 * Swaps the values of two double variables using pointer parameters
 */
void swap(double *a, double *b) {
    double temp;
    temp = *a;
    *a = *b;
    *b = temp;
    printf("  [Inside swap] *a = %.2lf, *b = %.2lf\n", *a, *b);
}

int main() {
    double num1, num2, result;
    int choice;

    // Display welcome message
    printf("\n");
    printf("+==========================================+\n");
    printf("|     Command Line Calculator v7.0        |\n");
    printf("|        Pointer Basics Edition           |\n");
    printf("+==========================================+\n");
    printf("\n");
    printf("Author: Ryan Zhang\n");
    printf("\n");

    while (true) {
        // Display operation menu
        printf("+------------------------------------------+\n");
        printf("|  Please select an operation:             |\n");
        printf("+------------------------------------------+\n");
        printf("|  1. Addition       (+)                   |\n");
        printf("|  2. Subtraction    (-)                   |\n");
        printf("|  3. Multiplication (*)                   |\n");
        printf("|  4. Division       (/)                   |\n");
        printf("|  6. Swap Demo      (Pointer)             |\n");
        printf("|  5. Exit                                 |\n");
        printf("+------------------------------------------+\n");
        printf("\nEnter your choice [1-6]: ");

        // Read and validate choice
        if (!safe_read_int(&choice)) {
            printf("\n[X] Error: Please enter a valid number!\n\n");
            continue;
        }

        if (choice == 5) {
            printf("\n");
            printf("+==========================================+\n");
            printf("|  Thank you for using Calculator!        |\n");
            printf("|  Goodbye!                               |\n");
            printf("+==========================================+\n");
            printf("\n");
            break;
        }

        // Validate choice range
        if (choice < 1 || choice > 6) {
            printf("\n[X] Error: Invalid choice! Please select 1-6.\n\n");
            continue;
        }

        // Handle swap demo - demonstrates pointer usage
        if (choice == 6) {
            double x = 10.5;
            double y = 20.8;

            printf("\n");
            printf("========================================\n");
            printf("  Pointer Demo: Swap Function\n");
            printf("========================================\n");
            printf("\n");

            // Display initial values
            printf("Initial values:\n");
            printf("  x = %.2lf, y = %.2lf\n", x, y);
            printf("\n");

            // Test pass by value (doesn't work)
            printf("Test 1: swap_wrong(x, y) - Pass by value\n");
            swap_wrong(x, y);
            printf("  [After call] x = %.2lf, y = %.2lf\n", x, y);
            printf("  Values NOT swapped!\n");
            printf("\n");

            // Test pass by reference (works correctly)
            printf("Test 2: swap(&x, &y) - Pass by reference\n");
            swap(&x, &y);
            printf("  [After call] x = %.2lf, y = %.2lf\n", x, y);
            printf("  Values successfully swapped!\n");
            printf("\n");

            // Display memory addresses
            printf("Memory addresses:\n");
            printf("  Address of x: %p\n", (void*)&x);
            printf("  Address of y: %p\n", (void*)&y);
            printf("\n");

            printf("========================================\n");
            printf("\n");
            continue;
        }

        // Prompt user for numbers
        printf("\n");

        printf("Enter first number:  ");
        if (!safe_read_double(&num1)) {
            printf("\nError: Please enter a valid number!\n\n");
            continue;
        }

        printf("Enter second number: ");
        if (!safe_read_double(&num2)) {
            printf("\nError: Please enter a valid number!\n\n");
            continue;
        }

        // Perform calculation based on user choice
        printf("\n");
        printf("------------------------------------------\n");

        switch (choice) {
            case 1:
                result = num1 + num2;
                printf("  %.2lf + %.2lf = %.2lf\n", num1, num2, result);
                break;

            case 2:
                result = num1 - num2;
                printf("  %.2lf - %.2lf = %.2lf\n", num1, num2, result);
                break;

            case 3:
                result = num1 * num2;
                printf("  %.2lf * %.2lf = %.2lf\n", num1, num2, result);
                break;

            case 4:
                if (num2 == 0) {
                    printf(" Error: Cannot divide by zero!\n");
                } else {
                    result = num1 / num2;
                    printf("  %.2lf / %.2lf = %.2lf\n", num1, num2, result);
                }
                break;
        }

        printf("------------------------------------------\n");
        printf("\n");
    }

    return 0;
}
