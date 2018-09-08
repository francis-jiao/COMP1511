//mingfang jiao z5142125
// favourite number 3
// calculates and displays some information about a user entered integer
// 2017-08-10
// Alex Linker <{a.linker, z5061930}@unsw.edu.au>
// Jashank Jeremy <{jashankj, z5017851}@cse.unsw.edu.au>
// 2017-08-14

#include <stdio.h>
#include <stdlib.h>

#define TRUE  1
#define FALSE 0

#define LAST_TIMES_TABLE 12

// Function prototypes
void printTimesTable(int n);
int factorial(int n);
int isPerfectNumber(int n);

int main (int argc, char *argv[]) {
    // !!! DO NOT CHANGE THIS MAIN FUNCTION !!! \\

    // Gets a user entered number.
    printf ("Enter your favourite number: ");

    // Check to see if a valid integer was entered.
    int num;
    if (scanf ("%d", &num) != 1) {
        printf ("Couldn't read an integer.\n");
        return EXIT_FAILURE;
    }

    // Check to see if the integer was positive.
    if (num < 0) {
        printf ("You didn't enter a positive number.\n");
        return EXIT_SUCCESS;
    }

    // Print out some facts.
    printf ("You entered %d.\n", num);

    // Print their number's factorial.
    int fact = factorial (num);
    printf ("%d! = %d\n", num, fact);
    // Print the times table.
    printTimesTable (num);
    // Print whether the number is a perfect number.
    if(isPerfectNumber (num) == TRUE) {
        printf("%d is a perfect number.\n", num);
    } else {
        printf("%d is not a perfect number.\n",num);
    }
    return EXIT_SUCCESS;
}
// END OF MAIN FUNCTION
// Print the 1-12 times tables of the inputted number.
void printTimesTable (int n) {
    // PUT YOUR CODE HERE
    int times = 1;
    while(times<=LAST_TIMES_TABLE){
        printf("%d x %d = %d\n", times, n, n*times);
        times = times + 1;
    }
}
// Return the factorial of n.
int factorial (int n) {
    // PUT YOUR CODE HERE
    int result = n;
    while(n>1) {
        result = result* (n - 1);
        n = n-1;
    }
    return result; // change this line to your return value
}
// Return TRUE if n is a perfect number, FALSE otherwise.
int isPerfectNumber (int n) {
    // PUT YOUR CODE HERE
    int base = 1;
    int perfectnum = 0;
    if(n == 1){
        return 0;
    } else{
        while(perfectnum<n){
            perfectnum = perfectnum + base;
            base = base + 1;
            while((base<n) && (n%base!=0)){
                base = base + 1;
            }
        }
    }
    if(perfectnum == n){
        return 1; // change this line to your return value
    } else{
        return 0;
    }
}

