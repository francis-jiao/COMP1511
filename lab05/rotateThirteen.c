// Perform the ROT13 algorithm on a string
// Completed by
//  mingfang Jiao z5142125
// Commpleted on 2017-08-??
// Tutor's name (dayHH-lab)

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#define FALSE 0
#define TRUE (!FALSE)
#define MAX_LENGTH 256

// Add your own #defines here

void rotateThirteen (char *string);
char rotateOne (char c);
int stringLength (char *string);
int stringsEqual (char *stringA, char *stringB);

// Add your own function porototypes here

int main (int argc, char *argv[]) {
    // Example tests
    char testA[MAX_LENGTH] = "Hello, world!";
    rotateThirteen (testA);
    assert (stringsEqual ("Uryyb, jbeyq!", testA));

    char testB[MAX_LENGTH] = "abcdefghijklmnopqrstuvwxyz";
    rotateThirteen (testB);
    assert (stringsEqual ("nopqrstuvwxyzabcdefghijklm", testB));

    char testC[MAX_LENGTH] = "The quick brown fox jumped over the lazy dog.";
    rotateThirteen (testC);
    assert (stringsEqual ("Gur dhvpx oebja sbk whzcrq bire gur ynml qbt.",
    testC));

    // Add your own tests here

    printf ("All tests passed. You are awesome!\n");

    return EXIT_SUCCESS;
}

void rotateThirteen (char *string) {
    // YOUR CODE HERE
    // See: https://en.wikipedia.org/wiki/ROT13
    int currentPos = 0;
    while(currentPos < stringLength(string)){
        if(string[currentPos]>=97 && string[currentPos]<=109){
            string[currentPos] = string[currentPos]+13;
        } else if(string[currentPos]>=110 && string[currentPos]<=122){
            string[currentPos] = string[currentPos]-13;
        } else if(string[currentPos]>=65 && string[currentPos]<=77){
            string[currentPos] = string[currentPos]+13;
        } else if(string[currentPos]>=78 && string[currentPos]<=90){
            string[currentPos] = string[currentPos]-13;
        }
        currentPos++;
    }
}

char rotateOne (char c) {
    // Use your code from the rotateOne warm up here
    if(c>='a' && c<='y'){
        c = c + 1;
    } else if(c=='z'){
        c = 'a';
    } else if(c>='A' && c<='Y'){
        c = c + 1;
    } else if(c=='Z'){
        c ='A';
    }
    // Don't forget to return your result.
    return c;
}

int stringLength (char *string) {
    // Use your code from the stringLength activity here
    int i = 0;
    while (string[i] != '\0') {
        i++;
    }
    // Don't forget to return your result.
    return i;
}

int stringsEqual (char *stringA, char *stringB) {
    // Use your code from the stringsEqual activity here
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
