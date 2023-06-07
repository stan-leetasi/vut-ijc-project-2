// htab_clear.c
// Řešení IJC-DU2, příklad b), 16.4.2023
// Autor: Stanislav Letaši, FIT
// Přeloženo: gcc 11.3.0
// Definícia funkcie htab_clear

#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include "htab.h"
#include "_htab_private.h"

/*
Vymaže všekty záznamy a uvoľní pamäť linked listov. Necháva alokovanú pamäť pre 1 záznam na každom indexe
*/
void htab_clear(htab_t * t){

    for(size_t i = 0; i < t->arr_size; i++)
    {
        if(t->arr[i]->data.key == NULL) // Na indexe nie je záznam
        {
            continue;
        }
        if(t->arr[i]->next == t->arr[i]) // Na indexe je len 1. záznam
        {
            htab_erase(t, t->arr[i]->data.key);
            continue;
        }
        else // Na indexe je viac záznamov
        {
            while(t->arr[i]->data.value != 0)
            {
                htab_erase(t, (t->arr[i]->data.key));
                t->arr[i] = t->arr[i]->next;
            }

        }
        
    }
}