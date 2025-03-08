#include "freq_table.h"
#include <stdio.h>
#include <stdlib.h>

int *frequency_table(char *fileName) {
	FILE *inFile = fopen(fileName, "rb");
	if (inFile == NULL) {
	  fprintf(stderr, "Error: Cannot open file %s\n", fileName);
	  exit(1);
	}
  
	int *frequencyTable = (int *)malloc(ASCII_SIZE * sizeof(int));
	for (int i = 0; i < ASCII_SIZE; i++) {
	  frequencyTable[i] = 0;
	}
	if (frequencyTable == NULL) {
	  fprintf(stderr, "Error: Cannot allocate memory\n");
	  exit(1);
	}
  
	int ch;
	while ((ch = fgetc(inFile)) != EOF) {
	  if (ch >= 0 && ch < ASCII_SIZE) {
		frequencyTable[ch]++;
	  } else {
		fprintf(stderr, "Warning: Character out of range %d\n", ch);
	  }
	}
  
	fclose(inFile);
	return frequencyTable;
  }