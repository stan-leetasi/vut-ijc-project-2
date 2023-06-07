// _htab_private.h
// Řešení IJC-DU2, příklad b), 16.4.2023
// Autor: Stanislav Letaši, FIT
// Přeloženo: gcc 11.3.0
// Definícia štruktúry htab

#ifndef _HTAB_PRIVATE_H__
#define _HTAB_PRIVATE_H__

#include "htab.h"

// Definícia položky v tabulke
typedef struct htab_ent {
    htab_pair_t data; // Dáta prvej položky na adrese
    struct htab_ent *next; // Ukazateľ na ďalšiu položku na rovnakej adrese
} htab_ent_t;

// Definícia štruktúry htab
struct htab {
    size_t size;  // Počet položiek v tabuľke
    size_t arr_size;  // Veľkosť alokovanej pamäti/kapacita tabuľky
    htab_ent_t **arr;  // Pole položiek (linked list)
};

#endif




