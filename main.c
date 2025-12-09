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
#define HISTORY_FILE "calculator_history.txt"
Record history[MAX_HISTORY];
int history_count = 0;

void save_history() {
    FILE *file = fopen(HISTORY_FILE, "w");
    if (file == NULL) {
        printf("Warning: Could not save history to file.\n");
        return;
    }

    fprintf(file, "%d\n", history_count);
    for (int i = 0; i < history_count; i++) {
        fprintf(file, "%lf %lf %lf %s\n",
            history[i].num1,
            history[i].num2,
            history[i].result,
            history[i].operator);
    }
    fclose(file);
}

void load_history() {
    FILE *file = fopen(HISTORY_FILE, "r");
    if (file == NULL) {
        return;
    }

    int count;
    if (fscanf(file, "%d", &count) != 1) {
        fclose(file);
        return;
    }

    for (int i = 0; i < count && i < MAX_HISTORY; i++) {
        if (fscanf(file, "%lf %lf %lf %s",
            &history[i].num1,
            &history[i].num2,
            &history[i].result,
            history[i].operator) == 4) {
            history_count++;
        }
    }
    fclose(file);
}

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


int main(int argc, char *argv[]) {
    double num1, num2, result;
    int choice;

    if (argc == 3) {
        char *op = argv[1];
        num1 = atof(argv[2]);

        if (strcmp(op, "sqrt") == 0) {
            if (num1 < 0) {
                printf("Error: Cannot calculate square root of negative number!\n");
                return 1;
            }
            result = square_root(num1);
            printf("sqrt(%.2lf) = %.2lf\n", num1, result);
        } else {
            printf("Error: Unknown single-argument operator '%s'\n", op);
            printf("Supported: sqrt\n");
            return 1;
        }
        return 0;
    } else if (argc == 4) {
        num1 = atof(argv[1]);
        num2 = atof(argv[3]);
        char *op = argv[2];
        if (strcmp(op, "+") == 0) {
            result = add(num1, num2);
            printf("%.2lf + %.2lf = %.2lf\n", num1, num2, result);
        } else if (strcmp(op, "-") == 0) {
            result = subtract(num1, num2);
            printf("%.2lf - %.2lf = %.2lf\n", num1, num2, result);
        } else if (strcmp(op, "x") == 0 || strcmp(op, "*") == 0) {
            result = multiply(num1, num2);
            printf("%.2lf x %.2lf = %.2lf\n", num1, num2, result);
        } else if (strcmp(op, "/") == 0) {
            if (num2 == 0) {
                printf("Error: Cannot divide by zero!\n");
                return 1;
            }
            result = divide(num1, num2);
            printf("%.2lf / %.2lf = %.2lf\n", num1, num2, result);
        } else if (strcmp(op, "^") == 0 || strcmp(op, "pow") == 0) {
            result = power(num1, num2);
            printf("%.2lf ^ %.2lf = %.2lf\n", num1, num2, result);
        } else if (strcmp(op, "%") == 0 || strcmp(op, "mod") == 0) {
            if (num2 == 0) {
                printf("Error: Cannot perform modulo with zero!\n");
                return 1;
            }
            result = modulo(num1, num2);
            printf("%.2lf mod %.2lf = %.2lf\n", num1, num2, result);
        } else {
            printf("Error: Unknown operator '%s'\n", op);
            printf("Supported operators: + - x / ^ %% pow mod\n");
            return 1;
        }
        return 0;
    } else if (argc > 1) {
        printf("Usage:\n");
        printf("  %s [num1 operator num2]  - Two operands\n", argv[0]);
        printf("  %s [operator num]        - Single operand\n", argv[0]);
        printf("\nExamples:\n");
        printf("  %s 10 + 20\n", argv[0]);
        printf("  %s 5 x 3\n", argv[0]);
        printf("  %s sqrt 16\n", argv[0]);
        printf("\nSupported operators:\n");
        printf("  Two operands: + - x / ^ %% pow mod\n");
        printf("  Single operand: sqrt\n");
        return 1;
    }

    load_history();


    // Display welcome message
    printf("\n");
    printf("+==========================================+\n");
    printf("|     Command Line Calculator v15.0        |\n");
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
        printf("|  8. Expression Calculator                |\n");
        printf("|  9. View History                         |\n");
        printf("|  10. Clear History                       |\n");
        printf("|  11. Swap           (demo)               |\n");
        printf("|  12. Exit                                |\n");
        printf("+------------------------------------------+\n");
        printf("\n");
        printf("Enter your choice [1-11]: ");

        // Read and validate choice
        if (!safe_read_int(&choice)) {
            printf("\n[X] Error: Please enter a valid number!\n\n");
            continue;
        }

        if (choice == 12) {
            save_history();
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
        if (choice == 11) {
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

        if (choice == 8) {
            expression_calculator();
            return 0;
        }

        // Handle history functions - no need for number input
        if (choice == 9) {
            view_history();
            continue;
        }

        if (choice == 10) {
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
                snprintf(operator_str, sizeof(operator_str), "%s", "+");
                break;

            case 2:
                result = subtract(num1, num2);
                printf("  %.2lf - %.2lf = %.2lf\n", num1, num2, result);
                snprintf(operator_str, sizeof(operator_str), "%s", "-");
                break;

            case 3:
                result = multiply(num1, num2);
                printf("  %.2lf * %.2lf = %.2lf\n", num1, num2, result);
                snprintf(operator_str, sizeof(operator_str), "%s", "*");
                break;

            case 4:
                if (num2 == 0) {
                    printf(" Error: Cannot divide by zero!\n");
                } else {
                    result = divide(num1, num2);
                    snprintf(operator_str, sizeof(operator_str), "%s", "/");
                    printf("  %.2lf / %.2lf = %.2lf\n", num1, num2, result);
                }
                break;

            case 5:
                result = power(num1, num2);
                snprintf(operator_str, sizeof(operator_str), "%s", "^");
                printf("  %.2lf^%.2lf = %.2lf\n", num1, num2, result);
                break;

            case 6:
                if (num1 < 0) {
                    printf("  Error: Cannot calculate square root of negative number!\n");
                } else {
                    result = square_root(num1);
                    num2 =  0;
                    snprintf(operator_str, sizeof(operator_str), "%s", "sqrt");
                    printf("  sqrt(%.2lf) = %.2lf\n", num1, result);
                }
                break;

            case 7:
                if (num2 == 0) {
                    printf("  Error: Cannot perform modulo with zero!\n");
                } else {
                    result = modulo(num1, num2);
                    snprintf(operator_str, sizeof(operator_str), "%s", "%");
                    printf("  %.2lf mod %.2lf = %.2lf\n", num1, num2, result);
                }
                break;
        }

        if (history_count < MAX_HISTORY && strlen(operator_str) > 0) {
            history[history_count].num1 = num1;
            history[history_count].num2 = num2;
            history[history_count].result = result;
            snprintf(history[history_count].operator, sizeof(history[history_count].operator), "%s", operator_str);
            history_count++;
        }

        printf("------------------------------------------\n");
        printf("\n");
    }

    return 0;
}
