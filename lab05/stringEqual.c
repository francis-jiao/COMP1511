// String Equality
// Created by
//  mingfang Jiao z5142125
// Created on 2017-08-??
// Tutor's name (dayHH-lab)

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#define TRUE (1 == 1)
#define FALSE (! TRUE)

int stringsEqual (char *stringA, char *stringB);

int main (int argc, char *argv[]) {
    // Some simple assert-based tests.
    // You probably want to write some more.
    assert (stringsEqual ("", "") == TRUE);
    assert (stringsEqual (" ", "") == FALSE);
    assert (stringsEqual ("", " ") == FALSE);
    assert (stringsEqual (" ", " ") == TRUE);
    assert (stringsEqual ("\n", "\n") == TRUE);
    assert (stringsEqual ("This is 17 bytes.", "") == FALSE);
    assert (stringsEqual ("", "This is 17 bytes.") == FALSE);
    assert (stringsEqual ("This is 17 bytes.", "This is 17 bytes.") == TRUE);
    assert (stringsEqual ("Here are 18 bytes!", "This is 17 bytes.") == FALSE);

    printf ("All tests passed.  You are awesome!\n");

    return EXIT_SUCCESS;
}

// Takes two strings, and if they are the same,
// returns TRUE, or FALSE otherwise.
int stringsEqual (char *stringA, char *stringB) {
    // Your code goes here!
    // Don't forget to return your result.
    //Assume they are the same, until prove otherwise
    
    int areStringsIdentical = TRUE;
    int currentPos = 0;
    int areSameLength = FALSE;
    int shouldBreak = FALSE;
    
    // Check if the strings have same length
    while (shouldBreak == FALSE) {
        if (stringA[currentPos] == '\0' && stringB[currentPos] == '\0') {
            areSameLength = TRUE;
            shouldBreak = TRUE;
        } else if (stringA[currentPos] =='\0') {
            areSameLength = FALSE;
            shouldBreak = TRUE;
                        
        } else if (stringB[currentPos] == '\0') {
            areSameLength = FALSE;
            shouldBreak = TRUE;
        }
        currentPos++;
    }
    // check if the strings that have same length are identical
    int arrLength = currentPos;
    currentPos = 0;
    if (areSameLength == TRUE) {
        while (currentPos < arrLength && areStringsIdentical == TRUE) {
            if(stringA[currentPos] != stringB[currentPos]){
                areStringsIdentical = FALSE;
            }
            currentPos++;
        }
    }
    
    int areStringsEqual = FALSE;
    if (areStringsIdentical == TRUE && areSameLength == TRUE) {
        areStringsEqual = TRUE;
    }
    
    return areStringsEqual;
}
