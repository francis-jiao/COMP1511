// Calculate the magnitude of a complex number
// By mingfang Jiao (z5142125) Zheng Tong (z5142003)
// Written on 2017-0?-??
// Tutor (dayHH-lab)

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// DO NOT CHANGE THIS STRUCT
typedef struct _complex {
    double real;
    double imaginary;
} complex;

double complexAbsolute(complex c);

// DO NOT CHANGE THIS MAIN FUNCTION
int main (int argc, char *argv[]) {

    // getting the complex number
    complex c;

    printf("Enter the real part: ");
    scanf("%lf", &c.real);

    printf("Enter the imaginary part: ");
    scanf("%lf", &c.imaginary);

    // get the absolute value
    double absoluteValue = complexAbsolute(c);

    // print the value
    printf("The absolute value is %.2lf.\n", absoluteValue);

    return EXIT_SUCCESS;
}
// END OF MAIN FUNCTION

// this function returns the magnitude (absolute value)
// of a complex number
double complexAbsolute(complex c) {
    double value;
    value = sqrt((c.real)*(c.real)+(c.imaginary)*(c.imaginary));
    return value;
}
