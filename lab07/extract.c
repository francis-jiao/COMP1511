// Functions and types used to extract x,y,z values from a string
// containing a URL of the form:
// "http://almondbread.cse.unsw.edu.au/mandelbrot/2/5/3.14/-0.141/tile.bmp"
//
// mingfang jiao (z5142125)
// Written on 2017-09-??
// Tutor (dayHH-lab)

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "extract.h"
triordinate extract (char *message);

double myAtoD (char *message);
double myAtoD1(char *message);
long myAtoL (char *message);

int main (int argc, char *argv[]) {

    char *message = "http://almondbread.cse.unsw.edu.au/mandelbrot/2/5/3.14/-0.141/tile.bmp";

    triordinate dat = extract (message);

    printf ("dat is (%f, %f, %d)\n", dat.x, dat.y, dat.z);

    assert (dat.x == 3.14);
    assert (dat.y == -0.141);
    assert (dat.z == 5);

    return EXIT_SUCCESS;
}
triordinate extract (char *message){
    triordinate coordinate;
    coordinate.z=myAtoL(message);
    coordinate.x=myAtoD(message);
    coordinate.y=myAtoD1(message);
    return coordinate;
}
double myAtoD (char *message){
    int i=49,k=1,j=1,sign=1,g=1;
    double x,temp,z=10.0,decimal=0,temp1,w=10.0,r;
    //starts from message[49] which is '/' and read the string
    while(message[i]!='\0'){
        if(message[i-k]=='-'){
            x=(message[i-k]-48);
            sign=-1;
        }
//Add the number before decimal point and after decimal point
        if(message[i]=='.'){
            while(message[i+j]!='/'){
                temp=(message[i+j]-48);
                while(g<=j){
                    temp=temp/z;
                    g++;
                }
                decimal+=temp;
                j++;
                g=1;
            }
            while(message[i-k]!='.'&&message[i-k]!='/'){
                temp1=(message[i-k]-48)*sign;
                if(message[i-k-1]>='0'&&message[i-k-1]<='9'){
                    r=(message[i-k-1]-48)*w;
                    if(sign==1){
                        x=(temp1+decimal+r);
                        return x*1000/1000;
                    }else if(sign==-1){
                        x=(temp1-decimal-r);
                        return x*1000/1000;
                    }
                }
    //Determine the sign of the value;
                if(sign==1){
                    x=(temp1+decimal);
                    return x*1000/1000;
                }else if(sign==-1){
                    x=(temp1-decimal);
                    return x*1000/1000;
                }
                k++;
            }
        }
        i++;
    }
    return 0;
}
long myAtoL (char *message){
    int i=48;
    int integer;
    while(message[i]!='\0'){
        if(message[i]>=48&&message[i]<=57){
            integer=message[i]-48;
            return integer;
        }
        i++;
    }
    return 0;
}
double myAtoD1(char *message){
    int i=54,k=1,j=1,sign=1,g=1;
    double x,temp,z=10.0,decimal=0,temp1,w=10.0,r;
    while(message[i]!='\0'){
        if(message[i-k]=='-'){
            x=(message[i-k]-48);
            sign=-1;
        }
        if(message[i]=='.'){
            while(message[i+j]!='/'){
                temp=(message[i+j]-48);
                while(g<=j){
                    temp=temp/z;
                    g++;
                }
                decimal+=temp;
                j++;
                g=1;
            }
            while(message[i-k]!='.'&&message[i-k]!='/'){
                temp1=(message[i-k]-48)*sign;
                if(message[i-k-1]>='0'&&message[i-k-1]<='9'){
                    r=(message[i-k-1]-48)*w;
                    if(sign==1){
                        x=(temp1+decimal+r);
                        return x*1000/1000;
                    }else if(sign==-1){
                        x=(temp1-decimal-r);
                        return x*1000/1000;
                    }
                }
                if(sign==1){
                    x=(temp1+decimal);
                    return x*1000/1000;
                }else if(sign==-1){
                    x=(temp1-decimal);
                    return x*1000/1000;
                }
                k++;
            }
        }
        i++;
    }
    return 0;
}
