// Convert a character to uppercase.
// Created by ... (z0000000)
// Created on 2017-08-??
// Tutor's name (dayHH-lab)

#include <stdio.h>
#include <stdlib.h>

char uppercase (char c);

// DO NOT CHANGE THIS MAIN FUNCTION
int main (int argc, char *argv[]) {

    // Get the character
    int c = getchar ();

    // Loop until end of characters
    while (c != EOF) {
        // print the character in uppercase
        putchar (uppercase (c));

        // get the next character
        c = getchar ();
    }

    return EXIT_SUCCESS;
}
// END OF MAIN FUNCTION

char uppercase (char c) {
    if(c>='a' && c<='z') {
        return c-32;
    } else {
        return c;
    }
}
