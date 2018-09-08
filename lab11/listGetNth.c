#include"list.h"
#define NULL 0

// This function returns the value of the nth item
// in a list
int listGetNth (List l, int n){    
    Node curr = l->head;
    int i=0;
    while(curr != NULL && i != n) {
        curr = curr->next;
        i++;
    }
    return curr->value;
}
