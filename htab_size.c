// htab_size.c
// Řešení IJC-DU2, příklad b), 16.4.2023
// Autor: Stanislav Letaši, FIT
// Přeloženo: gcc 11.3.0
// Definícia funkcie htab_size
#include "htab.h"
#include "_htab_private.h"

/*
Spočíta všetky položky v tabuľke, vracia počet
*/
size_t htab_size(const htab_t *t)
{
    size_t count = 0;
    for (size_t i = 0; i < t->arr_size; i++) 
    {
        htab_ent_t *head = t->arr[i];
        for(htab_ent_t *current = head->next; current != head; current = current->next)
        {
            count++;
        }
    }
    return count;
}