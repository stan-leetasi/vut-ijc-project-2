// htab_find.c
// 17.4.2023
// Author: Stanislav Letaši, FIT
// Compiled with: gcc 11.3.0

#include "htab.h"
#include "_htab_private.h"
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
/**
 * Returns the last record on index
 */
htab_pair_t *htab_find(const htab_t * t, htab_key_t key){

    size_t index = htab_hash_function(key) % t->arr_size;

    if(t->arr[index]->data.key == NULL) // no record on index
        return NULL;
    
    else // find the last record on index
    {
        htab_ent_t *current;
        htab_ent_t *head;
        current = t->arr[index];
        head = current;

        bool found = false; 
        while (!found)
        {
            if(current->next == head) // last record was found
                found = true;
            
            else
                current = current->next;
        }
        
        htab_pair_t *pair;
        pair = &(current->data);
        return pair;
        
    }
}