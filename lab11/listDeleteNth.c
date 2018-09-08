// Van Minh Tran (z5135094)
// Mingfang Jiao (z5142125)
#include"list.h"
#include<stdio.h>
#include<stdlib.h>

void listDeleteNth (List l, int n){
    Node nodeToReserve;
    Node curr =l->head;
    int length = listGetLength(l);
    if(n == 0){
        nodeToReserve = l->head->next;
        free(l->head);
        l->head = nodeToReserve;
    }else{
        int i=1;
        while(i<n) {
            curr=curr->next;
            i++;
        }
        nodeToReserve = curr->next->next;
        free(curr->next);
        curr->next = nodeToReserve;
    }
}

int listGetLength(List l) {
    int i=0;
    Node curr = l->head;
    while(curr != NULL) {
        i++;
        curr = curr->next;
    }
    return i;
}
