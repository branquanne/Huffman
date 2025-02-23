#include "freq_table.h"
#include "validate_data.c"
#include <stdio.h>
#include <stdlib.h>

int *checkFrequency(char *fileContents) {
    int i = 0;
    int *freq_table = calloc(256, sizeof(int));
    if (freq_table == NULL) {
        printf("Could not allocate memory for frequency table\n");
        exit(1);
    }

    while (fileContents[i] != '\0') {
        freq_table[(unsigned char)fileContents[i]]++;
        i++;
    }

    return freq_table;
}

int **sortFrequencyTable(int *freq_table) {
    int **sorted_freq_table = malloc(256 * sizeof(int *));
    if (sorted_freq_table == NULL) {
        printf("Could not allocate memory for sorted frequency table\n");
        exit(1);
    }

    for (int i = 0; i < 256; i++) {
        sorted_freq_table[i] = malloc(2 * sizeof(int));
        if (sorted_freq_table[i] == NULL) {
            printf("Could not allocate memory for sorted frequency table\n");
            exit(1);
        }
        sorted_freq_table[i][0] = i;
        sorted_freq_table[i][1] = freq_table[i];
    }

    for (int i = 0; i < 256; i++) {
        for (int j = i + 1; j < 256; j++) {
            if (sorted_freq_table[i][1] < sorted_freq_table[j][1]) {
                int *temp = sorted_freq_table[i];
                sorted_freq_table[i] = sorted_freq_table[j];
                sorted_freq_table[j] = temp;
            }
        }
    }

    return sorted_freq_table;
}
