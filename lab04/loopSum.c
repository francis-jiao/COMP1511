//mingfang Jiao z5142125
//the sum of some numbers
#include<stdio.h>
#include<stdlib.h>
int main (int argc, char *argv[]) {
    int numprint;
    printf("How many numbers: ");
    int sum=0;
    scanf("%d\n",&numprint);
    while(numprint>0) {
        int num2 = 0;
        int num1;
        scanf("%d",&num1);
        sum = sum + num1;
        numprint-=1;
    }
    printf("%d\n",sum);
    return EXIT_SUCCESS;
}

