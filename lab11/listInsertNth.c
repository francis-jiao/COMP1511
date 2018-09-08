// Van Minh Tran (z5135094)
// Mingfang Jiao (z5142125)
#include"list.h"
#include<stdio.h>
#include<stdlib.h>

void listInsertNth (List l, int n, int val){
    Node insert=calloc(1,sizeof(struct _node));
    insert->value=val;
    if(n==0){
        insert->next=l->head;
        l->head=insert;
    }else{
        int i=1;
        Node curr = l->head;
        while(i<n){
            curr=curr->next;
            i++;
        }
        insert->next=curr->next;
        curr->next=insert;
    }
}
