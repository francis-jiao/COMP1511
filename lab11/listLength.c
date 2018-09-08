#include"list.h"
#define NULL 0

// This function returns the length of a linked list
int listLength (List l){
    if(l->head == NULL){
        return 0;
    }
    Node curr = l->head;
    int listLength=0;
    while(curr != NULL) {
        listLength++;
        curr=curr->next;
    }
    return listLength;
}

