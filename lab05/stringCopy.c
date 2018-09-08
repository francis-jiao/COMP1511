// Copy a String
// Created by mingfang jiao z5142125
// Created on 2017-08-??
// Tutor's name (dayHH-lab)

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0
#define BUFFER_LENGTH 64

void stringCopy (char *destination, char *source, int destSize);

int main (int argc, char *argv[]) {
    // Declare a buffer.  In this case, we're declaring and using a
    // 64-byte buffer, but this could be any length you like, and in
    // our tests you will be required to handle arrays of any length.
    char buffer[BUFFER_LENGTH] = {0};

    // Copy a string into the buffer ...
    stringCopy (buffer, "Seventeen bytes.\n", BUFFER_LENGTH);

    // ... and print it out.  The `%s` format code prints a string.
    printf ("<%s>\n", buffer);

    return EXIT_SUCCESS;
}

// Takes a string in `source`, and copies it to `destination`, which
// is `destSize` elements in size; only copies up to `destSize` bytes.
// Ensures the `destination` array is null-terminated.
void stringCopy (char *destination, char *source, int destSize) {
    // Your code goes here!
    int currentPos = 0;
    int hasReachedSourceNullTerminator = 0;
    while(currentPos < destSize && hasReachedSourceNullTerminator == 0) {
        if (source[currentPos]!='\0') {
            destination[currentPos] = source[currentPos];
        } else {
            hasReachedSourceNullTerminator = 1;
        }
        currentPos++;
    }
    destination[destSize -1] = '\0';
    
    // Don't forget to return your result.
}
