// Display an integer in English
// Created by mingfang Jiao z5142125
// 1-Aug-2017

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    printf("Please enter an integer: ");
    int num=0;
    scanf("%d", &num);
    if (num <= 5 && num >= 1) {
        if (num == 1) {
            printf("You entered one.\n");
        } else if (num == 2) {
            printf("You entered two.\n");
        } else if (num == 3) {
            printf("You entered three.\n");
        } else if (num == 4) {
            printf("You entered four.\n");
        } else
        printf("You entered five.\n");
    } else if (num < 1) {
        printf("You entered a number less than one.\n"); 
    } else {
        printf("You entered a number greater than five.\n");
    }
    return EXIT_SUCCESS;
}

