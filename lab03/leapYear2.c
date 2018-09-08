//judge the leap year ,section2>
//mingfang jiao (z5142125)
//13-Aug-2017

#include<stdio.h>
#include<stdlib.h>

#define start_year 1582
int isleapyear(int year);

int main(int argc, char *argv[]) {
    int year;
    printf("Enter a year after 1582: ");
    scanf("%d",&year);
    if(year<start_year) {
        printf("%d is before 1582.\n",year);
        return EXIT_SUCCESS;
    }
    if (isleapyear(year)) {
        printf("%d is a leap year.\n",year);
    }else{
        printf("%d is not a leap year.\n",year);
    }
    return EXIT_SUCCESS;
}


int isleapyear(int year) {
    if(year%4==0){
        if(year%100==0){
            if(year%400==0){
                return 1;
            }else{
                return 0;
            }
        }else{
            return 1;
        }
    }else{
        return 0;
    }
}


