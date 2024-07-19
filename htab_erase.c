// htab_erase.c
// 17.4.2023
// Author: Stanislav Letaši, FIT
// Compiled with: gcc 11.3.0

#include "htab.h"
#include "_htab_private.h"
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

/**
 * Deletes record of a given key from the table
 */
bool htab_erase(htab_t * t, htab_key_t key){

    size_t index = htab_hash_function(key) % t->arr_size;

    if(t->arr[index]->data.key == NULL) // no record on index
    {
        return false;
    }
    else // at least 1 record on index
    {
        if (t->arr[index]->next == t->arr[index]) // only 1 record on index
        {
            if(strcmp((t->arr[index]->data.key),key) != 0) // searched record is not on index
            {
                return false;
            }
            
            free((char*)(t->arr[index]->data.key));
            t->arr[index]->data.key = NULL;
            t->arr[index]->data.value = 0; 
            return true;
        }

        else // more records on index
        {
            htab_ent_t *previous;
            htab_ent_t *current; 
            htab_ent_t *head; // first record on index
            
            head = t->arr[index];
            current = t->arr[index];

            if(strcmp((head->data.key),key) == 0) // first record on index == key
            {
                free((char*)(head->data.key));

                // copy data from 2nd record into head
                head->data.key = (head->next)->data.key; 
                head->data.value = (head->next)->data.value;

                // remove 2nd record
                current = head->next; 
                head->next=(head->next)->next;
                free(current);

                return true;
            }
            else // find key
            {
                previous = current;
                current = current->next;

                while (strcmp((current->data.key),key) != 0)
                {
                    if(current == head) // loop searched all records on index unsuccessfully
                        return false;
                    
                    else
                    {
                        previous = current;
                        current = current->next;
                    }
                }

                // (n-1)-th record will point to the (n+1)-th record, n-th record is removed
                previous->next = current->next; 
                free((char*)(current->data.key)); 
                free(current);
                return true;
            }
        }
    }
}