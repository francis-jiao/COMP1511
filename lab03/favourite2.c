//mingfang jiao z5142125
// favourite number 2
// alex linker <a.linker@unsw.edu.au>
// calculates and displays some information about a user entered integer

#include <stdio.h>
#include <stdlib.h>

#define MY_FAVE 17

//function prototypes
int square (int n);
void printOddOrEven (int n);
int multiply (int a, int b);
int main (int argc, char *argv[]) {
    //DO NOT CHANGE THIS MAIN FUNCTION

    //gets a user entered number.
    int num;
    printf("Enter your favourite number: ");
    //check to see if a valid integer was entered
    if (scanf("%d", &num) == 0){
        printf ("Error: please enter a integer!\n");
        return EXIT_FAILURE;
    }

    //print out facts
    printf("You entered %d.\n", num);
    //prints double their number
    int dbl = multiply (num, 2);
    printf("%d doubled is %d.\n", num, dbl);
    int sq = square (num);
    printf("%d squared is %d.\n", num, sq);
    //prints their favourite times my favourite
    int total = num * MY_FAVE;
    printf("%d x %d is %d.\n",num,MY_FAVE,total);
    printOddOrEven(num);
    return EXIT_SUCCESS;
}

//this function takes in an integer and returns it squared.
int square (int n) {
    int ans = n*n;
    //ENTER YOUR CODE HERE
    return ans;
}
//this function prints if a number is even or odd
//in the format "n is even."
void printOddOrEven (int n) {
    if(n%2==0) {
        printf("%d is even.\n",n);
    } else {
        printf("%d is odd.\n",n);
    }//ENTER YOUR CODE HERE
}

//this fucntion takes two integers
//and returns the value obtained by
//multiplying them together.
int multiply (int a, int b) {
    int ans= a*b;
    return ans;//ENTER YOUR CODE HERE
}

