#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
    double num1, num2, result;
    int choice;

    // Display welcome message
    printf("\n");
    printf("╔════════════════════════════════════════╗\n");
    printf("║     Command Line Calculator v5.0      ║\n");
    printf("║         Loop System Edition            ║\n");
    printf("╚════════════════════════════════════════╝\n");
    printf("\n");
    printf("Author: Ryan Zhang\n");
    printf("\n");

    while (true) {
        // Display operation menu
        printf("┌────────────────────────────────────────┐\n");
        printf("│  Please select an operation:           │\n");
        printf("├────────────────────────────────────────┤\n");
        printf("│  1. Addition       (+)                 │\n");
        printf("│  2. Subtraction    (-)                 │\n");
        printf("│  3. Multiplication (*)                 │\n");
        printf("│  4. Division       (/)                 │\n");
        printf("│  5. Exit                               │\n");
        printf("└────────────────────────────────────────┘\n");
        printf("\nEnter your choice [1-5]: ");
        scanf("%d", &choice);

        if (choice == 5) {
            printf("\n");
            printf("╔════════════════════════════════════════╗\n");
            printf("║  Thank you for using Calculator!       ║\n");
            printf("║  Goodbye! 👋                           ║\n");
            printf("╚════════════════════════════════════════╝\n");
            printf("\n");
            break;
        }

        // Validate choice
        if (choice < 1 || choice > 5) {
            printf("\n❌ Error: Invalid choice! Please select 1-5.\n\n");
            continue;
        }

        // Prompt user for numbers
        printf("\n");
        printf("Enter first number:  ");
        scanf("%lf", &num1);
        printf("Enter second number: ");
        scanf("%lf", &num2);

        // Perform calculation based on user choice
        printf("\n");
        printf("─────────────────────────────────────────\n");

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
                printf("  %.2lf × %.2lf = %.2lf\n", num1, num2, result);
                break;

            case 4:
                if (num2 == 0) {
                    printf("  ❌ Error: Cannot divide by zero!\n");
                } else {
                    result = num1 / num2;
                    printf("  %.2lf ÷ %.2lf = %.2lf\n", num1, num2, result);
                }
                break;
        }

        printf("─────────────────────────────────────────\n");
        printf("\n");
    }

    return 0;
}
