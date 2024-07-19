// htab_statistics.c
// 17.4.2023
// Author: Stanislav Letaši, FIT
// Compiled with: gcc 11.3.0

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

        if(t->arr[i]->data.key == NULL) // no record on index
        {
            if(0 < min){
                min=0;
            }
            continue;
        }

        htab_ent_t *current;
        htab_ent_t *head; 

        head = t->arr[i]; 
        current = head;
            
            bool found = false;
            while (found == false)
            {
                if(current->next == head)
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
            if(curr_count > max)
                max = curr_count;
            
            if(curr_count < min)
                min = curr_count;
            
            curr_count = 0;
    }

    avg = avg / (double)(t->arr_size);
    size_t size = htab_size(t);
    size_t bucket_cnt = htab_bucket_count(t);

    fprintf(stderr, "Statistics: MAX: %ld, MIN: %ld, AVERAGE: %lf, TABLE SIZE: %ld, BUCKET COUNT: %ld\n",max, min, avg, size, bucket_cnt);
}