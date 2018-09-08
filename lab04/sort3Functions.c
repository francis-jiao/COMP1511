//mingfang Jiao z5142125
// Alex Linker 2017-08-13
// Read in three numbers, and print them out in sorted order, using functions.

#include <stdio.h>
#include <stdlib.h>

// Function prototypes
int min2(int a, int b);
int max2(int a, int b);
int min3(int a, int b, int c);
int mid3(int a, int b, int c);
int max3(int a, int b, int c);

// DO NOT CHANGE THIS MAIN FUNCTION
int main (int argc, char *argv[]) {
    // Get the user-inputted numbers.
    int a, b, c;
    printf("Enter 3 numbers: ");
    scanf("%d %d %d", &a, &b, &c);
    
    // Print the minimum (smallest) number.
    printf("%d\n", min3(a, b, c));
    // Print the middle number.
    printf("%d\n", mid3(a, b, c));
    // Print the maximum (biggest) number.
    printf("%d\n", max3(a, b, c));
    
    return EXIT_SUCCESS;
}

// END OF MAIN FUNCTION

// Return the smallest value out of a and b.
int min2(int a, int b) {
    int min2;
    if (a > b) {
        min2 = b;
    }else {
        min2 = a;
    }
    return min2;
}
// CHANGE THIS LINE TO YOUR RETURN VALUE

// Return the largest value out of a and b.
int max2(int a, int b) {
    int max2;
    if (a > b) {
        max2 = a;
    } else {
        max2 = b;
    }
    return max2;
}


// Return the smallest value out of a, b, and c.
int min3(int a, int b, int c) {
    int min3;
    if (a<=b && a<=c) {
        min3 = a;
    }else if(b<a && b<=c) {
        min3 = b;
    } else {
        min3 = c;
    }
    return min3;
}

// Return the middle/median value out of a, b, and c.
int mid3(int a, int b, int c) {
    int mid3;
    if ((a<=b && a>=c) || (a<=c && a>=b)){
        mid3 = a;
    } else if((b<a && b>=c) || (b<=c && b>a)) {
        mid3 = b;
    } else {
        mid3 = c;
    }
    return mid3;
}
        

// Return the largest value out of a, b, and c.
int max3(int a, int b, int c) {
    int max3;
    if (a>=b && a>=c) {
        max3 = a;
    } else if(b>a && b>=c) {
        max3 = b ;
    } else {
        max3 = c;
    }
    return max3;
}



