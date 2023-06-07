// htab_bucket_count.c
// Řešení IJC-DU2, příklad b), 16.4.2023
// Autor: Stanislav Letaši, FIT
// Přeloženo: gcc 11.3.0
// Definícia funkcie htab_bucket_count

#include "htab.h"
#include "_htab_private.h"
#include <stdlib.h>
#include <stdbool.h>
/*
Spočíta pre koľko položiek je v tabuľke alokovaná pamäť, vracia výsledok
*/
size_t htab_bucket_count(const htab_t * t){

    size_t count = t->arr_size;
    bool end_of_list = false;
    htab_ent_t *current;
    htab_ent_t *head;
    for (size_t i = 0; i < t->arr_size; i++) 
    {
        current = t->arr[i];
        head = current;
        while(end_of_list == false)
        {
            current = current->next;
            if(current != head)
            {
                count++;
            }
            else
            {
                end_of_list = true;
            }
        }
    }
    return count;
}