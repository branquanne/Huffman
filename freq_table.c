#include "freq_table.h"
#include "validate_data.c"
#include <stdio.h>
#include <stdlib.h>

int *checkFrequency(char *fileContents) {
  int i = 0;
  int freq_table[256] = {0};

  while (fileContents[i] != '\0') {
    freq_table[(unsigned char)fileContents[i]]++;
    i++;
  }

  return freq_table;
}
