// htab_lookup_add.c
// Řešení IJC-DU2, příklad b), 16.4.2023
// Autor: Stanislav Letaši, FIT
// Přeloženo: gcc 11.3.0
// Definícia funkcie htab_lookup_add

#include "htab.h"
#include "_htab_private.h"
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>


htab_pair_t *htab_lookup_add(htab_t * t, htab_key_t key){

    size_t index = htab_hash_function(key) % t->arr_size;

    if(t->arr[index]->data.key == NULL) // Prvy záznam na indexe neexistuje
    {
        size_t len = strlen(key);
        t->arr[index]->data.key = malloc((len+1)*sizeof(char)); // Alocovanie pamäte pre string "key"
        strcpy((char*)(t->arr[index]->data.key),key); // Skopírovanie stringu key
        t->arr[index]->data.value = 1;
        t->arr[index]->next=t->arr[index]; // 1. zaznam ukazuje sam na seba

        htab_pair_t *pair;
        pair = &(t->arr[index]->data);
        return pair;
    }

    else // Na danom indexe už záznam existuje
    {
        if(strcmp((t->arr[index]->data.key),key) == 0) // Ak je prvý záznam identický s key, zväčší value a vráti pair
        {
            t->arr[index]->data.value = (t->arr[index]->data.value) + 1;

            htab_pair_t *pair;
            pair = &(t->arr[index]->data);
            return pair; 
        }

        else // Hľadanie záznamu ktorého kľúč = key
        {
            htab_ent_t *current; // Dočasná premenná pre záznam
            htab_ent_t *head; // Dočasná premenná pre prvý záznam na indexe
            current = (t->arr[index])->next;
            head = t->arr[index];

            while (true) // Pokiaľ neexistuje ďalší záznam(vrátenie sa na začiatok zoznamu)
            {
                if(strcmp((current->data.key),key) == 0) // Ak je záznam identický s key, zväčší value a vráti pair
                {
                    current->data.value = (current->data.value) + 1;

                    htab_pair_t *pair;
                    pair = &(current->data);
                    return pair; 
                }
                else // Ak nie, posunie sa na ďalší
                {
                    if(current->next == head)
                    {
                        break;
                    }
                    else
                    {
                        current = current->next;
                    }
                    
                }
            }

            // Ak záznam s hľadaným key nebol nájdený, pridá sa nový
            htab_ent_t *new_ent = malloc(sizeof(htab_ent_t)); // Alokovanie pamäte pre nový záznam
            if(new_ent == NULL)
            {
                htab_clear(t);
                htab_free(t);
                fprintf(stderr, "Zlyhala alokacia pamate v htab_lookup_add\n");
                exit(1);
            }

            size_t len = strlen(key);
            new_ent->data.key = malloc((len+1)*sizeof(char)); // Alocovanie pamäte pre string "key"
            strcpy((char*)(new_ent->data.key),key); // Skopírovanie stringu key do záznamu
            
            new_ent->data.value = 1;
            current->next = new_ent;
            new_ent->next=head;

            htab_pair_t *pair;
            pair = &(new_ent->data);
            return pair;

        }
    }
}
