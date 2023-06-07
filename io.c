// io.c
// Řešení IJC-DU2, příklad b), 17.4.2023
// Autor: Stanislav Letaši, FIT
// Přeloženo: gcc 11.3.0
// Načíta prvé slovo zo zadaného súboru a vracia jeho dĺžku

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
#include <string.h>


int read_word(char *s, int max, FILE *f, bool *frst_err)
{
    if (f == NULL) // Ak zlyhalo otvorenie vstupného suboru
    {
        fprintf(stderr, "Otvorenie vstupneho suboru zlyhalo\n");
        exit(1);
    }

    if (feof(f))
    {
        return EOF;
    }

    int c;

    int index = 0;

    memset(s, '\0', max+1);

    while ((c = fgetc(f)) != ' ' && c!= EOF) // Čítanie znakov zo súboru kým nenajde whitespace alebo EOF
    {
        if(c == '\n' && index == 0) // Preskočenie prázdneho riadku
        {
            continue;
        }

        if(c == '\0' || c == '\n') // Ukončenie slova newline charakterom
        {
            c = fgetc(f); // Odstranenie newline charakteru a posunutie sa na dalsi riadok
            return index;
        }

        if (index >= max) // Ak slovo presiahlo dĺžku max znakov
        {
            if (*frst_err == false)
            {
                fprintf(stderr, "Slovo prekrocilo hranicu %i charakterov, zvysne charaktery budu ignorovane\n",max);
                *frst_err = true;
            }

            while ((c = fgetc(f)) != ' ' && c != EOF && c != '\n'); // Načítanie a zahodenie zvyšných charakterov
             
            return max;
        }

        s[index] = c; // Pridanie znaku do stringu
        index++;
    }

    if(c == EOF && index == 0)
    {
        return EOF;
    }
    else
    {
        return index;
    }
}