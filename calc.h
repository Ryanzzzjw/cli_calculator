/*
 * Calculator Header File
 * Function declarations for calculator operations
 */

#ifndef CALC_H
#define CALC_H

// Basic arithmetic operations
double add(double a, double b);
double subtract(double a, double b);
double multiply(double a, double b);
double divide(double a, double b);

// Pointer demonstration functions
void swap(double *a, double *b);

// Scientific calculator functions
double power(double base, double exponent);
double square_root(double number);
double modulo(double a, double b);

void expression_calculator(void);

// History record structure
typedef struct {
    double num1;
    double num2;
    double result;
    char operator[10];
} Record;


#endif  // CALC_H
