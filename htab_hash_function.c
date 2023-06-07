// htab_hash_function.c
// Řešení IJC-DU2, příklad b), 16.4.2023
// Autor: Stanislav Letaši, FIT
// Přeloženo: gcc 11.3.0
// Definícia funkcie htab_hash_function

#include <string.h>
#include <stdlib.h>
#include "htab.h"

/*
Vypočíta hash zadaného stringu a vracia jeho hodnotu
*/
size_t htab_hash_function(htab_key_t str){

    size_t hash = 0;
    size_t a = 65599;

    for(size_t i = 0; str[i] != '\0'; i++)
    {
        hash = hash*a + str[i];
    }

    return hash;
}