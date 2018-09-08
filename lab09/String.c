// StringADT
// Mingfang Jiao (z5142125)
// Van Minh Tran (z5135094)
#include "String.h"
#include<string.h>
#include<stdlib.h>
#include<stdio.h>

#define TRUE 1
#define FALSE 0
typedef struct _string {
    char *array;
    int length;
}string;

// Create a new `String`, from a C-style null-terminated array of
// characters.
String newString (char *str) {
    string *s = calloc (1, sizeof (string));
    s->length = strlen(str);
    s->array = calloc(s->length,sizeof(char));
    return s;
}

// Release all resources associated with a `String`.
void destroyString (String s){
    free(s);
}
// Get the length of a `String`.
int stringLength (String s){
    return s->length;
}
// Make a (mutable) copy of a `String`.
String stringClone (String s){
    String r= newString(s->array);
    return r;
}

// Given a `String`, and an index in the `String`, return the
// character at that index.
char stringAt (String s, int index){
    return s->array[index];
}
// Given a `String`, and a character to look for in the `String`,
// return either the index of the character, or `-1` if the character
// could not be found in the `String`.
int stringFindChar (String s, char find){
    int i=0;
    while(i< s->length) {
        if(find == s->array[i]) {
            return find;
        }
        i++;
    }
    return -1;
}
// Are two `String`s equal?
int stringsEqual (String s1, String s2){
    int i=0;
    if(s1->length !=s2->length) {
        return FALSE;
    }
    while(i< s1->length) {
        if(s1->array[i] != s2->array[i]) {
            return FALSE;
        }
        i++;
    }
    return TRUE;
}
// Given two `String`s, concatenates them into a new `String`.
String stringConcat (String s1, String s2){
    String r = calloc(1,sizeof(struct _string));
    r->length = s1->length + s2->length;
    r->array = calloc(1,sizeof(char));
    int i=0;
    while(i < s1->length) {
        r->array[i]=s1->array[i];
        i++;
    }
    int f=0;
    while(f < s2->length) {
        r->array[f+i+1] = s2 ->array[f];
        f++;
    }
    return r;
}

