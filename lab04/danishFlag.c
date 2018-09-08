// show different size of danish flag
//mingfang jiao (z5142125), Yawen Luo (z5134924)
// 2017-08-15
//Zachary

#include <stdio.h>
#include <stdlib.h>

void topleft(int n, int size);
void topright(int n, int size);
void space(int n, int size);

int main(int argc, char *argv[]){
    printf("Enter the flag size: ");
    int size;
    scanf("%d", &size);
    int n = 1;
    int n1 = 1;
    int n2 = 1;
    int n3 = 1;
    while(n1<=(size*2-1)){
        topleft(n, size);
        printf("  ");
        topright(n, size);
        printf("\n");
        n1 = n1 + 1;
    }
    while(n2<=2){
        space(n, size);
        printf("\n");
        n2 = n2 + 1;
    }
    while(n3<=(size*2-1)){
        topleft(n, size);
        printf("  ");
        topright(n, size);
        printf("\n");
        n3 = n3 + 1;
    }
    return EXIT_SUCCESS;
}

void topleft(int n, int size){
    while(n<=(size*3-1)){
        printf("#");
        n = n + 1;
    }
}
void topright(int n, int size){
    while(n<=(size*6-1)){
        printf("#");
        n = n + 1;
    }
}
void space(int n, int size){
    while(n<=(size*3*3)){
        printf(" ");
        n = n + 1;
    }
}
