#include "freq_table.h"
#include "validate_data.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int **sortFrequencyTable(int *freq_table);

int main(void) {

  // Load file in array byte-wise, create frequency table and sort it (for testing purposes)
  char *fileContents = loadFileCharacters("test.txt");
  int *freq_table = checkFrequency(fileContents);
  int **sorted_freq_table = sortFrequencyTable(freq_table);

  // Print the frequency table
  for (int i = 0; i < 256; i++) {
    // Only characters that appear in the file should be printed
    if (sorted_freq_table[i][1] != 0) {
      printf("Character: %c (ASCII value: %d)\t Frequency: %d\n", (char)sorted_freq_table[i][0], (int)sorted_freq_table[i][0], sorted_freq_table[i][1]);
    }
  }

  // Free memory
  for (int i = 0; i < 256; i++) {
    free(sorted_freq_table[i]);
  }
  free(sorted_freq_table);
  free(freq_table);
  free(fileContents);

  return 0;
}

// Sort the frequency table in descending order
int **sortFrequencyTable(int *freq_table) {

  // Allocate memory for the sorted frequency table
  int **sorted_freq_table = malloc(256 * sizeof(int *));

  // Assign the character and frequency to the (yet to be sorted) frequency table
  for (int i = 0; i < 256; i++) {
    sorted_freq_table[i] = malloc(2 * sizeof(int));
    sorted_freq_table[i][0] = i;
    sorted_freq_table[i][1] = freq_table[i];
  }

  // Sort the frequency table in descending order
  for (int i = 0; i < 256; i++) {
    for (int j = i + 1; j < 256; j++) {
      // If the frequency of the character at index i is less than the frequency of the character at index j, swap them
      if (sorted_freq_table[i][1] < sorted_freq_table[j][1]) {
        int *temp = sorted_freq_table[i];
        sorted_freq_table[i] = sorted_freq_table[j];
        sorted_freq_table[j] = temp;
      }
    }
  }

  return sorted_freq_table;
}
