#include "huffman.h"
#include "bit_buffer.h"
#include "freq_table.h"
#include "trie.h"
#include "validate_data.h"
#include "huffman_tabell.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {
  // Validate command-line arguments
  if (!checkNumberOfArguments(argc) || !checkOptionValidity(argv)) {
    printf("Invalid arguments\n");
    return 1;
  }

  char *option = argv[1];
  char *file0 = argv[2];
  char *file1 = argv[3];
  char *file2 = argv[4];

  if (option == "-encode") {
    encode(file0, file1, file2);
  }

  if (option == "-decode") {
    decode(file0, file1, file2);
  }

}

void encode(char *file0, char *file1, char *file2) {
  // Create frequency table
  int *frequencyTable = checkFrequency(file0);

  // Build Huffman Trie
  TrieNode *root = buildHuffmanTrie(frequencyTable);

  // Create Huffman Table
  HuffmanTable *huffmanTable = createHuffmanTable();
  buildHuffmanTable(root, huffmanTable, 0, 0);

  // Encode file
  encodeFile(file0, file1, huffmanTable);

  // Free memory
  freeTrie(root);
  freeHuffmanTable(huffmanTable);
  free(frequencyTable);
}

void decode(char *file0, char *file1, char *file2) {
  // Create Huffman Table
  HuffmanTable *huffmanTable = createHuffmanTable();

  // Decode file
  decodeFile(file0, file1, file2, huffmanTable);

  // Free memory
  freeHuffmanTable(huffmanTable);
}