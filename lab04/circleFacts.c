//Mingfang Jiao z5142125
// Alex Linker 2017-08-13
// This program print out facts about a circle given its radius,
// using functions.

#include <stdio.h>
#include <stdlib.h>

#define PI 3.14

// Function prototypes
double area(double radius);
double circumference(double radius);
double diameter(double radius);

// DO NOT CHANGE THIS MAIN FUNCTION
int main (int argc, char *argv[]) {
    // Get the radius
    double radius;
    printf("Enter the radius: ");
    scanf("%lf", &radius);
    
    // Print the area to 2 decimal places.
    printf("Area          = %.2lf\n", area(radius));
    // Print the circumference to 2 decimal places.
    printf("Circumference = %.2lf\n", circumference(radius));
    // Print diameter to 2 decimal places.
    printf("Diameter      = %.2lf\n", diameter(radius));
    
    return EXIT_SUCCESS;
}

// END OF MAIN FUNCTION

// Calculate the area of a circle, given the radius.
double area(double radius) {
    return PI*radius*radius;
}

// Calculate the circumference of a circle, given the radius.
double circumference(double radius) {
    // PUT YOUR CODE HERE

    return PI*radius*2; // CHANGE THIS LINE TO YOUR RETURN VALUE
}

// Calculate the diameter of a circle, given the radius.
double diameter(double radius) {
    // PUT YOUR CODE HERE

    return 2*radius; // CHANGE THIS LINE TO YOUR RETURN VALUE
}

