// htab_erase.c
// Řešení IJC-DU2, příklad b), 16.4.2023
// Autor: Stanislav Letaši, FIT
// Přeloženo: gcc 11.3.0
// Definícia funkcie htab_erase

#include "htab.h"
#include "_htab_private.h"
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
/*
Vymaže záznam zadaného key
*/
bool htab_erase(htab_t * t, htab_key_t key){

    size_t index = htab_hash_function(key) % t->arr_size;

    if(t->arr[index]->data.key == NULL) // Na indexe neexistuje záznam
    {
        return false;
    }
    else // Na danom indexe existuje aspoň 1 záznam 
    {
        if (t->arr[index]->next == t->arr[index]) // Na indexe je len 1 záznam
        {
            if(strcmp((t->arr[index]->data.key),key) != 0) // Na indexe neexistuje hľadaný záznam
            {
                return false;
            }
            // Na indexe existuje hľadaný záznam
            free((char*)(t->arr[index]->data.key)); // Odstránenie allocovanej pamäti pre string key
            t->arr[index]->data.key = NULL;
            t->arr[index]->data.value = 0; 
            return true;
        }

        else // Na indexe je viac záznamov, nájde sa key
        {
            htab_ent_t *previous; // Dočasná premenná pre predošlý záznam
            htab_ent_t *current; // Dočasná premenná pre záznam
            htab_ent_t *head; // Dočasná premenná pre prvý záznam na indexe
            
            head = t->arr[index]; // 1. záznam na indexe
            current = t->arr[index];

            if(strcmp((head->data.key),key) == 0) // Hľadaný key == 1. položka v linked liste - head
            {
                free((char*)(head->data.key)); // Odstránenie allocovanej pamäti pre string key
                head->data.key = (head->next)->data.key; // Prekopírovanie key z ďalšieho záznamu
                head->data.value = (head->next)->data.value;
                current = head->next; // Uvoľní sa pamäť 2. položky v linked liste, do pamäte head sa prekpírovali údaje z 2.
                head->next=(head->next)->next; // head->next bude ukazovať na 3. položku alebo sám na seba
                free(current); // Uvoľnenie pamäti 2. položky
                return true;
            }
            else
            {
                previous = current;
                current = current->next;

                while (strcmp((current->data.key),key) != 0) // Hľadanie zhodného záznamu
                {
                    if(current == head) // Pokiaľ neexistuje ďalší záznam(vrátenie sa na začiatok zoznamu)
                    {
                        return false; // Hľadaný klúč nebol nájdený
                    }
                    else
                    {
                        previous = current;
                        current = current->next;
                    }
                }
                // Zhodný kľúč bol nájdený, loop sa ukončil
                previous->next = current->next; // (n-1)-tý záznam bude ukazovať na (n+1)-tý záznam
                free((char*)(current->data.key)); // Uvoľnenie allocovanej pamäte pre string key
                free(current); // Uvoľnenie alokovanej pamäti pre n-tý záznam
                return true;
            }

            return true;
        }
    }
}