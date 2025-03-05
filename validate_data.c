#include "validate_data.h"

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

bool checkNumberOfArguments(int numberOfArguments) {
  if (numberOfArguments == 5) {
    return true;
  }
  return false;
}

bool checkOptionValidity(char **arguments) {
  if (strcmp(arguments[1], "-encode") == 0 || strcmp(arguments[1], "-decode") == 0) {
    return true;
  }
  return false;
}

bool checkInFile(char *fileName) {
  FILE *inFile = fopen(fileName, "rb");
  if (inFile == NULL) {
    printf("Could not open file %s\n", fileName);
    return false;
  }
  fclose(inFile);
  return true;
}
