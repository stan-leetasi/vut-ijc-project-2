// htab_statistics.c
// Řešení IJC-DU2, příklad b), 16.4.2023
// Autor: Stanislav Letaši, FIT
// Přeloženo: gcc 11.3.0
// Definícia funkcie htab_statistics

#include <stdio.h>
#include <stdlib.h>
#include "htab.h"
#include "_htab_private.h"

void htab_statistics(const htab_t * t)
{
    size_t min = 100000;
    size_t max = 0;
    double avg = 0.0;
    size_t curr_count = 0;

    for (size_t i = 0; i < t->arr_size; i++) 
    {

        if(t->arr[i]->data.key == NULL) // Prázdny index
        {
            if(0 < min){
                min=0;
            }
            continue;
        }
        if(t->arr[i] == t->arr[i]->next) // Ak sa na indexe nachádza len 1 záznam
        {
            if (1>max){
                max = 1;
            }
            if (1<min){
                min = 1;
            }
            avg = avg + 1.0;
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
                    avg = avg + 1.0;
                    curr_count = curr_count + 1;
                    found = true;
                }
                else
                {
                    current = current->next;
                    curr_count = curr_count + 1;
                    avg = avg + 1.0;
                }
            }
            if(curr_count > max){
                max = curr_count;
            }
            if(curr_count < min){
                min = curr_count;
            }
            curr_count = 0;
    }
    avg = avg / (double)(t->arr_size);
    fprintf(stderr, "Statistics: MAX: %ld, MIN: %ld, AVERAGE: %lf\n",max,min,avg);
}