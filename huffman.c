#include "huffman.h"
#include "bit_buffer.h"
#include "common_headers.h"
#include "encode_decode.h"
#include "freq_table.h"
#include "huffman_table.h"
#include "pqueue.h"
#include "validate_data.h"

int main(int argc, char **argv) {
  if (checkNumberOfArguments(argc) == false) {
    printf("Usage: %s [-encode | -decode] <input file> <output file>\n", argv[0]);
    return 1;
  }
  if (checkOptionValidity(argv) == false) {
    printf("Invalid option: %s\n", argv[1]);
    return 1;
  }
  if (checkInFile(argv[2]) == false) {
    return 1;
  }

  char *option = argv[1];
  char *inFile = argv[2];
  char *outFile = argv[3];

  int *frequencyTable = checkFrequency(inFile);
  TrieNode *root = buildHuffmanTrie(frequencyTable);
  HuffmanTable *table = create_huffman_table(root, MAX_ASCII_SIZE);

  if (strcmp(option, "-encode") == 0) {
    endodeFile(inFile, outFile, table);
  } else {
    decodeFile(inFile, outFile, root);
  }

  free(frequencyTable);
  freeTrie(root);
  for (size_t i = 0; i < table->size; i++) {
    bit_buffer_free(table->entries[i].bit_sequence);
  }
  free(table->entries);
  free(table);

  return 0;
}