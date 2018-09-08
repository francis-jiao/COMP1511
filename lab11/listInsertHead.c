#include"list.h"
#define NULL 0

void listInsertHead (List l, int val){
    Node inser = calloc(1,sizeof(struct _node));
    inser->value = val;
    inser->next = l->head;
    l->head = inser;
}
