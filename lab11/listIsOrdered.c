// Van Minh Tran (z5135094)
// Mingfang Jiao (z5142125)
#include"list.h"
#include<stdio.h>

int listIsOrdered (List l){
    Node curr;
    curr=l->head;
    int state = TRUE;
    if(curr==NULL) {
        return state;
    } else {
        while(curr->next != NULL) {
            if(curr->next->value < curr->value) {
                state = FALSE;
            }
            curr= curr->next;
        }
    }
    return state;
}
