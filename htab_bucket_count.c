// htab_bucket_count.c
// 17.4.2023
// Author: Stanislav Letaši, FIT
// Compiled with: gcc 11.3.0

#include "htab.h"
#include "_htab_private.h"
#include <stdlib.h>
#include <stdbool.h>

/**
 * Returns the number of entities which the table has allocated memory for
 */
size_t htab_bucket_count(const htab_t * t){

    size_t count = t->arr_size;
    htab_ent_t *current;
    htab_ent_t *head;
    for (size_t i = 0; i < t->arr_size; i++) 
    {
        current = t->arr[i];
        head = current;
        if(current->data.key == NULL)
            continue;

        while(true)
        {
            current = current->next;
            if(current != head)
                count++;

            else
                break;
        }
    }
    return count;
}