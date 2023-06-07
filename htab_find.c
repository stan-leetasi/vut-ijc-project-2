// htab_find.c
// Řešení IJC-DU2, příklad b), 16.4.2023
// Autor: Stanislav Letaši, FIT
// Přeloženo: gcc 11.3.0
// Definícia funkcie htab_find

#include "htab.h"
#include "_htab_private.h"
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

htab_pair_t *htab_find(const htab_t * t, htab_key_t key){

    
    size_t index = htab_hash_function(key) % t->arr_size;

    if(t->arr[index]->data.key == NULL) // Na indexe neexistuje záznam
    {
        return NULL;
    }
    else // Na danom indexe existuje aspoň 1 záznam 
    {
        if (t->arr[index]->next == t->arr[index]) // Na indexe je len 1 záznam
        {
            htab_pair_t *pair;
            pair = &(t->arr[index]->data);
            return pair;
        }
        else // Na indexe je viac záznamov, najde sa posledný
        {
            htab_ent_t *current; // Dočasná premenná pre záznam
            htab_ent_t *head; // Dočasná premenná pre prvý záznam na indexe
            current = t->arr[index];
            head = current;
            bool found = false; // Bool na indikáciu ukončenia loopu
            while (found == false)
            {
                if(current->next == head) // Pokiaľ neexistuje ďalší záznam(vrátenie sa na začiatok zoznamu)
                {
                    found = true;
                }
                else
                {
                current = current->next;
                }
            }
            
            htab_pair_t *pair;
            pair = &(current->data);
            return pair;
        }
    }
}