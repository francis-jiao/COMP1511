// convert a string to lowercase
// Created by
// mingfang Jiao z5142125
// Created on 2017-08-??
// Tutor's name (dayHH-lab)

#include <stdio.h>
#include <stdlib.h>

void stringToLower (char *buffer);

int main (int argc, char *argv[]) {
    /// THIS WON'T WORK!
    ///
    /// `str` only points to a string literal, which is stored in a
    /// read only section of the program.  If you attempt to modify
    /// it, your program will crash with a memory error (usually,
    /// SIGSEGV, the infamous "segmentation fault").
    //
    // char *str = "Hello!"
    // stringToLower (str)

    char str[] = "Seventeen...  SEVENTEEN, I SAY!";
    stringToLower (str);
    printf ("%s\n", str);

    return EXIT_SUCCESS;
}

// Takes a string in `buffer`, and lowercases it.
void stringToLower (char *buffer) {
    // YOUR CODE GOES HERE!
    int currentPos=0;
    while (buffer[currentPos]!='\0') {
        if (buffer[currentPos]>='A' && buffer[currentPos]<='Z') {
            buffer[currentPos]=buffer[currentPos]+32;
        }
        currentPos++;
    }
}
