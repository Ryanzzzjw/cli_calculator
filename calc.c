/*
 * Calculator Implementation File
 * Contains the actual implementation of calculation functions
 */

#include <stdio.h>
#include "calc.h"
#include <math.h>

/*
 * Addition function
 * Returns the sum of two numbers
 */
double add(double a, double b) {
    return a + b;
}

/*
 * Subtraction function
 * Returns the difference of two numbers
 */
double subtract(double a, double b) {
    return a - b;
}

/*
 * Multiplication function
 * Returns the product of two numbers
 */
double multiply(double a, double b) {
    return a * b;
}

/*
 * Division function
 * Returns the quotient of two numbers
 * Note: Division by zero check is handled in main.c
 */
double divide(double a, double b) {
    return a / b;
}

/*
 * Swap function (pass by reference) - correct implementation using pointers
 * Swaps the values of two double variables using pointer parameters
 */
void swap(double *a, double *b) {
    double temp = *a;
    *a = *b;
    *b = temp;
    printf("  [Inside swap] *a = %.2lf, *b = %.2lf\n", *a, *b);
}

/*
 * Power function
 * Calculates base raised to the power of exponent (base^exponent)
 */
double power(double base, double exponent) {
    return pow(base, exponent);
}

/*
 * Square root function
 * Returns the square root of a number
 * Note: Negative number check is handled in main.c
 */
double square_root(double number) {
    return sqrt(number);
}

/*
 * Floating-point modulo function
 * Returns the remainder of a / b for floating-point numbers
 * Note: Division by zero check is handled in main.c
 */
double modulo(double a, double b) {
    return fmod(a, b);
}
