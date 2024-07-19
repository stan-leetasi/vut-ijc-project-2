// htab_lookup_add.c
// 17.4.2023
// Author: Stanislav Letaši, FIT
// Compiled with: gcc 11.3.0

#include "htab.h"
#include "_htab_private.h"
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

/**
 * Finds a key in the table t, adds a new entry if the key
 * is not in the table, otherwise increases the data value by 1.
 * Returns pointer to the found or newly added pair
 */
htab_pair_t *htab_lookup_add(htab_t * t, htab_key_t key){

    size_t index = htab_hash_function(key) % t->arr_size;

    if(t->arr[index]->data.key == NULL) // no record on index
    {
        size_t len = strlen(key);
        t->arr[index]->data.key = malloc((len+1)*sizeof(char));
        strcpy((char*)(t->arr[index]->data.key),key); 
        t->arr[index]->data.value = 1;
        t->arr[index]->next=t->arr[index]; 

        htab_pair_t *pair;
        pair = &(t->arr[index]->data);
        return pair;
    }

    // at least one record on index

    htab_ent_t *current;
    htab_ent_t *head;
    current = (t->arr[index])->next;
    head = t->arr[index];

    while (true) // try to find the key
    {
        if(strcmp((current->data.key),key) == 0)
        {
            current->data.value = (current->data.value) + 1;

            htab_pair_t *pair;
            pair = &(current->data);
            return pair; 
        }
        else
        {
            if(current->next == head)
                break;
            
            else
                current = current->next;
        }
    }

    // key not found, add a new record
    htab_ent_t *new_ent = malloc(sizeof(htab_ent_t));
    if(new_ent == NULL)
    {
        htab_clear(t);
        htab_free(t);
        fprintf(stderr, "ERR: Memory allocation failure in htab_lookup_add\n");
        exit(1);
    }

    size_t len = strlen(key);
    new_ent->data.key = malloc((len+1)*sizeof(char));
    strcpy((char*)(new_ent->data.key),key); 
    
    new_ent->data.value = 1;
    current->next = new_ent;
    new_ent->next=head;

    htab_pair_t *pair;
    pair = &(new_ent->data);
    return pair;
}

