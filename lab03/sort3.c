//to sort numbers in increasing order
//Yawen Luo(z5134924), Mingfang Jiao(z5142125);
//Zachary
//2017-08-08

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    int x,y,z,t;
    printf("Enter 3 numbers: ");
    scanf("%d %d %d",&x,&y,&z);
    if (x>y) {
        t=x;x=y;y=t;
    }
    if (x>z) {
        t=x;x=z;z=t;
    }
    if (y>z) {
        t=y;y=z;z=t;
    }
    printf("%d\n%d\n%d\n",x,y,z);
    return EXIT_SUCCESS;
}


