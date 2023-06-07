// htab_init.c
// Řešení IJC-DU2, příklad b), 16.4.2023
// Autor: Stanislav Letaši, FIT
// Přeloženo: gcc 11.3.0
// Definícia funkcie htab_init

#include <stdio.h>
#include <stdlib.h>
#include "htab.h"
#include "_htab_private.h"

/*
Alokuje pamäť pre n prvkov a vracia pointer na tabuľku
*/
htab_t *htab_init(const size_t n){
    
    htab_t *table = malloc(sizeof(htab_t)); // Ukazateľ na hash table
    if(table == NULL){
        fprintf(stderr, "Zlyhala alokacia pamate v htab_init\n");
        return NULL;
    }
    table->size = 0;
    table->arr_size = n;

    table->arr = malloc((n*sizeof(htab_ent_t*))); // Ukazateľ na pole ukazatelov na linked listy
    if(table->arr == NULL){
        free(table);
        fprintf(stderr, "Zlyhala alokacia pamate v htab_init\n");
        return NULL;
    }

    for (size_t i = 0; i < n; i++)
    {
        table->arr[i] = malloc(sizeof(htab_ent_t)); // Prva položka linked listu
        if(table->arr[i] == NULL){
            for(int j = i; j > 0; j--)
            {
                free(table->arr[i]);
            }
        free(table->arr);
        free(table);
        fprintf(stderr, "Zlyhala alokacia pamate v htab_init\n");
        return NULL;
        }
        
        table->arr[i]->data.key = NULL;
        table->arr[i]->data.value = 0;
        table->arr[i]->next = NULL;
    }

    return table;
}

