#include "freq_table.h"
#include "validate_data.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ASCII_SIZE 256

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

int *checkFrequency(char *fileName) {
  FILE *inFile = fopen(fileName, "rb");

  int *frequencyTable = malloc(256 * sizeof(int));

  for (int i = 0; i < MAX_ASCII_SIZE; i++) {
    frequencyTable[i] = 0;
  }

  int ch;
  while ((ch = fgetc(inFile)) != EOF) {
    frequencyTable[ch]++;
  }

  fclose(inFile);
  return frequencyTable;
}