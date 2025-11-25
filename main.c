#include <stdio.h>
#include <stdlib.h>

int main() {

    double num1, num2, sum;
    // Display welcome message
    printf("================================\n");
    printf("  Command Line Calculator\n");
    printf("================================\n");
    printf("\n");

    // Display version information
    printf("Version: 1.0\n");
    printf("Author: Ryan Zhang\n");
    printf("\n");

    // Prompt user
    printf("Enter first number: \n");
    scanf("%lf", &num1);
    printf("Enter second number: \n");
    scanf("%lf", &num2);

    sum = num1 + num2;
    printf("result: %.2lf + %.2lf = %.2lf\n", num1, num2, sum);
    printf("Press Enter to exit...\n");

    // Wait for user input (pause program)
    getchar();

    printf("\nThank you for using! Goodbye!\n");

    return 0;
}
