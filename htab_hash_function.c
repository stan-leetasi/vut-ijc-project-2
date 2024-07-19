// htab_hash_function.c
// 17.4.2023
// Author: Stanislav Letaši, FIT
// Compiled with: gcc 11.3.0

#include <string.h>
#include <stdlib.h>
#include "htab.h"

/**
 * Calculates the hash of str
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