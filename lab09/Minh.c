// Image ADT
// Van Minh Tran (z5135094)
// Mingfang Jiao (z5142125)
// 2017/09/22
// Riyasat & Zac (Tue17 - Sitar)
#include <stdlib.h>
#include <stdio.h>
#include "Image.h"
#include <math.h>
struct _image {
    unsigned int width;
    unsigned int height;
    pixel **pixels;
} image;
Image newImage (unsigned int width, unsigned int height){
    Image im1 = calloc(1, sizeof(image));
    im1->width = width;
    im1->height = height;
    pixel **pixels = calloc(height, sizeof(pixel *));
    unsigned int i = 0;
    while (i < height) {
        pixels[i] = calloc(width, sizeof(pixel));
        i++;
    }
    im1->pixels = pixels;
    return im1;
}
void destroyImage(Image img){
    unsigned i = 0;
    while (i < img->height) {
        free(img->pixels[i]);
        i++;
    }
    free(img->pixels);
    free(img);
}
unsigned int imageGetWidth (Image i){
    return i->width;
}
unsigned int imageGetHeight (Image i){
    return i->height;
}
pixel imageGetPixel (Image i, point p){
    pixel im;
    im.red = i->pixels[p.y][p.x].red;
    im.green = i->pixels[p.y][p.x].green;
    im.blue = i->pixels[p.y][p.x].blue;
    return im;
}
void imageSetPixel (Image i, point p, pixel color){
    i->pixels[p.y][p.x].red = color.red;
    i->pixels[p.y][p.x].green = color.green;
    i->pixels[p.y][p.x].blue = color.blue;
}
void imageDrawLine (Image i, pixel color, point start, point end){
    if (end.x != start.x){
        int j = 0;
        point img;
        while (j < end.x-start.x) {
            int yCoord = (((end.y - start.y) * j )/(end.x - start.x))+ start.y;
            img.x = start.x + j;
            img.y = yCoord;
            imageSetPixel (i, img, color);
            j++;
        }
    } else {
        int j = 0;
        point img;
        while ( j < end.y-start.y){
            img.x = start.x;
            img.y = start.y + j;
            imageSetPixel (i, img, color);
            j++;
        }
    }
}
void imageDrawRectangle (Image i, pixel color, point bottomLeft, point topRight){
    point start;
    point end;
    int j = 0;
    while (j < topRight.y - bottomLeft.y) {
        start.y = bottomLeft.y + j;
        start.x = bottomLeft.x;
        end.y = start.y;
        end.x = topRight.x;
        imageDrawLine(i, color, start, end);
        j++;
    }
}
void imageDrawCircle (Image i, pixel color, point centre, unsigned int radius){
    point start;
    point end;
    start.x = centre.x - radius;
    start.y = centre.y - radius;
    end.x = centre.x + radius;
    end.y = centre.y + radius;
    int j = 0;
    while (j < end.y) {
        int k = 0;
        while (k < end.x){
            if (((start.x + k) - centre.x)
                    * ((start.x + k) - centre.x)
                    + ((start.y + j) - centre.y)
                    * ((start.y + j) - centre.y)
                    <= radius*radius){
                point a;
                a.x = start.x + k;
                a.y = start.y + j;
                imageSetPixel(i, a, color);
            }
            k++;
        }
        j++;
    }
}
