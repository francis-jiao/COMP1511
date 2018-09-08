//mingfang Jiao z5142125
//count down positive integer to zero
#include<stdio.h>
#include<stdlib.h>

int main(int argc, char *argv[]) {
    int num;
    printf("Enter a positive integer: ");
    scanf("%d",&num);
    while(num>=0) {
        printf("%d\n",num);
        num-=1;
    }
    return EXIT_SUCCESS;
}
