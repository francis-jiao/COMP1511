// Displaying arrays as text
// Create by
// mingfang Jiao z5142125
// Created on 2017-08-??
// Tutor's name (dayHH-lab)

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#define ENOUGH_SPACE 100

void showLetters (int size, char letters[]);

int main (int argc, char *argv[]) {

    char lettersA[13] = {0};
    lettersA[0] = 72;
    lettersA[1] = 101;
    lettersA[2] = 108;
    lettersA[3] = 108;
    lettersA[4] = 111;
    lettersA[5] = 44;
    lettersA[6] = 32;
    lettersA[7] = 119;
    lettersA[8] = 111;
    lettersA[9] = 114;
    lettersA[10] = 108;
    lettersA[11] = 100;
    lettersA[12] = 33;
    showLetters (13, lettersA);

    putchar ('\n');

    char lettersB[13] = {
        84,  101, 115, 116,
        32,  109, 101, 115,
        115, 97,  103, 101,
        46
    };
    showLetters (13, lettersB);

    putchar ('\n');

    char lettersC[11] = {
        's', 'a', 'm', 'p', 'l', 'e',
        ' ', 't', 'e', 'x', 't'
    };
    showLetters (11, lettersC);

    putchar ('\n');

    char lettersD[ENOUGH_SPACE] = "a string";
    showLetters (8, lettersD);

    putchar ('\n');

    return EXIT_SUCCESS;
}

// Shows an array of letters, with given length.
void showLetters (int size, char letters[]) {
    // Your code here
    int i = 0;
    while (i < size) {
        putchar(letters[i]);
        i++;
    }
}
