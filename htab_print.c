// htab_print.c
// 17.4.2023
// Author: Stanislav Letaši, FIT
// Compiled with: gcc 11.3.0

#include "htab.h"
#include "_htab_private.h"
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

/**
 * Prints record key and data
 */
void htab_print(htab_pair_t *data)
{
    printf("%d \t %s\n", data->value, data->key);
}