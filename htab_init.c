// htab_init.c
// 17.4.2023
// Author: Stanislav Letaši, FIT
// Compiled with: gcc 11.3.0

#include <stdio.h>
#include <stdlib.h>
#include "htab.h"
#include "_htab_private.h"

/**
 * Allocates memory for n elements and returns a pointer to the table
 */
htab_t *htab_init(const size_t n){
    
    htab_t *table = malloc(sizeof(htab_t)); // hash table pointer
    if(table == NULL){
        fprintf(stderr, "ERR: Memory allocation failure in htab_init\n");
        return NULL;
    }
    table->size = 0;
    table->arr_size = n;

    table->arr = malloc((n*sizeof(htab_ent_t*))); // pointer to the array of pointers to linked lists
    if(table->arr == NULL){
        free(table);
        fprintf(stderr, "ERR: Memory allocation failure in htab_init\n");
        return NULL;
    }

    for (size_t i = 0; i < n; i++)
    {
        table->arr[i] = malloc(sizeof(htab_ent_t)); // first element of the linked list
        if(table->arr[i] == NULL){
            for(int j = i; j > 0; j--)
            {
                free(table->arr[i]);
            }
        free(table->arr);
        free(table);
        fprintf(stderr, "ERR: Memory allocation failure in htab_init\n");
        return NULL;
        }
        
        table->arr[i]->data.key = NULL;
        table->arr[i]->data.value = 0;
        table->arr[i]->next = NULL;
    }

    return table;
}

