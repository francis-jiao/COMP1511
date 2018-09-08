#include "list.h"
#include<stdlib.h>
#include<stdio.h>

void listDeleteContains (List l,int val){
    Node curr = l->head;
    state = FALSE;
    if(curr->value == val) {
        state = TRUE;
        Node todelete = l->head;
        free(l->head);
        l->head = todelete->next;
    }
    while(curr->next != NULL && state == FALSE) {
        if(curr->next->value == val) {
            state = TRUE;
            Node todelete = curr->next;
            free(curr->next);
            curr->next = todelete->next;
        }
        curr=curr->next;
    }
}
    
