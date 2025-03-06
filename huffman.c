#include "huffman.h"
#include "bit_buffer.h"
#include "common_headers.h"
#include "encode_decode.h"
#include "freq_table.h"
#include "pqueue.h"
#include "validate_data.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
/* G*/

int main(int argc, char **argv) {

  // Validera körningsargument (kan bryta ut till egen funktion)
  validateData(argc, argv);

  char *option = argv[1];
  char *file0 = argv[2];
  char *file1 = argv[3];
  char *file2 = argv[4];

  // freq_table
  int *freq_table = checkFrequency(file0);

  // buildHuffmanTrie
  TrieNode *root = buildHuffmanTrie(freq_table);

  if (strcmp(option, "-encode")) {
    
    HuffmanTable table = createHuffmanTable(root, MAX_ASCII_SIZE);
    // encode
    encodeFile(file1, file2, table);
  } else if (strcmp(option, "-decode")) {
    // decode
    decodeFile(file1, file2, root);
  }

  free(freq_table);
  free(root);

  return 0;
}

void validateData(int argc, char **argv) {
  
  for (int i = 2; i < argc; i++) {
    checkInFile(argv[i]);
  } 

  if (checkNumberOfArguments(argc) == false) {
    printf(stderr, "Invalid number of arguments\n");
    exit(1);
  }

  if (checkOptionValidity(argv) == false) {
    printf(stderr, "Invalid option\n");
    exit(1);
  }
}