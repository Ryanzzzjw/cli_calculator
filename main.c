/*
 * Command Line Calculator v9.0
 * Scientific Calculator Edition
 * Author: Ryan Zhang
 */

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "calc.h"

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

// History management
#define MAX_HISTORY 100
Record history[MAX_HISTORY];
int history_count = 0;

void view_history() {
     if (history_count == 0) {
             printf("\nNo calculation history yet.\n\n");
             return;
        }
    printf("\n");
     printf("========================================\n");
     printf("  Calculation History\n");
     printf("========================================\n");
     printf("\n");

     for (int i = 0; i < history_count; i++) {
             if (strcmp(history[i].operator, "sqrt") == 0) {
                 printf("%d. sqrt %.2lf = %.2lf\n",
                        i + 1,
                        history[i].num1,
                        history[i].result);
             } else {
                 printf("%d. %.2lf %s %.2lf = %.2lf\n",
                        i + 1,
                        history[i].num1,
                        history[i].operator,
                        history[i].num2,
                        history[i].result);
             }
         }
     printf("\n");
     printf("========================================\n");
     printf("\n");
}

void clear_history() {
     history_count = 0;
     printf("\nHistory cleared successfully!\n\n");
}


int main() {
    double num1, num2, result;
    int choice;

    // Display welcome message
    printf("\n");
    printf("+==========================================+\n");
    printf("|     Command Line Calculator v9.0        |\n");
    printf("|    Scientific Calculator Edition        |\n");
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
        printf("|  5. Power          (x^y)                 |\n");
        printf("|  6. Square Root    (sqrt(x))             |\n");
        printf("|  7. Modulo         (x mod y)             |\n");
        printf("|  8. View History                         |\n");
        printf("|  9. Clear History                        |\n");
        printf("|  10. Swap           (demo)               |\n");
        printf("|  11. Exit                                |\n");
        printf("+------------------------------------------+\n");
        printf("\n");
        printf("Enter your choice [1-11]: ");

        // Read and validate choice
        if (!safe_read_int(&choice)) {
            printf("\n[X] Error: Please enter a valid number!\n\n");
            continue;
        }

        if (choice == 11) {
            printf("\n");
            printf("+==========================================+\n");
            printf("|  Thank you for using Calculator!        |\n");
            printf("|  Goodbye!                               |\n");
            printf("+==========================================+\n");
            printf("\n");
            break;
        }

        // Validate choice range
        if (choice < 1 || choice > 11) {
            printf("\n[X] Error: Invalid choice! Please select 1-9.\n\n");
            continue;
        }

        // Handle swap demo - demonstrates pointer usage
        if (choice == 10) {
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

            // Test pass by reference (works correctly)
            printf("Test: swap(&x, &y) - Pass by reference\n");
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

        // Handle history functions - no need for number input
        if (choice == 8) {
            view_history();
            continue;
        }

        if (choice == 9) {
            clear_history();
            continue;
        }

        // Prompt user for numbers
        printf("\n");

        // Square root only needs one number
        if (choice == 6) {
            printf("Enter number:  ");
            if (!safe_read_double(&num1)) {
                printf("\nError: Please enter a valid number!\n\n");
                continue;
            }
        } else {
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
        }

        // Perform calculation based on user choice
        printf("\n");
        printf("------------------------------------------\n");

        char operator_str[10] = "";

        switch (choice) {
            case 1:
                result = add(num1, num2);
                printf("  %.2lf + %.2lf = %.2lf\n", num1, num2, result);
                strcpy(operator_str, "+");
                break;

            case 2:
                result = subtract(num1, num2);
                printf("  %.2lf - %.2lf = %.2lf\n", num1, num2, result);
                strcpy(operator_str, "-");
                break;

            case 3:
                result = multiply(num1, num2);
                printf("  %.2lf * %.2lf = %.2lf\n", num1, num2, result);
                strcpy(operator_str, "*");
                break;

            case 4:
                if (num2 == 0) {
                    printf(" Error: Cannot divide by zero!\n");
                } else {
                    result = divide(num1, num2);
                    strcpy(operator_str, "/");
                    printf("  %.2lf / %.2lf = %.2lf\n", num1, num2, result);
                }
                break;

            case 5:
                result = power(num1, num2);
                strcpy(operator_str, "^");
                printf("  %.2lf^%.2lf = %.2lf\n", num1, num2, result);
                break;

            case 6:
                if (num1 < 0) {
                    printf("  Error: Cannot calculate square root of negative number!\n");
                } else {
                    result = square_root(num1);
                    num2 =  0;
                    strcpy(operator_str, "sqrt");
                    printf("  sqrt(%.2lf) = %.2lf\n", num1, result);
                }
                break;

            case 7:
                if (num2 == 0) {
                    printf("  Error: Cannot perform modulo with zero!\n");
                } else {
                    result = modulo(num1, num2);
                    strcpy(operator_str, "%");
                    printf("  %.2lf mod %.2lf = %.2lf\n", num1, num2, result);
                }
                break;
        }

        if (history_count < MAX_HISTORY && strlen(operator_str) > 0) {
            history[history_count].num1 = num1;
            history[history_count].num2 = num2;
            history[history_count].result = result;
            strcpy(history[history_count].operator, operator_str);

            history_count++;

        }

        printf("------------------------------------------\n");
        printf("\n");
    }

    return 0;
}
