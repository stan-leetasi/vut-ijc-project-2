// htab_free.c
// 17.4.2023
// Author: Stanislav Letaši, FIT
// Compiled with: gcc 11.3.0


#include <stdio.h>
#include <stdlib.h>
#include "htab.h"
#include "_htab_private.h"

/**
 * Frees memory allocated by table
 */
void htab_free(htab_t * t){
    for(size_t i = 0; i < t->arr_size; i++)
    {
        free(t->arr[i]);
    }
    free(t->arr);
    free(t);
}