#include "validate_data.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {

  // Test checkNumberOfArguments
  checkNumberOfArguments(5);
  checkNumberOfArguments(4);

  if (checkNumberOfArguments(5) == false) {
    printf("checkNumberOfArguments with 5 arguments failed\n");
  } else {
    printf("checkNumberOfArguments with 5 arguments passed\n");
  }

  if (checkNumberOfArguments(4) == false) {
    printf("checkNumberOfArguments with 4 arguments failed\n");
  } else {
    printf("checkNumberOfArguments with 4 arguments passed\n");
  }

  // Test checkOptionValidity
  char *arguments[] = {"huffman", "-encode", "file0", "file1", "file2"};
  bool isOk = checkOptionValidity(arguments);
  printf("\nInput: %s %s %s %s %s\nResult:\t%s\n\n", arguments[0], arguments[1], arguments[2], arguments[3], arguments[4], isOk ? "Passed" : "Failed");

  char *arguments2[] = {"huffman", "-decode", "file0", "file1", "file2"};
  isOk = checkOptionValidity(arguments2);
  printf("Input: %s %s %s %s %s\nResult:\t%s\n\n", arguments2[0], arguments2[1], arguments2[2], arguments2[3], arguments2[4], isOk ? "Passed" : "Failed");

  char *arguments3[] = {"huffman", "-invalid", "file0", "file1", "file2"};
  isOk = checkOptionValidity(arguments3);
  printf("Input: %s %s %s %s %s\nResult:\t%s\n\n", arguments3[0], arguments3[1], arguments3[2], arguments3[3], arguments3[4], isOk ? "Passed" : "Failed");

  // Test loadFileCharacters
  char *fileContent = loadFileCharacters("test.txt");
  printf("%s\n", fileContent);
  free(fileContent);
  return 0;
}