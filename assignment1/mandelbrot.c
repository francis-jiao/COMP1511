// Assignment 1 Mandelbrot
//
// Completed by
// Mingfang Jiao z5142125
// Tong Zheng z5142003            
// Modified on 2017-
// Tutor's name (dayHH-lab)

// Add your own #includes here

#include <stdio.h>
#include <stdlib.h>
#include "mandelbrot.h"
#include "pixelColor.h"
#include <math.h>

// Add your own #defines here

// Add your own function prototypes here

static complex giveComplexNumber (double x, double y, int z, complex center);

// Draw a single Mandelbrot tile, by calculating and colouring each of
// the pixels in the tile.
//
// Your function "returns" this tile by filling in the `pixels` 2D array
// that is passed in to your function.
//
// The `pixels` array is TILE_SIZE high and TILE_SIZE wide.
// The bottom left corner of the image is pixels[0][0].
//
// `center` is a complex number, representing the center of the tile.
// `z` is used to calculate the distance between each pixel in the image.
// Each pixel is 2^(-z) apart from each other.
void drawMandelbrot(pixel pixels[TILE_SIZE][TILE_SIZE],complex center, int z) {
    // hint: use this array to store the result from escapeGrid.
    int grid[TILE_SIZE][TILE_SIZE];

    escapeGrid(grid, center, z);
    int x = 0;
    int y = 0;
    while (y < TILE_SIZE) {
        while (x < TILE_SIZE) {
            pixels[y][x] = pixelColor(grid[y][x]);
            x++;
        }
        x = 0;
        y++;
    }

}

// Determine the number of steps required to escape the Mandelbrot set,
// for the given complex number `c`.
int escapeSteps(complex c) {
    int steps = 0;
    complex z = {
        .re = 0,
        .im = 0
    };
    while (steps < MAX_STEPS && (z.re * z.re + z.im * z.im <= 4)) {
        double newRe = z.re * z.re - z.im * z.im + c.re;
        z.im = 2 * z.re * z.im + c.im;
        z.re = newRe;
        steps++;
    }
    return steps;
}

// Fill a grid of TILE_SIZE by TILE_SIZE pixels, with the number of
// steps each pixel took to escape the Mandelbrot set.
void escapeGrid(int grid[TILE_SIZE][TILE_SIZE],complex center, int z) {
    int x = 0;
    int y = 0;
    while (y < TILE_SIZE) {
        while (x < TILE_SIZE) {
            grid[y][x] = escapeSteps(giveComplexNumber(x, y, z, center));
            x++;
        }
        x = 0;
        y++;
    }
}

// Add your own functions here.
// Remember to make them static.
static complex giveComplexNumber (double x, double y, int z, complex center) {
    int centerX = 512/2;
    int centerY = 512/2;
    double xDist = x - centerX;
    double yDist = y - centerY;

    double pixelDist = pow(2, -z);
    complex c = {
        .re = xDist * pixelDist + center.re,
        .im = yDist * pixelDist + center.im
    };
    return c;
}
