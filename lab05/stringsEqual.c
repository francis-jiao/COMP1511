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
    int i=0;
    char c1=stringA[0];
    char c2=stringB[0];
    while(c1 != '\0' && c2 != '\0') {
        if(c1 != c2) {
            return FALSE;
        }
        i++;
        c1=stringA[i];
        c2=stringB[i];
    }
    if(c1== '\0' && c2== '\0') {
        return TRUE;
    }else{
        return FALSE;
    }
    return 0;
}




