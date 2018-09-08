// COMP1511 17s2 -- Complex ADT
// Created by: ... (z0000000)
//             ... (z0000000)
// Created on: 2017-09-??
// Tutorial:   dayHH-lab

#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#include "Complex.h"
void printComplex(Complex c);
typedef struct _complex {
    double re;
    double im;
} complex;


int main(int argc, char *argv[]) {
    Complex c=newComplex(1.0,1.0);
    printComplex(c);
    return EXIT_SUCCESS;
}
// Create a new `Complex` number from two `double`s.
Complex newComplex (double re, double im) {
	complex *new = calloc(1, sizeof(complex));

	// Sometimes calloc fails
    if (new == NULL) {
		printf(
			stderr,
			"Failed to allocate memory for Complex.\n"
		);
		exit(EXIT_FAILURE);
	}

	new->re = re;
	new->im = im;

	return new;
}

// Release all resources associated with a `Complex` number.
void destroyComplex (Complex c) {
    free(c);
}

// Retrieve the real part of the `Complex` number.
double complexRe (Complex c) {
    return c->re;
}

// Retrieve the imaginary part of the `Complex` number.
double complexIm (Complex c) {
    // Add your code here.
    return c->im;
}

// Add two `Complex` numbers together.
Complex complexAdd (Complex w, Complex z) {
    double newre=w->re+z->re;
    double newim=w->im+z->im;
    Complex new=newComplex(newre,newim);
    return new;
}

// Multiply two `Complex` numbers together
void printComplex(Complex c) {
    assert(c != NULL);
    printf("(%lf+%lf)\n", c->re,c->im);
}

