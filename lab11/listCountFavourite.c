// Van Minh Tran (z5135094)
// Mingfang Jiao (z5142125)
#include"list.h"
#include<stdio.h>

int listCountFavourite (List l){
    int i=0;
    Node curr=l->head;
    if(curr==NULL) {
        return 0;
    }
    while(curr!=NULL) {
        if(curr->value%17==0) {
            i++;
        }
        curr=curr->next;
    }
    return i;
}
