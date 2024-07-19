// htab_clear.c
// 17.4.2023
// Author: Stanislav Letaši, FIT
// Compiled with: gcc 11.3.0

#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include "htab.h"
#include "_htab_private.h"

/**
 * Deletes all records and frees memory of the linked lists.
 */
void htab_clear(htab_t * t){

    for(size_t i = 0; i < t->arr_size; i++)
    {
        while(t->arr[i]->data.value != 0)
            {
                htab_erase(t, (t->arr[i]->data.key));
                t->arr[i] = t->arr[i]->next;
            }
    }
}