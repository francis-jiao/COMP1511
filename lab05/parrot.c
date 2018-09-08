#include<stdio.h>
#include<stdlib.h>

int main(int argc,char *argv[]) {
    char c;
    c = getchar ();
    putchar (c);
    while(c!= EOF) {
        c = getchar();        
        putchar(c);
    }
    return EXIT_SUCCESS;
}
        
        
