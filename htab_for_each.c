// htab_for_each.c
// 17.4.2023
// Author: Stanislav Letaši, FIT
// Compiled with: gcc 11.3.0

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "htab.h"
#include "_htab_private.h"

/**
 * Iterates over all records and calls function f
 */
void htab_for_each(const htab_t * t, void (*f)(htab_pair_t *)) 
{
    for (size_t i = 0; i < t->arr_size; i++) 
    {
        htab_ent_t *current;
        htab_ent_t *head; 

        head = t->arr[i];
        current = head;

        if(t->arr[i]->data.key == NULL) // no record on index
            continue;
            
        while (true)
        {
            if(current->next == head) // last record was found
            {
                f(&(current->data));
                break;
            }
            else
            {
                (f(&(current->data)));
                current = current->next;
            }
        }     
    }
}
