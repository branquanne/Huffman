#include "freq_table.h"
#include "validate_data.h"
#include <stdio.h>
#include <stdlib.h>

/*
 * File: freq_table.c
 *
 * Description:
 *
 *
 *
 *
 * Author: Henrik Röjvall & Bran Quanne
 *
 * Date: 2025-02-23
 *
 */

/*  External functions  */

int *checkFrequency(char *fileContents) {
  int i = 0;
  int *freq_table = malloc(256 * sizeof(int));

  while (fileContents[i] != '\0') {
    freq_table[(unsigned char)fileContents[i]]++;
    i++;
  }

  return freq_table;
}