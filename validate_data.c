#include "validate_data.h"
#include "huffman.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * File: validate_data.c
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

bool checkNumberOfArguments(int numberOfArguments) {
  return numberOfArguments == 5 ? true : false;
}

bool checkOptionValidity(char **arguments) {
  return strcmp(arguments[1], "-encode") == 0 || strcmp(arguments[1], "-decode") == 0 ? true : false;
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
