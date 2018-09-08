#include"list.h"
#define NULL 0
#define FALSE 0
#define TRUE (!FALSE)
// This function returns TRUE if val exists in the list,
// FALSE otherwise
int listContains (List l, int val){
    if(l->head == NULL) {
        return FALSE;
    }    
    Node curr = l->head;
    while(curr != NULL) {
        if(curr->value == val) {
            return TRUE;
        }else{        
            curr = curr->next;
        }
    }
    return FALSE;
}

