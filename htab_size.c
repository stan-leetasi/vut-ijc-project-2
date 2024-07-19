// htab_size.c
// 17.4.2023
// Author: Stanislav Letaši, FIT
// Compiled with: gcc 11.3.0

#include "htab.h"
#include "_htab_private.h"

/**
 * Returns number of records in table t
 */
size_t htab_size(const htab_t *t)
{
    size_t count = 0;
    for (size_t i = 0; i < t->arr_size; i++) 
    {
        htab_ent_t *head = t->arr[i];
        if(head->data.key == NULL) // no record on index
            continue;

        count++;

        for(htab_ent_t *current = head->next; current != head; current = current->next)
            count++;
    }
    return count;
}