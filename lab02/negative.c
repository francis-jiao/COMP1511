// don't be so negative
// created by mingfang jiao z5142125
//1-Aug-2017

#include<stdio.h>
#include<stdlib.h>

int main (int argc, char *argv[]) {
    int num;
    scanf("%d",&num);
    if (num > 0) {
        printf("You have entered a positive number.\n");
    } else if (num == 0) {
        printf("You have entered zero.\n");
    }else {
        printf("Don't be so negative!\n");
    }
    return EXIT_SUCCESS;
}
