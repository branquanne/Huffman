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
  return numberOfArguments == 5 ? true : false; // !Gör om till vanlig if
}

bool checkOptionValidity(char **arguments) {
  return strcmp(arguments[1], "-encode") == 0 || strcmp(arguments[1], "-decode") == 0 ? true : false; // !Gör om till vanlig if
}

bool checkInFile(char *fileName) {
  FILE *inFile = fopen(fileName, "rb");
  if (inFile == NULL) {
    printf("Could not open file %s\n", fileName);
  }
  fclose(fileName);
}
