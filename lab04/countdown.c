//mingfang Jiao z5142125
//count down from 10 to 0
#include<stdio.h>
#include<stdlib.h>

int main(int argc, char *argv[]) {
    int counter = 10;
    while(counter>=0) {
        printf("%d\n", counter);
        counter = counter - 1;
    }
    return EXIT_SUCCESS;
}

