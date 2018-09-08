#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    printf("Enter a year after 1852: ");
    int year = 0;
    scanf("%d", &year);

    if (year < 1852){
        printf("%d is before 1852.\n", year);
    } else if (year % 4 == 0 && year % 100 != 0){
        printf("%d is a leap year.\n", year);		
    } else if (year % 4 == 0 && year % 100 == 0 && year % 400 == 0){
        printf("%d is a leap year.\n", year);
    } else {
        printf("%d is not a leap year.\n", year);
    }
    return EXIT_SUCCESS; 
}

