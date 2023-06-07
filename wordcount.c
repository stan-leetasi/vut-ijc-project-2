// wordcount.c
// Řešení IJC-DU2, příklad b), 16.4.2023
// Autor: Stanislav Letaši, FIT
// Přeloženo: gcc 11.3.0
// počíta počet slov vo vstupnom texte
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>
#include <fcntl.h>
#include "htab.h"
#include "io.c"

// Optimálna veľkosť tabuľky by malo byť prvočíslo
// 18000 slov je priemerný počet unikátnych slov v knihe
// 18000*1,3 je 23400, a 23431 je najbližšie prvočíslo
#define ARR_SIZE 23431


int main()
{
    htab_t *table;
    table = htab_init(ARR_SIZE); // Vytvorenie tabulky

    // Kód ktorý ukončí program ak nie je spustený so vstupom na stdin
    // Bez neho program čaká na vstup zo stdin
    // Musí byť odkomentovaný aby bol program kompatibilný s UNIX pipe
    /*
    fcntl(STDIN_FILENO, F_SETFL, fcntl(STDIN_FILENO, F_GETFL, 0) | O_NONBLOCK); // Nastavenie stdin streamu do non-blocking módu

    char c = getchar(); // Pokus o prečítanie prvého charakteru (v non-blocking móde sa nečaká na zadanie charakteru ak na stdin už nie je vstup)

    if (c == EOF) // Overenie či stdin nie je prázdny
    {
        fprintf(stderr, "Na stdin nebol zadany vstup\n");
        htab_clear(table);
        htab_free(table);
        exit(1);
    }
    else
    {
        fcntl(STDIN_FILENO, F_SETFL, fcntl(STDIN_FILENO, F_GETFL, 0)); // Vrátenie default nastavení stdin streamu
        ungetc(c, stdin);                                              // Vrátenie prečítaného charakteru na stdin
    }
    */

    bool frst_err = false; // Pri prvom presiahnutí MAX_LENGTH sa nastaví na true, aby sa správa o prekročení dĺžky vypísala len raz

    int length = 0; // Dĺžka slova
    char *string = malloc(256*sizeof(char)); // String na dočasné uloženie slova (limit dĺžky 256)

    while(true) // Načítanie vstupu zo stdin
    {
        length = read_word(string,255,stdin,&frst_err);
        if(length == EOF)
        {
            break;
        }
        htab_lookup_add(table,string);
    }

    htab_for_each(table,htab_print);
    htab_statistics(table);

    free(string);
    htab_clear(table);
    htab_free(table);
    
    return 0;
}