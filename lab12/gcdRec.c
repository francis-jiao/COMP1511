// Van Minh Tran (z5135094)
// Mingfang Jiao (z5142125)
#include<stdio.h>
#include<stdlib.h>
int gcdRec(int a, int b);

int gcdRec(int a, int b) {
    int r=a%b;
    if(r==0) {
        return b;
    }
    return gcdRec(b,r);
}
