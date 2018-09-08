#include <stdio.h>
#include <stdlib.h>

char lowercase (char c);

// DO NOT CHANGE THIS MAIN FUNCTION
int main (int argc, char *argv[]) {
    char lower[26]= {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};   
    char upper[26]= {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};    
    char c;
    c = getchar();
    while(c>='A' && c<='Z') {
        int a = upper[&c];               
        putchar(lower[*a]);
    }
    return 0;
}

