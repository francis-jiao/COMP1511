// Created by
//  ... (z0000000)
//  ... (z0000000)
// Created on 2017-08-??
// Tutor's name (dayHH-lab)

#include <stdio.h>
#include <stdlib.h>

#define MAX_LENGTH 1024

void printFirstMiddleLast (int size, int array[MAX_LENGTH]);

// DO NOT CHANGE THIS MAIN FUNCTION
int main (int argc, char *argv[]) {
    // Get the array size.
    int size;
    printf ("Enter array size: ");
    scanf ("%d", &size);

    // Declare the array.
    int array[MAX_LENGTH];

    printf ("Enter array values: ");
    // Intialise the array values.
    int i = 0;
    while (i < size) {
        scanf ("%d", &array[i]);
        i++;
    }

    printFirstMiddleLast (size, array);

    return EXIT_SUCCESS;
}

// Print the first, middle, and last values of an array,
// on separate lines.
void printFirstMiddleLast (int size, int array[MAX_LENGTH]) {
    if(size%2==0) {
        printf("%d\n%d\n%d\n", array[0],array[size/2],array[size-1]);
    } else {
        printf("%d\n%d\n%d\n", array[0],array[(size-1)/2],array[size-1]);
    }
}

