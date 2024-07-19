// io.c
// 17.4.2023
// Author: Stanislav Letaši, FIT
// Compiled with: gcc 11.3.0

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>
#include <fcntl.h>
#include "htab.h"
#include "io.c"

// Optimal table size should be a prime number
// 18000 is the number of unique words in a book
// 18000*1,3 is 23400, 23431 is the closest prime number
#define ARR_SIZE 23431

int main()
{
    htab_t *table;
    table = htab_init(ARR_SIZE);

    bool frst_err = false; // error message will only be printed once per session

    int length = 0; // word length
    char *string = malloc(256*sizeof(char)); // temporary string

    while(true) // read input from stdin
    {
        length = read_word(string, 255, stdin, &frst_err);

        if(length == EOF)
            break;
        
        if(length > 0)
            htab_lookup_add(table,string);
    }

    htab_for_each(table,htab_print);
    htab_statistics(table);

    free(string);
    htab_clear(table);
    htab_free(table);
    
    return 0;
}