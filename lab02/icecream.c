//Ice-cream
//created by mingfang jiao z5142125
//1-Aug-2017

#include<stdio.h>
#include<stdlib.h>

int main (int argc, char *argv[]) {

    int scoops;
    int each;
    printf("How many scoops?");
    scanf("%d",&scoops);
    printf(" How many dollars does each scoop cost?");
    scanf("%d",&each);
    if (scoops * each >10) {
        printf(" Oh no, you don't have enough money :(\n");
    } else { 
        printf(" You have enough money!\n");
    }
    return EXIT_SUCCESS;
}
