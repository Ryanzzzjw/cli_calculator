/*
 * Command Line Calculator v6.0
 * Input Validation Edition
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

int main() {
    double num1, num2, result;
    int choice;

    // Display welcome message
    printf("\n");
    printf("+==========================================+\n");
    printf("|     Command Line Calculator v6.0        |\n");
    printf("|       Input Validation Edition          |\n");
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
        printf("|  5. Exit                                 |\n");
        printf("+------------------------------------------+\n");
        printf("\nEnter your choice [1-5]: ");

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
        if (choice < 1 || choice > 5) {
            printf("\n[X] Error: Invalid choice! Please select 1-5.\n\n");
            continue;
        }

        // Prompt user for numbers
        printf("\n");

        printf("Enter first number:  ");
        if (!safe_read_double(&num1)) {
            printf("\n[X] Error: Please enter a valid number!\n\n");
            continue;
        }

        printf("Enter second number: ");
        if (!safe_read_double(&num2)) {
            printf("\n[X] Error: Please enter a valid number!\n\n");
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
                    printf("  [X] Error: Cannot divide by zero!\n");
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
