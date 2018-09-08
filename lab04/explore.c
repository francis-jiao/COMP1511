//mingfang jiao (z5142125) Yawen Luo (z5134924)
//Exploring memory
//Created by Richard Buckland on 2012-11-20.

#include <stdio.h>
#include <stdlib.h>

long add (int x, int y);

int main(int argc, char *argv[]) {

    int x;
    int y;
    long total;

    x = 40;
    y = 2;

    printf("The size of a int, in bytes, is %lu.\n", sizeof(x));
    printf("The variable x is located at memory address %p.\n", &x);
    printf("The size of a int, in bytes, is %lu.\n", sizeof(y));
    printf("The variable y is located at memory address %p.\n", &y);

    total = add (x, y);

    printf("the sum of %d and %d is %ld\n", x, y, total);

    char c ='a';

    unsigned long ul       = 0;
    printf("The size of a unsigned long, in bytes, is %d.\n", sizeof(ul));
    printf("The variable ul is located at memory address %p.\n", &ul);
    unsigned int ui        = 1;
    printf("The size of a unsigned int, in bytes, is %d.\n", sizeof(ui));
    printf("The variable ui is located at memory address %p.\n", &ui);
    unsigned long long ull = 2;
    printf("The size of a unsigned long long, in bytes, is %d.\n", sizeof(ull));
    printf("The variable ull is located at memory address %p.\n", &ull);
    unsigned short us      = 3;
    printf("The size of a unsigned short, in bytes, is %d.\n", sizeof(us));
    printf("The variable us is located at memory address %p.\n", &us);
    signed long sl       = 4;
    printf("The size of a signed long, in bytes, is %d.\n", sizeof(sl));
    printf("The variable sl is located at memory address %p.\n", &sl);
    signed int si        = 5;
    printf("The size of a signed int, in bytes, is %d.\n", sizeof(si));
    printf("The variable si is located at memory address %p.\n", &si);
    signed long long sll = 6;
    printf("The size of a signed long long, in bytes, is %d.\n", sizeof(sll));
    printf("The variable sll is located at memory address %p.\n", &sll);
    signed short ss      = 7;
    printf("The size of a signed short, in bytes, is %d.\n", sizeof(ss));
    printf("The variable ss is located at memory address %p.\n", &ss);

    long l       = 8;
    printf("The size of a long, in bytes, is %d.\n", sizeof(l));
    printf("The variable l is located at memory address %p.\n", &l);
    int i        = 9;
    printf("The size of a int, in bytes, is %d.\n", sizeof(i));
    printf("The variable i is located at memory address %p.\n", &i);
    long long ll = 10;
    printf("The size of a long long, in bytes, is %d.\n", sizeof(ll));
    printf("The variable ll is located at memory address %p.\n", &ll);
    short s      = 11;
    printf("The size of a short, in bytes, is %d.\n", sizeof(s));
    printf("The variable s is located at memory address %p.\n", &s);
    float f = 3.1;
    printf("The size of a float, in bytes, is %d.\n", sizeof(f));
    printf("The variable f is located at memory address %p.\n", &f);
    double d = 3.14;
    printf("The size of a double, in bytes, is %d.\n", sizeof(d));
    printf("The variable d is located at memory address %p.\n", &d);
    // add them all together just to make use of them so the compiler
    // doesn't grumble that they are unused in the program
    printf("The variable x is located at memory address %p.\n", &x);
    total = add (x, y);
    double grandTotal;
    grandTotal =  c + ul + ui + ull + us + sl + si + sll + ss + l +  i + ll +  s + f + d;

    printf ("all these things added together make %f\n",grandTotal);

    // Add in your own variables, printf statements and arithmetic to
    // figure out the size of different types, where they live
    // and how big the numebrs they store are

    return EXIT_SUCCESS;
}

long add (int x, int y) {
    long answer;
    answer = x + y;

    return answer;
}
