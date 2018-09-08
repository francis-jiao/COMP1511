//mingfang jiao z5142125
//show square

#include<stdio.h>
#include<stdlib.h>
int square(int num);
int main(int argc, char *argv[]) {

    printf("Enter a size: ");
    int num;
    scanf("%d",&num);
    int num1=num;
    if(num == 0) {
        printf("\n");
    } else {
        while(num1>0) {
            square(num);
            printf("\n");
            num1 -=1;
        }
    }
    return EXIT_SUCCESS;
}

int square(int num) {
    while(num>0) {
        printf("#");
        num-=1;
    }
    return 0;
}
    

