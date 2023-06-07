// htab_for_each.c
// Řešení IJC-DU2, příklad b), 16.4.2023
// Autor: Stanislav Letaši, FIT
// Přeloženo: gcc 11.3.0
// Definícia funkcie htab_for_each
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "htab.h"
#include "_htab_private.h"

void htab_for_each(const htab_t * t, void (*f)(htab_pair_t *)) 
{
    //htab_pair_t *pair;

    for (size_t i = 0; i < t->arr_size; i++) 
    {

        if(t->arr[i]->data.key == NULL) // Preskočenie prázdneho záznamu
        {
            continue;
        }
        if(t->arr[i] == t->arr[i]->next) // Ak sa na indexe nachádza len 1 záznam
        {
            f(&(t->arr[i]->data));
            continue;
        }

        htab_ent_t *current; // Dočasná premenná pre záznam
        htab_ent_t *head; // Dočasná premenná pre prvý záznam na indexe

        head = t->arr[i]; // 1. záznam na indexe
        current = head;
            
            bool found = false; // Bool na indikáciu ukončenia loopu
            while (found == false)
            {
                if(current->next == head) // Pokiaľ neexistuje ďalší záznam(vrátenie sa na začiatok zoznamu)
                {
                    f(&(current->data));
                    found = true;
                }
                else
                {
                    (f(&(current->data)));
                    current = current->next;
                }
            }     
    }
}
