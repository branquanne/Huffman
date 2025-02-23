#include "validate_data.h"
#include "huffman.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

//
// Beskriv vad delen ska göra
// o Identifiera in-/utdata
// o Ta fram algoritm
// o Identifiera datatyper

void loadFileCharacters(char *fileName) {
  long fileLength;
  FILE *inFile = fopen(fileName, "rb"); //! Lägg in error handling sen

  if (inFile == NULL) {
    printf("Error: Could not open file\n");
    exit(EXIT_FAILURE);
  }

  fseek(inFile, fileLength, SEEK_END);
  ftell(inFile);
  rewind(inFile);
  char *buffer = (char *)malloc(fileLength * sizeof(char *));
  fread(buffer, fileLength, 1, inFile);
  fclose(inFile);

  // Läs in en char i taget
  //  Lägg in i antingen bitbuffer eller array
  //  Arrayen ska vara storlek 256 dvs en plats för varje tecken
  //  Varje plats börjar på 0. Om tex tecken "e" förekommer 19 ggr i texten så är indx 101 ("e i utf-8") värdet 19
}
