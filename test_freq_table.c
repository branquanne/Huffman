#include "freq_table.h"
#include "validate_data.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {

    // Ladda in filen och skapa frekvenstabell
    char *fileContents = loadFileCharacters("balenPaEkeby_GostaBerlingsSaga_SelmaLagerlof.txt");
    int *freq_table = checkFrequency(fileContents);
    int **sorted_freq_table = sortFrequencyTable(freq_table);

    // Skriv ut frekvenstabellen
    for (int i = 0; i < 256; i++) {
        printf("Character: %c\t Frequency: %d\n", (char)sorted_freq_table[i][0], sorted_freq_table[i][1]);
    }

    // Frigör minne
    for (int i = 0; i < 256; i++) {
        free(sorted_freq_table[i]);
    }
    free(sorted_freq_table);
    free(freq_table);
    free(fileContents);

    return 0;
}