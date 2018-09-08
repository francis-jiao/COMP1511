// CONVERT A STRING TO UPPERCASE
// CREATED BY
// mingfang Jiao z5142125
// CREATED ON 2017-08-??
// TUTOR'S NAME (DAYHH-LAB)

#include <stdio.h>
#include <stdlib.h>

void stringToUpper (char *buffer);

int main (int argc, char *argv[]) {
    /// THIS WON'T WORK!
    ///
    /// `str` only points to a string literal, which is stored in a
    /// read only section of the program.  If you attempt to modify
    /// it, your program will crash with a memory error (usually,
    /// SIGSEGV, the infamous "segmentation fault").
    //
    // char *str = "Hello!"
    // stringToUpper (str)

    char str[] = "Seventeen...  SEVENTEEN, I SAY!";
    stringToUpper (str);
    printf ("%s\n", str);

    return EXIT_SUCCESS;
}

// TAKES A STRING IN `buffer`, AND UPPERCASES IT.
void stringToUpper (char *buffer) {
    // YOUR CODE GOES HERE!
    int currentPos=0;
    while (buffer[currentPos]!='\0') {
        if (buffer[currentPos]>='a' && buffer[currentPos]<='z') {
            buffer[currentPos]=buffer[currentPos]-32;
        }
        currentPos++;
    }
}
