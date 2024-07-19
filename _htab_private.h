// _htab_private.h
// 17.4.2023
// Author: Stanislav Letaši, FIT
// Compiled with: gcc 11.3.0

#ifndef _HTAB_PRIVATE_H__
#define _HTAB_PRIVATE_H__

#include "htab.h"

// entity in the hash table
typedef struct htab_ent {
    htab_pair_t data;       // data of a record
    struct htab_ent *next;  // pointer to the next record on the same address
} htab_ent_t;

struct htab {
    size_t size;        // number of entities in the table
    size_t arr_size;    // table capacity
    htab_ent_t **arr;   // linked list of entities
};

#endif




