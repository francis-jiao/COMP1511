// Useful array functions
// Created by
//  mingfang Jiao (z5142125)
// Created on 2017-08-??
// Tutor's name (dayHH-lab)

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#define SMALL_ARRAY 5
#define MEDIUM_ARRAY 20
#define LARGE_ARRAY 200

// Display useful facts about the array (changes the array)
void arrayFacts (int size, int array[]);

// Reading and showing arrays
void scanArray (int size, int array[]);
void showArray (int size, int array[]);

// Array functions without side effects
int arrayMax (int size, int array[]);
int arrayMin (int size, int array[]);
int arraySum (int size, int array[]);
int arrayAverage (int size, int array[]);

// Changing the whole array
void arrayAdd (int size, int array[], int num);
void arrayScale (int size, int array[], int num);

int main (int argc, char *argv[]) {

    // Some unit tests on a small array
    int arrayA[SMALL_ARRAY] = {1, 2, 3, 4, 5};
    assert (arrayMin (SMALL_ARRAY, arrayA) == 1);
    assert (arrayMax (SMALL_ARRAY, arrayA) == 5);
    assert (arraySum (SMALL_ARRAY, arrayA) == 15);
    assert (arrayAverage (SMALL_ARRAY, arrayA) == 3);
    arrayAdd (SMALL_ARRAY, arrayA, 1);
    assert (arrayMin (SMALL_ARRAY, arrayA) == 2);
    assert (arrayMax (SMALL_ARRAY, arrayA) == 6);
    assert (arraySum (SMALL_ARRAY, arrayA) == 20);
    assert (arrayAverage (SMALL_ARRAY, arrayA) == 4);

    // Create a medium-sized array to perform more unit tests
    int arrayB[MEDIUM_ARRAY] = {0};
    int b = 0;
    while (b < MEDIUM_ARRAY) {
        arrayB[b] = b * b;
        b++;
    }
    assert (arrayMin (MEDIUM_ARRAY, arrayB) == 0);
    assert (arrayMax (MEDIUM_ARRAY, arrayB) == 361);
    assert (arraySum (MEDIUM_ARRAY, arrayB) == 2470);
    assert (arrayAverage (MEDIUM_ARRAY, arrayB) == 123);
    arrayScale (MEDIUM_ARRAY, arrayB, -2);
    assert (arrayMin (MEDIUM_ARRAY, arrayB) == -722);
    assert (arrayMax (MEDIUM_ARRAY, arrayB) == 0);
    assert (arraySum (MEDIUM_ARRAY, arrayB) == -4940);
    assert (arrayAverage (MEDIUM_ARRAY, arrayB) == -247);

    // Test an array with manual values
    int manualArray[MEDIUM_ARRAY] = {0};
    scanArray (MEDIUM_ARRAY, manualArray);
    arrayFacts (MEDIUM_ARRAY, manualArray);

    printf ("All tests passed. You are Awesome!");

    return EXIT_SUCCESS;
}

// Displays some useful facts about an array
// NOTE: this will change the array that is used
void arrayFacts (int size, int array[]) {
    printf ("The largest value in the array is %d\n",
        arrayMax (size, array));
    printf ("The smallest value in the array is %d\n",
        arrayMin (size, array));
    printf ("The sum of all values in the array is %d\n",
        arraySum (size, array));
    printf ("The average value in the array is %d\n",
        arrayAverage (size, array));

    int s = 0;
    while (s < 5) {
        printf ("The array, with %d added to all elements, "
            "looks like:\n", s);
        arrayAdd (size, array, s);
        showArray (size, array);
        s++;
    }

    printf ("The array, with 10 subtracted from all elements, "
        "looks like:\n");
    arrayAdd (size, array, -10);
    showArray (size, array);

    int m = 1;
    while (m <= 5) {
        printf ("The array, with all elements multiplied by %i, "
            "looks like:\n", m);
        arrayScale (size, array, m);
        showArray (size, array);
        m++;
    }
}

// Read values from the screen, store the values in an array
void scanArray (int size, int array[]) {
    printf ("Enter %d numbers: ", size);
    // ADD YOUR CODE HERE
    int i = 0;
    while (i < size) {
        scanf("%d", &array[i]);
        i++;
    }
}

// Show an array on the screen,
// Should look like [0, 1, 2, 3, 4, 5]
void showArray (int size, int array[]) {
    printf ("[");
    // ADD YOUR CODE HERE
    int i = 0;
    while (i < size) {
        printf("%d", array[i]);
        if (i < size - 1){
            printf(", ");
        }
        i++;
    }
    printf ("]\n");
}

// Returns the largest value in an array
int arrayMax (int size, int array[]) {
    // ADD YOUR CODE HERE
    int max = array[0];
    int i = 1;
    while (i < size) {
        if(array[i]>max) {
            max = array[i];
        }
        i++;
    }
    return max;
}

// Returns the smallest value in the array
int arrayMin (int size, int array[]) {
    // ADD YOUR CODE HERE
    int min = array[0];
    int i = 1;
    while (i < size) {
        if(array[i]<min) {
            min = array[i];
        }
        i++;
    }
    return min;
}

// Returns the sum of all values in the array
int arraySum (int size, int array[]) {
    // ADD YOUR CODE HERE
    int sum = array[0];
    int i = 1;
    while (i < size) {
        sum = sum + array[i];
        i++;
    }
    return sum;
}

// Returns the average of all values in the array
int arrayAverage (int size, int array[]) {
    // ADD YOUR CODE HERE
    int sum = array[0];
    int i = 1;
    while (i < size) {
        sum = sum + array[i];
        i++;
    }
    int average = sum/size;
    return average;
}

// Adds `num` to all values in the array
void arrayAdd (int size, int array[], int num) {
    // ADD YOUR CODE HERE
    scanf("%d", &num);
    int i = 0;
    while (i < size) {
        array[i] = array[i] + num;
        i++;
    }
}

// Multiplies all values in the array by num
void arrayScale (int size, int array[], int num) {
    // ADD YOUR CODE HERE
    scanf("%d", &num);
    int i = 0;
    while (i < size) {
        array[i] = array[i] * num;
        i++;
    }
}
