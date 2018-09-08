// Assignment 1 Mandelbrot: Pixel Color
//
// Completed by
// Mingfang Jiao (z5142125)
// Tong Zheng (z5142003)
//
// Modified on 2017-??-??
// Tutor's name (dayHH-lab)

#include "mandelbrot.h"
#include "pixelColor.h"

// This function should take a number (of steps taken to escape the
// Mandelbrot set), and convert it to a color.
//
// You have artistic licence here, so make your Mandelbrot look amazing.
pixel pixelColor(int steps) {
    pixel color;
    color.red = steps*5;
    color.green=steps*2;
    color.blue =steps*2;
    return color;
}

