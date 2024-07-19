// io.c
// 17.4.2023
// Author: Stanislav Letaši, FIT
// Compiled with: gcc 11.3.0

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
#include <string.h>

/**
 * Reads a single word from input file f, 
 * writes the word into string s, returns word length
 */
int read_word(char *s, int max, FILE *f, bool *frst_err)
{
    if (f == NULL)
    {
        fprintf(stderr, "ERR: Failed to open input file\n");
        exit(1);
    }

    if (feof(f))
        return EOF;
    
    int c;
    int index = 0;

    memset(s, '\0', max+1); // zero-out the string

    while ((c = fgetc(f)) != ' ' && c!= EOF) // read chars from file
    {
        if(c == '\0' || c == '\n' || c == ',' || c == '.')
        {
            // dispose of irrelevant characters
            while((c = fgetc(f)) == '\0' || c == '\n' || c == ',' || c == '.');

            return index;
        }

        if (index >= max)
        {
            if (*frst_err == false)
            {
                fprintf(stderr, "A word has exceeded %i characters, the rest of the characters will be ignored\n",max);
                *frst_err = true;
            }

            while ((c = fgetc(f)) != ' ' && c != EOF && c != '\n'); // dispose of the rest of the word
            return max;
        }

        s[index] = c; // add character to string
        index++;
    }

    if(c == EOF && index == 0)
        return EOF;
    
    return index;
}