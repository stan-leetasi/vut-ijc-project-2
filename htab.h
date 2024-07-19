// htab.h -- interface of the htab library (solution IJC-DU2)
// License: none (Public domain)

// the following lines prevent multiple inclusions:
#ifndef HTAB_H__
#define HTAB_H__

#include <string.h>     // size_t
#include <stdbool.h>    // bool

// Table:
struct htab;    // incomplete structure declaration - user does not see the content
typedef struct htab htab_t;     // typedef as per assignment

// Types:
typedef const char * htab_key_t;        // key type
typedef int htab_value_t;               // value type

// Pair of data in the table:
typedef struct htab_pair {
    htab_key_t    key;          // key
    htab_value_t  value;        // associated value
} htab_pair_t;                  // typedef as per assignment

// Hash function (same for all tables in the program)
// If you define the same function in the program, yours will be used.
size_t htab_hash_function(htab_key_t str);

// Functions for working with the table:
htab_t *htab_init(const size_t n);              // table constructor
size_t htab_size(const htab_t * t);             // number of records in the table
size_t htab_bucket_count(const htab_t * t);     // size of the array's allocated memory

htab_pair_t * htab_find(const htab_t * t, htab_key_t key);  // search
htab_pair_t * htab_lookup_add(htab_t * t, htab_key_t key);  // find a record, add to the data value or insert a new record

bool htab_erase(htab_t * t, htab_key_t key);    // deletes the given record

// for_each: goes through all records and calls the function f on them
// Note: f must not change the key .key or add/remove items
void htab_for_each(const htab_t * t, void (*f)(htab_pair_t *data));

void htab_print(htab_pair_t *data); // Prints the word and the number of occurrences to stdout

void htab_clear(htab_t * t);    // deletes all records
void htab_free(htab_t * t);     // table destructor

// computation and printing of statistics of the length of lists (min,max,avg, size, bucket count) to stderr:
void htab_statistics(const htab_t * t);

#endif // HTAB_H__
