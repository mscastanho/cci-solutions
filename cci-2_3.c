#include <stdlib.h>
#include <stdio.h>

/* The problem with deleting a node in a linked list
 * without having access to the whole structure is 
 * that we need to find a way to update the previous
 * element correctly.
 * 
 * Since we cannot move backwards (singly linked list),
 * we can try to move one element ahead, copy the data
 * to the present element and erase the next element.
 * 
 * This way we don't have to update de previous node,
 * but we guarantee that it points to the correct one
 * after the delete operation.
 * 
 * Be careful with corner cases!
 * 
 * Also, if the element is the last, then we have no 
 * way to solve the problem. We would have no data to 
 * copy, thus we cannot make the previous element point 
 * correctly to the next node.
 *   
 */

typedef struct node {
    char c;
    struct node *next;
}list_node;

void delete_node(list_node *ln){
    list_node *next;

    if(ln == NULL)
        return;
    else
        next = ln->next;
    
    if(next == NULL){
        /* Last element. Problem! No data to copy */
    }

    ln->c = next->c;
    ln->next = next->next;
    free(next);
}