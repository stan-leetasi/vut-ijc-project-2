// htab_free.c
// Řešení IJC-DU2, příklad b), 16.4.2023
// Autor: Stanislav Letaši, FIT
// Přeloženo: gcc 11.3.0
// Definícia funkcie htab_free

#include <stdio.h>
#include <stdlib.h>
#include "htab.h"
#include "_htab_private.h"

/*
Uvoľní pamäť alokovanú tabuľkou
*/
void htab_free(htab_t * t){
    for(size_t i = 0; i < t->arr_size; i++)
    {
        free(t->arr[i]);
    }
    free(t->arr);
    free(t);
}