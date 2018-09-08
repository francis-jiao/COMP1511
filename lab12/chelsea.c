//Chelsea(z5142118) and Xiuyi(z5135224)
//Zain and Anna(F09A)
//2017-10-20 (FriSitar)

#include <stdio.h>
#include <stdlib.h>
#include "Set.h"

#define TRUE 1
#define FALSE 0

typedef struct _node *Node;

typedef struct _set{
    Node head;
}set;

typedef struct _node{
    item value;
    Node next;
}node;

static int isElementOf(item item, Set set);
static int setLength(Set set);

// Create a new `Set`.
Set newSet (void){
    Set new = calloc(1, sizeof(set));
    new->head->next = NULL;
    return new;
}

// Release all resources associated with a `Set`.
void destroySet (Set set){
    Node curr = set->head;
    Node temp;
    while(curr->next != NULL) {
        temp = curr->next;
        free(curr);
        curr = curr->next;
    }
}

// Add an `item` to the `Set`.
void setAdd (Set set, item item){
    Node curr = set->head;
    Node new = calloc(1, sizeof(node));
    new->value = item;
    int escape = FALSE;
    while(curr->next != NULL && escape == FALSE) {
        if(curr->value == item){
            escape = TRUE;
        }
        curr = curr->next;
    }
    if(escape == FALSE) {
        if(curr->value != item) {
            curr->next = new;
            new->next = NULL;
        }
    }
}

// Remove an `item` from the `Set`.
void setRemove (Set set, item item){
    Node curr = set->head;
    while(curr->next->value != item) {
        curr = curr->next;
    }
    Node temp = curr->next->next;
    free(curr->next);
    curr->next = curr->next->next;
}

// Does the `Set` contain this `item`?
bool setContains (Set set, item item){
    Node curr = set->head;
    bool state = FALSE;
    while(curr != NULL){
        if(curr->value == item){
            state = TRUE;
        }
        curr = curr->next;
    }
    return state;
}

// Take the union of two sets (a ∪ b).
Set setUnion (Set a, Set b){
    Node curr = b->head;
    Node validNode;
    Node temp;
    while(curr != NULL) {
       if(isElementOf(curr->value, a) == TRUE) {
            validNode = curr;
            temp = a->head->next;
            a->head = validNode;
            validNode->next = temp;
        }
        curr = curr->next;
    }
    return a;
}

// Take the intersection of two sets (a ∩ b).
Set setIntersection (Set a, Set b){
    Node curr = b->head;
    Node validNode;
    Set intersectSet = newSet();
    intersectSet->head = NULL;
    bool escape = FALSE;
    while(curr != NULL && escape == FALSE) {
       if(isElementOf(curr->value, a) == TRUE) {
            validNode = curr;
            validNode->next = NULL;
            intersectSet->head = validNode;
            escape = TRUE;
        }
        curr = curr->next;
    }
    Node intersectCurr = intersectSet->head;
    while(curr != NULL) {
       if(isElementOf(curr->value, a) == TRUE) {
            validNode = curr;
            validNode->next = NULL;
            intersectCurr->next = validNode;
            intersectCurr = intersectCurr->next;
        }
        curr = curr->next;
    }
    return intersectSet;
}

// Is `a` a subset of `b` (a ⊆ b)?
bool setSubset (Set a, Set b){
    Node curr = a->head;
    bool state = TRUE;
    while(curr != NULL) {
        if(isElementOf(curr->value, b) != TRUE){
            state = FALSE;
        }
    }
    return state;
}

// Is `a` equal to `b` (where a ⊆ b and b ⊆ a, a == b).
bool setEqual (Set a, Set b){
    bool state = FALSE;
    if(setLength(a) == setLength(b)) {
        Node curr = b->head;
        while(curr != NULL) {
            if(isElementOf(curr->value, a) == FALSE){
                state = FALSE;
            }
            curr = curr->next;
        }
    }
    return state;
}

static int isElementOf(item item, Set set) {
    Node curr = set->head;
    bool state = FALSE;
    while(curr != NULL) {
        if(curr->value == item){
            state = TRUE;
        }
    }
    return state;
}

static int setLength(Set set) {
    Node curr = set->head;
    int i = 0;
    while(curr != NULL) {
        curr = curr->next;
        i++;
    }
    return i;
}
