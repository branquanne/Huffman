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

int main(void) {

  char *fileName = "balenPaEkeby_GostaBerlingsSaga_SelmaLagerlof.txt";
  char *fileContent = loadFileCharacters(fileName);
  printf("%d\n", fileContent[0]);
  // printf("%s\n", fileContent);

  free(fileContent);

  return 0;
}

int checkInputValidity(int numberOfArguments, char **arguments) {
  printf("Usage: %s\n [OPTION] [FILE0] [FILE1] [FILE2]\n", arguments[0]);
  printf("Options:\n");
  printf("-encode encodes FILE1 according to frequence analysis done on FILE0. Stores the result in FILE2");
  printf("-decode decodes FILE1 according to frequence analysis done on FILE0. Stores the result in FILE2");
  exit(1);
}

char *loadFileCharacters(char *fileName) {

  FILE *file = fopen(fileName, "rb");
  if (file == NULL) {
    printf("Could not open file %s\n", fileName);
    exit(1);
  }

  fseek(file, 0, SEEK_END);
  long fileSize = ftell(file);
  fseek(file, 0, SEEK_SET);

  char *fileContent = malloc(fileSize + 1);
  if (fileContent == NULL) {
    printf("Could not allocate memory for file content\n");
    exit(1);
  }

  fread(fileContent, 1, fileSize, file);
  fileContent[fileSize] = '\0';
  fclose(file);

  return fileContent;
}
