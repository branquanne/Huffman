#include "validate_data.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {

  // Test checkNumberOfArguments
  checkNumberOfArguments(5);
  checkNumberOfArguments(4);

  if (checkNumberOfArguments(5) == false) {
    printf("Error: checkNumberOfArguments with 5 arguments failed\n");
  } else {
    printf("checkNumberOfArguments with 5 arguments passed\n");
  }

  if (checkNumberOfArguments(4) == false) {
    printf("Error: checkNumberOfArguments with 4 arguments failed\n");
  } else {
    printf("checkNumberOfArguments with 4 arguments passed\n");
  }

  // Test checkOptionValidity
  char *arguments[] = {"huffman", "-encode", "file0", "file1", "file2"};
  checkOptionValidity(arguments);
  char *arguments2[] = {"huffman", "-decode", "file0", "file1", "file2"};
  checkOptionValidity(arguments2);
  char *arguments3[] = {"huffman", "-invalid", "file0", "file1", "file2"};
  checkOptionValidity(arguments3);

  // Test loadFileCharacters
  char *fileContent = loadFileCharacters("test.txt");
  printf("%s\n", fileContent);
  free(fileContent);
  return 0;
}