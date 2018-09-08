// Sort three numbers using pointers to the variables
// Completed by
// mingfang Jiao z5142125
// Completed on 2017-08-??
// Tutor name (dayHH-lab)

#include <stdio.h>
#include <stdlib.h>

void swap (int *a, int *b);
void sortThree (int *a, int *b, int *c);

int  main (int argc, char *argv[]) {
    printf ("Enter three numbers: ");
    int a, b, c;
    scanf ("%d %d %d", &a, &b, &c);

    sortThree (&a, &b, &c);

    printf ("The numbers, in order, are: %d %d %d\n", a, b, c);

    return EXIT_SUCCESS;
}

// Swap the values in two variables given their pointers
void swap (int *a, int *b) {
    /// Your code here
    int i;
    i = *a;
    *a = *b;
    *b = i;
}

// Sort the values in three variables, given their pointers
void sortThree (int *a, int *b, int *c) {
    /// Your code here
    if(*a>*b){
        swap(a,b);
    }
    if(*b>*c){
        swap(b,c);
    }
    if(*a>*b){
        swap(a,b);
    }
}
