#include <stdlib.h>
#include <stdio.h>

/* Add digit by digit. If the result is greater
 * than 10, carry 1 to next addition. Keep going
 * until the end of either number.
 * 
 * Then we have to check if there are digits left
 * in either one, and then just copy them to the end
 * of the result.
 */

typedef struct sl_list {
    int d;
    struct sl_list *next;
}sl_list;

//sl_list* list_create(int d);

//sl_list* list_copy(sl_list* l);

sl_list* list_add(sl_list *a, sl_list *b){
    sl_list *sum, *i, *prev;
    int res, carry;

    if(a == NULL){
        if(b == NULL)
            return NULL;
        else
            sum = list_copy(b);
    }else{
        if(b == NULL)
            sum = list_copy(a);
        else{
            sum = i = NULL;
            carry = 0;

            while(a != NULL && b != NULL){
                res = a->d + b->d + carry;
                carry = res/10;
                res = res%10;

                prev = i;
                i = list_create(0);

                // Save pointer to beginning
                if(sum == NULL)
                    sum = i;
                
                // Update previous node
                if(prev != NULL)
                    prev->next = i;

                a = a->next;
                b = b->next;
            }

            if(a == NULL)
                if(b != NULL) // Digits left in B
                    i->next = list_copy(b);
                //else No digits left    
            else // Digits left in A
                i->next = list_copy(a);
        }
    }

    return sum;
}