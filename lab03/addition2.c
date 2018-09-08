//mingfang jiao z5142125
//decimal to hexadecimal

#include<stdio.h>
#include<stdlib.h>

int main(int argc, char *argv[]) {
    printf("Please enter two positive integers:");
    int num1;
    int num2;
    scanf(" %d %d",&num1 ,&num2);
    int sum = num1 + num2;
    printf(" %#04x + %#04x = %#04x\n", num1,num2,sum);
    return EXIT_SUCCESS;
}
